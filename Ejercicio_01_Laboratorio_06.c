/**************************************************
* PROGRAMA : Laboratorio 06
* OBJETIVO : Impplementacion de funciones ABB
* ALUMNO: 
			Alex Ceverino Chuquiano
* PROFESOR : 
			Tomas Lara
* ASIGNATURA : Estructura de Datos 
* SECCION : 651
* FECHA DE ULTIMA ACTUALIZACION : 20 / 05 / 2017
***************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct info{
	int valor;
}Info;

typedef struct nodo{
	Info *dato;
	struct nodo *izq;
	struct nodo *der;
}Nodo;

Nodo *crearNodo(int elem){
	Nodo *nuevo;
	nuevo = (Nodo*)malloc(sizeof(Nodo));
	Info *pinfo;
	pinfo = (Info*)malloc(sizeof(Info));
	pinfo->valor = elem;
	nuevo->dato = pinfo;
	nuevo->der = NULL;
	nuevo->izq = NULL;
	return nuevo;
}

Nodo *insertarArbolBinario(Nodo *raiz,int num){
	if (raiz == NULL){
		return crearNodo(num);
		
	}else if(num < raiz->dato->valor){
		
		raiz->izq = insertarArbolBinario(raiz->izq,num);
	}else if(num > raiz->dato->valor){
		
		raiz->der = insertarArbolBinario(raiz->der,num);
	}
	return raiz;
}

void buscarMenorElem(Nodo *raiz){
	if (raiz->izq == NULL){
		printf ("\nElemento Menor : %i",raiz->dato->valor);
	}else{
		buscarMenorElem(raiz->izq);
	}
	
}
void buscarMayorElem(Nodo *raiz){
	if (raiz->der == NULL){
		printf("\nElemento mayor : %i",raiz->dato->valor);
	}else{
		buscarMayorElem(raiz->der);
	}
}

Nodo *buscarPadre(Nodo *raiz,int num){
	Nodo *padre;
	while (raiz != NULL){
		if ( num < raiz->dato->valor){
			if ( num == raiz->der->dato->valor){
				padre = raiz;
				return padre;
			}else{
				raiz = raiz->der;
			}
		}else if( num > raiz->dato->valor ){
			if ( num == raiz->izq->dato->valor){
				padre = raiz;
				return padre;
			}else{
				raiz = raiz->izq;
			}
		}
		
	}
}

void swap(int *num1 ,int *num2){
	int auxNum;
	auxNum = *num1;
	*num1 = *num2;
	*num2 = auxNum;
}

void eliminarNodo(Nodo *raiz, int num){
	if (raiz == NULL){
		printf("Elemento no encontrado");
	}else if(raiz->dato->valor == num){
		int opc;
		printf("\nEliminar por [ 1 ] Antecesor // [ 0 ] Sucesor : ");
		scanf("%i",&opc);
		Nodo *aux = raiz;
		if (opc == 1){
			Nodo *aux2 = aux->izq;
			Nodo *padre = aux->izq;
			if (aux2->der == NULL){
				swap(&aux->dato->valor,&aux2->dato->valor);
				free(aux2);
				aux->izq = NULL;
			}else{	
				while ( aux2->der != NULL){
					aux2 = aux2->der;
				}
				while (padre != NULL){
					if ( aux2->dato->valor == padre->der->dato->valor){
						break;
					}else{
						padre = padre->der;
					}
				}
				swap(&aux->dato->valor,&aux2->dato->valor);
				eliminarNodo(padre,aux2->dato->valor);
			}
		}else if (opc == 0){
			Nodo *aux2 = aux->der;
			Nodo *padre = aux->der;
			if (aux2->izq == NULL){
				swap(&aux->dato->valor,&aux2->dato->valor);
				free(aux2);
				aux->der = NULL;
			}else{	
				while ( aux2->izq != NULL){
					aux2 = aux2->izq;
				}
				while (padre != NULL){
					if ( aux2->dato->valor == padre->izq->dato->valor){
						break;
					}else{
						padre = padre->izq;
					}
				}
				swap(&aux->dato->valor,&aux2->dato->valor);
				eliminarNodo(padre,aux2->dato->valor);
			}
		}
	}else if (num < raiz->dato->valor){
		if (num == raiz->izq->dato->valor){
			if (raiz->izq->izq == NULL && raiz->izq->der == NULL){
				free(raiz->izq);
				raiz->izq = NULL;
			}else if (raiz->izq->izq != NULL && raiz->izq->der != NULL){
				int opc;
				printf("\nEliminar por [ 1 ] Antecesor // [ 0 ] Sucesor : ");
				scanf("%i",&opc);
				Nodo *aux = raiz->izq;
				if (opc == 1){
					Nodo *aux2 = aux->izq;
					Nodo *padre = aux->izq;
					if (aux2->der == NULL){
						swap(&aux->dato->valor,&aux2->dato->valor);
						free(aux2);
						aux->izq = NULL;
					}else{	
						while ( aux2->der != NULL){
							aux2 = aux2->der;
						}
						while (padre != NULL){
							if ( aux2->dato->valor == padre->der->dato->valor){
								break;
							}else{
								padre = padre->der;
							}
						}
						swap(&aux->dato->valor,&aux2->dato->valor);
						eliminarNodo(padre,aux2->dato->valor);
					}
				}else if (opc == 0){
					Nodo *aux2 = aux->der;
					Nodo *padre = aux->der;
					if (aux2->izq == NULL){
						swap(&aux->dato->valor,&aux2->dato->valor);
						free(aux2);
						aux->der = NULL;
					}else{	
						while ( aux2->izq != NULL){
							aux2 = aux2->izq;
						}
						while (padre != NULL){
							if ( aux2->dato->valor == padre->izq->dato->valor){
								break;
							}else{
								padre = padre->izq;
							}
						}
						swap(&aux->dato->valor,&aux2->dato->valor);
						eliminarNodo(padre,aux2->dato->valor);
					}
				}
			}else if (raiz->izq->der != NULL){
				Nodo *aux = raiz->izq;
				raiz->izq = aux->der;
				free(aux);
			}else if (raiz->izq->izq != NULL){
				Nodo *aux = raiz->izq;
				raiz->izq = aux->izq;
				free (aux);
			}
		}else{
			eliminarNodo(raiz->izq,num);
		}
	}else if (num > raiz->dato->valor){	
		if (num == raiz->der->dato->valor){	
			if (raiz->der->izq == NULL && raiz->der->der == NULL){
				free(raiz->der);
				raiz->der = NULL;
			}else if (raiz->der->izq != NULL && raiz->der->der != NULL){
				int opc;
				printf("\nEliminar por [ 1 ] Antecesor // [ 0 ] Sucesor : ");
				scanf("%i",&opc);
				Nodo *aux = raiz->der;
				if (opc == 1){
					Nodo *aux2 = aux->izq;
					Nodo *padre = aux->izq;
					if (aux2->der == NULL){
						swap(&aux->dato->valor,&aux2->dato->valor);
						free(aux2);
						aux->izq = NULL;
					}else{	
						while ( aux2->der != NULL){
							aux2 = aux2->der;
						}
						while (padre != NULL){
							if ( aux2->dato->valor == padre->der->dato->valor){
								break;
							}else{
								padre = padre->der;
							}
						}
						swap(&aux->dato->valor,&aux2->dato->valor);
						eliminarNodo(padre,aux2->dato->valor);
					}
				}else if (opc == 0){
					Nodo *aux2 = aux->der;
					Nodo *padre = aux->der;
					if (aux2->izq == NULL){
						swap(&aux->dato->valor,&aux2->dato->valor);
						free(aux2);
						aux->der = NULL;
					}else{	
						while ( aux2->izq != NULL){
							aux2 = aux2->izq;
						}
						while (padre != NULL){
							if ( aux2->dato->valor == padre->izq->dato->valor){
								break;
							}else{
								padre = padre->izq;
							}
						}
						swap(&aux->dato->valor,&aux2->dato->valor);
						eliminarNodo(padre,aux2->dato->valor);
					}
				}
			}else if (raiz->der->der != NULL){
				Nodo *aux = raiz->der;
				raiz->der = aux->der;
				free(aux);
			}else if (raiz->der->izq != NULL){
				Nodo *aux = raiz->der;
				raiz->der = aux->izq;
				free (aux);
			}
		}else{
			eliminarNodo(raiz->der,num);
		}
	}
}

void inorden(Nodo *raiz){
	if(raiz != NULL){
		inorden(raiz->izq);
		printf("%i  ",raiz->dato->valor);
		inorden(raiz->der);
	}
}

int nivelArbol(Nodo *raiz){
    if(raiz == NULL){
        return 0;
    }else{
        return 1+ max(nivelArbol(raiz->izq), nivelArbol(raiz->der));
    }
}

int max(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

int main(){
	int vector[] = {9,78,6,3,7,9,5,88,10,0,1,34,22,4,2,8,45,32,65,42};
	int tam = sizeof(vector)/sizeof(int);
	int i;
	Nodo *raiz = NULL;
	for (i = 0;i <tam ; i++ ){
		raiz = insertarArbolBinario(raiz,vector[i]);
	}
	//pregunta 1 : 
	printf("\n");
	buscarMenorElem(raiz);
	
	//pregunta 2:
	printf("\n");
	buscarMayorElem(raiz);
	
	//pregunta 3:
	int nivel;
	nivel = nivelArbol(raiz);
	printf("\n");
	printf("\nEl nivel del arbol es : %i",nivel);
	printf("\n");
	
	//pregunta 4:
	int eliminar;
	printf("\n");
	printf("\nEliminar elemento del arbol : ");
	scanf("%i",&eliminar);
	printf("\n");
	int aux = eliminar;
	Nodo *paux = raiz;
	//observacion : El programa se queda pegado cuando 
	//				se envia elemento que no existe en el arbol
	eliminarNodo(raiz,eliminar);
	
	//pregunta 5:
	printf("\n");
	printf("\nArbol Inorden :  \n");
	printf("\n");
	inorden(raiz);
	
	return 0;
}


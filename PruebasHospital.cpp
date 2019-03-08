#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct nodo{
	char dato[' '];
	nodo *sig;
};
void insertar(nodo *&lista, char n[ ]);
void mostrar_lista(nodo *lista);///no lleva " & " devido a que esa es la referencia de datos, solo llevamos " * " por que me apunta 
//void buscar(nodo *lista, int n);
//void eliminar(nodo *&lista, int n);
//void eliminarC(nodo *&lista, int &n);

main(){

	char r;
	nodo *lista=NULL;
	int dato;
	int op;
	char res;
	int elemento;
	do{
		system("cls");
cout<<"Selecciona una accion: \n";
cout<<"\n1)Ingresar un elemento";
cout<<"\n2)imprimir un elementos";
cout<<"\n3)buscar";
cout<<"\n4)salir";
cout<<"\n5)eliminar elemento por elemento\n";
cout<<"\n6)eliminar toda la lista"<<endl;
cin>>op;
	switch(op){
	case 1:
	char dato[' '];
	char r;
	do{
			cout<<"teclee un elemento:\t";
			cin>>dato;
			insertar(lista,dato);
			cout<<"otro dato s/n";
			cin>>r;			
		}while(r!='n');		
		break;
		case 2:
		mostrar_lista(lista);
		break;
		case 3:
			cout<<"elemento a buscar: ";
			cin>>elemento;
		//buscar(lista,elemento);
		break;
		case 4:
			return 0;
		break;
		case 5:
			//eliminar(lista,dato);
			break;
			case 6:
		//eliminarC(lista,dato);
		break;
		default:
			cout<<"valor invalido"<<endl;
	}
	cout<<"\n Repetir proceso del menu principal?";
	cin>>res;
}while(res!='n');
		getch();
}


void insertar(nodo *&lista, char n[ ]){
	nodo *nvo_nodo=new nodo();
	nvo_nodo->dato[' ']=n[' '];
	nodo *aux1=lista;
	nodo *aux2;
		while(aux1!=NULL){
		aux2=aux1;
		aux1=aux1->sig;
		}
		if(lista==aux1){
			lista=nvo_nodo;
		}
			else{
				aux2->sig=nvo_nodo;
			}
				nvo_nodo->sig=aux1;
				cout<<"\t elemento: "<<n <<"\tinsertado adecuadamente"<<endl;
}


void mostrar_lista(nodo *lista){
nodo *actual=new nodo();
actual=lista;
	while(actual!=NULL){
		cout<<actual->dato[ ]<<" , ";
	actual=actual->sig;
	}
		if(actual==NULL){
			cout<<"...Fin lista";
		}
}
/*
void buscar(nodo *lista, int n){
bool band=false;
nodo *actual=new nodo();// crea el nuevo espacio de memoria
actual=lista;//la variable actual contiene todos los elementos de la lista

	while((actual!=NULL)&&(actual->dato<=n)){//el elemento buscado debe de ser menor a el elemento mayor de la lista
   	if(actual->dato==n){
      	band=true;
      }
      actual=actual->sig;
	}
   		if(band==true){
         cout<<"Elemento "<<n<<" Encontrado\n ";
      	}
         	else{
             cout<<"Elemento "<<n<<" NO Encontrado\n ";
            }
}
*/
/*
void eliminar(nodo *&lista, int n){
		nodo *auxBorrar;
		nodo *anterior=NULL;
	if(lista!=NULL){
		auxBorrar=lista;
			while((auxBorrar!=NULL)&&(auxBorrar->dato!=n)){
				anterior=auxBorrar;
				auxBorrar=auxBorrar->sig;
			}
				if(auxBorrar==NULL){
					cout<<"elemento no existe"<<endl;
					
				}
					else{		
						if(anterior==NULL){
							lista=lista->sig;
							cout<<"Elemento:\t"<<n<<" Eliminado"<<endl;
							delete auxBorrar;
						}
							else{
								anterior->sig=auxBorrar->sig;
								delete auxBorrar;
							}
						
					}
	}
}


void eliminarC(nodo *&lista, int &n){
	nodo *aux=lista;	
	n=aux->dato;
	while(lista!=NULL){
		lista=aux->sig;
		delete aux;
	}
}

*/


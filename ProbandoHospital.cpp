#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<cstring>
#include<string.h>
#include"coordenadas.h"
using namespace std;

struct nodo{
	long double matricula;
	char nombre[20];
	char apellido[20];
	char domicilio[50];
	long double telefono;
	nodo *sig;
};
void ingresarDatos(nodo *&);
void eliminar_act(nodo*actual,nodo*anterior,nodo*lista);
int mostrar_lista(nodo *lista);///no lleva " & " devido a que esa es la referencia de datos, solo llevamos " * " por que me apunta
void buscar(nodo *lista, int op);
void tabla(int lim);
void tablaRegreso();
void tablaEntrada(int lim);
void pacientes(int lim);
void buscarp(int lim);
void datosEncontrados(int lim);
void modificar(nodo *lista, int op);
void bajaPaciente(nodo *&lista, int op);
int i;
int glo;
main(){

	char r;
	nodo *lista=NULL;
	int op;
	char res;
	int elemento;
	do{
	do{//primer while para repetir lo de imprimir	
		system("cls");
		tabla(32);
		gotoxy(48,1);cout<<"H O S P I T A L +";
gotoxy(41,4);cout<<"Selecciona una accion... \n";
gotoxy(41,5);cout<<"1)Alta de pacientes"<<endl;
gotoxy(41,6);cout<<"2)Consulta Todos los pacientes"<<endl;
gotoxy(41,7);cout<<"3)Consulta por paciente";
gotoxy(41,8);cout<<"4)Modificar paciente";
gotoxy(41,9);cout<<"5)Bajar paciente";
gotoxy(41,10);cout<<"6)salir";
gotoxy(41,11);cin>>op;
	switch(op){
	case 1:
			system("cls");
			tablaEntrada(30);
			//////////
			ingresarDatos(lista);
		break;
		case 2:
			system("cls");
		elemento=mostrar_lista(lista);
		break;
		case 3:
			int ac;
			system("cls");
			buscarp(31);
			gotoxy(42,2);cout<<"BUSCAR PACIENTE";
			gotoxy(41,4);cout<<"Seleccione una opcion:";
gotoxy(41,5);cout<<"1)codigo";
gotoxy(41,6);cout<<"2)Nombre";
gotoxy(41,7);cout<<"3)Apellido";
gotoxy(41,8);cout<<"4)Domicilio";
gotoxy(41,9);cout<<"5)telefono";
gotoxy(41,10);cin>>ac;
buscar(lista,ac);

			break;
			case 4:
			system("cls");
			buscarp(31);
			gotoxy(42,2);cout<<"Modificar datos paciente";
			gotoxy(41,4);cout<<"Seleccione una opcion:";
			gotoxy(41,5);cout<<"1)codigo";
			gotoxy(41,6);cout<<"2)Nombre";
			gotoxy(41,7);cout<<"3)Apellido";
			gotoxy(41,8);cout<<"4)Domicilio";
			gotoxy(41,9);cout<<"5)telefono";
			gotoxy(41,10);cin>>glo;
			modificar(lista,glo);
			break;
			case 5:
				system("cls");
			buscarp(31);
			gotoxy(42,2);cout<<"Baja de paciente";
			gotoxy(41,6);cout<<"2)Nombre";
			gotoxy(41,7);cout<<"3)Apellido";
			gotoxy(41,8);cout<<"4)Domicilio";
			gotoxy(41,9);cout<<"5)telefono";
			gotoxy(41,10);cin>>glo;
				bajaPaciente(lista,glo);
				break;
				case 6:
				return 0;	
				break;
			
		default:
			cout<<"valor invalido"<<endl;
	}
	}while(elemento==1);
	gotoxy(77,3);cout<<"Regresar al menu principal?";
	gotoxy(77,4);cin>>res;
}while(res!='n');
		getch();
}

void ingresarDatos(nodo *&lista){
nodo *nvo_nodo=new nodo();
			gotoxy(41,3);cout<<"DATOS DEL PACIENTE";
			gotoxy(41,5);cout<<"Matricula:\t "<<endl;
			gotoxy(41,6);cin>>nvo_nodo->matricula;
			gotoxy(41,7);cout<<"Nombre:\t"<<endl;
			gotoxy(41,8);cin>>nvo_nodo->nombre;
			gotoxy(41,9);cout<<"Apellidos:\t"<<endl;
			gotoxy(41,10);cin>>nvo_nodo->apellido;
			gotoxy(41,11);cout<<"Domicilio:\t"<<endl;
			gotoxy(41,12);cin>>nvo_nodo->domicilio;
			gotoxy(41,13);cout<<"Telefono:\t"<<endl;
			gotoxy(41,14);cin>>nvo_nodo->telefono;
	nodo *aux1=lista;
	nodo *aux2;
	
	while(aux1!=NULL){
		aux2=aux1;
		aux1=aux1->sig;
	}
	if(lista==aux1){
		lista=nvo_nodo;
	}else{
		aux2->sig=nvo_nodo;
	}
	nvo_nodo->sig=aux1;	
	gotoxy(42,16);cout<<"ELEMENTOS INSERTADOS";
				gotoxy(42,18);cout<<"Matricula: "<<nvo_nodo->matricula;
				gotoxy(42,19);cout<<"Nombre: "<<nvo_nodo->nombre;
				gotoxy(42,20);cout<<"Apellidos: "<<nvo_nodo->apellido;
				gotoxy(42,21);cout<<"Domicilio: "<<nvo_nodo->domicilio;
				gotoxy(42,22);cout<<"Telefono: "<<nvo_nodo->telefono;
}

int mostrar_lista(nodo *lista){
nodo *actual=new nodo();
actual=lista;
pacientes(30);
gotoxy(40,2);cout<<"LISTADO DE PACIENTES";
if(actual==NULL){
	cout<<"Lista vacia";
}
	while(actual!=NULL){
		cout<<"\n \n";
		cout<<"\t\t\t\t\tMatricula del paciente:"<<actual->matricula<<endl;
		cout<<"\t\t\t\t\tNombre del paciente: "<<actual->nombre<<endl;
		cout<<"\t\t\t\t\tApellido del paciente: "<<actual->apellido<<endl;
		cout<<"\t\t\t\t\tDomicilio del paciente: "<<actual->domicilio<<endl;
		cout<<"\t\t\t\t\tTelefono del paciente: "<<actual->telefono<<endl;
	
	actual=actual->sig;
	}
	gotoxy(77,3);system("pause");
	return 1;
}


void buscar(nodo *lista, int op){
bool band=false;
nodo *actual=new nodo();// crea el nuevo espacio de memoria
actual=lista;//la variable actual contiene todos los elementos de la lista
		switch(op){
		case 1:
			system("cls");
			//tablaRegreso();
			datosEncontrados(46);
			float matri;
			gotoxy(29,2);cout<<"Datos del paciente de acuerdo a la matricula\n ";
			gotoxy(29,3);cout<<"Matricula del paciente abuscar:";
			gotoxy(63,3);cin>>matri;
			while(actual!=NULL){//el elemento buscado debe de ser menor a el elemento mayor de la lista
				if(actual->matricula==matri){
 				band=true;
      			cout<<"\n \n";
         		cout<<"\t\t\t\t\tPaciente: "<<actual->matricula<<" Encontrado\n ";
         		cout<<"\t\t\t\t\tLos datos del paciente son:"<<endl;
         		cout<<"\t\t\t\t\tMatricula: "<<actual->matricula<<endl;
				cout<<"\t\t\t\t\tNombre: "<<actual->nombre<<endl;
				cout<<"\t\t\t\t\tApellido: "<<actual->apellido<<endl;
				cout<<"\t\t\t\t\tDomicilio: "<<actual->domicilio<<endl;
				cout<<"\t\t\t\t\tTelefono: "<<actual->telefono<<endl;
				  }
      		actual=actual->sig;
			}
					if(band==true){
         			gotoxy(29,19);cout<<"Datos del paciente impresos... \n"; 
      				}
         				else{
             			gotoxy(29,5);cout<<"Paciente: "<<matri<<" NO Encontrado\n ";
            			}
	gotoxy(29,20);system("pause");
        break;
        case 2:
        	system("cls");
			//tablaRegreso();
			datosEncontrados(46);
			char bus[20];
			gotoxy(29,2);cout<<"Datos del paciente de acuerdo a su nombre\n ";
			gotoxy(29,3);cout<<"Nombre del paciente a buscar:";
			gotoxy(63,3);cin>>bus;
			
			while(actual!=NULL){//el elemento buscado debe de ser menor a el elemento mayor de la lista
					
				if(strcmp(actual->nombre,bus)==0){
 				band=true;
      			cout<<"\n \n";
         		cout<<"\t\t\t\t\tPaciente:  Encontrado\n ";
         		cout<<"\t\t\t\t\tLos datos del paciente son:"<<endl;
         		cout<<"\t\t\t\t\tMatricula: "<<actual->matricula<<endl;
				cout<<"\t\t\t\t\tNombre: "<<actual->nombre<<endl;
				cout<<"\t\t\t\t\tApellido: "<<actual->apellido<<endl;
				cout<<"\t\t\t\t\tDomicilio: "<<actual->domicilio<<endl;
				cout<<"\t\t\t\t\tTelefono: "<<actual->telefono<<endl;
				  }
      		actual=actual->sig;
			}
					if(band==true){
         			gotoxy(29,19);cout<<"Datos del paciente impresos... \n"; 
      				}
         				else{
             			gotoxy(29,5);cout<<"Paciente: "<<matri<<" NO Encontrado\n ";
            			}
	gotoxy(29,20);system("pause");
        	
        	break;
        	case 3:
        		system("cls");
			//tablaRegreso();
			datosEncontrados(46);
			char busc[20];
			gotoxy(29,2);cout<<"Datos del paciente de acuerdo a su Apellido\n ";
			gotoxy(29,3);cout<<"Apellido del paciente a buscar:";
			gotoxy(63,3);cin>>busc;
			
			while(actual!=NULL){//el elemento buscado debe de ser menor a el elemento mayor de la lista
					
				if(strcmp(actual->apellido,busc)==0){
 				band=true;
      			cout<<"\n \n";
         		cout<<"\t\t\t\t\tPaciente  Encontrado\n ";
         		cout<<"\t\t\t\t\tLos datos del paciente son:"<<endl;
         		cout<<"\t\t\t\t\tMatricula: "<<actual->matricula<<endl;
				cout<<"\t\t\t\t\tNombre: "<<actual->nombre<<endl;
				cout<<"\t\t\t\t\tApellido: "<<actual->apellido<<endl;
				cout<<"\t\t\t\t\tDomicilio: "<<actual->domicilio<<endl;
				cout<<"\t\t\t\t\tTelefono: "<<actual->telefono<<endl;
				  }
      		actual=actual->sig;
			}
					if(band==true){
         			gotoxy(29,19);cout<<"Datos del paciente impresos... \n"; 
      				}
         				else{
             			gotoxy(29,5);cout<<"Paciente: "<<matri<<" NO Encontrado\n ";
            			}
	gotoxy(29,20);system("pause");
        	
        		
        		break;
        		case 4:
        			system("cls");
			//tablaRegreso();
			datosEncontrados(46);
			char busca[20];
			gotoxy(29,2);cout<<"Datos del paciente de acuerdo a su domicilio\n ";
			gotoxy(29,3);cout<<"Domicilio del paciente a buscar:";
			gotoxy(63,3);cin>>busca;
			
			while(actual!=NULL){//el elemento buscado debe de ser menor a el elemento mayor de la lista
					
				if(strcmp(actual->domicilio,busca)==0){
 				band=true;
      			cout<<"\n \n";
         		cout<<"\t\t\t\t\tPaciente:  Encontrado\n ";
         		cout<<"\t\t\t\t\tLos datos del paciente son:"<<endl;
         		cout<<"\t\t\t\t\tMatricula: "<<actual->matricula<<endl;
				cout<<"\t\t\t\t\tNombre: "<<actual->nombre<<endl;
				cout<<"\t\t\t\t\tApellido: "<<actual->apellido<<endl;
				cout<<"\t\t\t\t\tDomicilio: "<<actual->domicilio<<endl;
				cout<<"\t\t\t\t\tTelefono: "<<actual->telefono<<endl;
				  }
      		actual=actual->sig;
			}
					if(band==true){
         			gotoxy(29,19);cout<<"Datos del paciente impresos... \n"; 
      				}
         				else{
             			gotoxy(29,5);cout<<"Paciente: "<<matri<<" NO Encontrado\n ";
            			}
	gotoxy(29,20);system("pause");
        	
        			break;
        			case 5:
        				system("cls");
			//tablaRegreso();
			datosEncontrados(46);
			long double tel;
			gotoxy(29,2);cout<<"Datos del paciente de acuerdo a su telefono\n ";
			gotoxy(29,3);cout<<"Telefono del paciente a buscar:";
			gotoxy(63,3);cin>>tel;
			
			while(actual!=NULL){//el elemento buscado debe de ser menor a el elemento mayor de la lista
					
				if(actual->telefono==tel){
 				band=true;
      			cout<<"\n \n";
         		cout<<"\t\t\t\t\tPaciente:  Encontrado\n ";
         		cout<<"\t\t\t\t\tLos datos del paciente son:"<<endl;
         		cout<<"\t\t\t\t\tMatricula: "<<actual->matricula<<endl;
				cout<<"\t\t\t\t\tNombre: "<<actual->nombre<<endl;
				cout<<"\t\t\t\t\tApellido: "<<actual->apellido<<endl;
				cout<<"\t\t\t\t\tDomicilio: "<<actual->domicilio<<endl;
				cout<<"\t\t\t\t\tTelefono: "<<actual->telefono<<endl;
				  }
      		actual=actual->sig;
			}
					if(band==true){
         			gotoxy(29,19);cout<<"Datos del paciente impresos... \n"; 
      				}
         				else{
             			gotoxy(29,5);cout<<"Paciente: "<<matri<<" NO Encontrado\n ";
            			}
	gotoxy(29,20);system("pause");
        	
        				break;
        			
        default:
        	cout<<"Valor invalido";
        	
		}//llave del switch
}

void tabla(int lim){
	for(i=0;i<lim;i++){
		gotoxy(40+i,0);cout<<"*";
		gotoxy(40+i,3);cout<<"*";
		gotoxy(40+i,12);cout<<"*";
		gotoxy(72,1+i-20);cout<<"*";
		gotoxy(40,1+i-20);cout<<"*";
	}
}
void tablaEntrada(int lim){
	for(i=0;i<lim;i++){
		gotoxy(40+i,2);cout<<"*";
		gotoxy(40+i,4);cout<<"*";
		gotoxy(40+i,15);cout<<"*";
		gotoxy(40+i,17);cout<<"*";
		gotoxy(40+i,25);cout<<"*";
		}
			for(i=0;i<24;i++){
			gotoxy(40,2+i);cout<<"*";	
			gotoxy(70,2+i);cout<<"*";
			}	
	for(i=0;i<33;i++){
		gotoxy(76+i,5);cout<<"*";
		gotoxy(76+i,2);cout<<"*";
	}
		for(i=0;i<4;i++){
		gotoxy(108,2+i);cout<<"*";
		gotoxy(76,2+i);cout<<"*";
		}
}


void pacientes(int lim){
	for(i=0;i<lim;i++){
		gotoxy(40+i,1);cout<<"*";
		gotoxy(40+i,32);cout<<"*";
		gotoxy(40+i,3);cout<<"*";
	}
	for(i=0;i<32;i++){
		gotoxy(39,1+i);cout<<"*";
		gotoxy(70,1+i);cout<<"*";
		
	}
}

void buscarp(int lim){
	for(i=0;i<lim;i++){
		gotoxy(41+i-1,0);cout<<"*";
		gotoxy(41+i-1,3);cout<<"*";
		gotoxy(41+i-1,11);cout<<"*";
		gotoxy(70,1+i-20);cout<<"*";
		gotoxy(40,1+i-20);cout<<"*";
	}
}

void datosEncontrados(int lim){
	for(int i=0;i<lim;i++){
		gotoxy(28+i,1);cout<<"*";
		gotoxy(28+i,4);cout<<"*";
		gotoxy(28+i,41);cout<<"*";
	}
		for(int i=0;i<41;i++){
			gotoxy(28,1+i);cout<<"*";
			gotoxy(73,1+i);cout<<"*";

		}
}

void tablaRegreso(){	
	for(i=0;i<33;i++){
		gotoxy(76+i,5);cout<<"*";
		gotoxy(76+i,2);cout<<"*";
	}
		for(i=0;i<4;i++){
		gotoxy(108,2+i);cout<<"*";
		gotoxy(76,2+i);cout<<"*";
		}
}
///////////////////////////////////////////
//de aqui se añadio mas codigo


void modificar(nodo *lista, int op){
bool band=false;
nodo *actual=new nodo();// crea el nuevo espacio de memoria
actual=lista;//la variable actual contiene todos los elementos de la lista
		switch(op){
		case 1:
			system("cls");
			//tablaRegreso();
			datosEncontrados(46);
			float matri;
			gotoxy(29,2);cout<<"Datos del paciente a modificar\n ";
			gotoxy(29,3);cout<<"Matricula del paciente a modificar:";
			gotoxy(63,3);cin>>matri;
			
			while(actual!=NULL){//el elemento buscado debe de ser menor a el elemento mayor de la lista
					
				if(actual->matricula==matri){
 				band=true;
 				cout<<"\n";
      			cout<<"\t\t\t\t\tNueva Matricula: "<<endl;
				cout<<"\n\t\t\t\t\t";cin>>actual->matricula;
				  }
				  
      		actual=actual->sig;
			}
					if(band==true){
         			gotoxy(29,19);cout<<"Matricula modificada... \n"; 
      				}
         				else{
             			gotoxy(29,5);cout<<"Paciente: "<<matri<<" NO Encontrado\n ";
            			}
	gotoxy(29,20);system("pause");
        break;
        case 2:
        	system("cls");
			//tablaRegreso();
			datosEncontrados(46);
			char bus[20];
			gotoxy(29,2);cout<<"Datos del paciente a modificar\n ";
			gotoxy(29,3);cout<<"Nombre del paciente a modificar:";
			gotoxy(63,3);cin>>bus;
			
			while(actual!=NULL){//el elemento buscado debe de ser menor a el elemento mayor de la lista
					
				if(strcmp(actual->nombre,bus)==0){
 				band=true;
 				cout<<"\n";
      			cout<<"\t\t\t\t\tNuevo Nombre: "<<endl;
				cout<<"\n\t\t\t\t\t";cin>>actual->nombre;
				  }
				  
      		actual=actual->sig;
			}
					if(band==true){
         			gotoxy(29,19);cout<<"Nombre modificado... \n"; 
      				}
         				else{
             			gotoxy(29,5);cout<<"Paciente: "<<matri<<" NO Encontrado\n ";
            			}
	gotoxy(29,20);system("pause");
        	break;
        	case 3:
        		system("cls");
			//tablaRegreso();
			datosEncontrados(46);
			char bus2[20];
			gotoxy(29,2);cout<<"Datos del paciente a modificar\n ";
			gotoxy(29,3);cout<<"Apellido del paciente a modificar:";
			gotoxy(63,3);cin>>bus2;
			
			while(actual!=NULL){//el elemento buscado debe de ser menor a el elemento mayor de la lista
					
				if(strcmp(actual->apellido,bus2)==0){
 				band=true;
 				cout<<"\n";
      			cout<<"\t\t\t\t\tNuevo Apellidos: "<<endl;
				cout<<"\n\t\t\t\t\t";cin>>actual->apellido;
				  }
				  
      		actual=actual->sig;
			}
					if(band==true){
         			gotoxy(29,19);cout<<"Apellido modificado... \n"; 
      				}
         				else{
             			gotoxy(29,5);cout<<"Paciente: "<<matri<<" NO Encontrado\n ";
            			}
	gotoxy(29,20);system("pause");
        		break;
        		case 4:
        			system("cls");
			//tablaRegreso();
			datosEncontrados(46);
			char bus3[20];
			gotoxy(29,2);cout<<"Datos del paciente a modificar\n ";
			gotoxy(29,3);cout<<"Domicilio del paciente a modificar:";
			gotoxy(63,3);cin>>bus3;
			
			while(actual!=NULL){//el elemento buscado debe de ser menor a el elemento mayor de la lista
					
				if(strcmp(actual->domicilio,bus3)==0){
 				band=true;
 				cout<<"\n";
      			cout<<"\t\t\t\t\tNuevo Domicilio: "<<endl;
				cout<<"\n\t\t\t\t\t";cin>>actual->domicilio;
				  }
				  
      		actual=actual->sig;
			}
					if(band==true){
         			gotoxy(29,19);cout<<"Domicilio modificada... \n"; 
      				}
         				else{
             			gotoxy(29,5);cout<<"Paciente: "<<matri<<" NO Encontrado\n ";
            			}
	gotoxy(29,20);system("pause");
        			break;
        			case 5:
        				system("cls");
			//tablaRegreso();
			datosEncontrados(46);
			long double tel;
			gotoxy(29,2);cout<<"Datos del paciente a modificar\n ";
			gotoxy(29,3);cout<<"Telefono del paciente a modificar:";
			gotoxy(63,3);cin>>tel;
			
			while(actual!=NULL){//el elemento buscado debe de ser menor a el elemento mayor de la lista
					
				if(actual->telefono==tel){
 				band=true;
 				cout<<"\n";
      			cout<<"\t\t\t\t\tNuevo Telefono: "<<endl;
				cout<<"\n\t\t\t\t\t";cin>>actual->telefono;
				  }
				  
      		actual=actual->sig;
			}
					if(band==true){
         			gotoxy(29,19);cout<<"Telefono modificado... \n"; 
      				}
         				else{
             			gotoxy(29,5);cout<<"Paciente: "<<matri<<" NO Encontrado\n ";
            			}
	gotoxy(29,20);system("pause");
        				break;
        			
        default:
        	cout<<"Valor invalido";
        	
		}//llave del switch
	
}


////////////

//añadi nuevo codigo 2
	void eliminar_act(nodo*actual,nodo*anterior,nodo*lista){
	if(anterior==NULL){
		delete actual;
		actual=lista;	
	}else{
		anterior->sig=actual->sig;
   		delete actual;
        actual=lista;
   }
}
	
void bajaPaciente(nodo *&lista, int op){
	if(lista!=NULL){
		nodo *auxBorrar;
		nodo *anterior=NULL;
		auxBorrar=lista;
		nodo *actual=new nodo();
		actual=lista;
		int co=0;
		bool band=false;
			switch(op){
			case 1:
				system("cls");
			//tablaRegreso();
			datosEncontrados(46);
			long double matri;
			int sel;
			gotoxy(29,2);cout<<"Datos del paciente a dar de baja\n ";
			gotoxy(29,3);cout<<"Matricula del paciente:";
			gotoxy(63,3);cin>>matri;				
			
				
						
			while(actual!=NULL){//el elemento buscado debe de ser menor a el elemento mayor de la lista
					band=true;
				if(actual->matricula==matri){
				co++;	
				
				cout<<"\n \n";
         		cout<<"\t\t\t\t\tPaciente: "<<actual->matricula<<" Encontrado\n ";
         		cout<<"\t\t\t\t\tLos datos del paciente son:"<<endl;
         		cout<<"\t\t\t\t\tMatricula: "<<actual->matricula<<endl;
				cout<<"\t\t\t\t\tNombre: "<<actual->nombre<<endl;
				cout<<"\t\t\t\t\tApellido: "<<actual->apellido<<endl;
				cout<<"\t\t\t\t\tDomicilio: "<<actual->domicilio<<endl;
				cout<<"\t\t\t\t\tTelefono: "<<actual->telefono<<endl;
				
				gotoxy(77,3+co*5);cout<<"Seguro de dar de baja X_X ?";
						gotoxy(77,4+co*5); cout<<"1)si \t2)no";
						gotoxy(77,6+co*5);cin>>sel;
						
						
						if(sel==1){
							//eliminar_act(actual,anterior,lista);
							
							if(auxBorrar==NULL){
							gotoxy(29,18);cout<<"Paciente no existe: "<<matri<<endl;
							}
								else{
									if(anterior==NULL){
										
										lista=lista->sig;
										delete auxBorrar;
										gotoxy(29,19);cout<<"Paciente dado de baja";
									}else{
											anterior->sig=auxBorrar->sig;
											delete auxBorrar;
											
										}


								}
						}	
							
						}
      		actual=actual->sig;
			}
					if(band=true){ 
      				}
         				else{
             			gotoxy(29,5);cout<<"Paciente: "<<matri<<" NO Encontrado\n ";
            			}
	gotoxy(29,20);system("pause");							
					//gotoxy(29,20);system("pause");
					break;
					default:
						cout<<"valor invalido";
			}
	
	}
	
}






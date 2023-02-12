#include<iostream>
#include<conio.h>
#include "clase.h"
#include<stdlib.h>
#include<stdio.h>


using namespace std;

struct nodo{;
	string nss, name, apell,apell2;
	int edad, diag;
	//float cal1,cal2,cal3,pro;
	nodo *siguiente;
};
void titulos();
void titulos_todo();
void cuadro(int x1, int y1, int x2, int y2);
void alta_paciente(nodo *&,string nss, string name,string apell,string apell2, int edad, int diag);
void ver_pacientes(nodo *);
void buscar_lista(nodo *,string nss, string name,string apell,string apell2, int edad, int diag);
void eliminar_nodo(nodo *&,string a,string b,string c,string d,int e ,int f );


main(){
	nodo*lista=NULL;
	int opc,opc1;
    string nss, name, apell,apell2;
    int edad, diag;
    char resp;
    float pro;
    
	system("cls");
	system("COLOR f0");
gotoxy(30,3);cout<<"#     # #######  #####  ######  ### #######    #    #       "<<endl;
gotoxy(30,4);cout<<"#     # #     # #     # #     #  #     #      # #   #       "<<endl;
gotoxy(30,5);cout<<"#     # #     # #       #     #  #     #     #   #  #       "<<endl;
gotoxy(30,6);cout<<"####### #     #  #####  ######   #     #    #     # #       "<<endl;
gotoxy(30,7);cout<<"#     # #     #       # #        #     #    ####### #       "<<endl;
gotoxy(30,8);cout<<"#     # #     # #     # #        #     #    #     # #       "<<endl;
gotoxy(30,9);cout<<"#     # #######  #####  #       ###    #    #     # ####### "<<endl; 
gotoxy(30,12);cout<<" ###    #     #     #####      #####   "<<endl;
gotoxy(30,13);cout<<"  #     ##   ##    #     #    #     # "<<endl;
gotoxy(30,14);cout<<"  #     # # # #    #          #       "<<endl;
gotoxy(30,15);cout<<"  #     #  #  #     #####      #####  "<<endl;
gotoxy(30,16);cout<<"  #     #     #          #          # "<<endl;
gotoxy(30,17);cout<<"  #     #     #    #     #    #     # "<<endl;
gotoxy(30,18);cout<<" ###    #     #     #####      #####  "<<endl; 
gotoxy(75,12);cout<<"     _      "<<endl;
gotoxy(75,13);cout<<"    | |     "<<endl;
gotoxy(75,14);cout<<" ___| |___  "<<endl;
gotoxy(75,15);cout<<"(___   ___) "<<endl;
gotoxy(75,16);cout<<"    | |     "<<endl;
gotoxy(75,17);cout<<"    |_|     "<<endl;                                                         
    getch();
do{
		

    system("cls");
    system("COLOR 0f");
	cuadro(19,0,100,20);
	cuadro(19,0,100,2);
	cuadro(20,3,99,14);
	
	gotoxy(46,1);cout<<"~~~~~ MENU PRINCIPAL ~~~~~"<<endl;
	gotoxy(35,6);cout<<"1.-Alta de Paciente";
	gotoxy(65,6);cout<<"2.-Baja de Paciente";
	gotoxy(35,12);cout<<"3.-Consultas";
	gotoxy(65,12);cout<<"4.-Salir";
	gotoxy(35,16);cout<<" Selecciona una Opcion:";
	gotoxy(19,21);cout<<"Instituto Mexicano del Seguro Social (IMSS)";
	gotoxy(60,16);cin>>opc;
	system("cls");
	switch(opc){
		case 1:
			do{
			    titulos();
			    //system("COLOR f0");
			   system("COLOR 0f");
			 	gotoxy(40,5);cin>>nss;
			 	gotoxy(40,7);cin>>name;
			 	gotoxy(40,9);cin>>apell;
			 	gotoxy(40,11);cin>>apell2;
				gotoxy(40,13);cin>>edad;
			 	gotoxy(40,16);cin>>diag;

			    alta_paciente(lista,nss,name,apell,apell2,edad,diag);
			 	//getch();
			 	system("cls");
			 	cuadro(35,10,80,15);
			 	gotoxy(40,10);cout<<" Dar de Alta otro Paciente (s/n): "<<endl;
			 	gotoxy(50,12);cin>>resp;
			 	system("cls");
			}while(resp=='s');	
		    break;	
		case 2:
			//system("COLOR 4f");
			cuadro(35,10,80,19);
			gotoxy(40,12);cout<<"NSS del Paciente a dar de Baja: "<<endl;
        	gotoxy(40,14);cin>>nss;
        	    eliminar_nodo(lista,nss,name,apell,apell2,edad,diag);
        	    break;
		case 3:
			do{
					cuadro(35,10,80,18);
					system("COLOR 0f");
		    gotoxy(40,11);cout<<"1. Consultar un Paciente"<<endl;
		    gotoxy(40,12);cout<<"2. Consultar todos los Pacientes"<<endl;
		    gotoxy(40,13);cout<<"3. Ir MENU"<<endl;
		    gotoxy(40,16);cout<<" Selecciona una Opcion:";
		    cin>>opc1;
		    system("cls");
		
				    switch(opc1){
					
					case 1:
						cuadro(35,10,80,15);
						gotoxy(40,10);cout<<" Escriba su NSS "<<endl;
        	            gotoxy(40,12);cin>>nss;
        	            system("cls");
						buscar_lista(lista,nss,name,apell,apell2,edad,diag);
						getch();
						system("cls");
						break;	
					case 2:
						ver_pacientes(lista);
						getch();
						system("cls");
						break;		
					}	
			      }while(opc1!=3);
		    break;			
    }
  }while(opc!=4);
 // system("COLOR 4f");	
}

void titulos (){
		cuadro(10,3,115,20);
	gotoxy(15,5);cout<<"Numero de Seguro Social:";
	gotoxy(15,7);cout<<"Nombre(s):";
	gotoxy(15,9);cout<<"Primer Apellido:";
	gotoxy(15,11);cout<<"Segundo Apellido:";
	gotoxy(15,13);cout<<"Edad:";
	gotoxy(15,16);cout<<"Diagnostico:";
		cuadro(10,21,115,30);
	gotoxy(18,22);cout<<"TIPOS DE DIAGNOSTICO";
	gotoxy(15,24);cout<<"Enfermedades";
	gotoxy(38,24);cout<<"Costo/Dias";
	gotoxy(18,25);cout<<" 1                    236.20";
	gotoxy(18,26);cout<<" 2                    780.19";
	gotoxy(18,27);cout<<" 3                   1740.10";
	gotoxy(18,28);cout<<" 4                   2801.90";
	gotoxy(60,25);cout<<"NOTA: Si la persona tiene entre 14 y 21 de Edad";	
	gotoxy(65,26);cout<<" se le aplicara un descuento del 12%";
} 
void titulos_todo(){
		cuadro(10,4,115,6);
	gotoxy(15,5);cout<<"NSS";
	gotoxy(35,5);cout<<"Nombre(s)";
	gotoxy(48,5);cout<<"Primer Apellido";
	gotoxy(68,5);cout<<"Segundo Apellido";
	gotoxy(88,5);cout<<"Edad";
	gotoxy(98,5);cout<<"Diagnostico";
}
void cuadro(int x1, int y1, int x2, int y2){
    int i;
    for (i=x1;i<x2;i++){	
		gotoxy(i,y1);printf("Ä") ; //linea horizontal superior 
		gotoxy(i,y2);printf("Ä") ; //linea horizontal inferior
    }

    for (i=y1;i<y2;i++){	
		gotoxy(x1,i);printf("³") ; //linea vertical izquierda
		gotoxy(x2,i);printf("³") ; //linea vertical derecha
    }
    
    gotoxy(x1,y1); printf("Ú"); //Esquinas del cuadro
    gotoxy(x1,y2); printf("À");
    gotoxy(x2,y1); printf("¿");
    gotoxy(x2,y2); printf("Ù");
}
void alta_paciente(nodo *&lista,string a, string b,string c,string d,int e, int f){
	nodo *nvo_nodo=new nodo();
	nvo_nodo->nss=a;
	nvo_nodo->name=b;
	nvo_nodo->apell=c;
	nvo_nodo->apell2=d;
	nvo_nodo->edad=e;
	nvo_nodo->diag=f;
	nodo *aux1=lista;
	nodo*aux2;
while((aux1!=NULL)&&(aux1->nss<a)){
	aux2=aux1;
	aux1=aux1->siguiente;
}
if(lista==aux1){
	lista=nvo_nodo;
}	
else{
	aux2->siguiente=nvo_nodo;
}
nvo_nodo->siguiente=aux1;
	
}

void ver_pacientes(nodo *lista){
	nodo *actual=new nodo();
	actual=lista;
	int x=0;
gotoxy(15,1);cout<<"Pacientes:"<<endl;	
while (actual!=NULL){
	//cuadro(10,3,115,10);
	titulos_todo();
gotoxy(15,7+x);cout<<actual->nss;
gotoxy(35,7+x);cout<<actual->name;
gotoxy(48,7+x);cout<<actual->apell;
gotoxy(68,7+x);cout<<actual->apell2;
gotoxy(88,7+x);cout<<actual->edad;
gotoxy(98,7+x);cout<<actual->diag;
   x=x+4;
	actual=actual->siguiente;
  }
}

void buscar_lista(nodo *lista,string a,string b,string c,string d,int e,int f){
	bool band=false;
	nodo *actual=new nodo();
	actual=lista;
	while((actual !=NULL)&&(actual->nss<=a)){	
	if(actual ->nss==a){
		band=true; 
		}
	
	
	if(band == true){
     cuadro(10,3,115,10);
	 titulos_todo();
     gotoxy(15,7);cout<<a;
     gotoxy(35,7);cout<<actual->name;
	 gotoxy(48,7);cout<<actual->apell;
	 gotoxy(68,7);cout<<actual->apell2;
	 gotoxy(88,7);cout<<actual->edad;
	 gotoxy(98,7);cout<<actual->diag;

	}
		actual=actual->siguiente;
}
	if(band == false){
system("COLOR 4f");
	cuadro(35,10,80,15);
gotoxy(40,10);cout<<" ERROR ";		
gotoxy(40,12);cout<<" Paciente NO Registrado";
	}		
}
void eliminar_nodo(nodo *&lista, string a,string b,string c,string d,int e, int f){
	if(lista !=NULL){
		nodo*aux_borrar;
		nodo*anterior=NULL;
		aux_borrar=lista;
		while((aux_borrar !=NULL)&&(aux_borrar->nss!=a)){
			anterior=aux_borrar;
			aux_borrar=aux_borrar->siguiente;
		}
		int diagnostico;
		int dias;
		int edad;
		float costo,descuento,total;
		string liquidado;
		
		if(aux_borrar==NULL){
			gotoxy(40,12);cout<<"	NSS INCORRECTO";
			getch();
			}

//
			else if(anterior==NULL){
				diagnostico=aux_borrar->diag;
				edad=aux_borrar->edad;
				gotoxy(40,16);cout<<"Numero de dias de hospitalizacion?"<<endl;    
				gotoxy(40,18);cin >>dias;
				cuadro(35,21,80,30);
        		gotoxy(40,22);cout<<"Estado de Cuenta: "<<endl;
				gotoxy(40,24);cout<<"Diagnostico: "<<diagnostico;			        	    
				if(diagnostico==1){costo=236.20;}else if(diagnostico==2){costo=780.19;}else if(diagnostico==3){costo=1740.10;}else if(diagnostico==4){costo=2801.90;}else{costo=0;}
				gotoxy(60,24);cout<<"Costo/dia: "<<costo;			        	    
				if((edad>=14)&&(edad<=21)){descuento=0.88;
				gotoxy(40,26);cout<<"Se aplica despuento por edad "<<edad<<" años";			        	    
				}else{descuento=1;
				gotoxy(40,26);cout<<"No aplica despuento (edad="<<edad<<" años)";			        	    
				}
				total=(dias*costo*descuento);
				gotoxy(40,28);cout<<"Total a pagar: $"<<total;			        	    
				cuadro(35,31,80,34);
				gotoxy(40,32);cout<<"Saldo Liquidado por el paciente (s/n)?";	
				cin>> liquidado;
				getch();
				if ((liquidado=="s")||(liquidado=="S")){
				lista=lista->siguiente;
				delete aux_borrar;
				}
				}
				else{
						
					diagnostico=aux_borrar->diag;
					edad=aux_borrar->edad;
					gotoxy(40,16);cout<<"Numero de dias de hospitalizacion?"<<endl;    
					gotoxy(40,18);cin >>dias;
					cuadro(35,21,80,30);
        			gotoxy(40,22);cout<<"Estado de Cuenta: "<<endl;
					gotoxy(40,24);cout<<"Diagnostico: "<<diagnostico;			        	    
					if(diagnostico==1){costo=236.20;}else if(diagnostico==2){costo=780.19;}else if(diagnostico==3){costo=1740.10;}else if(diagnostico==4){costo=2801.90;}else{costo=0;}
					gotoxy(60,24);cout<<"Costo/dia: "<<costo;			        	    
					if((edad>=14)&&(edad<=21)){descuento=0.88;
					gotoxy(40,26);cout<<"Se aplica despuento por edad "<<edad<<" años";			        	    
					}else{descuento=1;
					gotoxy(40,26);cout<<"No aplica despuento (edad="<<edad<<" años)";			        	    
					}
					total=(dias*costo*descuento);
					gotoxy(40,28);cout<<"Total a pagar: $"<<total;			        	    
					cuadro(35,31,80,34);
					gotoxy(40,32);cout<<"Saldo Liquidado por el paciente (s/n)?";	
					cin>> liquidado;
					getch();
					if ((liquidado=="s")||(liquidado=="S")){
					anterior->siguiente=aux_borrar->siguiente;
					delete aux_borrar;
					}
					
					}
	}
}

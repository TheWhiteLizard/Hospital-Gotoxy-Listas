#include<iostream>
#include<conio.h>
#include "clase.h"
#include<stdlib.h>
using namespace std;

struct nodo{
	string name;
	string mat,materia;
	float cal1,cal2,cal3,pro;
	nodo *siguiente;
};
void titulos();
void insertar_lista(nodo *&,string mat, string name,string materia, float cal1, float cal2, float cal3, float pro);
void mostrar_lista(nodo *);
void buscar_lista(nodo *,string a,string b,string o,float c,float d,float e,float f);
void eliminar_nodo(nodo *&,string a,string b,string o,float c,float d,float e,float f);


main(){
	nodo*lista=NULL;
	int opc,opc1;
    string mat,materia;
    float cal1,cal2,cal3;
    char resp;
    string name;
    float pro;

do{
		
	system("cls");
	gotoxy(40,0);cout<<"  MENU"<<endl;
	gotoxy(30,1);cout<<"1)Alta de Alumno";
	gotoxy(30,2);cout<<"2)Consultar de Alumnos";
	gotoxy(30,3);cout<<"3)Bajas de Alumnos";
	gotoxy(30,4);cout<<"4)Salir";
	gotoxy(30,7);cout<<"Selecciona una opcion:";
	gotoxy(56,7);cin>>opc;
	system("cls");
	switch(opc){
		case 1:
			do{
			    titulos();
			 	gotoxy(15,7);cin>>mat;
			 	gotoxy(35,7);cin>>name;
			 	gotoxy(48,7);cin>>materia;
				gotoxy(69,7);cin>>cal1;
			 	gotoxy(69,8);cin>>cal2;
			    gotoxy(69,9);cin>>cal3;
			    pro=(cal1+cal2+cal3)/3;
			    gotoxy(85,7);cout<<pro;
			    insertar_lista(lista,mat,name,materia,cal1,cal2,cal3,pro);
			 	getch();
			 	system("cls");
			 	gotoxy(40,7);cout<<"Deseas agregar otro alumno s/n :"<<endl;
			 	gotoxy(80,7);cin>>resp;
			 	system("cls");
			}while(resp=='s');	
		break;	
			
		case 2:
			do{
		    gotoxy(19,7);cout<<"1. Consulta de todos los Alumnos"<<endl;
		    gotoxy(19,8);cout<<"2. Consulta de un Alumno"<<endl;
		    gotoxy(19,9);cout<<"3. Ir MENU"<<endl;
		    gotoxy(19,11);cout<<" Selecciona una opcion:";
		    cin>>opc1;
		    system("cls");
		
				    switch(opc1){
					case 1:
						mostrar_lista(lista);
						getch();
						system("cls");
						break;
					case 2:
						gotoxy(19,10);cout<<"Teclee el alumno a buscar"<<endl;
        	            gotoxy(19,12);cin>>name;
        	            system("cls");
						buscar_lista(lista,mat,name,materia,cal1,cal2,cal3,pro);
						getch();
						system("cls");
						break;		
					}	
			      }while(opc1!=3);
			      break;
		case 3:
			gotoxy(19,10);cout<<"Teclee nombre del alumno a eliminar "<<endl;
        	    cin>>name;
        	    eliminar_nodo(lista,mat,name,materia,cal1,cal2,cal3,pro);
        	    break;	
    }
  }while(opc!=4);	
}

void titulos (){
	
	gotoxy(15,5);cout<<"Matricula";
	gotoxy(35,5);cout<<"Nombre";
	gotoxy(48,5);cout<<"Materia";
	gotoxy(65,5);cout<<"Calificacion";
	gotoxy(85,5);cout<<"Promedio";
}
void insertar_lista(nodo *&lista,string a, string b,string o, float c, float d, float e, float f){
	nodo *nvo_nodo=new nodo();
	nvo_nodo->mat=a;
	nvo_nodo->name=b;
	nvo_nodo->materia=o;
	nvo_nodo->cal1=c;
	nvo_nodo->cal2=d;
	nvo_nodo->cal3=e;
	nvo_nodo->pro=f;
	nodo *aux1=lista;
	nodo*aux2;
while((aux1!=NULL)&&(aux1->mat<a)){
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

void mostrar_lista(nodo *lista){
	nodo *actual=new nodo();
	actual=lista;
	int x=0;
gotoxy(15,1);cout<<"Los elementos son:"<<endl;	
while (actual!=NULL){
	titulos();
gotoxy(15,7+x);cout<<actual->mat;
gotoxy(35,7+x);cout<<actual->name;
gotoxy(45,7+x);cout<<actual->materia;
gotoxy(69,7+x);cout<<actual->cal1;
gotoxy(69,8+x);cout<<actual->cal2;
gotoxy(69,9+x);cout<<actual->cal3;
gotoxy(85,7+x);cout<<actual->pro;
   x=x+4;
	actual=actual->siguiente;
  }
}

void buscar_lista(nodo *lista,string a,string b,string o, float d,float e,float f,float g){
	bool band=false;
	nodo *actual=new nodo();
	actual=lista;
	while((actual !=NULL)&&(actual->name<=b)){	
	if(actual ->name==b){
		band=true; 
		}
	
	
	if(band == true){
     
	 titulos();
     gotoxy(15,7);cout<<a;
     gotoxy(35,7);cout<<actual->name;
	 gotoxy(45,7);cout<<actual->materia;
	 gotoxy(69,7);cout<<actual->cal1;
	 gotoxy(69,8);cout<<actual->cal2;
	 gotoxy(69,9);cout<<actual->cal3;
	 gotoxy(85,7);cout<<actual->pro;
	}
		actual=actual->siguiente;
}
	if(band == false){
gotoxy(15,7);cout<<" Alumno ("<<b<<") no ha sido encontrado en la lista";
	}
		
}
void eliminar_nodo(nodo *&lista,string a,string b,string o,float c,float d,float e,float f){
	if(lista !=NULL){
		nodo *aux_borrar;
		nodo *anterior=NULL;
		aux_borrar=lista;
		while((aux_borrar!=NULL)&&(aux_borrar->mat!=a)){
			anterior=aux_borrar;
			aux_borrar=aux_borrar->siguiente;
		}
		if(aux_borrar==NULL){
			cout<<"Alumno no existe"<<endl;
		}
		else if(anterior==NULL){
			lista=lista->siguiente;
			delete aux_borrar;
			cout<<"Alumno borrado";
		}
		else{
			anterior->siguiente=aux_borrar->siguiente;
			delete aux_borrar;
			cout<<"Alumno Borrado";
		}
	}	
}

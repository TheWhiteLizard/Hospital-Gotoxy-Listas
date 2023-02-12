#include <iostream>
#include <stdlib.h>
#include "clase.h"
#include <conio.h>

using namespace std;

struct nodo{
	int dato;
	nodo *siguiente;
};

void insertar_lista(nodo *&,int);
void mostrar_lista(nodo *);
void mayormenor(nodo*);

main(){	
	nodo *lista=NULL;
	int dato,opc;
	char res;
		do{
	gotoxy(30,5);cout<<"Ingresa tu Numero Entero:";
	gotoxy(60,5);cin>>dato;
	system("cls");
	insertar_lista(lista,dato);
    gotoxy(37,8);cout<<"Agregar otro elemento? s/n";
    gotoxy(65,8);cin>>res;
	system("cls");     
    }while(res == 's');
	mostrar_lista(lista);
	mayormenor(lista);
	getch();
}

void insertar_lista(nodo *&lista,int n){
	nodo *nvo_nodo=new nodo();
	nvo_nodo->dato=n;
	nodo *aux1=lista;
	nodo *aux2;
	
	while ((aux1 != NULL)){
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
	gotoxy(30,5);cout<<"\t Numero "<<n<<" insertado a la lista correctamente"<<endl;
}
void mostrar_lista(nodo *lista){
	nodo *actual=new nodo();
	actual=lista;
	gotoxy(30,5);cout<<"la lista es: ";
	while(actual != NULL){
	cout<<actual->dato<<", ";
    actual =actual->siguiente;
	}	
}

void mayormenor(nodo *lista){
	int mayor=0,menor=1000;
	
	while (lista != NULL){
		if ((lista->dato)>mayor){
			mayor=lista->dato;
		}
		if((lista != NULL)<menor){
			menor=lista->dato;
		} 
		lista=lista->siguiente;
	}
gotoxy(30,6);cout<<"El "<<mayor<<" es el numero mayor";
gotoxy(30,7);cout<<"El "<<menor<<" es el numero menor";
}

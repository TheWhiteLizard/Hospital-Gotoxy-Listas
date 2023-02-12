#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "clase.h"
using namespace std;

struct nodo{
	double dato;
	nodo *siguiente;
};

void insertar_lista(nodo *&, double);
void promedio_lista(nodo *, int);
void multiplicar_lista(nodo *);
void diferencia_lista(nodo *, int);

main(){
	nodo *lista = NULL;
	double dato;
	char resp;
	int x;
	x=0;
	do{
		system("cls");
		gotoxy(30,2); cout<<"Inserte un numero real: ";
		gotoxy(58,2); cin>>dato;
		system("cls");
		insertar_lista(lista, dato);
		gotoxy(30,6); cout<<"Deseas insertar otro dato? s/n";
		gotoxy(30,7); cin>>resp;
		system("cls");
		x=x+1;
	}while (resp!='n');
	promedio_lista(lista,x);
	multiplicar_lista(lista);
	diferencia_lista(lista,x);
	getch();
}

void insertar_lista(nodo *&lista, double n){
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
	gotoxy(30,2); cout<<"Numero "<<n<<" insertado a la lista correctamente"<<endl;
}
void promedio_lista(nodo *lista, int x){
	double suma, prom, val;
	while (lista!=NULL){
	val = lista->dato;
	suma=suma+val;
	lista = lista -> siguiente;
	}
	prom=suma/x;
	gotoxy(30,2); cout<<"El promedio de los datos de la lista es "<<prom;
}
void multiplicar_lista(nodo *lista){
	double mayor=0,menor=9999, multi;
	
	while (lista != NULL){
		if ((lista->dato)>mayor){
			mayor=lista->dato;
		}
		if((lista != NULL)<menor){
			menor=lista->dato;
		} 
		lista=lista->siguiente;
	}
	multi=mayor*menor;
	gotoxy(30, 4); cout<<"La multiplicacion del mayor y el menor es "<<multi;
}
void diferencia_lista(nodo *lista, int x){
	double suma=0, prom=0, val=0, dif=0;
	while (lista!=NULL){
	val = lista->dato;
	suma=suma+val;
	lista = lista -> siguiente;
	}
	prom=suma/x;
	dif=suma-prom;
	gotoxy(30,5); cout<<"La diferencia entre suma y promedio es "<<dif;
}

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "clase.h"
using namespace std;

struct nodo{
	double num;
	nodo *siguiente;
};

void insertar_lista(nodo *&, double);
void promedio_lista(nodo *, int);
void multiplicar_lista(nodo *);
void diferencia_lista(nodo *, int);

main(){
	nodo *lista = NULL;
	double num;
	char res;
	int x;
	x=0;
	do{
		system("cls");
		gotoxy(20,2); cout<<"Inserte un numero: ";
		gotoxy(38,2); cin>>num;
		insertar_lista(lista, num);
		gotoxy(20,6); cout<<"Desea insertar otro dato? s/n";
		gotoxy(20,7); cin>>res;
		x=x+1;
	}while (res!='n');
	promedio_lista(lista,x);
	multiplicar_lista(lista);
	diferencia_lista(lista,x);
}

void insertar_lista(nodo *&lista, double n){
	nodo *nvo_nodo=new nodo();
	nvo_nodo->num=n;
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
	gotoxy(31,5); cout<<"Numero "<<n<<" insertado a la lista correctamente"<<endl;
}

void promedio_lista(nodo *lista, int x){
	double suma, prom, val;
	while (lista!=NULL){
	val = lista->num;
	suma=suma+val;
	lista = lista -> siguiente;
	}
	prom=suma/x;
	gotoxy(31,7); cout<<"El promedio de los datos de la lista es "<<prom;
}

void multiplicar_lista(nodo *lista){
	double mayor=0,menor=9999, multi;
	
	while (lista != NULL){
		if ((lista->num)>mayor){
			mayor=lista->num;
		}
		if((lista != NULL)<menor){
			menor=lista->num;
		} 
		lista=lista->siguiente;
	}
	multi=mayor*menor;
	gotoxy(31, 8); cout<<"La multiplicacion entre el mayor y el menor es "<<multi;
}

void diferencia_lista(nodo *lista, int x){
	double suma=0, prom=0, val=0, dife=0;
	while (lista!=NULL){
	val = lista->num;
	suma=suma+val;
	lista = lista -> siguiente;
	}
	prom=suma/x;
	dife=suma-prom;
	gotoxy(31,9); cout<<"La diferencia entre la suma y promedio es "<<dife;
}


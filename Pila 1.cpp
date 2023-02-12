#include <iostream>
#include <conio.h>
#include <stdlib.h> //para utilizar new//
using namespace std;

struct nodo{
	int dato;
	nodo *siguiente;
};

void agregarpila(nodo *&,int);

main(){
	nodo *pila=NULL;
	int dato;
	char res;
	do{
		cout<<"teclee un elemento: ";
	    cin>>dato;
	    agregarpila(pila,dato);
	    cout<<"desea otro dato? s/n ";
	    cin>>res;
	}while(res!='n');
	
	/* cout<<"teclee un elemento: ";
	    cin>>dato;
	    agregarpila(pila,dato);*/
       
	getch();
}
void agregarpila(nodo *&pila,int n){
	nodo *nvo_nodo=new nodo();
	nvo_nodo->dato=n;
	nvo_nodo->siguiente=pila;
	pila=nvo_nodo;
	cout<<"n elemento "<<n<<" agregando a pila correctamente"<<endl;
}

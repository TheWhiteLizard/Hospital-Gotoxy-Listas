#include <iostream>
#include <conio.h>
#include <stdlib.h> //para utilizar new//
using namespace std;

struct nodo{
	int dato;
	nodo *siguiente;
};

void agregarpila(nodo *&,int);
void sacarpila(nodo*&pila,int&n);
main(){
	nodo *pila=NULL;
	int dato;
		cout<<"teclee un elemento: ";
	    cin>>dato;
	    agregarpila(pila,dato);
	    cout<<"teclee un elemento: ";
	    cin>>dato;
	    agregarpila(pila,dato);

	cout<<"\n sacando los elementos de la Pila"<<endl;    
 while(pila!=NULL){
 	sacarpila(pila,dato);
 	if(pila!=NULL){
 		cout<<dato<<",";
	 }
else{
	cout<<dato<<",";
}	 
}
getch();
	
}
void agregarpila(nodo *&pila,int n){
	nodo *nvo_nodo=new nodo();
	nvo_nodo->dato=n;
	nvo_nodo->siguiente=pila;
	pila=nvo_nodo;
	cout<<"\n elemento "<<n<<" agregando a pila correctamente"<<endl;
}
void sacarpila(nodo*&pila,int&n){// el parametro n se pasa por la referencia
nodo*aux=pila;
n=aux->dato;
pila=aux->siguiente;
delete aux;
} 

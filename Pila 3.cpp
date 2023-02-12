#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct nodo{
	string nom;
	float estatura;
	nodo*siguiente;
};

void agregarpila(nodo *&,string nom, float estatura);
void sacarpila(nodo *&pila,string &n, float &m);

main(){
	char regresar;
	string  nom;
	float estatura;
	nodo*pila=NULL;
	
	do{
	cout<<"Nombre: "<<endl;
	cin>>nom;
	cout<<""<<endl;
	cout<<"Estatura: "<<endl;
	cin>>estatura;
	
	agregarpila(pila, nom, estatura);
	
	cout<<""<<endl;
	cout<<"Desea agregar otra persona?  n/s: ";
	cin>>regresar;
	system("cls");
	}while(regresar == 's'|| regresar == 'S');
	
	cout<<" Sacando los elementos de la PILA"<<endl;
			while(pila != NULL){
			sacarpila(pila, nom, estatura);
			if(pila != NULL){
			cout<<nom<<", "<<estatura<<", ";
			}
			else{
			cout<<nom<<", "<<estatura<<".";
			
			}
			
		}
	
	getch ();
	
}

void agregarpila(nodo*&pila, string n, float m){
	nodo *nvo_nodo=new nodo();
	nvo_nodo->nom = n;
	nvo_nodo->estatura = m;
	nvo_nodo->siguiente=pila;
	pila=nvo_nodo;
	
	
	cout<<"\nelemento "<<n<<" "<<m<<" agregando a Pila correctamente"<<endl;
	
}

void sacarpila(nodo *&pila, string &n, float &m){
	nodo*aux=pila;
	n=aux->nom;
	m=aux->estatura;
	pila=aux->siguiente;
	delete aux;
	
/*	nodo*aux=pila;
	m=aux->dato;
	pila=aux->siguiente;
	delete aux;*/
}



#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "clase.h"

using namespace std;

struct nodo{
	string nom,app,apm;
	int edad,sueldo;
	nodo *siguiente;
};

void insertar_lista(nodo *&,string nom ,string app,string apm,int edad,int sueldo);
void titulos();
main(){
	
	nodo *lista=NULL;
	string nom,app,apm;
	int edad,sueldo;
	char res;
	do{
	titulos();
	gotoxy(8,6);cin>>nom;
	gotoxy(25,6);cin>>app;
	gotoxy(42,6);cin>>apm;
	gotoxy(61,6);cin>>edad;
	gotoxy(73,6);cin>>sueldo;
	insertar_lista(lista,nom,app,apm,edad,sueldo); 
	gotoxy(39,15);cout<<" Agregar otro nombre s/n:";
	cin>>res;
	system("cls");
  }while(res=='s');
}


void titulos (){
	
	gotoxy(8,5);cout<<"Nombre";
	gotoxy(25,5);cout<<"Apellido P";
	gotoxy(42,5);cout<<"Apellido M";
	gotoxy(61,5);cout<<"Edad";
	gotoxy(73,5);cout<<"Sueldo";		
}

void insertar_lista(nodo *&lista,string n,string m,string o,int q,int w){
	nodo *nvo_nodo=new nodo();
	nvo_nodo->nom=n;
	nvo_nodo->app=m;
	nvo_nodo->apm=o;
	nvo_nodo->edad=q;
	nvo_nodo->sueldo=w;
	nodo *aux1=lista;
	nodo *aux2;
	
	while ((aux1 != NULL)&&(aux1->nom<n)){
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
	cout<<"\n\n \t *El nombre ("<<n<<") se insertado a la lista correctamente"<<endl;
	cout<<"\t *Los apellidos ("<<m<<" "<<o<<") se insertados a la lista correctamente"<<endl;
	cout<<"\t *La edad ("<<q<<") fue insertada a la lista correctamente"<<endl;
	cout<<"\t *El sueldo ("<<w<<") fue insertado a la lista correctamente"<<endl;
}

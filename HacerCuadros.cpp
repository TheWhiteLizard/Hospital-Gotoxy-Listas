#include<iostream>
#include <windows.h>
#include<stdio.h>


using namespace std;

void cuadro(int x1, int y1, int x2, int y2);
void gotoxy(int x,int y);
main(){
	system("COLOR f0");

	cuadro(0,0,78,24);
}
void cuadro(int x1, int y1, int x2, int y2){
    int i;
    for (i=x1;i<x2;i++){	
		gotoxy(i,y1);printf("�") ; //linea horizontal superior 
		gotoxy(i,y2);printf("�") ; //linea horizontal inferior
    }

    for (i=y1;i<y2;i++){	
		gotoxy(x1,i);printf("�") ; //linea vertical izquierda
		gotoxy(x2,i);printf("�") ; //linea vertical derecha
    }
    
    gotoxy(x1,y1); printf("�"); //Esquinas del cuadro
    gotoxy(x1,y2); printf("�");
    gotoxy(x2,y1); printf("�");
    gotoxy(x2,y2); printf("�");
}
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
}

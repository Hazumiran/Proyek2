#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#include <windows.h>
#include <string.h>
#include "firep.h"
#include "crud.h"
#define MAX 10000 

void inphand();
void gotoxy(int x, int y);
int main() {
	int ch;
	
	do {
		system("cls");				
		printf("\n\t1.CREATE\n\t2.Tampil\n\t3.DELETE\n\t4.Total Character\n\t5.Find and Replace\n\t6.Keluar");		
		printf("\n\tMenu: ");fflush(stdin);
		scanf("%d",&ch);
		
			switch(ch)
			{
			case 1:
				Create();
				break;
			case 2:
				Display();
				break;
			case 3:
				Delete();
				break;
			case 4:
				total_char();
				break;
			case 5:
				system("cls");
				findrep();
				break;
			case 6:
				exit(1);
				break;
			default:
				printf("Inputan Salah");
				break;
			}
			
	}while(ch != 5);

}

//void inphand(){
//	char key,vh='*';
//	int x=1,y=1,mode=0;
//	system("cls");
//	while(1){
//		key=getch();
//		
//		switch(key){
//			case 72: if(y==1) y=25;else y--; break;
//			case 75: if(x==1) x=80;else x--; break;
//			case 77: if(x==80) x=1;else x++; break;
//			case 80: if(y==25) y=1;else y++; break;
//			case 32: if(mode==1) mode=0;else mode=1;break; //spasi gan
//			case 13: if(vh=='*') vh=' ';else vh='*';break; //enter
//			case 24: exit(0);break;
//			case 27: exit(0); break;
//		}
//		gotoxy(x,y);
//		if(mode==1) printf("%c",vh);
//	}
//	
//}

//void gotoxy(int x, int y)
//{
//  static HANDLE h = NULL;  
//  if(!h)
//    h = GetStdHandle(STD_OUTPUT_HANDLE);
//  COORD c = { x, y };  
//  SetConsoleCursorPosition(h,c);
//}

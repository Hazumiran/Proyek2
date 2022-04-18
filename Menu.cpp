#include <stdio.h>
#include <stdlib.h>
#include "editor.h"
#include "FileHandl.h"

void Menu(){
	int pilihan;
	printf("\tMENU\n");
	printf("----------------\n");
	printf("1. Create File\n");
	printf("2. Open File\n");
	printf("3. Help\n\n");
	printf("Pilihan : ");
	scanf("%d",&pilihan);
	if(pilihan == 1){
		system("cls");
		CreateFile();
	}else if(pilihan == 2){
		system("cls");
			OpenFile();
	}else if(pilihan == 3){
		system("cls");
	    printf("-----------------------------------------------------------------------------------------------\n");
		printf("| File Name : ");
		printf("| NODE JS TEXT EDITOR |\t\n");
		printf("-----------------------------------------------------------------------------------------------\n");
		printf("\tCtrl+D : Delete Line\tCtrl+E : Edit\t\tCtrl+N : New Window \n");
		printf("\tCtrl+Q : Insert Line\tCtrl+i : Insert Again\n\n");
		Menu();
	}else{
		system("cls");
		printf("Invalid Input");
		Menu();
	}
}
#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "crud.h"

void Create(){

	int ukur;
	system("cls");
	fp1=fopen("temp.txt","w");
	printf("\n\tCtrl + S And enter to save\n\n\t");
 
	while(1)
	{
	c=getchar();
	fputc(c,fp1);
	
	if(c == 19){	
	
		fclose(fp1);	
		printf("\n\tEnter then new filename: ");
		scanf("%s",fn);
		fp1=fopen("temp.txt","r");
		fp2=fopen(fn,"w");
				   
		while(!feof(fp1)){
			c=getc(fp1);
			putc(c,fp2);
		}
				   
		fclose(fp2);
		break;
		}
	}
}

void Display(){
	
	printf("\n\tEnter the file name: ");
	scanf("%s",fn);
	fp1=fopen(fn,"r");
	
	if(fp1==NULL){
		printf("\n\tFile not found!");
		goto end1;
	}
	
	while(!feof(fp1)){
		c=getc(fp1);
		printf("%c",c);
	}
	
	end1:
	fclose(fp1);
	printf("\n\n\tPress any key to continue\n");
	getch();
}

void Delete(){
	
	printf("\n\tEnter the file name: ");
	scanf("%s",fn);
	fp1=fopen(fn,"r");
	
	if(fp1==NULL){
		printf("\n\tFile not found!");
		goto end2;
	}
	
	fclose(fp1);
	
	if(remove(fn)==0){
		printf("\n\n\tFile has been deleted successfully!");
	goto end2;
	}
	else
	
	printf("\n\tError!\n");
	end2: printf("\n\n\tPress any key to continue\n");
	getch();
}



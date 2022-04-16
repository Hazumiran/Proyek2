#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <iostream>

void display(char fn[]){
    FILE *fptr = NULL; 
	int i = 0,tot = 0;	
	char text[MAX][LEN];

    fptr = fopen(fn, "r");
    while(fgets(text[i], LEN, fptr)) 
	{
        text[i][strlen(text[i]) - 1] = '\0';
        i++;
    }
    tot = i;  
    for(i = 0; i < tot; ++i)
    {
        printf("\t %d :%s\n", i, text[i]);
    }

}

void display1(char fname[]){
	char text[MAX][LEN];
	printf("Input the filename to be opened : ");
	scanf("%s",fname);
	printf("\nIsi File : \n",fname);
	printf("\n");  
	display(fname);
	printf("\n");
    printf("Press any key...");
    getch();
    system("cls");
    arr();
}
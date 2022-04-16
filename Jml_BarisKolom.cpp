#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <iostream>

void Total_Char(char fn[]){
	int total= 0,i,j;
	char text[MAX][LEN];
	char ch;
	FILE *fp;
	
	
	fp = fopen(fn, "r");
	
	for(i = 0; i < MAX; i++) {
		
	   for(j = 0; text[ i ][ j ]; j++) {
	       total+=1;
		}	 	
		if(!*text[i]) 
	    	break;
	}

	printf("\n Lines :%i",total);
	printf("/Coloumns : %i\n\n",i);
	system("pause");
	fclose(fp);
	Menu();
}
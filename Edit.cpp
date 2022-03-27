#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <iostream>

void edit_file(char fn[]){
	FILE *fp, *fpt;
	char text[MAX][LEN];
	char pil;
	char inpedit;
	char newword[LEN];
	char buffer[LEN];
	int j,i;
	
	fp = fopen(fn, "r");
	printf("\n");	

		int inp;
		fflush(stdin);
		
    	printf("Pilih index yang mau di edit :  ");
    	scanf("%d",&inp);
    	fflush(stdin);
    	
//    	printf("Data Lama : ");
//    	for(j = 0; text[ inp ][ j ]; j++)
//		{
//			putchar(text[ inp ][ j ]);
//		}
			

	//	fp = fopen(fn,"r");	
		fpt = fopen("temp.txt","w");
		printf ("\ninput Data baru :");

		fflush(stdin);
		fgets(newword, LEN, stdin);	

		i = 0;
			while ((fgets(buffer, LEN, fp)) != NULL)
			{
			
			    if (i == inp)
			        fputs(newword, fpt);
			    else
			        fputs(buffer, fpt);
			            
			        i++;
			}
    	fclose(fp);
		fclose(fpt);
		remove(fn);
		rename("temp.txt", fn);

//		system ("cls");
		Menu();
	
}
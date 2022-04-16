#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <iostream>

void Delete(char fn[]){
	FILE *fp;
	char text[MAX][LEN];
//	char fn[15];
	
	fp=fopen("temp.txt","w");
	printf("\n\tEnter the file name: ");
	scanf("%s",fn);
	fp=fopen(fn,"r");
	
	if(fp==NULL){
		printf("\n\tFile not found!");
		goto end2;
	}
	
	fclose(fp);
	
	if(remove(fn)==0){
		printf("\n\n\tFile has been deleted successfully!");
	goto end2;
	}
	else
	
	printf("\n\tError!\n");
	end2: printf("\n\n\tPress any key to continue\n");
	
}

void DeleteLine(char fn[]){
	FILE *fp, *fp1;
	char p;
	char text[MAX][LEN];
	int tot = 0, i = 0, j=0;
	int delete_line, temp = 1;
	fp = fopen(fn, "r");
	
    printf("\nEnter line number of the line to be deleted:");
    scanf("%d", &delete_line);
    delete_line += 1;
    
    fp1 = fopen("delete.txt", "w");
    while((fgets(text[i], LEN, fp)) != NULL)
    {
    	if(temp != delete_line)
        {
       		fputs(text[i], fp1);
        }
        if(text[i], fp1){
			temp++;
		}
	}

    fclose(fp);
    fclose(fp1);
    remove(fn);
    rename("delete.txt", fn);
    printf("\nAfter Delete:\n");
    fp = fopen(fn, "r");
	while(fgets(text[j], LEN, fp)) 
	{
        text[j][strlen(text[j]) - 1] = '\0';
        j++;
    }
   tot = j;  
    for(j = 0; j <= tot-1; ++j)
    {
        printf("%d :%s\n", j, text[j]);
    }
    fclose(fp);
    
    Ulang :
    printf("\nWant to delete again? (Y/N)");
    scanf("%s", &p);
    	if(p == 'y' || p == 'Y'){
    		DeleteLine(fn);
		}   
		else if(p == 'n' || p == 'N'){
			system("cls");
			Menu();
		}
		else{
			printf("invalid input");
			goto Ulang;
		}
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "firep.h"

#define SIZE 1000
#define CHAR_SIZE 256

void ReplaceText(char string[], char newWord[], char oldWord[], int s){
	int oldsize = strlen(oldWord);
	int newsize = strlen(newWord);
	int j,k;
	
	if(newsize<oldsize){
		for(k=(s+oldsize);k<strlen(string)+(oldsize-newsize);k++){
			string[k-(oldsize-newsize)]=string[k];
		}
	}
	else if(newsize>oldsize){ 
		for(k=strlen(string);k>s;k--){
			string[k+newsize-oldsize]=string[k];
		}
	}
	
	for(j=0;j<newsize;j++,s++) 
		string[s]=newWord[j];
}

void search(char string[], char oldWord[], char newWord[]){ 
    int str2[CHAR_SIZE];
	int oldsize = strlen(oldWord); 
    int strsize = strlen(string); 
	int count=0,shift=0,i,j;
  
 	for (i = 0; i < CHAR_SIZE; i++) 
    	str2[i] = -1;
  
    for (i = 0; i < oldsize; i++) 
    	str2[oldWord[i]] = i;
    
    while(shift <= (strsize - oldsize)){ 
    	j = oldsize-1; 
  
        while(j >= 0 && oldWord[j] == string[shift+j]) 
            j--; 
  
        if (j < 0){ 
        	ReplaceText(string,newWord,oldWord,shift); 
        	count++;
			if(shift+oldsize < strsize)
					shift += oldsize - str2[string[shift+oldsize]];
            else shift += 1;
        }
        else
            shift += (1>j-str2[string[shift+j]]) ? 1 : j-str2[string[shift+j]]; 
    }
    
    if(count==0) {
    	printf("Word can't found in text.\n");
	}
	else printf("Found And Replaced: %d\n",count);
}

void findrep(){
	
	FILE *fp;
    char path[SIZE];
    char oldWord[SIZE], newWord[SIZE];
	char string[SIZE];
	int sens;
	
    printf("Enter path of source file: ");fflush(stdin);
    gets(path);
    
    fp = fopen(path,"r");
    
    if(fp==NULL){
    	printf("File tidak ditemukan");
	}
    
    fgets(string,SIZE,fp);
	    
	printf("\nOriginal Text: \n");
	puts(string);
    printf("\n");
    
    printf("Find: ");
    gets(oldWord);
    
    printf("Replace: ");
 	gets(newWord);
    
    printf("For case sensivity enter 1, else 0: ");
    scanf("%d",&sens);
    
	
	if(sens==1)
		search(string,oldWord,newWord);
    else{ 
    	strlwr(string);
    	search(string,oldWord,newWord);
	}
    
 	fclose(fp);
 	
 	fp=fopen(path,"w");
 	fputs(string,fp);
 	fclose(fp);
 	
 	printf("\nNew Text: \n");
 	puts(string);
 	printf("\nPress any key to continue\n");
	getch();
	system("cls");
	main();
 	

}

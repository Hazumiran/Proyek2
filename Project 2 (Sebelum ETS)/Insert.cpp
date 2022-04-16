#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <iostream>


void insert_line(char fn[]){
	FILE *fp, *fp1;
	char text[MAX][LEN];
	char baru[LEN];
	char tampung[MAX][LEN];
	int insert;
	char ch, p;
	int i=0,j=0;
	
//	system("cls");
	fp = fopen(fn, "r");
    
  	while (!feof(fp) && ch != EOF){
// 		melanjut:
//        printf("%c", ch);
        tampung[i][j] = getc(fp);
//        puts(tampung[i]);
		if(tampung[i][j] == '\n'){
			i++;
			j=0;
		}
		else{
			j++;
		}
	}
	
	int batas = i;
	printf("Masukkan Kalimat : ");
    scanf("%s",&baru);
    fflush(stdin);

	fp = fopen(fn, "w");
	
	printf("\nPada baris mana akan dimasukkan :");
    scanf("%d", &insert);

	for(i=0;i<=batas;i++){
		j=0;
		if(i == (insert)){
//			strcpy(text[i],baru);
			for(;j<strlen(baru);j++){
				printf("%c",baru[j]);fflush(stdin);
				fprintf(fp,"%c",baru[j]);
				if(j+1 == strlen(baru)) {
					j=0;
					fprintf(fp,"\n");
					printf("\n");
					goto lanjut;
				}
			}
			fprintf(fp,"\n");
//			printf("\n");
		}
		else{
			lanjut:
			for(;j<strlen(text[i]);j++){
				fprintf(fp,"%c",tampung[i][j]);
				printf("%c",tampung[i][j]);fflush(stdin);
				if(tampung[i][j] == '\n') 
		        		goto mulai;
			}
		}
//		printf("\n");
//		fprintf(fp,"\n");
		mulai:;
	}
	fclose(fp);
	Menu();

}			

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <iostream>

FILE *fp, *fp1;
//char fn[15];


void arr(){
	char text[MAX][LEN];
	int t;
	printf("\n\tEnter the file name: ");
	scanf("%s",fn);
	fp=fopen(fn,"w+");
	
	printf("File Name : %s ",fn);
	printf("\t\tStatus : Menu Not In Control \n");
	printf("\tCtrl+D : Delete Line\tCtrl+E : Edit\tCtrl+R : Total Char\n");
	printf("\tCtrl+Q : Insert Line\tCtrl+i : Insert Again\n\n");
	fflush(stdin);
  	for(t = 0; t < MAX; t++){  		
	    printf("%d: ", t);fflush(stdin);
	    gets(text[t]);fflush(stdin);
	    if(!*text[t]) 
	        break; 
			
	fprintf(fp,"%s \n",text[t]);     	    	        

	}	
	fclose(fp);	
	Menu();	
}


void Menu(){	
	int k=0,l=0,t;
	char text[MAX][LEN];
	system("cls");
	printf("File Name : %s ",fn);
	printf("\t\t Status : Menu In Control\n ");
	printf("\tCtrl+D : Delete Line\tCtrl+E : Edit\tCtrl+R : Total Char\n");
	printf("\tCtrl+Q : Insert Line\tCtrl+i : Insert Again\n\n");
	
	fp = fopen(fn,"at+");	
	fp1 = fopen(fn,"rt");	

	if(fp1 != NULL){
		while (!feof(fp1)){
        text[k][l] = getc(fp1);
		if(text[k][l] == '\n'){
			k++;
			l=0;
		}
		else{
			l++;
		}
	}
	t=k;
	}

//	display(fn);
	
	for(k=0; k < t; k++) {
					printf("%d: ", k);
		    	for(l=0; text[ k ][ l ]; l++){		   	 		      
		        	putchar(text[ k ][ l ]);			  		   
		   		}
 			}
 			
	char key;
	key = getch();
	if(key == 5){
			fclose(fp);
			fclose(fp1);
			edit_file(fn);			
printf("test 1");
		}
		else if(key == 18){
			fclose(fp);
			fclose(fp1);
			Total_Char(fn);			
printf("test 2");
		}
		else if(key== 4){
			fclose(fp);
			fclose(fp1);
			DeleteLine(fn);			
printf("test 3");
		}
		else if(key == 17){
			fclose(fp);
			fclose(fp1);
			insert_line(fn);

printf("test 4");
		}

		else if(key == 14){
			system("start Array_TE.exe");
			Menu();
//			insert_line();
		}
		else if(key == 9){
			system("cls");
			printf("File Name : %s ",fn);
			printf("\t\tStatus : Menu Not In Control \n");
	printf("\tCtrl+D : Delete Line\tCtrl+E : Edit\tCtrl+R : Total Char\n");
	printf("\tCtrl+Q : Insert Line\tCtrl+i : Insert Again\n\n");
		
		int w; 		
		for(k=0; k < t; k++) {
					printf("%d: ", k);
		    	for(l=0; text[ k ][ l ]; l++){		   	 		      
		        	putchar(text[ k ][ l ]);			  		   
		   		}	         	    	
 			}
			for(w = k; w < MAX; w++){  		
	    		printf("%d: ", w);fflush(stdin);
	    		gets(text[w]);	    			
	    		t++;
				fprintf(fp,"%s \n",text[w]);
	    			if(!*text[w]) {
	    				t--;
						fclose(fp);	 	
						Menu();
			}			        		     	    	        
		}
		fclose(fp);	  	
		fclose(fp1);				
		}
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <iostream>
 

#define MAX 100
#define LEN 80	
#define BUFFER_SIZE 1000
char text[MAX][LEN];
void arr();
int edit();
void Total_Char();
void display();
void shortcut(char isi);
void edit_file(char fn[]);
void Delete();
void find();
void replaceAll(char *str, const char *oldWord, const char *newWord);

	FILE *fp;
	char fn[15];
	int i,j,t,k,l,m,temp_m;

int main(void)
{
	printf("\t1.Creat\n\t2.Tampil\n\t3.Total Character\n\t4.Delete\n\t5.find\n");
	int pil;
	scanf("%i",&pil);
  	do{
  		switch (pil){
  			case 1:{
  				printf("masukkan data kosong untuk quit.\n");
		  		arr();
				break;
			}
			case 2:{
				display();
				break;
			}
			case 3:{
				Total_Char();
				break;
			}
			case 4:{
				Delete();
				break;
			}
				case 5:{
				find();
				break;
			}
		}
	}while(pil != 4);
	
	end1:;
}

void arr(){
	
//	system("cls");
//	start1:
//	fp = fopen("baru.txt","wb+");

	printf("Ctrl+S : Save\tCtrl+E : Edit\t\n");
	
	printf("\n\tEnter the file name: ");
	scanf("%s",fn);
	fp=fopen(fn,"w+");

	fflush(stdin);
  	for(t = 0; t < MAX; t++){  		
	    printf("%d: ", t);fflush(stdin);
	    gets(text[t]);	    			
		fprintf(fp,"%s \n",text[t]);
	    if(!*text[t]) 
	        break; /* quit on blank line */	        	    	        
	}	
	fclose(fp);
	
	char pilihan;
	retry:
	printf("input data lagi ga ?(Y/N)");
	scanf("%s",&pilihan);
	
//LAGI DI OPREK KU DIAZ JANGAN DI ACAK ACAK
//BUBUKA OPREK
		if(pilihan == 'Y' || pilihan == 'y'){
		fp = fopen(fn,"wt+");				
		
		for(k = 0; k < t; k++) {
//			for(m = 0; text[ k ][ m ]; m++){
//				temp_m = temp_m + m;
//			}
			
		   for(l = 0; text[ k ][ l ]; l++){		   	 
		      printf("%d: ", k);
		      putchar(text[ k ][ l ]);
//		      fprintf(fp,"%s \n",text[ k ][ l ]);
			  		   putchar('\n');
		   } 		     	         	    	
 		}
 		printf("masukin data");
// 		printf("%d",temp_m);
//	    int temp_inputagain;
//	    for(temp_inputagain = temp_inputagain + t; temp_inputagain < MAX; ++temp_inputagain){  		
//	    printf("%d: ", temp_inputagain);
//	    gets(text[temp_inputagain]);	    			
//			fprintf(fp,"%s \n",text[temp_inputagain]);
//	    	if(!*text[temp_inputagain]) 
//	        break; /* quit on blank line */	        	    	        
//	}	
	fclose(fp);	
	
//PANUTUP OPREK
				
				
				
		}else if(pilihan == 'S' || pilihan == 'n'){
			edit_file(fn);	 
		}else{
			printf("invalid input");
			goto retry;
		}
	
}

void Total_Char(){
	int total;
	
	for(i = 0; i < MAX; i++) {
	   for(j = 0; text[ i ][ j ]; j++) {
	       total+=1;
		}
	 	
		if(!*text[i]) 
	    	break;
	}
	printf("\nTotal Character : %i",total);
	printf("\nTotal Baris	 : %i\n\n",i);
	main();
}

void display(){
	char fname[20];
    FILE *fptr = NULL; 
    int i = 0;
    int j = 0;
    int tot = 0;
	printf("Input the filename to be opened : ");
	scanf("%s",fname);	

    fptr = fopen(fname, "r");
    while(fgets(text[i], LEN, fptr)) 
	{
        text[i][strlen(text[i]) - 1] = '\0';
        i++;
    }
    tot = i;
	printf("\nIsi File : \n",fname);
	printf("\n");    
    for(i = 0; i < tot-1; ++i)
    {
        printf("\t %d :%s\n", i, text[i]);
    }
    
    printf("\n");
    printf("Press any key...");
    getch();
    system("cls");
    main();
}

void edit_file(char fn[]){
	
	char pil;
	char inpedit;
	char newword[LEN];
	char buffer[LEN];
	FILE *fpt;
	
	printf("\n");
	tambah:
	
	 printf("\nselesai, mau edit file ? (Y/N) ");
	 scanf("%s",&inpedit);
	 
	 //Edit Kembali line
	 if(inpedit == 'y' || inpedit == 'Y')
	 {
		int inp;
		fflush(stdin);
		
    	printf("Pilih index yang mau di edit :  ");
    	scanf("%d",&inp);
    	fflush(stdin);
    	
    	//Tampil Data Lama
    	printf("Data Lama : ");
    	for(j = 0; text[ inp ][ j ]; j++)
		{
			putchar(text[ inp ][ j ]);
		}
			
		//Ganti Data
		fp = fopen(fn,"r");	
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
 		goto tambah;

	 }
	 else{
		ulang:
		printf("\nApakah Akan kembali Menulis y/n: ");
		scanf("%s",&pil);
		
		if(pil == 'y' || pil == 'Y'){
			arr();//start1;
		}
		else if(pil == 'n' || pil == 'N'){
			system ("cls");
			main();
		}
		else{
			printf("invalid input");
			goto ulang;
		}
	} 		
}

//void shortcut(char isi){
//	if(isi == 4){
//		edit_file();
//	}	
//}
void Delete(){
	FILE *fp;
	char fn[15];
	
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
void find()
{
   FILE * fPtr;
    FILE * fTemp;
    char path[100];
    
    char buffer[BUFFER_SIZE];
    char oldWord[100], newWord[100];


    printf("masukan nama file: ");
    scanf("%s", path);

    printf("find: ");
    scanf("%s", oldWord);

    printf("replace ");
    scanf("%s", newWord);


    /*  Open all required files */
    fPtr  = fopen(path, "r");
    fTemp = fopen("replace.tmp", "w"); 

    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr == NULL || fTemp == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }


    /*
     * Read line from source file and write to destination 
     * file after replacing given word.
     */
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
        // Replace all occurrence of word from current line
        replaceAll(buffer, oldWord, newWord);

        // After replacing write it to temp file.
        fputs(buffer, fTemp);
    }


    /* Close all files to release resource */
    fclose(fPtr);
    fclose(fTemp);


    /* Delete original source file */
    remove(path);

    /* Rename temp file as original file */
    rename("replace.tmp", path);

    printf("\nSukses dirubah dari '%s' menjadi '%s'.", oldWord, newWord);


}



/**
 * Replace all occurrences of a given a word in string.
 */
void replaceAll(char *str, const char *oldWord, const char *newWord)
{
    char *pos, temp[BUFFER_SIZE];
    int index = 0;
    int owlen;

    owlen = strlen(oldWord);

    // Fix: If oldWord and newWord are same it goes to infinite loop
    if (!strcmp(oldWord, newWord)) {
        return;
    }


    /*
     * Repeat till all occurrences are replaced. 
     */
    while ((pos = strstr(str, oldWord)) != NULL)
    {
        // Backup current line
        strcpy(temp, str);

        // Index of current found word
        index = pos - str;

        // Terminate str after word found index
        str[index] = '\0';

        // Concatenate str with new word 
        strcat(str, newWord);
        
        // Concatenate str with remaining words after 
        // oldword found index.
        strcat(str, temp + index + owlen);
    }
}

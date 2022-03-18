#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX 100
#define LEN 80	

char text[MAX][LEN];
void arr();
int edit();
void Total_Char();
void display();
void shortcut(char isi);
void edit_file(char fn[]);
void DeleteLine(char fn[]);

	FILE *fp;
	char fn[15];
	int i,j,t,k,l,m,temp_m;

int main(void)
{
	printf("\t1.Creat\n\t2.Tampil\n\t3.Total Character\n");
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
	int total = 0;
	
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
    char inpedit;
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
    fclose(fp);
    
    kembali :
	printf("\nWant to delete line? (Y/N)");fflush(stdin);
	scanf("%s",&inpedit);fflush(stdin);
	if(inpedit == 'y' || inpedit == 'Y'){
	 	DeleteLine(fname);
	}else if(inpedit == 'n' || inpedit == 'N'){
		main();
	} else{
		printf("\ninvalid input !!");
		goto kembali; 
	}
	
	fclose(fp);
	main();
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
//    	printf("Data setelah Update : \n%s", text[t]);
//	    	// JANGAN DIHAPUS, CODE ASLI
//	 	for(i = 0; i < t; i++) {
//		   for(j = 0; text[ i ][ j ]; j++) 
//		      putchar(text[ i ][ j ]);
//		      fprintf(fp,"%s \n",text[ i ][ j ]);
//		   putchar('\n');
// 		}

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


void DeleteLine(char fn[]){
	FILE *fp1;
	int delete_line, temp = 1, k;
	char ch, p;
	
	system("cls");
	fp = fopen(fn, "r");
    ch = getc(fp);fflush(stdin);
  	while (ch != EOF){
  		
        printf("%c", ch);
        ch = getc(fp);
        fflush(stdin);
    }
    //rewind
    rewind(fp);
    printf("\nEnter line number of the line to be deleted:");
    scanf("%d", &delete_line);fflush(stdin);
    //open new file in write mode
    fp1 = fopen("temp.txt", "w");
    ch = 'A';
    while (ch != EOF)
    {
        ch = getc(fp); fflush(stdin);
        if (temp != delete_line)
        {
            putc(ch, fp1);
        }
        if (ch == '\n')
        {
            temp++;
        }
    }
    fclose(fp);
    fclose(fp1);
    remove(fn);
    rename("temp.txt", fn);
    printf("\nAfter Delete:\n");
    fp = fopen(fn, "r");fflush(stdin);
    ch = getc(fp);
    while (ch != EOF){
        printf("%c", ch);
        ch = getc(fp);
    }
    
    fclose(fp);
    
    Ulang :
    printf("\nWant to delete again? (Y/N)");
    scanf("%s", &p);
    	if(p == 'y' || p == 'Y'){
    		DeleteLine(fn);
		}
		else if(p == 'n' || p == 'N'){
			main();
		}
		else{
			printf("invalid input");
			goto Ulang;
		}
}

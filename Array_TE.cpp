#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 100
#define LEN 80	

char text[MAX][LEN];
void arr();
int edit();
void Total_Char();
void display();
void shortcut(char isi);
void edit_file();

	FILE *fp;
	char fn[15];
	int i,j,t;

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
	
	system("cls");
//	start1:
//	fp = fopen("baru.txt","wb+");

	printf("Ctrl+S : Save\tCtrl+E : Edit\t\n");
	
	printf("\n\tEnter the file name: ");
	scanf("%s",fn);
	fp=fopen(fn,"wb+");

	input_again:
	fflush(stdin);
  	for(t = 0; t < MAX; t++){
  		
	    printf("%d: ", t);
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
		if(pilihan == 'Y' || pilihan == 'y'){
			goto input_again;				
		}else if(pilihan == 'S' || pilihan == 'n'){
			edit_file();	 
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

	register int t, i, j;	
	printf("\nIsi teks\n");
	for(i = 0; i < t; i++) {
	   for(j = 0; text[ i ][ j ]; j++) 
	       putchar(text[ i ][ j ]);
	 	  putchar('\n');
	}	
	main();
}

void edit_file(){
	
	char pil;
	
	printf("\n\n");
	 char inpedit;
	 tambah:
	 printf("selesai, mau edit file ? (Y/N) ");
	 scanf("%s",&inpedit);
	 if(inpedit == 'y' || inpedit == 'Y'){
	 int inp;
    	printf("Pilih index yang mau di edit :  ");
    	scanf("%d",&inp);
    	
    	fp = fopen("baru.txt","wt+");
    	printf("Data Lama : ");
    	for(j = 0; text[ inp ][ j ]; j++){
			putchar(text[ inp ][ j ]);}
		printf ("\ninput Data baru :");
		
//	gets(text[t]);
    	
		scanf("%s",text[inp]);
//		fscanf(fp,"%s",text[inp]);
    	
    	
    	printf("Data setelah Update : \n%s", text[t]);
	    	// JANGAN DIHAPUS, CODE ASLI
	 	for(i = 0; i < t; i++) {
		   for(j = 0; text[ i ][ j ]; j++) 
		      putchar(text[ i ][ j ]);
		      fprintf(fp,"%s \n",text[ i ][ j ]);
		   putchar('\n');
 		}
 		goto tambah;
 		fclose(fp);
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


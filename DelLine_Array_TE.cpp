#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 100
#define LEN 800

char text[MAX][LEN];
void arr();
int edit();
void Total_Char();
void display();
void DeleteLine();
void shortcut(char isi);
void edit_file();

FILE *fp;
char fn[15];
int i,j,t;

int main(void)
{
	int pil;
	
	system("cls");
	printf("\n\t-----------------");
	printf("\n\t|   MAIN MENU   |");
	printf("\n\t-----------------");
	printf("\n\n\t1.CREATE\n\t2.DISPLAY\n\t3.TOTAL CHARACTER\n\t4.EXIT\n");
	printf("\n\tEnter your choice: ");
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

	
	fflush(stdin);
  	for(t = 0; t < MAX; t++){
  		printf("%d: ", t);
	    gets(text[t]);	
		fprintf(fp,"%s \n",text[t]);
		if(!*text[t]) 
	break;         
	}
	
//	printf("\nIsi teks\n");
//	for(i = 0; i < t; i++) {
//	   for(j = 0; text[ i ][ j ]; j++) 
//	       putchar(text[ i ][ j ]);
//	 	  putchar('\n');
//	}

	fclose(fp);
	edit_file();	 
}

void Total_Char(){
	int total;
	
	printf("\n\tEnter the file name: ");
	scanf("%s",fn);
//	system("cls");
	fp = fopen(fn, "r");
		
	for(i = 0; i < MAX; i++) {
	   for(j = 0; text[ i ][ j ]; j++) {
	       total+=1;
		}
	 	
		if(!*text[i]) 
	    	break;
	}
	
	printf("\nTotal Character : %i",total);
	printf("\nTotal Baris	 : %i\n\n",i);
	fclose(fp);
	main();
}

void display(){	
   	register int t, i, j;
   	char buff[MAX];
   	char inpedit;
	
	printf("\n\tEnter the file name: ");
	scanf("%s",fn);
	system("cls");
	fp=fopen(fn,"r");
		
	printf("\nIsi teks : \n");	
	while(fgets(buff, sizeof(buff), fp)){
        printf("%s", buff);
    }	
	
//	for(i = 0; i < t; i++) {
//	   for(j = 0; text[ i ][ j ]; j++) 
//	       putchar(text[ i ][ j ]);
//	 	  putchar('\n');
//	} 

	kembali :
	printf("\nWant to delete line? (Y/N)");
	scanf("%s",&inpedit);
	if(inpedit == 'y' || inpedit == 'Y'){
		fclose(fp);
	 	DeleteLine();
	}else if(inpedit == 'n' || inpedit == 'N'){
		main();
	} else{
		printf("\ninvalid input !!");
		goto kembali; 
	}
	
	fclose(fp);
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
		//gets(text[t]);
    	
		scanf("%s",text[inp]);
		//fscanf(fp,"%s",text[inp]);
    	
    	printf("\nData setelah Update : \n%s", text[t]);
	 	for(i = 0; i < t; i++) {
	 		printf("%d: ", i);
		   for(j = 0; text[ i ][ j ]; j++) 
		      putchar(text[ i ][ j ]);
		      fprintf(fp,"%s \n",text[ i ][ j ]);
		   	  putchar('\n');
 		}
 //		rename("baru.txt", fn);
 		goto tambah;
 		fclose(fp);
	}
	else{
		ulang:
		printf("\nApakah Akan kembali Menulis? (Y/N) ");
		scanf("%s",&pil);
		
		if(pil == 'y' || pil == 'Y'){
			arr();
		}
		else if(pil == 'n' || pil == 'N'){
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

	FILE *fp1;
void DeleteLine(){
	int delete_line, temp = 1, k;
	char ch, p;
	
	system("cls");
	fp = fopen(fn, "r");
    ch = getc(fp);
  	while (ch != EOF){
  		
        printf("%c", ch);
        ch = getc(fp);
    }
    //rewind
    rewind(fp);
    printf("\nEnter line number of the line to be deleted:");
    scanf("%d", &delete_line);
    //open new file in write mode
    fp1 = fopen("temp.txt", "w");
//    ch = 'A';
    while (ch != EOF)
    {
        ch = getc(fp);
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
    fp = fopen(fn, "r");
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
    		DeleteLine();
		}
		else if(p == 'n' || p == 'N'){
			main();
		}
		else{
			printf("invalid input");
			goto Ulang;
		}
}

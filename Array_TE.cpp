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
void DeleteLine();
void insert_line();

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

	printf("\tCtrl+D : Delete Line\tCtrl+E : Edit\tCtrl+R : Total Char\n");
	printf("\tCtrl+D : Insert Line\n");
	
	printf("\n\tEnter the file name: ");
	scanf("%s",fn);
	fp=fopen(fn,"w+");

	fflush(stdin);
  	for(t = 0; t < MAX; t++){  		
	    printf("%d: ", t);fflush(stdin);
	    gets(text[t]);	
//	    *text[t] = getchar();	    			
		fprintf(fp,"%s \n",text[t]);
		
		if(*text[t] == 5){
			fclose(fp);
			edit_file(fn);
			goto retry;
		}
		else if(*text[t] == 18){
			fclose(fp);
			Total_Char();
			goto retry;
		}
		else if(*text[t] == 4){
			fclose(fp);
			DeleteLine();
			goto retry;
		}
		else if(*text[t] == 17){
			fclose(fp);
			insert_line();
			goto retry;
		}
	    else if(!*text[t]) 
	        break; /* quit on blank line */	        	    	        
	}	
	fclose(fp);
	
	char pilihan;
	retry:
	system("cls");
		for(k = 0; k < t; k++) {
					printf("%d: ", k);
		    		for(l = 0; text[ k ][ l ]; l++){		   	 		      
		        		putchar(text[ k ][ l ]);			  		   
		   			} putchar('\n');		     	         	    	
 				}
	
	printf("input data lagi ga ?(Y/N)");
	scanf("%s",&pilihan);
	
	if(pilihan == 'Y' || pilihan == 'y' ){
		fp = fopen(fn,"wt+");			
								 																
 			int w; 		
			for(; k < t; k++) {
					printf("%d: ", k);
		    	for(; text[ k ][ l ]; l++){		   	 		      
		        	putchar(text[ k ][ l ]);			  		   
		   		} putchar('\n');		     	         	    	
 			}
			for(w = k; w < MAX; w++){  		
	    		printf("%d: ", w);fflush(stdin);
	    		gets(text[w]);	    			
				fprintf(fp,"%s \n",text[w]);
	    			if(!*text[w]) {
	    				goto retry; /* quit on blank line */	   	
					}			        		     	    	        
		}
		fclose(fp);	  											
		}else if(pilihan == 'S' || pilihan == 'n'){
			edit_file(fn);	 
		}else{
			printf("invalid input");
			goto retry;
		}
//PANUTUP OPREK	
	edit_file(fn);	
}

void Total_Char(){
	int total= 0;
	
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


void DeleteLine(){
	FILE *fp1;
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
    delete_line += 1;
    //open new file in write mode
    fp1 = fopen("temp.txt", "w");
    ch = 'A';
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

void insert_line(){
	
	char baru[LEN];
	char tampung[MAX][LEN];
	FILE *fp1;
	int insert;
	char ch, p;
	i=0,j=0;
	
	system("cls");
	fp = fopen(fn, "r");
	fp1 = fopen(fn, "r");
	
    ch = getc(fp);
    
  	while (ch != EOF){
//        printf("%c", ch);
        ch = getc(fp);
        tampung[i][j] = getc(fp1);
        if(!ch){
        	i++;
		}
		j++;
    }
    
    fclose(fp);
    fclose(fp1);

    printf("Masukkan Kalimat : ");
	for(t = 0; t < MAX; t++){  		
	    
	    scanf("%c",&baru[t]);
		if(baru[t] == '\n') 
	        break;
	}
	
    printf("\nPada baris mana akan dimasukkan :");
    scanf("%d", &insert);
	
	for(i=0;i<MAX;i++){
		if(i == (insert-1)){
			for(j=0;j<LEN;j++){
				printf("%c",text[j]);
				if(!*text[j]) 
	        		break;
			}
		}
		for(j=0;j<LEN;j++){
			printf("%c",tampung[i][j]);
			if(!*tampung[j]) 
	        		break;
		}
	}
}

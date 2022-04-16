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
void Total_Char();
void display(char fname[]);
void display1(char fname[]);
void edit_file(char fn[]);
void Menu();
void Delete();
void find();
void replaceAll(char *str, const char *oldWord, const char *newWord);
void DeleteLine();
void insert_line();

<<<<<<< HEAD
	FILE *fp,*fp1;
=======
<<<<<<< HEAD

=======
>>>>>>> b8f821fb1dbeb1d182876d901a93892e9c226adc
	FILE *fp, *fp1;
>>>>>>> c5ae0ad42687384672f68f83a107462b7662ac02
	char fn[15];
	int i,j,t,k,l,m,temp_m;

int main(void)
{
	arr();
}
void Menu(){	
system("cls");
printf("-----------------------------------------------------------------------------------------------\n");
printf("| File Name : %s ",fn);
printf("| Status : Menu In Control |\t");
Total_Char();
printf("-----------------------------------------------------------------------------------------------\n");
	printf("\tCtrl+D : Delete Line\tCtrl+E : Edit\t\tCtrl+N : New Window \n");
	printf("\tCtrl+Q : Insert Line\tCtrl+i : Insert Again\n\n");
<<<<<<< HEAD
	fflush(stdin);
	fp = fopen(fn,"at+");	
fp1 = fopen(fn,"rt");	
k=0,l=0;

<<<<<<< HEAD
=======
//	if(fp1 != NULL){
//		while (!feof(fp1)){
//        text[k][l] = getc(fp1);
//		if(!*text[k]){
//			k++;
//			l=0;
//		}
//		else{
//			l++;
//		}
//	}
//	}
=======
	
fp = fopen(fn,"at+");	
fp1 = fopen(fn,"rt");	
k=0,l=0;

<<<<<<< HEAD

=======
>>>>>>> b8f821fb1dbeb1d182876d901a93892e9c226adc
<<<<<<< HEAD
=======
>>>>>>> main
>>>>>>> Diaz
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
<<<<<<< HEAD
=======
<<<<<<< HEAD

	
=======
>>>>>>> Diaz
	
<<<<<<< HEAD
=======
//	display(fn);
	
>>>>>>> b8f821fb1dbeb1d182876d901a93892e9c226adc
>>>>>>> c5ae0ad42687384672f68f83a107462b7662ac02
<<<<<<< HEAD
=======
>>>>>>> main
>>>>>>> Diaz
	for(k=0; k < t; k++) {
					printf("%d: ", k);
		    	for(l=0; text[ k ][ l ]; l++){		   	 		      
		        	putchar(text[ k ][ l ]);			  		   
<<<<<<< HEAD
<<<<<<< HEAD
=======
		   		}
 			}
 			
=======
<<<<<<< HEAD
>>>>>>> Diaz
		   		}printf("\n");
 			}
 			
//	for(k=0; k < t; k++) {
//					printf("%d: ", k);
//		    	for(l=0; text[ k ][ l ]; l++){		   	 		      
//		        	putchar(text[ k ][ l ]);			  		   
//		   		} putchar('\n');
// 			}

=======
		   		}
 			}
 			
>>>>>>> c5ae0ad42687384672f68f83a107462b7662ac02
<<<<<<< HEAD
=======
>>>>>>> main
>>>>>>> Diaz
	char key;
	key = getch();
	if(key == 5){
			fclose(fp);
<<<<<<< HEAD
			fclose(fp1);
<<<<<<< HEAD
=======
>>>>>>> Tubagus
			edit_file(fn);			
=======
			edit_file(fn);			
printf("test 1");
=======
<<<<<<< HEAD
			fclose(fp1);
=======
>>>>>>> Tubagus
			edit_file(fn);			
>>>>>>> Diaz
<<<<<<< HEAD
=======
printf("test 1");
>>>>>>> c5ae0ad42687384672f68f83a107462b7662ac02
<<<<<<< HEAD
=======
>>>>>>> main
>>>>>>> Diaz
		}
		else if(key == 18){
			fclose(fp);
			fclose(fp1);
			Total_Char();			
printf("test 2");
		}
		else if(key== 4){
			fclose(fp);
			fclose(fp1);
			DeleteLine();			
printf("test 3");
		}
		else if(key == 17){
			fclose(fp);
			fclose(fp1);
			insert_line();
<<<<<<< HEAD
<<<<<<< HEAD
=======

printf("test 4");
		}
		else if(key == 14){
			system("start Array_TE.exe");
			Menu();
		}
=======
<<<<<<< HEAD
>>>>>>> Diaz
		}		
		else if(key == 6){
		fclose(fp);
		findword(fn);
		}				
		else if(key == 14){
			system("start Array_TE.exe");
			Menu();
		}				
=======

printf("test 4");
		}
<<<<<<< HEAD
		
		else if(key == 6){
		fclose(fp);
		findword(fn);
		}
		
=======
>>>>>>> b8f821fb1dbeb1d182876d901a93892e9c226adc
		else if(key == 14){
			system("start Array_TE.exe");
			Menu();
//			insert_line();
		}
>>>>>>> c5ae0ad42687384672f68f83a107462b7662ac02
<<<<<<< HEAD
=======
>>>>>>> main
>>>>>>> Diaz
		else if(key == 9){
			system("cls");
printf("-----------------------------------------------------------------------------------------------\n");
printf("| File Name : %s ",fn);
printf("| Status : Menu In Not Control |\t");
Total_Char();
printf("-----------------------------------------------------------------------------------------------\n");
	printf("\tCtrl+D : Delete Line\tCtrl+E : Edit\t\tCtrl+N : New Window \n");
	printf("\tCtrl+Q : Insert Line\tCtrl+i : Insert Again\n\n");
		
		int w; 		
		for(k=0; k < t; k++) {
					printf("%d: ", k);
		    	for(l=0; text[ k ][ l ]; l++){		   	 		      
		        	putchar(text[ k ][ l ]);			  		   
<<<<<<< HEAD
<<<<<<< HEAD
=======
		   		}	         	    	
=======
<<<<<<< HEAD
>>>>>>> Diaz
		   		}  printf("\n");	         	    	
=======
		   		}	         	    	
>>>>>>> c5ae0ad42687384672f68f83a107462b7662ac02
<<<<<<< HEAD
=======
>>>>>>> main
>>>>>>> Diaz
 			}
			for(w = k; w < MAX; w++){  		
	    		printf("%d: ", w);fflush(stdin);
	    		gets(text[w]);	    			
	    		t++;
				fprintf(fp,"%s \n",text[w]);
	    			if(!*text[w]) {
	    				t--;
						fclose(fp);	
						fclose(fp1); 	
						Menu();
			}			        		     	    	        
		}
<<<<<<< HEAD
<<<<<<< HEAD
=======
		fclose(fp);	  	
		fclose(fp1);				
		}
		}
=======
<<<<<<< HEAD
>>>>>>> Diaz
		fclose(fp);	  					
		}}
=======
		fclose(fp);	  	
		fclose(fp1);				
		}
}

void arr(){
>>>>>>> c5ae0ad42687384672f68f83a107462b7662ac02
<<<<<<< HEAD
=======
>>>>>>> main
>>>>>>> Diaz

void arr(){	
	printf("\n\tEnter the file name: ");
	scanf("%s",fn);
	fp=fopen(fn,"w+");
	system("cls");
printf("-----------------------------------------------------------------------------------------------\n");
printf("| File Name : %s ",fn);
printf("| Status : Menu Not In Control |\t");
Total_Char();
printf("-----------------------------------------------------------------------------------------------\n");
	printf("\tCtrl+D : Delete Line\tCtrl+E : Edit\t\tCtrl+N : New Window \n");
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
//	char pilihan;
//	retry:
//
//	display(fn);
	
//	printf("input data lagi ga ?(Y/N)");
//	scanf("%s",&pilihan);
//	
//	if(pilihan == 'Y' || pilihan == 'y' ){
//		fp = fopen(fn,"at+");			
//								 																
// 			int w; 		
//			for(; k < t; k++) {
//					printf("%d: ", k);
//		    	for(l=0; text[ k ][ l ]; l++){		   	 		      
//		        	putchar(text[ k ][ l ]);			  		   
//		   		} putchar('\n');  	         	    	
// 			}
//			for(w = k; w < MAX; w++){  		
//	    		printf("%d: ", w);fflush(stdin);
//	    		gets(text[w]);	    			
//	    		t++;
//				fprintf(fp,"%s \n",text[w]);
//	    			if(!*text[w]) {
//	    				t--;
//						fclose(fp);	 	
//	    				goto retry; /* quit on blank line */
//			}			        		     	    	        
//		}
//		fclose(fp);	  											
//		}else if(pilihan == 'S' || pilihan == 'n'){
//			edit_file(fn);	 
//		}else{
//			printf("invalid input");
//			goto retry;
//		}
//	edit_file(fn);	
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
<<<<<<< HEAD
	printf("\tColoumns :%i",total);
	printf("/Lines : %i |\n",i);
=======

	printf("\n Lines :%i",total);
	printf("/Coloumns : %i\n\n",i);
	system("pause");
	Menu();
>>>>>>> c5ae0ad42687384672f68f83a107462b7662ac02
}

void display(char fname[]){
    FILE *fptr = NULL; 
    int i = 0;
    int j = 0;
    int tot = 0;	
    fptr = fopen(fname, "r");
    while(fgets(text[i], LEN, fptr)) 
	{
        text[i][strlen(text[i]) - 1] = '\0';
        i++;
    }
    tot = i;  
    for(i = 0; i < tot; ++i)
    {
<<<<<<< HEAD
        printf("%d :%s\n", i, text[i]);
    }    
=======
        printf("\t %d :%s\n", i, text[i]);
    }

>>>>>>> c5ae0ad42687384672f68f83a107462b7662ac02
}

void display1(char fname[]){
	printf("Input the filename to be opened : ");
	scanf("%s",fname);
	printf("\nIsi File : \n",fname);
	printf("\n");  
	display(fname);
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
<<<<<<< HEAD
	
	printf("\n");


=======
<<<<<<< HEAD

=======
	
	printf("\n");	
>>>>>>> b8f821fb1dbeb1d182876d901a93892e9c226adc
>>>>>>> c5ae0ad42687384672f68f83a107462b7662ac02
		int inp;
		fflush(stdin);		
    	printf("Pilih index yang mau di edit :  ");
    	scanf("%d",&inp);
    	fflush(stdin);    	
    	printf("Data Lama : ");
    	for(j = 0; text[ inp ][ j ]; j++)
		{
			putchar(text[ inp ][ j ]);
		}
			
printf("\n");
		fp = fopen(fn,"r");	
		fpt = fopen("temp.txt","w");
		printf ("input Data baru :");
		

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

<<<<<<< HEAD
	} 		
=======
<<<<<<< HEAD
	 }		
>>>>>>> c5ae0ad42687384672f68f83a107462b7662ac02

=======
			system ("cls");
			Menu();
	
}
>>>>>>> b8f821fb1dbeb1d182876d901a93892e9c226adc

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


    fPtr  = fopen(path, "r");
    fTemp = fopen("replace.tmp", "w"); 

    if (fPtr == NULL || fTemp == NULL)
    {
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }

    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
        replaceAll(buffer, oldWord, newWord);
        fputs(buffer, fTemp);
    }
    fclose(fPtr);
    fclose(fTemp);
    remove(path);
    rename("replace.tmp", path);
    printf("\nSukses dirubah dari '%s' menjadi '%s'.", oldWord, newWord);


}

void replaceAll(char *str, const char *oldWord, const char *newWord)
{
    char *pos, temp[BUFFER_SIZE];
    int index = 0;
    int owlen;

    owlen = strlen(oldWord);

    if (!strcmp(oldWord, newWord)) {
        return;
    }

    while ((pos = strstr(str, oldWord)) != NULL)
    {
        strcpy(temp, str);
        index = pos - str;
        str[index] = '\0';
        strcat(str, newWord);
        strcat(str, temp + index + owlen);
    }
}

void DeleteLine(){
FILE *fp1;
	int delete_line, temp = 1;
	int tot = 0;
	int i = 0;
	int j=0;
	char ch,p;
	fp = fopen(fn, "r");
    printf("\nEnter line number of the line to be deleted:");
    scanf("%d", &delete_line);
    delete_line += 1;
    
    fp1 = fopen("delete.tmp", "w");
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
    rename("delete.tmp", fn);
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
    		DeleteLine();
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


void insert_line(){
	char baru[LEN];
	char tampung[MAX][LEN];
	FILE *fp1;
	int insert;
	char ch, p;
	i=0,j=0;
<<<<<<< HEAD
=======
//	system("cls");
>>>>>>> c5ae0ad42687384672f68f83a107462b7662ac02
	fp = fopen(fn, "r");
  	while (!feof(fp) && ch != EOF){
        tampung[i][j] = getc(fp);
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
<<<<<<< HEAD
=======
//			printf("\n");
>>>>>>> c5ae0ad42687384672f68f83a107462b7662ac02
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
<<<<<<< HEAD
=======
//		printf("\n");
//		fprintf(fp,"\n");
>>>>>>> c5ae0ad42687384672f68f83a107462b7662ac02
		mulai:;
	}
	fclose(fp);
	Menu();
<<<<<<< HEAD
}
=======
<<<<<<< HEAD
}			
>>>>>>> c5ae0ad42687384672f68f83a107462b7662ac02

void findword(char fn[]) {
	char str[LEN];
	int kata = 0, iya;
	
	i=0,j=0;
	
    fp = fopen(fn,"r");
    
    printf("Kata yang mau dicari substringnya: ");
	scanf("%s", str);
	
	while(fgets(text[i], LEN, fp)) 
	{
		
        text[i][strlen(text[i]) - 1] = '\0';
        if(strstr(text[i], str) != NULL) {
        		iya = strlen(text[i]) - 1;
        		printf("Ketemu di baris %d character urutan ke %d!!\n", i, iya);
        		kata++;
         }
        i++;
    }
	printf("Ada di %d line yang ditemukan memiliki substring yang sama ", kata);	
}	
=======
}			
>>>>>>> b8f821fb1dbeb1d182876d901a93892e9c226adc

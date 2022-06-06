#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <iostream>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>
 

#define MAX 20
#define LEN 80	
#define BUFFER_SIZE 1000

char text[MAX][LEN];
void arr();
void Total_Char();
void display(char fname[]);
void display1(char fname[]);
void edit_file(char fn[]);
void Menu(char x);
void Delete();
void findword(char fn[]);
void gotoxy(int baris,int kolom);
void replaceAll(char *str, const char *oldWord, const char *newWord);
void DeleteLine();
void insert_line();
void input_handl(int *baris, int *kolom, char *ch, char arr[MAX][LEN]);
void insert_text(char arr[MAX][LEN]);

	FILE *fp, *fp1;
	char fn[15];
	int i,j,t,k,l,m,temp_m;

int main(void)
{
//	arr();
//	printf("-----------------------------------------------------------------------------------------------\n");
//	printf("| File Name : %s ",fn);
//	printf("| Status : Menu In Control |\t");
//	Total_Char();
//	printf("-----------------------------------------------------------------------------------------------\n");
//	printf("\tCtrl+D : Delete Line\tCtrl+E : Edit\t\tCtrl+N : New Window \n");
//	printf("\tCtrl+Q : Insert Line\tCtrl+i : Insert Again\tCtrl+L : Delete File\n");
//	printf("\tCtrl+F : Find & Replace\n\n");
	insert_text(text);
//	printf("\t1.Creat\n\t2.Tampil\n\t3.Total Character\n\t4.Delete\n\t5.find\n");
//	int pil;
//	scanf("%i",&pil);
//  	do{
//  		switch (pil){
//  			case 1:{
//  				printf("masukkan data kosong untuk quit.\n");
//		  		arr();
//				break;
//			}
//			case 2:{
//				display1(fn);
//				break;
//			}
//			case 3:{
//				Total_Char();
//				break;
//			}
//			case 4:{
//				Delete();
//				break;
//			}
//				case 5:{
//				find();
//				break;
//			}
//		}
//	}while(pil != 4);
//	
//	end1:;
}
void Menu(char x){	
//system("cls");
//printf("-----------------------------------------------------------------------------------------------\n");
//printf("| File Name : %s ",fn);
//printf("| Status : Menu In Control |\t");
//Total_Char();
//printf("-----------------------------------------------------------------------------------------------\n");
//	printf("\tCtrl+D : Delete Line\tCtrl+E : Edit\t\tCtrl+N : New Window \n");
//	printf("\tCtrl+Q : Insert Line\tCtrl+i : Insert Again\tCtrl+L : Delete File\n");
//	printf("\tCtrl+F : Find & Replace\n\n");
	
//fp = fopen(fn,"at+");	
//fp1 = fopen(fn,"rt");	
//k=0,l=0;

//	if(fp1 != NULL){
//		while (!feof(fp1)){
//        text[k][l] = getc(fp1);
//		if(text[k][l] == '\n'){
//			k++;
//			l=0;
//		}
//		else{
//			l++;
//		}
//	}
//	t=k;
//	}
	
//	display(fn);
	
	
//	for(k=0; k < t; k++) {
//					printf("%d: ", k);
//		    	for(l=0; text[ k ][ l ]; l++){		   	 		      
//		        	putchar(text[ k ][ l ]);			  		   
//		   		}
// 			}
 			
//	key = getch();
	if(x == 5){
//			fclose(fp);
//			fclose(fp1);
			edit_file(fn);			
//printf("test 1");
		}
		else if(x == 6){
//		fclose(fp);
//		fclose(fp1);
		findword(fn);
		}
		else if(x == 18){
//			fclose(fp);
//			fclose(fp1);
			Total_Char();			
//printf("test 2");
		}
		else if(x== 4){
//			fclose(fp);
//			fclose(fp1);
			DeleteLine();			
//printf("test 3");
		}
		else if(x == 17){
//			fclose(fp);
//			fclose(fp1);
			insert_line();

//printf("test 4");
		}
		else if(x == 14){
			system("start Array_TE.exe");
			Menu(x);
//			insert_line();
		}
		else if(x == 12){
//			fclose(fp);
//			fclose(fp1);
			Delete();
		}
//		else if(key == 9){
//			system("cls");
//
//printf("-----------------------------------------------------------------------------------------------\n");
//printf("| File Name : %s ",fn);
//printf("| Status : Menu Not In Control |\t");
//Total_Char();
//printf("-----------------------------------------------------------------------------------------------\n");
//	printf("\tCtrl+D : Delete Line\tCtrl+E : Edit\t\tCtrl+N : New Window \n");
//	printf("\tCtrl+Q : Insert Line\tCtrl+i : Insert Again\tCtrl+L : Delete File\n");
//	printf("\tCtrl+F : Find & Replace\n\n");
//		
//		int w; 		
//		for(k=0; k < t; k++) {
//					printf("%d: ", k);
//		    	for(l=0; text[ k ][ l ]; l++){		   	 		      
//		        	putchar(text[ k ][ l ]);			  		   
//		   		}	         	    	
// 			}
//			for(w = k; w < MAX; w++){  		
//	    		printf("%d: ", w);fflush(stdin);
//	    		gets(text[w]);	    			
//	    		t++;
//				fprintf(fp,"%s \n",text[w]);
//	    			if(!*text[w]) {
//	    				t--;
//						fclose(fp);	
//						fclose(fp1); 	
//						Menu(key);
//			}			        		     	    	        
//		}
//		fclose(fp);	  	
//		fclose(fp1);				
//		}
}

void arr(){

	
//	printf("\n\tEnter the file name: ");
//	scanf("%s",fn);
//	fp=fopen(fn,"w+");
//	
//	
//printf("-----------------------------------------------------------------------------------------------\n");
//printf("| File Name : %s ",fn);
//printf("| Status : Menu Not In Control |\t");
//Total_Char();
//printf("-----------------------------------------------------------------------------------------------\n");
//	printf("\tCtrl+D : Delete Line\tCtrl+E : Edit\t\tCtrl+N : New Window \n");
//	printf("\tCtrl+Q : Insert Line\tCtrl+i : Insert Again\tCtrl+L : Delete File\n");
//	printf("\tCtrl+F : Find & Replace\n\n");
//	fflush(stdin);
	
//	Menu();
//  	for(t = 0; t < MAX; t++){  		
//	    printf("%d: ", t);fflush(stdin);
//	    gets(text[t]);fflush(stdin);
//	    if(!*text[t]) 
//	        break; /* quit on blank line */	 
//			
//	fprintf(fp,"%s \n",text[t]);     	    	        
//
//	}	
//	fclose(fp);	
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
	printf("\tColoumns :%i",total);
	printf("/Lines : %i |\n",i);
}

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
	getch();
//	Menu();	
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
        printf("\t %d :%s\n", i, text[i]);
    }

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
	
	printf("\n");	
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

			system ("cls");
//			Menu();
	
}

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
			getch();
//    		Menu();
	goto end2;
	}
	else
	
	printf("\n\tError!\n");
	end2: printf("\n\n\tPress any key to continue\n");
	getch();
//    Menu();
    
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
	
//	system("cls");
	fp = fopen(fn, "r");
	
//    while(fgets(text[i], LEN, fp)) 
//	{
//        text[i][strlen(text[i]) - 1] = '\0';
//        i++;
//    }
//    tot = i;  
//    for(i = 0; i <= tot-1; ++i)
//    {
//        printf("%d :%s\n", i, text[i]);
//    }
//
//    rewind(fp);
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
//			Menu();
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
//	Menu();
}			

void gotoxy(int baris,int kolom)
{
	COORD coord;
	
    coord.X = kolom;
    coord.Y = baris;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

bool Cek_Input(char ch)
{
	switch(ch)
	{
		// Null
		case 0:
		{
			return true;
			break;
		}
		
		// Backspace
		case 8:
		{
			return true;
			break;
		}
		
		// Enter
		case 13:
		{
			return true;
			break;
		}
		
		// Arrow
		case -32:
		{
			return true;
			break;
		}
		
		// Tab
		case 9:
		{
			return true;
			break;
		}
		
		// ESC
		case 27:
		{
			return true;
			break;
		}
		
		// Normal
		default:
		{
			return false;
			break;
		}	
	}		
}

void insert_text(char arr[MAX][LEN])
{
    char ch;
    bool Validasi_Input;
    int baris = 0;
    int kolom = 0;
    
    //system("cls");
    
    gotoxy(MAX+1, 0);
	printf("\tCtrl+D : Delete Line\tCtrl+E : Edit\t\tCtrl+N : New Window \n");
	printf("\tCtrl+Q : Insert Line\tCtrl+i : Insert Again\tCtrl+L : Delete File\n");
	printf("\tCtrl+F : Find & Replace\n\n");
    gotoxy(0,0);
    // Menulis Pada Array
    while(1)
	{   
		ch = getch();
		Menu(ch);
		// Selesai Menulis
		if (ch == 17){
			break;
		}
		
		// Cek Input Handling
		Validasi_Input = Cek_Input(ch);
		
		if (Validasi_Input)
		{
			input_handl(&baris, &kolom, &ch, arr);	
		}
		
		if (baris < MAX-1 or kolom <= LEN-1)
		{
			if (kolom <= MAX-1 and !Validasi_Input)
			{
				printf("%c", ch);
				arr[baris][kolom] = ch;
				kolom++;
			}else 
			
			if (kolom > MAX-1 and baris < LEN-1 and !Validasi_Input)
			{

				kolom = 0;
				baris++;
				gotoxy(baris,kolom);	
				printf("%c", ch);
				arr[baris][kolom] = ch;
				kolom++;
			}
			//Menyaring Informasi
			//cursor_information(baris, kolom, arr);
			//Pindah Kursor
			gotoxy(baris,kolom);
		}
	}
}

void input_handl(int *baris, int *kolom, char *ch, char arr[MAX][LEN])
{
	int brs = 0, klm = 0, klm_1 = 0, temp;
	bool status;
	
	// Null
	if (*ch == 0)
	{
		*ch = getch();
	}
	
	// Esc
	if (*ch == 27)
	{
		*ch = 0;
	}
	
	// Tab
	if (*ch == 9)
	{
		gotoxy(*baris,*kolom);
		
	}
	
	// Backspace
	if (*ch == 8)
	{		
		if (*kolom <= MAX and *kolom != 0)
		{
			*kolom = *kolom - 1;
			brs = *baris;
			klm = *kolom;
			
			while (klm < MAX)
			{
				gotoxy(brs,klm);
			
				//Ubah Array
				if ((klm + 1) != MAX){
					arr[brs][klm] = arr[brs][klm+1];
				}else{
					arr[brs][klm] = NULL;
				}
				
				//Tampil Layar
				if (arr[brs][klm] == NULL){
					printf(" ");
				}else{
					printf("%c", arr[brs][klm]);	
				}	
				
				klm = klm + 1;
			}
			gotoxy(*baris,*kolom);
		}else
		
		if (arr[*baris][*kolom] == NULL and *baris < LEN-1)
		{
			//Cek Baris Dibawah
			status = false;
			for(int i = *baris+1; i < LEN; i++)
			{
				if (arr[i][0] != NULL){
					status = true;
					break;
				}
			}
			
			//Jika Seluruh Baris Dibawahnya Kosong
			if (!status)
			{
				if(*baris != 0)
				{
					brs = *baris;
					klm = *kolom;		
					gotoxy(*baris,*kolom);
					brs = *baris - 1;
					klm = *kolom;
					while (klm <= MAX-1)
					{
						if (arr[brs][klm] == NULL){
							break;
						}
						klm = klm + 1;
					}
					*kolom = klm;
					*baris = brs;
				}else{
					gotoxy(*baris,*kolom);
				}
				
			//Jika Baris Dibawahnya Terdapat Yang Tidak Kosong		
			}else{
				brs = *baris;
				klm = *kolom;
				while (brs <= LEN-1)
				{	
					if (klm == MAX){
						klm = 0;
						brs = brs + 1;
					}
					
					gotoxy(brs,klm);
					
					//Ubah Array
					if (brs < MAX-1){
						arr[brs][klm] = arr[brs+1][klm];
					}else{
						arr[brs][klm] = NULL;
					}
					
					//Tampil Layar
					gotoxy(brs,klm);
					if (arr[brs][klm] == NULL and brs != LEN){
						printf(" ");
					}else{
						printf("%c", arr[brs][klm]);	
					}
					
					klm = klm + 1;
				}
			}
			gotoxy(*baris,*kolom);
		}else
		
		if (*kolom == 0 and *baris != 0 and arr[*baris+1][*kolom] != NULL)
		{
			//Cari Huruf Terakhir
			*baris = *baris - 1;
			*kolom = 0;
			while(*kolom < MAX)
			{
				if (arr[*baris][*kolom] == NULL){
					break;
				}
				*kolom = *kolom + 1;
				gotoxy(*baris,*kolom);
			}
			if (*kolom == MAX){
				*kolom = *kolom - 1;
			}
			brs = *baris;
			klm = *kolom;
			temp = 0;
		
			while (brs == *baris and klm <= MAX)
			{
				if (klm == MAX){
					brs = brs + 1;
					klm = 0;
				}else{
					
					gotoxy(brs,klm);
					
					//Ubah Array
					arr[brs][klm] = arr[brs+1][klm_1];
					if (arr[brs][klm] != NULL){
						temp = temp + 1;
						arr[brs+1][klm_1] = NULL;
					}
					
					//Tampil Layar
					if (arr[brs][klm] == NULL){
						printf(" ");
					}else{
						printf("%c", arr[brs][klm]);	
					}
					
					klm = klm + 1;
					klm_1 = klm_1 + 1;
				}
			}
			
			klm_1 = temp;
			while (klm < MAX)
			{
				gotoxy(brs,klm);
			
				//Ubah Array
				if (klm_1 < MAX){
					arr[brs][klm] = arr[brs][klm_1];
				}else{
					arr[brs][klm] = NULL;
				}
				
				//Tampil Layar
				if (arr[brs][klm] == NULL){
					printf(" ");
				}else{
					printf("%c", arr[brs][klm]);	
				}	
				
				klm = klm + 1;
				if (klm_1 < MAX){
					klm_1 = klm + 1;
				}
			}
			gotoxy(*baris,*kolom);
		}else
			
		if (*kolom == 0 and *baris != 0 and arr[*baris+1][*kolom] == NULL)
		{
			brs = *baris - 1;
			klm = *kolom;
			while (klm <= MAX-1)
			{
				if (arr[brs][klm] == NULL){
					break;
				}
				klm = klm + 1;
			}
			*kolom = klm;
			*baris = brs;
		}
	}

	
	// Enter
	if (*ch == 13)
	{
		if (*baris < MAX-1){
			*baris = *baris + 1;
			*kolom = 0;
		}
		gotoxy(*baris, *kolom);
	}
	
	// Arrow
	if (*ch == -32)
	{
		*ch = getch();
		
		switch(*ch)
		{
			// Up Arrow
			case 72:
			{
				if (*baris <= MAX-1){
					if (*baris == 0){
						gotoxy(*baris,*kolom);
					}
					else
					
					if (*baris != 0){
						*baris = *baris - 1;
						gotoxy(*baris,*kolom);
				}
				break;
			}
			
			// Down Arrow
			case 80:
			{
				if (*baris <= LEN-1){
					if (*baris == LEN-1){
						gotoxy(*baris,*kolom);
					}
					else{
						if(arr[*baris+1][*kolom] == NULL){
							gotoxy(*baris,*kolom);
						}else{
							*baris = *baris + 1;
							gotoxy(*baris,*kolom);
						}	
					}
				}                     
			}
			
			// Left Arrow
			case 75:
			{
				if (*kolom <= LEN)
				{
					if (*kolom == 0 and *baris == 0){
						gotoxy(*baris,*kolom);
					}else
					
					if (*kolom != 0){
						*kolom = *kolom - 1;
						gotoxy(*baris, *kolom);
					}else
					
					if (*kolom == 0 and *baris != 0){
						*baris = *baris - 1;
						for (int i = 0; i <= LEN; i++)
						{
							if(arr[*baris][*kolom] == NULL){
								break;
							}
							*kolom = i + 1;
						}
						if (*kolom > LEN){
							*kolom = *kolom - 1;
						}
						gotoxy(*baris,*kolom);
					}
				}
				break;
			}
			
			// Right Arrow
			case 77:
			{
				if (*kolom <= LEN)
				{	
					if (*kolom <= LEN and arr[*baris][*kolom] != NULL and (*kolom + 1) <= LEN){
						*kolom = *kolom + 1;
						gotoxy(*baris,*kolom);
					}else
					
					if (*kolom <= LEN and arr[*baris+1][0] != NULL and (*baris + 1) < MAX){
						*kolom = 0;
						*baris = *baris + 1;
						gotoxy(*baris,*kolom);
					}else
					
					if (*kolom == LEN and *baris == MAX){
						gotoxy(*baris,*kolom);
					}else
					
					if (*kolom != LEN and arr[*baris][*kolom] != NULL){
						for(int i = 0; i < LEN; i++){
							if (arr[*baris][*kolom] == NULL){
								break;
							}
							*kolom = i + 1;
						}
						gotoxy(*baris,*kolom);
					}else
					
					if (*kolom != LEN and arr[*baris][*kolom] != NULL){
						for(int i = 0; i < LEN; i++){
							if (arr[*baris][*kolom] == NULL){
								break;
							}
							*kolom = i + 1;
						}
						gotoxy(*baris,*kolom);
					}else
					
					if (*kolom == LEN and *baris < MAX){
						for(int i = *baris+1; i < MAX; i++)
						{
							if (arr[i][0] != NULL){
								*baris = *baris + 1;
								*kolom = 0;
								gotoxy(*baris,*kolom);
								break;
							}
						}
					}	
				}
				break;
			}
		}
	}
}
}
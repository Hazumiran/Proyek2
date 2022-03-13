#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define LEN 80

char text[MAX][LEN];
void arr();
int edit();
void Total_Char();
void display();

int main(void)
{
	printf("\t1.Creat\n\t2.Tampil\n");
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
	
	start1:
	char pil;
	register int t, i, j;
	fflush(stdin);
	
  	for(t = 0; t < MAX; t++){
	    printf("%d: ", t);
	    gets(text[t]);
	    if(!*text[t]) 
	        break; /* quit on blank line */
	}
	
//	printf("\nIsi teks\n");
//	for(i = 0; i < t; i++) {
//	   for(j = 0; text[ i ][ j ]; j++) 
//	       putchar(text[ i ][ j ]);
//	 	  putchar('\n');
//	}
	 printf("\n\n");
	 char inpedit;
	 printf("selesai, mau edit file ? (Y/N) ");
	 scanf("%s",&inpedit);
	 if(inpedit == 'y' || inpedit == 'Y'){
	 	int inp;
    	printf("Pilih index yang mau di edit ");
    	scanf("%d",&inp);
    	for(j = 0; text[ inp ][ j ]; j++){
			putchar(text[ inp ][ j ]);
		}
	 }else{
	ulang:
	printf("\nApakah Akan kembali Menulis y/t : ");
	scanf("%s",&pil);
	
	if(pil == 'y' || pil == 'Y'){
		goto start1;
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

void Total_Char(){
	int total;
	int i,j,t;
	
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

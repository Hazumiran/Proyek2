#include <stdio.h>

#define MAX 100
#define LEN 80

char text[MAX][LEN];
int arr();
int edit();

int main()
{
 arr();
}

int arr(){
	
	register int t, i, j;

  printf("masukkan data kosong untuk quit.\n");

  for(t = 0; t < MAX; t++) {
    printf("%d: ", t);
    gets(text[t]);
    if(!*text[t]) 
        break; /* quit on blank line */
  }

// JANGAN DIHAPUS, CODE ASLI
//  for(i = 0; i < t; i++) {
//    for(j = 0; text[ i ][ j ]; j++) 
//        putchar(text[ i ][ j ]);
//    putchar('\n');
//  }

    printf("\n\n");
 	int inp;
    	printf("Pilih index yang mau di edit ");
    	scanf("%d",&inp);
    	for(j = 0; text[ inp ][ j ]; j++){
		putchar(text[ inp ][ j ]);
}}



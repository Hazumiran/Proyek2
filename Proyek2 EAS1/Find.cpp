#include "Find.h"
#include <string.h>
#include <stdlib.h>

void find(List *content, char fname[20]){

	char kata[25], pilih;
	int pjg, pos;
	printf("\nkata yang mau dicari : ");fflush(stdin);
	gets(kata);
	pjg = strlen(kata);

    Node *temp = NULL;
    int i, j = 0;

	for(temp = content->head; NULL != temp; temp = temp->next)
    {
		if(kata[i] == temp->data){
			i++;
			if(i == pjg){
				if(temp->next->data == SPACEKEY){
					break;
				}
			}
		}
		else{
			i = 0;
		}
		j++;
    }	

	pos = j - pjg + 1;
	if(i == 0){
		printf("Ga ketemu");
	}
	else{
		printf("ketemu");
		printf("\nApakah mau me-replace (y/n) ? ");
		
	while(pilih = _getch()){ // Mencegah user ngetik aneh aneh
		if(pilih == 'y' || pilih == 'Y'){
			putchar('y');
			replace(content, pos, pjg, fname);
		}
		else if (pilih == 'n' || pilih == 'N'){
			putchar('n');
			system("cls");
			main();
		}	
		}
	}
}

void replace (List *content, int pos, int pjg, char fname[20]){
	int i = 0, j = 0, k = 0, selisih;
	char kata[25];
	
	printf("\n");
	printf("Masukkan Kata pengganti : ");fflush(stdin);
	gets(kata);
	k = strlen(kata);
	
	Node *temp = NULL;
	for(temp = content->head; NULL != temp; temp = temp->next){
		if(i == pos){
			while(j < k){
				if (k == pjg){
					temp->data = kata[j];
					temp = temp->next;
					j++;
				}
				else if(k > pjg){
//					selisih = k - pjg;
					printf("lebih, gabisa diganti \n");
					break;
				}
				else if(k < pjg){
//					selisih = pjg - k;
					printf("kurang, gabisa diganti \n");
					break;
				}	
			}
			break;            
		}
		else{
			i++;
		}
	}

	//tampil list baru
	for(temp = content->head; NULL != temp; temp = temp->next)
    {
        printf("%c", temp->data);
    }
    
    //save list baru
    FILE *fp = fopen(fname, "w");
    for(temp = content->head; NULL != temp; temp = temp->next)
    {
        putc(temp->data, fp);
    }
    fclose(fp);
	printf("\n %d %d %d", i, pos, pjg);
	getch();
	system("cls");
	main();
}
		
              

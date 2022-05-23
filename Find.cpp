#include "Find.h"
#include <string.h>
#include <stdlib.h>

void find(List *content, char fname[20]){

	char kata[100], pilih;
	int pjg, pos;
	printf("\nkata yang mau dicari : ");fflush(stdin);
	gets(kata);
	pjg = strlen(kata);

    Node *temp = NULL;
    int i = 0, j = 0;

	for(temp = content->head; NULL != temp->next; temp = temp->next)
    {
		if(kata[i] == temp->data){
			i++;
			if(i == pjg){
					break;
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
	fflush(stdin);
	while(pilih = _getch()){ // Mencegah user ngetik aneh aneh
		if(pilih == 'y' || pilih == 'Y'){
			putchar('y');
			replace(content, pos, pjg, fname);
		}
		else if (pilih == 'n' || pilih == 'N'){
			putchar('n');
			getch();
			system("cls");
			main();
		}	
		}
	}
}

void replace (List *content, int pos, int pjg, char fname[20]){
	int i = 0, j = 0, k = 0, selisih;
	char kata[100];
	
	printf("\n");
	printf("Masukkan Kata pengganti : ");fflush(stdin);
	gets(kata);
	k = strlen(kata);
	
	Node *temp = NULL;
	for(temp = content->head; NULL != temp->next; temp = temp->next){
		if(i == pos){
			
			if (k == pjg){
				while(j < k){
					temp->data = kata[j];
					temp = temp->next;
					j++;
				}
			}
			
			else if(k < pjg){
				while(j < pjg){
					if(j < k){
						temp->data = kata[j];
					}
					else if(j >= k){
						Node *P;
						P = temp;
						temp = temp->prev;
						temp->next = P->next;
						P->next->prev = temp;
						DeAlokasi(P);
					}
					j++;
					temp = temp->next;					
				}
			}
			
			else if(k > pjg){
				selisih = k - pjg;
				while(j < pjg + selisih){
					if (j < pjg){
						temp->data = kata[j];
						temp = temp->next;
					}
					else if(j < k){
						Node *P = nodeCtor(kata[j]);
						temp->prev->next = P;
						P->prev = temp->prev;
						temp->prev = P;
						P->next = temp;
					}
					j++;
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

	printf("\n %d i %d pos %d pjg %d k", i, pos, pjg, k);
	getch();
	system("cls");
}
		
              

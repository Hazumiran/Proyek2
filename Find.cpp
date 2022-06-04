#include "Find.h"
#include <string.h>
#include <stdlib.h>
#include "PulDown.h"

void find(List *content){
	Baris_Kolom  position;
	position.x = 0;
	position.y = 0;
	position.jml_char = 0;
	
	char kata[25], pilih;
	int pjg, pos;
	printf("\nkata yang mau dicari : ");fflush(stdin);
	gets(kata);
	pjg = strlen(kata);

    Node *temp = NULL;
    int i, j = 0;

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
		printf("Kata yang dicari tidak ada\n");
	getch();	
	system("cls");
	PullDownDisplay();
 	displayContent(content, &position);
	}
	else{
		printf("\nApakah mau me-replace (y/n) ? ");
		pilih = _getch(); // Mencegah user ngetik aneh aneh
			if(pilih == 'y' || pilih == 'Y'){
				putchar('y');
				replace(content, pos, pjg);
				system("cls");
				PullDownDisplay();
				displayContent(content, &position);
			}
			else if (pilih == 'n' || pilih == 'N'){
				putchar('n');
				getch();	
				system("cls");
				PullDownDisplay();
				displayContent(content, &position);
			}	
	}
}

void replace (List *content, int pos, int pjg){
	int i = 0, j = 0, k = 0, selisih;
	char kata[25];
	
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
						Node *P = CreateNode(kata[j]);
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
	for(temp = content->head; NULL != temp; temp = temp->next)
    {
        printf("%c", temp->data);
    }
    

}
		
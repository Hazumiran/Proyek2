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
	TextBox(5,45);
	goto_xy(32,9);
	color(543);
	printf("Kata yang mau dicari : ");fflush(stdin);
	goto_xy(56,9);
	gets(kata);fflush(stdin);
	system("cls");
	PullDownDisplay();
 	displayContent(content, &position);
	pjg = strlen(kata);

    Node *temp = NULL;
    int i, j = 0;

	temp = content->head;
	
	if(temp != NULL){
		for(temp = content->head; NULL != temp->next; temp = temp->next){
			if(kata[i] == temp->data){
				i++;
				if(i == pjg){
					if(temp->next->data == SPACEKEY || temp->next->data == NLINE || temp->next == NULL){
						break;
					}
				}
			}
			else{
				i = 0;
			}
			j++;
	    }
	}
	else{
		i = 0;
	}	

	pos = j - pjg + 1;
	if(i == 0){

		TextBox(5,45);
		goto_xy(34,9);
		color(543);
		printf("Kata yang dicari tidak ada");fflush(stdin);
		getch();	
		system("cls");
		PullDownDisplay();
 		displayContent(content, &position);
	}
	else{
		TextBox(5,45);
		goto_xy(32,9);
		color(543);
		printf("Apakah mau me-replace (y/n) ? ");
		goto_xy(62,9);fflush(stdin);
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
	color(7);
}

void replace (List *content, int pos, int pjg){
	int i = 0, j = 0, k = 0, selisih;
	char kata[25];
	
	TextBox(5,45);
	goto_xy(32,9);
	color(543);
	printf("Masukkan Kata pengganti : ");fflush(stdin);
	goto_xy(58,9);
	gets(kata);fflush(stdin);
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
    
color(7);
}
		
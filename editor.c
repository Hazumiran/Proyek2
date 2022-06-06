#include "editor.h"
#include "PulDown.h"
#include "FileHandl.h"

Point *pointCtor(){
    Point *newPoint = (Point *)malloc(sizeof(Point));
    newPoint->x = NULL;
    newPoint->y = NULL;
    newPoint->index = NULL;

    return newPoint;
} 

//void printListChars(List *list)
//{
//    Node *temp = NULL;
//    for(temp = list->head; NULL != temp; temp = temp->next)
//    {
//        if(temp->data == '\n')
//            printf("[\\n]->");
//        else
//            printf("[%c]->", temp->data);
//    }
//    printf("[NULL]\n");
//}

void gotoxy(Point *point)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Cord;
    Cord.X = point->x;
    Cord.Y = point->y+1;
    SetConsoleCursorPosition(hStdout, Cord);
}

void displayContent(List *list,Baris_Kolom *position)
{
	char key;
	List *content;
	Node *temp = NULL;
	system("cls");
	PullDownDisplay();
	
	for(temp = list->head; NULL != temp; temp = temp->next){
        putchar(temp->data);
    }

	
	if(position->y >= 21){
			printf("\n");
			goto_xy(0,0);
			color(543);	
			printf("File     ");
		
			goto_xy(9,0);
			color(543);	
			printf("Edit     ");
		
			goto_xy(18,0);
			color(543);	
			printf("View    ");
			color(543);
			printf("                                                                                              \n");
			color(7);				
	}
	goto_xy(0,21);
	color(543);
    printf("\nKolom : %d   ",position->x); 
    color(543);
	printf("Baris : %d   ",position->y);
	color(543);
	printf("Jumlah Karakter : %d                                                                          ", position->jml_char);
	color(7);

}

int readFile(FILE *fp, List *content, Point *CursorPos)
{
    char character;
    while(EOF != (character = getc(fp)))
    {
        if(character == '\n')
        {
            putchar(character);
            insertNode(content, CreateNode(character), CursorPos->index);
			CursorPos->y += 1;
			CursorPos->x = 0;
            CursorPos->index += 1;
        }
        else
        {
            putchar(character);
            insertNode(content, CreateNode(character), CursorPos->index);
            CursorPos->x += 1;
            CursorPos->index += 1;
        }
    }
    return 0;
}

int KursorHandl(List *content, Point *CursorPos, Baris_Kolom *position){
//	unsigned char key;
//	CursorPos->y +=1;
//	gotoxy(CursorPos);
    signed char key;
    List *copy_text;
	while(ESC != (key = getch()))
    {
        if(key == ARROWKEY)
        {
            key = _getch();
            if(key == ARROWUPKEY)//UP
            {
            	//jika berada di ujung atas
                if(CursorPos->y == 0)
                {
                    //At top line
                    position->y = 1;
                    
					position->x = CursorPos->x;
        			position->y = CursorPos->y;
        			position->jml_char = getIndex(content,CursorPos);
					displayContent(content,position);
                    continue;
                }
                
                //yang atas lebih sedikit dari yang bawah
                else if(CursorPos->x > getLineLen(content, CursorPos->y))
                {
                	position->y -= 1;
                	position->x = getLineLen(content, CursorPos->y) + 1;
                	displayContent(content,position);
                    CursorPos->x = getLineLen(content, CursorPos->y);
                    CursorPos->y -=1;
                    CursorPos->index = getIndex(content, CursorPos);
                    
					position->x = CursorPos->x;
        			position->y = CursorPos->y;
        			position->jml_char = getIndex(content,CursorPos);
					gotoxy(CursorPos);
                    continue;
                }
                //Tanpa ketentutan
                else
                {
                    position->y -= 1;
                    displayContent(content,position);             	
                    CursorPos->y -= 1;
                    CursorPos->index = getIndex(content, CursorPos);
                    
					position->x = CursorPos->x;
        			position->y = CursorPos->y;
        			position->jml_char = getIndex(content,CursorPos);
					gotoxy(CursorPos);
                    continue;
                }
            }
            else if(key == ARROWDOWNKEY)//DOWN
            {
            	//pada ujung bawah
                if(CursorPos->y == getHeight(content))
                {
                	position->y = position->y;
					position->x = CursorPos->x;
        			position->y = CursorPos->y;
        			position->jml_char = getIndex(content,CursorPos);
					displayContent(content,position);
                    continue;
                }
                //yang bawah lebih sedikit dari yang atas
                else if(CursorPos->x > getLineLen(content, CursorPos->y + 2))
                {
                	position->y += 1;
                	position->x = getLineLen(content, CursorPos->y + 2) + 1;
                	displayContent(content,position);
                    CursorPos->x = getLineLen(content, CursorPos->y + 2);
                    CursorPos->y += 1;
                    CursorPos->index = getIndex(content, CursorPos);
                    
					position->x = CursorPos->x;
        			position->y = CursorPos->y;
        			position->jml_char = getIndex(content,CursorPos);
					gotoxy(CursorPos);
                    continue;
                }
                //tanpa ketentuan
                else
                {
                	position->y += 1;
                	displayContent(content,position);
                    CursorPos->y += 1;
                    CursorPos->index = getIndex(content, CursorPos);
                    
					position->x = CursorPos->x;
        			position->y = CursorPos->y;
        			position->jml_char = getIndex(content,CursorPos);
					gotoxy(CursorPos);
                    continue;
                }

            }
            else if(key == ARROWRIGHTKEY) //RIGHT
            {
                if((CursorPos->y == getHeight(content)) && (CursorPos->x == getLineLen(content, CursorPos->y + 1)))
                {
                    //At end of file
                    position->x = position->x;
                    
					position->x = CursorPos->x;
        			position->y = CursorPos->y;
        			position->jml_char = getIndex(content,CursorPos);
					displayContent(content,position);
                    continue;
                }
                else if(CursorPos->x == getLineLen(content, CursorPos->y + 1))
                {
                    //At end of line, but not end of file
                    position->x = 1;
                    position->y += 1;
                    displayContent(content,position);
                    CursorPos->x = 0;
					++CursorPos->y;
                    CursorPos->index = getIndex(content, CursorPos);
                    
					position->x = CursorPos->x;
        			position->y = CursorPos->y;
        			position->jml_char = getIndex(content,CursorPos);
					gotoxy(CursorPos);
                    continue;
                }
                else
                {
                	position->x += 1;
                	displayContent(content,position);
                    CursorPos->x += 1;
                    CursorPos->index = getIndex(content, CursorPos);
                    
					position->x = CursorPos->x;
        			position->y = CursorPos->y;
        			position->jml_char = getIndex(content,CursorPos);
					gotoxy(CursorPos);
                    continue;
                }
            }
            else if(key == ARROWLEFTKEY)//LEFT
            {
                if((CursorPos->x == 0) && (CursorPos->y == 0))
                {
                    //At start of file
                    position->x = 1;
                    position->x = CursorPos->x;
        			position->y = CursorPos->y;
        			position->jml_char = getIndex(content,CursorPos);
					displayContent(content,position);
                    continue;
                }
                else if(CursorPos->x == 0)
                {
                    //At start of line, but not start of file
                    position->x = getLineLen(content, CursorPos->y) + 1;
                    position->y -= 1;
                    displayContent(content,position);
                    CursorPos->x = getLineLen(content, CursorPos->y);
                    --CursorPos->y;
                    CursorPos->index = getIndex(content, CursorPos);
                    position->x = CursorPos->x;
        			position->y = CursorPos->y;
        			position->jml_char = getIndex(content,CursorPos);
					gotoxy(CursorPos);
                    continue;
                }
                else{
                	position->x -= 1;
                	displayContent(content,position);
                    --CursorPos->x;
                    CursorPos->index = getIndex(content, CursorPos);
                    position->x = CursorPos->x;
        			position->y = CursorPos->y;
        			position->jml_char = getIndex(content,CursorPos);
					gotoxy(CursorPos);
                    continue;
                }
            }
            else if(key == CTRLLEFT){
            	CursorPos->x = 0;
            	CursorPos->index = getIndex(content, CursorPos);
            	position->x = CursorPos->x;
        		position->y = CursorPos->y;
        		position->jml_char = getIndex(content,CursorPos);
				gotoxy(CursorPos);
            	continue;
			}
			else if(key == CTRLRIGHT){
				CursorPos->x = getLineLen(content, CursorPos->y + 1);
				CursorPos->index = getIndex(content, CursorPos);
				position->x = CursorPos->x;
        		position->y = CursorPos->y;
        		position->jml_char = getIndex(content,CursorPos);
				gotoxy(CursorPos);
				continue;
			}
        }
        else if(key == BACKSPACEKEY) //TODO check bug when deleting after arrow job
        {
            if((CursorPos->x == 0) && (CursorPos->y == 0))
            {
 			    position->x = 1;
                position->y = 1;
                
                position->x = CursorPos->x;
        		position->y = CursorPos->y;
        		position->jml_char = getIndex(content,CursorPos);
                displayContent(content,position);
                continue;  
            }
            else if(CursorPos->x == 0)
            {
                position->x = getLineLen(content, CursorPos->y);
                position->y -= 1;
                displayContent(content,position);
				CursorPos->x = getLineLen(content, CursorPos->y);
		        CursorPos->y -= 1;
		        
		        position->x = CursorPos->x;
        		position->y = CursorPos->y;
        		position->jml_char = getIndex(content,CursorPos);
		        removeNodeByIndex(content, CursorPos->index -= 1);	
            }
            else
            {
                putchar(BACKSPACEKEY);
                putchar(SPACEKEY);
                putchar(BACKSPACEKEY);
                removeNodeByIndex(content, CursorPos->index -= 1);
                CursorPos->x -= 1;
                position->x -= 1;
                
                position->x = CursorPos->x;
        		position->y = CursorPos->y;
                displayContent(content,position);
                position->jml_char = getIndex(content,CursorPos);
            }    
        position->x = position->x - 1;
        displayContent(content,position);
        }
        else if(key == TAB)
        {
            int i;
            for(i = 0; i < 4; ++i)
            {
                insertNode(content, CreateNode(SPACEKEY), CursorPos->index);
                ++CursorPos->x;
                ++CursorPos->index;
                
                position->x = CursorPos->x;
        		position->y = CursorPos->y;
        		position->jml_char = getIndex(content,CursorPos);
            }
        position->x += 3;    
        }
        else if(key == 3){
        	copy_text = CreateHead();
        	copy(content , CursorPos, copy_text);
		}
		else if(key == 22){
        	paste(content , CursorPos, copy_text);
        	system("cls");
		}
        else if(key == 11){
//        	position->x = getLineLen(content, CursorPos->x);
//        	position->y = getLineLen(content, CursorPos->y);
//        	displayContent(content,position);
//        	CursorPos->x = 0;
//        	CursorPos->y = 0;
//        	CursorPos->index = getIndex(content, CursorPos);
//          gotoxy(CursorPos);
        	return 2;
		}
        else
        {
            if(key == ENTERKEY || key == NLINE)
            {
                insertNode(content, CreateNode(NLINE), CursorPos->index);
				CursorPos->x = 0;
                ++CursorPos->y;
                ++CursorPos->index;
                position->x = 0;
        		position->y += 1;
        		
        		position->x = CursorPos->x;
        		position->y = CursorPos->y;
        		position->jml_char = getIndex(content,CursorPos);
            }
            else
            {
                insertNode(content, CreateNode(key), CursorPos->index);
                ++CursorPos->x;
                ++CursorPos->index;
                position->x = CursorPos->x;
        		position->y = CursorPos->y;
        		position->jml_char = getIndex(content,CursorPos);
            }
        }
        position->jml_char = getIndex(content,CursorPos);
        displayContent(content, position);
        gotoxy(CursorPos);        
	}
	
    CursorPos->y = getHeight(content);
    gotoxy(CursorPos);
    
    printf("\n----------\nSave Changes?(y/n) ");
    while(ESC != (key = _getch()))
    {
        if(key == 'y' || key == 'Y')
        {
            putchar('y');
            return 0;
        }
        else if(key == 'n' || key == 'N' || key == ESC)
        {
            putchar('n');
            return 1;
        }
    }
}

int saveToFile(FILE *fp, List *content)
{
    Node *temp = NULL;
    for(temp = content->head; NULL != temp; temp = temp->next)
    {
        putc(temp->data, fp);
    }
}

//jumlah keseluruhan baris
int getHeight(List *content)
{
    int height = 0;
    Node *temp = NULL;
    for(temp = content->head; NULL != temp; temp = temp->next)
    {
        if(temp->data == '\n')
            ++height;
    }
    return height;
}

//Menghutung jumlah character dalam satu baris
int getLineLen(List *content, int lineNum)
{
    int i = 1;
    int linelen = 0;
    Node *temp;
    for(temp = content->head; temp != NULL; temp = temp->next)
    {
        if(i == lineNum)
        {
            if(temp->data != '\n')
                ++linelen;
            else
                break;
        }
        else if(i < lineNum)
        {
            if(temp->data == '\n')
                ++i;
        }
    }
    return linelen;
}

//Mencari Index tertentu
int getIndex(List *content, Point *CursorPos)
{
    int i = 0;
    int indx = 0;
    Node *temp = NULL;
    int x = CursorPos->x;
    int y = CursorPos->y;
    for(temp = content->head; NULL != temp; temp = temp->next)
    {
        if(i == y)
        {
            for(i = 0; i < x; ++i)
                ++indx;
            return indx;
        }
        else if(temp->data == '\n')
            ++i;
        ++indx;
    }
}

void copy(List *list, Point *CursorPos, List *copy_text){
	int stop = getIndex(list, CursorPos);
	int i;
	Node *temp = list->head;
	
	for(i=0;i<stop;i++){
		temp = temp->next;
	}
	i=0;
	do{
		insertNode(copy_text, CreateNode(temp->data), i);
		i++;
		temp = temp->next;
	}while(temp->data != ' ');
	
	for(Node *coba = copy_text->head; NULL != coba; coba =coba->next){
		printf("%c",coba->data);
	}
}

void paste(List *list, Point *CursorPos, List *copy_text){
	
	int stop = getIndex(list, CursorPos);
	Node *front = NULL;
	Node *back = NULL;
	
	front = list->head;
	back = list->head;
	Node *temp = NULL;
	
	for(int i=0;i<stop;i++){
		front = front->next;
	}
	back = front->next;
	
	back->prev = NULL;
	front->next = NULL;
	
	temp = copy_text->head;
	while(NULL != temp->next){
		temp = temp->next;
	}
	
	copy_text->head->prev = front;
	temp->next = back;
	
	back->prev = temp;
	front->next = copy_text->head;
	
}

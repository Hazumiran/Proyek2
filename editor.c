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
    Cord.Y = point->y+3;
    SetConsoleCursorPosition(hStdout, Cord);
}

void displayContent(List *list,Baris_Kolom *position)
{
    int x = 0;
	int y = 28;
	char key;
	List *content;
	Node *temp = NULL;
	
	if (position->x == 0){
		position->y = 1; 
	}
	else if(position->x == 0){
		position->x = 1; 
	}else if(key == 75){
		position->x = 1;
		position->y = 1;
	}
	
	if(position->x <= 9 || position->y <= 9){
		system("cls");
		PullDownDisplay();
		for(temp = list->head; NULL != temp; temp = temp->next)
    	{
        putchar(temp->data);
    	}
	}else if( position->x <= 9 && position->y <= 9){
		system("cls");
		PullDownDisplay();
		for(temp = list->head; NULL != temp; temp = temp->next)
    	{
        putchar(temp->data);
    	}
	}
	else if( position->x >= 10 && position->x >= 10){
		system("cls");
		PullDownDisplay();
		for(temp = list->head; NULL != temp; temp = temp->next)
    	{
        putchar(temp->data);
    	}
	}else if( position->x >= 10 || position->y >= 10){
		PullDownDisplay();
		for(temp = list->head; NULL != temp; temp = temp->next)
    	{
        putchar(temp->data);
    	}
	}
	
	for(int i=1; i <= 125; i++)
	{
		goto_xy(x,y);
		printf("%c", 196);
		x++;
	}

	goto_xy(0,28);
    printf("\nBaris : %d\t",position->x); 
	printf("Kolom : %d\t",position->y);
//	printf("Jumlah Karakter : %d", *jml_char);
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
//	CursorPos->y=3;
    signed char key;
    position->x =  1;
    position->y =  1;
    
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
                    gotoxy(CursorPos);
                    continue;
                }
                //Tanpa ketentutan
                else
                {
                    position->x -= 1;
                    displayContent(content,position);             	
                    CursorPos->y -= 1;
                    CursorPos->index = getIndex(content, CursorPos);
                    gotoxy(CursorPos);
                    continue;
                }
            }
            else if(key == ARROWDOWNKEY)//DOWN
            {
            	//pada ujung bawah
                if(CursorPos->y == getHeight(content))
                {
                	position->x = position->x;
                	displayContent(content,position);
                    continue;
                }
                //yang bawah lebih sedikit dari yang atas
                else if(CursorPos->x > getLineLen(content, CursorPos->y + 2))
                {
                	position->x += 1;
                	position->x = getLineLen(content, CursorPos->y + 2) + 1;
                	displayContent(content,position);
                    CursorPos->x = getLineLen(content, CursorPos->y + 2);
                    CursorPos->y += 1;
                    CursorPos->index = getIndex(content, CursorPos);
                    gotoxy(CursorPos);
                    continue;
                }
                //tanpa ketentuan
                else
                {
                	position->x += 1;
                	displayContent(content,position);
                    CursorPos->y += 1;
                    CursorPos->index = getIndex(content, CursorPos);
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
                    gotoxy(CursorPos);
                    continue;
                }
                else
                {
                	position->x += 1;
                	displayContent(content,position);
                    CursorPos->x += 1;
                    CursorPos->index = getIndex(content, CursorPos);
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
                    displayContent(content,position);
                    continue;
                }
                else if(CursorPos->x == 0)
                {
                    //At start of line, but not start of file
                    position->x = getLineLen(content, CursorPos->y) + 1;
                    position->x -= 1;
                    displayContent(content,position);
                    CursorPos->x = getLineLen(content, CursorPos->y);
                    --CursorPos->y;
                    CursorPos->index = getIndex(content, CursorPos);
                    gotoxy(CursorPos);
                    continue;
                }
                else{
                	position->x -= 1;
                	displayContent(content,position);
                    --CursorPos->x;
                    CursorPos->index = getIndex(content, CursorPos);
                    gotoxy(CursorPos);
                    continue;
                }
            }
            else if(key == CTRLLEFT){
            	CursorPos->x = 0;
            	CursorPos->index = getIndex(content, CursorPos);
            	gotoxy(CursorPos);
            	continue;
			}
			else if(key == CTRLRIGHT){
				CursorPos->x = getLineLen(content, CursorPos->y + 1);
				CursorPos->index = getIndex(content, CursorPos);
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
                displayContent(content,position);
                continue;  
            }
            else if(CursorPos->x == 0)
            {
                position->x = getLineLen(content, CursorPos->y) + 1;
                position->y = position->y - 1;
                displayContent(content,position);
				CursorPos->x = getLineLen(content, CursorPos->y);
		        CursorPos->y -= 1;
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
                displayContent(content,position);
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
            }
        position->x = position->x + 3;    
        }
        else if(key == 11){
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
        		position->y = position->y + 1;
            }
            else
            {
                insertNode(content, CreateNode(key), CursorPos->index);
                ++CursorPos->x;
                ++CursorPos->index;
            }
        }
        position->x+=1;
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

//Menghutung jumlah semua character
//int Jml_Character(List *content, int lineNum)
//{
//    int i = 1;
//    int linelen = 0;
//    Node *temp;
//    for(temp = content->head; temp != NULL; temp = temp->next)
//    {
//        if(i == lineNum)
//        {
//            if(temp->data != '\n')
//                ++linelen;
//            else
//        }
//        else if(i < lineNum)
//        {
//            if(temp->data == '\n')
//                ++i;
//        }
//    }
//    return linelen;
//}

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

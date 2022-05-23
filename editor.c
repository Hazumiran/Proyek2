#include "editor.h"
#include "PulDown.h"
<<<<<<< HEAD
#include "FileHandl.h"
=======
>>>>>>> main

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

void TempKolomBaris(int *baris , int *kolom, int *jml_char){
	int x = 28;
	int y = 0;
	
	for(int i=1; i <= 125; i++)
	{
		gotoxy(x,y);
		printf("%c", 196);
		y++;
	}
	if (*baris == 0){
		*baris = 1; 
	}
	else if(*kolom == 0){
		*kolom = 1; 
	}
	
	gotoxy(28,0);
    printf("\nBaris : %d\t",*baris); 
	printf("Kolom : %d\t",*kolom);
//	printf("Jumlah Karakter : %d", *jml_char);
}

void displayContent(List *list,int *baris, int *kolom, int *jml_char)
{
    Node *temp = NULL;
    system("cls");
	PullDownDisplay();
    for(temp = list->head; NULL != temp; temp = temp->next)
    {
        putchar(temp->data);
    }
    TempKolomBaris(baris, kolom, jml_char);
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
  //      *jml_char = *jml_char + 1;
    }
    return 0;
}

int KursorHandl(List *content, Point *CursorPos, int *baris, int *kolom, int *jml_char){

//	unsigned char key;
//	CursorPos->y=3;
	int tamp = 0;
    signed char key;
    *kolom =  1;
    *baris =  1;
    
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
                    *baris = 1;
                    TempKolomBaris(baris, kolom, jml_char);
                    continue;
                }
                
                //yang atas lebih sedikit dari yang bawah
                else if(CursorPos->x > getLineLen(content, CursorPos->y))
                {
                	*baris = *baris -1;
                	*kolom = getLineLen(content, CursorPos->y) + 1;
                    TempKolomBaris(baris, kolom, jml_char);
                    CursorPos->x = getLineLen(content, CursorPos->y);
                    CursorPos->y -=1;
                    CursorPos->index = getIndex(content, CursorPos);
                    gotoxy(CursorPos);
                    continue;
                }
                //Tanpa ketentutan
                else
                {
                	*baris = *baris - 1;
                    TempKolomBaris(baris, kolom, jml_char);
                    CursorPos->y -=1;
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
                	*baris = *baris;
                	TempKolomBaris(baris, kolom, jml_char);
                    continue;
                }
                //yang bawah lebih sedikit dari yang atas
                else if(CursorPos->x > getLineLen(content, CursorPos->y + 2))
                {
                	*baris = *baris + 1;
                	*kolom = getLineLen(content, CursorPos->y + 2) + 1;
                    TempKolomBaris(baris, kolom, jml_char);
                    CursorPos->x = getLineLen(content, CursorPos->y + 2);
                    CursorPos->y += 1;
                    CursorPos->index = getIndex(content, CursorPos);
                    gotoxy(CursorPos);
                    continue;
                }
                //tanpa ketentuan
                else
                {
                	*baris = *baris + 1;
                    TempKolomBaris(baris, kolom, jml_char);
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
                    *kolom = *kolom;
					TempKolomBaris(baris, kolom, jml_char);
                    continue;
                }
                else if(CursorPos->x == getLineLen(content, CursorPos->y + 1))
                {
                    //At end of line, but not end of file
                    *kolom = 1;
                    *baris = *baris + 1;
                    TempKolomBaris(baris, kolom, jml_char);
                    CursorPos->x = 0;
					++CursorPos->y;
                    CursorPos->index = getIndex(content, CursorPos);
                    gotoxy(CursorPos);
                    continue;
                }
                else
                {
                	*kolom = *kolom + 1;
                    TempKolomBaris(baris, kolom, jml_char);
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
                    *kolom = 1;
                    TempKolomBaris(baris, kolom, jml_char);
                    continue;
                }
                else if(CursorPos->x == 0)
                {
                    //At start of line, but not start of file
                    *kolom = getLineLen(content, CursorPos->y) + 1;
                    *baris = *baris - 1;
                    TempKolomBaris(baris, kolom, jml_char);
                    CursorPos->x = getLineLen(content, CursorPos->y);
                    --CursorPos->y;
                    CursorPos->index = getIndex(content, CursorPos);
                    gotoxy(CursorPos);
                    continue;
                }
                else{
                	*kolom = *kolom - 1;
                    TempKolomBaris(baris, kolom, jml_char);
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
            if((CursorPos->x == 0) && (CursorPos->y == 3))
            {
              *kolom = getLineLen(content, CursorPos->y);
              *baris = *baris -1;
              TempKolomBaris(baris, kolom, jml_char);
                continue;
            }
            else if(CursorPos->x == 0)
            {
            	*kolom = 1;
				TempKolomBaris(baris, kolom, jml_char); 
				CursorPos->x = getLineLen(content, CursorPos->y);
		        CursorPos->y -= 1;
		        removeNodeByIndex(content, CursorPos->index -= 1);	
            }
            else
            {
<<<<<<< HEAD
				*kolom = *kolom - 1;
                TempKolomBaris(baris, kolom, jml_char);
=======
>>>>>>> main
                putchar(BACKSPACEKEY);
                putchar(SPACEKEY);
                putchar(BACKSPACEKEY);
                removeNodeByIndex(content, CursorPos->index -= 1);
                CursorPos->x -= 1;
            }
        *kolom = *kolom - 1;
    	TempKolomBaris(baris, kolom, jml_char);
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
        *kolom = *kolom + 3;    
        }
        else if(key == 11){
<<<<<<< HEAD
        	PullDown(content);
=======
        	PullDown(content, &tamp);
        	if(tamp == 0){
        		return tamp;
			}
>>>>>>> main
		}
        else
        {
            if(key == ENTERKEY || key == NLINE)
            {
                insertNode(content, CreateNode(NLINE), CursorPos->index);
				CursorPos->x = 0;
                ++CursorPos->y;
                ++CursorPos->index;
                *kolom = 0;
        		*baris = *baris + 1;
            }
            else
            {
                insertNode(content, CreateNode(key), CursorPos->index);
                ++CursorPos->x;
                ++CursorPos->index;
            }
        }
        *kolom = *kolom + 1;
        displayContent(content, baris, kolom, jml_char);
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

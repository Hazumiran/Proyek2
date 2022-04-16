#include "editor.h"

Point *pointCtor(){
    Point *newPoint = (Point *)malloc(sizeof(Point));
    newPoint->x = NULL;
    newPoint->y = NULL;
    newPoint->index = NULL;

    return newPoint;
}

void printListChars(List *list)
{
    Node *temp = NULL;
    for(temp = list->head; NULL != temp; temp = temp->next)
    {
        if(temp->data == '\n')
            printf("[\\n]->");
        else
            printf("[%c]->", temp->data);
    }
    printf("[NULL]\n");
}

void gotoPos(Point *point)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Cord;
    Cord.X = point->x;
    Cord.Y = point->y;
    SetConsoleCursorPosition(hStdout, Cord);
}

void displayContent(List *list)
{
    Node *temp = NULL;
    system("cls");
    for(temp = list->head; NULL != temp; temp = temp->next)
    {
        putchar(temp->data);
    }
}

int readFile(FILE *fp, List *content, Point *CursorPos)
{
    char character;
    while(EOF != (character = getc(fp)))
    {
        if(character == '\n')
        {
            putchar(character);
            insertNode(content, nodeCtor(character), CursorPos->index);
			CursorPos->y += 1;
            CursorPos->x = 0;
            CursorPos->index += 1;
        }
        else
        {
            putchar(character);
            insertNode(content, nodeCtor(character), CursorPos->index);
            CursorPos->x += 1;
            CursorPos->index += 1;
        }
    }
    return 0;
}

int editContent(List *content, Point *CursorPos){

//	unsigned char key;
    signed char key;
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
                    continue;
                }
                
                //yang atas lebih sedikit dari yang bawah
                else if(CursorPos->x > getLineLen(content, CursorPos->y))
                {
                    CursorPos->x = getLineLen(content, CursorPos->y);
                    CursorPos->y -=1;
                    CursorPos->index = getIndex(content, CursorPos);
                    gotoPos(CursorPos);
                    continue;
                }
                //Tanpa ketentutan
                else
                {
                    CursorPos->y -=1;
                    CursorPos->index = getIndex(content, CursorPos);
                    gotoPos(CursorPos);
                    continue;
                }
            }
            else if(key == ARROWDOWNKEY)//DOWN
            {
            	//pada ujung bawah
                if(CursorPos->y == getHeight(content))
                {
                    continue;
                }
                //yang bawah lebih sedikit dari yang atas
                else if(CursorPos->x > getLineLen(content, CursorPos->y + 2))
                {
                    CursorPos->x = getLineLen(content, CursorPos->y + 2);
                    CursorPos->y += 1;
                    CursorPos->index = getIndex(content, CursorPos);
                    gotoPos(CursorPos);
                    continue;
                }
                //tanpa ketentuan
                else
                {
                    CursorPos->y += 1;
                    CursorPos->index = getIndex(content, CursorPos);
                    gotoPos(CursorPos);
                    continue;
                }

            }
            else if(key == ARROWRIGHTKEY) //RIGHT
            {
                if((CursorPos->y == getHeight(content)) && (CursorPos->x == getLineLen(content, CursorPos->y + 1)))
                {
                    //At end of file
                    continue;
                }
                else if(CursorPos->x == getLineLen(content, CursorPos->y + 1))
                {
                    //At end of line, but not end of file
                    CursorPos->x = 0;
                    ++CursorPos->y;
                    CursorPos->index = getIndex(content, CursorPos);
                    gotoPos(CursorPos);
                    continue;
                }
                else
                {
                    ++CursorPos->x;
                    CursorPos->index = getIndex(content, CursorPos);
                    gotoPos(CursorPos);
                    continue;
                }
            }
            else if(key == ARROWLEFTKEY)//LEFT
            {
                if((CursorPos->x == 0) && (CursorPos->y == 0))
                {
                    //At start of file
                    continue;
                }
                else if(CursorPos->x == 0)
                {
                    //At start of line, but not start of file
                    CursorPos->x = getLineLen(content, CursorPos->y);
                    --CursorPos->y;
                    CursorPos->index = getIndex(content, CursorPos);
                    gotoPos(CursorPos);
                    continue;
                }
                else
                {
                    --CursorPos->x;
                    CursorPos->index = getIndex(content, CursorPos);
                    gotoPos(CursorPos);
                    continue;
                }
            }
        }
        else if(key == BACKSPACEKEY) //TODO check bug when deleting after arrow job
        {
            if((CursorPos->x == 0) && (CursorPos->y == 0))
            {
                continue;
            }
            else if(CursorPos->x == 0)
            {
                CursorPos->x = getLineLen(content, CursorPos->y);
                CursorPos->y -= 1;
                removeNodeByIndex(content, CursorPos->index -= 1);
            }
            else
            {
//                putchar(BACKSPACEKEY);
//                putchar(SPACEKEY);
//                putchar(BACKSPACEKEY);
                removeNodeByIndex(content, CursorPos->index -= 1);
                CursorPos->x -= 1;
            }
        }
        else if(key == TAB)
        {
            int i;
            for(i = 0; i < 4; ++i)
            {
                insertNode(content, nodeCtor(SPACEKEY), CursorPos->index);
                ++CursorPos->x;
                ++CursorPos->index;
            }
        }
        else
        {
            if(key == ENTERKEY || key == NLINE)
            {
                insertNode(content, nodeCtor(NLINE), CursorPos->index);
                CursorPos->x = 0;
                ++CursorPos->y;
                ++CursorPos->index;
            }
            else
            {
                insertNode(content, nodeCtor(key), CursorPos->index);
                ++CursorPos->x;
                ++CursorPos->index;
            }
        }

        displayContent(content);
        gotoPos(CursorPos);
    }

    CursorPos->y = getHeight(content);
    gotoPos(CursorPos);
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

void saveToFile(FILE *fp, List *content)
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

//Menghutung jumlah character pada 1 baris
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

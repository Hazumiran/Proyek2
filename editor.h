#include <conio.h>
#include <windows.h>
#include "linkedlist.h"

#ifndef editor.H
#define editor.H

#define ZERO 0
#define NLINE 10
#define ENTERKEY 13
#define SPACEKEY 32
#define BACKSPACEKEY 8
#define TAB 9
#define ESC 27

//#define ARROWKEY 224
#define ARROWKEY -32
#define ARROWUPKEY 72
#define ARROWDOWNKEY 80
#define ARROWRIGHTKEY 77
#define ARROWLEFTKEY 75

#define CTRLRIGHT 116
#define CTRLLEFT 115


#define yKey 121
#define YKey 89
#define nKey 110
#define NKey 78

#define TRUE 1
#define FALSE 0

typedef struct ScreenPos_s
{
    int x;
    int y=3;
    int index;
}Point;

Point * pointCtor();
void printListChars(List *list);
void TempKolomBaris(int *baris , int *kolom, int jml_char);
void displayContent(List *list, int *baris, int *kolom, int *jml_char);
int lineLen(List *content, int line);
int readFile(FILE *fp, List *content, Point *CursorPos);
int KursorHandl(List *content, Point *CursorPos, int *baris, int *kolom, int *jml_char);
int saveToFile(FILE *fp, List *content);
int getHeight(List *content);
int getLineLen(List *content, int lineNum);
int getIndex(List *content, Point *CursorPos);

#endif
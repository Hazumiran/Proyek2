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
    int y;
    int index;
}Point;

typedef struct Baris_Kolom{
	int x;
	int y;
	int jml_char;
};

Point * pointCtor();
void printListChars(List *list);
void displayContent(List *list, Baris_Kolom *position);
int lineLen(List *content, int line);
int readFile(FILE *fp, List *content, Point *CursorPos);
int KursorHandl(List *content, Point *CursorPos, Baris_Kolom *position);
int saveToFile(FILE *fp, List *content);
int getHeight(List *content);
int getLineLen(List *content, int lineNum);
int getIndex(List *content, Point *CursorPos);
void paste(List *list, Point *CursorPos, List *copy_text);
void copy(List *list, Point *CursorPos, List *copy_text);

#endif
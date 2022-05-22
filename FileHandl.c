#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "FileHandl.H"
#include "linkedlist.H"
#include "editor.H"
#include "PulDown.h"

FILE *fp;

void CreateFile(){
		char fname[20];
        List *content = CreateHead();
        
        printf(" Name Of File : ");
		scanf("%s",fname);		
		system("cls");
		
        Point *CursorPos = pointCtor();
		PullDownDisplay();
        if(KursorHandl(content, CursorPos) == 0){
			fp = fopen(fname, "w");
            saveToFile(fp, content);
            fclose(fp);
            putchar('\n');
        }
        deleteList(content);
}

void OpenFile(){
	char fname[20];
        List *content = CreateHead();
        
        printf(" Input the filename to be opened : ");
		scanf("%s",fname);
        FILE *fp = fopen(fname, "r");

        Point *CursorPos = pointCtor();
        system("cls");

        readFile(fp, content, CursorPos);
        fclose(fp);
        if(KursorHandl(content, CursorPos) == 0)
        {
            fp = fopen(fname, "w");
            saveToFile(fp, content);
            fclose(fp);
            putchar('\n');
        }
        deleteList(content);
}
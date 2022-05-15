#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "FileHandl.H"
#include "linkedlist.H"
#include "editor.H"

FILE *fp;

void CreateFile(){
		char fname[20];
        List *content = CreateHead();
        
        printf(" Name Of File : ");
		scanf("%s",fname);
		
		system("cls");
        Point *CursorPos = pointCtor();
	    int a = 186;
	    int b = 200;
	    int c = 201;
	    printf("%c\n",c);
	    printf("%c\n",a);
	    printf("%c\n",b);
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
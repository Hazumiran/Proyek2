#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "FileHandl.H"
#include "linkedlist.H"
#include "editor.H"
#include <dirent.h>
#include <corecrt.h> 

FILE *fp;
int baris = 0, kolom = 0;

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
        if(KursorHandl(content, CursorPos, &baris, &kolom) == 0){
            saveToFile(fp, content);
			fp = fopen(fname, "w");
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
        if(KursorHandl(content, CursorPos, &baris, &kolom) == 0)
        {
            fp = fopen(fname, "w");
            saveToFile(fp, content);
            fclose(fp);
            putchar('\n');
        }
        deleteList(content);
}

bool txt_exe(char const *name)
{
	size_t len = strlen(name);
	return len > 4 && strcmp(name + len - 4, ".txt")== 0;
}

void Delete(){
	DIR *d;
  struct dirent *dir;
  d = opendir(".");
  if (d) {
    while ((dir = readdir(d)) != NULL) {
     if(txt_exe(dir->d_name)){    	
    	  printf("%s\n", dir->d_name);
		}	
    }
    closedir(d);
  }
int c;
FILE *file;
file = fopen("temp.txt", "r");
if (file) {
    while ((c = getc(file)) != EOF)
        putchar(c)  ;
    fclose(file);
}
FILE *fp;
	char fn[15];
	fp=fopen("temp.txt","r");
	printf("\n\t pilih file yang akan dihapus: ");
	scanf("%s",fn);
	fp=fopen(fn,"r");
	
	if(fp==NULL){
		printf("\n\tFile not found!");
	}
	
	fclose(fp);
	
remove(fn);
		printf("\n\n\tFile has been deleted successfully!");
    		
    
}	

void gotoxy(int baris,int kolom)
{
	COORD coord;
	
    coord.X = kolom;
    coord.Y = baris;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
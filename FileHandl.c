#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "FileHandl.H"
#include "linkedlist.H"
#include "editor.H"
#include "PulDown.h"
#include <dirent.h>
#include <corecrt.h> 

FILE *fp;

void CreateFile(){
		char fname[20];
        List *content = CreateHead();
		system("cls");
		strcpy(fname,"temp.txt");
		
        Point *CursorPos = pointCtor();
		PullDownDisplay();
		
		while(KursorHandl(content, CursorPos) != 1){
            printf("Masukkin nama filnya gan : ");
            scanf("%s",fname);
            rename("temp.txt",fname);
			fp = fopen(fname, "w");
            saveToFile(fp, content);
			fp = fopen(fname, "w");
            fclose(fp);
		}
		
//        if(KursorHandl(content, CursorPos) == 0){
//			fp = fopen(fname, "w");
//            saveToFile(fp, content);
//            fclose(fp);
//            putchar('\n');
//        }
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

bool txt_exe(char const *name){
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

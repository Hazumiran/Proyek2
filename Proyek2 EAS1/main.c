#include "editor.h"

int main() {
	char fname[20];
        List *content = listCtor();
        
        printf(" Input the filename to be opened : ");
		scanf("%s",fname);
        FILE *fp = fopen(fname, "r");

        Point *CursorPos = pointCtor();
        system("cls");

        readFile(fp, content, CursorPos);
        fclose(fp);
        if(editContent(content, CursorPos) == 0)
        {
            fp = fopen(fname, "w");
            saveToFile(fp, content);
            fclose(fp);
            putchar('\n');
        }
        deleteList(content);
    return 0;
}

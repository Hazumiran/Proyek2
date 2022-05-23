#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "crud.h"

void total_char(){
	char buff[255];
	int total = 0;
	
	printf("\n\tEnter the file name: ");
	scanf("%s",fn);
	fp1=fopen(fn,"r");
	
	while(fgets(buff,sizeof(buff),fp1)){
		total = strlen(buff);
	}
	
	printf("Total character dalam file tersebut = %i",total);
	
	fclose(fp1);
	printf("\n\n\tPress any key to continue\n");
	getch();
}


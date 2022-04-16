#ifndef firep_H
#define firep_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000
#define CHAR_SIZE 256

void ReplaceText(char string[], char newWord[], char oldWord[], int s);
void search(char string[], char oldWord[], char newWord[]);
void findrep();
int main();

#endif

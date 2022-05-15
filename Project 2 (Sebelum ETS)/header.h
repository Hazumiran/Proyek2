#ifndef header_h
#define header_h 

#define MAX 100
#define LEN 80	
#define BUFFER_SIZE 1000

void arr();
void Total_Char(char fn[30]);
void display(char fname[30]);
void display1(char fname[30]);
void edit_file(char fn[30]);
void Menu();
void Delete();
void find();
void replaceAll(char *str, const char *oldWord, const char *newWord);
void DeleteLine(char fn[30]);
void insert_line(char fn[30]);

#endif
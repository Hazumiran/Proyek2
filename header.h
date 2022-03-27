#ifndef header_h
#define header_h 

#define MAX 100
#define LEN 80	
#define BUFFER_SIZE 1000

void arr();
void Total_Char(char fn[]);
void display(char fname[]);
void display1(char fname[]);
void edit_file(char fn[]);
void Menu();
void Delete();
void find();
void replaceAll(char *str, const char *oldWord, const char *newWord);
void DeleteLine(char fn[]);
void insert_line(char fn[]);

//char text[MAX][LEN];
//FILE *fp, *fp1;
//char fn[15];
//int i,j,t,k,l,m,temp_m,tot;
#endif
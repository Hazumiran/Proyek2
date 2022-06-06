#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include "editor.h"
#include "Find.h"
//#include "help.h"


#define bb  201 // ╔
#define cc  205 // ═
#define dd  186 // ║
#define ee  200 // ╚
#define ff  203 // ╦
#define gg  202 // ╩
#define hh  188 // ╝
#define ii  187 // ╗


void goto_xy(int x, int y);
void color(int color);
int Dialog();
void Menu_Pertama();
void PullDown(List *list, char fname[20], Baris_Kolom *position);
int PullDownDisplay();
void TextBox(int c, int d);
void TextBox2(int c, int d);
void help();

void about();
void writeflush();

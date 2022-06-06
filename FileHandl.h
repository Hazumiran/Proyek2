#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>

#include "linkedlist.H"
#include "editor.H"
#include "PulDown.h"

#ifndef FileHandl_H
#define FileHandl_H

void CreateFile(List *list);
void OpenFile(List *list);
void Menu();
void Delete();
void rename();
bool txt_exe(char const *name);

void driver();


#endif
#include "PulDown.h"
#include "editor.h"
#include "FileHandl.h"

void color(int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

void goto_xy(int x, int y){
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}


void PullDown(List *list, int *x){
	HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    baliksini:
    int Set[] = {7,7,7};
	char counter = 2;
	char key;
	
	for(int i = 0 ;;){
	displayContent(list);
	tampil:
	color(Set[3]);
	goto_xy(0,0);	
	printf("%c",bb);
	color(Set[3]);
	for(int p = 0; p < 91; p++){
		if(p == 6 || p == 12){
			printf("%c",ff);
		}
		printf("%c",cc);		
	}
	color(Set[3]);
	printf("\n%c",dd);
	goto_xy(1,1);
	color(Set[0]);	
	printf("File ");
	color(Set[3]);
	printf(" %c",dd);
	
	goto_xy(8,1);
	color(Set[1]);	
	printf("Edit  ");
	
	color(Set[3]);	
	printf("%c",dd);
	goto_xy(15,1);
	color(Set[2]);	
	printf("View \t\t\t\t\t\t\t\t\t");
	color(Set[3]);
	printf("\n%c",ee);
	
	for(int u = 0; u < 91; u++){
		if(u == 6 || u == 12){
			printf("%c",gg);		
		}
		printf("%c",cc);		
	}	
		
		key = _getch();
		if(key == 11){
			break;
		}
		
		if(key == 75&& (counter >=2 && counter <= 3)){
//			system("cls");
			counter --;
			
		}if(key == 77 && (counter >=1 && counter <= 2)){
//			system("cls");
			counter ++;
			
		}if(key == '\r'){
			balikmenu:
			if(counter == 1){
				balikdialog:
//				cout<<"Menu 1 Is Open";
				
	//TAMPIL MENU SOALNYA LOH KOK GAADA ANEH
				color(Set[3]);
				goto_xy(0,0);				
				printf("%c",bb);
				for(int p = 0; p < 91; p++){
				if(p == 6 || p == 12){
					printf("%c",ff);
				}
				printf("%c",cc);		
				}
				printf("\n%c",dd);
				goto_xy(1,1);
				color(Set[0]);				
				printf("File ");
				color(Set[3]);
				printf(" %c",dd);
				
				goto_xy(8,1);
				color(Set[1]);				
				printf("Edit  ");
				
				color(Set[3]);	
				printf("%c",dd);
				goto_xy(15,1);
				color(Set[2]);				
				printf("View");
				color(Set[3]);
				printf("\n%c",ee);
				for(int u = 0; u < 91; u++){
				if(u == 6 || u == 12){
					printf("%c",gg);		
				}
				printf("%c",cc);		
				}				
				// PANUTUP TAMPIL GAN	
				int Set2[] = {7,7,7};
				char counter2 = 2;
				char key2;
	
				for(int a = 0 ;;){
				goto_xy(1,3);
				color(Set[3]);
				printf("%c",dd);
				color(Set2[0]);		
				printf("Save      ");
				color(Set[3]);
				printf(" %c",dd);
			
				goto_xy(1,4);
				color(Set[3]);
				printf("%c",dd);
				color(Set2[1]);
				printf("Open File");
				color(Set[3]);
				printf("  %c",dd);
				
				goto_xy(1,5);
				color(Set[3]);
				printf("%c",dd);
				color(Set2[2]);
				printf("Delete File");	
				color(Set[3]);
				printf("%c",dd);
				
				goto_xy(1,6);
				color(Set[3]);
				printf("%c",dd);
				color(Set2[3]);
				printf("Exit");						
				
				color(Set[3]);
				printf("\t     %c",dd);
				printf("\n %c",ee);
				printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",hh);
	
				key2 = _getch();
				
				if(key2 == 72&& (counter2 >=2 && counter2 <= 4)){			
					counter2 --;
					
				}if(key2 == 80 && (counter2 >=1 && counter2 <= 3)){			
					counter2 ++;
					
				}if(key2 == 75&& (counter2 >=2 && counter2 <= 3)){
//					system("cls");
					displayContent(list);
					counter --;
					goto balikmenu;
					
				}if(key2 == 77 && (counter2 >=1 && counter2 <= 2)){
//					system("cls");
					displayContent(list);
					counter ++;
					goto balikmenu;
				}if(key2 == 20){	//ctrl + T		
					goto baliksini; 
				
				//-----------------------------------------------------------------------Untuk nambahin function di edit
				}if(key2 == '\r'){
					if(counter2 ==1){
						*x = 0;
						goto_xy(20,10);
						printf("filenya ke save gan");
						getch();
						system("cls");
//					printf("asek");
					}
					if(counter2 ==2){
						OpenFile();	
					printf("New Windows jalan");
					}
					if(counter2 ==4){
						//DIALOG BOX
						
							int Set4[] = {7,7};
							char counter4 = 1;
							char key4;
							for(int DialogCount = 0 ;;){									
									goto_xy(31,9);										
									color(Set[3]);
									printf("%c",bb);
										for(int garis = 0; garis < 31; garis++){						
										printf("%c",cc);		
										}
									printf("%c",ii);
									
									goto_xy(31,10);														
									printf("%c",dd);
									goto_xy(31,11);														
									printf("%c",dd);
									goto_xy(31,12);					
									printf("%c",dd);
									goto_xy(31,13);					
									printf("%c",dd);
									goto_xy(31,14);					
									printf("%c",dd);
									goto_xy(31,15);					
									printf("%c",dd);	
									goto_xy(31,16);					
									printf("%c",ee);
									goto_xy(32,16);	
									for(int garis2 = 0; garis2 < 31; garis2++){						
										printf("%c",cc);		
										}										
									goto_xy(63,10);					
									printf("%c",dd);
									goto_xy(63,11);					
									printf("%c",dd);					
									goto_xy(63,12);					
									printf("%c",dd);
									goto_xy(63,13);					
									printf("%c",dd);
									goto_xy(63,14);					
									printf("%c",dd);
									goto_xy(63,15);					
									printf("%c",dd);
									goto_xy(63,16);					
									printf("%c",hh);
									
									
									//Text
									goto_xy(34,11);														
									printf("Apakah Yakin ingin Keluar ?");
									goto_xy(33,15);		
									color(Set4[0]);
									printf("Yes");
									goto_xy(60,15);
									color(Set4[1]);					
									printf("No");
									
										key4 = _getch();
		
											if(key4 == 75&& (counter4 >=2 && counter4 <= 3)){												
												counter4 --;
												
											}if(key4 == 77 && (counter4 >=1 && counter4 <= 2)){												
												counter4 ++;
												
											}if(key4 == '\r'){												
												if(counter4 == 1){
													system("cls");
//													return 0;
													exit(1);
												}if(counter4 == 2){
													system("cls");
													goto balikmenu;
												}else{
													goto balikdialog;
												}
												
										}Set4[0] =7;
												Set4[1] =7;													

												if(counter4 == 1){
														Set4[0] = 9;
												}
												if(counter4 == 2){
														Set4[1] = 9;
												}
							}//PANUTUP FOR DIALOG
						//PANUTUP DIALOG
					}if(counter2 ==3){
					printf("New Windows jalan");
					}
				}

				Set2[0] =7;
				Set2[1] =7;
				Set2[2] =7;
				Set2[3] =7;
				Set2[4] =7;
		
				if(counter2 == 1){
						Set2[0] = 9;					
				}
				if(counter2 == 2){
						Set2[1] = 9;						
				}
				if(counter2 == 3){
						Set2[2] = 9;						
				}if(counter2 == 4){
						Set2[3] = 9;
				}if(counter2 == 5){
						Set2[4] = 9;
				}
			
				} //penutup for
				
				
				
		}if(counter == 2){
//				cout<<"Menu 2 Is Open";	
				
	//TAMPIL MENU SOALNYA LOH KOK GAADA ANEH
				goto_xy(0,0);
				printf("%c",bb);
				for(int p = 0; p < 91; p++){
				if(p == 6 || p == 12){
					printf("%c",ff);
				}
				printf("%c",cc);		
				}
				printf("\n%c",dd);
				goto_xy(1,1);
				color(Set[0]);
				printf("File ");
				color(Set[3]);
				printf(" %c",dd);
				
				goto_xy(8,1);
				color(Set[1]);
				printf("Edit  ");
				
				color(Set[3]);	
				printf("%c",dd);
				goto_xy(15,1);
				color(Set[2]);
				printf("View");
				color(Set[3]);
				printf("\n%c",ee);
				for(int u = 0; u < 91; u++){
				if(u == 6 || u == 12){
					printf("%c",gg);		
				}
				printf("%c",cc);		
				}
// PANUTUP TAMPIL GAN	
				int Set3[] = {7,7,7};
				char counter3 = 2;
				char key3;
						
				for(int b ;;){
					
				goto_xy(8,3);
				color(Set[3]);
				printf("%c",dd);
				color(Set3[0]);		
				printf("Find And Replace");
				color(Set[3]);
				printf(" %c",dd);
			
				goto_xy(8,4);
				color(Set[3]);
				printf("%c",dd);
				color(Set3[1]);
				printf("Copy");
				color(Set[3]);
				printf("             %c",dd);
				
				goto_xy(8,5);
				color(Set[3]);
				printf("%c",ee);
				printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",hh);

				key3 = _getch();
				
				if(key3 == 72&& (counter3 >=2 && counter3 <= 3)){			
					counter3 --;
					
				}if(key3 == 80 && (counter3 >=1 && counter3 <= 2)){			
					counter3 ++;
					
				}if(key3 == 75&& (counter3 >=2 && counter3 <= 3)){
//					system("cls");	
					displayContent(list);				
					counter --;
					goto balikmenu;
					
				}if(key3 == 77 && (counter3 >=0 && counter3 <= 3)){
//					system("cls");
					displayContent(list);
					counter ++;
					goto balikmenu;
				}if(key3 == 20){	//ctrl + T		
					goto baliksini; 
				
				//-----------------------------------------------------------------untuk Menu Edit Masukin sini functionnya
				}if(key3 == '\r'){
					if(counter3 ==1){
					printf("New Windows jalan");
					}
					if(counter3 ==2){
					printf("New Windows jalan");
					}
					if(counter3 ==3){
					printf("New Windows jalan");
					}
				}

				Set3[0] =7;
				Set3[1] =7;
				Set3[2] =7;
		
				if(counter3 == 1){
						Set3[0] = 9;
				}
				if(counter3 == 2){
						Set3[1] = 9;
				}
				if(counter3 == 3){
						Set3[2] = 9;
				}

				}//panutup for
				
		}if(counter == 3){
				printf("Menu 3 Is Open");
		}else{
				goto baliksini;
		}
		}
		
		Set[0] =7;
		Set[1] =7;
		Set[2] =7;
		Set[3] =15;
		

		if(counter == 1){
				Set[0] = 9;
		}
		if(counter == 2){
				Set[1] = 9;
		}
		if(counter == 3){
				Set[2] = 9;
		}
	 }
}

void PullDownDisplay(){
	
	for(int i = 0; i<3;i++){
		for(int j=0;j<91;j++){
			if(i == 0){
				if(j == 0){
					printf("%c",bb);
				}
				else if(j==7 || j ==14){
					printf("%c",ff);
				}
				else{
					printf("%c",cc);
				}			
			}
			if(i == 1){
				if(j == 0 || j == 7 || j == 14){
					printf("%c",dd);
				}
				if (j == 0){
					printf("File");
					j=j+4;
				}
				else if( j == 7){
					printf("Edit");
					j=j+4;
				}
				else if(j == 14){
					printf("View");
					j=j+4;
				}
				else{
					printf(" ");
				}
			}
			if(i == 2){
				if(j == 0){
					printf("%c",ee);
				}
				else if(j==7 || j ==14){
					printf("%c",gg);
				}
				else{
					printf("%c",cc);
				}			
			}
		}
		printf("\n");
	}
}
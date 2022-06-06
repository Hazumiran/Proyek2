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

void PullDown(List *list, char fname[20], Baris_Kolom *position){
	HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    baliksini:
    int Set[] = { 543,543,543};
	char counter = 1;
	char key;
	int temp1, temp2;
	
	for(int i = 0 ;;){
	displayContent(list, position);
	tampil:

	goto_xy(0,0);
	color(Set[0]);	
	printf("File     ");

	goto_xy(9,0);
	color(Set[1]);	
	printf("Edit     ");

	goto_xy(18,0);
	color(Set[2]);	
	printf("View    ");
	color(543);
	printf("                                                                                              ");
	color(7);	
		
		key = _getch();
		if(key == 11){
			position->x = position->x;
			position->y = position->y;
			break;
		}
		
		if(key == 75&& (counter >=2 && counter <= 3)){
			counter --;

		}if(key == 77 && (counter >=1 && counter <= 2)){
			counter ++;
			
		}if(key == '\r'){
			balikmenu:
			if(counter == 1){
				balikdialog:
				
	//TAMPIL MENU SOALNYA LOH KOK GAADA ANEH
				goto_xy(0,0);
				color(760);	
				printf("File     ");
			
				goto_xy(9,0);
				color(543);	
				printf("Edit     ");

				
				goto_xy(18,0);
				color(543);	
				printf("View    ");
				color(543);
				printf("                                                                                              ");
				color(543);	
				// PANUTUP TAMPIL GAN	
				int Set2[] = {543,543,543,543};
				char counter2 = 2;
				char key2;
	
				for(int a = 0 ;;){
				goto_xy(1,1);
				color(543);
				printf("%c",dd);
				color(Set2[0]);		
				printf("Save       ");
				color(543);
				printf("%c",dd);
			
				goto_xy(1,2);
				color(543);
				printf("%c",dd);
				color(Set2[1]);
				printf("Open File  ");
				color(543);
				printf("%c",dd);
				
				goto_xy(1,3);
				color(543);
				printf("%c",dd);
				color(Set2[2]);
				printf("Delete File");	
				color(543);
				printf("%c",dd);
				
				goto_xy(1,4);
				color(543);
				printf("%c",dd);
				color(Set2[3]);
				
				printf("Rename File");	
				color(543);
				printf("%c",dd);
				
				goto_xy(1,5);
				color(543);
				printf("%c",dd);
				color(Set2[4]);
				printf("Exit       ");						
				
				color(543);
				printf("%c",dd);
				color(543);
					goto_xy(1,6);
				printf("%c",ee);
				printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",hh);
				color(7);	
				key2 = _getch();
				
				if(key2 == 72&& (counter2 >=2 && counter2 <= 5)){		
					counter2 --;
					
				}if(key2 == 80 && (counter2 >=0 && counter2 <= 4)){			
					counter2 ++;
					
				}if(key2 == 75&& (counter2 >=2 && counter2 <= 3)){
					displayContent(list, position);
					counter --;
					goto balikmenu;
					
				}if(key2 == 77 && (counter2 >=1 && counter2 <= 5)){
					displayContent(list, position);
					counter ++;
					goto balikmenu;
				}if(key2 == 20){	//ctrl + T		
					goto baliksini; 
				
				//-----------------------------------------------------------------------Untuk nambahin function di edit
				}if(key2 == '\r'){
					if(counter2 ==1){
            			CreateFile(list);
						getch();
						system("cls");
						PullDownDisplay();
//					printf("asek");
					}
					if(counter2 ==2){
						goto_xy(20,10);
						OpenFile(list);
					}
					if(counter2 ==3){
						Delete();
						getch();
						system("cls");
						PullDownDisplay();
					}
					if(counter2 ==4){
						rename();
						getch();
						system("cls");
						PullDownDisplay();
					}

					if(counter2 ==5){
						//DIALOG BOX
						
							int Set4[] = {543,543};
							char counter4 = 1;
							char key4;
							for(int DialogCount = 0 ;;){									
									goto_xy(41,9);										
									color(543);
									printf("%c",bb);
										for(int garis = 0; garis < 31; garis++){						
										printf("%c",cc);		
										}
									printf("%c",ii);
									
									goto_xy(41,10);
									color(543);
									printf("%c                                ",dd);
									goto_xy(41,11);
									color(543);
									printf("%c  ",dd);
									goto_xy(41,12);
									color(543);
									printf("%c                                ",dd);
									goto_xy(41,13);
									color(543);
									printf("%c                                ",dd);
									goto_xy(41,14);
									color(543);
									printf("%c                                ",dd);
									goto_xy(41,15);
									color(543);
									printf("%c                                ",dd);	
									goto_xy(41,16);
									color(543);
									printf("%c",ee);
									goto_xy(42,16);
									color(543);
									for(int garis2 = 0; garis2 < 31; garis2++){						
										printf("%c",cc);		
										}										
									goto_xy(73,10);
									color(543);
									printf("%c",dd);
									goto_xy(73,11);
									color(543);
									printf("%c",dd);					
									goto_xy(73,12);
									color(543);
									printf("%c",dd);
									goto_xy(73,13);
									color(543);
									printf("%c",dd);
									goto_xy(73,14);
									color(543);
									printf("%c",dd);
									goto_xy(73,15);
									color(543);
									printf("%c",dd);
									goto_xy(73,16);
									color(543);			
									printf("%c",hh);
									
									
									//Text
									goto_xy(44,11);
									color(543);
									printf("Apakah Yakin ingin Keluar ?  ");
									goto_xy(43,15);		
									color(Set4[0]);
									printf("Yes");
									goto_xy(70,15);
									color(Set4[1]);					
									printf("No");
									color(7);
									
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
																		
											}
												Set4[0] =543;
												Set4[1] =543;													

												if(counter4 == 1){
														Set4[0] = 760;
												}
												if(counter4 == 2){
														Set4[1] = 760;
												}
							}//PANUTUP FOR DIALOG
						//PANUTUP DIALOG

					}if(counter2 ==3){

					printf("New Windows jalan");
					}
				}

				Set2[0] =543;
				Set2[1] =543;
				Set2[2] =543;
				Set2[3] =543;
				Set2[4] =543;

				if(counter2 == 1){
						Set2[0] = 760;					
				}
				if(counter2 == 2){
						Set2[1] = 760;						
				}
				if(counter2 == 3){
						Set2[2] = 760;						
				}if(counter2 == 4){
						Set2[3] = 760;
				}if(counter2 == 5){
						Set2[4] = 760;
				}
			
				} //penutup for
				
				
				
		}if(counter == 2){
//				cout<<"Menu 2 Is Open";	
				
	//TAMPIL MENU SOALNYA LOH KOK GAADA ANEH
				goto_xy(0,0);
				goto_xy(0,0);
				color(543);	
				printf("File     ");
			
				goto_xy(9,0);
				color(760);	
				printf("Edit     ");
			
				goto_xy(18,0);
				color(543);	
				printf("View    ");
				color(543);
				printf("                                                                                              ");
				color(7);	
// PANUTUP TAMPIL GAN	
				int Set3[] = {543,543};
				char counter3 = 1;
				char key3;
						
				for(int b ;;){
					
				goto_xy(8,1);
				color(543);
				printf("%c",dd);
				color(Set3[0]);		
				printf("Find And Replace ");
				color(543);
				printf("%c",dd);
			
				goto_xy(8,2);
				color(543);
				printf("%c",dd);
				color(Set3[1]);
				printf("Copy             ");
				color(543);
				printf("%c",dd);
				
				goto_xy(8,3);
				color(543);
				printf("%c",ee);
				printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",hh);
				color(7);
				key3 = _getch();
				
				if(key3 == 72&& (counter3 >=2 && counter3 <= 3)){			
					counter3 --;
					
				}if(key3 == 80 && (counter3 >=0 && counter3 <= 1)){			
					counter3 ++;
					
				}if(key3 == 75&& (counter3 >=1 && counter3 <= 3)){
					displayContent(list, position);				
					counter --;
					goto balikmenu;
					
				}if(key3 == 77 && (counter3 >=0 && counter3 <= 3)){
					displayContent(list, position);
					counter ++;
					goto balikmenu;
				}if(key3 == 20){	//ctrl + T		
					goto baliksini; 
				
				//-----------------------------------------------------------------untuk Menu Edit Masukin sini functionnya
				}if(key3 == '\r'){
					if(counter3 ==1){
					find(list);
					}
					if(counter3 ==2){
					printf("New Windows jalan");
					}
				
				}

				Set3[0] =543;
				Set3[1] =543;
	
		
				if(counter3 == 1){
						Set3[0] = 760;
				}
				if(counter3 == 2){
						Set3[1] = 760;
				}

				}//panutup for
				
		}if(counter == 3){
				
				
				goto_xy(0,0);
				goto_xy(0,0);
				color(543);	
				printf("File     ");
			
				goto_xy(9,0);
				color(543);	
				printf("Edit     ");
			
				goto_xy(18,0);
				color(760);	
				printf("View    ");
				color(543);
				printf("                                                                                              ");
				color(7);	
// PANUTUP TAMPIL GAN	
				int Set5[] = {543,543,543};
				char counter5 = 2;
				char key5;
						
				for(int g ;;){
					
				goto_xy(17,1);
				color(543);
				printf("%c",dd);
				color(Set5[0]);		
				printf("New Windows      ");
				color(543);
				printf("%c",dd);
			
				goto_xy(17,2);
				color(543);
				printf("%c",dd);
				color(Set5[1]);
				printf("Help             ");
				color(543);
				printf("%c",dd);
				
				goto_xy(17,3);
				color(543);
				printf("%c",dd);
				color(Set5[2]);
				printf("About            ");
				color(543);
				printf("%c",dd);
				
				goto_xy(17,4);
				color(543);
				printf("%c",ee);
				printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",cc);printf("%c",hh);
				color(7);
				key5 = _getch();
				
				if(key5 == 72&& (counter5 >=2 && counter5 <= 3)){			
					counter5 --;
					displayContent(list, position);
					
				}if(key5 == 80 && (counter5 >=1 && counter5 <= 2)){			
					counter5 ++;
					displayContent(list, position);
					
				}if(key5 == 75&& (counter5 >=1 && counter5 <= 3)){
					displayContent(list, position);				
					counter --;
					goto balikmenu;
					
				}if(key5 == 77 && (counter5 >=1 && counter5 <= 2)){
					displayContent(list, position);
					counter ++;
					goto balikmenu;
				}if(key5 == 20){	//ctrl + T	
					displayContent(list, position);	
					goto baliksini; 
				
				//-----------------------------------------------------------------untuk Menu Edit Masukin sini functionnya
				}if(key5 == '\r'){

			switch(counter5){
				case 1:
					system("start Project4.exe");
					break;
				case 2:
					help();
					getch();
					system("cls");
					PullDownDisplay();
					break;
				case 3:
					TextBox(11,57 );
					about();
					getch();
					system("cls");
					PullDownDisplay();
					break;
				}
			}

				Set5[0] =543;
				Set5[1] =543;
				Set5[2] =543;
		
				if(counter5 == 1){
						Set5[0] = 760;
				}
				if(counter5 == 2){
						Set5[1] = 760;
				}
				if(counter5 == 3){
						Set5[2] = 760;
				}

				}//panutup for
				
				
				
				
		}else{
				displayContent(list, position);
				goto baliksini;
		}
		}
		
		Set[0] =543;
		Set[1] =543;
		Set[2] =543;
		Set[3] =543;
		

		if(counter == 1){
				Set[0] = 760;
		}
		if(counter == 2){
				Set[1] = 760;
		}
		if(counter == 3){
				Set[2] = 760;
		}
		if(counter == 4){
				Set[2] = 760;
		}
	 }
}

int PullDownDisplay(){
	int count_tahan;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
    {
        return GetLastError();
    }

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))
    {
        return GetLastError();
    }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode))
    {
        return GetLastError();
    }
//    goto_xy(0,21);
//    color(543);
//    printf("\nBaris : 1       Kolom : 1                                                                                               "); 
//	color(7);

	if(count_tahan == 0){
	goto_xy(0,21);
	color(543);
    printf("\nKolom : 0   "); 
    color(543);
	printf("Baris : 0   ");
	color(543);
	printf("Jumlah Karakter : 0                                                                             ");
	color(7);
	count_tahan = count_tahan+1;
}
	count_tahan = count_tahan+1;


	goto_xy(0,0);
	color(543);	
	printf("File     ");

	goto_xy(9,0);
	color(543);	
	printf("Edit     ");

	goto_xy(18,0);
	color(543);	
	printf("View    ");
	color(543);
	printf("                                                                                              \n");
	color(7);

	

}

void TextBox(int c, int d){
	int x =30, a=x;
	int y =6, b=y;
	
	goto_xy(x,y);
	color(543);
	for(int i =0;i<c;i++){		
		goto_xy(x,y+=1);
		color(543);
		for(int j=0; j<d;j++){
			if(i==0){
				if(j==0){					
					printf("%c",bb);
				}
				else if(j==(d-1)){
					printf("%c",ii);
				}
				else{
					printf("%c",cc);
				}
			}
			else if(i == (c-1)){
				if(j==0){
					printf("%c",ee);
				}
				else if(j==(d-1)){
					printf("%c",hh);
				}
				else{
					printf("%c",cc);
				}
			}
			else{
				if(j==0){
					printf("%c",dd);
				}
				else if(j==(d-1)){
					printf("%c",dd);
				}
				else{
					printf(" ");
				}
			}
		}
		printf("\n");
	}
	goto_xy(a+3,b+3);
	color(7);
}

void TextBox2(int c, int d){
	int x =24, a=x;
	int y =1, b=y;
	
	goto_xy(x,y);
	color(543);
	for(int i =0;i<c;i++){		
		goto_xy(x,y+=1);
		color(543);
		for(int j=0; j<d;j++){
			if(i==0){
				if(j==0){					
					printf("%c",bb);
				}
				else if(j==(d-1)){
					printf("%c",ii);
				}
				else{
					printf("%c",cc);
				}
			}
			else if(i == (c-1)){
				if(j==0){
					printf("%c",ee);
				}
				else if(j==(d-1)){
					printf("%c",hh);
				}
				else{
					printf("%c",cc);
				}
			}
			else{
				if(j==0){
					printf("%c",dd);
				}
				else if(j==(d-1)){
					printf("%c",dd);
				}
				else{
					printf(" ");
				}
			}
		}
		printf("\n");
	}
	goto_xy(a+3,b+3);
	color(7);
}

void help(){
	
	system("cls");
	TextBox2(17,80);
	goto_xy(48,2);
	color(543);
	printf("PANDUAN PENGGUNAAN APLIKASI");
	goto_xy(26, 3);
	printf("a. Penjelasan Mengenai Shortcut");
	goto_xy(27,4);
	printf("1 Untuk masuk dan keluar dari Control Menu menggunakan CTRL + K");
	goto_xy(27,5);
	printf("2 Untuk keluar dari Menu Pulldown menggunakan CTRL + T");
	goto_xy(26,7);
	printf("b. Penjelasan Mengenai Menu");
	goto_xy(27,8);
	printf("1. Save = menyimpan ketikan ke dalam file");
	goto_xy(27,9);
	printf("2. Open File = membuka file yang diinginkan dan mengupdate");
	goto_xy(27,10);
	printf("3. Delete File = Digunakan untuk menghapus file yang diinginkan");
	goto_xy(27,11);
	printf("4. Exit = Digunakan untuk keluar dari program");
	goto_xy(26,12);
	printf("c Edit Menu");
	goto_xy(27,13);
	printf("1. Find and Replace = Digunakan untuk mengetahui keberadaan kata yang dicari");
	goto_xy(27,14);
	printf("2. Undo = Digunakan untuk melakukan Undo pada isi file");
	goto_xy(26,15);
	printf("d View");
	goto_xy(27,16);
	printf("1. New Windows = Digunakan untuk membuka jendela baru");
	goto_xy(27,17);
	printf("2. About = Tentang aplikasi");
	color(7);
}

void writeflush(char const *str, size_t len){
  fwrite(str, 1, len, stdout);
  fflush(stdout);
}
void about (){

	goto_xy(31,8);
	color(543);
	printf("THANKS TO :");
	goto_xy(31,10);
	color(543);
	printf(" Benny Yoga Suhardi    211511035");
	goto_xy(31,11);
	color(543);
	printf(" Muhamad Diaz Adhari   211511044");
	goto_xy(31,12);
	color(543);
	printf(" Muhamad Nauval Ardana 211511046");
	goto_xy(31,13);
	color(543);
	printf(" Nazwa Fitriyani Zahra 211511051");
	goto_xy(31,14);
	color(543);
	printf(" Tubagus Aji Prasetia  211511061");
	goto_xy(31,16);
	color(543);
	static const int second = 1000000;
  	static char const *titletext ="N  O  D  E  J  S  V  2.2 ";
   	writeflush(" ", 1);
   	color(7);
  
  	

//  clsscreen();
 	usleep(second / 2);
  	 for (int i = 0; i < 23; ++i)
{

    writeflush(titletext + i, 1);
    usleep(second / 30);	}               
  	usleep(second / 2);
	
}


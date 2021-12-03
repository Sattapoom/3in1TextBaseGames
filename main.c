#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
#include<math.h>

// =========================== MAIN MENU ====================================

COORD coord= {0,0}; 
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


typedef struct
{
    int line,line2,name;
	int sum,percen,bus;
	
    
} Data;

// ========== Golbal Variable =================
void DisplayMainmenu();
void DisplayEndgamemenu();
void Curser();
void Endgamecurser(int);
void highlight(int);
void window(int a,int b,int c,int d);

void Game1();
void Game2();
void Game3();

int currentgame;
int menunum;
// EOC ====== Golbal Variable ====== EOC ======

int main()
{
    DisplayMainmenu();
    return 0;
}


void DisplayMainmenu()
{
	int i;
    const char *menu[]= {"   Game 1 ","   Game 2 ","   Game 3 ","   Exit"};
    system("cls");
	window(25,50,20,30);
    gotoxy(33,18);
    printf("Main Menu");
   for (i=0; i<=3; i++)
  {
        gotoxy(30,23+i);
       printf("%s\n\n\n",menu[i]);
  }
    menunum = 4;
    Curser();
}


void DisplayEndgamemenu()
{
    int i;
    const char *menu[]= {"   Play Again ","   Main Menu "};
    system("cls");
	window(25,50,20,28);
    gotoxy(33,18);
    printf("End Game");
   for (i=0; i<=1; i++)
  {
        gotoxy(30,23+i);
       printf("%s\n\n\n",menu[i]);
  }
    menunum = 2;
    Curser();
}


void Curser()
{
    int count=1;
    char ch='0';
    gotoxy(30,23);
    while(1)
    {
        switch(ch)
        {
        case 80:
            count++;
            if (count==menunum+1) count=1;
            break;
        case 72:
            count--;
            if(count==0) count=menunum;
            break;
        }
        highlight(count);
        ch=getch();
        if(ch=='\r')
        {
            system("cls");
           if(menunum==4)
            {
                if (count==1) Game1();
                else if(count==2) Game2();
                else if(count==3) Game3();
                else   exit(0);
            }
            if(menunum==2)
            {   
                if (count==1)
                {
                    if (currentgame == 1) Game1();
                    if (currentgame == 2) Game2();
                    if (currentgame == 3) Game3();
                }
                else if(count==2) DisplayMainmenu();
                else   exit(0);
            }
            break;
        }
    }
}



void highlight(int count)
{
    if(menunum == 4)
    {
        gotoxy (30,23);
        printf("   Game 1 ");
        gotoxy (30,24);
        printf("   Game 2 ");
        gotoxy (30,25);
        printf("   Game 3 ");
        gotoxy (30,26);
        printf("   Exit        ");
        switch(count)
        {
        case 1:
            gotoxy (30,23);
            printf(" - Game 1 ");
            break;
        case 2:
            gotoxy (30,24);
            printf(" - Game 2 ");
            break;
        case 3:
            gotoxy (30,25);
            printf(" - Game 3 ");
            break;
        case 4:
            gotoxy (30,26);
            printf(" - Exit ");
            break;
        }
    }
    else if(menunum == 2)
    {
        gotoxy (30,23);
        printf("   Play Again ");
        gotoxy (30,24);
        printf("   Main Menu ");
    
        switch(count)
        {
        case 1:
            gotoxy (30,23);
            printf(" - Play Again ");
            break;
        case 2:
            gotoxy (30,24);
            printf(" - Main Menu ");
            break;
        }
    }
}


void window(int a,int b,int c,int d)
{
    int i;
    system("cls");
    gotoxy(20,10);
    for (i=1; i<=11; i++)
        printf("=");
    printf(" Play Games ");
    for (i=1; i<=11; i++)
        printf("=");
    printf("\n\n");
    gotoxy(21,11);
    printf("\t    Choose Your Games");
    for (i=a; i<=b; i++)
    {
        gotoxy(i,17);
        printf("=");
        gotoxy(i,19);
        printf("=");
        gotoxy(i,c);
        printf(".");
        gotoxy(i,d);
        printf(".");
    }
    gotoxy(a,17);
    printf("=");
    gotoxy(a,19);
    printf("=");
    gotoxy(b,17);
    printf("=");
    gotoxy(b,19);
    printf("=");
    for(i=c; i<=d; i++)
    {
        gotoxy(a,i);
        printf(".");
        gotoxy(b,i);
        printf(".");
    }
    gotoxy(a,c);
    printf(".");
    gotoxy(a,d);
    printf(".");
    gotoxy(b,c);
    printf(".");
    gotoxy(b,d);
    printf(".");
}
// ===========EOC============ MAIN MENU ===============EOC==================

void Game1()
{
    currentgame =1;
	printf("Playing 1'st game.\n\n\n");
    
    if(getch() == '\r')
    {
        DisplayEndgamemenu();
    }
}


void Game2()
{
    currentgame = 2;
	printf("Playing 2'nd game.\n\n\n");
    if(getch() == '\r')
    {
        DisplayEndgamemenu();
    }
}


void Game3()
{
    currentgame = 3;
	printf("Playing 3'rd game.\n\n\n");
    if(getch() == '\r')
    {
        DisplayEndgamemenu();
    }
}
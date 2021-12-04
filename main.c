#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
#include<math.h>

// =========================== MAIN MENU ====================================

    // ====================== Golbal Variable =======================

void DisplayMenu();
void Highlight(int,int);

void Game1();
void Game2();
void Game3();
void stopgame(int,char*);

COORD pos= {0,0}; 
int currentwindow;
int lastgame;

    // EOC ============ Golbal Variable ============ EOC ============

int main()
{
    currentwindow = 0;
    DisplayMenu();
    return 0;
}

void changepos(int x,int y)
{
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void DisplayMenu()
{
    system("cls");
    int totalchoice;
    char *menu[4];
    if(currentwindow == 0)
    {
        menu[0]= "  Game 1 ";
        menu[1]= "  Game 2 ";
        menu[2]= "  Game 3 ";
        menu[3]= "  Exit";
        totalchoice=4;
        changepos(0,1);
        printf("*********** Main Menu ***********");
    }
    else if(currentwindow == -1)
    {
        menu[0]= "   Play Again ";
        menu[1]= "   Main Menu ";
        totalchoice=2;
        changepos(0,1);
        printf("*********** Game Over ***********");
    }
    for (int i=0; i<totalchoice; i++)
    {
        changepos(5,3+i);
        printf("%s\n\n\n",menu[i]);
    }
    
    
    int selectedchioce=1;
    char ch='0';
    changepos(5,3);
    while(1)
    {
        switch(ch)
        {
        case 80:
            selectedchioce++;
            if (selectedchioce==totalchoice+1) selectedchioce=1;
            break;
        case 72:
            selectedchioce--;
            if(selectedchioce==0) selectedchioce=totalchoice;
            break;
        }
        Highlight(selectedchioce, totalchoice);
        ch=getch();
        if(ch=='\r')
        {
            system("cls");
           if(currentwindow == 0)
            {
                if (selectedchioce==1) Game1();
                else if(selectedchioce==2) Game2();
                else if(selectedchioce==3) Game3();
                else   exit(0);
            }
            if(currentwindow == -1)
            {   
                if (selectedchioce==1)
                {
                    if (lastgame == 1) Game1();
                    else if (lastgame == 2) Game2();
                    else if (lastgame == 3) Game3();
                }
                else if(selectedchioce == 2) 
                {
                    currentwindow = 0;
                    DisplayMenu();
                }
                else   exit(0);
            }
            break;
        }
    }
}


void Highlight(int count, int totalchoice)
{
    if(totalchoice == 4)
    {
        changepos (5,3);
        printf("   Game 1 ");
        changepos (5,4);
        printf("   Game 2 ");
        changepos (5,5);
        printf("   Game 3 ");
        changepos (5,6);
        printf("   Exit        ");
        switch(count)
        {
        case 1:
            changepos (5,3);
            printf("- Game 1 ");
            break;
        case 2:
            changepos (5,4);
            printf("- Game 2 ");
            break;
        case 3:
            changepos (5,5);
            printf("- Game 3 ");
            break;
        case 4:
            changepos (5,6);
            printf("- Exit ");
            break;
        }
    }
    else if(totalchoice == 2)
    {
        changepos (5,3);
        printf("   Play Again ");
        changepos (5,4);
        printf("   Main Menu ");
    
        switch(count)
        {
        case 1:
            changepos (5,3);
            printf("- Play Again ");
            break;
        case 2:
            changepos (5,4);
            printf("- Main Menu ");
            break;
        }
    }
}

// ===========EOC============ MAIN MENU ===============EOC==================



// ============================= GAME ======================================
void stopgame(int lgame,char* status)
{   
    changepos(0,0);
    printf("- - - YOU %s - - -",status);
    lastgame = lgame;
    if(getch() == '\r')
    {
        currentwindow = -1;
        DisplayMenu();
    }
}


void Game1()
{
    currentwindow = 1;

    // Add game 1 here vvvvv
    changepos(0,1);
	printf("Playing 1'st game.\n\n\n");

    // Add game 1 here ^^^^^

    stopgame(1,"WIN");
}


void Game2()
{
    currentwindow = 2;

    // Add game 2 here vvvvv
    changepos(0,1);
	printf("Playing 2'nd game.\n\n\n");
    
    // Add game 2 here ^^^^^

    stopgame(2,"WIN");
}


void Game3()
{
    currentwindow = 3;

    // Add game 3 here vvvvv
    changepos(0,1);
	printf("Playing 3'rd game.\n\n\n");
    
    // Add game 3 here ^^^^^

    stopgame(3,"WIN");
}
// ========= EOC =============== GAME ============== EOC ===================
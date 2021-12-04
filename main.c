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

void Game1(int);
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

void chgcursorpos(int x,int y)
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
        chgcursorpos(0,1);
        printf("*********** Main Menu ***********");
    }
    else if(currentwindow == -1)
    {
        menu[0]= "   Play Again ";
        menu[1]= "   Main Menu ";
        totalchoice=2;
        chgcursorpos(0,1);
        printf("*********** Game Over ***********");
    }
    for (int i=0; i<totalchoice; i++)
    {
        chgcursorpos(5,3+i);
        printf("%s\n\n\n",menu[i]);
    }
    
    
    int selectedchioce=1;
    char ch='0';
    chgcursorpos(5,3);
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
                if (selectedchioce==1) Game1(0);
                else if(selectedchioce==2) Game2();
                else if(selectedchioce==3) Game3();
                else   exit(0);
            }
            if(currentwindow == -1)
            {   
                if (selectedchioce==1)
                {
                    if (lastgame == 1) Game1(0);
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
        chgcursorpos (5,3);
        printf("   Game 1 ");
        chgcursorpos (5,4);
        printf("   Game 2 ");
        chgcursorpos (5,5);
        printf("   Game 3 ");
        chgcursorpos (5,6);
        printf("   Exit        ");
        switch(count)
        {
        case 1:
            chgcursorpos (5,3);
            printf("- Game 1 ");
            break;
        case 2:
            chgcursorpos (5,4);
            printf("- Game 2 ");
            break;
        case 3:
            chgcursorpos (5,5);
            printf("- Game 3 ");
            break;
        case 4:
            chgcursorpos (5,6);
            printf("- Exit ");
            break;
        }
    }
    else if(totalchoice == 2)
    {
        chgcursorpos (5,3);
        printf("   Play Again ");
        chgcursorpos (5,4);
        printf("   Main Menu ");
    
        switch(count)
        {
        case 1:
            chgcursorpos (5,3);
            printf("- Play Again ");
            break;
        case 2:
            chgcursorpos (5,4);
            printf("- Main Menu ");
            break;
        }
    }
}

// ===========EOC============ MAIN MENU ===============EOC==================



// ============================= GAME ======================================
void stopgame(int lgame,char* status)
{   
    chgcursorpos(0,0);
    printf("- - - YOU %s - - -",status);
    lastgame = lgame;
    if(getch() == '\r')
    {
        currentwindow = -1;
        DisplayMenu();
    }
}


void Game1(int wincount)
{
    currentwindow = 1;

    // Add game 1 here vvvvv
    char* choice[] = {
        "Fried chicken with Sticky rice",
        "Icecream",
        "Apple",
        "Grilled Pork with Sticky Rice",
        "Corn soup",
        "Orange juice"
    };
    int price[] = {15,5,10,20,10,15};
    char* choosenfood[] = {"","",""};
    int checklist[] = {0,0,0};
    int choosencount = 0;
    int selecting = 0;
    char ch = '0';
    chgcursorpos(0,1);
	printf("Choose 3 of these product to find all conditions that will cause the total price to not exceed than 35 baht.");
    chgcursorpos(1,10);
    printf("You Chosen : None");
    chgcursorpos(1,11);
    printf("Found condition : %d",wincount);
    while(1)
    {
        switch(ch)
        {
        case 80:
            selecting++;
            if (selecting > 5) selecting=0;
            break;
        case 72:
            selecting--;
            if(selecting < 0) selecting=5;
            break;
        }
        
        for(int i=0;i<6;i++){
            chgcursorpos(5,3+i);
            printf("   %s",choice[i]);
        }
        for(int i=0;i<6;i++){ 
            if(price[i] != 0)
            {
                chgcursorpos(43,3+i);
                printf("%d",price[i]);
                chgcursorpos(46,3+i);
                printf("Bath.");
            }
        }

        chgcursorpos(5,3+selecting);
        printf("- %s ",choice[selecting]);

        ch=getch();
        if(ch=='\r')
        {
            if(choice[selecting] != "")
            {
                choosenfood[choosencount] = choice[selecting];
                checklist[choosencount] = selecting;
                choosencount++;
                choice[selecting] = "";
                printf("%c[2K",27);
                chgcursorpos(1,10);
                printf("%c[2KYou Chosen : ",27);
                for(int i=0 ; i<3;i++){
                    if(choosenfood[i] != "") printf("%s    ",choosenfood[i]);
                }
            }
        }
        if(choosencount >= 3) break;
    }
    
    const int wincondition[][] = {
        {0,1,2},
        {0,1,5},
        {0,4,5},
        {1,2,3}
    };
    
    // Add game 1 here ^^^^^

    //stopgame(1,"WIN");
}


void Game2()
{
    currentwindow = 2;

    // Add game 2 here vvvvv
    chgcursorpos(0,1);
	printf("Playing 2'nd game.\n\n\n");
    
    // Add game 2 here ^^^^^

    stopgame(2,"WIN");
}


void Game3()
{
    currentwindow = 3;

    // Add game 3 here vvvvv
    chgcursorpos(0,1);
	printf("Playing 3'rd game.\n\n\n");
    
    // Add game 3 here ^^^^^

    stopgame(3,"WIN");
}
// ========= EOC =============== GAME ============== EOC ===================
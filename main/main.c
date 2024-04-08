#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <process.h>
#include <stdbool.h>
#include <math.h>

#define MIN(i, j) (((i) < (j)) ? (i) : (j))
#define MAX(i, j) (((i) > (j)) ? (i) : (j))
#define WINPOINTSTICTACTOE 100
#define MAX_SIZE 20
#define MAX_MINES 50
#define spade 06
#define club 05
#define diamond 04
#define heart 03
#define RESULTS "Blackjack.txt"
void logIntoGame();      //Two player log-in
void playGame();     //Starts game with two players
void printBlackJackTitle(); // Prints BlackJack title -- 8lines
void printRectArea(); // prints rectangle - player area
void updateScores(); // Prints score values
void displayRules(); // Displays rules for the game
int player1Score;
int player2Score;
int player1Cash;
int player2Cash;
int user1Wins = 0;
int user2Wins = 0;
int firstPlay = 1;
int reverse = 0;


char padding[300];


typedef struct user{
    char email[50];
    char userName[30];
    char password[16];
    int score;

}user;

typedef struct
{
    char name[30];
    int scores[4];
} Player;

user activeUser;

void leaderboard(); // Main leaderboard

void getCash(char user1[30],char user2[30])
{
    FILE *file = fopen("blackjack.txt","r");

    char user[30];
    char score[10];
    char cash[10];
    while(fscanf(file,"%s %s %s",user,cash,score) == 3){
            if(!strcmp(user,user1)){
                player1Cash = atoi(cash);

            }
            if(!strcmp(user,user2)){
                player2Cash = atoi(cash);

            }
          }
    fclose(file);
}
void copyFile(file1,file2)
{

    FILE *fileptr2 = fopen(file2,"r");

    if(!fileptr2) return;

    FILE *fileptr1 = fopen(file1,"w");

    char user[30],pass[30],score[10];

    while(fscanf(fileptr2,"%s %s %s",user,pass,score) == 3){
        fprintf(fileptr1,"%s ",user);
        fprintf(fileptr1, "%s ", pass);
        fprintf(fileptr1, "%s", score);
        fprintf(fileptr1, "\n");
    }
    fclose(fileptr1);
    fclose(fileptr2);
}
void addCashAndScore(char user1[30],char user2[30])
{

        FILE* file = fopen("blackjack.txt", "r");
        FILE* temp_file = fopen("temp.txt", "w");

        if(!file) {
            gotoxy(108,56);
            printf("DALJE NECES MOCI");
            getch();
        }

        char username[100];
        char cash[100];
        char score[100];



        while(fscanf(file,"%s %s %s",username,cash,score) == 3)
        {

            if (!strcmp(user1, username))
            {

                fprintf(temp_file, "%s ", user1);
                fprintf(temp_file, "%d ",player1Cash);
                if(cash < 0){
                    fprintf(temp_file,"%d ",0);
                }
                else{
                    fprintf(temp_file, "%d ", player1Cash * 2);
                }
                fprintf(temp_file, "\n");
            }
            else if (!strcmp(user2, username))
            {
                fprintf(temp_file, "%s ", user2);
                fprintf(temp_file, "%d ",player2Cash);
                if(cash < 0){
                    fprintf(temp_file,"%d ",0);
                }
                else{
                    fprintf(temp_file, "%d ", player2Cash * 2);
                }
                fprintf(temp_file, "\n");
            }
            else
            {
                fprintf(temp_file, "%s ", username);
                fprintf(temp_file, "%s ", cash);
                fprintf(temp_file, "%s ", score);

                fprintf(temp_file, "\n");
            }
        }
        fclose(file);
        fclose(temp_file);

        remove("blackjack.txt");
        rename("temp.txt", "blackjack.txt");


    }
void printBlackJackTitle()
{
    printf("\n                                                                 %c%c%c%c%c     %c%c            %c%c         %c%c%c%c%c    %c    %c                   %c%c%c%c%c%c%c%c      %c%c         %c%c%c%c%c    %c    %c                ", club, club, club, club, club, spade, spade, diamond, diamond, heart, heart, heart, heart, heart, club, club, diamond, diamond, diamond, diamond, diamond, diamond, diamond, diamond, heart, heart, club, club, club, club, club, spade, spade);
    printf("\n                                                                 %c    %c    %c%c           %c  %c       %c     %c   %c   %c                       %c%c        %c  %c       %c     %c   %c   %c              ", club, club, spade, spade, diamond, diamond, heart, heart, club, club, diamond, diamond, heart, heart, club, club, spade, spade);
    printf("\n                                                                 %c    %c    %c%c          %c    %c     %c          %c  %c                        %c%c       %c    %c     %c          %c  %c               ", club, club, spade, spade, diamond, diamond, heart, club, club, diamond, diamond, heart, heart, club, spade, spade);
    printf("\n                                                                 %c%c%c%c%c     %c%c          %c %c%c %c     %c          %c %c                         %c%c       %c %c%c %c     %c          %c %c              ", club, club, club, club, club, spade, spade, diamond, diamond, diamond, diamond, heart, club, club, diamond, diamond, heart, heart, heart, heart, club, spade, spade);
    printf("\n                                                                 %c    %c    %c%c         %c %c%c%c%c %c    %c          %c%c %c                        %c%c      %c %c%c%c%c %c    %c          %c%c %c              ", club, club, spade, spade, diamond, diamond, diamond, diamond, diamond, diamond, heart, club, club, club, diamond, diamond, heart, heart, heart, heart, heart, heart, club, spade, spade, spade);
    printf("\n                                                                 %c     %c   %c%c         %c      %c    %c          %c   %c                       %c%c      %c      %c    %c          %c   %c                ", club, club, spade, spade, diamond, diamond, heart, club, club, diamond, diamond, heart, heart, club, spade, spade);
    printf("\n                                                                 %c     %c   %c%c        %c        %c    %c     %c   %c    %c                   %c  %c%c     %c        %c    %c     %c   %c    %c           ", club, club, spade, spade, diamond, diamond, heart, heart, club, club, diamond, diamond, diamond, heart, heart, club, spade, spade);
    printf("\n                                                                 %c%c%c%c%c%c    %c%c%c%c%c%c%c   %c        %c     %c%c%c%c%c    %c     %c                  %c%c%c      %c        %c     %c%c%c%c%c    %c     %c             ", club, club, club, club, club, club, spade, spade, spade, spade, spade, spade, spade, diamond, diamond, heart, heart, heart, heart, heart, club, club, diamond, diamond, diamond, heart, heart, club, club, club, club, club, spade, spade);
    printf("\n");
}
void printRectArea()
{
    gotoxy(12,18);

    printf("_________________________________________________________________________________________________________________________________________________________________________________________________________________________\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |________________________________________________________________________________________________________________________________________________________________________________________________________________________|\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |                                                                                                                                                                                                                        |\n");
    printf("            |________________________________________________________________________________________________________________________________________________________________________________________________________________________|\n");
}
void updateScores(int score1, int score2)
{
    gotoxy(215,20);
    printf("SCORE: %d",score1);
    gotoxy(215,36);
    printf("SCORE: %d",score2);
}
void displayRules()
{
    system("cls");
    printf("\n\n\n\n\n\n");
    printBlackJackTitle();
    printf("\n\n\n\n\n\n\n");
    printf("                                                                            __________________________________________________________________________________\n");
    printf("                                                                            |                                                                                |\n");
    printf("                                                                            |                                                                                |\n");
    printf("                                                                            |              88\"\"Yb     88   88     88         888888     .dP\"Y8               |\n");
    printf("                                                                            |              88__dP     88   88     88         88__       `Ybo.\"               |\n");
    printf("                                                                            |              88\"Yb      Y8   8P     88  .o     88\"\"       o.`Y8b               |\n");
    printf("                                                                            |              88  Yb     `YbodP'     88ood8     888888     8bodP'               |\n");
    printf("                                                                            |                                                                                |\n");
    printf("                                                                            |                                                                                |\n");
    printf("                                                                            |                                                                                |\n");
    printf("                                                                            |                                                                                |\n");
    printf("                                                                            |                                                                                |\n");
    printf("                                                                            |                                                                                |\n");
    printf("                                                                            |                                                                                |\n");
    printf("                                                                            |                                                                                |\n");
    printf("                                                                            |                                                                                |\n");
    printf("                                                                            |                                                                                |\n");
    printf("                                                                            |                                                                                |\n");
    printf("                                                                            |                                                                                |\n");
    printf("                                                                            |                                                                                |\n");
    printf("                                                                            |                                                                                |\n");
    printf("                                                                            |                                                                                |\n");
    printf("                                                                            |                                                                                |\n");
    printf("                                                                            |________________________________________________________________________________|\n");

    gotoxy(81,31);
    printf("1.Main goal of the game is to reach 21 points - or have higher score");
    gotoxy(81,32);
    printf(" than other player");
    gotoxy(81,34);
    printf("2.After first two deals player gets to choose two options:");
    gotoxy(88,36);
    printf("* HIT - take another card");
    gotoxy(88,37);
    printf("* STAY - freeze score (stop playing)");
    gotoxy(81,39);
    printf("3.If you get over 21 points, you lose!");
    gotoxy(81,41);
    printf("4.You get the bet if you win 3 rounds");
    gotoxy(111,43);
    printf("GOOD LUCK!");
    gotoxy(116,45);
    getch();
    return printMainInterfaceBJ();
}
void BlackJackLeaderboard()
{
    FILE *file = fopen("blackjack.txt","r");
        int numPlayers = 0;

        Player players[100];
        char user[30];
        char skor1[30];
        char skor2[30];

        while(fscanf(file,"%s %s %s", user, skor1, skor2) == 3)
        {

            strcpy(players[numPlayers].name, user);
            players[numPlayers].scores[0] = atoi(skor1);
            players[numPlayers].scores[1] = atoi(skor2);
            numPlayers++;
        }

        fclose(file);

        for(int i=0;i<numPlayers-1;i++)
        {
            for(int j=i;j<numPlayers;j++)
            {
                if(players[i].scores[1] < players[j].scores[1])
                {
                    players[numPlayers] = players[i];
                    players[i] = players[j];
                    players[j] = players[numPlayers];
                }
            }
        }

        system("cls");
        printf("\n");
        printf("                                              88          88888888888        db        88888888ba,   88888888888 88888888ba  88888888ba    ,ad8888ba,        db        88888888ba  88888888ba,\n");
        printf("                                              88          88                d88b       88      `\"8b  88          88      \"8b 88      \"8b  d8\"'    `\"8b      d88b       88      \"8b 88      `\"8b\n");
        printf("                                              88          88               d8'`8b      88        `8b 88          88      ,8P 88      ,8P d8'        `8b    d8'`8b      88      ,8P 88        `8b\n");
        printf("                                              88          88aaaaa         d8'  `8b     88         88 88aaaaa     88aaaaaa8P' 88aaaaaa8P' 88          88   d8'  `8b     88aaaaaa8P' 88         88\n");
        printf("                                              88          88\"\"\"\"\"        d8YaaaaY8b    88         88 88\"\"\"\"\"     88\"\"\"\"88'   88\"\"\"\"\"\"8b, 88          88  d8YaaaaY8b    88\"\"\"\"88'   88         88\n");
        printf("                                              88          88            d8\"\"\"\"\"\"\"\"8b   88         8P 88          88    `8b   88      `8b Y8,        ,8P d8\"\"\"\"\"\"\"\"8b   88    `8b   88         8P\n");
        printf("                                              88          88           d8'        `8b  88      .a8P  88          88     `8b  88      a8P  Y8a.    .a8P d8'        `8b  88     `8b  88      .a8P\n");
        printf("                                              88888888888 88888888888 d8'          `8b 88888888Y\"'   88888888888 88      `8b 88888888P\"    `\"Y8888Y\"' d8'          `8b 88      `8b 88888888Y\"'\n");
        printf("\n\n");
        printf("_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|                                USERNAME                                      |                                     CASH                                     |                                    SCORE                                    |");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|______________________________________________________________________________|______________________________________________________________________________|_____________________________________________________________________________|");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|                 1.                                                           |                                                                              |                                                                             |");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|______________________________________________________________________________|______________________________________________________________________________|_____________________________________________________________________________|");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|                 2.                                                           |                                                                              |                                                                             |");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|______________________________________________________________________________|______________________________________________________________________________|_____________________________________________________________________________|");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|                 3.                                                           |                                                                              |                                                                             |");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|______________________________________________________________________________|______________________________________________________________________________|_____________________________________________________________________________|");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|                 4.                                                           |                                                                              |                                                                             |");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|______________________________________________________________________________|______________________________________________________________________________|_____________________________________________________________________________|");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|                 5.                                                           |                                                                              |                                                                             |");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|______________________________________________________________________________|______________________________________________________________________________|_____________________________________________________________________________|");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|                 6.                                                           |                                                                              |                                                                             |");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|______________________________________________________________________________|______________________________________________________________________________|_____________________________________________________________________________|");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|                 7.                                                           |                                                                              |                                                                             |");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|______________________________________________________________________________|______________________________________________________________________________|_____________________________________________________________________________|");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|                 8.                                                           |                                                                              |                                                                             |");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|______________________________________________________________________________|______________________________________________________________________________|_____________________________________________________________________________|");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|                 9.                                                           |                                                                              |                                                                             |");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|______________________________________________________________________________|______________________________________________________________________________|_____________________________________________________________________________|");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|                10.                                                           |                                                                              |                                                                             |");
        printf("|                                                                              |                                                                              |                                                                             |");
        printf("|______________________________________________________________________________|______________________________________________________________________________|_____________________________________________________________________________|");


        int temp = 19;
        for(int i=0;i<10;i++)
        {
            gotoxy(20,temp);
            printf("%s",players[i].name);
            temp+=5;
        }
        temp = 19;
        for(int i=0;i<10;i++)
        {
            gotoxy(117,temp);
            printf("%d", players[i].scores[0]);
            temp+=5;
        }
        temp = 19;
        for(int i=0;i<10;i++)
        {
            gotoxy(196,temp);
            printf("%d", players[i].scores[1]);
            temp+=5;
        }


        getch();
}
void printMainInterfaceBJ()
{
    system("cls");
    printf("\n");
    printf("\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n");
    printf("\n                                                                                                           222                111                            ");
    printf("\n                                                                                                         222 222            11111                              ");
    printf("\n                                                                                                        222   222          11 111                            ");
    printf("\n                                                                                                             222              111                               ");
    printf("\n                                                                                                            222               111                           ");
    printf("\n                                                                                             ");
    printf("\n                                                                                             %c%c%c%c%c     %c%c            %c%c         %c%c%c%c%c    %c    %c                ", club, club, club, club, club, spade, spade, diamond, diamond, heart, heart, heart, heart, heart, club, club);
    printf("\n                                                                                             %c    %c    %c%c           %c  %c       %c     %c   %c   %c              ", club, club, spade, spade, diamond, diamond, heart, heart, club, club);
    printf("\n                                                                                             %c    %c    %c%c          %c    %c     %c          %c  %c               ", club, club, spade, spade, diamond, diamond, heart, club, club);
    printf("\n                                                                                             %c%c%c%c%c     %c%c          %c %c%c %c     %c          %c %c              ", club, club, club, club, club, spade, spade, diamond, diamond, diamond, diamond, heart, club, club);
    printf("\n                                                                                             %c    %c    %c%c         %c %c%c%c%c %c    %c          %c%c %c             ", club, club, spade, spade, diamond, diamond, diamond, diamond, diamond, diamond, heart, club, club, club);
    printf("\n                                                                                             %c     %c   %c%c         %c      %c    %c          %c   %c               ", club, club, spade, spade, diamond, diamond, heart, club, club);
    printf("\n                                                                                             %c     %c   %c%c        %c        %c    %c     %c   %c    %c             ", club, club, spade, spade, diamond, diamond, heart, heart, club, club);
    printf("\n                                                                                             %c%c%c%c%c%c    %c%c%c%c%c%c%c   %c        %c     %c%c%c%c%c    %c     %c            ", club, club, club, club, club, club, spade, spade, spade, spade, spade, spade, spade, diamond, diamond, heart, heart, heart, heart, heart, club, club);
    printf("\n");
    printf("\n                                                                                                                     21                                   ");

    printf("\n                                                                                                  %c%c%c%c%c%c%c%c      %c%c         %c%c%c%c%c    %c    %c                ", diamond, diamond, diamond, diamond, diamond, diamond, diamond, diamond, heart, heart, club, club, club, club, club, spade, spade);
    printf("\n                                                                                                     %c%c        %c  %c       %c     %c   %c   %c              ", diamond, diamond, heart, heart, club, club, spade, spade);
    printf("\n                                                                                                     %c%c       %c    %c     %c          %c  %c               ", diamond, diamond, heart, heart, club, spade, spade);
    printf("\n                                                                                                     %c%c       %c %c%c %c     %c          %c %c              ", diamond, diamond, heart, heart, heart, heart, club, spade, spade);
    printf("\n                                                                                                     %c%c      %c %c%c%c%c %c    %c          %c%c %c             ", diamond, diamond, heart, heart, heart, heart, heart, heart, club, spade, spade, spade);
    printf("\n                                                                                                     %c%c      %c      %c    %c          %c   %c               ", diamond, diamond, heart, heart, club, spade, spade);
    printf("\n                                                                                                  %c  %c%c     %c        %c    %c     %c   %c    %c             ", diamond, diamond, diamond, heart, heart, club, spade, spade);
    printf("\n                                                                                                   %c%c%c      %c        %c     %c%c%c%c%c    %c     %c            ", diamond, diamond, diamond, heart, heart, club, club, club, club, club, spade, spade);
    printf("\n");
    printf("\n                                                                                                      222                     111                         ");
    printf("\n                                                                                                     222                      111                         ");
    printf("\n                                                                                                    222                       111                         ");
    printf("\n                                                                                                   222222222222222      111111111111111                       ");
    printf("\n                                                                                                   2222222222222222    11111111111111111                         \n\n\n\n\n\n\n\n");
    printf("                     _________________________________________                                     _________________________________________                                      _________________________________________\n");
    printf("                     |                                       |                                     |                                       |                                      |                                       |\n");
    printf("                     |                PLAY: 1                |                                     |               RULES: 2                |                                      |              LEADERBOARD: 3           |\n");
    printf("                     |_______________________________________|                                     |_______________________________________|                                      |_______________________________________|");
    printf("\n\n\n\n");
    printf("                                                                                                        _______________________________");
    printf("\n                                                                                                              ENTER YOUR OPTION:      ");
    printf("\n\n                                                                                                                  (EXIT: 0)");
   // getch();

    //asktitle();
     int option;
     gotoxy(118,57);
     scanf("%d",&option);
     switch(option){
     case 0:
         return 0;
         break;
     case 1:
         return logIntoGame();
         break;
     case 2:
        return displayRules();
        break;
     case 3:
        BlackJackLeaderboard();
        return printMainInterfaceBJ();
        break;
     default:
        gotoxy(112,61);
        printf("Invalid input!");
        sleep(2);
        return printMainInterfaceBJ();
        break;
     }
}
void playBlackJack()
{
    printMainInterfaceBJ();
}
void logIntoGame()
{
    system("cls");

    printf("\n\n\n\n\n");
    printBlackJackTitle();
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                                              __________________________________________                                                               ___________________________________________\n");
    printf("                                              |                                        |                                                               |                                         |\n");
    printf("                                              |  PLAYER 1. USERNAME:                   |               (BOTH PLAYERS MUST HAVE ACCOUNTS)               |  PLAYER 2. USERNAME:                    |\n");
    printf("                                              |________________________________________|                                                               |_________________________________________|\n");
    printf("\n\n");
    printf("                                              __________________________________________                                                               ___________________________________________\n");
    printf("                                              |                                        |                                                               |                                         |\n");
    printf("                                              |  PLAYER 1. PASSWORD:                   |                (TYPE \"EXIT\" ANYWHERE TO EXIT)                 |  PLAYER 2. PASSWORD:                    |\n");
    printf("                                              |________________________________________|                                                               |_________________________________________|\n");
    printf("\n\n");

    char user1[30],pass1[30],user2[30],pass2[30];

    gotoxy(69,31);
    scanf("%s",&user1);
    if(!strcmp(user1,"EXIT")) return printMainInterfaceBJ();

    gotoxy(69,37);
    scanf("%s",&pass1);
    if(!strcmp(pass1,"EXIT")) return printMainInterfaceBJ();

    gotoxy(174,31);
    scanf("%s",&user2);
    if(!strcmp(user2,"EXIT")) return printMainInterfaceBJ();

    gotoxy(174,37);
    scanf("%s",&pass2);
    if(!strcmp(pass2,"EXIT")) return printMainInterfaceBJ();

    if(!(validUser(user1,pass1) && validUser(user2,pass2))){
        gotoxy(103,44);
        printf("INCORRECT USERNAMES OR PASSWORDS!");
        sleep(2);
        return printMainInterfaceBJ();
    }

    player1Score = player2Score = 0;
    getCash(user1,user2);
    playGame(user1,user2);

}
int randomCard(int *x, int *y, int playerScore)
{
    srand((unsigned) time(NULL)); //Generates random seed for rand() function
    int card=rand()%12;

    srand((unsigned) time(NULL));
     int randomShape = rand()%4+3;
     char shape[2] = "0";
     char randomCardShape[2];
     sprintf(randomCardShape,"%d",randomShape); // puts num 3-6 in randomCardShape
     strcat(shape,randomCardShape); // ascii value of shape as string

     char cardText[] = {'2','3','4','5','6','7','8','9','10','A','J','Q','K'};  // card array

    gotoxy(*x,*y);
    printf("-------------\n");
    gotoxy(*x,*y+1);
    printf("| %c         |\n", atoi(shape));
    gotoxy(*x,*y+2);
    printf("|           |\n");
    gotoxy(*x,*y+3);
    printf("|           |\n");
    gotoxy(*x,*y+4);
    if(card == 8) printf("|    10     |\n");
    else printf("|     %c     |\n",cardText[card]);
    gotoxy(*x,*y+5);
    printf("|           |\n");
    gotoxy(*x,*y+6);
    printf("|           |\n");
    gotoxy(*x,*y+7);
    printf("|         %c |\n", atoi(shape));
    gotoxy(*x,*y+8);
    printf("-------------\n");

    *x += 18;

    card+=2; // value between 2-14 instead of 0-12(array);
    if(card >= 10){
        if(card == 11){
            if(playerScore > 10) return 1;
            else return 11;  // return 1 or 11 depending on score
        }
        else{
            return 10;
        }
    }
    return card;

}
void generatePad(int width,char text[50],char pad[50])
{
    int i;
    for(i = 0; i < (width-strlen(text))/2; i++){
        pad[i] = ' ';
    }
    pad[i] = '\0';
}
void printGameInterface(char user1[30],char user2[30])
{
    char pad[20];
    system("cls");
    printf("\n\n\n");
    printBlackJackTitle();
    printf("\n");

    gotoxy(100,13);
    printf("________________________________________");
    gotoxy(100,14);
    printf("|                  |                   |");
    gotoxy(100,15);
    printf("|                  |                   |");  // create box for rounds
    gotoxy(100,16);
    printf("|                  |                   |");
    gotoxy(100,17);
    printf("|__________________|___________________|");

    gotoxy(101,15);
    generatePad(18,user1,pad);
    printf("%s%s",pad,user1);
    gotoxy(121,15);                       // print users centered in box
    generatePad(18,user2,pad);
    printf("%s%s",pad,user2);

    gotoxy(101,16);
    printf("        %d",user1Wins);
    gotoxy(121,16);
    printf("        %d",user2Wins);

    printRectArea();
    updateScores(0,0);
    printf("\n");
    gotoxy(15,20); //
    printf("PLAYER 1 (%s):",user1);

    gotoxy(15,36); //
    printf("PLAYER 2 (%s):",user2);

    gotoxy(108,60);
    printf("________________________");

    //gotoxy(112,62);
    //printf("ENTER YOUR OPTION:");

    gotoxy(112,62);
    printf("ENTER YOUR BET:");

    gotoxy(45,57);
    printf("______________________________\n");
    gotoxy(45,58);
    printf("|                            |\n");
    gotoxy(45,59);
    printf("|          HIT : H           |\n");
    gotoxy(45,60);
    printf("|____________________________|\n");

    gotoxy(168,57);
    printf("______________________________\n");
    gotoxy(168,58);
    printf("|                            |\n");
    gotoxy(168,59);
    printf("|         STAY : S           |\n");
    gotoxy(168,60);
    printf("|____________________________|\n");


}
void printUser(char user[30])
{
    gotoxy(108,63);
    printf("                       ");

    char pad[20];
    int i;
    for(i = 0; i < (24 - strlen(user) - 2)/2; i++){
        pad[i] = ' ';
    }
    pad[i] = '\0';
    gotoxy(108,63);
    printf("%s(%s)",pad,user);


}
void printCenteredText(char text[50],int width)
{
    char pad[50];
    int i;
    for(i = 0; i < (width - strlen(text))/2; i++){
        pad[i] = ' ';
    }
    pad[i] = '\0';
    printf("%s%s",pad,text);
}
void playGame(char user1[30],char user2[30])
{

    int player1Active = 1;
    int bet1;
    int card1CoordsX = 20; int card1CoordsY = 23;

    int player2Active = 1;
    int bet2;
    int card2CoordsX = 20; int card2CoordsY = 39;
    int cardValue;

    char option[5];
    printGameInterface(user1,user2);

    if(firstPlay){
    reverse = 0;
    printUser(user1);

    gotoxy(118,59);
    scanf("%d",&bet1);

    gotoxy(118,59);
    printf("     "); // overwrites bet

    printUser(user2);


    gotoxy(118,59);
    scanf("%d",&bet2);

    gotoxy(108,63);
    printf("                  ");  // overwrites 2.username
    gotoxy(118,59);
    printf("     "); // overwrites bet


    }

    gotoxy(111,62);
    printf("ENTER YOUR OPTION:");

    void playFirstHands(){
    if(reverse){
        cardValue = randomCard(&card2CoordsX,&card2CoordsY,player2Score);
        player2Score += cardValue;

        updateScores(player1Score,player2Score);
        gotoxy(118,59);
        sleep(1);

        cardValue = randomCard(&card1CoordsX,&card1CoordsY,player1Score);
        player1Score += cardValue;

        updateScores(player1Score,player2Score);
        gotoxy(118,59);
        sleep(1);
    }
    else{
        cardValue = randomCard(&card1CoordsX,&card1CoordsY,player1Score);
        player1Score += cardValue;

        updateScores(player1Score,player2Score);
        gotoxy(118,59);
        sleep(1);

        cardValue = randomCard(&card2CoordsX,&card2CoordsY,player2Score);
        player2Score += cardValue;

        updateScores(player1Score,player2Score);
        gotoxy(118,59);
        sleep(1);
    }
    }

    playFirstHands();
    playFirstHands();


    while(1){
        firstPlay = 0;
        if(player1Active && !reverse){


            printUser(user1);
            gotoxy(119,59);
            scanf("%s",&option);
            gotoxy(119,59);
            printf(" ");
            gotoxy(110,57);

            if(!strcmp(option,"H") || !strcmp(option,"h")){

                sleep(1);
                cardValue = randomCard(&card1CoordsX,&card1CoordsY,player1Score);
                player1Score += cardValue;
                updateScores(player1Score,player2Score);
                if(player1Score >= 21){reverse = !reverse; break;}
            }
            else if(!strcmp(option,"S") || !strcmp(option,"s")){
                player1Active = 0;
            }


        }
        if(player2Active){
            printUser(user2);
            gotoxy(119,59);
            scanf("%s",&option);
            gotoxy(119,59);
            printf(" ");

            if(!strcmp(option,"H") || !strcmp(option,"h")){
                sleep(1);
                cardValue = randomCard(&card2CoordsX,&card2CoordsY,player2Score);
                player2Score += cardValue;
                updateScores(player1Score,player2Score);
                if(player2Score >= 21){reverse = !reverse; break;}
            }
            else if(!strcmp(option,"S") || !strcmp(option,"s")){
                player2Active = 0;
            }
        }
        if(player1Active && reverse){
            printUser(user1);
            gotoxy(119,59);
            scanf("%s",&option);
            gotoxy(119,59);
            printf(" ");

            gotoxy(110,57);

            if(!strcmp(option,"H") || !strcmp(option,"h")){

                sleep(1);
                cardValue = randomCard(&card1CoordsX,&card1CoordsY,player1Score);
                player1Score += cardValue;
                updateScores(player1Score,player2Score);
                if(player1Score >= 21){reverse = !reverse; break;}
            }
            else if(!strcmp(option,"S") || !strcmp(option,"s")){
                player1Active = 0;
            }

        }


        if(!player1Active && player2Score > player1Score){reverse = !reverse; break;}
        if(!player2Active && player1Score > player2Score){reverse = !reverse; break;}
        if(!player1Active && !player2Active){reverse = !reverse; break;}

    }

    gotoxy(115,57);
    char user1Won[50];
    strcpy(user1Won,user1);
    strcat(user1Won," won");

    char user2Won[50];
    strcpy(user2Won,user2);
    strcat(user2Won," won");
    gotoxy(108,56);
    if(player1Score == player2Score) printCenteredText("draw",24);
    else{
    if(player1Score == 21){
        //printf("(%s) won",user1);
        printCenteredText(user1Won,24);
        user1Wins++;
    }
    else if(player2Score == 21){
       // printf("%s won",user2);
        printCenteredText(user2Won,24);
        user2Wins++;
    }
    else if(player1Score < 21 && player1Score > player2Score){
        //printf("%s won",user1);
        printCenteredText(user1Won,24);
        user1Wins++;
    }
    else if(player2Score < 21 && player2Score > player1Score){
       // printf("%s won",user2);
        printCenteredText(user2Won,24);
        user2Wins++;
    }
    else if(player1Score > 21){
       // printf("%s won",user2);
        printCenteredText(user2Won,24);
        user2Wins++;
    }
    else{
       // printf("%s won",user1);
        printCenteredText(user1Won,24);
        user1Wins++;
    }}
    sleep(2);
    player1Score = player2Score = 0;
     while(user1Wins < 3 && user2Wins < 3){
        system("cls");
        playGame(user1,user2);
    }

    gotoxy(101,16);
    printf("        %d",user1Wins);
    gotoxy(121,16);
    printf("        %d",user2Wins);

    gotoxy(108,56);
    if(user1Wins == 3){
        player1Cash += bet2;
        player2Cash -= bet2;
        printCenteredText(user1Won,24);
    }
    if(user2Wins == 3){
        player2Cash += bet1;
        player1Cash -= bet1;
        printCenteredText(user2Won,24);

    }
    sleep(2);
    addCashAndScore(user1,user2);
    getch();

    gotoxy(108,56);
    printCenteredText("New Game: 1  EXIT: 0 ",24);

    gotoxy(119,59);
    scanf("%s",&option);

    if(!strcmp(option,"1")){
            player1Score = player2Score = 0;
            firstPlay = 1;
            user1Wins = user2Wins = 0;
            return playGame(user1,user2);
    }
    else return printMainInterfaceBJ();
}

void removeSidebar()
{
    HWND console = GetConsoleWindow();
    ShowScrollBar(console, SB_BOTH, FALSE);
}
void screenSetting()
{
    void setScreenResolution()
    {
        DEVMODE devMode;
        ZeroMemory(&devMode, sizeof(devMode));
        devMode.dmSize = sizeof(devMode);
        devMode.dmPelsWidth = 1920;
        devMode.dmPelsHeight = 1080;
        devMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;
    }
    void setConsoleFullscreen()
    {
        HWND console = GetConsoleWindow();
        SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
        ShowWindow(console, SW_MAXIMIZE);
    }
    void removeSidebar()
    {
        HWND console = GetConsoleWindow();
        ShowScrollBar(console, SB_BOTH, FALSE);
    }
    void removeTop()
    {
        HWND console = GetConsoleWindow();
        SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) & ~WS_CAPTION);
    }
    void color()
    {
        system("COLOR 0B");
    }
    color();
    removeTop();
    setScreenResolution();
    setConsoleFullscreen();
    removeSidebar();
}
void gameScreen()
{
    system("cls");
    printf("\n\n\n\n");
    printf("                                                           ,ad8888ba,        db        88b           d88 88888888888    8b           d8 88888888888 88888888ba   ad88888ba  88888888888\n");
    printf("                                                          d8\"'    `\"8b      d88b       888b         d888 88             `8b         d8' 88          88      \"8b d8\"     \"8b 88         \n");
    printf("                                                         d8'               d8'`8b      88`8b       d8'88 88              `8b       d8'  88          88      ,8P Y8,         88         \n");
    printf("                                                         88               d8'  `8b     88 `8b     d8' 88 88aaaaa          `8b     d8'   88aaaaa     88aaaaaa8P' `Y8aaaaa,   88aaaaa    \n");
    printf("                                                         88      88888   d8YaaaaY8b    88  `8b   d8'  88 88\"\"\"\"\"           `8b   d8'    88\"\"\"\"\"     88\"\"\"\"88'     `\"\"\"\"\"8b, 88\"\"\"\"\"    \n");
    printf("                                                         Y8,        88  d8\"\"\"\"\"\"\"\"8b   88   `8b d8'   88 88                 `8b d8'     88          88    `8b           `8b 88         \n");
    printf("                                                          Y8a.    .a88 d8'        `8b  88    `888'    88 88                  `888'      88          88     `8b  Y8a     a8P 88         \n");
    printf("                                                           `\"Y88888P\" d8'          `8b 88     `8'     88 88888888888          `8'       88888888888 88      `8b  \"Y88888P\"  88888888888\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                ___________________________________________________                            ___________________________________________________                            ___________________________________________________\n");
    printf("                |                                                 |                            |                                                 |                            |                                                 |\n");
    printf("                |                                                 |                            |                ####                             |                            |                                                 |\n");
    printf("                |        = =      |             |                 |                            |          ##  ##    ##                           |                            |                                                 |\n");
    printf("                |      =     =    |             |                 |                            |                      ##                         |                            |                                                 |\n");
    printf("                |     =       =   |             |                 |                            |        ##    ##        ##                       |                            |                                                 |\n");
    printf("                |     =       =   |             |                 |                            |            ##      ##########                   |                            |    _     _            _    _            _       |\n");
    printf("                |      =     =    |             |                 |                            |                    ##########                   |                            |   | |   | |          | |  (_)          | |      |\n");
    printf("                |        = =      |             |                 |                            |                ##################               |                            |   | |__ | | __ _  ___| | ___  __ _  ___| | __   |\n");
    printf("                |    _____________|_____________|_____________    |                            |              ######################             |                            |   | '_ \\| |/ _` |/ __| |/ / |/ _` |/ __| |/ /   |\n");
    printf("                |                 |  __     __  |                 |                            |              ######################             |                            |   | |_) | | (_| | (__|   <| | (_| | (__|   <    |\n");
    printf("                |                 |  \\ \\   / /  |                 |                            |            ##########################           |                            |   |_.__/|_|\\__,_|\\___|_|\\_\\ |\\__,_|\\___|_|\\_\\   |\n");
    printf("                |                 |   \\ \\_/ /   |                 |                            |            ################  ########           |                            |                          _/ |                   |\n");
    printf("                |                 |    | _ |    |                 |                            |              ##############  ######             |                            |                         |__/                    |\n");
    printf("                |                 |   / / \\ \\   |                 |                            |              ############  ########             |                            |                                                 |\n");
    printf("                |                 |  /_/   \\_\\  |                 |                            |                ##################               |                            |                                                 |\n");
    printf("                |                 |             |                 |                            |                  ##############                 |                            |                                                 |\n");
    printf("                |                                                 |                            |                      ######                     |                            |                                                 |\n");
    printf("                |_________________________________________________|                            |_________________________________________________|                            |_________________________________________________|\n");
    printf("\n\n");
    printf("                                 TIC-TAC-TOE: 1                                                                  MINESWEEPER: 2                                                                   Black Jack: 3\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                     _________________________________________                                      _________________________________________                                      _________________________________________\n");
    printf("                     |                                       |                                      |                                       |                                      |                                       |\n");
    printf("                     |                EXIT: 0                |                                      |           ENTER A NUMBER:             |                                      |             LEADERBOARD: 4            |\n");
    printf("                     |_______________________________________|                                      |_______________________________________|                                      |_______________________________________|");

}
void TicTacToe()
{
    int validUser(char user[100],char enteredPassword[100])
    {
        FILE *file = fopen("accounts.txt", "r");

        char username[100];
        char password[100];
        char score[10];

        while (fscanf(file, "%s %s %s", username, password, score) == 3)
        {
            if (strcmp(username, user) == 0 && strcmp(password,enteredPassword) == 0)
            {
                fclose(file);
                return 1;
            }
        }
        fclose(file);
        return 0;
    }
    void addScore(char userInput[100], int scoreInput, int ind)
    {

        FILE* file = fopen("iksoks.txt", "r");
        FILE* temp_file = fopen("temp.txt", "w");

        char username[100];
        char score1[100];
        char score2[100];
        char score3[100];
        char score4[100];
        Player temp;


        while(fscanf(file,"%s %s %s %s %s",username,score1,score2,score3,score4) == 5)
        {

            if (strcmp(userInput, username) == 0)
            {
                temp.scores[0] = atoi(score1);
                temp.scores[1] = atoi(score2);
                temp.scores[2] = atoi(score3);
                temp.scores[3] = atoi(score4);

                temp.scores[3]+=scoreInput;

                if(ind == 1) temp.scores[0]+=scoreInput;
                else if(ind == 2) temp.scores[1]+=scoreInput;
                else temp.scores[2]+=scoreInput;

                fprintf(temp_file, "%s ", userInput);
                fprintf(temp_file, "%d ", temp.scores[0]);
                fprintf(temp_file, "%d ", temp.scores[1]);
                fprintf(temp_file, "%d ", temp.scores[2]);
                fprintf(temp_file, "%d ", temp.scores[3]);
                fprintf(temp_file, "\n");
            }
            else
            {
                fprintf(temp_file, "%s ", username);
                fprintf(temp_file, "%s ", score1);
                fprintf(temp_file, "%s ", score2);
                fprintf(temp_file, "%s ", score3);
                fprintf(temp_file, "%s ", score4);
                fprintf(temp_file, "\n");
            }
        }


        fclose(file);
        fclose(temp_file);

         if (remove("iksoks.txt") != 0) {
            printf("Failed to remove the original file.\n");
            return;
        }
        if (rename("temp.txt", "iksoks") != 0) {
            printf("Failed to rename the temporary file.\n");
            return;
        }
    }
    void nameGet()
    {
        system("cls");
        printf("\n\n");
        printf("                                                                                               _______ _        _______           _______ \n");
        printf("                                                                                              |__   __(_)      |__   __|         |__   __| \n");
        printf("                                                                                                 | |   _  ___     | | __ _  ___     | | ___   ___ \n");
        printf("                                                                                                 | |  | |/ __|    | |/ _` |/ __|    | |/ _ \\ / _ \\ \n");
        printf("                                                                                                 | |  | | (__     | | (_| | (__     | | (_) |  __/ \n");
        printf("                                                                                                 |_|  |_|\\___|    |_|\\__,_|\\___|    |_|\\___/ \\___| \n");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("                                              __________________________________________                                                               ___________________________________________\n");
        printf("                                              |                                        |                                                               |                                         |\n");
        printf("                                              |  PLAYER 1. USERNAME:                   |               (BOTH PLAYERS MUST HAVE ACCOUNTS)               |  PLAYER 2. USERNAME:                    |\n");
        printf("                                              |________________________________________|                                                               |_________________________________________|\n");
        printf("\n\n");
        printf("                                              __________________________________________                                                               ___________________________________________\n");
        printf("                                              |                                        |                                                               |                                         |\n");
        printf("                                              |  PLAYER 1. PASSWORD:                   |                (TYPE \"EXIT\" ANYWHERE TO EXIT)                 |  PLAYER 2. PASSWORD:                    |\n");
        printf("                                              |________________________________________|                                                               |_________________________________________|\n");
        printf("\n\n");

    }
    void mainScreen ()
    {
        system("cls");
        printf("\n\n");
        printf("                                                                                               _______ _        _______           _______ \n");
        printf("                                                                                              |__   __(_)      |__   __|         |__   __| \n");
        printf("                                                                                                 | |   _  ___     | | __ _  ___     | | ___   ___ \n");
        printf("                                                                                                 | |  | |/ __|    | |/ _` |/ __|    | |/ _ \\ / _ \\ \n");
        printf("                                                                                                 | |  | | (__     | | (_| | (__     | | (_) |  __/ \n");
        printf("                                                                                                 |_|  |_|\\___|    |_|\\__,_|\\___|    |_|\\___/ \\___| \n");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("                ___________________________________________________                            ___________________________________________________                            ___________________________________________________\n");
        printf("                |                                                 |                            |                                                 |                            |                                                 |\n");
        printf("                |                  $$$$$$$$$$$$$                  |                            |        = =      |             |                 |                            |                                                 |\n");
        printf("                |              $$$$$$$ _________$$$               |                            |      =     =    |             |                 |                            |                  ..ee$$$$$ee..                  |\n");
        printf("                |           $$$$$$$$$ ___________ $$$$            |                            |     =       =   |             |                 |                            |              .e$*\"\"    $    \"\"*$e.              |\n");
        printf("                |          $$_$$$____$$ ________ $___$$           |                            |     =       =   |             |                 |                            |            z$\"*.       $         $$c            |\n");
        printf("                |         $___$________$ ______ $______$$         |                            |      =     =    |             |                 |                            |          z$\"   *.      $       .P  ^$c          |\n");
        printf("                |        $___$ _________ $$$$$$$$_______$$        |                            |        = =      |             |                 |                            |         d\"      *      $      z\"     \"b         |\n");
        printf("                |       $___$$ ________ $$$$$$$$$________$$       |                            |    _____________|_____________|_____________    |                            |        $\"        b     $     4%       ^$        |\n");
        printf("                |      $$___$ _________ $$$$$$$$$$________$$      |                            |                 |  __     __  |                 |                            |       d%         *     $     P         '$       |\n");
        printf("                |      $___$$ _______$$$$$$$$$$$$$$_______$$      |                            |                 |  \\ \\   / /  |                 |                            |      .$          'F    $    J\"          $r      |\n");
        printf("                |      $__$$$$$ __ $$$___$$$$$$$__ $$$$___$$      |                            |                 |   \\ \\_/ /   |                 |                            |      4L           b    $    $           J$      |\n");
        printf("                |      $$$$$$$$$$$ _______ $$$________$$$$$$      |                            |                 |    | _ |    |                 |                            |      $F$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$      |\n");
        printf("                |      $_$$$$$$$ __________ $__________$$$$$      |                            |                 |   / / \\ \\   |                 |                            |      4F          4F    $    4r          4P      |\n");
        printf("                |      $_$$$$$$$ __________ $__________$$$$$      |                            |                 |  /_/   \\_\\  |                 |                            |      ^$          $     $     b          $%      |\n");
        printf("                |       $_$$$$$$ _________ $$__________ $$$       |                            |    _____________|_____________|_____________    |                            |       3L        .F     $     'r        JP       |\n");
        printf("                |        $_$$__$$ ________ $_________$$_$$        |                            |                 |  __     __  |      = =        |                            |        *c       $      $      3.      z$        |\n");
        printf("                |         $$_____$$$ ___ $$$$$____$$$___$         |                            |                 |  \\ \\   / /  |    =     =      |                            |         *b     J\"      $       3r    dP         |\n");
        printf("                |          $$ _____ $$$$$$$$$$$$$$$___$$          |                            |                 |   \\ \\_/ /   |   =       =     |                            |          ^$c  z%       $        \"c z$\"          |\n");
        printf("                |           $$$ _____ $$$$$$$$$$____$$            |                            |                 |    | _ |    |   =       =     |                            |            \"*$L        $        .d$\"            |\n");
        printf("                |             $$$$ __ $$$$$$$$$__$$$              |                            |                 |   / / \\ \\   |    =     =      |                            |               \"*$ee..  $  ..ze$P\"               |\n");
        printf("                |                $$$$$ _____ $$$$$                |                            |                 |  /_/   \\_\\  |      = =        |                            |                   \"\"*******\"\"                   |\n");
        printf("                |                    $$$$$$$$$$                   |                            |                                                 |                            |                                                 |\n");
        printf("                |_________________________________________________|                            |_________________________________________________|                            |_________________________________________________|\n");
        printf("\n");
        printf("                                FOOTY TIC-TAC-TOE: 1                                                         CLASSIC TIC-TAC-TOE: 2                                                         BASKETBALL TIC-TAC-TOE: 3            \n");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("                           _____________________________                                                  _____________________________                                                   _____________________________\n");
        printf("                           |                           |                                                  |                           |                                                   |                           |\n");
        printf("                           |          EXIT: 0          |                                                  |    ENTER YOUR CHOICE:     |                                                   |      LEADERBOARD: 4       |\n");
        printf("                           |___________________________|                                                  |___________________________|                                                   |___________________________|\n");
        printf("\n");
    }
    void basketballTicTacToe(char player1Name[30], char player2Name[30])
    {
        char listaIgraci[][30] = {"Kareem Abdul-Jabbar","Michael Jordan", "Larry Bird", "Magic Johnson","LeBron James", "Kevin Durant","Stephen Curry","Dirk Nowitzki","Giannis Antetokounmpo","David Robinson", /*1;3*/ "Stephen Curry","Kevin Durant","Michael Jordan","LeBron James","Kareem Abdul-Jabbar","Kobe Bryant","Tim Duncan","Magic Johnson","David Robinson","Hakeem Olajuwon" /*1:4*/,"Kareem Abdul-Jabbar","Bill Russell","Micheal Jordan", "Lebron James","Magic Johnson","Tim Duncan","James Harden","Allen Iverson","David Robinson","Derrick Rose"/*1:5*/, "LeBron James","Derrick Rose","/","/","/","/","/","/","/","/" /*1:6*/, "Micheal Jordan", "Derrick Rose","/","/","/","/","/","/","/","/" /*1:7*/,"LeBron James","Kevin Durant","James Harden","/","/","/","/","/","/","/" /*1:8*/, "LeBron James","Shaquille O'Neal","/","/","/","/","/","/","/","/" /*1:9*/, "LeBron James","Kareem Abdul-Jabbar","Russell Westbrook","Magic Johnson","Kobe Bryant","Shaquille O'Neal","/","/","/","/" /*1:10*/, "LeBron James","David Robinson","Stephen Curry","Larry Bird","Micheal Jordan","Allen Iverson","Kobe Bryant","James Harden","Tim Duncan","Kevin Durant" /*2:3*/, "LeBron James","Micheal Jordan","Hakeem Olajuwon","Kobe Bryant","Shaquille O'Neal","Kawhi Leonard","Kevin Durant","Stephen Curry","Magic Johnson","Tim Duncan" /*2:4*/, "LeBron James","Micheal Jordan","Hakeem Olajuwon","Tim Duncan","Magic Johnson","David Robinson","Shaquille O'Neal","/","/","/" /*2:5*/,"Lebron James","Dwayne Wade","Shaquille O'Neal","/","/","/","/","/","/","/" /*2:6*/, "Micheal Jordan","Dwayne Wade","/","/","/","/","/","/","/","/" /*2:7*/, "LeBron James","Kevin Durant","Kawhi Leonard","/","/","/","/","/","/","/" /*2:8*/, "LeBron James","Dwayne Wade","Shaquille O'Neal","/","/","/","/","/","/","/" /*2:9*/, "LeBron James","Shaquille O'Neal","Kobe Bryant","Magic Johnson","Kareem Abdul-Jabbar","/","/","/","/","/" /*2:10*/,"LeBron James","Micheal Jordan","Kobe Bryant","Kevint Durant","Stephen Curry","Tim Duncan","David Robinson","Kareem Abdul-Jabbar","/","/" /*3:4*/,"Kareem Abdul-Jabbar","Lebron James","Micheal Jordan","Magic Johnson","Tim Duncan","David Robinson","Hakeem Olajuwon","Shaquille O'Neal","/","/" /*3:5*/,"LeBron James","Dwayne Wade","Shaquille O'Neal","/","/","/","/","/","/","/" /*3:6*/,"Micheal Jordan","Dwayne Wade","Dennis Rodman","Scottie Pippen","Steave Kerr","Toni Kukoc","/","/","/","/" /*3:7*/, "Lebron James","Kevin Durant","Kawhi Leonard","/","/","/","/","/","/","/" /*3:8*/,"LeBron James","Dwayne Wade","Kevin Love","Shaquille O'Neal","/","/","/","/","/","/" /*3:9*/ ,"LeBron James","Kareem Abdul-Jabbar","Magic Johnson","Kobe Bryant","Shaquille O'Neal","Wilt Chamberlain","Rajon Rondo","Paul Gasol","/" /*3:10*/,"Lebron James","Kobe Bryant","Kareem Abdul-Jabbar","Wilt Chamberlain","Micheal Jordan","Shaquille O'Neal","Kevin Durant","Tim Duncan","David Robinson","Rey Allen","/" /*4:5*/,"Zydrunas Ilgauskas","LeBron James","Kyrie Irving","/","/","/","/","/","/","/" /*4:6*/,"Derrick Rose","Micheal Jordan","Scottie Pippen","/","/","/","/","/","/","/" /*4:7*/,"Kevin Durant","LeBron James","Antony Davis","James Harden","/","/","/","/","/","/" /*4:8*/,"LeBron James","Dwayne Wade","/","/","/","/","/","/","/","/" /*4:9*/,"Magic Johnson","LeBron James","Kareem Abdul-Jabbar","Carmelo Anthony","/","/","/","/","/","/" /*4:10*/,"Kareem Abdul-Jabbar","LeBron James","David Robinson","Tim Duncan","Hakeem Olajuwon","Kevin Durant","James Harden","/","/","/" /*5:6*/,"Dwayne Wade","/","/","/","/","/","/","/","/","/" /*5:7*/,"LeBron James","/","/","/","/","/","/","/","/","/" /*5:8*/,"LeBron James","Derrick Rose","Dwayne Wade","/","/","/","/","/","/","/" /*5:9*/,"George Mikan", "LeBron James","/","/","/","/","/","/","/","/"/*5:10*/,"LeBron James","/","/","/","/","/","/","/","/","/" /*6:7*/,"DeMar DeRozan","/","/","/","/","/","/","/","/","/" /*6:8*/,"Dwayne Wade","/","/","/","/","/","/","/","/","/" /*6:9*/,"Pat Bev","Alex Caruso","Lozno Ball","Dennis Rodman","Pau Gasol","/","/","/","/","/" /*6:10*/,"Micheal Jordan","Robert Parish","Dwayne Wade","DeMar DeRozan","Pau Gasol","George Gervin","/","/","/","/" /*7:8*/ ,"LeBron James","/","/","/","/","/","/","/","/","/" /*7:9*/,"LeBron James","Anthony Davis","Austin Reaves","Rui Hachimura","Dennis Shroder","/","/","/","/","/" /*7:10*/,"LeBron James","Kevin Durant","James Harden","Carmelo Anthony","/","/","/","/","/","/" /*8;9*/,"LeBron James","Shaquille O'Neal","Gary Payton","/","/","/","/","/","/","/" /*8:10*/,"LeBron James","Shaquille O'Neal","Rey Allen","Dwayne Wade","Gary Payton","Joe Johnson","/","/","/","/" /*9:10*/ ,"LeBron James","Kareem Abdul-Jabbar","Kobe Bryant","Karl Malone","Wilt Chamberlain","Shaquille O'Neal","Carmelo Anthony","Jerry West","Russell Westbrook","Pau Gasol"};
        char listaTimova[25][25] = {"        MVP        ", "    FINALS MVP     ","     2+ RINGS      ","    TOP 5 PICK     ","       CAVS        ","       BULLS       ","   PW: WESTBROOK   ","       HEAT        ","      LAKERS       ","    20K POINTS     "};
        char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        char showingSquares[][20] = {"                   ","                   ","                   ","         1         ","                   ","                   ","                   ","                   ","                   ","                   ","         2         ","                   ","                   ","                   ","                   ","                   ","                   ","         3         ","                   ","                   ","                   ","                   ","                   ","                   ","         4         ","                   ","                   ","                   ","                   ","                   ","                   ","         5         ","                   ","                   ","                   ","                   ","                   ","                   ","         6         ","                   ","                   ","                   ","                   ","                   ","                   ","         7         ","                   ","                   ","                   ","                   ","                   ","                   ","         8         ","                   ","                   ","                   ","                   ","                   ","                   ","         9         ","                   ","                   ","                   "};
        int scoreAddPlayer1=0;
        int scoreAddPlayer2=0;
        int tempScore;

        int checkwin()
        {
            if (square[1] == square[2] && square[2] == square[3])
                return 1;

            else if (square[4] == square[5] && square[5] == square[6])
                return 1;

            else if (square[7] == square[8] && square[8] == square[9])
                return 1;

            else if (square[1] == square[4] && square[4] == square[7])
                return 1;

            else if (square[2] == square[5] && square[5] == square[8])
                return 1;

            else if (square[3] == square[6] && square[6] == square[9])
                return 1;

            else if (square[1] == square[5] && square[5] == square[9])
                return 1;

            else if (square[3] == square[5] && square[5] == square[7])
                return 1;

            else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
                square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
                != '7' && square[8] != '8' && square[9] != '9')

                return 0;
            else
                return  - 1;
        }

        void board(int ind, char igrac[20],char row1[25], char row2[25], char row3[25], char col1[25], char col2[25], char col3[25])
        {
            system("cls");
            printf("\n\n\n");
            printf("                                              ___________________________________________________                                              ___________________________________________________\n");
            printf("                                              |                                                 |                                              |                                                 |\n");
            printf("                                              |                                                 |                                              |    Use capital letters when typing players      |\n");
            printf("                                              |                                                 |                                              |        Type the full name of the player         |\n");
            printf("                                              |                                                 |                                              |           example: Russell Westbrook            |\n");
            printf("                                              |_________________________________________________|                                              |_________________________________________________|\n");
            printf("\n\n\n\n");

            if(ind == 1) printf("                                                                                                          PLAYER SELECTED: %s            ", igrac);

            printf("\n\n\n");
            printf("                                                                                _________________________________________________________________________________\n");
            printf("                                                                                |                   |                   |                   |                   |\n");
            printf("                                                                                |                   |                   |                   |                   |\n");
            printf("                                                                                |                   |                   |                   |                   |\n");
            printf("                                                                                |                   |                   |                   |                   |\n");
            printf("                                                                                |                   |%s|%s|%s|\n",row1,row2,row3);
            printf("                                                                                |                   |                   |                   |                   |\n");
            printf("                                                                                |                   |                   |                   |                   |\n");
            printf("                                                                                |                   |                   |                   |                   |\n");
            printf("                                                                                |___________________|___________________|___________________|___________________|\n");
            printf("                                                                                |                   |                   |                   |                   |\n");
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[0],showingSquares[7],showingSquares[14]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[1],showingSquares[8],showingSquares[15]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[2],showingSquares[9],showingSquares[16]);
            printf("                                                                                |%s|%s|%s|%s|\n",col1,            showingSquares[3],showingSquares[10],showingSquares[17]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[4],showingSquares[11],showingSquares[18]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[5],showingSquares[12],showingSquares[19]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[6],showingSquares[13],showingSquares[20]);
            printf("                                                                                |___________________|___________________|___________________|___________________|\n");
            printf("                                                                                |                   |                   |                   |                   |\n");
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[21],showingSquares[28],showingSquares[35]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[22],showingSquares[29],showingSquares[36]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[23],showingSquares[30],showingSquares[37]);
            printf("                                                                                |%s|%s|%s|%s|\n",col2,            showingSquares[24],showingSquares[31],showingSquares[38]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[25],showingSquares[32],showingSquares[39]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[26],showingSquares[33],showingSquares[40]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[27],showingSquares[34],showingSquares[41]);
            printf("                                                                                |___________________|___________________|___________________|___________________|\n");
            printf("                                                                                |                   |                   |                   |                   |\n");
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[42],showingSquares[49],showingSquares[56]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[43],showingSquares[50],showingSquares[57]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[44],showingSquares[51],showingSquares[58]);
            printf("                                                                                |%s|%s|%s|%s|\n",col3,            showingSquares[45],showingSquares[52],showingSquares[59]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[46],showingSquares[53],showingSquares[60]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[47],showingSquares[54],showingSquares[61]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[48],showingSquares[55],showingSquares[62]);
            printf("                                                                                |___________________|___________________|___________________|___________________|\n");
            printf("\n\n\n\n\n\n");
            printf("        ___________________________________________________                                    ___________________________________________________                                   ___________________________________________________\n");
            printf("        |                                                 |                                    |                                                 |                                   |                                                 |\n");
            printf("        |                                                 |                                    |                                                 |                                   |                                                 |\n");

            if(ind == -1) printf("        |                NEW GAME: \"GAME\"                 |                                    |                 SKIP TURN: \"TURN\"               |                                   |                     EXIT: \"EXIT\"                |\n");
            else          printf("        |               SHUFFLE: \"SHUFFLE\"                |                                    |                 SKIP TURN: \"TURN\"               |                                   |                     EXIT: \"EXIT\"                |\n");

            printf("        |                                                 |                                    |                                                 |                                   |                                                 |\n");
            printf("        |_________________________________________________|                                    |_________________________________________________|                                   |_________________________________________________|\n");
        }

        int choiceCheck(char mark, char igrac[20], int col, int row)
        {
            int maks = MAX(row,col);
            int minn = MIN(row,col);
            int k = (minn*(minn+1))/2;
            int indeks = (minn*10 - k +(maks-minn)-1)*10;
            for(int i=0;i<10;i++)
            {
                if(strcmp(listaIgraci[indeks+i],igrac) == 0)
                {
                    return 1;
                }
            }
            return 0;
        }

        void tableChange(int choice, int player)
        {
            choice--;
            if(player == 1)
            {
                strcpy(showingSquares[7*choice],  "     __     __     ");
                strcpy(showingSquares[7*choice+1],"     \\ \\   / /     ");
                strcpy(showingSquares[7*choice+2],"      \\ \\_/ /      ");
                strcpy(showingSquares[7*choice+3],"       | _ |       ");
                strcpy(showingSquares[7*choice+4],"      / / \\ \\      ");
                strcpy(showingSquares[7*choice+5],"     /_/   \\_\\     ");


            }
            else
            {
                strcpy(showingSquares[7*choice],  "       =   =       ");
                strcpy(showingSquares[7*choice+1],"     =       =     ");
                strcpy(showingSquares[7*choice+2],"    =         =    ");
                strcpy(showingSquares[7*choice+3],"    =         =    ");
                strcpy(showingSquares[7*choice+4],"    =         =    ");
                strcpy(showingSquares[7*choice+5],"     =       =     ");
                strcpy(showingSquares[7*choice+6],"       =   =       ");
            }
        }

        void tableReset()
        {
            for(int i=0;i<63;i++)
            {
                strcpy(showingSquares[i],  "                   ");
            }
            strcpy(showingSquares[3],   "         1         ");
            strcpy(showingSquares[10],  "         2         ");
            strcpy(showingSquares[17],  "         3         ");
            strcpy(showingSquares[24],  "         4         ");
            strcpy(showingSquares[31],  "         5         ");
            strcpy(showingSquares[38],  "         6         ");
            strcpy(showingSquares[45],  "         7         ");
            strcpy(showingSquares[52],  "         8         ");
            strcpy(showingSquares[59],  "         9         ");
            square[1] = '1';
            square[2] = '2';
            square[3] = '3';
            square[4] = '4';
            square[5] = '5';
            square[6] = '6';
            square[7] = '7';
            square[8] = '8';
            square[9] = '9';
        }

        int player = 1, i, choice;
        char izbor[20];
        char mark;
        char tempPlayer[30];
        char indikator[20];
        int shuffind;

        int a[6];
        time_t t;
        srand((unsigned)time(&t));

        do
        {
            tableReset();
            i=-1;
            player  = 1;
            shuffind = 0;

            bool arr[15]={0};
            for(int i1=0;i1<6;++i1)
            {
                int r=rand()%9;
                if(!arr[r])
                a[i1] = r;
                else
                i1--;
                arr[r]=1;
            }

            do
            {

                player = (player % 2) ? 1 : 2;
                mark = (player == 1) ? 'X' : 'O';

                board(0,izbor, listaTimova[a[3]], listaTimova[a[4]], listaTimova[a[5]], listaTimova[a[0]], listaTimova[a[1]], listaTimova[a[2]]);
                gotoxy(49,6);
                if(player == 1) printf("%s enter a player: ", player1Name);
                else printf("%s enter a player: ", player2Name);
                fflush(stdin);
                gets(izbor);

                if(!strcmp(izbor,"TURN"))
                {
                    player++;
                }
                else
                {
                    if(!strcmp(izbor,"SHUFFLE"))
                    {
                        i= 1;
                        shuffind = 1;
                    }
                    else
                    {
                        if(!strcmp(izbor,"EXIT"))
                        {
                            gotoxy(110,64);
                            return 0;
                        }
                        else
                        {

                            board(1,izbor, listaTimova[a[3]], listaTimova[a[4]], listaTimova[a[5]], listaTimova[a[0]], listaTimova[a[1]], listaTimova[a[2]]);
                            gotoxy(49,6);

                            if(player == 1) printf("%s enter a number: ", player1Name);
                            else printf("%s enter a number: ", player2Name);


                            scanf("%d", &choice);

                            if (choice == 1 && square[1] == '1')
                            {
                                if(choiceCheck(mark,izbor,a[0],a[3]))
                                {
                                    square[1] = mark;
                                    tableChange(choice,player);
                                }
                            }
                            else if (choice == 2 && square[2] == '2')
                            {
                                if(choiceCheck(mark,izbor,a[0],a[4]))
                                {
                                    square[2] = mark;
                                    tableChange(choice,player);
                                }
                            }
                            else if (choice == 3 && square[3] == '3')
                            {
                                if(choiceCheck(mark,izbor,a[0],a[5]))
                                {
                                    square[3] = mark;
                                    tableChange(choice,player);
                                }
                            }
                            else if (choice == 4 && square[4] == '4')
                            {
                                if(choiceCheck(mark,izbor,a[1],a[3]))
                                {
                                    square[4] = mark;
                                    tableChange(choice,player);
                                }
                            }
                            else if (choice == 5 && square[5] == '5')
                            {
                                if(choiceCheck(mark,izbor,a[1],a[4]))
                                {
                                    square[5] = mark;
                                    tableChange(choice,player);
                                }
                            }
                            else if (choice == 6 && square[6] == '6')
                            {
                                if(choiceCheck(mark,izbor,a[1],a[5]))
                                {
                                    square[6] = mark;
                                    tableChange(choice,player);
                                }
                            }
                            else if (choice == 7 && square[7] == '7')
                            {
                                if(choiceCheck(mark,izbor,a[2],a[3]))
                                {
                                        square[7] = mark;
                                        tableChange(choice,player);
                                }
                            }
                            else if (choice == 8 && square[8] == '8')
                            {
                                if(choiceCheck(mark,izbor,a[2],a[4]))
                                {
                                    square[8] = mark;
                                    tableChange(choice,player);
                                }
                            }
                            else if (choice == 9 && square[9] == '9')
                            {
                                if(choiceCheck(mark,izbor,a[2],a[5]))
                                {
                                    square[9] = mark;
                                    tableChange(choice,player);
                                }
                            }
                            else
                            {
                                board(0,izbor, listaTimova[a[3]], listaTimova[a[4]], listaTimova[a[5]], listaTimova[a[0]], listaTimova[a[1]], listaTimova[a[2]]);
                                gotoxy(115,13);
                                printf("INVALID MOVE");
                                gotoxy(62,6);
                                printf("PRESS ANY BUTTON ");
                                player--;
                                getch();

                            }

                            i = checkwin(square);
                            player++;
                        }
                    }
                }

            }while (i ==  - 1);

            if(!shuffind)
            {
                board(-1,izbor, listaTimova[a[3]], listaTimova[a[4]], listaTimova[a[5]], listaTimova[a[0]], listaTimova[a[1]], listaTimova[a[2]]);

                if (i == 1)
                {

                    gotoxy(110,13);
                    if(player-1 == 1)
                    {
                        printf("RESULT: %s WIN ", player1Name);
                        scoreAddPlayer1 +=WINPOINTSTICTACTOE;
                    }
                    else
                    {
                        printf("RESULT: %s WIN ", player2Name);
                        scoreAddPlayer2 +=WINPOINTSTICTACTOE;
                    }

                }
                else
                {
                    gotoxy(111,13);
                    printf("\aRESULT: GAME DRAW");
                    scoreAddPlayer1 += (WINPOINTSTICTACTOE/2);
                    scoreAddPlayer2 += (WINPOINTSTICTACTOE/2);

                }


                gotoxy(53,6);
                printf("Enter \"GAME\" or \"EXIT\":  ");
                scanf("%s", &indikator);
            }


            addScore(player1Name,scoreAddPlayer1,3);
            addScore(player2Name,scoreAddPlayer2,3);

            strcpy(tempPlayer,player1Name);
            strcpy(player1Name,player2Name);
            strcpy(player2Name,tempPlayer);

            tempScore = scoreAddPlayer1;
            scoreAddPlayer1 = scoreAddPlayer2;
            scoreAddPlayer2 = tempScore;
        }
        while((!strcmp(indikator,"GAME")) || shuffind);

        return 0;
    }
    void footyTicTacToe (char player1Name[30], char player2Name[30])
    {

        char listaIgraci[][20] = {"Messi","Di Maria","Varane","Giroud","Kante","Neuer","Khedira","Schweinsteiger","Muller","Lahm","Kroos","Boateng","Iniesta","Ramos","Pique","Puyol","Xavi","Kaka","Ronaldinho","Casillas" /*1:3*/,"Pele","Cafu","Lucio","Carlos","Ronaldo","Rivaldo","Ronaldinho","Dida","Pele","Kaka","Garincha","Alberto","/","/","/","/","/","/","/","/"/*1:4*/,"Iniesta","Romario","Rivaldo","Pique","Puyol","Xavi","Pedro","Villa","Valdes","Busquets","Umtiti","Dembele","Messi","Henry","/","/","/","/","/","/"/*1:5*/,"Cannavaro","Valdano","Karembeu","Carlos","Casillas","Albiol","Alonso","Arbeloa","Khedira","Varane","Kroos","Mendy","Zidane","/","/","/","/","/","/","/"/*1:6*/,"Giroud","Kante","Pedro","Schurrle","Torres","Mata","Belleti","Petit","Deshamps","Desailly","Greaves","Fabregas","Bonetti","Fernandez","/","/","/","/","/","/"/*1:7*/,"Alonso","Torres","Reina","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*!;8*/,"Martinez","Di Maria","Charlton","Blanc","Varane","Pique","Mata","Schweomsteoger","/","/","/","/","/","/","/","/","/","/","/","/"/*1:9*/,"Alvarez","Boateng","Mendy","Silva","Navas","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*1:10*/,"Muller","Tolisso","Boateng","Gotze","Kroos","Lahm","Schweinsteiger","Neuer","Beckenbauer","/","/","/","/","/","/","/","/","/","/","/"/*1:11*/,"Dembele","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*1:12*/,"Martinez","Acuna","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*1:13*/,"Di Maria","Parades","Matuidi","Del Piero","Cannavaro","Buffon","Zidane","Deschamps","Coman","Khedira","/","/","/","/","/","/","/","/","/","/"/*1:14*/,"Giroud","Inzaghi","Pirlo","Nesta","Abbiati","Ronaldo","Ronaldinho","Kaka","/","/","/","/","/","/","/","/","/","/","/","/"/*1:15*/,"Martinez","Ronaldo","Materazzi","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*2:3*/,"Neymar","Casemiro","Marcelo","Alves","Carlos","Dida","Firmino","Luiz","Coutinho","Adriano","Lucio","Maicon","Rivaldo","Vinicius Jr","Silva","Rodrygo","Militao","Alberto","Kaka","Cafu"/*2:4*/,"Suarez","Neymar","Pedro","Messi","Xavi","Busquets","Iniesta","Rakitic","Alba","Alves","Pique","Ter Stegen","Henry","Toure","Valdes","Eto'o","Puyol","Mascherano","Fabregas","Adriano"/*2:5*/,"Ronaldo","Benzema","Bale","Modric","Kroos","Casemiro","Ramos","Varane","Carvajal","Marcelo","Casillas","Courtois","Vinicius Jr","Rodrygo","Camavinga","Alba","Coentrao","Zidane","Carlos","Pepe"/*2:6*/,"Drogba","Lampard","Cahill","Cole","Cech","Luiz","Mata","Werner","Ziyech","Pulisic","Giroud","Kante","Kovacic","Mount","Rudiger","James","Chillwell","Azpilicueta","Silva","Mendy"/*2:7*/,"Salah","Mane","Firmino","Thiago","Fabinho","Wijnildum","Henderson","Arnold","Robertson","Van Dijk","Matip","Alisson","Alonso","Owen","Gerrard","Carragher","Dudek","Carson","/","/"/*2:8*/,"Ronaldo","Di Maria","Casemiro","Varane","Solskjaer","Rooney","Welbeck","Tevez","Nani","Park","Giggs","Scholes","Carrick","Neville","Evra","Pique","Vidic","Ferdinand","Van Der Sar","/" /*2:9*/,"Tevez","Carson","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*2:10*/,"Robben","Ribery","Mandzukic","Lewandowski","Thiago","Schweinsteiger","Muller","Alaba","Boateng","Lahm","Coman","Gnabry","Neuer","Martinez","Mane","Kimmich","Davis","Coutinho","Kroos","Beckenbauer"/*2:11*/,"Lewandowski","Hakimi","Perisic","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*2:12*/,"Ziyech","Seedorf","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*2:13*/,"Ronaldo","Di Maria","Del Piero","Deschamps","Zidane","Khedira","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*2:14*/,"Maldini","Nesta","Dida","Cafu","Gattuso","Inzaghi","Pirlo","Seedorf","Shevchenko","Kaka","Ronaldinho","/","/","/","/","/","/","/","/","/" /*2:15*/,"Stankovic","Quaresma","Pandev","Milito","Eto'o","Balotelli","Motta","Sneijder","Materazzi","Lucio","Zanetti","Cordoba","Maicon","Cesar","/","/","/","/","/","/"/*3:4*/,"Alves","Ronaldinho","Neymar","Raphinha","Coutinho","Rivaldo","/","/","/","/","/","/","/","/","/","/","/","/","/","/" /*3:5*/,"Vinicius Jr", "Casemiro", "Marcelo", "Kaka","Rodrygo", "Militao", "Carlos","/","/","/","/","/","/","/","/","/","/","/","/","/" /*3:6*/,"Willian", "Luiz", "Ramires", "Pato", "Oscar", "Silva","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*3:7*/,"Fabinho","Alisson","Firmino","Coutinho","Arthur","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*3:8*/,"Antony","Fred","Casemiro","Telles","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*3:9*/,"Ederson","Jesus","Fernardinho","Danilo","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*3:10*/,"Costa","Coutinho","Dante","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*3:11*/,"Reinier","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*3:12*/,"Antony","Neres","Luis","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*3:13*/,"Bremer","Sandro","Alves","Danilo","Costa","Arthur","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*3:14*/,"Ronaldo","Kaka","Cafu","Ronaldinho","Silva","Pato","Rivaldo","Paqueta","Dida","/","/","/","/","/","/","/","/","/","/","/"/*3:15*/,"Ronaldo","Maicon","Cesar","Lucio","Miranda","Coutinho","Telles","/","/","/","/","/","/","/","/","/","/","/","/","/"/*4:5*/,"Figo","Hagi","Enrique","Ronaldo","Eto'o","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*4:6*/,"Fabregas","Petit","Gudjohnsen","Deco","Quaresma","Pedro","Eto'o","/","/","/","/","/","/","/","/","/","/","/","/","/"/*4:7*/,"Thiago","Suarez","Coutinho","Mascherano","Reina","Arthur","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*4:8*/,"Pique","Ibrahimovic","Valdes","Sanchez","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*4:9*/,"Torres","Toure","Aguero","Bravo","/","/","/","/","/","-/","/","/","/","/","/","/","/","/","/","/"/*4:10*/,"Thiago","Coutinho","Lewandowski","Vidal","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*4:11*/,"Dembele","Boateng","Lewandowski","Gomez","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*4:12*/,"De Jong","Vermalen","Koeman","Suarez","Dest","Rijkard","Davids","Ibrahimovic","Cruyff","Overmars","Kluivert","/","/","/","/","/","/","/","/","/"/*4:13*/,"Alves","Ibrahimovic","Henry","Davids","Pjanic","Vidal","Arthur","/","/","/","/","/","/","/","/","/","/","/","/","/"/*4:14*/,"Ronaldo","Ibrahimovic","Ronaldinho","Rivaldo","Dest","Kluivert","Kessie","Boateng","Reina","/","/","/","/","/","/","/","/","/","/","/"/*4:15*/,"Ronaldo","Ibrahimovic","Eto'o","Motta","Davids","Alcantara","Maxwell","Quaresma","Vidal","Figo","Sanchez","/","/","/","/","/","/","/","/","/"/*5:6*/,"Robben","Courtois","Kovacic","Hazard","Rudiger","Essien","Makelele","Morata","Eto'o","/","/","/","/","/","/","/","/","/","/","/"/*5:7*/,"Owen","Fabinho","Arbeloa","Anelka","Alonso","Dudek","/","/","/","/","/","/","/","/","/","/","/","/","/","/" /*5:8*/,"Ronaldo","Di Maria","Beckham","Varane","Casemiro","Oweb","Van Nistelrooy","Hernandez","/","/","/","/","/","/","/","/","/","/","/","/"/*5:9*/,"Diaz","Anelka","Danilo","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/" /*5:10*/,"Robben","Rodriguez","Alaba","Kroos","Alonso","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*5:11*/,"Hakimi","Reinier","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/" /*5:12*/,"Seedorf","Sneijder","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/" /*5:13*/,"Ronaldo","Zidane","Morata","Cannavaro","Higuain","Khedira","Di Maria","Danilo","/","/","/","/","/","/","/","/","/","/","/","/" /*5:14*/,"Ronaldo","Kaka","Seedorf","Robinho","Higuain","Hernandez","Diaz","/","/","/","/","/","/","/","/","/","/","/","/","/" /*5:15*/,"Ronaldo","Seedorf","Figo","Sneijder","Hakimi","Cannavaro","Kovacic","/","/","/","/","/","/","/","/","/","/","/","/","/" /*6:7*/,"Salah","Anelka","Cole","Torres","Sturridge","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*6:8*/,"Lukaku","Matic","Veron","Mata","Falcao","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/" /*6:9*/,"Ake","Lampard","De Bruyne","Sterling","Anelka","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*6:10*/,"Robben","Ballack","Pizzaro","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*6:11*/,"Pulisic","Schurrle","Aubameyang","Hazard","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*6:12*/,"Ziyech","Luis","Traore","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*6:13*/,"Morata","Cuadrado","Anelka","Higuain","Zakaria","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*6:14*/,"Giroud","Shevchenko","Essien","Silva","Aubameyang","Torres","Crespo","Guilit","Higuain","Bakayoko","/","/","/","/","/","/","/","/","/","/"/*6:15*/,"Lukaku","Eto'o","Crespo","Veron","Quaresma","Kovacic","Moses","/","/","/","/","/","/","/","/","/","/","/","/","/"/*7:8*/,"Toure","Owen","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*7:9*/,"Milner","Sterling","Balotelli","Toure","Sturridge","Anelka","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*7:10*/,"Thiago","Mane","Reina","Alonso","Can","Saqiri","Coutinho","/","/","/","/","/","/","/","/","/","/","/","/","/"/*7:11*/,"Can","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*7:12*/,"Suarez","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*7:12*/,"Arthur","Sissoko","Can","Anelka","Rush","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*7:14*/,"Torres","Balotelli","Suso","Reina","Origi","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/" /*7:15*/,"Saqiri","Coutinho","Balotelli","Keane","Moses","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/" /*8:9*/,"Tevez","Schmeichel","Sancho","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*8:10*/,"Sabitzer","Schweinsteiger","Blind","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/" /*8:11*/,"Sancho","Kagawa","Mkhitaryan","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*8:12*/,"Antony","Martinez","Van De Beek","Blind","Stam","Ibrahimovic","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*8:13*/,"Ronaldo","Pogba","Tevez","Ibrahimovic","Van Der Sar","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/" /*8:14*/,"Ibrahimovic","Beckham","Dalot","Darmian","Stam","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/" /*8:15*/,"Lukaku","Ibrahimovic","Telles","Sanchez","Veron","Forlan","Darmian","Young","Vidic","Eriksen","Mkhitaryan","/","/","/","/","/","/","/","/","/"/*9:10*/,"Cancelo","Sane","Boateng","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/" /*9:11*/,"Sancho","Haaland","Akanji","Gundogan","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*9:12*/,"De Jong","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*9:13*/,"Cancelo","Danilo","Tevez","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*9:14*/,"Diaz","Balotelli","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*9:15*/,"Cancelo","Balotelli","Dzeko","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*10:11*/,"Lewandowski","Hummels","Gotze","Sule","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*10:12*/,"Blind","Gravenberch","Mazraoui","De Ligt","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*10:13*/,"Costa","De Ligt","Coman","Benatia","Vidal","Mandzukic","Can","/","/","/","/","/","/","/","/","/","/","/","/","/"/*10:14*/,"Oddo","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*10:15*/,"Matthaus","Lucio","Perisic","Cancelo","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*11:12*/,"Haller","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*11:13*/,"Can","Immobile","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*11:14*/,"Aubameyang","Boateng","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*11:15*/,"Perisic","Hakimi","Mkhitaryan","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*12:13*/,"De Ligt","Ibrahimovic","Van Der Sar","Davids","Milik","/","/","/","/","/","/","/","/","/","/","/","/","/","/","/"/*12:14*/,"Seedorf","Van Basten","Davids","Ibrahimovic","Rijkaard","Kluivert","Stam","Dest","/","/","/","/","/","/","/","/","/","/","/","/"/*12:15*/,"Seedorf","Davids","Ibrahimovic","Onana","Bergkamp","Sneijder","Eriksen","/","/","/","/","/","/","/","/","/","/","/","/","/"/*13:14*/,"Pirlo","Baggio","Inzaghi","Davids","Bonucci","Zambrota","Vieira","Higuain","/","/","/","/","/","/","/","/","/","/","/","/"/*13:15*/,"Pirlo","Ibrahimovic","Vieira","Davids","Baggio","Cannavaro","Bonucci","Cancelo","/","/","/","/","/","/","/","/","/","/","/","/"/*14:15*/,"Pirlo","Ronaldo","Seedorf","Crespo","Ibrahimovic","Balotelli","Baggio","Calhanoglu","/","/","/","/","/","/","/","/","/","/","/","/"};
        char listaTimova[25][25] = {"     WC Winner     ", "     CL Winner     ","     Brazilian     ","     Barcelona     ","    Real Madrid    ","      Chelsea      ","     Liverpool     ","    Man. United    ","     Man. City     ", "   Bayern Munich   ","     Dortmund      ","        Ajax       ","     Juventus      ", "      AC Milan     ", "    Inter Milan    "};
        char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        char showingSquares[][20] = {"                   ","                   ","                   ","         1         ","                   ","                   ","                   ","                   ","                   ","                   ","         2         ","                   ","                   ","                   ","                   ","                   ","                   ","         3         ","                   ","                   ","                   ","                   ","                   ","                   ","         4         ","                   ","                   ","                   ","                   ","                   ","                   ","         5         ","                   ","                   ","                   ","                   ","                   ","                   ","         6         ","                   ","                   ","                   ","                   ","                   ","                   ","         7         ","                   ","                   ","                   ","                   ","                   ","                   ","         8         ","                   ","                   ","                   ","                   ","                   ","                   ","         9         ","                   ","                   ","                   "};
        int scoreAddPlayer1=0;
        int scoreAddPlayer2=0;
        int tempScore;

        int checkwin()
        {
            if (square[1] == square[2] && square[2] == square[3])
                return 1;

            else if (square[4] == square[5] && square[5] == square[6])
                return 1;

            else if (square[7] == square[8] && square[8] == square[9])
                return 1;

            else if (square[1] == square[4] && square[4] == square[7])
                return 1;

            else if (square[2] == square[5] && square[5] == square[8])
                return 1;

            else if (square[3] == square[6] && square[6] == square[9])
                return 1;

            else if (square[1] == square[5] && square[5] == square[9])
                return 1;

            else if (square[3] == square[5] && square[5] == square[7])
                return 1;

            else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
                square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
                != '7' && square[8] != '8' && square[9] != '9')

                return 0;
            else
                return  - 1;
        }

        void board(int ind, char igrac[20],char row1[25], char row2[25], char row3[25], char col1[25], char col2[25], char col3[25])
        {
            system("cls");
            printf("\n\n\n");
            printf("                                              ___________________________________________________                                              ___________________________________________________\n");
            printf("                                              |                                                 |                                              |                                                 |\n");
            printf("                                              |                                                 |                                              |    Use capital letters when typing players      |\n");
            printf("                                              |                                                 |                                              |   Only type the last name of the player except  |\n");
            printf("                                              |                                                 |                                              |      for players like Di Maria, De Jong ...     |\n");
            printf("                                              |_________________________________________________|                                              |_________________________________________________|\n");
            printf("\n\n\n\n");

            if(ind == 1) printf("                                                                                                             PLAYER SELECTED: %s            ", igrac);

            printf("\n\n\n");
            printf("                                                                                _________________________________________________________________________________\n");
            printf("                                                                                |                   |                   |                   |                   |\n");
            printf("                                                                                |                   |                   |                   |                   |\n");
            printf("                                                                                |                   |                   |                   |                   |\n");
            printf("                                                                                |                   |                   |                   |                   |\n");
            printf("                                                                                |                   |%s|%s|%s|\n",row1,row2,row3);
            printf("                                                                                |                   |                   |                   |                   |\n");
            printf("                                                                                |                   |                   |                   |                   |\n");
            printf("                                                                                |                   |                   |                   |                   |\n");
            printf("                                                                                |___________________|___________________|___________________|___________________|\n");
            printf("                                                                                |                   |                   |                   |                   |\n");
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[0],showingSquares[7],showingSquares[14]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[1],showingSquares[8],showingSquares[15]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[2],showingSquares[9],showingSquares[16]);
            printf("                                                                                |%s|%s|%s|%s|\n",col1,            showingSquares[3],showingSquares[10],showingSquares[17]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[4],showingSquares[11],showingSquares[18]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[5],showingSquares[12],showingSquares[19]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[6],showingSquares[13],showingSquares[20]);
            printf("                                                                                |___________________|___________________|___________________|___________________|\n");
            printf("                                                                                |                   |                   |                   |                   |\n");
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[21],showingSquares[28],showingSquares[35]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[22],showingSquares[29],showingSquares[36]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[23],showingSquares[30],showingSquares[37]);
            printf("                                                                                |%s|%s|%s|%s|\n",col2,            showingSquares[24],showingSquares[31],showingSquares[38]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[25],showingSquares[32],showingSquares[39]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[26],showingSquares[33],showingSquares[40]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[27],showingSquares[34],showingSquares[41]);
            printf("                                                                                |___________________|___________________|___________________|___________________|\n");
            printf("                                                                                |                   |                   |                   |                   |\n");
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[42],showingSquares[49],showingSquares[56]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[43],showingSquares[50],showingSquares[57]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[44],showingSquares[51],showingSquares[58]);
            printf("                                                                                |%s|%s|%s|%s|\n",col3,            showingSquares[45],showingSquares[52],showingSquares[59]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[46],showingSquares[53],showingSquares[60]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[47],showingSquares[54],showingSquares[61]);
            printf("                                                                                |                   |%s|%s|%s|\n",showingSquares[48],showingSquares[55],showingSquares[62]);
            printf("                                                                                |___________________|___________________|___________________|___________________|\n");
            printf("\n\n\n\n\n\n");
            printf("        ___________________________________________________                                    ___________________________________________________                                   ___________________________________________________\n");
            printf("        |                                                 |                                    |                                                 |                                   |                                                 |\n");
            printf("        |                                                 |                                    |                                                 |                                   |                                                 |\n");

            if(ind == -1) printf("        |                NEW GAME: \"GAME\"                 |                                    |                 SKIP TURN: \"TURN\"               |                                   |                     EXIT: \"EXIT\"                |\n");
            else          printf("        |               SHUFFLE: \"SHUFFLE\"                |                                    |                 SKIP TURN: \"TURN\"               |                                   |                     EXIT: \"EXIT\"                |\n");

            printf("        |                                                 |                                    |                                                 |                                   |                                                 |\n");
            printf("        |_________________________________________________|                                    |_________________________________________________|                                   |_________________________________________________|\n");
        }

        int choiceCheck(char mark, char igrac[20], int col, int row)
        {
            int maks = MAX(row,col);
            int minn = MIN(row,col);
            int k = (minn*(minn+1))/2;
            int indeks = (minn*15 - k +(maks-minn)-1)*20;
            for(int i=0;i<20;i++)
            {
                if(strcmp(listaIgraci[indeks+i],igrac) == 0)
                {
                    return 1;
                }
            }
            return 0;
        }

        void tableChange(int choice, int player)
        {
            choice--;
            if(player == 1)
            {
                strcpy(showingSquares[7*choice],  "     __     __     ");
                strcpy(showingSquares[7*choice+1],"     \\ \\   / /     ");
                strcpy(showingSquares[7*choice+2],"      \\ \\_/ /      ");
                strcpy(showingSquares[7*choice+3],"       | _ |       ");
                strcpy(showingSquares[7*choice+4],"      / / \\ \\      ");
                strcpy(showingSquares[7*choice+5],"     /_/   \\_\\     ");


            }
            else
            {
                strcpy(showingSquares[7*choice],  "       =   =       ");
                strcpy(showingSquares[7*choice+1],"     =       =     ");
                strcpy(showingSquares[7*choice+2],"    =         =    ");
                strcpy(showingSquares[7*choice+3],"    =         =    ");
                strcpy(showingSquares[7*choice+4],"    =         =    ");
                strcpy(showingSquares[7*choice+5],"     =       =     ");
                strcpy(showingSquares[7*choice+6],"       =   =       ");
            }
        }

        void tableReset()
        {
            for(int i=0;i<63;i++)
            {
                strcpy(showingSquares[i],  "                   ");
            }
            strcpy(showingSquares[3],   "         1         ");
            strcpy(showingSquares[10],  "         2         ");
            strcpy(showingSquares[17],  "         3         ");
            strcpy(showingSquares[24],  "         4         ");
            strcpy(showingSquares[31],  "         5         ");
            strcpy(showingSquares[38],  "         6         ");
            strcpy(showingSquares[45],  "         7         ");
            strcpy(showingSquares[52],  "         8         ");
            strcpy(showingSquares[59],  "         9         ");
            square[1] = '1';
            square[2] = '2';
            square[3] = '3';
            square[4] = '4';
            square[5] = '5';
            square[6] = '6';
            square[7] = '7';
            square[8] = '8';
            square[9] = '9';
        }

        int player = 1, i, choice;
        char izbor[20];
        char mark;
        char tempPlayer[30];
        char indikator[20];
        int shuffind;

        int a[6];
        time_t t;
        srand((unsigned)time(&t));

        do
        {
            tableReset();
            i=-1;
            player  = 1;
            shuffind = 0;

            bool arr[15]={0};
            for(int i1=0;i1<6;++i1)
            {
                int r=rand()%14;
                if(!arr[r])
                a[i1] = r;
                else
                i1--;
                arr[r]=1;
            }

            do
            {

                player = (player % 2) ? 1 : 2;
                mark = (player == 1) ? 'X' : 'O';

                board(0,izbor, listaTimova[a[3]], listaTimova[a[4]], listaTimova[a[5]], listaTimova[a[0]], listaTimova[a[1]], listaTimova[a[2]]);
                gotoxy(49,6);
                if(player == 1) printf("%s enter a player name: ", player1Name);
                else printf("%s enter a player name: ", player2Name);
                fflush(stdin);
                gets(izbor);

                if(!strcmp(izbor,"TURN"))
                {
                    player++;
                }
                else
                {
                    if(!strcmp(izbor,"SHUFFLE"))
                    {
                        i= 1;
                        shuffind = 1;
                    }
                    else
                    {
                        if(!strcmp(izbor,"EXIT"))
                        {
                            gotoxy(110,64);
                            return 0;
                        }
                        else
                        {

                            board(1,izbor, listaTimova[a[3]], listaTimova[a[4]], listaTimova[a[5]], listaTimova[a[0]], listaTimova[a[1]], listaTimova[a[2]]);
                            gotoxy(49,6);

                            if(player == 1) printf("%s enter a number: ", player1Name);
                            else printf("%s enter a number: ", player2Name);


                            scanf("%d", &choice);

                            if (choice == 1 && square[1] == '1')
                            {
                                if(choiceCheck(mark,izbor,a[0],a[3]))
                                {
                                    square[1] = mark;
                                    tableChange(choice,player);
                                }
                            }
                            else if (choice == 2 && square[2] == '2')
                            {
                                if(choiceCheck(mark,izbor,a[0],a[4]))
                                {
                                    square[2] = mark;
                                    tableChange(choice,player);
                                }
                            }
                            else if (choice == 3 && square[3] == '3')
                            {
                                if(choiceCheck(mark,izbor,a[0],a[5]))
                                {
                                    square[3] = mark;
                                    tableChange(choice,player);
                                }
                            }
                            else if (choice == 4 && square[4] == '4')
                            {
                                if(choiceCheck(mark,izbor,a[1],a[3]))
                                {
                                    square[4] = mark;
                                    tableChange(choice,player);
                                }
                            }
                            else if (choice == 5 && square[5] == '5')
                            {
                                if(choiceCheck(mark,izbor,a[1],a[4]))
                                {
                                    square[5] = mark;
                                    tableChange(choice,player);
                                }
                            }
                            else if (choice == 6 && square[6] == '6')
                            {
                                if(choiceCheck(mark,izbor,a[1],a[5]))
                                {
                                    square[6] = mark;
                                    tableChange(choice,player);
                                }
                            }
                            else if (choice == 7 && square[7] == '7')
                            {
                                if(choiceCheck(mark,izbor,a[2],a[3]))
                                {
                                        square[7] = mark;
                                        tableChange(choice,player);
                                }
                            }
                            else if (choice == 8 && square[8] == '8')
                            {
                                if(choiceCheck(mark,izbor,a[2],a[4]))
                                {
                                    square[8] = mark;
                                    tableChange(choice,player);
                                }
                            }
                            else if (choice == 9 && square[9] == '9')
                            {
                                if(choiceCheck(mark,izbor,a[2],a[5]))
                                {
                                    square[9] = mark;
                                    tableChange(choice,player);
                                }
                            }
                            else
                            {
                                board(0,izbor, listaTimova[a[3]], listaTimova[a[4]], listaTimova[a[5]], listaTimova[a[0]], listaTimova[a[1]], listaTimova[a[2]]);
                                gotoxy(115,13);
                                printf("INVALID MOVE");
                                gotoxy(62,6);
                                printf("PRESS ANY BUTTON ");
                                player--;
                                getch();

                            }

                            i = checkwin(square);
                            player++;
                        }
                    }
                }

            }while (i ==  - 1);

            if(!shuffind)
            {
                board(-1,izbor, listaTimova[a[3]], listaTimova[a[4]], listaTimova[a[5]], listaTimova[a[0]], listaTimova[a[1]], listaTimova[a[2]]);

                if (i == 1)
                {
                    gotoxy(110,13);
                    if(player-1 == 1)
                    {
                        printf("RESULT: %s WIN ", player1Name);
                        scoreAddPlayer1 +=WINPOINTSTICTACTOE;
                    }
                    else
                    {
                        printf("RESULT: %s WIN ", player2Name);
                        scoreAddPlayer2 +=WINPOINTSTICTACTOE;
                    }
                }
                else
                {
                    gotoxy(111,13);
                    printf("\aRESULT: GAME DRAW");
                    scoreAddPlayer1 += (WINPOINTSTICTACTOE/2);
                    scoreAddPlayer2 += (WINPOINTSTICTACTOE/2);

                }


                gotoxy(53,6);
                printf("Enter \"GAME\" or \"EXIT\":  ");
                scanf("%s", &indikator);
            }


            addScore(player1Name,scoreAddPlayer1,1);
            addScore(player2Name,scoreAddPlayer2,1);

            strcpy(tempPlayer,player1Name);
            strcpy(player1Name,player2Name);
            strcpy(player2Name,tempPlayer);

            tempScore = scoreAddPlayer1;
            scoreAddPlayer1 = scoreAddPlayer2;
            scoreAddPlayer2 = tempScore;
        }
        while((!strcmp(indikator,"GAME")) || shuffind);

        return 0;
    }
    void classicTicTacToe (char player1Name[30], char player2Name[30])
    {
        char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        char showingSquares[][20] = {"                   ","                   ","                   ","         1         ","                   ","                   ","                   ","                   ","                   ","                   ","         2         ","                   ","                   ","                   ","                   ","                   ","                   ","         3         ","                   ","                   ","                   ","                   ","                   ","                   ","         4         ","                   ","                   ","                   ","                   ","                   ","                   ","         5         ","                   ","                   ","                   ","                   ","                   ","                   ","         6         ","                   ","                   ","                   ","                   ","                   ","                   ","         7         ","                   ","                   ","                   ","                   ","                   ","                   ","         8         ","                   ","                   ","                   ","                   ","                   ","                   ","         9         ","                   ","                   ","                   "};
        int scoreAddPlayer1=0;
        int scoreAddPlayer2=0;
        int tempScore;

        int checkwin()
        {
            if (square[1] == square[2] && square[2] == square[3])
                return 1;

            else if (square[4] == square[5] && square[5] == square[6])
                return 1;

            else if (square[7] == square[8] && square[8] == square[9])
                return 1;

            else if (square[1] == square[4] && square[4] == square[7])
                return 1;

            else if (square[2] == square[5] && square[5] == square[8])
                return 1;

            else if (square[3] == square[6] && square[6] == square[9])
                return 1;

            else if (square[1] == square[5] && square[5] == square[9])
                return 1;

            else if (square[3] == square[5] && square[5] == square[7])
                return 1;

            else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
                square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
                != '7' && square[8] != '8' && square[9] != '9')

                return 0;
            else
                return  - 1;
        }

        void board()
        {
            system("cls");

            printf("\n\n\n");
            printf("\n\n\n\n");
            printf("                                                                                                    ______________________________________\n");
            printf("                                                                                                    |                                    |\n");
            printf("                                                                                                    |                                    |\n");
            printf("                                                                                                    |____________________________________|\n");
            printf("\n\n\n\n\n\n");
            printf("                                                                                         _____________________________________________________________\n");
            printf("                                                                                         |                   |                   |                   |\n");
            printf("                                                                                         |%s|%s|%s|\n",showingSquares[0],showingSquares[7],showingSquares[14]);
            printf("                                                                                         |%s|%s|%s|\n",showingSquares[1],showingSquares[8],showingSquares[15]);
            printf("                                                                                         |%s|%s|%s|\n",showingSquares[2],showingSquares[9],showingSquares[16]);
            printf("                                                                                         |%s|%s|%s|\n",showingSquares[3],showingSquares[10],showingSquares[17]);
            printf("                                                                                         |%s|%s|%s|\n",showingSquares[4],showingSquares[11],showingSquares[18]);
            printf("                                                                                         |%s|%s|%s|\n",showingSquares[5],showingSquares[12],showingSquares[19]);
            printf("                                                                                         |%s|%s|%s|\n",showingSquares[6],showingSquares[13],showingSquares[20]);
            printf("                                                                                         |___________________|___________________|___________________|\n");
            printf("                                                                                         |                   |                   |                   |\n");
            printf("                                                                                         |%s|%s|%s|\n",showingSquares[21],showingSquares[28],showingSquares[35]);
            printf("                                                                                         |%s|%s|%s|\n",showingSquares[22],showingSquares[29],showingSquares[36]);
            printf("                                                                                         |%s|%s|%s|\n",showingSquares[23],showingSquares[30],showingSquares[37]);
            printf("                                                                                         |%s|%s|%s|\n",showingSquares[24],showingSquares[31],showingSquares[38]);
            printf("                                                                                         |%s|%s|%s|\n",showingSquares[25],showingSquares[32],showingSquares[39]);
            printf("                                                                                         |%s|%s|%s|\n",showingSquares[26],showingSquares[33],showingSquares[40]);
            printf("                                                                                         |%s|%s|%s|\n",showingSquares[27],showingSquares[34],showingSquares[41]);
            printf("                                                                                         |___________________|___________________|___________________|\n");
            printf("                                                                                         |                   |                   |                   |\n");
            printf("                                                                                         |%s|%s|%s|\n",showingSquares[42],showingSquares[49],showingSquares[56]);
            printf("                                                                                         |%s|%s|%s|\n",showingSquares[43],showingSquares[50],showingSquares[57]);
            printf("                                                                                         |%s|%s|%s|\n",showingSquares[44],showingSquares[51],showingSquares[58]);
            printf("                                                                                         |%s|%s|%s|\n",showingSquares[45],showingSquares[52],showingSquares[59]);
            printf("                                                                                         |%s|%s|%s|\n",showingSquares[46],showingSquares[53],showingSquares[60]);
            printf("                                                                                         |%s|%s|%s|\n",showingSquares[47],showingSquares[54],showingSquares[61]);
            printf("                                                                                         |%s|%s|%s|\n",showingSquares[48],showingSquares[55],showingSquares[62]);
            printf("                                                                                         |___________________|___________________|___________________|\n");
            printf("\n\n\n\n\n\n\n");
            printf("                                              __________________________________________                                                               __________________________________________\n");
            printf("                                              |                                        |                                                               |                                         |\n");
            printf("                                              |                EXIT: 0                 |                                                               |               NEW GAME: 10              |\n");
            printf("                                              |________________________________________|                                                               |_________________________________________|\n");

        }

        void tableChange(int choice, int player)
        {
            choice--;
            if(player == 1)
            {
                strcpy(showingSquares[7*choice],  "     __     __     ");
                strcpy(showingSquares[7*choice+1],"     \\ \\   / /     ");
                strcpy(showingSquares[7*choice+2],"      \\ \\_/ /      ");
                strcpy(showingSquares[7*choice+3],"       | _ |       ");
                strcpy(showingSquares[7*choice+4],"      / / \\ \\      ");
                strcpy(showingSquares[7*choice+5],"     /_/   \\_\\     ");


            }
            else
            {
                strcpy(showingSquares[7*choice],  "       =   =       ");
                strcpy(showingSquares[7*choice+1],"     =       =     ");
                strcpy(showingSquares[7*choice+2],"    =         =    ");
                strcpy(showingSquares[7*choice+3],"    =         =    ");
                strcpy(showingSquares[7*choice+4],"    =         =    ");
                strcpy(showingSquares[7*choice+5],"     =       =     ");
                strcpy(showingSquares[7*choice+6],"       =   =       ");
            }
        }

        void tableReset()
        {
            for(int i=0;i<63;i++)
            {
                strcpy(showingSquares[i],  "                   ");
            }
            strcpy(showingSquares[3],   "         1         ");
            strcpy(showingSquares[10],  "         2         ");
            strcpy(showingSquares[17],  "         3         ");
            strcpy(showingSquares[24],  "         4         ");
            strcpy(showingSquares[31],  "         5         ");
            strcpy(showingSquares[38],  "         6         ");
            strcpy(showingSquares[45],  "         7         ");
            strcpy(showingSquares[52],  "         8         ");
            strcpy(showingSquares[59],  "         9         ");
            square[1] = '1';
            square[2] = '2';
            square[3] = '3';
            square[4] = '4';
            square[5] = '5';
            square[6] = '6';
            square[7] = '7';
            square[8] = '8';
            square[9] = '9';
        }

        int ind;
        char tempPlayer[30];
        int player = 1, i, choice;
        char mark;
        int shuffind;
        do
        {
            shuffind = 0;
            player = 1;
            ind = 1;

            tableReset();

            do
            {
                board();
                player = (player % 2) ? 1 : 2;
                gotoxy(105,9);
                if(player == 1) printf("%s enter a number: ", player1Name);
                else printf("%s enter a number: ", player2Name);

                scanf("%d", &choice);

                if(choice == 0)
                {
                    return 0;
                }
                else
                {
                    if(choice == 10)
                    {
                        shuffind = 1;
                        i=1;
                    }
                    else
                    {
                        mark = (player == 1) ? 'X' : 'O';

                        if (choice == 1 && square[1] == '1')
                        {
                            square[1] = mark;
                            tableChange(choice,player);
                        }
                        else if (choice == 2 && square[2] == '2')
                        {
                            square[2] = mark;
                            tableChange(choice,player);
                        }

                        else if (choice == 3 && square[3] == '3')
                        {
                            square[3] = mark;
                            tableChange(choice,player);
                        }

                        else if (choice == 4 && square[4] == '4')
                        {
                            square[4] = mark;
                            tableChange(choice,player);
                        }

                        else if (choice == 5 && square[5] == '5')
                        {
                            square[5] = mark;
                            tableChange(choice,player);
                        }

                        else if (choice == 6 && square[6] == '6')
                        {
                            square[6] = mark;
                            tableChange(choice,player);
                        }

                        else if (choice == 7 && square[7] == '7')
                        {
                            square[7] = mark;
                            tableChange(choice,player);
                        }

                        else if (choice == 8 && square[8] == '8')
                        {
                            square[8] = mark;
                            tableChange(choice,player);
                        }

                        else if (choice == 9 && square[9] == '9')
                        {
                            square[9] = mark;
                            tableChange(choice,player);
                        }

                        else
                        {
                            board();
                            gotoxy(114,15);
                            printf("INVALID MOVE");
                            gotoxy(105,9);
                            printf("      PRESS ANY BUTTON  ");
                            player--;
                            getch();
                        }

                        i = checkwin();
                        player++;

                    }
                }

            }
            while (i ==  - 1);

            if(!shuffind)
            {
                if (i == 1)
                {
                    board();
                    gotoxy(110,15);

                    if(player-1 == 1)
                    {
                        printf("RESULT: %s WIN ", player1Name);
                        scoreAddPlayer1 +=WINPOINTSTICTACTOE;
                    }
                    else
                    {
                        printf("RESULT: %s WIN ", player2Name);
                        scoreAddPlayer2 +=WINPOINTSTICTACTOE;
                    }

                    gotoxy(105,9);
                    printf("      PRESS 0 OR 10: ");
                    scanf("%d", &ind);
                }
                else
                {
                    board();
                    gotoxy(112,15);
                    printf("\aRESULT: GAME DRAW");
                    scoreAddPlayer1 += (WINPOINTSTICTACTOE/2);
                    scoreAddPlayer2 += (WINPOINTSTICTACTOE/2);
                    gotoxy(105,9);
                    printf("       PRESS 0 OR 10: ");
                    scanf("%d", &ind);
                }
            }
            else
            {
                ind  = 1;
            }

            addScore(player1Name,scoreAddPlayer1,2);
            addScore(player2Name,scoreAddPlayer2,2);

            tempScore = scoreAddPlayer1;
            scoreAddPlayer1 = scoreAddPlayer2;
            scoreAddPlayer2 = tempScore;

            strcpy(tempPlayer,player1Name);
            strcpy(player1Name,player2Name);
            strcpy(player2Name,tempPlayer);
        }
        while(ind != 0);

        return 0;
    }
    void TicTacToeLeaderboard()
    {
        FILE *file = fopen("iksoks.txt","r");
        int numPlayers = 0;

        Player players[100];
        char user[30];
        char skor1[30];
        char skor2[30];
        char skor3[30];
        char skor4[30];

        while(fscanf(file,"%s %s %s %s %s", user, skor1, skor2, skor3, skor4) == 5)
        {

            strcpy(players[numPlayers].name, user);
            players[numPlayers].scores[0] = atoi(skor1);
            players[numPlayers].scores[1] = atoi(skor2);
            players[numPlayers].scores[2] = atoi(skor3);
            players[numPlayers].scores[3] = atoi(skor4);

            numPlayers++;

        }

        fclose(file);

        for(int i=0;i<numPlayers-1;i++)
        {
            for(int j=i;j<numPlayers;j++)
            {
                if(players[i].scores[3] < players[j].scores[3])
                {
                    players[numPlayers] = players[i];
                    players[i] = players[j];
                    players[j] = players[numPlayers];
                }
            }
        }

        system("cls");
        printf("\n");
        printf("                                              88          88888888888        db        88888888ba,   88888888888 88888888ba  88888888ba    ,ad8888ba,        db        88888888ba  88888888ba,\n");
        printf("                                              88          88                d88b       88      `\"8b  88          88      \"8b 88      \"8b  d8\"'    `\"8b      d88b       88      \"8b 88      `\"8b\n");
        printf("                                              88          88               d8'`8b      88        `8b 88          88      ,8P 88      ,8P d8'        `8b    d8'`8b      88      ,8P 88        `8b\n");
        printf("                                              88          88aaaaa         d8'  `8b     88         88 88aaaaa     88aaaaaa8P' 88aaaaaa8P' 88          88   d8'  `8b     88aaaaaa8P' 88         88\n");
        printf("                                              88          88\"\"\"\"\"        d8YaaaaY8b    88         88 88\"\"\"\"\"     88\"\"\"\"88'   88\"\"\"\"\"\"8b, 88          88  d8YaaaaY8b    88\"\"\"\"88'   88         88\n");
        printf("                                              88          88            d8\"\"\"\"\"\"\"\"8b   88         8P 88          88    `8b   88      `8b Y8,        ,8P d8\"\"\"\"\"\"\"\"8b   88    `8b   88         8P\n");
        printf("                                              88          88           d8'        `8b  88      .a8P  88          88     `8b  88      a8P  Y8a.    .a8P d8'        `8b  88     `8b  88      .a8P\n");
        printf("                                              88888888888 88888888888 d8'          `8b 88888888Y\"'   88888888888 88      `8b 88888888P\"    `\"Y8888Y\"' d8'          `8b 88      `8b 88888888Y\"'\n");
        printf("\n\n");
        printf("_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|                   USERNAME                   |              FOOTY TIC-TAC-TOE               |             CLASSIC TIC-TAC-TOE              |            BASKETBALL TIC-TAC-TOE            |                  TOTAL SCORE                  |");
        printf("|                                              |                    SCORE                     |                    SCORE                     |                    SCORE                     |                                               |");
        printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|           1.                                 |                                              |                                              |                                              |                                               |");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|           2.                                 |                                              |                                              |                                              |                                               |");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|           3.                                 |                                              |                                              |                                              |                                               |");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|           4.                                 |                                              |                                              |                                              |                                               |");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|           5.                                 |                                              |                                              |                                              |                                               |");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|           6.                                 |                                              |                                              |                                              |                                               |");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|           7.                                 |                                              |                                              |                                              |                                               |");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|           8.                                 |                                              |                                              |                                              |                                               |");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|           9.                                 |                                              |                                              |                                              |                                               |");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|          10.                                 |                                              |                                              |                                              |                                               |");
        printf("|                                              |                                              |                                              |                                              |                                               |");
        printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");

        int temp = 19;
        if(numPlayers > 10) numPlayers = 10;
        for(int i=0;i<numPlayers;i++)
        {
            gotoxy(15,temp);
            printf("%s",players[i].name);
            temp+=5;
        }
        temp = 19;
        for(int i=0;i<numPlayers;i++)
        {
            gotoxy(69,temp);
            printf("%d", players[i].scores[0]);
            temp+=5;
        }
        temp = 19;
        for(int i=0;i<numPlayers;i++)
        {
            gotoxy(116,temp);
            printf("%d", players[i].scores[1]);
            temp+=5;
        }
        temp = 19;
        for(int i=0;i<numPlayers;i++)
        {
            gotoxy(163,temp);
            printf("%d", players[i].scores[2]);
            temp+=5;
        }
        temp = 19;
        for(int i=0;i<numPlayers;i++)
        {
            gotoxy(210,temp);
            printf("%d", players[i].scores[3]);
            temp+=5;
        }

        getch();
    }
    char player1Name[100] = "jao", player2Name[100];
    char player1Password[100],player2Password[100];

    int gameChoice;
    do
    {

        nameGet();

        if(strcmp(player1Name,"jao"))
        {
            gotoxy(103,45);
            printf("INCORRECT USERNAMES OR PASSWORDS!");
        }
        gotoxy(69,33);
        scanf("%s", &player1Name);
        if(!strcmp(player1Name,"EXIT")) return 0;

        gotoxy(69,39);
        scanf("%s", &player1Password);
        if(!strcmp(player1Password,"EXIT")) return 0;

        gotoxy(174,33);
        scanf("%s", &player2Name);
        if(!strcmp(player2Name,"EXIT")) return 0;

        gotoxy(174,39);
        scanf("%s", &player2Password);
        if(!strcmp(player2Password,"EXIT")) return 0;

    }
    while((!validUser(player1Name,player1Password)) || (!validUser(player2Name,player2Password)));

    do
    {
        mainScreen();
        gotoxy(130,60);

        scanf("%d", &gameChoice);
        if(gameChoice == 1) footyTicTacToe(player1Name,player2Name);
        else if(gameChoice == 2) classicTicTacToe(player1Name,player2Name);
        else if(gameChoice == 3) basketballTicTacToe(player1Name,player2Name);
        else if(gameChoice == 4) TicTacToeLeaderboard();
    }
    while(gameChoice != 0);

    return 0;
}
void mineSweeper()
{

    char gameBoard[MAX_SIZE][MAX_SIZE];
    char visibleBoard[MAX_SIZE][MAX_SIZE];
    int remainingCells;
    int size;
    int numMines;

    void printFrame(int x1, int y1, int x2, int y2)
    {
        int i;

        gotoxy(x1, y1);
        for (i = x1; i <= x2; i++)
        {
            printf("_");
        }

        for (i = y1+1; i < y2+1; i++)
        {
            gotoxy(x1, i);
            printf("|");
            gotoxy(x2, i);
            printf("|");
        }

        gotoxy(x1, y2);
        printf("|");

        for (i = x1; i < x2-1; i++)
        {
            printf("_");
        }
        printf("|");
    }

    void initializeBoards()
    {
        int i, j;
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                gameBoard[i][j] = '.';
                visibleBoard[i][j] = '.';
            }
        }
    }

    void placeMines(int n, int m)
    {
        int i, j, count = 0;
        while (count < numMines)
        {
            do
            {
                i= rand() % size;
                j = rand() % size;
            }
            while (i == n && j == m);


            if (gameBoard[i][j] != '*')
            {
                gameBoard[i][j] = '*';
                count++;
            }
        }
    }
    void mineLeaderboard()
{
    FILE *file = fopen("mines.txt","r");
    int numPlayers = 0;

    Player players[100];
    char user[30];
    char skor1[30];
    char skor2[30];
    char skor3[30];
    char skor4[30];
    while(fscanf(file,"%s %s %s %s %s", user, skor1, skor2, skor3, skor4) == 5)
    {

        strcpy(players[numPlayers].name, user);
        players[numPlayers].scores[0] = atoi(skor1);
        players[numPlayers].scores[1] = atoi(skor2);
        players[numPlayers].scores[2] = atoi(skor3);
        players[numPlayers].scores[3] = atoi(skor4);

        numPlayers++;

    }

    fclose(file);

    for(int i=0;i<numPlayers-1;i++)
    {
        for(int j=i;j<numPlayers;j++)
        {
            if(players[i].scores[3] < players[j].scores[3])
            {
                players[numPlayers] = players[i];
                players[i] = players[j];
                players[j] = players[numPlayers];
            }
        }
    }

    system("cls");
    printf("\n");
    printf("                                              88          88888888888        db        88888888ba,   88888888888 88888888ba  88888888ba    ,ad8888ba,        db        88888888ba  88888888ba,\n");
    printf("                                              88          88                d88b       88      `\"8b  88          88      \"8b 88      \"8b  d8\"'    `\"8b      d88b       88      \"8b 88      `\"8b\n");
    printf("                                              88          88               d8'`8b      88        `8b 88          88      ,8P 88      ,8P d8'        `8b    d8'`8b      88      ,8P 88        `8b\n");
    printf("                                              88          88aaaaa         d8'  `8b     88         88 88aaaaa     88aaaaaa8P' 88aaaaaa8P' 88          88   d8'  `8b     88aaaaaa8P' 88         88\n");
    printf("                                              88          88\"\"\"\"\"        d8YaaaaY8b    88         88 88\"\"\"\"\"     88\"\"\"\"88'   88\"\"\"\"\"\"8b, 88          88  d8YaaaaY8b    88\"\"\"\"88'   88         88\n");
    printf("                                              88          88            d8\"\"\"\"\"\"\"\"8b   88         8P 88          88    `8b   88      `8b Y8,        ,8P d8\"\"\"\"\"\"\"\"8b   88    `8b   88         8P\n");
    printf("                                              88          88           d8'        `8b  88      .a8P  88          88     `8b  88      a8P  Y8a.    .a8P d8'        `8b  88     `8b  88      .a8P\n");
    printf("                                              88888888888 88888888888 d8'          `8b 88888888Y\"'   88888888888 88      `8b 88888888P\"    `\"Y8888Y\"' d8'          `8b 88      `8b 88888888Y\"'\n");
    printf("\n\n");
    printf("_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|                   USERNAME                   |            EASY-MODE MINESWEEPER             |            MEDIUM-MODE MINESWEEPER           |            HARD-MODE MINESWEEPER             |                  TOTAL SCORE                  |");
    printf("|                                              |                    SCORE                     |                    SCORE                     |                    SCORE                     |                                               |");
    printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|           1.                                 |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|           2.                                 |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|           3.                                 |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|           4.                                 |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|           5.                                 |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|           6.                                 |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|           7.                                 |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|           8.                                 |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|           9.                                 |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|          10.                                 |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");

    int temp = 19;
    if(numPlayers > 10) numPlayers = 10;
    for(int i=0;i<numPlayers;i++)
    {
        gotoxy(15,temp);
        printf("%s",players[i].name);
        temp+=5;
    }
    temp = 19;
    for(int i=0;i<numPlayers;i++)
    {
        gotoxy(69,temp);
        printf("%d", players[i].scores[0]);
        temp+=5;
    }
    temp = 19;
    for(int i=0;i<numPlayers;i++)
    {
        gotoxy(116,temp);
        printf("%d", players[i].scores[1]);
        temp+=5;
    }
    temp = 19;
    for(int i=0;i<numPlayers;i++)
    {
        gotoxy(163,temp);
        printf("%d", players[i].scores[2]);
        temp+=5;
    }
    temp = 19;
    for(int i=0;i<numPlayers;i++)
    {
        gotoxy(210,temp);
        printf("%d", players[i].scores[3]);
        temp+=5;
    }

    getch();
}

void addScore(char userInput[100], int scoreInput, int ind)
{

    FILE* file = fopen("mines.txt", "r");
    FILE* temp_file = fopen("temp.txt", "w");

    char username[100];
    char score1[100];
    char score2[100];
    char score3[100];
    char score4[100];
    Player temp;


    while(fscanf(file,"%s %s %s %s %s",username,score1,score2,score3,score4) == 5)
    {

        if (strcmp(userInput, username) == 0)
        {
            temp.scores[0] = atoi(score1);
            temp.scores[1] = atoi(score2);
            temp.scores[2] = atoi(score3);
            temp.scores[3] = atoi(score4);

            temp.scores[3]+=scoreInput;

            if(ind == 1) temp.scores[0]+=scoreInput;
            else if(ind == 2) temp.scores[1]+=scoreInput;
            else temp.scores[2]+=scoreInput;

            fprintf(temp_file, "%s ", userInput);
            fprintf(temp_file, "%d ", temp.scores[0]);
            fprintf(temp_file, "%d ", temp.scores[1]);
            fprintf(temp_file, "%d ", temp.scores[2]);
            fprintf(temp_file, "%d ", temp.scores[3]);
            fprintf(temp_file, "\n");
        }
        else
        {
            fprintf(temp_file, "%s ", username);
            fprintf(temp_file, "%s ", score1);
            fprintf(temp_file, "%s ", score2);
            fprintf(temp_file, "%s ", score3);
            fprintf(temp_file, "%s ", score4);
            fprintf(temp_file, "\n");
        }
    }


    fclose(file);
    fclose(temp_file);

     if (remove("mines.txt") != 0) {
        printf("Failed to remove the original file.\n");
        return;
    }
    if (rename("temp.txt", "mines.txt") != 0) {
        printf("Failed to rename the temporary file.\n");
        return;
    }
}
    void printNova()
    {
            int provera;

            gotoxy(78, 3);
            printf("_____________________________________________________________________________________                  \n", size);
            gotoxy(78, 4);
            printf("|                                                                                   |                  \n", size);
            gotoxy(78, 5);
            printf("|                          Do you want to play again?(1,0)                          |                  \n", size);
            gotoxy(78, 6);
            printf("|                                                                                   |                  \n", size);
            gotoxy(78, 7);
            printf("|                                                                                   |                  \n", size);
            gotoxy(78, 8);
            printf("|___________________________________________________________________________________|                  \n", size);
            gotoxy(120, 7);

            scanf("%d", &provera);

    }
    void printBoard(char board[MAX_SIZE][MAX_SIZE])
    {
        int i, j;
        printf("   ");
        gotoxy(84 - 5*(size-8), 11);
        for (i = 0; i < size; i++)
        {
            printf("     %2d   ", i);
        }
        printf("\n");

        for (i = 0; i < size; i++)
        {
            gotoxy(80 - 5*(size-8), 16 + i*4);
            printf("%d ", i);

            for (j = 0; j < size; j++)
            {
                if(board[i][j] == '1')
                {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                    printf("%9c ", board[i][j]);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
                else if(board[i][j] == '2')
                {
                    HANDLE hConsole1 = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole1, FOREGROUND_GREEN);
                    printf("%9c ", board[i][j]);
                    SetConsoleTextAttribute(hConsole1, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                }
                else if(board[i][j] == '3')
                {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    printf("%9c ", board[i][j]);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                }
                else if(board[i][j] == '4')
                {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE);
                    printf("%9c ", board[i][j]);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
                else
                    printf("%9c ", board[i][j]);


            }
            printf("\n");
        }
    }

    void revealAllCells()
    {
        int i, j;
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                if (gameBoard[i][j] == '*')
                {
                    visibleBoard[i][j] = '*';
                }
            }
        }
    }

    int countAdjacentMines(int row, int col)
    {
        int count = 0;
        int i, j;
        for (i = row - 1; i <= row + 1; i++)
            {
            for (j = col - 1; j <= col + 1; j++)
            {
                if (i >= 0 && i < size && j >= 0 && j < size)
                {
                    if (gameBoard[i][j] == '*')
                    {
                        count++;
                    }
                }
            }
        }

        return count;
    }

    void revealCell(int row, int col, int difficulty, int prvi)
    {
        if (visibleBoard[row][col] != '.')
        {
            if (prvi == 0)
            {
            if(difficulty == 3)
            {
                printFrame(71, 63, 170, 65);
                gotoxy(107, 64);
                printf("Already revealed, try other");
            }
            else if(difficulty == 2)
            {
                printFrame(71, 57, 170, 59);
                gotoxy(107, 58);
                printf("Already revealed, try other");
            }
            else if(difficulty == 1)
            {
                printFrame(71, 51, 170, 53);
                gotoxy(107, 52);
                printf("Already revealed, try other");
            }
            }
            return;
        }

        visibleBoard[row][col] = '0' + countAdjacentMines(row, col);
        remainingCells--;

        if (visibleBoard[row][col] == '0')
        {
            int i, j;
            for (i = row - 1; i <= row + 1; i++)
            {
                for (j = col - 1; j <= col + 1; j++)
                {
                    if (i >= 0 && i < size && j >= 0 && j < size)
                    {
                        revealCell(i, j, difficulty, 1);
                    }
                }
            }
        }

    }


    void revealCell2(int row, int col, int difficulty)
    {
        visibleBoard[row][col] = '0' + countAdjacentMines(row, col);
        remainingCells--;

        int i, j;
        for (i = row - 1; i <= row + 1; i++)
        {
            for (j = col - 1; j <= col + 1; j++)
            {
                if (i >= 0 && i < size && j >= 0 && j < size)
                {
                    if(gameBoard[i][j] != '*')
                    revealCell(i, j, difficulty, 1);
                }
            }
        }
    }

    void prviklik(int difficulty)
    {
        dodjidavarissanama:
        remainingCells = size * size - numMines;

        initializeBoards();

        int row, col;

        printf("\n");
        printBoard(visibleBoard);

        gotoxy(78, 3);
        printf("_____________________________________________________________________________________\n", size);
        gotoxy(78, 4);
        printf("|                                                                                   |\n", size);
        gotoxy(78, 5);
        if(size > 10)
            printf("|                 Enter the row and column (0-%d) to reveal a cell:                 |\n", size-1);
        else
            printf("|                 Enter the row and column (0-%d) to reveal a cell:                  |\n", size-1);

        gotoxy(78, 6);
        printf("|                                                                                   |\n", size);
        gotoxy(78, 7);
        printf("|                                                                                   |\n", size);
        gotoxy(78, 8);
        printf("|___________________________________________________________________________________|\n", size);
        gotoxy(119, 7);
        scanf("%d %d", &row, &col);
        system("cls");
        printFrame(15, 3, 225, 63);
        placeMines(row, col);
        if (row < 0 || row >= size || col < 0 || col >= size)
            {
                if(difficulty == 3)
                {
                    printFrame(71, 63, 170, 65);
                    gotoxy(107, 64);
                    printf("Invalid input. Try again.");
                }
                else if(difficulty == 2)
                {
                    gotoxy(0, 57);
                    printFrame(71, 57, 170, 59);
                    gotoxy(107, 58);
                    printf("Invalid input. Try again.");

                }
                else if(difficulty == 1)
                {

                    printFrame(71, 51, 170, 53);
                    gotoxy(107, 52);
                    printf("Invalid input. Try again.");
                }

                goto dodjidavarissanama;
            }

        if (gameBoard[row][col] == '*')
        {
            printf("Game over! You stepped on a mine.\n");
            revealAllCells();
            printBoard(visibleBoard);

        }

        revealCell2(row, col, difficulty);

        return 0;
    }

    void playGame()
    {
        oznaka:
        srand(time(NULL));
        user activeUser;
        char proba[30] = "veljko";
        strcpy(activeUser.userName,proba );

        int k = 10;

        gotoxy(49, 21-k);
        printf("88b           d88 88 888b      88 88888888888 ad88888ba  I8,        8        ,8I 88888888888 88888888888 88888888ba  88888888888 88888888ba\n");
        gotoxy(49, 22-k);
        printf("888b         d888 88 8888b     88 88         d8'     '8b `8b       d8b       d8' 88          88          88      '8b 88          88      '8b\n");
        gotoxy(49, 23-k);
        printf("88`8b       d8'88 88 88 `8b    88 88         Y8,          '8,     ,8'8,     ,8'  88          88          88      ,8P 88          88      ,8P\n");
        gotoxy(49, 24-k);
        printf("88 `8b     d8' 88 88 88  `8b   88 88aaaaa    `Y8aaaaa,     Y8     8P Y8     8P   88aaaaa     88aaaaa     88aaaaaa8P' 88aaaaa     88aaaaaa8P'\n");
        gotoxy(49, 25-k);
        printf("88  `8b   d8'  88 88 88   `8b  88 88'''''      `'''''8b,   `8b   d8' `8b   d8'   88'''''     88'''''     88'''''''   88'''''     88''''88'\n");
        gotoxy(49, 26-k);
        printf("88   `8b d8'   88 88 88    `8b 88 88                 `8b    `8a a8'   `8a a8'    88          88          88          88          88    `8b\n");
        gotoxy(49, 27-k);
        printf("88    `888'    88 88 88     `8888 88         Y8a     a8P     `8a8'     `8a8'     88          88          88          88          88     `8b\n");
        gotoxy(49, 28-k);
        printf("88     `8'     88 88 88      `888 88888888888 1Y88888P1       `8'       `8'      88888888888 88888888888 88          88888888888 88      `8b\n");


        int difficulty;
        printFrame(42 +  5 *k, 35 + k, 98 +  5 *k ,42 + k);
        printFrame(97, 34, 143 ,39);
        gotoxy(49 +  5 *k, 37 + k);
        printf("        Select the difficulty level");
        gotoxy(49 +  5 *k, 39  + k);
        printf("1. Easy   (Size:8x8,   Number of mines: 10)");
        gotoxy(49 +  5 *k, 40  + k);
        printf("2. Medium (Size:10x10, Number of mines: 20)");
        gotoxy(49 +  5 *k, 41  + k);
        printf("3. Hard   (Size:12x12, Number of mines: 36)");
        gotoxy(100 + 10, 37);
        printf("Enter your choice:");
        printFrame(15, 2, 225, 63);
        gotoxy(119 + 10, 37);
        scanf("%d", &difficulty);

        system("cls");

        printFrame(15, 3, 225, 63);


        if (difficulty == 3)
        {
            size = 12;
            numMines = 36;
        }
        else if (difficulty == 2)
        {
            size = 10;
            numMines = 20;
        }
        else
        {
            size = 8;
            numMines = 10;
        }

        system("cls");
        printFrame(15, 3, 225, 63);
        gotoxy(0, 20);

        prviklik(difficulty);
        int row, col;

        while (1)
        {
            printf("\n");
            printBoard(visibleBoard);

            gotoxy(78, 3);
            printf("_____________________________________________________________________________________");
            gotoxy(78, 4);
            printf("|                                                                                   |");
            gotoxy(78, 5);

            if(size > 10)
                printf("|                 Enter the row and column (0-%d) to reveal a cell:                 |", size-1);
            else
                printf("|                 Enter the row and column (0-%d) to reveal a cell:                  |", size-1);

            gotoxy(78, 6);
            printf("|                                                                                   |");
            gotoxy(78, 7);
            printf("|                                                                                   |" );
            gotoxy(78, 8);
            printf("|___________________________________________________________________________________|" );
            gotoxy(119, 7);

            scanf("%d %d", &row, &col);

            system("cls");
            printFrame(15, 3, 225, 63);


            if (row < 0 || row >= size || col < 0 || col >= size)
            {
                if(difficulty == 3)
                {
                    printFrame(71, 63, 170, 65);
                    gotoxy(107, 64);
                    printf("Invalid input. Try again.");
                }
                else if(difficulty == 2)
                {
                    gotoxy(0, 57);
                    printFrame(71, 57, 170, 59);
                    gotoxy(107, 58);
                    printf("Invalid input. Try again.");

                }
                else if(difficulty == 1)
                {

                    printFrame(71, 51, 170, 53);
                    gotoxy(107, 52);
                    printf("Invalid input. Try again.");
                }

                continue;
            }

            if (gameBoard[row][col] == '*')
            {
                system("cls");


                if(difficulty == 3)
                {
                    gotoxy(0, 63);
                    printf("                                                                  _________________________________________________________________________________________________________");
                    gotoxy(0, 64);
                    printf("                                                                  |                                   Game over! You stepped on a mine.                                   |");
                    gotoxy(0, 65);
                    printf("                                                                  |_______________________________________________________________________________________________________|");
                }
                else if(difficulty == 2)
                {
                    gotoxy(0, 57);
                    printf("                                                                  _________________________________________________________________________________________________________");
                    gotoxy(0, 58);
                    printf("                                                                  |                                   Game over! You stepped on a mine.                                   |");
                    gotoxy(0, 59);
                    printf("                                                                  |_______________________________________________________________________________________________________|");
                }
                else if(difficulty == 1)
                {

                    gotoxy(0, 51);
                    printf("                                                                  _________________________________________________________________________________________________________");
                    gotoxy(0, 52);
                    printf("                                                                  |                                   Game over! You stepped on a mine.                                   |");
                    gotoxy(0, 53);
                    printf("                                                                  |_______________________________________________________________________________________________________|");
                }
                printFrame(15, 3, 225, 63);

                revealAllCells();
                printBoard(visibleBoard);
                int provera;
                gotoxy(78, 3);
                printf("_____________________________________________________________________________________\n", size);
                gotoxy(78, 4);
                printf("|                                                                                   |\n", size);
                gotoxy(78, 5);
                printf("|                          Do you want to play again?(1,0)                          |\n", size);
                gotoxy(78, 6);
                printf("|                                                                                   |\n", size);
                gotoxy(78, 7);
                printf("|                                                                                   |\n", size);
                gotoxy(78, 8);
                printf("|___________________________________________________________________________________|\n", size);

                gotoxy(120, 7);
                scanf("%d", &provera);

                if(!provera)
                {
                    return 0;
                }
                else
                {
                    system("cls");
                    goto oznaka;
                }
            }

            revealCell(row, col, difficulty, 0);

            if (remainingCells == 0)
            {
                    if(difficulty == 3)
                    {
                        addScore(activeUser.userName, 100, 3);
                        gotoxy(0, 63);
                        printf("                                                                      _________________________________________________________________________________________________");
                        gotoxy(0, 64);
                        printf("                                                                      |                                   Congratulations! You won!                                   |");
                        gotoxy(0, 65);
                        printf("                                                                      |_______________________________________________________________________________________________|");
                    }
                    else if(difficulty == 2)
                    {
                        addScore(activeUser.userName, 100, 2);
                        gotoxy(0, 57);
                        printf("                                                                      _________________________________________________________________________________________________");
                        gotoxy(0, 58);
                        printf("                                                                      |                                   Congratulations! You won!                                   |");
                        gotoxy(0, 59);
                        printf("                                                                      |_______________________________________________________________________________________________|");
                    }
                    else if(difficulty == 1)
                    {
                        addScore(activeUser.userName, 100, 1);
                        gotoxy(0, 51);
                        printf("                                                                      _________________________________________________________________________________________________");
                        gotoxy(0, 52);
                        printf("                                                                      |                                   Congratulations! You won!                                   |");
                        gotoxy(0, 53);
                        printf("                                                                      |_______________________________________________________________________________________________|");
                    }

                    printBoard(visibleBoard);
                    int provera;

                    gotoxy(78, 3);
                    printf("_____________________________________________________________________________________\n", size);
                    gotoxy(78, 4);
                    printf("|                                                                                   |\n", size);
                    gotoxy(78, 5);
                    printf("|                          Do you want to play again?(1,0)                          |\n", size);
                    gotoxy(78, 6);
                    printf("|                                                                                   |\n", size);
                    gotoxy(78, 7);
                    printf("|                                                                                   |\n", size);
                    gotoxy(78, 8);
                    printf("|___________________________________________________________________________________|\n", size);

                    gotoxy(120, 7);
                    scanf("%d", &provera);

                    if(!provera)
                    {
                        return 0;
                    }
                    else
                    {
                        system("cls");
                        printFrame(15, 3, 225, 63);
                        goto oznaka;
                    }
            }

        }

    }
    int difficulty;

    system("COLOR 07");
    do
    {

        system("cls");


        int k = 10;

        gotoxy(49, 21-k);
        printf("88b           d88 88 888b      88 88888888888 ad88888ba  I8,        8        ,8I 88888888888 88888888888 88888888ba  88888888888 88888888ba\n");
        gotoxy(49, 22-k);
        printf("888b         d888 88 8888b     88 88         d8'     '8b `8b       d8b       d8' 88          88          88      '8b 88          88      '8b\n");
        gotoxy(49, 23-k);
        printf("88`8b       d8'88 88 88 `8b    88 88         Y8,          '8,     ,8'8,     ,8'  88          88          88      ,8P 88          88      ,8P\n");
        gotoxy(49, 24-k);
        printf("88 `8b     d8' 88 88 88  `8b   88 88aaaaa    `Y8aaaaa,     Y8     8P Y8     8P   88aaaaa     88aaaaa     88aaaaaa8P' 88aaaaa     88aaaaaa8P'\n");
        gotoxy(49, 25-k);
        printf("88  `8b   d8'  88 88 88   `8b  88 88'''''      `'''''8b,   `8b   d8' `8b   d8'   88'''''     88'''''     88'''''''   88'''''     88''''88'\n");
        gotoxy(49, 26-k);
        printf("88   `8b d8'   88 88 88    `8b 88 88                 `8b    `8a a8'   `8a a8'    88          88          88          88          88    `8b\n");
        gotoxy(49, 27-k);
        printf("88    `888'    88 88 88     `8888 88         Y8a     a8P     `8a8'     `8a8'     88          88          88          88          88     `8b\n");
        gotoxy(49, 28-k);
        printf("88     `8'     88 88 88      `888 88888888888 1Y88888P1       `8'       `8'      88888888888 88888888888 88          88888888888 88      `8b\n");


        gotoxy(0, 57);
        printf("                     _________________________________________                                      _________________________________________                                      _________________________________________\n");
        printf("                     |                                       |                                      |                                       |                                      |                                       |\n");
        printf("                     |                EXIT: 0                |                                      |             PLAY GAME: 1              |                                      |            LEADERBOARD: 2             |\n");
        printf("                     |_______________________________________|                                      |_______________________________________|                                      |_______________________________________|");
        printFrame(15, 3, 225, 63);
        gotoxy(98 + 10, 37);
        printf("  Enter your choice:");
        printFrame(97, 34, 143 ,39);

        gotoxy(98+ 19+ 12, 37);
        scanf("%d", &difficulty);

        if(difficulty == 1)
        {
            system("cls");
            playGame();
        }
        else if(difficulty == 2)
        {
            system("cls");
            mineLeaderboard();
        }
        else if(difficulty != 0)
        {
            gotoxy(113, 45);
            printf("INVALID CHOICE");
            getch();
        }

    }
    while(difficulty!=0);

    return 0;
}
void displayVerse()
{
    int choice;
    screenSetting();

    do
    {
        system("COLOR 0B");
        gameScreen();
        gotoxy(128,63);
        scanf("%d", &choice);

        if(choice == 1) TicTacToe();
        else if(choice  == 2) mineSweeper();
        else if(choice == 3) playBlackJack();
        else if(choice == 4) leaderboard();

    }
    while(choice != 0);

}





void changeResolution(){

    DEVMODE devMode;
    ZeroMemory(&devMode, sizeof(devMode));
    devMode.dmSize = sizeof(devMode);
    devMode.dmPelsWidth = 1920;
    devMode.dmPelsHeight = 1080;
    devMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;

    LONG result = ChangeDisplaySettings(&devMode, CDS_FULLSCREEN);
}
/// Change screen color ---- IRRELEVANT
void changeConsoleToColors(int ForgC, int BackC)
 {

 system("COLOR 0B");
 return;
}

/// CALCULATE NUMBER OF PIXELS IN XY BASIS
void calcScreenSize(int *x, int *y){
    int width = GetSystemMetrics(SM_CXSCREEN);
    int height = GetSystemMetrics(SM_CYSCREEN);

    *x = width / 8;
    *y = height / 8;
}

///SET CURSOR ON LOAD
void gotoxy(int x,int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
}

/// force open full window
void setConsoleFullscreen(){
    HWND consoleWindow = GetConsoleWindow();
    void forceSetFullScreen(){
        SetWindowLong(consoleWindow,GWL_STYLE,GetWindowLong(consoleWindow,GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
        ShowWindow(consoleWindow, SW_MAXIMIZE);
    }
    void removeScrollbar(){
        ShowScrollBar(consoleWindow,SB_BOTH,FALSE);
    }
    void removeTopNotch(){
        SetWindowLong(consoleWindow,GWL_STYLE,GetWindowLong(consoleWindow,GWL_STYLE) & ~WS_CAPTION);
    }

    forceSetFullScreen();
    removeScrollbar();
    removeTopNotch();
}

///Validation functions
int contains(char str[],char c){
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == c) return 1;
    }
    return 0;
}

int hasUpperChar(char str[]){
    for(int i = 0; i < strlen(str); i++){
        if(str[i] >= 65 && str[i] <= 90) return 1;
    }
    return 0;
}

int hasNumber(char str[]){
    for(int i = 0; i < strlen(str); i++){
        if(str[i] >= 48 && str[i] <= 57) return 1;
    }
    return 0;
}
int validInput(char email[], char password[]){
    char specialChars[] =  "!#$%&'()*+,-/:;<=>?[]^`{|}~";
    int validEmail(char email[]){

        int valid = contains(email,'@');
        if(!valid) return 0;
        for(int i = 0; i < strlen(specialChars); i++){
            if(contains(email,specialChars[i])) return 0;
        }
        return 1;

    }

    int validPassword(char password[]){
        return(hasUpperChar(password) && hasNumber(password) && strlen(password) >= 8);
        return 0;
    }
    return validEmail(email) * validPassword(password);

}

void coloredStringRed(char str[]){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                printf("%s",str);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

///Generate user for email
void generateUser(char email[], char user[]){
    int i = 0;
    while(email[i] != '@'){
        user[i] = email[i];
        i++;
    }
    user[i] = '\0';
}

///Generate new random password
char* generateRandomString(int length) {
    char* randomString = malloc((length + 1) * sizeof(char)); // Allocate memory for the string

    if (randomString == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    srand(time(NULL)); // Initialize random number generator

    for (int i = 0; i < length; i++) {
        randomString[i] = 'A' + (rand() % 26); // Generate a random uppercase letter
    }

    randomString[length] = '\0'; // Null-terminate the string

    return randomString;
}

void initMainScreen();

void printGameVerse(){
     printf("                                                           ,ad8888ba,        db        88b           d88 88888888888    8b           d8 88888888888 88888888ba   ad88888ba  88888888888\n");
    printf("                                                          d8\"'    `\"8b      d88b       888b         d888 88             `8b         d8' 88          88      \"8b d8\"     \"8b 88         \n");
    printf("                                                         d8'               d8'`8b      88`8b       d8'88 88              `8b       d8'  88          88      ,8P Y8,         88         \n");
    printf("                                                         88               d8'  `8b     88 `8b     d8' 88 88aaaaa          `8b     d8'   88aaaaa     88aaaaaa8P' `Y8aaaaa,   88aaaaa    \n");
    printf("                                                         88      88888   d8YaaaaY8b    88  `8b   d8'  88 88\"\"\"\"\"           `8b   d8'    88\"\"\"\"\"     88\"\"\"\"88'     `\"\"\"\"\"8b, 88\"\"\"\"\"    \n");
    printf("                                                         Y8,        88  d8\"\"\"\"\"\"\"\"8b   88   `8b d8'   88 88                 `8b d8'     88          88    `8b           `8b 88         \n");
    printf("                                                          Y8a.    .a88 d8'        `8b  88    `888'    88 88                  `888'      88          88     `8b  Y8a     a8P 88         \n");
    printf("                                                           `\"Y88888P\" d8'          `8b 88     `8'     88 88888888888          `8'       88888888888 88      `8b  \"Y88888P\"  88888888888\n");
}

void printMainInterface(char *option){
    system("cls");
    HWND hwnd = GetConsoleWindow();
    SetWindowLongPtr(hwnd, GWL_STYLE, GetWindowLongPtr(hwnd, GWL_STYLE) & ~WS_CAPTION);
    ShowWindow(hwnd, SW_MAXIMIZE);
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    int n = ((screenWidth/8) - 86)/2;
    for(int i=0;i<n;i++)
    {
        padding[i] = ' ';
    }
    for(int i=0;i<(((screenHeight/16)-28)/2)-11;i++) // 8 linije
    {
        printf("\n");
    }
    printGameVerse();
    printf("\n\n\n");
    printf("%s_______________________________________________________________________________________\n",padding);
    printf("%s|                                                                                     |\n",padding);
    printf("%s|                                                                                     |\n",padding);
    printf("%s|                _____________________________________________________                |\n",padding);
    printf("%s|                |                                                   |                |\n",padding);
    printf("%s|                |                1.CREATE ACCOUNT                   |                |\n",padding);
    printf("%s|                |___________________________________________________|                |\n",padding);
    printf("%s|                                                                                     |\n",padding);
    printf("%s|                                                                                     |\n",padding);
    printf("%s|                _____________________________________________________                |\n",padding);
    printf("%s|                |                                                   |                |\n",padding);
    printf("%s|                |                    2.LOGIN                        |                |\n",padding);
    printf("%s|                |___________________________________________________|                |\n",padding);
    printf("%s|                                                                                     |\n",padding);
    printf("%s|                                                                                     |\n",padding);
    printf("%s|                _____________________________________________________                |\n",padding);
    printf("%s|                |                                                   |                |\n",padding);
    printf("%s|                |                 3.LEADERBOARD                     |                |\n",padding);
    printf("%s|                |___________________________________________________|                |\n",padding);
    printf("%s|                                                                                     |\n",padding);
    printf("%s|                                                                                     |\n",padding);
    printf("%s|                _____________________________________________________                |\n",padding);
    printf("%s|                |                                                   |                |\n",padding);
    printf("%s|                |                 4.REPORT A BUG                    |                |\n",padding);
    printf("%s|                |___________________________________________________|                |\n",padding);
    printf("%s|                                                                                     |\n",padding);
    printf("%s|                                                                                     |\n",padding);
    printf("%s|_____________________________________________________________________________________|\n",padding);

    printf("\n\n\n\n%s                                  ENTER YOUR OPTION:                                   \n",padding);

    gotoxy(119,53);
    scanf("%s",option);

}

///CREATE ACCOUNT

void enterInfoFile(char user[],char password[]) {
    int score = 0;
    FILE *file = fopen("accounts.txt", "a");

    if (file == NULL) {
        fclose(file);
        return;
    }


    fprintf(file, "%s ", user);
    fprintf(file, "%s ", password);
    fprintf(file, "%d", score);
    fprintf(file, "\n");

    fclose(file);

}

void createMinesFile(char user[30]){
    FILE *file = fopen("mines.txt","a");

    fseek(file, 0, SEEK_END);

    fprintf(file,"%s 0 0 0 0\n",user);

    fclose(file);

}
void createIksoksFile(char user[30]){
    FILE *file = fopen("iksoks.txt","a");

    fseek(file, 0, SEEK_END);

    fprintf(file,"%s 0 0 0 0\n",user);

    fclose(file);

}
void createBlackJackFile(char user[30]){
    FILE *file = fopen("blackjack.txt","a");

    fseek(file, 0, SEEK_END);
    fprintf(file, "\n");
    fprintf(file,"%s 500 1000",user);

    fclose(file);

}

void submitReport(char subject[],char report[]){
    time_t date;
    time(&date); // generate date - ctime to return string weekday dd/mm time /yy

    FILE *file = fopen("reports.txt", "a");
    if (file == NULL) {
        return;
    }

    fprintf(file,"%s\n",subject);
    fprintf(file,"  %s\n",ctime(&date));
    fprintf(file," %s\n",report);
    fprintf(file,"______________________________________________\n\n") ;

    fclose(file);

}

int userExists(char* user) {
    FILE* file = fopen("accounts.txt", "r");

    if (file == NULL) {
        return;
    }

    char username[100];
    char password[100];
    char score[10];

    while (fscanf(file, "%s %s %s", username, password, score) == 3) {
        if (strcmp(username, user) == 0) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

int validUser(char* user,char *enteredPassword) {
    FILE* file = fopen("accounts.txt", "r");

    if (file == NULL) {
        return;
    }

    char username[100];
    char password[100];
    char score[10];

    while (fscanf(file, "%s %s %s", username, password, score) == 3) {
        if (strcmp(username, user) == 0 && strcmp(password,enteredPassword) == 0) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

int findInfoFile(char* user, char *userScore, char *passwordInput) {
    FILE* file = fopen("accounts.txt", "r");

    if (file == NULL) {
        fclose(file);
        return;
    }

    char username[100];
    char password[100];
    char score[10];

    while (fscanf(file, "%s %s %s", username, password, score) == 3) {
        if (strcmp(username, user) == 0 && strcmp(password,passwordInput) == 0) {
            strcpy(userScore,score);
            fclose(file);
            return 1;

        }
    }
    fclose(file);
    return 0;


}



/*user *createStructOutOfFile(int *size) {
    user *users = (user*)calloc(1,sizeof(user));
    int i = 0;

    FILE* file = fopen("accounts.txt", "r");

    if (file == NULL) {
        return;
    }

    char username[100];
    char password[100];
    char score[10];

    while (fscanf(file, "%s %s %s", username, password, score) == 3) {
            strcpy(users[i].userName,username);
            strcpy(users[i].password,password);
            users[i].score = atoi(score);
            i++;
            users = (user*)realloc(users,(i+1) * sizeof(user));
        }

    fclose(file);
    *size = i;
    return users;
}*/

void overwritePassword(char *userInput, char *passwordInput) {
    // Open the file in read mode
    FILE* file = fopen("accounts.txt", "r");
    if (file == NULL) {
        fclose(file);
        return;
    }

    // Create a temporary file for writing
    FILE* temp_file = fopen("temp.txt", "w");
    if (temp_file == NULL) {

        fclose(file);
        return;
    }

    char username[100];
    char password[100];
    char score[10];

    while(fscanf(file,"%s %s %s",username,password,score) == 3){
            if (strcmp(userInput, username) == 0){
                fprintf(temp_file, "%s ", userInput);
                fprintf(temp_file, "%s ", passwordInput);
                fprintf(temp_file, "%s", score);
                fprintf(temp_file, "\n");
            }else{
                fprintf(temp_file, "%s ", username);
                fprintf(temp_file, "%s ", password);
                fprintf(temp_file, "%s", score);
                fprintf(temp_file, "\n");
            }


    }


    fclose(file);
    fclose(temp_file);

    // Replace the original file with the temporary file
    remove("accounts.txt");
    rename("temp.txt","accounts.txt");

}
void sortStruct(user users[], int n){
    int i,j;
    for(i = 0; i < n - 1; i++){
        for(j = i; j < n;j++){
            if(users[i].score < users[j].score){
                user tmp = users[i];
                users[i] = users[j];
                users[j] = tmp;
            }
        }
    }
}


/// send new password on GMAIL SMTP
void sendEmail(char *email, char *password){
    FILE *f = fopen("script.txt","w");

    fprintf(f,"var Mailer = require(\"nodemailer\");var transportar = Mailer.createTransport({  service: \"gmail\",  auth: {    user: \"stralezl06@gmail.com\",    pass: \"kquxqkmgafialzmw\"  },});var mailOptions = {  from: \"stralezl06@gmail.com\",  to: \"%s\",  subject: \"GameVerse Login\",  html: \"<h1>Your new passowrd</h1><p>%s</p>\",};transportar.sendMail(mailOptions, (error, info) => {  if (error) console.log(error);  console.log(info);});",email,password);
    fclose(f);
    const char* javascriptInterpreter = "\"C:\\Program Files\\nodejs\\node.exe\""; // Replace with the actual path to the JavaScript interpreter
    const char* javascriptFile = "script.txt";

    char command[256];

    sprintf(command, "%s %s", javascriptInterpreter, javascriptFile);

    int result = system(command);
    return;

}

void forgotPassword(char *user){
    char padding[50];
    int i;
    for(i = 0; i < 46-strlen(user); i++){
        padding[i] = ' ';
    }
    padding[i] = '\0';

    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printGameVerse();
    printf("\n\n\n");
    printf("                                                                           __________________________________________________________________________________________\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                      HI, %s%s|\n",user,padding);
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                       CHECK YOUR EMAIL FOR NEW GENERATED PASSWORD                      |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                      ______________________________________________                    |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                   1:MAIN PAGE                           2.LOGIN PAGE                   |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |________________________________________________________________________________________|\n");
    gotoxy(120,29);
    int option;
    scanf("%d",&option);
    if(option == 1) initMainScreen();
    else if(option == 2) login();
    else{
        gotoxy(110,33);
        printf("ENTER VALID OPTION!");
        sleep(1);
        forgotPassword(user);

    }
}




///CREATE ACCOUNT
void createAccount(){
    system("cls");
    printf("\n\n\n\n\n\n\n\n"); /// + 6y
    printGameVerse();
    printf("\n\n\n");
    printf("                                                                           __________________________________________________________________________________________\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                    CREATE ACCOUNT                                      |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                    ________________________________________________                    |\n");
    printf("                                                                           |                    |                                              |                    |\n");
    printf("                                                                           |                    |                                              |                    |\n");
    printf("                                                                           |                    |   EMAIL:                                     |                    |\n");
    printf("                                                                           |                    |                                              |                    |\n");
    printf("                                                                           |                    |______________________________________________|                    |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                     RETURN: EXIT                                       |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                    ________________________________________________                    |\n");
    printf("                                                                           |                    |                                              |                    |\n");
    printf("                                                                           |                    |                                              |                    |\n");
    printf("                                                                           |                    |  PASSWORD:                                   |                    |\n");
    printf("                                                                           |                    |                                              |                    |\n");
    printf("                                                                           |                    |______________________________________________|                    |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |________________________________________________________________________________________|\n");
    char email[50],password[20],score[10],user[30];

    gotoxy(107,29);
    fflush(stdin);
    scanf("%s", &email);

    if(!strcmp(email,"EXIT")) initMainScreen(); // RETURN

    generateUser(email,user);

    gotoxy(97,43);
    if(userExists(user)){
        printf("User already exists!!!");
        sleep(2);
        createAccount();
    }

    printf("Password has to be at least 8 characters long");
    gotoxy(97,44);
    printf("including at least one big letter and number!");

    gotoxy(109,39);
    scanf("%s", &password);

    gotoxy(111,25);

    if(!validInput(email,password)){
        printf("INVALID INPUT!");
        sleep(2);
        createAccount();
    }else{


        printf("ACCOUNT CREATED");
        sleep(1);
        ///UBACI U DATOTEKU
        enterInfoFile(user,password);
        createMinesFile(user);
        createIksoksFile(user);
        createBlackJackFile(user);
        initMainScreen();
    }


}


///LOGIN
void login(){
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printGameVerse();
    printf("\n\n\n");
    printf("                                                                           __________________________________________________________________________________________\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                 LOG IN TO YOUR ACCOUNT                                 |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                    ________________________________________________                    |\n");
    printf("                                                                           |                    |                                              |                    |\n");
    printf("                                                                           |                    |                                              |                    |\n");
    printf("                                                                           |                    |   EMAIL:                                     |                    |\n");
    printf("                                                                           |                    |                                              |                    |\n");
    printf("                                                                           |                    |______________________________________________|                    |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                     RETURN: EXIT                                       |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                    ________________________________________________                    |\n");
    printf("                                                                           |                    |                                              |                    |\n");
    printf("                                                                           |                    |                                              |                    |\n");
    printf("                                                                           |                    |  PASSWORD:                                   |                    |\n");
    printf("                                                                           |                    |                                              |                    |\n");
    printf("                                                                           |                    |______________________________________________|                    |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                FORGOT PASSWORD: ENTER 1                                |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |________________________________________________________________________________________|\n");
    char email[50],password[20],user[30],score[10];

    gotoxy(107,29);
    scanf("%s", &email);

    if(!strcmp(email,"EXIT")) initMainScreen();

    gotoxy(109,39);
    scanf("%s", &password);
    generateUser(email,user);

    if(userExists(user) && !strcmp(password,"1")){
        char *newPassword = generateRandomString(8);

        overwritePassword(user,newPassword);
        sendEmail(email,newPassword);
        changeConsoleToColors(1,15);
        forgotPassword(user);

    }
    gotoxy(108,25);
    if(findInfoFile(user,score,password)){
        printf("LOGGED IN SUCCESSFULLY!!!");
        strcpy(activeUser.userName,user);
        activeUser.score = atoi(score);
        strcpy(activeUser.email,email);
        sleep(1);
        displayVerse();
    }else{
        printf("USER OR PASSWORD INVALID");
        sleep(2);
        login();
    }

}

void reportBug(){
    system("cls");
    printf("\n\n\n\n\n\n\n\n");
    printGameVerse();
    printf("\n\n\n");
    printf("                                                                           __________________________________________________________________________________________\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                      REPORT A BUG                                      |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |      SUBJECT:                                                                          |\n");
    printf("                                                                           |      ________________________________________________                                  |\n");
    printf("                                                                           |      |                                              |                                  |\n");
    printf("                                                                           |      |                                              |                                  |\n");
    printf("                                                                           |      |______________________________________________|                                  |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |      REPORT:                                                                           |\n");
    printf("                                                                           |      ___________________________________________________________                       |\n");
    printf("                                                                           |      |                                                         |                       |\n");
    printf("                                                                           |      |                                                         |                       |\n");
    printf("                                                                           |      |                                                         |                       |\n");
    printf("                                                                           |      |                                                         |                       |\n");
    printf("                                                                           |      |                                                         |                       |\n");
    printf("                                                                           |      |                                                         |                       |\n");
    printf("                                                                           |      |                                                         |                       |\n");
    printf("                                                                           |      |                                                         |                       |\n");
    printf("                                                                           |      |_________________________________________________________|                       |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |                                                                                        |\n");
    printf("                                                                           |________________________________________________________________________________________|\n");

    char subject[100], report[500];


    gotoxy(84,28);
    fflush(stdin);
    gets(subject);

    gotoxy(84,34);
    fflush(stdin);
    gets(report);

    submitReport(subject,report);

    gotoxy(112,44);
    printf("REPORT SUBMITED!");
    sleep(2);
    initMainScreen();

}





int chooseOption(char option){
    switch(option){
    case '1':
        createAccount();
        break;
    case '2':
        login();
        break;
    case '3':
        leaderboard();
        initMainScreen();
        break;
    case '4':
        reportBug();
        break;
    default:
        gotoxy(111,45);
        printf("Enter valid number!");
        sleep(1);
        initMainScreen();
        break;
    }
    return 0;

}

void leaderboard()
{
    FILE *file = fopen("iksoks.txt","r");
    int numUsers = 0;

    Player players[100];

    char user[30];
    char skor1[30];
    char skor2[30];
    char skor3[30];
    char skor4[30];

    while(fscanf(file,"%s %s %s %s %s", user, skor1, skor2, skor3, skor4) == 5)
    {
        strcpy(players[numUsers].name, user);
        players[numUsers].scores[0] = atoi(skor4);
        numUsers++;
    }

    fclose(file);

    FILE *fajs = fopen("mines.txt","r");

    numUsers = 0;

    while(fscanf(fajs,"%s %s %s %s %s", user, skor1, skor2, skor3, skor4) == 5)
    {

        players[numUsers].scores[1] = atoi(skor4);
        numUsers++;
    }

    fclose(fajs);

    FILE *fajl = fopen("blackjack.txt","r");

    numUsers = 0;

    while(fscanf(fajl,"%s %s %s", user, skor1, skor3) == 3)
    {

        players[numUsers].scores[2] = atoi(skor3);
        numUsers++;
    }

    fclose(fajl);

    for(int i=0;i<numUsers;i++)
    {
        players[i].scores[3] = players[i].scores[0] + players[i].scores[1] + players[i].scores[2];
    }


    for(int i=0;i<numUsers-1;i++)
    {
        for(int j=i;j<numUsers;j++)
        {
            if(players[i].scores[3] < players[j].scores[3])
            {
                players[numUsers] = players[i];
                players[i] = players[j];
                players[j] = players[numUsers];
            }
        }
    }
    system("cls");
    printf("\n");
    printf("                                              88          88888888888        db        88888888ba,   88888888888 88888888ba  88888888ba    ,ad8888ba,        db        88888888ba  88888888ba,\n");
    printf("                                              88          88                d88b       88      `\"8b  88          88      \"8b 88      \"8b  d8\"'    `\"8b      d88b       88      \"8b 88      `\"8b\n");
    printf("                                              88          88               d8'`8b      88        `8b 88          88      ,8P 88      ,8P d8'        `8b    d8'`8b      88      ,8P 88        `8b\n");
    printf("                                              88          88aaaaa         d8'  `8b     88         88 88aaaaa     88aaaaaa8P' 88aaaaaa8P' 88          88   d8'  `8b     88aaaaaa8P' 88         88\n");
    printf("                                              88          88\"\"\"\"\"        d8YaaaaY8b    88         88 88\"\"\"\"\"     88\"\"\"\"88'   88\"\"\"\"\"\"8b, 88          88  d8YaaaaY8b    88\"\"\"\"88'   88         88\n");
    printf("                                              88          88            d8\"\"\"\"\"\"\"\"8b   88         8P 88          88    `8b   88      `8b Y8,        ,8P d8\"\"\"\"\"\"\"\"8b   88    `8b   88         8P\n");
    printf("                                              88          88           d8'        `8b  88      .a8P  88          88     `8b  88      a8P  Y8a.    .a8P d8'        `8b  88     `8b  88      .a8P\n");
    printf("                                              88888888888 88888888888 d8'          `8b 88888888Y\"'   88888888888 88      `8b 88888888P\"    `\"Y8888Y\"' d8'          `8b 88      `8b 88888888Y\"'\n");
    printf("\n\n");
    printf("_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|                   USERNAME                   |                 TIC-TAC-TOE                  |                 MINESWEEPER                  |                  BLACKJACK                   |                  TOTAL SCORE                  |");
    printf("|                                              |                    SCORE                     |                    SCORE                     |                    SCORE                     |                                               |");
    printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|           1.                                 |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|           2.                                 |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|           3.                                 |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|           4.                                 |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|           5.                                 |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|           6.                                 |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|           7.                                 |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|           8.                                 |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|           9.                                 |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|          10.                                 |                                              |                                              |                                              |                                               |");
    printf("|                                              |                                              |                                              |                                              |                                               |");
    printf("|______________________________________________|______________________________________________|______________________________________________|______________________________________________|_______________________________________________|");

    int temp = 19;
    if(numUsers > 10) numUsers = 10;
    for(int i=0;i<numUsers;i++)
    {
        gotoxy(15,temp);
        printf("%s",players[i].name);
        temp+=5;
    }
    temp = 19;
    for(int i=0;i<numUsers;i++)
    {
        gotoxy(69,temp);
        printf("%d", players[i].scores[0]);
        temp+=5;
    }
    temp = 19;
    for(int i=0;i<numUsers;i++)
    {
        gotoxy(116,temp);
        printf("%d", players[i].scores[1]);
        temp+=5;
    }
    temp = 19;
    for(int i=0;i<numUsers;i++)
    {
        gotoxy(163,temp);
        printf("%d", players[i].scores[2]);
        temp+=5;
    }
    temp = 19;
    for(int i=0;i<numUsers;i++)
    {
        gotoxy(210,temp);
        printf("%d", players[i].scores[3]);
        temp+=5;
    }

    getch();

}



/// SCREEN APPEREANCE ON LOAD EVENT
initMainScreen(){
   // int sizeX,sizeY;
    char option;

    changeResolution();
    changeConsoleToColors(1,15);

    //calcScreenSize(&sizeX,&sizeY);
    printMainInterface(&option);

    chooseOption(option);
    getch();

}


int main(int argc, char *argv[])
{
    screenSetting();
    initMainScreen();
    return 0;
}



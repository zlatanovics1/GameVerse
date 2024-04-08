#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>                //Used for srand((unsigned) time(NULL)) command
#include <process.h>             //Used for system("cls") command
#include <windows.h>

#define spade 06                 //Used to print spade symbol
#define club 05                  //Used to print club symbol
#define diamond 04               //Used to print diamond symbol
#define heart 03                 //Used to print heart symbol
#define RESULTS "Blackjack.txt"  //File name is Blackjack

//Global Variables
/*int k;
int l;
int d;
int won;
int loss;
int cash = 500;
int bet;
int random_card;
int player_total=0;
int dealer_total;*/

int player1Score;
int player2Score;
int player1Cash;
int player2Cash;
int i = 0;
int j = 0;
int firstPlay = 1;
int reverse = 0;
//Function Prototypes
/*int spadecard();     //Displays Spade Card Image
int betting();       //Asks user amount to bet
void asktitle();     //Asks user to continue
void rules();        //Prints "Rules of Vlad's Blackjack" menu
void play();         //Plays game
void dealer();       //Function to play for dealer AI
void stay();         //Function for when user selects 'Stay'
void cash_test();    //Test for if user has cash remaining in purse
void askover();      //Asks if user wants to continue playing
void fileresults();  //Prints results into Blackjack.txt file in program directory
*/
void logIntoGame();      //Two player log-in
void playGame();     //Starts game with two players
void printBlackJackTitle(); // Prints BlackJack title -- 8lines
void printRectArea(); // prints rectangle - player area
void updateScores(); // Prints score values
void displayRules(); // Displays rules for the game

typedef struct Player{
    char name[30];
    int cash;
    int score;
}Player;

void changeResolution(){

    DEVMODE devMode;
    ZeroMemory(&devMode, sizeof(devMode));
    devMode.dmSize = sizeof(devMode);
    devMode.dmPelsWidth = 1920;
    devMode.dmPelsHeight = 1080;
    devMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;

    LONG result = ChangeDisplaySettings(&devMode, CDS_FULLSCREEN);
}

void changeConsoleToColors()
 {

 system("COLOR 0B");
 return;
}


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

void gotoxy(int x,int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
}

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

void getCash(char user1[30],char user2[30]){
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

void copyFile(file1,file2){

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


void addCashAndScore(char user1[100],char user2[100])
    {

        FILE* file = fopen("blackjack.txt", "r");
        FILE* temp_file = fopen("temp.txt", "w");

        if(!file) {
            gotoxy(108,56);
            printf("DALJE NECES MOCI");
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


void printBlackJackTitle(){
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

void printRectArea(){
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

void updateScores(int score1, int score2){
    gotoxy(215,20);
    printf("SCORE: %d",score1);
    gotoxy(215,36);
    printf("SCORE: %d",score2);
}

void displayRules(){
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
        //return BlackJackLeaderboard();
        break;
     default:
        gotoxy(112,61);
        printf("Invalid input!");
        sleep(2);
        return printMainInterfaceBJ();
        break;
     }
}



void playBlackJack(){
    changeResolution();
    changeConsoleToColors();
    setConsoleFullscreen();

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


int randomCard(int *x, int *y, int playerScore){
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

void generatePad(int width,char text[50],char pad[50]){
    int i;
    for(i = 0; i < (width-strlen(text))/2; i++){
        pad[i] = ' ';
    }
    pad[i] = '\0';
}


void printGameInterface(char user1[30],char user2[30]){
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
    printf("        %d",i);
    gotoxy(121,16);
    printf("        %d",j);

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

void printUser(char user[30]){
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

void printCenteredText(char text[50],int width){
    char pad[50];
    int i;
    for(i = 0; i < (width - strlen(text))/2; i++){
        pad[i] = ' ';
    }
    pad[i] = '\0';
    printf("%s%s",pad,text);
}


void playGame(char user1[30],char user2[30]){

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
            /*do{
            gotoxy(110,57);
            printf("INVALID INPUT!");

            gotoxy(118,59);
            scanf("%c",&option);
            gotoxy(118,59);
            printf(" ");}
            while(option != 'H' && option != 'S');
            gotoxy(110,57);
            printf("                ");*/
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
            /*do{
            gotoxy(115,57);
            printf("INVALID INPUT!");

            gotoxy(118,59);
            scanf("%c",&option);
            gotoxy(118,59);
            printf(" ");}
            while(option != 'H' && option != 'S');
            gotoxy(110,57);
            printf("                ");*/
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
            /*do{
            gotoxy(110,57);
            printf("INVALID INPUT!");

            gotoxy(118,59);
            scanf("%c",&option);
            gotoxy(118,59);
            printf(" ");}
            while(option != 'H' && option != 'S');
            gotoxy(110,57);
            printf("                ");*/
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
        i++;
    }
    else if(player2Score == 21){
       // printf("%s won",user2);
        printCenteredText(user2Won,24);
        j++;
    }
    else if(player1Score < 21 && player1Score > player2Score){
        //printf("%s won",user1);
        printCenteredText(user1Won,24);
        i++;
    }
    else if(player2Score < 21 && player2Score > player1Score){
       // printf("%s won",user2);
        printCenteredText(user2Won,24);
        j++;
    }
    else if(player1Score > 21){
       // printf("%s won",user2);
        printCenteredText(user2Won,24);
        j++;
    }
    else{
       // printf("%s won",user1);
        printCenteredText(user1Won,24);
        i++;
    }}
    sleep(2);
    player1Score = player2Score = 0;
     while(i < 3 && j < 3){
        system("cls");
        playGame(user1,user2);
    }

    gotoxy(101,16);
    printf("        %d",i);
    gotoxy(121,16);
    printf("        %d",j);

    gotoxy(108,56);
    if(i == 3){
        player1Cash += bet2;
        player2Cash -= bet2;
        printCenteredText(user1Won,24);
    }
    if(j == 3){
        player2Cash += bet1;
        player1Cash -= bet1;
        printCenteredText(user2Won,24);

    }
    sleep(2);
    addCashAndScore(user1,user2);

    gotoxy(108,56);
    printCenteredText("New Game: 1  EXIT: 0 ",24);

    gotoxy(119,59);
    scanf("%s",&option);

    if(!strcmp(option,"1")){
            player1Score = player2Score = 0;
            firstPlay = 1;
            i = j = 0;
            return playGame(user1,user2);
    }
    else return printMainInterfaceBJ();

}


int main()
{
    playBlackJack();
    return(0);
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main()
{
    system("COLOR 20");
    srand(time(NULL));
    char a[50][200];
    //int bokluk[50][200];
    int x,y,br,brbokluk;

    for (y=0; y<50; y++)
    {
        printf("\n");
        for(x=0; x<200; x++)
        {
            if (y==0 || y==49) a[y][x]=' -';
            else{
                if (x==0 || x==199) a[y][x]=' |';
                else a[y][x]=' ';
            }
            printf("%c", a[y][x]);
        }
    }

    printf("\nHow much trash do you want to collect today?: ");
    scanf("%d",&brbokluk);

    for (int n=0; n<brbokluk; n++)
    {
    RandFunction(x,y,a);
    PrintArr(a);
    }

    printf("\nTova e vasheto choveche - 'O'");
    //printf("\nIzberete na kyde da se dvijite!");
    Choveche(y,x,a);
    PrintArr(a);

    do
    {
        br=Move(y,x,a);
        PrintArr(a);
    }while(br!=brbokluk);

}


int PrintArr(char a[50][200])
{
    int y,x;
    system("cls"); // za triene
    for (y=0; y<50; y++)
    {
        printf("\n");
        for(x=0; x<200; x++)
        {
            printf("%c", a[y][x]);
        }

    }
}

int RandFunction(int x, int y, char a[50][200])
{
    srand(time(NULL));
    do{
    x=rand()%197 + 1;
    y=rand()%47 + 1;
    }while(a[y][x]=='W' || a[25][100]!=' ');

    a[y][x]='W';
}

int Choveche(int y, int x, char a[50][200])
{
    char moves;
    //char o;
    //o = 'o|--C';
    a[25][100]='O';
    printf("\n");
}

int Move(int x, int y, char a[50][200])
{
    int k=0,br=0;
    /*x=100;
    y=25;*/
    char posoka;
    char searchLeft = 'a';
    char searchRight = 'd';
    char searchUp = 'w';
    char searchDown = 's';

    char searchLeftD = '1';
    char searchRightD = '2';
    char searchUpD = '3';
    char searchDownD = '4';

    printf("\nPosoka (1=10 v lqvo; 2=10 v dqsno; 3=10 nagore; 4=10 nadolu)\n a=1 v lqvo; d=1 v dqsno; w=1 nagore; s=1 nadolu: ");
    posoka=getchar();

    y=SearchOY(a);
    x=SearchOX(a);

        if (posoka == searchLeftD){
            if (a[y][x-10]=='X' || a[y][x-10]=='W') a[y][x-1]='O';
            a[y][x]=' ';
        }

        if (posoka == searchRightD){
            if (a[y][x+10]=='X' || a[y][x+10]=='W') a[y][x+1]='O';
            a[y][x]=' ';
        }

        if (posoka == searchUpD){
            if(a[y-10][x]=='X' || a[y-10][x]=='W') a[y-1][x]='O';
            a[y][x]=' ';
        }

        if (posoka == searchDownD){
            if(a[y+10][x]=='X' || a[y+10][x]=='W') a[y+1][x]='O';
            a[y][x]=' ';
        }

        if (posoka == searchLeft){
            if (a[y][x-1]=='W') {
                printf("You collected trash!");
                delay(2);
                a[y][x-1]='X';
                br++;
            }
            else if(a[y][x-1]=='X'){
            printf("\nYou are next to trash. You can't step on it!");
            a[y][x]='O';
            //a[y][x]=' ';
            } else if(a[y][x-1]==' '){
                a[y][x-1]='O';
                a[y][x]=' ';
            }
        }

        if (posoka == searchRight) {
            if (a[y][x+1]=='W'){
                printf("You collected trash!");
                delay(2);
                a[y][x+1]='X';
                br++;
            } else if(a[y][x+1]=='X')
            {
                printf("\nYou are next to trash. You can't step on it!");
                a[y][x]='O';
            } else if(a[y][x+1]==' '){
                a[y][x+1]='O';
                a[y][x]=' ';
            }
        }

        if (posoka == searchUp ) {
            if (a[y-1][x]=='W'){
                printf("You collected trash!");
                delay(2);
                a[y-1][x]='X';
                br++;
            } else if(a[y-1][x]=='X'){
                printf("\nYou are next to trash. You can't step on it!");
                a[y][x]='O';
            } else if(a[y-1][x]==' '){
                a[y-1][x]='O';
                a[y][x]=' ';
            }
        }

        if (posoka == searchDown ) {
            if (a[y+1][x]=='W'){
                printf("You collected trash!");
                delay(2);
                a[y+1][x]='X';
                br++;
            } else if(a[y+1][x]=='X'){
                printf("\nYou are next to trash! You can't step on it!");
                a[y][x]='O';
            } else if(a[y+1][x]==' '){
                a[y+1][x]='O';
                a[y][x]=' ';
            }
        }
        return br;
}

SearchOY(char a[50][200])
{
    int x,y;
    for (y=0;y<49;y++)
    {
        for (x=0; x<199; x++)
        {
            if (a[y][x]=='O') {
                return y;
                break;

            }
        }
    }
}

SearchOX(char a[50][200])
{
    int x,y;
    for (y=0;y<49;y++)
    {
        for (x=0; x<199; x++)
        {
            if (a[y][x]=='O') {
                return x;
                break;
            }
        }
    }
}

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

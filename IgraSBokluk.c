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

    Choveche(y,x,a);
    PrintArr(a);
    x=100;
    y=25;
    do
    {
        br=Move(x,y,a);
        PrintArr(a);
    }while(br!=brbokluk);

    do{
        RecycleBin(x,y,a);
        PrintArr(a);
    }while(a[y+1][x]!='S'||a[y+1][x]!='H'||a[y+1][x]!='P'||a[y][x-1]!='S'||a[y][x+1]=='H');
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
    char o;
    //o = 'o|--C';
    a[25][100]='O';
    printf("\n");
}

int Move(int x, int y, char a[50][200])
{
    int k=0,br=0;
    x=100;
    y=25;
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
            else {
            a[y][x-10]='O';
            a[y][x]=' ';
            }
        }

        if (posoka == searchRightD){
            if (a[y][x+10]=='X' || a[y][x+10]=='W') a[y][x+1]='O';
            else {
            a[y][x+10]='O';
            a[y][x]=' ';
            }
        }

        if (posoka == searchUpD){
            if(a[y-10][x]=='X' || a[y-10][x]=='W') a[y-1][x]='O';
            else {
            a[y-10][x]='O';
            a[y][x]=' ';
            }
        }

        if (posoka == searchDownD){
            if(a[y+10][x]=='X' || a[y+10][x]=='W') a[y+1][x]='O';
            else {
            a[y+10][x]='O';
            a[y][x]=' ';
            }
        }

        if (posoka == searchLeft)
        {
             if (a[y][x-1]=='W')
            {
                printf("You collected trash!");
                delay(2);
                a[y][x-1]='X';
                br++;
            }
             if(a[y][x-1]=='X'&&br>=1)
            {
                printf("You have already taken this trash! You can't step on it.");
                a[y][x]='O';
            }
             if(a[y][x-1]==' ')
             {
              a[y][x-1]='O';
              a[y][x]=' ';
             }
        }

        if (posoka == searchRight)
        {
            if (a[y][x+1]=='W')
            {
                printf("You collected trash!");
                delay(2);
                a[y][x+1]='X';
                br++;
            }
             if(a[y][x+1]=='X' && br>=1)
            {
                printf("You have already taken this trash! You can't step on it.");
                a[y][x]='O';
            }
             if(a[y][x+1]==' ')
            {
               a[y][x+1]='O';
               a[y][x]=' ';
            }
        }

        if (posoka == searchUp ) {
            if (a[y-1][x]=='W')
            {
                printf("You collected trash!");
                delay(2);
                a[y-1][x]='X';
                br++;
            }
            if(a[y-1][x]=='X' &&br>=1)
            {
                printf("You have already taken this trash! You can't step on it.");
                a[y][x]='O';
            }
            if(a[y-1][x]==' ')
            {
                a[y-1][x]='O';
                a[y][x]=' ';
            }
        }

        if (posoka == searchDown )
        {
            if (a[y+1][x]=='W'){
                printf("You collected trash!");
                delay(2);
                a[y+1][x]='X';
                br++;
            }
            if(a[y+1][x]=='X' && br>=1)
            {
                printf("You have already taken this trash! You can't step on it.");
                a[y][x]='O';
            }
            if(a[y+1][x]==' ')
            {
                a[y+1][x]='O';
                a[y][x]=' ';
            }
        }

        return br;
}

int RecycleBin(int x, int y, char a[50][200])
{
    char recpa='H';
    char recpl='P';
    char recgl='S';

    a[48][98]='H';
    a[48][100]='P';
    a[48][102]='S';

    char posoka;
    char searchLeft = 'a';
    char searchRight = 'd';
    char searchUp = 'w';
    char searchDown = 's';

    char searchLeftD = '1';
    char searchRightD = '2';
    char searchUpD = '3';
    char searchDownD = '4';
    printf("You collected all the trash! Now you have to put all of it in the recycle bin.");
    printf("\nPosoka (1=10 v lqvo; 2=10 v dqsno; 3=10 nagore; 4=10 nadolu)\n a=1 v lqvo; d=1 v dqsno; w=1 nagore; s=1 nadolu: ");
    posoka=getchar();
    y=SearchOY(a);
    x=SearchOX(a);


        if (posoka == searchLeftD){
            if (a[y][x-10]=='X' || a[y][x-10]=='W'||a[y][x-10]=='S') a[y][x-1]='O';
            else {
            a[y][x-10]='O';
            a[y][x]=' ';
            }
        }

        if (posoka == searchRightD){
            if (a[y][x+10]=='X' || a[y][x+10]=='W' || a[y][x+10]=='H') a[y][x+1]='O';
            else {
            a[y][x+10]='O';
            a[y][x]=' ';
            }
        }

        /*if (posoka == searchUpD){
            if(a[y-10][x]=='X' || a[y-10][x]=='W') a[y-1][x]='O';
            else {
            a[y-10][x]='O';
            a[y][x]=' ';
            }
        }*/

        if (posoka == searchDownD){
            if(a[y+10][x]=='X' || a[y+10][x]=='W' || a[y+10][x]=='H' || a[y+10][x]=='P' || a[y+10][x]=='S') a[y+1][x]='O';
            else {
            a[y+10][x]='O';
            a[y][x]=' ';
            }
        }

        if (posoka == searchLeft)
        {
             /*if (a[y][x-1]=='W')
            {
                printf("You collected trash!");
                delay(2);
                a[y][x-1]='X';
                br++;
            }
             if(a[y][x-1]=='X'&&br>=1)
            {
                printf("You have already taken this trash! You can't step on it.");
                a[y][x]='O';
            }*/
             if(a[y][x-1]=='S')
             {
                 printf("Congratulations! You have just thrown your trash in the recycle bin!");
                 a[y][x]='O';
             }
             if(a[y][x-1]==' ')
             {
              a[y][x-1]='O';
              a[y][x]=' ';
             }
        }

        if (posoka == searchRight)
        {
            /*if (a[y][x+1]=='W')
            {
                printf("You collected trash!");
                delay(2);
                a[y][x+1]='X';
                br++;
            }
             if(a[y][x+1]=='X' && br>=1)
            {
                printf("You have already taken this trash! You can't step on it.");
                a[y][x]='O';
            }*/
             if(a[y][x+1]=='H')
             {
                printf("Congratulations! You have just thrown your trash in the recycle bin!");
                a[y][x]='O';
             }
             if(a[y][x+1]==' ')
            {
               a[y][x+1]='O';
               a[y][x]=' ';
            }
        }

        /*if (posoka == searchUp ) {
            if (a[y-1][x]=='W')
            {
                printf("You collected trash!");
                delay(2);
                a[y-1][x]='X';
                br++;
            }
            if(a[y-1][x]=='X' &&br>=1)
            {
                printf("You have already taken this trash! You can't step on it.");
                a[y][x]='O';
            }
            if(a[y-1][x]==' ')
            {
                a[y-1][x]='O';
                a[y][x]=' ';
            }
        }*/

        if (posoka == searchDown )
        {
            /*if (a[y+1][x]=='W'){
                printf("You collected trash!");
                delay(2);
                a[y+1][x]='X';
                br++;
            }
            if(a[y+1][x]=='X' && br>=1)
            {
                printf("You have already taken this trash! You can't step on it.");
                a[y][x]='O';
            }*/
            if(a[y+1][x]=='H'||a[y+1][x]=='P'||a[y+1][x]=='S')
            {
                printf("Congratulations! You have just thrown your trash in the recycle bin!");
                a[y][x]='O';
            }
            if(a[y+1][x]==' ')
            {
                a[y+1][x]='O';
                a[y][x]=' ';
            }
        }

}

SearchOY(char a[50][200])
{
    int x,y;
    for (y=0;y<49;y++)
    {
        for (x=0; x<199; x++)
        {
            if (a[y][x]=='O')
            {
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
            if (a[y][x]=='O')
            {
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

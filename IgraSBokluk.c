#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
int main()
{
    system("COLOR 20");
    srand(time(NULL));
    char a[50][200];
    int bokluk[50][200];
    int x,y;

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

    for (int n=0; n<5; n++){
    RandFunction(x,y,a);

    PrintArr(a);
    }

    printf("\nTova e vasheto choveche!");
    printf("\nIzberete na kyde da se dvijite!");

    Choveche(y,x,a);
    PrintArr(a);
    Move(y,x,a);
    PrintArr(a);

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
    x=rand()%198;
    y=rand()%48;
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
    int k=0;
    x=25;
    y=25;
    char posoka;
    char searchLeft = 'a';
    char searchRight = 'd';
    char searchUp = 'w';
    char searchDown = 's';
    printf("\nPosoka: ");
    posoka=getchar();




        if (posoka == searchLeft) {

            a[y][x-1]='O';
            a[y][x]=' ';

        }

        if (posoka == searchRight) {

            a[y][x+1]='O';
            a[y][x]=' ';

        }

        if (posoka == searchUp ) {

            a[y-1][x]='O';
            a[y][x]=' ';

        }

        if (posoka == searchDown ) {

            a[y+1][x]='O';
            a[y][x]=' ';

        }

}











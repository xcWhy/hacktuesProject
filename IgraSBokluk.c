#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    srand(time(NULL));
    int a[50][200];
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

    for (int n=0; n<20; n++){
    RandFunction(x,y,a);

    PrintArr(a);
    }
    Choveche(y,x,a);

    PrintArr(a);
}


int PrintArr(int a[50][200])
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

int RandFunction(int x, int y, int a[50][200])
{
    srand(time(NULL));
    do{
    x=rand()%198;
    y=rand()%48;
    }while(a[y][x]=='W' || a[25][100]!=' ');

    a[y][x]='W';
}

int Choveche(int y, int x, int a[50][200])
{
    char moves;
    a[25][100]='o|--c';
    printf("\n");

    moves=getchar();
    switch(moves)
    {
        case w: y--;
        case s: y++;
        case a: x--;
        case d: x++;
    }

    printf(" O\n");
    printf("/|\");
    printf("\n/ ");
    printf("/ \");
    return 0;
}


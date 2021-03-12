#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    system("COLOR 2F");
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

    for (int n=0; n<20; n++){
    RandFunction(x,y,a);

    PrintArr(a);
    }

    printf("\nTova e vasheto choveche!");
    printf("Izberete na kyde da se dvijite!");

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
    char C;
    C='o|--C';
    a[25][100]=C;
    printf("\n");


}

int Move(int x, int y, int a[50][200])
{
    int k=0;
    char posoka;
    char searchLeft = "left";
    char searchRight = "right";
    char searchUp = "up";
    char searchDown = "down";
    printf("Posoka: ");
    posoka=getchar();

    char ptr1 = strstr(posoka, searchLeft);
    char ptr2 = strstr(posoka, searchRight);
    char ptr3 = strstr(posoka, searchUp);
    char ptr4 = strstr(posoka, searchDown);

    do{
        if (ptr1 != NULL) {
            a[y][x-1]='C';
            a[y][x]=' ';
            break;
        }

        if (ptr2 != NULL) {
            a[y][x+1]='C';
            a[y][x]=' ';
            break;
        }

        if (ptr3 != NULL) {
            a[y-1][x]='C';
            a[y][x]=' ';
        }

        if (ptr4 != NULL) {
            a[y+1][x]='C';
            a[y][x]=' ';
            break;
        }



}






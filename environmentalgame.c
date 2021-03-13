#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int PrintArr(char a[50][200]);
void CollectedTrash();

int main()
{
    system("COLOR 20");
    srand(time(NULL));
    char a[50][200];
    int x,y,br=0,brbokluk,Kbr=0,brhar,brplast,brglass;
    int brpap,brgl,brpl;
    char recpa='H';
    char recpl='P';
    char recgl='S';


    for (y=0; y<50; y++)
    {
        printf("\n");
        for(x=0; x<200; x++)
        {
            if (y==0 || y==49) a[y][x]='-';
            else{
                if (x==0 || x==199) a[y][x]='|';
                else a[y][x]=' ';
            }
            printf("%c", a[y][x]);
        }
    }

    a[48][98]='H';
    a[48][100]='P';
    a[48][102]='S';

    do{
    printf("\nHow much paper do you want to collect from the field: ");
    scanf("%d",&brhar);
    }while(brhar<1 || brhar>3000);

    do{
    printf("\nHow much plastic materials do you want to collect from the field?: ");
    scanf("%d",&brplast);
    }while(brplast<1 || brplast>3000);

    do{
    printf("\nHow much glass do you want to collect from the field?: ");
    scanf("%d",&brglass);
    }while(brglass<1 || brglass>3000);

    for (int n=0; n<brhar; n++)
    {
      RandFunctionHar(x,y,a);
      PrintArr(a);
    }

    for (int n=0; n<brplast; n++)
    {
      RandFunctionPlast(x,y,a);
      PrintArr(a);
    }

    for (int n=0; n<brglass; n++)
    {
      RandFunctionGlass(x,y,a);
      PrintArr(a);
    }

    Choveche(y,x,a);
    PrintArr(a);

    do{
        br=MoveHar(x,y,a);
        HasTrash(y,x,a,br);
        PrintArr(a);
    }while(br!=brpap);

    CollectedPap();

    do{
        br=MovePlast(x,y,a);
        HasTrash(y,x,a,br);
        PrintArr(a);
    }while(br!=brpl);

    CollectedPl();

    do
    {
        br=MoveGlass(x,y,a);
        HasTrash(y,x,a,br);
        PrintArr(a);
    }while(br!=brgl);

    CollectedGl();

    do{
        Kbr=RecycleBin(x,y,a);
        HasTrash(x,y,a,br);
        PrintArr(a);
    }while(Kbr!=1);
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

int RandFunctionHar(int x, int y, char a[50][200])
{
    srand(time(NULL));
    do{
    x=rand()%197 + 1;
    y=rand()%47 + 1;
    }while(a[y][x]=='H' || a[25][100]!=' ');
    a[y][x]='H';
}

int RandFunctionPlast(int x, int y, char a[50][200])
{
    srand(time(NULL));
    do{
    x=rand()%197 + 1;
    y=rand()%47 + 1;
    }while(a[y][x]=='P' || a[25][100]!=' ');
    a[y][x]='P';
}

int RandFunctionGlass(int x, int y, char a[50][200])
{
    srand(time(NULL));
    do{
    x=rand()%197 + 1;
    y=rand()%47 + 1;
    }while(a[y][x]=='G' || a[25][100]!=' ');
    a[y][x]='G';
}

int Choveche(int y, int x, char a[50][200])
{
    char moves;
    //char o;
    //o = 'o|--C';
    a[25][100]='O';
    printf("\n");
}

int MoveHar(int x, int y, char a[50][200])
{
    int brpap=0;
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
            if (a[y][x-10]=='X'||a[y][x-10]=='h'||a[y][x-10]=='H' || a[y][x-10]=='P' || a[y][x-10]=='G') a[y][x-1]='O';
            else {
            a[y][x-10]='O';
            a[y][x]=' ';
            }
        }

        if (posoka == searchRightD){
            if (a[y][x+10]=='X'||a[y][x+10]=='h'||a[y][x+10]=='H'||a[y][x+10]=='P'||a[y][x+10]=='G') a[y][x+1]='O';
            else {
            a[y][x+10]='O';
            a[y][x]=' ';
            }
        }

        if (posoka == searchUpD){
            if(a[y-10][x]=='X'||a[y-10][x]=='h'||a[y-10][x]=='H' || a[y-10][x]=='P' || a[y-10][x]=='G') a[y-1][x]='O';
            else {
            a[y-10][x]='O';
            a[y][x]=' ';
            }
        }

        if (posoka == searchDownD){
            if(a[y+10][x]=='X'||a[y+10][x]=='h'||a[y+10][x]=='H'||a[y+10][x]=='P'||a[y+10][x]=='G') a[y+1][x]='O';
            else {
            a[y+10][x]='O';
            a[y][x]=' ';
            }
        }

        if (posoka == searchLeft)
        {
             if (a[y][x-1]=='h')
            {
                printf("\nYou collected paper!");
                delay(2);
                a[y][x-1]='X';
                brpap++;
            }
             if(a[y][x-1]=='X'&&brpap>=1)
            {
                printf("\nYou have already taken this trash! You can't step on it.");
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
            if (a[y][x+1]=='h')
            {
                printf("\nYou collected paper!");
                delay(2);
                a[y][x+1]='X';
                brpap++;
            }
             if(a[y][x+1]=='X' && brpap>=1)
            {
                printf("\nYou have already taken this trash! \nYou can't step on it.");
                a[y][x]='O';
            }
             if(a[y][x+1]==' ')
            {
               a[y][x+1]='O';
               a[y][x]=' ';
            }
        }

        if (posoka == searchUp )
        {
            if (a[y-1][x]=='h')
            {
                printf("\nYou collected paper!");
                delay(2);
                a[y-1][x]='X';
                brpap++;
            }
            if(a[y-1][x]=='X' &&brpap>=1)
            {
                printf("\nYou have already taken this trash! You can't step on it.");
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
            if (a[y+1][x]=='h'){
                printf("\nYou collected paper!");
                delay(2);
                a[y+1][x]='X';
                brpap++;
            }
            if(a[y+1][x]=='X' && brpap>=1)
            {
                printf("\nYou have already taken this trash! You can't step on it.");
                a[y][x]='O';
            }
            if(a[y+1][x]==' ')
            {
                a[y+1][x]='O';
                a[y][x]=' ';
            }
        }
    return brpap;
}

int MovePlast(int x,int y,char a[50][200])
{
    int brpl=0;
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
            if (a[y][x-10]=='X'||a[y][x-10]=='p'||a[y][x-10]=='H' || a[y][x-10]=='P'||a[y][x-10]=='G') a[y][x-1]='O';
            else {
            a[y][x-10]='O';
            a[y][x]=' ';
            }
        }

        if (posoka == searchRightD){
            if (a[y][x+10]=='X'||a[y][x+10]=='p'||a[y][x+10]=='H'||a[y][x+10]=='P'||a[y][x+10]=='G') a[y][x+1]='O';
            else {
            a[y][x+10]='O';
            a[y][x]=' ';
            }
        }

        if (posoka == searchUpD){
            if(a[y-10][x]=='X'||a[y-10][x]=='p'||a[y-10][x]=='H'||a[y-10][x]=='P'||a[y-10][x]=='G') a[y-1][x]='O';
            else {
            a[y-10][x]='O';
            a[y][x]=' ';
            }
        }

        if (posoka == searchDownD){
            if(a[y+10][x]=='X'||a[y+10][x]=='p'||a[y+10][x]=='H'||a[y+10][x]=='P'||a[y+10][x]=='G') a[y+1][x]='O';
            else {
            a[y+10][x]='O';
            a[y][x]=' ';
            }
        }

        if (posoka == searchLeft)
        {
             if (a[y][x-1]=='p')
            {
                printf("\nYou collected plastic materials!");
                delay(2);
                a[y][x-1]='X';
                brpl++;
            }
             if(a[y][x-1]=='X'&&brpl>=1)
            {
                printf("\nYou have already taken this trash! You can't step on it.");
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
            if (a[y][x+1]=='p')
            {
                printf("\nYou collected plastic materials!");
                delay(2);
                a[y][x+1]='X';
                brpl++;
            }
             if(a[y][x+1]=='X' && brpl>=1)
            {
                printf("\nYou have already taken this trash! \nYou can't step on it.");
                a[y][x]='O';
            }
             if(a[y][x+1]==' ')
            {
               a[y][x+1]='O';
               a[y][x]=' ';
            }
        }

        if (posoka == searchUp ) {
            if (a[y-1][x]=='p')
            {
                printf("\nYou collected plastic materials!");
                delay(2);
                a[y-1][x]='X';
                brpl++;
            }
            if(a[y-1][x]=='X' &&brpl>=1)
            {
                printf("\nYou have already taken this trash! You can't step on it.");
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
            if (a[y+1][x]=='p'){
                printf("\nYou collected plastic materials!");
                delay(2);
                a[y+1][x]='X';
                brpl++;
            }
            if(a[y+1][x]=='X' && brpl>=1)
            {
                printf("\nYou have already taken this trash! You can't step on it.");
                a[y][x]='O';
            }
            if(a[y+1][x]==' ')
            {
                a[y+1][x]='O';
                a[y][x]=' ';
            }
        }
}

int MoveGlass(int x, int y, char a[50][200])
{
    int brgl=0;
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
            if (a[y][x-10]=='X' ||a[y][x-10]=='g'||a[y][x-10]=='H' || a[y][x-10]=='P' || a[y][x-10]=='G') a[y][x-1]='O';
            else {
            a[y][x-10]='O';
            a[y][x]=' ';
            }
        }

        if (posoka == searchRightD){
            if (a[y][x+10]=='X' ||a[y][x+10]=='g'||a[y][x+10]=='H' || a[y][x+10]=='P' || a[y][x+10]=='G') a[y][x+1]='O';
            else {
            a[y][x+10]='O';
            a[y][x]=' ';
            }
        }

        if (posoka == searchUpD){
            if(a[y-10][x]=='X'||a[y-10][x]=='g'||a[y-10][x]=='H'||a[y-10][x]=='P'||a[y-10][x]=='G') a[y-1][x]='O';
            else {
            a[y-10][x]='O';
            a[y][x]=' ';
            }
        }

        if (posoka == searchDownD){
            if(a[y+10][x]=='X'||a[y+10][x]=='g'||a[y+10][x]=='H'||a[y+10][x]=='P'||a[y+10][x]=='G') a[y+1][x]='O';
            else {
            a[y+10][x]='O';
            a[y][x]=' ';
            }
        }

        if (posoka == searchLeft)
        {
             if (a[y][x-1]=='g')
            {
                printf("\nYou collected glass!");
                delay(2);
                a[y][x-1]='X';
                brgl++;
            }
             if(a[y][x-1]=='X'&&brgl>=1)
            {
                printf("\nYou have already taken this trash! You can't step on it.");
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
            if (a[y][x+1]=='g'||a[y][x+1]=='p'||a[y][x+1]=='h')
            {
                printf("\nYou collected glass!");
                delay(2);
                a[y][x+1]='X';
                brgl++;
            }
             if(a[y][x+1]=='X' && brgl>=1)
            {
                printf("\nYou have already taken this trash! \nYou can't step on it.");
                a[y][x]='O';
            }
             if(a[y][x+1]==' ')
            {
               a[y][x+1]='O';
               a[y][x]=' ';
            }
        }

        if (posoka == searchUp ) {
            if (a[y-1][x]=='g'||a[y-1][x]=='p'||a[y-1][x]=='h')
            {
                printf("\nYou collected glass!");
                delay(2);
                a[y-1][x]='X';
                brgl++;
            }
            if(a[y-1][x]=='X'&&brgl>=1)
            {
                printf("\nYou have already taken this trash! You can't step on it.");
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
            if (a[y+1][x]=='g'||a[y+1][x]=='p'||a[y+1][x]=='h'){
                printf("\nYou collected glass!");
                delay(2);
                a[y+1][x]='X';
                brgl++;
            }
            if(a[y+1][x]=='X' && brgl>=1)
            {
                printf("\nYou have already taken this trash! You can't step on it.");
                a[y][x]='O';
            }
            if(a[y+1][x]==' ')
            {
                a[y+1][x]='O';
                a[y][x]=' ';
            }
        }
        return brgl;
}

/*int Move(int x, int y, char a[50][200])
{
    int k=0,br=0;

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
            if (a[y][x-10]=='X' ||a[y][x-10]=='g'||a[y][x-10]=='p'||a[y][x-10]=='h'||a[y][x-10]=='H' || a[y][x-10]=='P' || a[y][x-10]=='G') a[y][x-1]='O';
            else {
            a[y][x-10]='O';
            a[y][x]=' ';
            }
        }

        if (posoka == searchRightD){
            if (a[y][x+10]=='X' ||a[y][x+10]=='g'||a[y][x+10]=='p'||a[y][x+10]=='h'||a[y][x+10]=='H' || a[y][x+10]=='P' || a[y][x+10]=='G') a[y][x+1]='O';
            else {
            a[y][x+10]='O';
            a[y][x]=' ';
            }
        }

        if (posoka == searchUpD){
            if(a[y-10][x]=='X' ||a[y-10][x]=='g'||a[y-10][x]=='p'||a[y-10][x]=='h'||a[y-10][x]=='H' || a[y-10][x]=='P' || a[y-10][x]=='G') a[y-1][x]='O';
            else {
            a[y-10][x]='O';
            a[y][x]=' ';
            }
        }

        if (posoka == searchDownD){
            if(a[y+10][x]=='X'||a[y+10][x]=='g'||a[y+10][x]=='p'||a[y+10][x]=='h'||a[y+10][x]=='H'||a[y+10][x]=='P'||a[y+10][x]=='G') a[y+1][x]='O';
            else {
            a[y+10][x]='O';
            a[y][x]=' ';
            }
        }

        if (posoka == searchLeft)
        {
             if (a[y][x-1]=='g'||a[y][x-1]=='p'||a[y][x-1]=='h')
            {
                printf("\nYou collected trash!");
                delay(2);
                a[y][x-1]='X';
                br++;
            }
             if(a[y][x-1]=='X'&&br>=1)
            {
                printf("\nYou have already taken this trash! You can't step on it.");
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
            if (a[y][x+1]=='g'||a[y][x+1]=='p'||a[y][x+1]=='h')
            {
                printf("\nYou collected trash!");
                delay(2);
                a[y][x+1]='X';
                br++;
            }
             if(a[y][x+1]=='X' && br>=1)
            {
                printf("\nYou have already taken this trash! \nYou can't step on it.");
                a[y][x]='O';
            }
             if(a[y][x+1]==' ')
            {
               a[y][x+1]='O';
               a[y][x]=' ';
            }
        }

        if (posoka == searchUp ) {
            if (a[y-1][x]=='g'||a[y-1][x]=='p'||a[y-1][x]=='h')
            {
                printf("\nYou collected trash!");
                delay(2);
                a[y-1][x]='X';
                br++;
            }
            if(a[y-1][x]=='X' &&br>=1)
            {
                printf("\nYou have already taken this trash! You can't step on it.");
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
            if (a[y+1][x]=='g'||a[y+1][x]=='p'||a[y+1][x]=='h'){
                printf("\nYou collected trash!");
                delay(2);
                a[y+1][x]='X';
                br++;
            }
            if(a[y+1][x]=='X' && br>=1)
            {
                printf("\nYou have already taken this trash! You can't step on it.");
                a[y][x]='O';
            }
            if(a[y+1][x]==' ')
            {
                a[y+1][x]='O';
                a[y][x]=' ';
            }
        }

        return br;
}*/

 void HasTrash(int y, int x, char a[50][200],int br)
{
    if ((a[y-1][x]=='O' || a[y][x-1]=='O' || a[y][x+1]=='O') && br!=0)
    {
        printf("\nYou threw some paper!");
        delay(2);
        a[48][98]='H';
        a[y][x]='O';
    }

    if ((a[y-1][x]=='O' || a[y][x-1]=='O' || a[y][x+1]=='O') && br==0)
        {
             printf("\nYou don't have any trash with you! \nYou can't throw yourself - you are not from paper?!");
             delay(2);
        }


    if ((a[47][100]=='O' || a[48][99]=='O' || a[48][101]=='O') && br!=0){ //plastmasa
        printf("\nYou threw some plastic materials!");
        delay(2);
        a[48][100]='P';
        a[y][x]='O';
    }

    if ((a[47][100]=='O' || a[48][99]=='O' || a[48][101]=='O') && br==0){
            printf("\nYou don't have any trash with you! \nGo collect some, before I see you again here empty handed!");
            delay(2);
        }

    if ((a[47][101]=='O' || a[48][99]=='O' || a[48][103]=='O') && br!=0){ //styklo
        printf("\nYou threw some glass away!");
        delay(2);
        a[48][102]='S';
        a[y][x]='O';
    }

    if ((a[47][101]=='O' || a[48][99]=='O' || a[48][103]=='O') && br==0){
            printf("\nYou don't have any trash with you! \nYou are not from glass so don't throw yourself?!");
            delay(2);
        }
}

void CollectedPap()
{
    printf("\nYou collected all the paper! \nNow you have to put it in the recycle bin for paper.");
}

void CollectedPl()
{
    printf("\nYou collected all the plastic! \nNow you have to put it in the recycle bin for plastic.");
}

void CollectedGl()
{
    printf("\nYou collected all the glass! \nNow you have to put it in the recycle bin for glass.");
}

int RecycleBin(int x, int y, char a[50][200])
{
    int Kbr,k=0;
    char posoka;
    char searchLeft = 'a';
    char searchRight = 'd';
    char searchUp = 'w';
    char searchDown = 's';

    char searchLeftD = '1';
    char searchRightD = '2';
    char searchUpD = '3';
    char searchDownD = '4';

    delay(2);
    if (Kbr!=1) printf("\nPosoka (1=10 v lqvo; 2=10 v dqsno; 3=10 nagore; 4=10 nadolu)\n a=1 v lqvo; d=1 v dqsno; w=1 nagore; s=1 nadolu: ");
    posoka=getchar();
    y=SearchOY(a);
    x=SearchOX(a);


        if (posoka == searchLeftD){
            if (a[y][x-10]=='X'||a[y][x-10]=='g'||a[y][x-10]=='p'||a[y][x-10]=='h'||a[y][x-10]=='S'||a[y][x-10]=='H'||a[y][x-10]=='P') a[y][x-1]='O';
            else {
            a[y][x-10]='O';
            a[y][x]=' ';
            }
        }

        if (posoka == searchRightD)
        {
            if (a[y][x+10]=='X' || a[y][x+10]=='g'|| a[y][x+10]=='p'|| a[y][x+10]=='h' || a[y][x+10]=='H'||a[y][x-10]=='S'||a[y][x-10]=='P') a[y][x+1]='O';
            else {
            a[y][x+10]='O';
            a[y][x]=' ';
            }
        }

        if (posoka == searchDownD){
            if(a[y+10][x]=='X' || a[y+10][x]=='g'|| a[y+10][x]=='p'|| a[y+10][x]=='h' || a[y+10][x]=='H' || a[y+10][x]=='P' || a[y+10][x]=='S') a[y+1][x]='O';
            else {
            a[y+10][x]='O';
            a[y][x]=' ';
            }
        }

        if (posoka == searchLeft)
        {
             if(a[y][x-1]=='S')
             {
                 printf("\nCongratulations! You have just thrown your trash in the recycle bin!");
                 Kbr=1;
                 delay(5);
                 a[y][x]='O';
                 return Kbr;
             }
             if(a[y][x-1]==' ')
             {
              a[y][x-1]='O';
              a[y][x]=' ';
             }
        }

        if (posoka == searchRight)
        {
             if(a[y][x+1]=='H')
             {
                printf("Congratulations! You have just thrown your trash in the recycle bin!");
                Kbr=1;
                delay(5);
                a[y][x]='O';
                return Kbr;
             }
             if(a[y][x+1]==' ')
            {
               a[y][x+1]='O';
               a[y][x]=' ';
            }
        }

        if (posoka == searchDown )
        {
            if(a[y+1][x]=='H'||a[y+1][x]=='P'||a[y+1][x]=='S')
            {
                printf("Congratulations! You have just thrown your trash in the recycle bin!");
                Kbr=1;
                delay(5);
                a[y][x]='O';
                return Kbr;
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
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

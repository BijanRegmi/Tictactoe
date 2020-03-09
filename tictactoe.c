#include <stdio.h>
#include <stdlib.h>

void show(char(*)[3],int,int);
void update(char(*)[3],int,int,int);
int check(char(*)[3],int,int);
void line(int);

int main()
{
    char players[2][20];
    int win=0,p_turn=0,ctr=0;
    fflush(stdout);
    printf("ENTER PLAYER 1 NAME: ");
    scanf("%s",players[0]);
    system("clear");
    fflush(stdout);
    printf("ENTER PLAYER 2 NAME: ");
    scanf("%s",players[1]);
    system("clear");
    
    char data[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    while (win==0)
    {
        if ((ctr%2)==0)
        {
            p_turn=0;
        }
        else
        {
            p_turn=1;
        }
        show(data,3,3);
        printf("%s\n",players[p_turn]);
        update(data,3,3,p_turn);
        show(data,3,3);
        win=check(data,3,3);
        ctr++;
    }
    if (win==1)
        printf("%s won!",players[p_turn]);
    else
        printf("GAME DRAW");
}

void show(char (*data)[3],int p, int q)
{
    system("clear");
    int i,j;
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            printf("\t%c\t",data[i][j]);
            if (j!=2)
                printf("|");
        }
        printf("\n");
        if (i!=2)
            line(16*3);
        printf("\n");
    }
}

void update(char (*data)[3],int p, int q, int turn)
{
    char a[3]={'O','X'};
    int index,index_x,index_y;
    A:
    printf("\nCHOOSE YOUR BOX INDEX ");
    scanf("%d",&index);
    index_x=index/10;
    index_y=index%10;
    if (index_y>2 || index_y>2 || data[index_x][index_y]=='O' || data[index_x][index_y]=='X')
    {
        printf("INVALID INPUT!\n");
        goto A;
    }
    data[index_x][index_y]=a[turn];
}

int check(char (*data)[3],int p, int q)
{
    int i,win=0,c=0;
    
    
    
    //Vertical
    for (i=0;i<=2;i++)
    {
        if(  data[i][0] == data[i][1]  &&  data[i][0]==data[i][2]   &&  data[i][0] != ' '  )
        {
            return 1;
        }
    }
    win=0;
    
    //Horizontal
    for (i=0;i<=2;i++)
    {
        if(  data[0][i] == data[1][i]  &&  data[0][i]==data[2][i]   &&  data[0][i] !=  ' '  )
        {
            return 1;
        }
    }
    win=0;

    //Diagonal
    if( ( data[0][0] == data[1][1] && data[0][0] == data[2][2] && data[0][0] != ' ' ) || ( data[0][2] == data[1][1] && data[0][2] == data[2][0] && data[0][2] != ' ' ) )
        return 1;
    
    win=0;
    
    for (i=0;i<=2;i++)
    {
        for (int j=0;j<=2;j++)
        {
            if (data[i][j]!=' ')
                c++;
        }
    }
    if (c==9)
        return (-1);
    return win;
}

void line(int a)
{
    for (int i=0;i<a;i++)
        printf("-");
}

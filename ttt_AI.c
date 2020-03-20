#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define clear "\e[1;1H\e[2J"

void print_grid(char (*)[4]);
int check(char (*)[4]);
void update(char (*)[4],int);
int ai(char (*)[4]);

int main()
{
    int i,stat;
    char players[2][10]={"COMPUTER","HUMAN"};
    bool pl=1;
    char grid[4][4]={"   ","   ","   "};
    print_grid(grid);
    for (i=0;i<9;i++)
    {
        if (pl)
            update(grid,pl);
        else
            ai(grid);
        sleep(1);
        print_grid(grid);
        if (check(grid))
        {
            printf("%s WON!",players[pl]);
            break;
        }
        pl = !pl;
    }
    if (i == 9)
    {
        printf("GAME DRAW ");
    }
}

int ai (char (*grid)[4])
{
    int x,y;
    char temp[4][4];
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
            temp[i][j] = grid[i][j];
    }

    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            if (temp[i][j] == ' ')
            {
                //CHECKS OWN WIN
                temp[i][j]='O';
                if(check(temp))
                {
                    grid[i][j]='X';
                    return 0;
                }
                temp[i][j]=' ';
            }
        }
    }
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            if (temp[i][j] == ' ')
            {
                //CHECKS OTHERS WIN
                temp[i][j]='X';
                if(check(temp))
                {
                    grid[i][j]='O';
                    return 0;
                }
                temp[i][j]=' ';
            }
        }
    }
    
    do
    {
        srand(time(0));
        x = rand()%3;
        y = rand()%3;

    } while (temp[x][y]!=' ') ;
    grid[x][y] = 'O';

}

void update(char (*grid)[4], int turn)
{
    char a[3]={'O','X'};
    int ch[10]={0,00,01,02,10,11,12,20,21,22};
    int index,index_x,index_y,l;
    A:
    
    printf("\nCHOOSE YOUR BOX NUMBER ");
    scanf("%d",&l);

    index=ch[l];
    index_x=index/10;
    index_y=index%10;
    
    if (index_y>2 || index_y>2 || grid[index_x][index_y] != ' ')
    {
        printf("INVALID INPUT!\n");
        goto A;
    }
    grid[index_x][index_y]=a[turn];
}

void print_grid(char (*grid)[4])
{
    printf(clear);
    printf("  %c  |  %c  |  %c  \n",grid[0][0],grid[0][1],grid[0][2]);
    printf("-----------------\n");
    printf("  %c  |  %c  |  %c  \n",grid[1][0],grid[1][1],grid[1][2]);
    printf("-----------------\n");
    printf("  %c  |  %c  |  %c  \n",grid[2][0],grid[2][1],grid[2][2]);
    printf("\n");
}

int check(char (*grid)[4])
{
    for (int i=0;i<3;i++)
    {
        //HORIZONTAL
        if ( (grid[i][0] == grid[i][1]) && (grid[i][1] == grid[i][2]) && (grid[i][2] != ' ') )
            return 1;

        //VERTICAL
        if ( (grid[0][i] == grid[1][i]) && (grid[1][i] == grid[2][i]) && (grid[2][i] != ' ') )
            return 1;
    }

    //DIAGONALS
    if ( (grid[0][0] == grid[1][1]) && (grid[1][1] == grid[2][2]) && (grid[1][1] != ' ') )
        return 1;
    if ( (grid[0][2] == grid[1][1]) && (grid[1][1] == grid[2][0]) && (grid[2][0] != ' ') )
        return 1;
    return 0;
}

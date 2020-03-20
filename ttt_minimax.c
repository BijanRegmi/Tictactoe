#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define clear "\e[1;1H\e[2J"

void grid_print(char(*)[4]);
void human(char(*)[4]);
void computer(char (*)[4]);
int check(char (*)[4]);
int minimax(char (*)[4],int);

int main()
{
    bool player=1;
    int i;
    char grid[4][4]={"   ","   ","   "},names[2][10]={"COMPUTER","HUMAN"};
    grid_print(grid);
    for (i=0;i<9;i++)
    {
        if(player)
            human(grid);
         else
            computer(grid);
        
        grid_print(grid);
        if (check(grid) == 1 || check(grid) == -1)
        {
            printf("%s IS THE WINNER!\n",names[player]);
            break;
        }
        player = !player;
    }
    if (i == 9)
        printf("GAME DRAW ");
}

void computer(char (*grid)[4])
{
    int i,j,pt,bpt=-20,index_x,index_y;
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            if (grid[i][j] == ' ')
            {
                grid[i][j]='O';
                pt=minimax(grid,0);
                grid[i][j]=' ';
                if(pt>bpt)
                {
                    bpt=pt;
                    index_x=i;
                    index_y=j;
                }
            }
        }
    }
    grid[index_x][index_y]='O';
}

int minimax(char (*grid)[4],int ismax)
{
    int score,i,j,pt;
    score = check(grid);
    if (score != 0)
    {
        return score;
    }
    if (ismax)      //maximizer
    {
        int bpt = -1;
        for (i=0;i<3;i++)
        {
            for (j=0;j<3;j++)
            {
                if (grid[i][j] == ' ')
                {
                    grid[i][j] = 'O';
                    pt = minimax(grid,0);
                    grid[i][j] = ' ';
                    if (pt>bpt)
                    {
                        bpt = pt;
                    }
                }
            }
        }
        return bpt;
    }
    else        //minimizer
    {
        int bpt = 1;
        for (i=0;i<3;i++)
        {
            for (j=0;j<3;j++)
            {
                if (grid[i][j] == ' ')
                {
                    grid[i][j] = 'X';
                    pt = minimax(grid,1);
                    grid[i][j] = ' ';
                    if (pt<bpt)
                    {
                        bpt = pt;
                    }
                }
            }
        }
        return bpt;
    }
}

void grid_print(char (*grid)[4])
{
    printf(clear);
    sleep(1);
    printf("  %c  |  %c  |  %c  \n",grid[0][0],grid[0][1],grid[0][2]);
    printf("-----------------\n");
    printf("  %c  |  %c  |  %c  \n",grid[1][0],grid[1][1],grid[1][2]);
    printf("-----------------\n");
    printf("  %c  |  %c  |  %c  \n",grid[2][0],grid[2][1],grid[2][2]);
}

void human(char (*grid)[4])
{
    int n,ch[10]={0,00,01,02,10,11,12,20,21,22},index,index_x,index_y;
    
    A:
    printf("\nCHOOSE YOUR BOX NUMBER ");
    scanf("%d",&n);
    
    index=ch[n];
    index_x=index/10;
    index_y=index%10;
    if (index_x>2 || index_y>2 || grid[index_x][index_y]!=' ')
    {
        printf("INVALID INPUT!\n");
        goto A;
    }
    grid[index_x][index_y]='X';
}

int check(char (*grid)[4])
{
    int c=0;        //counter for checking if game is over or not
    for (int i=0;i<3;i++)
    {
        //HORIZONTAL
        if ( (grid[i][0] == grid[i][1]) && (grid[i][1] == grid[i][2]) && (grid[i][0] != ' ') )
        {
            if (grid[i][0] == 'X')
                return -1;
            else
                return 1;
        }
        //VERTICAL
        if ( (grid[0][i] == grid[1][i]) && (grid[1][i] == grid[2][i]) && (grid[0][i] != ' ') )
        {
            if (grid[0][i] == 'X')
                return -1;
            else
                return 1;
        }
    }

    //DIAGONAL
    if ( ((grid[0][0] == grid[1][1]) && (grid[1][1] == grid[2][2]) && (grid[0][0] != ' ')) || ((grid[0][2] == grid[1][1]) && (grid[1][1] ==grid[2][0]) && (grid[1][1] != ' ')) )
    {
        if (grid[1][1] == 'X')
            return -1;
        else
            return 1;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(grid[i][j] != ' ')
                c++;
        } 
    }
    if(c == 9)
        return 78;      //random number telling game is tied
    else
        return 0;       //number telling the game is still to be finished
}

#include <stdio.h>

#define clear "\e[1;1H\e[2J"

void print_grid(char (*)[4]);
int check(char (*)[4]);
void update(char (*)[4],int);

int main()
{
    int i,stat;
    char players[2][10]={"Player 1","Player 2"};
    bool pl=1;
    char grid[4][4]={"   ","   ","   "};
    for (i=0;i<9;i++)
    {
        print_grid(grid);
        update(grid,pl);
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

void ai (char (*grid)[4])
{
    char temp[4][4];
}

void update(char (*grid)[4], int turn)
{
    char a[3]={'O','X'};
    int index,index_x,index_y;
    A:
    
    printf("\nCHOOSE YOUR BOX INDEX ");
    scanf("%d",&index);

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

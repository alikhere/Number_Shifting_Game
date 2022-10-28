#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
void Gamerule();
void ShowArray(int[][4]);
void RandomArray(int[][4]);
char ReadChar();
void LShift(int[][4], int*);
void RShift(int[][4], int*);
void UpShift(int[][4], int*);
void DownShift(int[][4], int*);
void swap(int*,int*);
int win(int[][4]);

int main()
{
    int array[4][4],move;
    char name[20],key;
    system("cls");
    printf("Enter Name: ");
    gets(name);
    system("cls");
    Gamerule();
    while(1)
    {   move=20;
        RandomArray(array);
        while(!win(array))
        {   system("cls");
            printf("\t \t \t \t \t \t Player Name: %s , Move remaining : %d",name,move);
            ShowArray(array);
            fflush(stdin);
            key=ReadChar();
            switch(key)
            {
                case 77:
                   RShift(array,&move);  //Right arrow
                   move--;
                   break;

                case 75:
                   LShift(array,&move);   //Left arrow
                   move--;
                   break;

                case 72:
                   UpShift(array,&move);  //Up arrow
                   move--;
                   break;

                case 80:
                   DownShift(array,&move);   //down arrow
                   move--;
                   break;   

                case 'e':
                case 'E':
                   system("cls");
                   printf("\n\n\t \t \t \t \t \t \t***ThankYou for Playing***\n"); 
                   printf("\t \t \t  \t \t \t \t Press Enter to Exit game\n\n");
                   fflush(stdin);
                   key=ReadChar();
                   if(key='\n')
                   {
                    system("cls");
                    return 0;
                   }
                    else
                    break;
              
                default:
                   printf("\nNot Alloyed \n");
            } 
            if(!move)
             break;

        }
        system("cls");
        if(!move)
        {
        printf("\t \t \t \t \t \t \t \t  You Lose !\n\n");
        printf("\nYou want to play again ?\n");
        printf("Enter y to play again and e to exit :\n");
        fflush(stdin);
        key=ReadChar();
        if(key=='e' || key=='E')
        {
         system("cls");
         return 0;
        }
        }
        else
        {
        printf("\t \t \t \t \t \t \t   Congratulation \n \t \t \t \t \t  \t \t \t   You Win !");
        printf("\nYou want to play again ?\n");
        printf("Enter y to play again and e to exit :\n");
        fflush(stdin);
        key=ReadChar();
        if(key=='e' || key=='E')
        {
         system("cls");
         return 0;
        }
        }

    }
    return 0;
}

void Gamerule()
{
    int i,j,a[4][4],count=1,c;
    printf("\t \t \t \t \t  \t   MATRIX PUZZEL\n");
    printf("\t \t \t  \t \t \t***RULES OF GAME***\n\n");
    printf("1. You can move only 1 steps at a time by arrow key\n");
    printf("\t Move Up: by Up arrow key\n\t Move Down: by Down arrow key\n\t Move Left: by Left arrow key\n\t Move Right: by RIght arrow key\n");
    printf("2. You can move number at empty position only\n");
    printf("3. For each valid move : your total number of move will decrease by 1 \n");
    printf("4. Winning situation   : Number in 4x4 matrix should be in order from 1 to 15\n\n");
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            a[i][j]=count;
            count++;
        }
    }
    a[3][3]=0;
    printf("\t \t \t \t \t \t \t   Winning Situation \n");
    ShowArray(a);
    printf("\n5. You can exit the game at any time by pressing 'E' or 'e'\n   So Try to win in minimum no of move.\n\n");
    printf("Enter any key to start....");
    getch();
    system("cls");


}

void ShowArray(int a[][4])
{
    int i,j;
    printf("\n\n \t \t \t \t \t \t \t ---------------------\n");
    for(i=0;i<4;i++)
    {
        printf("\t \t \t \t \t \t \t");
        for(j=0;j<4;j++)
        {
            if(a[i][j]!=0)
            printf(" | %2d",a[i][j]);
            else
            printf(" |   ");
        }
        printf(" |\n");
    }
    printf(" \t \t \t \t \t \t \t ---------------------\n");
}

void RandomArray(int arr[][4])
{
    int i,j,b[15],temp,index;
    for(i=0;i<15;i++)
      b[i]=i+1;
    index=14;
    srand(time(0));
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(i!=3 || j!=3)
            {
                temp=rand()%(index+1);
                arr[i][j]=b[temp];
                b[temp]=b[index--];
            }
            else
            arr[i][j]=0;
        }
    }
}

char ReadChar()
{
    char c;
    c=getch();
    if(c==0  || c==0xE0)
    c=getch;
    return c;
}

void RShift(int a[][4], int *p)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j]==0)
            {
                if(j>0)
                swap(&a[i][j],&a[i][j-1]);
                else
                {
                (*p)++;
                printf("\nNot Allowed\n");
                }
            }   

        }
    }

}

void LShift(int a[][4], int *p)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j]==0)
            {
                if(j<3)
                swap(&a[i][j],&a[i][j+1]);
                else
                {
                (*p)++;
                printf("\nNot Allowed\n");
                }
            }   

        }
    }

}

void UpShift(int a[][4], int *p)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j]==0)
            {
                if(i<3)
                swap(&a[i][j],&a[i+1][j]);
                else
                {
                (*p)++;
                printf("\nNot Allowed\n");
                }
                
            }   

        }
    }

}

void DownShift(int a[][4], int *p)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[i][j]==0)
            {
                if(i>0)
                swap(&a[i][j],&a[i-1][j]);
                else
                {
                (*p)++;
                printf("\nNot Allowed\n");
                }
            }   

        }
    }

}

void swap(int *p, int *q)
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}

int win(int a[][4])
{
    int i,j,count=1;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(i!=3 || j!=3)
            {
            if(a[i][j]!=count)
            return 0;
            count++;
            }
        }
    }
    return 1;
}


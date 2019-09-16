/*
	Tic Tac Toe Game
	Created By-  
				Tarun 
				B.tech.(CSE) 
				Ist Year
				Gla University,Mathura
	University Roll No.-181500756			
*/

#include"stdio.h"
#include"time.h"

/*
	Prototypes Of All Functions Used In Game
*/

int display(char(*)[3],int,int);
int instruction();
int delay(int);
int game_algo(char(*)[3]);
int check(char (*)[3],char,int);
int check_l_diag(char (*)[3],char);
int check_r_diag(char (*)[3],char);
int hori(char (*)[3],char,int);
int ver(char (*)[3],char,int);

int main(){
	char p[3][3]={0};
	int chance=9;
	instruction();
	game_algo(p);
	return 0;
}

/*
	Function To Display Matrix
*/
int display(char (*p)[3],int pos_i,int pos_j){
	int i ,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			{
				if(p[i][j]==0)
					if(i==pos_i && j==pos_j)
						printf("  ");
					else	
						printf("_ ");
				else
					printf("%c ",p[i][j]);	
			}
		printf("\n");
	}
	return 0;
}

/*
	Function To Display Instruction Of Game
*/

int instruction(){
	int t=2;
	while(t){
		printf("It is Tic Tac Toe Game\n");
		printf("Rules Are Same As Of Your Childhood\n");
		printf("Instruction To Play Are----\n");
		printf("---->Press W for moving up.\n");
		printf("---->Press S for moving down.\n");
		printf("---->Press A for moving left.\n");
		printf("---->Press D for moving right.\n");
		printf("---->Enter Your Corresponding Symbols To Play Game.\n");
		printf("---->Game Will Always Start With Player Having Symbol 'x'\n");
		printf("Game Starts In %d",t--);
		delay(1);
		system("cls");
	}
	return 0;
}

/*
	Function To Delay Time
*/

int delay(int t){
	int time_in_millisecond=1000*t;
	int start_time=clock();
	while(clock()<=start_time+time_in_millisecond);
	return 0;
}

/*
	Function Containing Algorithm Of Game
*/

int game_algo(char (*a)[3])
{
	int chance=9;
	time_t te;
	int pos_i=0,pos_j=0,alt=0;
	char player_name[2];
	printf("Player 1 Enter Name...");
	scanf("%s",&player_name[0]);
	printf("Player 2 Enter Name...");
	scanf("%s",&player_name[1]);
	srand((unsigned) time(&te));
	int t=1+rand() % 2;
	if(t==1)
		printf("Player One Symbol Is 'x' \nPlayer Two Symbol Is 'o'\n");
	else
		printf("Player One Symbol Is 'o' \nPlayer Two Symbol Is 'x'\n");	
	char temp;
	while(chance)
	{
		display(a,pos_i,pos_j);
		char ch=getch();
		system("cls");
		if(ch=='W'||ch=='w'||ch=='S'||ch=='s'||ch=='a'||ch=='A'||ch=='d'||ch=='D')
		{
					if(ch=='w'||ch=='W')
						{
							if(pos_i>0)
								pos_i--;
						
						}
					else if(ch=='s'||ch=='S')
						{
							if(pos_i<2)
									pos_i++;
						}	
					else if(ch=='a'||ch=='A')
						{
							if(pos_j>0)
									pos_j--;
						}	
					else if(ch=='d'||ch=='D')
						{
							if(pos_j<2)
									pos_j++;	
						}
		}
		else if(ch=='x' && alt==0)
			{
				if (a[pos_i][pos_j]=='x' || a[pos_i][pos_j]=='o')
						{
							printf("Place Already Occupied \n");
							chance+=1;
						}
				else	
					{
						a[pos_i][pos_j]='x';
						alt=1;
					}
				if(chance<=5)
					if(check(a,'x',t)==1)
						{
							display(a,0,0);
							goto ab;
						}
				chance--;
			}
			else if(ch=='o' && alt==1)
				{
					if (a[pos_i][pos_j]=='x' || a[pos_i][pos_j]=='o')
						{
							printf("Place Already Occupied \n");
							chance+=1;
						}
					else
						{
							a[pos_i][pos_j]='o';
							alt=0;
						}
					if(chance<=5)
						if(check(a,'o',t)==1)
							{
								display(a,0,0);
								goto ab;
							}
								
					chance--;
				}
				else
					printf("Invalid Input\n");
	}
	display(a,0,0);
	printf("It's A Draw");
	ab:return 0;
}

/*
	Function To Check Which Player Is Winner
*/

int check(char (*p)[3],char c,int t)
	{
		if(check_r_diag(p,c))
			if (c=='x')
				{
					if(t==1)
						printf("Player 1 Wins\n");
					else
						printf("Player 2 Wins\n");
					return 1;
				}
			else if	(c=='o')
					{
						if(t==1)
							printf("Player 2 Wins\n");
						else
							printf("Player 1 Wins\n");
						return 1;
					}
					
		if(check_l_diag(p,c))
			if (c=='x')
				{
					if(t==1)
						printf("Player 1 Wins\n");
					else
						printf("Player 2 Wins\n");
					return 1;
				}
			else if	(c=='o')
					{
						if(t==2)
							printf("Player 2 Wins\n");
						else
							printf("Player 1 Wins\n");
						return 1;
					}
		
		if(hori(p,c,1))
			if (c=='x')
				{
					if(t==1)
						printf("Player 1 Wins\n");
					else
						printf("Player 2 Wins\n");
					return 1;
				}
			else if	(c=='o')
					{
						if(t==2)
							printf("Player 2 Wins\n");
						else
							printf("Player 1 Wins\n");
						return 1;
					}	
		
		if(ver(p,c,1))
			if (c=='x')
				{
					if(t==1)
						printf("Player 1 Wins\n");
					else
						printf("Player 2 Wins\n");
					return 1;
				}
			else if	(c=='o')
					{
						if(t==2)
							printf("Player 1 Wins\n");
						else
							printf("Player 2 Wins\n");
						return 1;
					}					
		
		if(hori(p,c,0))
			if (c=='x')
				{
					if(t==1)
						printf("Player 1 Wins\n");
					else
						printf("Player 2 Wins\n");
					return 1;
				}
			else if	(c=='o')
					{
						if(t==2)
							printf("Player 2 Wins\n");
						else
							printf("Player 1 Wins\n");
						return 1;
					}
					
		if(hori(p,c,2))
			if (c=='x')
				{
					if(t==1)
						printf("Player 1 Wins\n");
					else
						printf("Player 2 Wins\n");
					return 1;
				}
			else if	(c=='o')
					{
						if(t==2)
							printf("Player 2 Wins\n");
						else
							printf("Player 1 Wins\n");
						return 1;
					}
					
		if(ver(p,c,0))
			if (c=='x')
				{
					if(t==1)
						printf("Player 1 Wins\n");
					else
						printf("Player 2 Wins\n");
					return 1;
				}
			else if	(c=='o')
					{
						if(t==2)
							printf("Player 2 Wins\n");
						else
							printf("Player 1 Wins\n");
						return 1;
					}
					
		if(ver(p,c,2))
			if (c=='x')
				{
					if(t==1)
						printf("Player 1 Wins\n");
					else
						printf("Player 2 Wins\n");
					return 1;
				}
			else if	(c=='o')
					{
						if(t==2)
							printf("Player 2 Wins\n");
						else
							printf("Player 1 Wins\n");
						return 1;
					}									
	}


/*
	Below This , All Functions Are Used To Check The That Any Order Is Formed Or Not
*/

int check_r_diag(char (*p)[3],char c)
	{
		if(p[1][1]==c && p[0][2]==c && p[2][0]==c)
			return 1;
		else
			return 0;	
	}
	
int check_l_diag(char (*p)[3],char c)
	{
		if(p[1][1]==c && p[0][0]==c && p[2][2]==c)
			return 1;
		else
			return 0;	
	}	
	
int hori(char (*p)[3],char c,int pos_i)
	{
		if(p[pos_i][0]==c && p[pos_i][1]==c && p[pos_i][2]==c)
			return 1;
		else
			return 0;	
	}

int ver(char (*p)[3],char c,int pos_j)
	{
		if(p[0][pos_j]==c && p[1][pos_j]==c && p[2][pos_j]==c)
			return 1;
		else
			return 0;	
	}

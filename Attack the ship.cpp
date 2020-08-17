#include <iostream>
#include <fstream>
#include <cctype>
#include <time.h>
using namespace std;

class board
{
	int ns,na,nm,a;
public:
	char b[10][10];
	board()
	{
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				b[i][j]='o';
			}
		}
	}
	int doAttack(int r,int c);

	void boardUpdate(int r,int c,int n);
	void viewBoard();


}o,p;
void board::boardUpdate(int r,int c,int n)
{
    		b[r][c]='S';
            p.ns=n;
}
int board::doAttack(int r,int c)
{
	if(o.b[r][c]=='S')
	{
		cout<<"You have hit a ship!\n";
		p.b[r][c]='H';
		o.b[r][c]='H';
		p.ns--;
	}
	else if(o.b[r][c]=='o')
	{
		cout<<"You have missed!\n";
		p.b[r][c]='M';
		o.b[r][c]='M';
	}
	else if(o.b[r][c]=='M')
	{
		cout<<"You have already missed this location, try again!\n";
	}
	else if(o.b[r][c]=='H')
	{
		cout<<"You already sunk this ship, try again!\n";
	}
	return p.ns;

}
void board::viewBoard()
{
	cout<<"    "<<0<<" "<<1<<" "<<2<<" "<<3<<" "<<4<<" "<<5<<" "<<6<<" "<<7<<" "<<8<<" "<<9<<endl;
	cout<<"  |---------------------|"<<endl;
	cout<<"A | "<<b[0][0]<<" "<<b[0][1]<<" "<<b[0][2]<<" "<<b[0][3]<<" "<<b[0][4]<<" "<<b[0][5]<<" "<<b[0][6]<<" "<<b[0][7]<<" "<<b[0][8]<<" "<<b[0][9]<<" |"<<endl;
	cout<<"B | "<<b[1][0]<<" "<<b[1][1]<<" "<<b[1][2]<<" "<<b[1][3]<<" "<<b[1][4]<<" "<<b[1][5]<<" "<<b[1][6]<<" "<<b[1][7]<<" "<<b[1][8]<<" "<<b[1][9]<<" |"<<endl;
	cout<<"C | "<<b[2][0]<<" "<<b[2][1]<<" "<<b[2][2]<<" "<<b[2][3]<<" "<<b[2][4]<<" "<<b[2][5]<<" "<<b[2][6]<<" "<<b[2][7]<<" "<<b[2][8]<<" "<<b[2][9]<<" |"<<endl;
	cout<<"D | "<<b[3][0]<<" "<<b[3][1]<<" "<<b[3][2]<<" "<<b[3][3]<<" "<<b[3][4]<<" "<<b[3][5]<<" "<<b[3][6]<<" "<<b[3][7]<<" "<<b[3][8]<<" "<<b[3][9]<<" |"<<endl;
	cout<<"E | "<<b[4][0]<<" "<<b[4][1]<<" "<<b[4][2]<<" "<<b[4][3]<<" "<<b[4][4]<<" "<<b[4][5]<<" "<<b[4][6]<<" "<<b[4][7]<<" "<<b[4][8]<<" "<<b[4][9]<<" |"<<endl;
	cout<<"F | "<<b[5][0]<<" "<<b[5][1]<<" "<<b[5][2]<<" "<<b[5][3]<<" "<<b[5][4]<<" "<<b[5][5]<<" "<<b[5][6]<<" "<<b[5][7]<<" "<<b[5][8]<<" "<<b[5][9]<<" |"<<endl;
	cout<<"G | "<<b[6][0]<<" "<<b[6][1]<<" "<<b[6][2]<<" "<<b[6][3]<<" "<<b[6][4]<<" "<<b[6][5]<<" "<<b[6][6]<<" "<<b[6][7]<<" "<<b[6][8]<<" "<<b[6][9]<<" |"<<endl;
	cout<<"H | "<<b[7][0]<<" "<<b[7][1]<<" "<<b[7][2]<<" "<<b[7][3]<<" "<<b[7][4]<<" "<<b[7][5]<<" "<<b[7][6]<<" "<<b[7][7]<<" "<<b[7][8]<<" "<<b[7][9]<<" |"<<endl;
	cout<<"I | "<<b[8][0]<<" "<<b[8][1]<<" "<<b[8][2]<<" "<<b[8][3]<<" "<<b[8][4]<<" "<<b[8][5]<<" "<<b[8][6]<<" "<<b[8][7]<<" "<<b[8][8]<<" "<<b[8][9]<<" |"<<endl;
	cout<<"J | "<<b[9][0]<<" "<<b[9][1]<<" "<<b[9][2]<<" "<<b[9][3]<<" "<<b[9][4]<<" "<<b[9][5]<<" "<<b[9][6]<<" "<<b[9][7]<<" "<<b[9][8]<<" "<<b[9][9]<<" |"<<endl;
	cout<<"  |---------------------|\n"<<endl;
}

int main()
{
	int n,c,i,r1,j,n1;
	char r,r2;
	ifstream file;
	file.open("shipData.txt");
	i=0;
	file>>n;
	n1=n;
	if(n>8||n<0)
	{
		cout<<"“Invalid number of ships”";
		return 0;
	}
	while(n1--)
	{
		file>>r>>c;
		r=toupper(r);
		r1=r-'A';
		o.boardUpdate(r1,c,n);
	}
	cout<<"Welcome to the game of Battleship.\n\n";
	cout<<"You can choose to play this game or let the computer play.\n\n";
	cout<<"You will have a 10 x 10 board and up to 8 ships at any round.You can request to view the original board containing ship coordinates up to 3 times.\n\n";
	cout<<"Choose coordinates and attack the ships. You have 3 guesses for each ship. Successfully destroy all ships to win the game.\n\n";
	cout<<"For each attack provide two inputs:\n";
	cout<<"row (A-J), column (0-9)\n\n";
	cout<<"Reading ships and coordinates\n";
	cout<<"You can't place more than 8 ships on a board.\n\n";
	cout<<"Reading each ship coordinates:\n";
	int t=3*n,t1=0,ns,d=0;
	while(t--)
	{
	    if(t1<3)
		{
		    cout<<"\n\n\nView the original board?  ";
            cin>>r;
            if(r=='Y'||r=='y')
            {
			cout<<"        Original view\n";

				o.viewBoard();
				t1++;
            }
            else if(r=='X'||r=='x')
            {
            return 0;
            }
		}
		cout<<"        Player view\n";
		p.viewBoard();
		if(d==0)
		{
            d=1;
		    cout<<"Do you want to play? ";
            cin>>r2;
		}

		    if(r2=='y'||r2=='Y')
		{
			cout<<"Enter the coordinate for attack: ";
			cin>>r>>c;
            if(r=='X'||r=='x')
            {
                return 0;
            }
			r=toupper(r);
			r1=r-'A';

			while(r1<0||c<0||r1>9||c>9)
			{
				cout<<"“Invalid coordinates. Please try again!”\n";
				cin>>r>>c;
			}

		}
        else if(r2=='X'||r2=='x')
        {
            return 0;
        }
        else if (r2=='N'||r2=='n')
        {
            srand(time(0));
            r1=rand()%10;
            c=rand()%10;
        }

        ns=p.doAttack(r1,c);

        if(3*ns<t)
        {
            t=3*ns;
        }

        if(ns==0)
        {
            p.viewBoard();
            cout<<"Congratulations! You won!\n";
            cout<<"Thanks for playing. Exiting...";
            return 0;
        }


	}
        if(ns!=0&&t==0)
        {
            cout<<"Sorry! You ran out of turns.";
        }

}

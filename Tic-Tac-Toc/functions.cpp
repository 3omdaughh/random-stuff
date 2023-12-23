#include "functions.h"

char board[3][3] = 
{
                    {'1','2','3'},
                    {'4','5','6'},
                    {'7','8','9'}
};

void displayBoard() 
{
    for(int i=0; i<3; i++) 
    {
        for(int j=0; j<3; j++) 
	{
            	cout << " | " << board[i][j];
        }
        	cout << " | " << endl;
    }
}

bool isWinner(char player)
{
    for(int i=0; i<3; i++)
    {
    	if(board[i][0]==player && board[i][1]==player && board[i][2]==player)
    		{
    			return true;
    		}
    	if(board[0][i]==player && board[1][i]==player && board[2][i]==player) 
    		{
    			return true;
    		}
    }

    if(board[0][0]==player && board[1][1]==player && board[2][2]==player)
    {
        return true;
    }
    if(board[0][2]==player && board[1][1]==player && board[2][0]==player)
    {
        return true;
    }
    return false;
}

bool isFull() 
{
    for(int i=0; i<3; i++) 
    {
        for(int j=0; j<3; j++) 
	{
            if(isdigit(board[i][j])) 
	    {
                return false;
            }
        }
    }
    return true;
}

void playerMove(char player) 
{
    int move;
    cout << "Player " << player << ", enter your move: ";
    cin >> move;
    for(int i=0; i<3; i++) 
    {
        for(int j=0; j<3; j++) 
	{
            if(board[i][j]==move+'0') 
	    {
                board[i][j]=player;
                return;
            }
        }
    }
    cout << "Invalid move! Try again." << endl;
    playerMove(player);
}

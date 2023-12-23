#include "functions.h"

int main() 
{
    char player = 'X';
    int move;
    bool gameOver = false;

    do 
    {
        displayBoard();
        playerMove(player);
        if(isWinner(player)) 
	{
            displayBoard();
            cout << "Player " << player << " wins!" << endl;
            gameOver = true;
        }
        else if(isFull())
       	{
            displayBoard();
            cout << "It's a tie!" << endl;
            gameOver = true;
        }
        else 
	{
            if(player == 'X') 
	    {
                player = 'O';
            }
            else 
	    {
                player = 'X';
            }
        }
    } 
    while(!gameOver);

    return 0;
}

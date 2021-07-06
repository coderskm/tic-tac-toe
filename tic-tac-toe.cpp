#include<iostream>
using namespace std;
string board[9] = {" "," "," "," "," "," "," "," "," "};
int player = 1; // for selecting position from player
int position = 0; // to select location 0 to 9

void introduction()
{
	cout<<"Press any key to begin: ";
	getchar(); // to get input from keyboard; haults the screen till it receives no input
	cout<<"\n";
	
	cout<<"*******************\n";
	cout<<"TIC-TAC-TOE\n";
	cout<<"*******************\n";
	
	cout<<"PLAYER 1) X\n";
	cout<<"PLAYER 2) O\n";
	
	cout<<"3x3 grid is shown below:\n\n";
	
    cout << "     |     |      \n";
    cout << "  1  |  2  |  3   \n";
    cout << "_____|_____|_____ \n";
    cout << "     |     |      \n";
    cout << "  4  |  5  |  6   \n";
    cout << "_____|_____|_____ \n";
    cout << "     |     |      \n";
    cout << "  7  |  8  |  9   \n";
    cout << "     |     |      \n\n";
}

bool isWinner() // to check if row, coulmn or diagonal have same X or O filled or not
{
	bool winner = false;
	
	//for rows
	if((board[0]==board[1]) && (board[1]==board[2]) && board[0] != " ") 
	{
		winner = true;
	}
	else if ((board[3] == board[4]) && (board[4] == board[5]) && board[3] != " ") 
	{
    winner = true;
    } 
	 
	else if ((board[6] == board[7]) && (board[7] == board[8]) && board[6] != " ") 
	{
    winner = true;
  	} 

	//for columns
	else if((board[0]==board[3]) && (board[3]==board[6]) && board[0] != " ")
	{
		winner = true;
	}
	
	else if ((board[1] == board[4]) && (board[4] == board[7]) && board[1] != " ")
	{
    	winner = true;
 	} 
	
	else if ((board[2] == board[5]) && (board[5] == board[8]) && board[2] != " ") 
	{
   		winner = true;
  	}

	//for diagonals
	else if ((board[0]==board[4]) && (board[4]==board[8]) && board[0] != " ")
	{
		winner = true;
	}
	
	else if ((board[2]==board[4]) && (board[4]==board[6]) && board[2] != " ")
	{
		winner = true;
	}
	
	return winner;
}
bool isFull() // to check if board is full or not
{
	bool full = true;
	for(int i=0;i<9;i++)
	{
		if(board[i]==" ") // if some space is empty in board
		{
			full = false;
		}
	}
	return full;
}

void draw() // to show board on screen after every move of each player
{
  cout<<  "     |     |      \n";
  cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
  cout << "_____|_____|_____ \n";
  cout << "     |     |      \n";
  cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
  cout << "_____|_____|_____ \n";
  cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
  cout << "     |     |      \n";
  cout << "\n";

}

void setPosition() // set player to correct position entered by it
{
	cout<<"PLAYER "<<player<<"'s (Enter from 1 to 9):";
	while(!(cin>>position)) // to check if position number is valid or not
	{
		cout<<"Enter Valid Number From 1 to 9"<<endl;
		cin.clear(); // flushes out everything in input buffer
		cin.ignore(); // ignores everything inside input buffer
	}
	while(board[position-1]!=" ") //to check whether entered board's position is filled or not 
	{
		cout<<"Already Filled Try Again\n";
		cout<<"PLAYER "<<player<<"'s (Enter from 1 to 9):";
		cin>>position;
		cout<<"\n";
	}
}

void update() // update board position's values after each turn of players
{
  
  if (player % 2 == 1)
  {
    board[position - 1] = "X";   
  }
  else
  {
    board[position - 1] = "O";
  }
}

void changePlayer()  // changing player's turn after each move
{
	if (player == 1)
  {
    player++;
  }
  else
  {
    player--;
  }
}

void take_turn() // if winner is not there and board is not full then we perform all invoked function
{
	while(!isWinner() && !isFull())  
	{
		// invoked functions
		setPosition();
		update();
		changePlayer();
		draw();
	}	
}

void ENDGAME()
{
	if(isWinner())
	{
		cout<<"Winner"<<endl;
		
	}
	
	else if(isFull())
	{
		cout<<"There is a tie!"<<endl;
	}
}
int main()
{
	introduction();
	take_turn();
	ENDGAME();
	return 0;
}

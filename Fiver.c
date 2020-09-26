#include <stdio.h>

const int board_size = 5;					// Game board size
const char BLACK = 'X';						// Black Piece
const char WHITE = 'O';						// White Piece

void initBoard(char board[][board_size]);   // Board initialization
void playGame(char board[][board_size]);	// Play the game
void displayBoard(char board [][board_size]);// Print game board
int checkEnd(char board[][board_size]);	// Check if game ends
void flip(char board[][board_size],int a,int b); // Flip the piece to a different color
int mv(int a,int b); //Checks if move is valid
int cmv(int a,int b);
int main(){
	char board[board_size][board_size];
	char answer;

	do{
		initBoard(board);
		printf("*********\n");
		printf("* Fiver *\n");
		printf("*********\n");
		displayBoard(board);
		do{
			playGame(board);
			displayBoard(board);
		}while(checkEnd(board));
		printf("Congratulations! You win!\n");
		printf("Play again (y/n)? ");
		scanf("%c", &answer);
	}while(answer=='Y' || answer=='y');
	return 0;
}

//initialize the game board content
void initBoard(char board[][board_size]){
	int i,j;
	for(i=0;i<board_size;i++)
        for (j=0;j<board_size;j++)
			board[i][j] = WHITE;
}

void playGame(char board[][board_size]){
	int a,b;

	do{
		printf("Please select the piece's row and column number: ");
		do{
		scanf ("%d%d",&a,&b);
		}while(mv(a,b));
		flip(board,a,b);
		if(checkEnd(board))break ;

	}while(1);

	//??
}

//check to see if all pieces have been changed to black
int checkEnd(char board[][board_size]){
	int i,j;
	for(i=0;i<board_size;i++)
    {
        for(j=0;j<board_size;j++)
        {
            if (board[i][j]=='O')return 1;
        }
    }
    return 0;
}

//display the game board
void displayBoard(char board[][board_size]){
	int i,j;
	for (i=0;i<board_size;i++)
     {
         for(j=0;j<board_size;j++)
         {
             printf ("%c",board[i][j]);
         }
         printf ("\n");
     }
}


//flip a piece to a different color
void flip(char board[][board_size],int a,int b){


    if(cmv(a-1,b))
    {
        if(board[a-1][b]=='O')board[a-1][b]='X';
        else board[a-1][b]='O';
    }
	if(cmv(a,b+1))
    {
        if(board[a][b+1]=='O')board[a][b+1]='X';
        else board[a][b+1]='O';
    }if(cmv(a,b-1))
    {
        if(board[a][b-1]=='O')board[a][b-1]='X';
        else board[a][b-1]='O';
    }if(cmv(a+1,b))
    {
        if(board[a+1][b]=='O')board[a+1][b]='X';
        else board[a+1][b]='O';
    }
    if(board[a][b]=='O')board[a][b]='X';
    else board[a][b]='O';
}
int mv(int a,int b)
{
    if(a<0||a>4||b<0||b>4)
    {
        printf ("Illegal Move\n");
        return 1;
    }
    return 0;
}
int cmv(int a,int b)
{
    if(a<0||b<0||a>4||b>4)return 0;
    return 1;
}

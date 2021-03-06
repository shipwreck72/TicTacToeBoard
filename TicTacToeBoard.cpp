#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if(turn == X)
  {
    turn = O;
    return turn;
  }
  else{
  
    turn = X;
  return turn;
}
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  if(row > BOARDSIZE-1 || row < 0 ||column > BOARDSIZE -1 || column < 0)
  {
    toggleTurn();
    return Invalid;
  }
    if(board[row][column]==Blank)
    {
      board[row][column] = turn;
      toggleTurn();
      return board[row][column];
    }
  toggleTurn();
  return Invalid;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
/*BUG: the column and row are flipped and should return the boared mirrored
where it should return the board how it really is
*/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if(row > BOARDSIZE-1 || row < 0 ||column > BOARDSIZE -1 || column < 0)
  {
    return Invalid;
  }
  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
   int i = 0;
   int j = 0;
    for(j=0; j<BOARDSIZE; j++)
    {
      if(board[i][j]==X && board[i+1][j] == X && board[i+2][j] == X)
     {
       return X;
     } else if (board[i][j]==O && board[i+1][j] == O && board[i+2][j] == O)
     {
       return O;
     }
    }
    
    i = 0;
    j = 0;
    for(i=0; i<BOARDSIZE; i++)
    {
      if(board[i][j]==X && board[i][j+1] == X && board[i][j+2] == X)
     {
       return X;
     } else if(board[i][j]==O && board[i][j+1] == O && board[i][j+2] == O)
     {
       return O;
     }
    }
    
    if(board[0][0]==X && board[1][1] == X && board[2][2] == X)
     {
       return X;
     } else if(board[0][0]==O && board[1][1] == O && board[2][2] == O)
     {
       return O;
     } else if(board[2][0]==X && board[1][1] == X && board[0][2] == X)
     {
       return X;
     } else if(board[2][0]==O && board[1][1] == O && board[0][2] == O)
     {
       return O;
     }
    for(i=0; i<BOARDSIZE; i++)
      for(j=0; j<BOARDSIZE; j++){
        if(board[i][j] == Blank){
          return Invalid;
        }
    }
    return Blank;
}

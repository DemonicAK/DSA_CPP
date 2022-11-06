
#include <iostream>
using namespace std;
#define N 4




void printSolution(int board[N][N])
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
      printf(" %d ", board[i][j]);
    printf("\n");
  }
}

// function to check whether the position is safe or not
bool isvalid(int board[N][N], int row, int col)
{
  int i, j;
  for (i = 0; i < col; i++)  //i=column
    if (board[row][i])   // checking the row 
      return false;

  for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    if (board[i][j])
      return false;
  for (i = row, j = col; j >= 0 && i < N; i++, j--)
    if (board[i][j])
      return false;

  return true;
}

// The function that solves the problem using backtracking
bool nqueen_col(int board[N][N], int col)
{
  if (col >= N)
    return true;

  for (int i = 0; i < N; i++)
  {
    // if it is safe to place the queen at position i,col -> place it
    if (isvalid(board, i, col))
    {

      board[i][col] = 1;

      if (nqueen_col(board, col + 1))
        return true;

      // backtrack if the above condition is false
      board[i][col] = 0; // BACKTRACK
    }
  }

  return false;
}




void solve()
{
    int board[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }

    if (nqueen_col(board, 0))
    {
        printSolution(board);
    }
    else
    {
        cout << "false";
    }
}

int main()
{
    int t = 1;
    while (t)
    {
        solve();
        t--;
    }

    return 0;
}
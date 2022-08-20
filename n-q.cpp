#include <iostream>
using namespace std;
#define N 4

void printarray(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool isvalid(int board[N][N], int row, int col)
{
    int i, j;
    for (int i = 0; i < row; i++)   //i=row
    { // column
        if (board[i][col])  //checking the column
        { // such that no other 1 is there
            return false;
        }
    }

    for (i = row, j = col; i >= 0 and j >= 0; i--, j--)
    {
        if (board[i][j])
        { // left diagonal
            return false;
        }
    }
    for (i = row, j = col; i >= 0 and j < N; i--, j++)
    { // right diagonal
        if (board[i][j])
        {
            return false;
        }
    }
    return true;
}

bool nqueen_row(int board[N][N], int row)
{
    if (row >= N)
    {
        return true;
    }
    for (int i = 0; i < N; i++)
    { // i = column

        if (isvalid(board, row, i))
        {
            board[row][i] = 1;

            if (nqueen_row(board, row + 1))
            {
                return true;
            }

            board[row][i] = 0;
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

    if (nqueen_row(board, 0))
    {
        printarray(board);
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
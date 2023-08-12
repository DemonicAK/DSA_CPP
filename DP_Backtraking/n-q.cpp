#include <bits/stdc++.h>
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

void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}
// it is done with the help of row wise

bool isvalid_row(int board[N][N], int row, int col)
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

        if (isvalid_row(board, row, i))
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

// it is done with the help of column wise

// function to check whether the position is safe or not
bool isvalid_col(int board[N][N], int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++) // i=column
        if (board[row][i])    // checking the row
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
        if (isvalid_col(board, i, col))
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

    cout<<"row wise\n";

    if (nqueen_row(board, 0))
    {
        printarray(board);
    }
    else
    {
        cout << "false";
    }

}

void solve1()
{
    int board[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }
    cout << "col wise\n";

    if (nqueen_col(board, 0))
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
        solve1();
        t--;
    }

    return 0;
}
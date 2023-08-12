#include <bits/stdc++.h> // Include every standard library
using namespace std;

// https://leetcode.com/problems/rotting-oranges/
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();    // no of rows
        int m = grid[0].size(); // no of cols

        queue<pair<pair<int, int>, int>> Q;
        int rotten[n][m];
        int fresh = 0;
        int rot = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                rotten[i][j] = 0;
                if (grid[i][j] == 2)
                {
                    rotten[i][j] = 1;
                    Q.push({{i, j}, 0});
                    rot++;
                }
                else if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }
        int mintime = 0;
        int drow[4] = {1, 0, -1, 0};
        int dcol[4] = {0, 1, 0, -1};
        int cnt = 0;

        while (!Q.empty())
        {
            int row = Q.front().first.first;
            int col = Q.front().first.second;
            int t = Q.front().second;

            mintime = max(mintime, t);
            Q.pop();

            for (int i = 0; i < 4; i++)
            {
                int r = row + drow[i];
                int c = col + dcol[i];

                if (r >= 0 && c >= 0 && r < n && c < m && grid[r][c] != 2 && grid[r][c] != 0 && rotten[r][c] == 0)
                {

                    Q.push({{r, c}, t + 1});

                    rotten[r][c] = 1;
                    cnt++;
                }
            }
        }

        if (fresh == cnt)
            return mintime;
        else
            return -1;
    }
};

int main()
{

    int n = 3, m = 3;
    // cin >> n >> m;
    vector<vector<int>> grid{{0, 2}};

    Solution s;
    cout << s.orangesRotting(grid) << endl;

    return 0;
}
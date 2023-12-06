

#include <bits/stdc++.h> // Include every standard library
using namespace std;


// https://leetcode.com/problems/01-matrix/description/
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {

    int n= mat.size();
    int m=mat[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 0));
    vector<vector<int>> vis(n, vector<int>(m, 0));

    queue<pair<int,pair<int,int>>> q;


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                q.push({0,{i,j}});
                vis[i][j]=1;
            }
        }
    }

    while(!q.empty()){
    int d=q.front().first;
    int row = q.front().second.first;
    int col = q.front().second.second;

    q.pop();

    for (int i=0;i<4;i++){
    }

    }


    }
};

int main()
{
    Solution a;
    vector<vector<int>> input = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> output = a.updateMatrix(input);
    //print 2d array
    for (auto i : output)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }


    return 0;
}
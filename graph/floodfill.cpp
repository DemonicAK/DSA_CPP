#include <bits/stdc++.h> // Include every standard library
using namespace std;
// https://leetcode.com/problems/flood-fill/
class Solution
{
private:
void dfs(vector<vector<int>> &img,int sr ,int sc, int oldcolor,int newcolor){
    if(sr<0 || sc<0 || sr>=img.size() || sc>=img[0].size() || img[sr][sc]!=oldcolor){
        return;
    }
    img[sr][sc] = newcolor;

    int drow[4]={1,-1,0,0};
    int dcol[4]={0,0,1,-1};
    for(int i=0;i<4;i++){
        dfs(img,sr+drow[i],sc+dcol[i],oldcolor,newcolor);
    }
}
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        vector<vector<int>> img = image;

        int oldColor = image[sr][sc];

        if (oldColor != color)
        {
            dfs(img,sr,sc,oldColor,color);
        }

        return img;
        
    }
};


int main(){
    Solution s;
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    vector<vector<int>>ans= s.floodFill(image, 1, 1, 2);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
};
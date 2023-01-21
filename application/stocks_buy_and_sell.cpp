#include <bits/stdc++.h>
using namespace std;
// Function to find the days of buying and selling stock for max profit.
vector<vector<int>> stockBuySell(vector<int> A, int n)
{
    // code here
    bool stock = false;
    int buyd = 0;
    int selld = 0;
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        int today = A[i];
        int tomorow = A[i + 1];
        if (!stock)
        {
            // to buy
            if (today < tomorow)
            {
                stock = true;
                buyd = i;
            }
        }
        else
        {
            // to sell
            if (today > tomorow)
            {
                stock = false;
                selld = i;

                vector<int> A{buyd, selld};
                ans.push_back(A);
            }
        }
    }
    return ans;
}

int main(){

    // N = 7
    vector<int> A = {4, 2, 2, 2, 4};

vector<vector<int>> ans = stockBuySell(A, A.size());

for (int i = 0; i < ans.size(); i++)
{
    cout << ans[i][0] << " " << ans[i][1] << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> stockBuySell(vector<int> A, int n)
{
    // code here
// int buy_ind=0,sell_ind=0;
//     int profit_tillnow = 0;
//     int buy = INT_MAX;

//     vector<vector<int>> ans;

//     for (int i = 0; i < n; i++)
//     {
//     int sell =A[i];
//       int  profit = sell - buy;
//         if (profit<0)
//         {
//             buy_ind = i;
//             buy = A[i];
//         }
//         else if ( profit_tillnow = profit)
//         {
//             profit_tillnow=profit;
//             sell_ind = i;
//             ans.push_back({buy_ind,sell_ind});
//         }
//         else if ( profit_tillnow < profit)
//         {
//             profit_tillnow=profit;
//             sell_ind = i;
//             ans.pop_back();
//             ans.push_back({buy_ind,sell_ind,profit_tillnow});
//         }
//     }
//     vector<vector<int>> ansi;

// int max_profit=0;

// for(int i=0;i<ans.size();i++){
// int curr_profit=ans[i][2];
// if(curr_profit>max_profit){
// max_profit=curr_profit;



// }


    // return ans;

    vector<vector<int>> res;

    int lastBuy = 0;

    for (int i = 1; i < n; i++)

    {

if (A[i] > A[lastBuy])

{

    res.push_back({lastBuy, i});
}

lastBuy = i;
    }

return res;




}






int main()
{

    // N = 7
    vector<int> A = {100, 180, 260, 310, 40, 535, 695};



    vector<vector<int>> ans = stockBuySell(A, A.size());


    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }

    return 0;
}
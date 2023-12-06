
#include <bits/stdc++.h> // Include every standard library
using namespace std;



class Solution
{
    public: 
     int maxSum(vector<int> &nums)
    {
        unordered_map<char, vector<int>> mpp;
        for (int num : nums)
        {
            string str = to_string(num);
            char maxi = *max_element(str.begin(), str.end());
            mpp[maxi].push_back(num);
        }
            int maxi = -1;
    
            for (auto it : mpp)
        {
            vector<int> vals=it.second;
            if (vals.size() >= 2)
            {
                vector<int> sorted = vals;
                sort(sorted.rbegin(), sorted.rend());
                int sum = sorted[0] + sorted[1];
                maxi= max(maxi, sum);
                
            }
        
        }
        return maxi;

        }};
        
int main(){
    vector<int> nums={10,11,12,13,14,15};
    Solution s;
    cout<<s.maxSum(nums);
    return 0;}

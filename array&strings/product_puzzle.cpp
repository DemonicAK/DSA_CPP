
#include<bits/stdc++.h>
using namespace std;



vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{

    // code here
    long long int zeroes = 0;
    long long int prod = 1;
    vector<long long int> ans;

    for (int i = 0; i < n; i++)
    {
        if (!nums[i])
            zeroes++;
        else
            prod *= nums[i];
    }

    if (zeroes > 1)
    {
        vector<long long int> my_vector(n, 0);
        return my_vector;
    }

    else
    {
        for (int i = 0; i < n; i++)
        {
        // cout<<nums[i]<<endl;
            if (nums[i]){

                long long int kk = prod / nums[i];
                // cout<<kk<<endl;
                ans.push_back(kk);
            }
            else
            // cout<<prod<<endl;
                ans.push_back(prod);
        }
    }

    return ans;
}

int main(){
    vector<long long int> nums{10, 3, 5, 6, 2};
        vector<long long int> output = productExceptSelf(nums, 5);
        for (int i = 0; i < output.size(); i++)
        {
            cout << output[i] << " ";
        }

    return 0;
}
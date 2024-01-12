#include <bits/stdc++.h>
using namespace std;

int binarysearch(int arr[], int size, int key)
{
    int strt = 0, end = size - 1;

    while (strt <= end)
    {
        int mid = (strt + end) / 2;
        if (key < arr[mid])
        {
            end = mid - 1;
        }
        else if (key == arr[mid])
        {
            return mid;
        }
        else
        {
            strt = mid + 1;
        }
    }
    return -1;
}

vector<int> find(int arr[], int n, int x)
{
    // code here

    int index = binarysearch(arr, n, x);
    // cout<<index<<endl;
    // for first occurenece
    int first = index - 1;
    while (arr[first] == x)
    {
        first -= 1;
        // cout<<first<<endl;
    }
    int last = index + 1;
    while (arr[last] == x)
    {
        last += 1;
    }

    vector<int> ans;
    ans.push_back(first + 1);
    ans.push_back(last - 1);

    return ans;
}

int main()
{

    int arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int n = 9;
    int x = 5;
    vector<int> ans = find(arr, n, x);
    cout << "initial:" << ans[0] << " "
         << "final:" << ans[1] << endl;

    return 0;
}

// better solutuion

// int start = 0, end = n - 1;
// while (start <= end)
// {
//  if (arr[start] < x)
//         start++;
//  if (arr[end] > x)
//         end--;
//  if (arr[start] == x && arr[end] == x)
//         return {start, end};
// }
// return {-1, -1};
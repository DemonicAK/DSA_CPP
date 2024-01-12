

#include <bits/stdc++.h>
using namespace std;

int binarysearch(vector<int> arr, int key)
{
    int n = arr.size();
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (mid == key)
            return mid;
        else if (arr[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int binarysearch_recursive(vector<int> arr, int key, int low, int high)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (key == mid)
            return mid;
        else if (arr[mid] > key)
        {
            return binarysearch_recursive(arr, key, low, mid - 1);
        }
        else
        {
            return binarysearch_recursive(arr, key, mid + 1, high);
        }
    }
    return -1;
}
//first index where "val is greater than or equal to key"
int lowerbound(vector<int> arr, int key)
{
    int n = arr.size();
    int low = 0, high = n - 1, result = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= key)
        {
            result = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return result;
}

//first index where "val is greater than key"
int upperbound(vector<int> arr, int key)
{
    int n = arr.size();
    int low = 0, high = n - 1, result = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > key)
        {
            result = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return result;
}


int main()
{

    vector<int> arr1 = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9, 10};
    int result1 = upperbound(arr1, 5);
    int result2 = lowerbound(arr1, 5);
    int ressu=lower_bound(arr1.begin(),arr1.end(),5)-arr1.begin();
    cout << "index: " << ressu << endl;

    return 0;
}
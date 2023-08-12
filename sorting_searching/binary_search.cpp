

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

int binarysearch_recursive(int arr[], int strt, int end, int key)
{
    if (strt <= end)
    {
        int mid = (strt + end) / 2;
        if (key < arr[mid])
        {
            return binarysearch_recursive(arr, strt, mid - 1, key);
        }
        else if (key == arr[mid])
        {
            return mid;
        }
        else
        {
            return binarysearch_recursive(arr, mid + 1, end, key);
        }
    }
    return -1;
}

int binarysearch_first_occurence(int arr[], int size, int key)
{
    int strt = 0, end = size - 1, result = -1;

    while (strt <= end)
    {
        int mid = (strt + end) / 2;
        if (key < arr[mid])
        {
            end = mid - 1;
        }
        else if (key == arr[mid])
        {
            result = mid;
            end = mid - 1;
        }
        else
        {
            strt = mid + 1;
        }
    }
    return result;
}

int binarysearch_last_occurence(int arr[], int size, int key)
{
    int strt = 0, end = size - 1, result = -1;

    while (strt <= end)
    {
        int mid = (strt + end) / 2;
        if (key < arr[mid])
        {
            end = mid - 1;
        }
        else if (key == arr[mid])
        {
            result = mid;
            strt = mid + 1;
        }
        else
        {
            strt = mid + 1;
        }
    }
    return result;
}

int binarysearch_count_smaller_than_value(int arr[], int size, int key)
{
    int strt = 0, end = size - 1;
    while (strt <= end)
    {
        int mid = (strt + end) / 2;
        if (key < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            strt = mid + 1;
        }
    }
    return strt;
}

int main()
{
    cout << "enter the number of elements :";
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "enter the number to be searched:";
    cin >> key;
    int result = binarysearch(arr, n, key);
    result++;

    cout << "position: " << result << endl;

    return 0;
}
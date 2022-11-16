
#include <iostream>
using namespace std;

int small_pos(int arr[], int size, int pos)
{

    int smallest = arr[pos];
    int smallpos = pos;
    for (int i = pos+1; i<size; i++)
    {
        if (arr[pos] <= smallest)
        {
            smallest = arr[pos];
            smallpos = pos;
        }
    }
    return smallpos;
}
void selectionsort(int arr[], int size)
{
    for (int i = 0; i < size ; i++)
    {
        int smallpos = small_pos(arr, size, i);
        int temp = arr[smallpos];
        arr[smallpos] = arr[i];
        arr[i] = temp;
    }
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
    selectionsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << "\n";
}
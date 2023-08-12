#include "bits/stdc++.h"
using namespace std;

/*
n=5
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5

*/

void pattern(int n)
{
    if (n == 1)
    {
        cout<<1<<"\n";
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << "\n";

    pattern(n - 1);

    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << "\n";
}

int main()
{
  pattern (5);
    return 0;
}
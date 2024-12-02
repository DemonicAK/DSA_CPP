#include <bits/stdc++.h> // Include every standard library
using namespace std;

/* Iterative Function to calculate (x^y) in O(logy) */
int power(int x, unsigned int y)
{
    int res = 1; // Initialize result

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = res * x;

        // y must be even now
        y = y >> 1; // y = y/2
        x = x * x;  // Change x to x^2
    }
    return res;
}

// used in binary seasrch in answers to avoid overflow
int power2(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > m)
            return 2;
    }
    if (ans == m)
        return 1;
    return 0;
}

// Driver program to test above functions
int main()
{
    int x = 3;
    unsigned int y = 5;

    cout << "Power is " << power(x, y);

    return 0;
}
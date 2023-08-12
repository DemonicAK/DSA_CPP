#include <bits/stdc++.h>
using namespace std;

// Given an array of integers A, of size N, and an integer K, print the first negative integer from every window of size K in the array A. If no negative integer is present in the window, print 0.

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{

    queue<int> neg;
    for (int y = 0; y < K; y++)
    {
        if (A[y] < 0)
            neg.push(A[y]);
    }
    vector<long long> ans;
    int i = 0, j = i + K-1;
    while (j < N)
    {

        if (A[j] < 0)
            neg.push(A[j]);

        if (neg.empty())
            ans.push_back(0);
        else
            ans.push_back(neg.front());

        if (neg.front() == A[i])
            neg.pop();

        i++;
        j++;
    }
    return ans;
}
int main()
{


    long long int N, K;
    cin >> N >> K;
    long long int A[N];
    for (long long int i = 0; i < N; i++)
        cin >> A[i];
    vector<long long> ans = printFirstNegativeInteger(A, N, K);
    for (long long int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}
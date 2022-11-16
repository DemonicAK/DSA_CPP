#include"bits/stdc++.h"
using namespace std;
 
void helo(int n)
{
    if(n==0)
    {
        return;
    }
    cout<<n<<"\n";
    helo(n-1);
}


int main()
{
 
 helo(3);
 return 0;
}
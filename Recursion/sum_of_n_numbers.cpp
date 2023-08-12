#include"bits/stdc++.h"
using namespace std;
 
// 1+2+3+4+5+6+7+8+9+10+........+n
int sum(int n)
{
    if(n==0)
    {
        return 0;
    }
    int prevsum=sum(n-1);
    return n+prevsum;
}




int main()
{

cout<<sum(4)<<"\n";
 
 
 return 0;
}
#include"bits/stdc++.h"
using namespace std;
 
// 1 2 3 4 5
// 1234 taking out last digit
// 123 taking out last digit
// 12 taking out last digit
// 1 taking out last digit



int sum (int n)
{

    // int t=n/10;
//    int s=0;
//    s+=n%10;

if(n==0){return 0;}
   return n%10+ sum(n/10);




}

int main()
{
 cout<<sum(123)<<"\n";
 
 return 0;
}
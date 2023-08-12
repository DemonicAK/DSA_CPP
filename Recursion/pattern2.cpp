#include"bits/stdc++.h"
using namespace std;
 

/*
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1

*/

 

 void pattern(int n){
     if (n==0)
     {
         return;
     }
     for (int i=1 ; i<=n ; i++){
         cout<<i<<" ";
     }
     cout<<"\n";
     pattern(n-1);
 
  }


 
int main()
{
 pattern(6);
 
 return 0;
}
#include"bits/stdc++.h"
using namespace std;
 


/*
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5

*/

 
void pattern(int n){
    if (n==0)
    {
        return;
    }
    pattern(n-1);
for (int i=1 ; i<=n ; i++){
    cout<<i<<" ";
}
cout<<"\n";

 }



int main()
{
 
 pattern(5);

 return 0;
}
#include<bits/stdc++.h>
using namespace std;
 
 /*
 0 1 1 2 3 5 8 .......
 */
// nth fibonacci number


// f(n)=f(n-1)+ f(n-2)


int fibonacci(int n){

if(n==0 || n==1)
    return n;


  return fibonacci(n-1)+fibonacci(n-2);
  
}   
int main()
{
 cout<<fibonacci(5)<<"\n";
   
 
 return 0;
}
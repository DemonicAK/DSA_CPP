#include<bits/stdc++.h>
using namespace std;
 // it is used to find the max sum 
int maxsum(vector<int> ve){
    int maxo=INT_MIN;
    int sum=0;
    for(int i=0;i<ve.size();++i){
        sum+=ve[i];
        maxo=max(maxo,sum);
        sum=max(0,sum);
    }
    return maxo;
}



int main()
{
    vector<int> vv;
 for (int  i = 0; i < 5; i++)
 {int b;
    cin>>b;
    vv.push_back(b);
 }
 int c=maxsum(vv);
 cout<<c;
 
 
 
 return 0;
}
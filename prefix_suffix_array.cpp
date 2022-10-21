
#include"bits/stdc++.h"
using namespace std;
 


 vector<int> prefix_min(vector<int> arr){

    vector<int> mi;

    int premin=INT_MAX;
for (int i=0; i< arr.size();i++ ){
int premin=min(arr[i],premin);
    mi.push_back(premin);
}


    return mi;
 }


int main()
{
 
int n=3;
// cin>>n;
 vector<int> arr;
 int ele;
 for(int i=0 ; i<n ; i++){
    cin>>ele;
    arr.push_back(ele);
 }
 vector<int> rr=prefix_min(arr);
 for(int i=0;i<rr.size();i++){
    cout<<rr[i]<<" ";
 }
 return 0;
}
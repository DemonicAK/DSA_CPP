//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int save_gotham(int arr[], int n);



int main() {
    
    int t;
    cin>> t;
    while(t--)
    {
        int n;cin>>n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        cout << save_gotham(arr, n) << endl;
    }
    
	return 0;
}
// } Driver Code Ends


int save_gotham(int arr[], int n)
{
    // Complete the function
    int curr=arr[0];
    int sum=0;
    for (int i=1;i<n;++i){
        if(arr[i]>curr){
            sum+=arr[i];
            curr=arr[i];
        }
    }
    return sum;
    
}
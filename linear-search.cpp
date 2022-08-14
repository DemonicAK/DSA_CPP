



#include<iostream>
using namespace std;

int linearsearch(int arr[],int size,int key)
{
    for (int i=0;i<size;i++){
        if (key==arr[i]){
            return i+1;;
        }
    }
    return -1;
} 
 
 
int main()
{
 cout<<"enter the number of elements :";
 int n;
 cin>>n;

 int arr[n];
 for (int i=0;i<n;i++){
    cin>>arr[i];

 }
 int key;
 cout<<"enter the number to be searched:";
 cin>>key;
 cout<<"index:"<< linearsearch(arr,n,key)<<endl;


 
 
    return 0;
}
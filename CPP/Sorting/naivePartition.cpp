#include <bits/stdc++.h>
using namespace std;


void partition(int arr[],int l,int h,int p){
    int temp[h-l+1];
    int index=0;
    for(int i=l;i<=h;i++){
        if(arr[i]<=arr[p]){
            temp[index]=arr[i];index++;
        }
    }
    for(int i=l;i<=h;i++){
        if(arr[i]>arr[p]){
            temp[index]=arr[i];index++;
        }
    }
     for(int i=l;i<=h;i++){
         arr[i]=temp[i-l];
    }
}



int main() {
	
    int arr[]={5,13,6,9,12,11,8};
	
	int n=sizeof(arr)/sizeof(arr[0]);
	
	partition(arr,0,n-1,n-1);
	
	for(int x: arr)
	    cout<<x<<" ";
}
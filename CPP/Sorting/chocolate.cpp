#include <bits/stdc++.h>
using namespace std;


int minDiff(int arr[],int n,int m){
    if(m>n)
        return -1;
    sort(arr,arr+n);
    int res=arr[m-1]-arr[0];
    for(int i=0;i+m-1<n;i++){
        res=min(res,arr[i+m-1]-arr[0]);
    }
    return res;

}
 
int main() {
	
    int arr[]={7,3,2,4,9,12,56};
	
	int n=sizeof(arr)/sizeof(arr[0]);int m=3;
	
	cout<<minDiff(arr,n,m);
}

/*Given an array of n integers where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets such that: 

Each student gets one packet.
The difference between the number of chocolates in the packet with maximum chocolates and packet with minimum chocolates given to the students is minimum.
*/
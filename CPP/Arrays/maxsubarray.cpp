#include <iostream>
#include <cmath>
using namespace std;

int maxSum(int arr[],int n){
    int maxending =arr[0];
    int res=0;
    for(int i=0;i<n;i++){
        maxending= max(maxending+arr[i],arr[i]);
        res=max(res,maxending);
    }
    return res;
}


int main() {
	
     int arr[] = {1, -2, 3, -1, 2}, n = 5;

     cout<<maxSum(arr, n);
    
}
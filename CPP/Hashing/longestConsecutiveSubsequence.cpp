// we have to find the subsequence which are consecutive like 1 2 3 or 7 8 9 .
#include <bits/stdc++.h>
using namespace std;

int findLongest(int arr[], int n)
{
  int res=0;
  int curr=1;
  sort(arr,arr+n);
  for(int i=1;i<n;i++){
      if(arr[i]==arr[i-1]+1){
          curr++;
      }else{
          res=max(curr,res);
          curr=1;
      }
  }
  res=max(curr,res);
  return res;
}

int main()
{
    int arr[] = {1, 9, 3, 4, 2, 10, 13};
   
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << findLongest(arr, n);
}
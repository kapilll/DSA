#include <iostream>
#include <cmath>
using namespace std;

int findMajority(int arr[],int n){
   int count=1;
   int res=0;
   for(int i=0;i<n;i++){
       if(arr[res]==arr[i]){
           count++;
       }
       else if(count==0){
           res=i;
           count=1;
       }
       else{
           count--;
       }
   }
   count=0;
  for(int i=0;i<n;i++){
      if(arr[res]==arr[i]){
        count++;
      }
  }
  if(count<=n/2){
      res=-1;
  }
    return res;
}


int main() {
	
     int arr[] = {8, 8, 6, 6, 6, 4, 6}, n = 7;

     cout<<findMajority(arr, n);
    
}
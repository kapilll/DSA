#include <iostream>
#include <cmath>
using namespace std;

int normalSum(int arr[],int n){
   int res=arr[0];
   int maxending=arr[0];


   for(int i=1;i<n;i++){
       maxending =max(maxending+arr[i],arr[i]);
       res=max(maxending,res);
   }
   return res;
}
int overallMaxSum(int arr[],int n){
   int normal_sum=normalSum(arr,n);
   if(normal_sum<0){
       return normal_sum;
   }
    int arraySum=0;
   for(int i=0;i<n;i++){
       arraySum+=arr[i];
       arr[i]=-arr[i];
   }
   int circular_sum=arraySum+normalSum(arr,n);
   return max(circular_sum,normal_sum);
}



int main() {
	
     int arr[] = {8, -4, 3, -5, 4}, n = 5;

     cout<<overallMaxSum(arr, n);
    
}
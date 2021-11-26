#include <iostream>
#include <cmath>
using namespace std;
int maxProfit(int arr[],int start,int end){
    int profit=0;
    if(end<=start){
        return 0;
    }
    for(int i=start;i<end;i++){
        for(int j=i+1;j<=end;j++){
            if(arr[i]<arr[j]){
                int curr_profit= arr[j]-arr[i]+maxProfit(arr,start,i-1)+maxProfit(arr,j+1,end);
                profit= max(profit,curr_profit);
            }
        }
    }
    return profit;
}
int main() {
	
      int arr[] = {1, 5, 3, 8, 12}, n = 5;

      cout<<maxProfit(arr, 0, n - 1);
    
}
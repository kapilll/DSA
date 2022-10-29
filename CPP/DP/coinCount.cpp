#include <iostream>
#include <string.h>
using namespace std;


int getCount(int coins[], int n, int sum)
{
    int dp[sum+1][n+1];
    
    for(int i=0;i<=n;i++)
    {
        dp[0][i]=1;
    }
    
    for(int j=0;j<=sum;j++)
    {
        dp[j][0]=0;
    }
    
    for(int i=1;i<=sum;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j] = dp[i][j-1];
            
            if(coins[j-1]<=i)
            dp[i][j]+=dp[i-coins[j-1]][j];
        }
    }//I am so sad that I could die right now one day i will be so happy that I could die then.

     
    // still sad this is almost 1year after the above one. I will change my life tonight. I will set the path
    //ablaze with my will power. 13-10-2022 .(I am listening to Mysterious girl-Peter Andre)
    //it's 28-10-2022 I didn't set ablaze anything lol. Today I got an ultimatum on my job. I have 2 months
    //to change my job that too I am not sure about. Still, I am going to start studying today.
    
    return dp[sum][n];
    
}
/*
if(sum==0)return 1;
if(n==0) return 0;
int res=getCount(coins,n-1,sum);
if(coins[n-1]<=sum){
    res+=getCount(coins,n,sum-coins[n-1]);
}
return res;
*/
int main() {
	
	
int coins[]={1, 2, 3}, sum=4, n=3;

cout<<getCount(coins, n, sum);
	

}
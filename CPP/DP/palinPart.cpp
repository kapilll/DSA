#include <iostream>
#include <limits.h>
using namespace std;


	
    int palPart(string str)
	{
        int n=str.length();
        int dp[n][n];
        bool isPalin[n][n];
        for(int i=0;i<n;i++){
            dp[i][i]=0;
            isPalin[i][i]=true;
        }
        for(int gap=1;gap<n;gap++){
            for(int i=0;i+gap<n;i++){
                int j=i+gap;
                if(str[i]==str[j] && (isPalin[i+1][j-1] || gap==1)){
                    dp[i][j]=0;
                    isPalin[i][j]=true;
                }else{
                    isPalin[i][j]=false;
                    dp[i][j]=INT_MAX;
                    for(int k=i;k<j;k++){
                        dp[i][j]=min(dp[i][j],1+dp[i][k]+dp[k+1][j]);
                    }
                }
            }
        }
        return dp[0][n-1];
	}

int main() {
    
    	string s = "geek";
    	
    	cout<<palPart(s);
    	
    	return 0;
}
#include <iostream>
#include <cmath>
#include <bits/stdc++.h> 
#include <climits>
using namespace std;

int maxOcc(int L[],int R[],int n){
    int s[1000];
    	memset(s, 0, sizeof(s));
    for(int i=0;i<n;i++){
       s[L[i]]++;
       s[R[i]+1]--;
    }

    int maxm=s[0]; int res=0;
    for(int i=1;i<1000;i++){
        s[i]+=s[i-1];

        if(maxm<s[i]){
            maxm=s[i];         //look at the questions at the end of the video
            res=i;
        }
    }
    return res;

}

int main() {
	
      int L[] = {1, 2, 3,5,5}, R[] = {3,5, 5, 7}, n = 3;
      
      cout<<maxOcc(L, R, n);

    
}

package DP;

import java.io.*;
import java.util.*;
import static java.lang.System.out;

class bestCoinCombination {

	public static int count( int S[], int m, int n )
	{
		int table[]=new int[n+1];
		table[0]=1;
		
		for(int i=0;i<m;i++) {
			for(int j=S[i];j<=n;j++) {
				table[j]+=table[j-S[i]];
			}
		}
		return table[n];
	}



	public static void main (String[] args) {
		
	    int coins[]={1, 2, 3}, sum=4, n=3;
	
	  
	   System.out.println(count(coins, n, sum));
	    
	}
}



package DP;

public class eggDrop{ 

	/* Function to get minimum number of 
	trials needed in worst case with n 
	eggs and k floors */
	static int eggDropM(int n, int k) 
	{ 
		if(k==1 || k==0)
			return k;
		if(n==1)
			return k;
		
		int x,res;
		int min=Integer.MAX_VALUE;
		
		for(x=1;x<=k;x++) {
			res=Math.max(eggDropM(n-1,x-1),eggDropM(n,k-x));
			if(min>res)
				min=res;
		}
		return min+1;
	} 

	// Driver code 
	public static void main(String args[]) 
	{ 
		int n = 2, k = 10; 
		System.out.print("Minimum number of "
						+ "trials in worst case with "
						+ n + " eggs and " + k 
						+ " floors is " + eggDropM(n, k)); 
	} 
	
} 


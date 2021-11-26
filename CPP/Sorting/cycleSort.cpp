// C++ program to implement cycle sort 
#include <iostream> 
using namespace std; 

// Function sort the array using Cycle sort 
void cycleSort(int arr[], int n) 
{ 
	int writes=0;
	for(int cycle_start=0;cycle_start<=n-2;cycle_start++){
		int item=arr[cycle_start];
		int pos=cycle_start;
		for(int i=cycle_start+1;i<n;i++){
			if(item>arr[i]){
				pos++;

			}
			
		}
		if(pos==cycle_start){
				continue;
			}
		if(item==arr[pos]){
			pos++;
		}
		if(pos!=cycle_start){
			swap(arr[pos],item);
			writes++;
		}
		while(pos!=cycle_start){
			pos=cycle_start;
			for(int i=cycle_start+1;i<n;i++){
			if(item>arr[i]){
				pos++;

			}
			
		}
		if(item==arr[pos]){
			pos++;
		}
		if(arr[pos]!=item){
			swap(arr[pos],item);
			writes++;
		}
		}
	}
} 

// Driver program to test above function 
int main() 
{ 
	int arr[] = { 1, 8, 3, 9, 10, 10, 2, 4 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cycleSort(arr, n); 

	cout << "After sort : " << endl; 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
	return 0; 
} 

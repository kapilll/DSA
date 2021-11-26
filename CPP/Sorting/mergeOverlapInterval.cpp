#include <bits/stdc++.h>
using namespace std;

struct Interval{
    int s,e;
};
bool myComp(Interval a,Interval b){
    return (a.s<b.s);
}

void mergeIntervals(Interval arr[],int n){
    sort(arr,arr+n,myComp);
    int index=0;
    for(int i=1;i<n;i++){
        if(arr[index].e>=arr[i].s){
            arr[index].e=max(arr[index].e,arr[i].e);
            arr[index].s=min(arr[index].s,arr[i].s);
        }
        else{
            index++;
            arr[index]=arr[i];
        }
    }
    cout << "\n The Merged Intervals are: ";  
    for (int i = 0; i <= index; i++)  
        cout << "[" << arr[i].s << ", " << arr[i].e << "] ";
}
  
int main() 
{ 
    Interval arr[] =  { {5,10}, {3,15}, {18,30}, {2,7} }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    mergeIntervals(arr, n); 
    
    return 0; 
} 

/*Given a set of time intervals in any order, merge all overlapping intervals into one and output the result which should have only mutually exclusive intervals. Let the intervals be represented as pairs of integers for simplicity. 
For example, let the given set of intervals be {{1,3}, {2,4}, {5,7}, {6,8}}. The intervals {1,3} and {2,4} overlap with each other, so they should be merged and become {1, 4}. Similarly, {5, 7} and {6, 8} should be merged and become {5, 8}
 */
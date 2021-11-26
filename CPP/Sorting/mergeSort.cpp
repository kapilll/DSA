#include <iostream>
#include <algorithm>
using namespace std;

void merge(int arr[],int l,int m,int h){
    int n1=m-l+1; int n2=h-m;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++){
        left[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++){
        right[j]=arr[m+1+j];
    }
    int i=0;int j=0;int k=l;
    while(i<n1 && j<n2){
        if(left[i]<right[j]){
            arr[k++]=left[i++];
        }
        else{
            arr[k++]=right[j++];
        }
    }
     while(i<n1)
        arr[k++]=left[i++];
    while(j<n2)
        arr[k++]=right[j++]; 
}

void mergeSort(int a[],int l,int r){
    if(r>l){
        int m=l+(r-l)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int main() {
	
    int a[]={10,5,30,15,7};
	int l=0,r=4;
	
	mergeSort(a,l,r);
	for(int x: a)
	    cout<<x<<" ";
}
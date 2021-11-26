#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int col[3];
    for(int i=0;i<3;i++){
        col[i]=0;
    }
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            col[0]++;
        }else if(arr[i]==2){
            col[1]++;
        }else if(arr[i]==3){
            col[2]++;
        }
    }
    sort(col,col+3);
    int res=col[0]+col[1];
    cout<<res;
    

}
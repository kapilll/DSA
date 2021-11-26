#include <bits/stdc++.h> 
using namespace std; 

const int CHAR=256;
int leftMost(string &str) 
{   
    
    bool visited[CHAR];
    fill(visited,visited+CHAR,false);
    int res=-1;
    for(int i=str.length()-1;i>=0;i--){
        if(visited[str[i]])
        res=i;
        else
        visited[str[i]]=true;
    }
    
    return res;
    /*
    int fiIndex[CHAR]={0};
    fill(fiIndex,fiIndex+CHAR,-1);
    int res=INT_MAX;
    for(int i=0;i<str.length();i++){
        int fi=fiIndex[str[i]];
        if(fi==-1){
            fiIndex[str[i]]=i;
        }
        else{
            res=min(res,fi);
        }
        return (res==INT_MAX)?-1:res;
    }*/
    /*int count[CHAR]={0};
    for(int i=0;i<str.length();i++){
        count[str[i]]++;
    }
    for(int i=0;i<str.length();i++){
        if(count[str[i]]>1)return i;
    }
    return -1;*/
}
 
int main() 
{ 
    string str = "geeksforgeeks";
    cout<<"Index of leftmost repeating character:"<<endl;
    cout<<leftMost(str)<<endl;  
    
    return 0; 
} 
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    vector<int>uid(n);
    vector<int>bal(n);
    for(int i=0;i<n;i++){
        cin>>uid[i]>>bal[i];
    }
    int t;
    cin>>t;
    vector<string>ans;
    while(t--){
        int sender,receiver,amount;
        cin>>sender>>receiver>>amount;
        int i1=-1,i2=-1;
        for(int j=0;j<n;j++){
            if(uid[j]==sender){
                i1=j;
            }
            if(uid[j]==receiver){
                i2=j;
            }     
        }
        if(sender!=-1&&receiver!=-1&&bal[i1]>=amount){
            bal[i1]-=amount;
            bal[i2]+=amount;
            ans.push_back("Success");
        }
        else{
            ans.push_back("Failure");
        }   
    }
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(bal[j]>bal[j+1]){
                swap(bal[j],bal[j+1]);
                swap(uid[j],uid[j+1]);
            }
        }
        
    }
    for(string s:ans){
        cout<<s<<endl;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<uid[i]<<" "<<bal[i]<<endl;
    }
    
    
   
    

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
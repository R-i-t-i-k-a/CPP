#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool CanCook(long long P, long long cooks, vector<long long>& ranks, long long mid){
    long long prata_cur = 0 ;
    for(int i = 0 ; i < cooks ; i++ ){
        int R = ranks[i], j = 1 ;
        int timeTaken = 0 ;
        while(true){
            if( timeTaken + R * j <= mid){
                ++prata_cur;
                timeTaken += R * j ;
                ++j ;
            }else break;
        }
    }
    if(prata_cur < P){
        return false;
    }else{
        return true;
    }
}

int prata_ready(long long P, long long cooks, vector<long long>& ranks){
    long long start=0; //minimum time - 0 prata
    long long MaxR= *max_element(ranks.begin(),ranks.end());
    long long end= P * (MaxR) * (MaxR+1) / 2; //maximum time , most rank cook makes all pratas
    while(start<=end){
        long long mid=start+(end-start)/2;
        bool canCook=CanCook(P, cooks, ranks, mid);
        if(!canCook){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return start;
}

int main(){
    long long cases;
    cout<<"Enter number of cases : ";
    cin>>cases;
    vector<long long> ans;
    for(long long i=0;i<cases;i++){
        long long Prata;
        cout<<"Enter number of pratas for case "<<i+1<<": ";
        cin>>Prata;
        long long cooks;
        cout<<"Enter number of cooks for case "<<i+1<<": ";
        cin>>cooks;
        vector<long long> ranks;
        cout<<"Enter rank of each cook : ";
        for(long long j=0;j<cooks;j++){
            long long val;
            cin>>val;
            ranks.push_back(val);
        }
        ans.push_back(prata_ready(Prata, cooks, ranks));
    }
    cout<<"The answer for each case is as follows : "<<endl;
    for(long long i=0;i<cases;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
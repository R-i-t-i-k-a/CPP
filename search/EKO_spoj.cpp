#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool checkCut(vector<int>& trees, long long n, long long m, long long mid){
    long long cuttedAmount=0;
    for(long long i=0;i<n;i++){
        long long cut_ith_tree=trees[i]-mid;
        if(cut_ith_tree<0){
            cut_ith_tree=0;
        }
        cuttedAmount+=cut_ith_tree;
    }
    if(cuttedAmount>m){
        return true;
    }else{
        return false;
    }
}

int requiredHieght(vector<int>& trees, long long n, long long m){
    long long start=1; //minimum length we can cut to get m 
    long long end= *max_element(trees.begin(),trees.end()); //maximum length we can cut to get m 
    while(start<=end){
        long long mid=start+(end-start)/2;
        bool check=checkCut(trees,n,m,mid);
        if(check){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return start;
}

int main(){
    long long n;
    cout<<"Number of trees : ";
    cin>>n;
    long long m;
    cout<<"Required wood in meters : ";
    cin>>m;
    vector<int> trees;
    cout<<"Enter the length of each tree : ";
    for(long long i=0;i<n;i++){
        int val;
        cin>>val;
        trees.push_back(val);
    }
    cout<<requiredHieght(trees,n,m);
    return 0;
}
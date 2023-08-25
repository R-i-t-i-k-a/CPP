//working as follows
/*
n=10 k=2
mask=1<<k  =>mask=100
ans=n|mask =>1010|100=1110=14
*/

#include <iostream>
using namespace std;

int setKthBit(int n,int k){
    int mask=1<<k;
    int ans=n|mask;
    return ans;
}

int main(){
    int N;
    cout<<"Enter the number: ";cin>>N;
    int k;
    cout<<"Enter kth bit to set: ";cin>>k;
    int ans=setKthBit(N,k);
    cout<<ans;
    return 0;
}
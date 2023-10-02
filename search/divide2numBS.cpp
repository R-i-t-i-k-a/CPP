//dividing two numbers using binary search
#include <iostream>
#include <vector>

using namespace std;

int divide_numbers(int n1,int n2){
    int s=0,e=abs(n1);
    int ans;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(abs(mid*n2)<=abs(n1)){
            ans=mid; //storing ans
            s=mid+1; //searching in right
        }else{
            e=mid-1; //left search
        }
        mid=s+(e-s)/2;
    }
    if((n1 && n2 > 0)||(n1 && n2 < 0)){
        return ans;
    }else{
        return -ans;
    }
}

int main(){
    int num1,num2,i;
    vector<int> arr={};
    cout<<"Enter dividend : ";cin>>num1;
    cout<<"Enter divisor : ";cin>>num2;
    int ans=divide_numbers(num1,num2);
    cout<<ans;
    return 0;
}
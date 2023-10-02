//finding odd occuring element using binary search
#include<iostream>
#include<vector>
using namespace std;

int odd_occuring_element(vector<int> arr){
    int s=0;
    int e=arr.size()-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(s==e){
            return s;
        }
        if(mid%2==0){
            if(arr[mid]==arr[mid+1]){
                s=mid+2;
            }else{
                e=mid;
            }
        }else{
            if(arr[mid]==arr[mid+1]){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        mid=s+(e-s)/2;
    }
    return -1;
}

int main(){
    vector<int> arr{1,1,2,2,3,3,4,4,3,3,600,4,4};
    int ans=odd_occuring_element(arr);
    cout<<arr[ans];
    return 0;
}
//searching an element in a nearly sorted array in logarithmic time

#include<iostream>
#include<vector>

using namespace std;

int b_search(vector<int>arr,int target){
    int s=0,e=arr.size()-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==target)
            return mid;
        if(mid-1>=0 && arr[mid-1]==target)
            return mid-1;
        if(mid+1<arr.size() && arr[mid+1]==target)
            return mid+1;

        if(arr[mid]<target){
            //right search
            s=mid+2;}
        else{
            //left search
            e=mid-2;}
        mid=s+(e-s)/2;
    }
    return -1;
}

int main(){
    vector<int> arr={};
    int n,i,x;
    cout<<"Enter array length";
    cin>>n;
    for(i=0;i<n;i++){
        cout<<i<<"th element: ";
        cin>>x;
        arr.push_back(x);
    }
    int target;
    cout<<"Enter element to search : ";
    cin>>target;
    int ans=b_search(arr,target);
    cout<<"element found at index : "<<ans;
    return 0;
}
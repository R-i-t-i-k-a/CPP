//to search an element by exponential search
#include <iostream>
#include <vector>
using namespace std;

void binary_search(vector<int>& a, int start, int end, int s){
    int mid;
    while(start<=end){
        mid=start+(end-start)/2;
        if(a[mid]==s){
            cout<<"Element found at index "<<mid<<endl;
            break;
        }else if(a[mid]>s){
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    //cout<<"Element found at index "<<end<<endl;
}

int main(){
    vector<int> arr={3,4,5,6,11,13,14,15,56,70};
    int search_element=15;
    if(arr[0]==search_element){
        cout<<"Element "<<search_element<<" found at index "<<0<<endl;
    }else{
        int i=1;
        while (i<arr.size() && arr[i]<=search_element)
        {
            i=i*2;
        }
        binary_search(arr,i/2,i,search_element);
    }
    return 0;
}
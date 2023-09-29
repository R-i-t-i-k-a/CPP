#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr{1,4,3,2,7,10,6};
    int x;
    cout<<"Enter element to search for : ";
    cin>>x;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==x){
            cout<<"Element found at "<<i<<" index";
        }
    }
    return 0;
}
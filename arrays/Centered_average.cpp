//g prep
//Return the "centered" average of an array of ints, 
// which we'll say is the mean average of the values, except ignoring the largest and smallest values in the array. 
// If there are multiple copies of the smallest value, ignore just one copy, and likewise for the largest value. 
// Use int division to produce the final average. You may assume that the array is length 3 or more.

// centered_average([1, 2, 3, 4, 100]) → 3
// centered_average([1, 1, 5, 5, 10, 8, 7]) → 5
// centered_average([-10, -4, -2, -4, -2, 0]) → -3

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findCenteredAverage(vector<int>& input_array){
    int arraySize = input_array.size();

    if(input_array.size()<3)    return -1;

    int maxElement = *max_element(input_array.begin(), input_array.end());
    int minElement = *min_element(input_array.begin(),input_array.end());

    // input_array.erase(find(input_array.begin(), input_array.end(),maxElement));
    // input_array.erase(find(input_array.begin(), input_array.end(),minElement));

    int sum = 0;
    for(int index = 0 ; index < arraySize ; index++){
        sum += input_array[index];
    }

    return ((sum-minElement-maxElement)/(arraySize-2));
}

int main(){
    vector<int> input_array;
    int n;
    cout<<"Enter the size of the array(Greater than 3) : ";
    cin>>n;
    cout<<"Enter the values in the array "<<endl;
    for(int i = 0 ; i < n ; i++){
        int val;
        cin>>val;
        input_array.push_back(val);
    }
    int ans = findCenteredAverage(input_array);
    cout<<"The centered average for the given array is : "<<ans<<endl;
    return 0;
}
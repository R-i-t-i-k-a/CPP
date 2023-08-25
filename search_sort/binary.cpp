#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int>& arr, int x, int s, int e)
{
    if (e >= s)
    {
        int mid=s+(e-s)/2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            binary_search(arr, x, s,mid-1);
        else
            binary_search(arr, x, mid+1, e);
    }
    else
        return -1;
}

int main()
{
    vector<int> arr{1, 4, 3, 2, 7, 10, 6};
    sort(arr.begin(), arr.end());
    int x;
    cout << "Enter element to search for : ";
    cin >> x;
    int ans = binary_search(arr, x, 0, arr.size()-1);
    cout << "Element found at " << ans << " index";
    return 0;
}
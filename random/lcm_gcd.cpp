#include <iostream>
#include <unordered_map>

using namespace std;

// Function to calculate GCD
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate LCM
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int N;
    cin >> N;

    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int result = 0;
    if(N==1){
        result=1;
    }
    for (int i = 0; i < N-1; i++) {
        for (int j = i + 1 ; j < N; j++) {
            int currentGcd = gcd(arr[i], arr[j]);
            int currentLcm = lcm(arr[i], arr[j]);
            cout<<arr[i]<<"i "<<arr[j]<<"j "<<endl;
            cout<<currentLcm<<"l "<<currentGcd<<"g "<<endl;
            int diff = currentLcm - currentGcd;
            if (diff == 0)
                result++;
        }
    }

    cout << result << endl;

    return 0;
}
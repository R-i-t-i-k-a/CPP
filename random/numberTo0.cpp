#include <iostream>
#include <vector>

using namespace std;

// Function to find the smallest prime factor of a number
int smallestPrimeFactor(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return i;
        }
    }
    return n;
}

int main() {
    int N;
    cin >> N;

    int steps=0;
    while (N > 0) {
        int spf = smallestPrimeFactor(N);
        N -= spf;
        steps++;
    }

    cout<<steps<<endl;

    return 0;
}

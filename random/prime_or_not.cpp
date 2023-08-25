//prints all prime numbers from 1 to user input n.
//comments removal print prime or not for all numbers.

#include <iostream>
using namespace std;

void prime(int n)
{
    for (int j = 0; j <= n; j++)
    {
        if (j == 0)
        {
            // cout <<j<<" is neither prime nor composite" << endl;
        }
        else if(j == 1){
            // cout<<j<<" is not prime"<<endl;
        }
        else
        {
            int p = 0;
            for (int i = 2; i < j; i++)
            {
                if (j % i == 0)
                {
                    p = 1;
                    // cout << j << " is not prime" << endl;
                    break;
                }
            }
            if (p == 0)
            {
                cout << j << endl;
            }
        }
    }
}

int main()
{
    int n;
    cout << ("Enter the number to check prime: ");
    cin >> n;
    prime(n);
    return 0;
}
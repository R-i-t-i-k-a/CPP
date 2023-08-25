#include <iostream>
using namespace std;
int main(){
    int a=5;
    int b=(++a)*(++a); //gives 49 due to operator precedence
    printf("%d",b);
    return 0;
}
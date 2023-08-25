#include <iostream>
using namespace std;
int main(){
    unsigned int a=-1;
    a=~a; 
    //COMPUTATION OF ~
    //if a is positive => ~a=-a-1
    //if a is negative => ~a=+a-1
    printf("%d\n",a);
    return 0;
}
// 4 pillars : Encapsulation, Inheritance, Polymorphism, Abstraction
#include <iostream>
using namespace std;

class Animal{
    private :
        int age;
    public : 

        int getAge(){
            return age;
        }
        void setAge(int age){
            this->age = age;
        }
        void eat(){
            cout<<"Eating"<<endl;
        }
};
//single level inheritance
class Dog: public Animal{
    public:
        //virtual to overcome upcasting
        virtual void bark(){
            cout<<"WOOF! WOOF!"<<endl;
        }
};
//multi level inheritance
class Pug: public Dog{
    public:
    //function overriding - run time polymorphism
    void bark(){
        cout<<"woof woof"<<endl;
        //to define custom behaviour of pug bark
    }
};

class A {
    public:
        int wholeNumber;
        void number(){
            cout<<"Number is a whole number."<<endl;
        }
        void nums(){
            cout<<"Number is a natural number. class A"<<endl;
        }
};
class B {
    public:
        int naturalNumber;
        void num(){
            cout<<"Number is a natural number."<<endl;
        }
        void nums(){
            cout<<"Number is a natural number. class B"<<endl;
        }

};
//multiple inheritance
class C : public A, public B {
    public:
        int integer;

        //polymorphism - compile time
        //sum function existing in multiple forms
        //function overloading - do not change ret type
        //but only the number of variables
        int sum(int a, int b, int c){
            return a+b+c;
        }
        int sum(int a, int b){
            return a+b;
        }
        int sum(int a, float b){
            return a+b+10;
        }
};
//what if - same behaviour in class A as well as B
//how would class Cl know which behaviour to access
//Diamond problem kind of
//actual diamond problem -> A->B,C->D 
class Cl : public A, public B {
    public:
        int val;
        //operator overloading
        void operator+(Cl& b){
            int val1 = this->val;
            int val2 = b.val;
            cout<<val1-val2<<endl;
            //did difference using + operator
        }
};
int main(){
    C obj;
    obj.num();
    obj.number();
    Cl objTest;
    //objTest.nums(); //error giving diamond problem
    //now to solve 
    objTest.A::nums();
    objTest.B::nums();
    cout<<obj.sum(1,2,3)<<" "<<obj.sum(5,4)<<" "<<obj.sum(0,2.5f)<<endl;
    //2.5f to represent that it is a floating point number
    Cl a,b;
    a.val = 20;
    b.val = 10;
    a+b; //similar to a.add(b);
    Pug tommy;
    tommy.bark();

    //parent class pointer to child class creation
    //upcasting
    Dog* sherry = new Pug();
    sherry->bark(); 
    //dog class bark func runs - pointer method
    //to change that use virtual func - (object method) in dog class
    //as shown

    //downcasting
    Pug* pup = (Pug*)new Dog();
    pup->bark(); 

    return 0;

}
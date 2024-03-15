//syntax understanding
#include <iostream>
using namespace std;

// class Animal{
//     char c;
//     double d;
//     int i;
//     short s;
// }; returns size to be 24 - 8+8+8 //Padding

// class Animal{
//     double d;
//     int i;
//     short s;
//     char c; 
// }; returns size to be 16 - 8+4+2+2 //greedy allignment

class Animal{
    //state or properties
    //to mark all data below to be public we do this
    // by default private
    //or mark private:
    private:
    int weight;
    public:
    int age;
    string name;
    
    //default constructor
    Animal(){
        //called whenever an object is created
        this->age = 0; //using this is a good practice
        this->name = "";
        this->weight = 0;
        cout<<"Constructor called"<<endl;
    }

    //parameterized constructor 1
    Animal(int age){
        //takes in a parameter
        this->age = age;
        cout<<"Paremeterized constructor 1 called."<<endl;
    }

    //parameterized constructor 2
    Animal(int age, int weight, string name){
        //takes in a parameter
        this->age = age;
        this->weight = weight;
        this->name = name;
        cout<<"Paremeterized constructor 2 called."<<endl;
    }

    //copy constructor
    Animal(Animal& obj){
        this->age = obj.age;
        this->name = obj.name;
        this->weight = obj.weight;
        cout<<"Copy constructor called for "<<obj.name<<endl;
    }

    //function - define behaviour
    void eat(){
        cout<<name<<" is eating."<<endl;
    }
    void sleep(){
        cout<<name<<" is sleeping."<<endl;
    }
    int getWeight(){
        return weight;
    }
    // void setWeight(int w){
    //     weight = w;
    // }
    void setWeight(int weight){
        this->weight = weight; //this pointer to current obj , other weight the one passed to function
    }

    //desctructor -- called automatically for static allocation -- manually for dynamic allocation
    ~Animal(){
        cout<<"Inside desctructor function"<<endl;
    }
};

int main(){
    // cout<<sizeof(Animal)<<endl; - size of the class

    //object creation

    //static
    Animal cat;
    //assign value else garbage returned 
    cat.age = 5;
    cat.name = "Hello Kitty";
    cout<<"Age of cat is "<<cat.age<<endl; // . operator to access properties
    cout<<"Name of cat is "<<cat.name<<endl;
    //to call a function/behaviour within the class
    cat.eat();
    cat.sleep();
    //to access a private member - getter and setter functions used.
    cat.setWeight(7);
    cout<<(cat.getWeight())<<endl;

    //dynamic memory - new(to allocate memory) and delete(to deallocate memory)
    //desctructor called dynamically using delete
    Animal* dog = new Animal; //obj dob created using dynamic memory
    (*dog).age = 3;
    //alter
    dog->name = "Jacky";
    cout<<"Age of dog is "<<(*dog).age<<endl;
    cout<<"Name of dog is "<<dog->name<<endl;
    dog->eat();
    dog->sleep();
    delete dog;
    Animal* testConstructor1 = new Animal(6);
    Animal* testConstructor2 = new Animal(6,101,"Tom");
    delete testConstructor1; delete testConstructor2; //manual destructor call for testconstructors
    //copy objects 2 ways - copy constructor called for this
    Animal t1 = cat;
    Animal t2(t1);
    return 0;
}
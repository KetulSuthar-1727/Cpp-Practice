#include <bits/stdc++.h>
using namespace std;

// This is the polymorphism
// Compile-time polymorphism 
// In this polymorphism we create the same name function with the different name or types of parameters
class Maths{
public:
  int sum (int a, int b){ // In this sum function we have passsed the a and b parameteres
    cout << "This has the integer paramteres" << endl;
    return a + b;
  }

  int sum(int a, int b , int c){ // In this sum function we have passed the a , b, and c parameters
    cout << "This has the three parameteres" << endl;
    return a + b + c;
  }

  int sum(float a, float b){
    cout << "This has float parameteres" << endl;
    return a + b;
  }
};

// Operator overloading

class Name{

public:
  int value;

  void operator + (Name & obj2){
    int val1 = this->value;
    int val2 = obj2.value;

    cout << val1 + val2 << endl;
  }

};

// Run-time polymorphism also called function overriding
class Animal{
public:

  Animal(){
    cout << "I am inside the animal constructor" << endl;
  }
  
  void speak(){
    cout << "Speaking" << endl;
  }

};

class Dog: public Animal{ // We have inherited the calss animal so the speak function is already inherited in this class
public:

  Dog(){
    cout << "I am inside the Dog constructor" << endl;
  }

  // This speak function is overridden

  void speak(){   // But here we have explicitly declared the same name function as the super class
    cout << "Barking" << endl;  // So this function will be executed rather then the Animal class function
  }

};


int main() {
    
  Name obj1, obj2;
  obj1.value = 10;
  obj2.value = 20;

  obj1 + obj2; // Directly writting without defining hat the opertaor + does show s the error

  Dog d;
  d.speak(); // Braking will be printed

  Animal *obj = new Animal;
  obj->speak();

  Dog *ob2 = new Dog;
  ob2->speak();

  // This is called the UpCasting
  // In this we have created parent class pointer and created the object of the child class
  Animal *a = new Dog(); 
  a->speak();

  // If we want to print the barking of child class function then we have to declare the Parent class function as a virtual using the virtual Keyword

  // DownCasting
  Dog *b = (Dog* ) new Animal(); // DownCasting is not supported thats why used (Dog*) in front to typecast
  b->speak();

  // In both the cases UpCasting and DownCasting the pointer function is called in first case the pointer is Animal class so the Animal class function will be called and in the second case the Dog class pointer so the Dog class function will be called

  // We have to use the virtual keyword for the Accessing the obj class function 
  // virtual keyword is written in front of the parent class function

  Animal *a = new Animal(); // In this case the animal constructor is called only
  Dog *b = new Dog(); // In this case both constructor is called because the dog class inherit the animal class
  Animal *c = new Dog(); // In this case both constructor is called because the object is dog type it refers to the animal class pointer but still it is a dog type object so it calls the both constructor
  Dog *d = new Animal(); // In this case only the Animal class constructor is called because object is created of the animal type and it doesnot inherit anything

  return 0;
}
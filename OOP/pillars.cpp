#include <bits/stdc++.h>
using namespace std;
// single inheritance
class Animal {

private:
	int age;
	int weight;

public:

	void eat(){
		cout << "Eating" << endl;
	}

	int getAge(){
		return this->age;
	}
	void setAge(int age){
		this->age = age;
	}

	int getWeight(){
		return this->weight;
	}
	void setWeight(int weight){
		this->weight = weight;
	}	

};
class dog :public Animal{

	
};

// Mulitilevel Inheritance
class Fruit{
public:
	string name;

};
class Mango :public Fruit{
	int size;
};
class Alphanso :public Fruit{
	int weight;
};

// Multiple Inheritance
class A{
public:

	int chemistry;
	A(){
		chemistry = 2010;
	}
};

class B{
public:
	
	int chemistry; // this is the diamond problem in which we have the same name of the property as the parent class
	B(){
		chemistry = 4320;
	}
};

class C :public A, public B{
public:

	int physics;
	// obj.A::chemistry << " "  << obj.B::chemistry 
	// by using this we can resolve the diamond problem
};

// heirarchicel Inhertitance
class Car{
	string name;

	void speed(){
		cout << "Speeding up" << endl;
	}
};
class Fortuner: public Car{
	int seats;
};
class Scorpio: public Car{
	int size;
};


int main() {
		
	C obj;
	
	cout << obj.A::chemistry << " "  << obj.B::chemistry << " " << endl;

	return 0;
}
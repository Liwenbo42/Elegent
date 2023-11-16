#include<iostream>

using namespace std;
////正常应该是先有参，后拷贝，再拷贝到a， 
class A {
	public: 
	A() {
		cout << this << " ：无参" << endl; 
	}
	A(int m){
		cout << this << ": 有参 " << endl;
	}
	A(const A &a){
		cout << this << "：拷贝" << endl; 
	}
};

A fun(){
	A temp(3);
	return temp;
}

int main(){
	A a = fun();
	cout << "a :" << &a << endl;
	return 0;
}

#include<iostream>

using namespace std;
////����Ӧ�������вΣ��󿽱����ٿ�����a�� 
class A {
	public: 
	A() {
		cout << this << " ���޲�" << endl; 
	}
	A(int m){
		cout << this << ": �в� " << endl;
	}
	A(const A &a){
		cout << this << "������" << endl; 
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

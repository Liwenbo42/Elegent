#include<iostream>

using namespace std;

class A{
	public:
	A(int x) : x(x){
		cout << this <<" : "<< "Class A:" << x << endl;
	}
	A(const A &a){
		cout << this <<"copy from:" << &a << endl;
	}
	void operator=(const A &a){
		cout << this <<" assign from" << &a << endl;
	}
	
	int x;
};

class B1 {
	public:
	B1() = default;
	B1(const B1 &){
		cout << "B1 copy constructor" << endl;
	} 
};

class B2 {
	public:
	B2() = default;
	B2(const B2 &){
		cout << "B2 copy constructor" << endl;
	} 
};


class B3 {
	public:
	B3() = default;
	B3(const B3 &){
		cout << "B3 copy constructor" << endl;
	} 
};

class B {
	public:
		B1 b1;
		B2 b2;
		B3 b3;
};

class Data{
	public:
	Data() : __x(100), __y(100), a(34) {
		cout << "default constructor " << endl;
	}
	int x() {
		return __x;
	}
	int y(){
		return __y;
	}
	~Data(){
		cout << "哈哈哈" << endl;
	}
	
	private:
	int __x, __y;
	A a;
};

int main(){
	B b;
	B b1 =b;
	
	Data d;
	cout << d.x() <<" " << d.y() << endl;
	A a(45); // 显式调用构造函数
	A b11(a); // 显式调用拷贝构造函数
	cout << "address: a  " << &a << endl;
    a = 78;
	return 0;
}

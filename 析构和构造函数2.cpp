#include<iostream>
using namespace std;

#define BEGINS(x) namespace x{
#define ENDS(x) }

BEGINS(test1)

class A {
	public:
		A() : x(1111){
			cout << "23500" << endl;
		}
		void say() const{
			cout << x << endl;
		}
		int x;
};

void main(){
	const A a;
	a.say();
	return;
}

ENDS(test1)

int main(){
	test1 :: main();
	return 0;
} 

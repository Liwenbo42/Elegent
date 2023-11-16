#include<iostream>
#include <ctime> // 添加这行来包含ctime头文件
using namespace std;

#define BEGINS(x) namespace x{
#define ENDS(x)}

BEGINS(haizei)

class A{
	private:
		int x, y;
	public:
		A():x(0), y(0){
			
		} 
		A(int a, int b):x(a), y(b){
			z1 = z2 = z3 = rand();
			cout << this << " rend value" << z1 << endl;
		}
		void fun(A &a){
			cout << "A:" << a.x << "  " << a.y << endl;
		}
		A operator+(int x) const {
			
			return A (this->x + x, this->y + x);
		}
		
		A &operator+=(int x){
			this->x += x;
			this->y +=x;
			return *this;	
		}
		
		A operator++(int){
			A ret(*this);
			this->x +=1;
			this->y +=1;
			cout << "P++" <<this->x << endl;
			return ret;
		}
		
		A &operator++(){
			this->x += 1;
			this->y +=1;
			cout <<"LSHI"<< this->x <<endl; 
			return *this;
		}
		
		friend void fun1(A &a);
		friend ostream &operator<<(ostream &out, const A &);
		friend A operator+(const A & a, const A & b);
//		friend A operator+(const A &, const int &);
		int z1, z2, z3;
};

void fun1(A &a){
	cout << "友元函数A:" << a.x << "  " << a.y << endl;
}

ostream &operator<<(ostream &out, const A &a){
	out << "运算符重载：" << a.x << "  " << a.y;
	return out; 
}

A operator+(const A &a, const A &b){
	return A(a.x + b.x, a.y + b.y); 
}

ENDS(haizei)


BEGINS(test1)
using namespace haizei;
int main() {
	
	srand(time(0));
	
	A a(1,3), b(3, 5);
	a.fun(a);
	fun1(a);
	cout << a << endl; 
	cout << (a + b) << endl;
	cout << (a + 5) << endl; 
	cout <<  (a + (a + b)) << endl;
	A z(100, 1000);
	cout << (z + 6) << endl;
	
	A *pp = &a;
	int A::* px = &A::z1;
	cout << pp->*px << endl;
	px = &A::z2;
	cout << pp->*px << endl;
	px = &A::z3;
	cout << pp->*px << endl;
	return 0;
}
ENDS(test1)

BEGINS(test2)

using namespace haizei;

int main(){
	//+=
	A p(3, 4);
	cout << ((p += 5) +=6) << endl;
	// p++,  ++p
	cout << "p++ :" << (p++) << endl;
	cout << p << endl;
	cout <<"++p"<< (++p) << endl;
	int n = 45;
	(++n)++;
	cout << n << endl;
	(++p)++;
	cout << "(++p)++" << p << endl;
	return 0;
}

ENDS(test2)
int main(){
	
	test2::main();
	
	return 0;
}

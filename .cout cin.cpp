#include<iostream>
#include<stdio.h>

#define BEGINS(x) namespace x{
#define ENDS(x) }

BEGINS(haizei)

class istream {
	public:
	istream& operator>>(int &x);
//	istream& operator>>(char x);
};

class ostream {
	public:
	ostream& operator<<(int x);
	ostream& operator<<(char x);
};

istream& istream::operator>>(int &x){
	scanf("%d", &x);
	return *this;
}

ostream& ostream::operator<<(int x){
	printf("%d", x);
	return *this;
}

ostream& ostream::operator<<(char x){
	printf("%c", x);
	return *this;
}

ostream cout;
istream cin;
const char endl = '\n';

ENDS(haizei)

int main(){
	int n =123;
	std::cin >> n;
	std::cout <<  n << std::endl;
	haizei::cin>>n;
	haizei::cout << n << haizei::endl; 
}

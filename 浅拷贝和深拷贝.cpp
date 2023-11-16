#include<iostream>

using namespace std;

#define BEGINS(x) namespace x{
#define ENDS(x)} 

class A {
	public:
		int x, y;
};

ostream &operator<<(ostream &out, const A &a){
		out <<"("<< a.x << "," << a.y << ")";
		return out;
}
BEGINS(haizei)



template<typename T>

class Vector {
	public:
//		Vector(int n = 100) : n(n), data (new T[n]) {}
		Vector(int n = 100) : n(n), data((T*)calloc(sizeof(T), n)) {}
		
		Vector(const Vector &a) : n(a.n) {
			data = (T*)malloc(sizeof(T) * n);
//			data = new T[n];
//			memcpy(data, a.data, sizeof(T) *n);   不可以这么用当传递 data中存储的对象也需要深拷贝时就错误了 
			for(int i = 0; i < n; i++){
				new(data + i) T(a.data[i]);
			} 
			return ;
		}
		
		T &at(int ind){ 
			return data[ind];
		
		}
		T &operator[](int ind){
			return data[ind];
		}
		void output(int m = -1){
			if (m == -1) m = n;
			if (data == nullptr) return;
			for(int i = 0; i < m; i++){
				cout << data[i] << " ";
			}
			cout << endl;
			return ;
		}
		
	private:
		T *data;
		int  n;
};

ENDS(haizei)

BEGINS(test1)
using namespace haizei;

int main(){
	 
	
	Vector<int> arr1;
	for(int i = 0; i < 10; i++){
		arr1.at(i) = i;
	}
	arr1.output(10);
	Vector<int> arr2(arr1);
	arr2.output(10);
	arr2[3] = 1000;
	arr1.output(10);
	arr2.output(10);
	return 0;
}

ENDS(test1)


BEGINS(test2)

using namespace haizei;

int main(){
	Vector<A> arr1;
	for(int i = 0; i < 10; i++){
		arr1[i] = (A){i, 2 * i};
	}
	arr1.output(10);
	Vector<A> arr2(arr1);
	arr2[3] = (A){4, 1000};
	arr1.output(10);
	arr2.output(10);
	
	return 0;
}

ENDS(test2)

BEGINS(test3)
using namespace haizei;

int main() {
//	Vector<Vector<int>> arr1;
//	Vector<Vector<int>> arr2(arr1);
    Vector<Vector<Vector<int>>> arr1;
	Vector<Vector<Vector<int>>> arr2(arr1);

	arr2[2][2][2] = 1000;
	
//	for(int i = 0; i < 3; i++){
//		arr1[i].output(3);
//	}
//	for(int i = 0; i < 3; i++){
//		arr2[i].output(3);
//	}
	
	return 0; 
}

ENDS(test3)

int main(){
	using namespace haizei; 
	test1 :: main();
	test2::main();
	test3::main();
	return 0;
} 

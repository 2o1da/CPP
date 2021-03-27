#include <iostream>
using namespace std;

void doSomething(int n)
{
	cout << &n << endl;
	n = 10;
	cout << "In doSomething " << n << endl;
}

void doSomething2(int& n) // reference를 쓰게 되면 변수 자체가 넘어가기 때문에 주소를 복사할 필요 없음  
{
	cout << &n << endl;
	n = 10; // const int& n 이면 할당하지 못함
	cout << "In doSomething2 " << n << endl;
}

void printElements(int(&arr)[5])
{
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

struct Something
{
	int v1;
	float v2;
};

struct Other
{
	Something st;
};

int main()
{
	int value = 5;

	int* ptr = nullptr;
	ptr = &value;

	int& ref = value; // 같은 메모리를 쓰는 것처럼 작동
	// value 변수의 또 다른 이름인 것처럼 사용할 수 있음, 별명

	cout << ref << endl; // 5

	ref = 10; // *ptr=10;

	cout << value << " " << ref << endl; // 10 10 

	cout << &value << endl;
	cout << &ref << endl;
	cout << ptr << endl;
	cout << &ptr << endl; // 포인터 변수 자체가 다른 주소를 갖고 있음

	//int& ref2 = value; //reference는 항상 초기화가 되어야 함, 별명이니까 원래 이름이 있어야 함, 리터럴은 못 들어감 (리터럴은 주소를 갖지 않기 때문)
	const int y = 8;
	//int& ref2 = y; // ref2에서 y값을 바꿀 수 있기 때문에 에러
	const int& ref2 = y;

	int value1 = 5;
	int value2 = 10;
	int& ref1 = value1;
	cout << ref1 << endl; // 5
	ref1 = value2;
	cout << ref1 << endl; // 10

	int n = 5;
	cout << n << endl; // 5
	cout << &n << endl;
	doSomething(n); // 10
	cout << n << endl; // 5  	
	
	cout << n << endl; // 5
	cout << &n << endl;
	doSomething2(n); // 10
	cout << n << endl; // 10  

	const int length = 5;
	int arr[length] = { 1,2,3,4,5 };
	printElements(arr);


	Other ot;
	int& v1 = ot.st.v1;
	v1 = 1;

	int x = 5;
	int* const ptr_x = &x;
	int& ref_x = x;

	*ptr_x = 10;
	ref_x = 10;
	// reference도 내부적으로 포인터로 되어있음
	cout << "x:" << x << endl;

	return 0; 
}
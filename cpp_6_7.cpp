#include <iostream>
#include <typeinfo>
using namespace std;

int* doSomething(int* ptr_a)
{
	return nullptr;
};

int main()
{
	int x = 5; // 모든 변수는 내부적으로 주소를 갖음

	cout << &x << endl; // & : Address-of operator:어떤 메모리 주소에 데이터를 담고 있는지 확인
	cout << (int)&x << endl; // 메모리 주소는 기본적으로 16진수이지만 10진수로 보고 싶을 때

	// 메모리 주소를 확인하는 건 의미가 없음
	// 하지만 메모리 주소를 변수에 담아 놓으면 편함
	// 포인터:메모리 주소 담는 변수
	
	// De-reference operator (*):포인터가 간접적으로 얘기하는 것을 직접적으로 들여다볼게
	// reference 의미가 CS에서 다양함
	// 보통 간접적으로 가르키는 것을 의미함
	// 포인터는 레퍼런스의 일부라고 볼 수 있음
	// C++에서는 포인터와 레퍼런스가 따로 있어서 용어 혼란스러울 수 있음
	cout << *(&x) << endl;
	cout << *&x << endl; // 상쇄, 소멸되는 것처럼 보이나 내부에서는 2가지를 거침

	// 포인터는 메모리 주소를 담는 변수
	typedef int* pint;
	//pint ptr_z = &x, ptr_y = &x;

	int* ptr_x = &x, //, ptr_y = &x; // ERROR: *은 오른쪽 붙이는 것을 추천하는 이유
		* ptr_y = &x; // 두세번째에도 포인터를 붙여줘야 함

	cout << ptr_x << endl;
	cout << *ptr_x << endl;
	
	// array에 element가 많은데 function parameter로 넣으면 전부 다시 복사가 되므로
	// 포인터로 첫번째 주소와 데이터 개수만 알려주면 됨

	cout << typeid(ptr_x).name() << endl; // int *, Pi(Pointer to integer)


 
	return 0;
}
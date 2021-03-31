#include <iostream>
#include <typeinfo>
using namespace std;

int* doSomething(int* ptr_a)
{
	return nullptr;
};

int main()
{
	int x = 5; // ��� ������ ���������� �ּҸ� ����

	cout << &x << endl; // & : Address-of operator:� �޸� �ּҿ� �����͸� ��� �ִ��� Ȯ��
	cout << (int)&x << endl; // �޸� �ּҴ� �⺻������ 16���������� 10������ ���� ���� ��

	// �޸� �ּҸ� Ȯ���ϴ� �� �ǹ̰� ����
	// ������ �޸� �ּҸ� ������ ��� ������ ����
	// ������:�޸� �ּ� ��� ����
	
	// De-reference operator (*):�����Ͱ� ���������� ����ϴ� ���� ���������� �鿩�ٺ���
	// reference �ǹ̰� CS���� �پ���
	// ���� ���������� ����Ű�� ���� �ǹ���
	// �����ʹ� ���۷����� �Ϻζ�� �� �� ����
	// C++������ �����Ϳ� ���۷����� ���� �־ ��� ȥ�������� �� ����
	cout << *(&x) << endl;
	cout << *&x << endl; // ���, �Ҹ�Ǵ� ��ó�� ���̳� ���ο����� 2������ ��ħ

	// �����ʹ� �޸� �ּҸ� ��� ����
	typedef int* pint;
	//pint ptr_z = &x, ptr_y = &x;

	int* ptr_x = &x, //, ptr_y = &x; // ERROR: *�� ������ ���̴� ���� ��õ�ϴ� ����
		* ptr_y = &x; // �μ���°���� �����͸� �ٿ���� ��

	cout << ptr_x << endl;
	cout << *ptr_x << endl;
	
	// array�� element�� ������ function parameter�� ������ ���� �ٽ� ���簡 �ǹǷ�
	// �����ͷ� ù��° �ּҿ� ������ ������ �˷��ָ� ��

	cout << typeid(ptr_x).name() << endl; // int *, Pi(Pointer to integer)


 
	return 0;
}
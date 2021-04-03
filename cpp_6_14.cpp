#include <iostream>
using namespace std;

void doSomething(int n)
{
    cout << &n << endl;
    n = 10;
    cout << "In doSomething " << n << endl;
}

void doSomething2(int &n) // reference�� ���� �Ǹ� ���� ��ü�� �Ѿ�� ������ �ּҸ� ������ �ʿ� ����
{
    cout << &n << endl;
    n = 10; // const int& n �̸� �Ҵ����� ����
    cout << "In doSomething2 " << n << endl;
}

void printElements(int (&arr)[5])
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

    int *ptr = nullptr;
    ptr = &value;

    int &ref = value; // ���� �޸𸮸� ���� ��ó�� �۵�
    // value ������ �� �ٸ� �̸��� ��ó�� ����� �� ����, ����

    cout << ref << endl; // 5

    ref = 10; // *ptr=10;

    cout << value << " " << ref << endl; // 10 10

    cout << &value << endl;
    cout << &ref << endl;
    cout << ptr << endl;
    cout << &ptr << endl; // ������ ���� ��ü�� �ٸ� �ּҸ� ���� ����

    //int& ref2 = value; //reference�� �׻� �ʱ�ȭ�� �Ǿ�� ��, �����̴ϱ� ���� �̸��� �־�� ��, ���ͷ��� �� �� (���ͷ��� �ּҸ� ���� �ʱ� ����)
    const int y = 8;
    //int& ref2 = y; // ref2���� y���� �ٲ� �� �ֱ� ������ ����
    const int &ref2 = y;

    int value1 = 5;
    int value2 = 10;
    int &ref1 = value1;
    cout << ref1 << endl; // 5
    ref1 = value2;
    cout << ref1 << endl; // 10

    int n = 5;
    cout << n << endl; // 5
    cout << &n << endl;
    doSomething(n);    // 10
    cout << n << endl; // 5

    cout << n << endl; // 5
    cout << &n << endl;
    doSomething2(n);   // 10
    cout << n << endl; // 10

    const int length = 5;
    int arr[length] = { 1, 2, 3, 4, 5 };
    printElements(arr);

    Other ot;
    int &v1 = ot.st.v1;
    v1 = 1;

    int x = 5;
    int *const ptr_x = &x;
    int &ref_x = x;

    *ptr_x = 10;
    ref_x = 10;
    // reference�� ���������� �����ͷ� �Ǿ�����
    cout << "x:" << x << endl;

    return 0;
}
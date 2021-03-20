#include <iostream>
#include <typeinfo>
using namespace std;

struct Something
{
    int a,b,c,d; // 4 X 4 = 16byte
};

int main()
{
    int x=3; // 4byte
    double d=1.0; // 8byte

    int *ptr_x=&x,*ptr_y=&x;
    double *ptr_d=&d;

    cout<<ptr_x<<endl;
    cout<<*ptr_x<<endl;

    cout<<ptr_d<<endl;
    cout<<*ptr_d<<endl;

    cout<<typeid(ptr_x).name()<<endl; // int *, pi:pointer to integer

    cout<<sizeof(x)<<endl;
    cout<<sizeof(d)<<endl;
    cout<<sizeof(&x)<<" "<<sizeof(ptr_x)<<endl;
    cout<<sizeof(&d)<<" "<<sizeof(ptr_d)<<endl; // 주소는 같음

    Something ss;
    Something *ptr_s; // WARNING:쓰레기, 엉뚱한 값이 들어있는데 호출

    cout<<sizeof(Something)<<endl; // 16
    cout<<sizeof(ptr_s)<<endl; // 포인터 주소(변수)는 고정
    
    return 0;
}
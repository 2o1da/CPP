#include <iostream>
using namespace std;

void doSomething(int n)
{
    n=10;

    cout<<"In doSomething "<<n<<endl;
}

void doSomething2(int &n)
{
    n=10;
    
    cout<<"In doSomething "<<n<<endl;
}

void printElements(const int(&arr)[5])
{
    for(int i=0;i<5;++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

struct Something
{
    int v1;
    float v2;
};

struct Other
{
    Something st;
}

int main()
{
    int value=5;

    int *ptr=nullptr;
    ptr=&value;

    int &ref=value; // 반드시 초기화, 리터럴은 못 들어감(메모리에 공시적인 주소 갖지 못함)

    const int y=8;
    //const int &ref=y;

    int value1=5;
    int value2=10;

    int &ref1=value1;
    cout<<ref1<<endl;
    ref1=value2;
    cout<<ref1<<endl;

    int n=5;
    cout<<n<<endl; // 5
    doSomething(n); // 10
    cout<<n<<endl;  // 5
    doSomething2(n); // 주소조차 복사할 필요가 없음
    cout<<n<<endl;

    cout<<ref<<endl;

    ref=10; // *ptr = 10;

    cout<<value<<" "<<ref<<endl;

    cout<<&value<<endl;
    cout<<&ref<<endl;
    cout<<ptr<<endl;
    cout<<&ptr<<endl;


    const int length=5;
    int arr[length]={1,2,3,4,5};

    printElements(arr);


    Other ot;
    //ot.st.v1=1;
    int &v1=ot.st.v1;
    v1=1;

    int x=5;
    int *const ptr2=&value;
    int &ref2=x;
    *ptr2=10;
    ref=10; // reference도 내부적으로는 pointer로 구성되어 있음

    return 0;
}
#include <iostream>
using namespace std;

// 메모리 할당 3가지
// 1.static memory allocation:전역 변수가 스태틱 변수와 같이 한번 만들면 프로그램이 끝날 때 까지 메로리를 갖고 있음
// 2.auto memory allocation:변수 선언, 정적 배열 선언했을 때 블럭 밖으로 나가면 사라지고 다시 메모리가 할당됨
// 3.dynamic memory allocation:포인터와 관련지어 까다로운 부분

int main()
{ 
    //int arr[10]; // 정적 배열, 스택에 들어가는데 스택은 용량이 적음
        //  동적 할당하면 힙에 들어가며, 힙은 용량이 커서 크게 받을 수 있음
    
    int *ptr = new (std::nothrow)int;//{ 7 };
    // 4바이트만큼 운영체제에게 받아오고 그 메모리 주소를 우리에게 알려주기 때문에 포인터로 받아야 함
    *ptr=7;
    
    int *ptr2=ptr;

    cout<<ptr<<endl;
    cout<<*ptr<<endl;

    delete ptr; // 메모리를 운영체제에게 돌려줌
    ptr=nullptr;

    if(ptr!=nullptr) // if(ptr)
    {
        cout<<ptr<<endl;
        cout<<*ptr<<endl;
    };

    // memory leak
    while(1)
    {
        int*ptr3=new int;
        cout<<ptr3<<endl;
        
        delete ptr3;
        // new, delete은 운영체제에 메모리를 달라고 해야하기 때문에 적게 사용하는 방식 선호
    }

    return 0;
}
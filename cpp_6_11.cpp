#include <iostream>
using namespace std;

// 메모리 할당 3가지
// 1.static memory allocation:전역 변수가 스태틱 변수와 같이 한번 만들면 프로그램이 끝날 때 까지 메로리를 갖고 있음
// 2.auto memory allocation:변수 선언, 정적 배열 선언했을 때 블럭 밖으로 나가면 사라지고 다시 메모리가 할당됨
// 3.dynamic memory allocation:포인터와 관련지어 까다로운 부분

int main()
{
    int arr[10]; // 정적 배열, 스택에 들어가는데 스택은 용량이 적음
        //  동적 할당하면 힙에 들어가며, 힙은 용량이 큼


    return 0;
}
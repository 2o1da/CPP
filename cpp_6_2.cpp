#include <iostream>
using namespace std;

// 배열과 포인터는 뗄래야 뗄 수 없는 사이

void doSomething(int students_scores[])       // 엄밀히 따지면 배열이 아님
{                                             // 문법 상 포인터라고 봄
    cout << (int)&students_scores << endl;    // 주소값을 저장하는 다른 변수의 주소 출력
    cout << (int)&students_scores[0] << endl; // 포인터 변수에 저장되어 있는 값의 주소
    cout << students_scores[0] << endl;
    cout << students_scores[1] << endl;
    cout << students_scores[2] << endl;
    cout << "Size in doSomthing " << sizeof(students_scores) << endl; // x64에서는 포인터 변수가 8바이트, 32비트에서는 4바이트
}

int main()
{
    const int num_students = 20;
    int students_scores[num_students] = {
        1,
        2,
        3,
        4,
        5,
    };

    cout << (int)students_scores << endl;  // 이름 자체가 주소로 쓰임
    cout << (int)&students_scores << endl; // 주소를 복사하는 것이 원소를 모두 복사하는 것보다 빠르기 때문
    cout << students_scores[0] << endl;
    cout << students_scores[1] << endl;
    cout << students_scores[2] << endl;
    cout << "Size in main " << sizeof(students_scores) << endl;

    doSomething(students_scores); // 배열의 모든 원소를 복사하는 것이 아니라 배열의 첫번째 주소 값만 복사
}
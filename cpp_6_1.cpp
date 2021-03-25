#include <iostream>
using namespace std;

#define NUM_STUDENTS 1000 // 정적 할당

struct Rectangle
{
    int length;
    int width;
};

enum StudentName
{
    Dasol, // 0
    Minjeong, // 1
    Love // 2
};

int main()
{
    int one_student_score; // 4btye
    int student_score[5]; // 20btye

    cout<<sizeof(one_student_score)<<endl;
    cout<<sizeof(student_score)<<endl;

    one_student_score=100;
    student_score[0]=100;

    cout<<sizeof(Rectangle)<<endl;

    Rectangle rect_arr[10];

    cout<<sizeof(rect_arr)<<endl;

    rect_arr[0].length=1;
    rect_arr[0].width=2;

    int my_array[] = {11,22}; // 1 2 0 0 0

    cout<<my_array[Dasol]<<endl;
    cout<<my_array[Minjeong]<<endl;
    cout<<my_array[Love]<<endl;

    // int num_students=0;
    // cin>>num_students;
    int students_scores[NUM_STUDENTS];

    int num=0;
    const int num2=5;
    int students_scores2[num];

    return 0;
}
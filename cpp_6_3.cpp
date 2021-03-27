#include <iostream>
using namespace std;

int main()
{
    //const int num_students = 5;
    //int scores[num_students] = { 84, 92, 76, 81, 56 };
    
    int scores[] = { 84, 92, 76, 81, 56 };

    const int num_students = sizeof(scores) / sizeof(int); // 함수 parameter 로 배열이 넘어간 것처럼 보이지만 실제로는 '포인터 주소'가 넘어감
    cout << sizeof(scores) << endl; // 20
    cout << sizeof(*scores) << endl; // 4, x64에서 8바이트가 됨 

    int total_score = 0;
    int max_score = 0;
    int min_score = 100;

    for (int i = 0; i < num_students; i++)
    {
        total_score += scores[i];
        max_score = (max_score < scores[i]) ? scores[i] : max_score;
        min_score = (min_score > scores[i]) ? scores[i] : min_score;
        
		//if (max_score < scores[i])
		//	max_score = scores[i];
    }
    cout << max_score << endl;
    cout << min_score << endl;

    double avg_score = static_cast<double>(total_score) / num_students; // 나누기 전에 casting 한 것과 나누기 한 후에 casting 한 것은 다름
    double avg_score2 = (total_score) / num_students; // 나누기 전에 casting 한 것과 나누기 한 후에 casting 한 것은 다름

    cout << avg_score << endl;
    cout << avg_score2 << endl;
}
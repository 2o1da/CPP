#include <iostream>
using namespace std;

int main()
{
    //const int num_students = 5;
    //int scores[num_students] = { 84, 92, 76, 81, 56 };
    
    int scores[] = { 84, 92, 76, 81, 56 };

    const int num_students = sizeof(scores) / sizeof(int); // �Լ� parameter �� �迭�� �Ѿ ��ó�� �������� �����δ� '������ �ּ�'�� �Ѿ
    cout << sizeof(scores) << endl; // 20
    cout << sizeof(*scores) << endl; // 4, x64���� 8����Ʈ�� �� 

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

    double avg_score = static_cast<double>(total_score) / num_students; // ������ ���� casting �� �Ͱ� ������ �� �Ŀ� casting �� ���� �ٸ�
    double avg_score2 = (total_score) / num_students; // ������ ���� casting �� �Ͱ� ������ �� �Ŀ� casting �� ���� �ٸ�

    cout << avg_score << endl;
    cout << avg_score2 << endl;
}
#include <iostream>
using namespace std;

void printArr(const int array[], const int length)
{
    for (int i = 0; i < length; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    // 선택정렬
    const int length = 5;
    int arr[length] = { 3, 5, 2, 1, 4 };

    printArr(arr, length);
    cout << endl;

    int flag = -1;
    for (int i = 0; i < length - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < length; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
                //swap(arr[i], arr[j]);
            }
        }
        swap(arr[min], arr[i]);

        printArr(arr, length);
    }

    //    printArr(arr, length);

    return 0;
}

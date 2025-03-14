#include <iostream>

using namespace std;

#define SIZE 5

int main()
{
#pragma region 선택 정렬
    /*
        주어진 리스트 중에 최소값을 찾은 다음 특정한 위치에서
        결과를 교체하는 방식으로 정렬하는 알고리즘
    */
#pragma endregion
    int arr[SIZE] = { 16, 2, 8, 11, 10 };

    for (int i = 0; i < SIZE-1; i++)
    {
        int min = arr[i];

        for (int j = i+1; j < SIZE; j++)
        {
            if (min >= arr[j]) 
            {
                std::swap(min, arr[j]);
            }
        }
        std::swap(arr[i], min);
    }

    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;

    int list[SIZE] = { 11,2,13,4,15 };
    for (int i = 0; i < SIZE-1; i++)
    {
        int min2 = list[i];
        int index = i;
        for (int j = 0; j < SIZE; j++)
        {
            if (min2 > list[j]) {
                min2 = list[j];
                index = j;
            }
        }
        std::swap(list[i], list[index]);
    }

    for (int i = 0; i < SIZE; i++)
    {
        cout << list[i] << " ";
    }

    return 0;
}
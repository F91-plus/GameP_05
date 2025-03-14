#include <iostream>

using namespace std;

#define SIZE 5

int main()
{
#pragma region 거품 정렬
    // 서로 인접한 두 원소를 비교하여 정렬하는 알고리즘


#pragma endregion
    int arr[5] = { 57,46,35,24,13 };
    int temp;
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        int index = 0;
        for (int j = 0; j < sizeof(arr) / sizeof(arr[0]); j++)
        {
            if (arr[index] > arr[index + 1]) 
            {
                temp = arr[index];
                arr[index] = arr[index + 1];
                arr[index + 1] = temp;
            }
            index++;
        }
        //cout << arr[i] << endl;
    }

    int list[SIZE] = { 13,8,97,1,36 };

    for (int i = 0; i < SIZE-1; i++)
    {
        for (int j = 0; j < (SIZE - i) - 1; j++) 
        {
            if (list[j] > list[j + 1])
                std::swap(list[j], list[j + 1]);
        }
    }



    return 0;
}
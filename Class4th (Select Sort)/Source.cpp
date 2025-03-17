#include <iostream>

using namespace std;

#define SIZE 5

int main()
{
#pragma region 삽입 정렬(Insort?)
    /*
        데이터를 하나씩 확인하면서 이미 정렬된 부분과 비교하여
        자신의 위치를 찾아 삽입하는 방식으로 정렬하는 알고리즘
        key?
    */
#pragma endregion
    int arr[SIZE] = { 6,9,8,1,3 };

    //for (int i = 0; i < SIZE-1; i++)
    //{
    //    int key = arr[i+1];
    //    for (int j = i; j >= 0; j--)
    //    {
    //        if (key <= arr[j])
    //        {
    //           swap(arr[i + 1], arr[j]);
    //           //swap은 사용 안하는 것으로 해야했음..
    //        }
    //    }
    //}
    
    /*for (const int& element : arr)
    {
        cout << element << " ";
    }*/


    int list[SIZE] = { 6,9,8,1,3 };
    int key2 = 0;
    int j = 0;

    for (int i = 0; i < SIZE; i++)
    {
        key2 = list[i];

        for (j = i-1; j >= 0 && list[j] > key2 ; j--)
        {
            list[j + 1] = list[j];
        }
        list[j + 1] = key2;
    }

    for(const int & element:list)
    {
        cout << element << " ";
    }

    return 0;
}

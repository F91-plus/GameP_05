#include <iostream>

using namespace std;

#define SIZE 8

void binary_Search2(int list[], int key) {
    int left = 0;
    int right = SIZE - 1;

    while (left <= right) {
        int pivot = (left + right) / 2;

        if (list[pivot] == key)
        {
            cout << "Key Found : " << list[pivot] << endl;

            return;
        }
        else if (list[pivot] > key) {
            right = pivot - 1;
        }
        else {
            left = pivot + 1;
        }
    }

    cout << "Not Key Found" << endl;
}

void binary_Search(int list[], int key) {
    // vector, array or 배열 사이즈를 매개변수로 전달해야함
    int left = 0;
    int right = sizeof(list) - 1;//포인터로 길이 8 고정
    int middle = (left + right) / 2;

    int* temp = new int[middle];

    if (list[middle] < key)
    {
        for (int i = 0; i <= middle; i++)
        {
            temp[i] = list[i+ middle +1];
        }
        binary_Search(temp, key);
    }
    else if (list[middle] == key) {
        cout << "key 값 [" << key << "] list : " << middle << "번째에 있습니다." << endl;
    }
    else if(left > right) {
        cout << "찾는 값이 없습니다.";
    }
    else
    {
        cout << "버그";
    }
}

int main()
{
#pragma region 이진 탐색(Two Pointer)
    /*
        탐색 범위를 반으로 나누어 찾는 값을 포함하는 범위를
        좁혀나가는 방식으로 동작하는 알고리즘 입니다.

        배열 left 와 right 엇갈린 상태인 경우에는 함수 종료
        left > right
    */

#pragma endregion
    int list[8] = { 5,6,11,13,27,55,66,99 };
    //vector<int> list = { 5,6,11,13,27,55,66,99 };
    int key = 55;

    //binary_Search(list, key);

    int list2[SIZE] = { 5,6,11,13,27,55,66,99 };

    binary_Search2(list2, key);


    return 0;
}
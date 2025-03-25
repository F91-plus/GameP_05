#include <iostream>

using namespace std;

#define SIZE 6

void QuickSort(int list[], int start, int end) {
    int pivot = start;    //list[start] -> start
    int left = start + 1;
    int right = end;

    for (int i = left; i <= end; i++)
    {
        if (list[pivot] < list[i])
        {
            swap(list[i], list[right]);
        }
    }

    for (int i = right; i >= start; i--)
    {
        if (list[pivot] > list[i]) {
            swap(list[i], list[start]);
        }
    }
}

void QuickSort2(int list[], int start, int end) {
    int pivot = start;    //list[start] -> start
    int left = start + 1;
    int right = end;

    if (start >= end)   // == -> >= 로 변경
    {
        return;
    }

    // left가 right보다 크거나 같을 떄까지 반복한다.
    while (left <= right)
    {
        //  left가 end보다 작거나 같고 list[left]가
        //  list[pivot]보다 작거나 같을 떄까지 반복한다.
        while (left <= end && list[pivot] >= list[left])
        {
            left++;     //left값 증가
        }

        //right가 start보다 크고 list[right]가
        //list[pivot]보다 크거나 같을 때까지 반복한다.
        while (right > start && list[pivot] <= list[right]) {
            right--;    //right의 값 감소
        }

        if (left > right)
        {
            std::swap(list[pivot], list[right]);
        }
        else
        {
            std::swap(list[left], list[right]);
        }
    }

    //QuickSort2(list, start, left);
    //QuickSort2(list, left, right);

    QuickSort2(list, start, right - 1);
    QuickSort2(list, right + 1, end);

}

int main()
{
#pragma region 퀵 정렬
    /*
        기준점을 획득한 다음 기준점을 기준으로 배열을 나누고
        한 쪽에는 기준점보다 작은 값들이 위치하게 하고 다른
        한 쪽에는 기준점 보다 큰 값들이 위치하도록 정렬한다.

        나누어진 하위 배열에 대해 재귀적으로 퀵 정렬을 호출하여
        모든 배열이 기본 배열이 될 떄까지 반복하면서 정렬하는
        알고리즘

        left 또는 right가 index를 넘어선 경우
        회차
        1.  546213  pivot = 5
            143256
        2.  143256  pivot = 1?

    */
#pragma endregion

    int list[SIZE] = { 5,4,6,2,1,3 };

    //QuickSort(list, 0, sizeof(list) / sizeof(int) - 1);

    QuickSort2(list, 0, SIZE - 1);

    for (int i = 0; i < SIZE; i++)
    {
        cout << list[i] << " ";
    }

    return 0;
}
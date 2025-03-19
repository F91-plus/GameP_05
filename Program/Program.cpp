#include <iostream>

using namespace std;

int Find(int list[], int left, int right)
{
    cout << " left : " << left << " right : " << right << endl;

    //배열 처음과 끝이 같다면 재귀 호출 해제?
    if (left != right)
    {
        int leftMax = Find(list, left, (left + right) / 2);
        int rightMax = Find(list, (left + right) / 2 + 1, right);

        int result = 0;
        //max, min
        if (leftMax > rightMax)
        {
            result = leftMax;
            return result;
        }
        else
        {
            result = rightMax;
            return result;
        }
    }
    else
    {
        return list[left];
    }
}


int main()
{
#pragma region 분할 정복
    /*
        주어진 2개 이상의 부분으로 문제를 나눈 뒤 각 부분
        문제에 대한 답을 재귀 호출을 이용하여 계산한 다음
        그 답으로부터 전체 문제의 답을 계산해내는 알고리즘

        분할 (Divide) : 주어진 문제를 두 개 혹은 그 이상의 형식으로 나눈다.

        정복 (Conquer) : 나누어진 문제를 재귀적으로 해결해서 나누어진 문제를
        더 이상 나누어서 문제가 필요없을 때까지 계속 분할한다.

        통합 (Combine) : 나누어서 해결한 문제들을 통합해서 원래 문제의 해답을
        생성한다.
    */
#pragma endregion
    
    int list[4] = { 1,2,3,4 };
    int list_length = sizeof(list) / sizeof(list[0]);   //4
    //int left = list_length / 2;
    //int right = list_length / 2;
    // 0~3 -> 0~1 / 2~3

    //Find(list, 0, list_length-1);

    cout << Find(list, 0, list_length - 1) << endl;

    int list2[] = { 20, 15, 99, 1 };
    int size = sizeof(list2) / sizeof(int);

    cout << Find(list2, 0, size-1) << endl;

    return 0;
}


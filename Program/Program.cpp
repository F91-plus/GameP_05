#include <iostream>

using namespace std;

int main()
{
#pragma region 계수 정렬
    /*
        데이터의 값을 비교하지 않고 각 원소에 데이터가
        몇 개 있는지 개수를 세어 저장한 다음 정렬하는 알고리즘
    */
#pragma endregion

    // 1. 해당 배열에 들어가있는 값을 확인해야함
    // 2. 값이 몇개 인지 확인
    // 3. 값이 낮은 순서 및 개수대로 출력해야함
    int count = 0;
    int check = 0;
    int list[10] = {1,1,3,1,2,3,4,4,2,5}; // 하나가 99라면?
    int* temp = new int[10];

    for (int i = 0; i < 10; i++)
    {
        check = list[i];
        for (int j = 0; j < 10; j++)
        {
            if (check == list[j])
            {
                count++;
            }
        }
        for (int k = 0; k < count; k++)
        {
            temp[i] = i;
        }
    }

    return 0;
}

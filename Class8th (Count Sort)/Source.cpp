#include <iostream>

using namespace std;

#define SIZE 10

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
    // 3. 값이 낮은 순서 및 개수대로 정렬해서 출력해야함
    //int count = 0;
    //int pre_count = 0;
    //int check = 0;
    //int check_number = 0;
    //int list[10] = {1,1,3,1,2,3,4,4,2,5};
    //int* index = new int[10];

    //for (int i = 0; i < 10; i++)
    //{
    //    check = list[i]; // 0:1
    //    if (list[i] == 0)
    //    {
    //        continue;
    //    }

    //    for (int j = 0; j < 10; j++)
    //    {
    //        if (check == list[j]) // 1 == 0~9의 값이?
    //        {
    //            count++;        // item이 몇개인지 확인함
    //            list[j] = 0;    //같다면 해당 index의 값을 0으로
    //        }
    //    }
    //    //check_number++; //미사용

    //    //개수는 구함, 이 구한것을 이제 배열에 넣어야함
    //    for (int i = 0; i < count; i++)
    //    {
    //        if (pre_count==0)
    //        {
    //            index[i] = check;
    //        }
    //        else {
    //            index[i + pre_count] = check;
    //        }
    //    }
    //    pre_count += count;
    //    count = 0;
    //}
    /*for (int i = 0; i < 10; i++)
    {
        cout << index[i] << " ";
    }*/


    int list[SIZE] = { 1,1,3,1,2,3,4,4,2,5 };
    int count[5] = { 0, };

    for (int i = 0; i < SIZE; i++)
    {
        count[list[i] - 1]++;
    }

    for (int i = 0; i < 5; i++)
    {
        if (list[i] != 0) {
            for (int j = 0; j < count[i]; j++)
            {
                cout << i + 1 << " ";
            }
        }
    }


    return 0;
}


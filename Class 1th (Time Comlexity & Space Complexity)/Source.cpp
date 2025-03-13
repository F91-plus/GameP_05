#include <iostream>

using namespace std;

int main()
{
#pragma region 완전 탐색
    /*
        가능한 모든 경우의 수를 탐색하면서 결과를
        찾아내는 알고리즘
    */
    int password[] = { 7,1,2 };
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++) {
                if (password[0] == i && password[1] == j && password[2] == k) {
                    cout << "Password Release" << i << " " << j << " " << k << endl;

                    break;
                }
            }
        }

    }

#pragma endregion
    int array[3] = { 0,0,0 };
    //array[0] = 0;
    //array[1] = 0;
    //array[2] = 0;
    /*while (true)
    {
        std::cout << "첫번째 비밀번호 입력" << std::endl;
        std::cin >> array[0];
        std::cout << "두번째 비밀번호 입력" << std::endl;
        std::cin >> array[1];
        std::cout << "세번째 비밀번호 입력" << std::endl;
        std::cin >> array[2];
        if (array[0] == 7 && array[1] == 1 && array[2] == 2)
        {
            std::cout << "비밀번호 확인" << std::endl;
        }
        else
        {
            std::cout << "비밀번호 틀림" << std::endl;
        }
    }*/
    return 0;
}

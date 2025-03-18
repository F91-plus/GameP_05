#include <iostream>

using namespace std;

int main()
{
#pragma region 시간 복잡도
    //컴퓨터 프로그램의 입력값과 연산 수행 시간의
    //상관 관계를 나타내는 척도

#pragma region 0(1) 상수시간
    /*
        입력 크기와 상관없이 일정한 시간 복잡도를
        가지는 시간
        ex) 배열의 요소 접근
    */
#pragma endregion

#pragma region 0(log n) 로그시간
    /*
        데이터 크기에 따라 싱행 시간이 로그 함수의 형태로
        증가하는 시간 복잡도
        ex) 이진 탐색
    */
#pragma endregion

#pragma region 0(n)선형 시간
    /*
        입력에 따라 걸리는 시간이 선형적으로 증가되는
        시간 복잡도
        ex) 순차 탐색
    */
#pragma endregion

#pragma region 0(n²) 제곱시간
    /*
        입력되는 데이터를 기준으로 n² 만큼의 시간이
        증가하는 시간 복잡도
        ex) 2 for statement
    */
#pragma endregion

#pragma endregion

#pragma region 공간 복잡도
    /*
        프로그램 실행과 완료에 얼마나 많은 공간이
        필요한 지 나타내는 척도
    */

#pragma region 고정 공간
    /*
        코드가 저장되는 공간으로 알고리즘 실행을 위해
        시스템이 필요로 하는 공간
        ex) 배열
    */
#pragma region 가변 공간
    /*
        문제를 해결하기 위해 알고리즘이 필요한 공간으로
        순환 프로그램일 경우 순환 스택을 의미
        ex) 재귀 함수
    */
#pragma endregion

#pragma endregion

#pragma endregion

#pragma region 점근적 표기법
    /*
        상수 계수와 중요하지 않은 항목을 제거하여 표기하는
        표기법
        f(n) = n²+ n + 300 => n²(점근적 표기법)
        n²을 제외한 n + 300부분은 제거하여 표시

        높은 수가 낮은 차수에 붙어 있어도 n이 무한대로 갈 수
        있기 때문에 제일 높은 차수가 된다.
    */
#pragma endregion

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

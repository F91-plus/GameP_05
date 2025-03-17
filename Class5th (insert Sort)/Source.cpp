#include <iostream>

using namespace std;

int euclid(int x, int y) {
    /*
        1. 두 개의 자연수 x, y가 있다.
        그리고 x와 y로 나눈 나머지를 R

        2. R이 0이라면, x와 y의 최대공약수 y가 된다.

        3. R이 0이 아니라면, x와 y의 최대 공약수는 y와 R의
        최대 공약수와 같기 때문에 x에는 y 그리고 y에는 R을
        대 입한 후 1번으로 돌아간다.
    */
    //int R = 0;

    //while (true) {
    //    R = x % y;  //나머지 10 >> 4
    //    y = x / y;  //y = 6 

    //    if (R != 0) // 10
    //    {
    //        x = R; // x = 10
    //    }
    //    else if (R==0)
    //    {
    //        break;
    //    }
    //    cout << R << endl;
    //}
    // return 0;

    if (y == 0) {
        return x;
    }
    else
    {
        return euclid(y, x % y);
    }
}

int main()
{
#pragma region 유클리드 호제법
    /*
        2개의 자연수 또는 정식의 최대 공약수를 구하는 방식으로
        두 수가 서로 상대방 수를 나누어서 원하는 수를 얻어내는 알고리즘
        시간 복잡도 : n
    */
#pragma endregion
    //int a = 12;
    //int b = 18;
    //int max = 1;
    //int count = 0;

    //for (int i = 2; ; i++)
    //{
    //    if (a % i == 0 && b % i == 0)
    //    {
    //        max *= i;
    //        a = a / i;
    //        b = b / i;
    //        
    //        i = 2;
    //        count++;

    //    }
    //    else if (a < i || b < i) {
    //        break;
    //    }

    //}

    //int a1 = 24;
    //int b1 = 48;
    //int result = 0;

    //for (int i = 1; i <= a1 && i <= b1; i++)
    //{
    //    if (a1 % i == 0 && b1 % i == 0) 
    //    {
    //        result = i;
    //    }
    //}
    //   
    //cout << "최대공약수 : " << result << endl;

    int a = 106;
    int b = 16;

    cout << euclid(a, b) << endl;

    return 0;
}




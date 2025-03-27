#include <iostream>

using namespace std;

void money_check(int won)
{
	int won1000 = 1000;
	int won500 = 500;
	int won100 = 100;
	int won50 = 50;
	int won10 = 10;

	int won1000_count = 0;
	int won500_count = 0;
	int won100_count = 0;
	int won50_count = 0;
	int won10_count = 0;

	while (true) {
		if (won > 1000)
		{
			won = won - won1000;
			won1000_count++;
		}
		else if (won >= 500 && won < 1000) {
			won = won - won500;
			won500_count++;
		}
		else if (won >= 100 && won < 500)
		{
			won = won - won100;
			won100_count++;
		}
		else if (won >= 50 && won < 100) {
			won = won - won50;
			won50_count++;
		}
		else if (won >= 10 && won < 50)
		{
			won = won - won10;
			won10_count++;
		}
		else if (won <= 9)
		{
			break;
		}
	}
	cout << "1000원 : " << won1000_count << endl;
	cout << "500원 : " << won500_count << endl;
	cout << "100원 : " << won100_count << endl;
	cout << "50원 : " << won50_count << endl;
	cout << "10원 : " << won10_count << endl;
}

const int& Greedy(int n) {
	int count = 0;

	while (n >= 10) {
		if (n >= 1000)
		{
			n -= 1000;
			count++;
		}
		else if (n >= 500)
		{
			n -= 500;
			count++;
		}
		else if (n >= 100)
		{
			n -= 100;
			count++;
		}
		else if (n >= 50) {
			n -= 50;
			count++;
		}
		else if (n >= 10) {
			n -= 10;
			count++;
		}
	}

	return count;
}

int main()
{
#pragma region 탐욕법
	/*
		최적의 해를 구하는 데에 사용되는 근사적인 방법으로 여러 경우 중
		하나를 검색해야 할 떄마다 그 순간에 최적이라고 생각되는 것을
		선택해 나가는 방식으로 진행하여 최종적인 해답을 구하는 알고리즘

		1. 탐욕 선택 속성
		각 단계에서 '최적의 선택'을 했을 때 전체 문제에 대한
		최적의 해를 구할 수 있는 경우

		2. 최적 부분 구조
		전체 문제의 최적의 해가 '부분 문제의 최적의 해로 구성
		될 수 있는 경우

		그리디 알고리즘 단계 (요약본?)
		1. 선택 절차(Selection Procedure)
			- 현재 상태에서의 최적의 해답을 선택한다.
		2. 적절성 검사 (Feasibility)
			- 선택된 해가 문제의 조건을 만족하는지 검사.
		3. 해답 검사 (Solution Check)
			- 원래의 문제가 해결되었는지 검사하고, 해결되지 않았다면
			  선택 절차로 돌아가 위의 과정을 반복한다.

		그리디 알고리즘 단계 (상세내용)
		1. 문제의 최적 부분 구조를 결정
		2. 문제의 구조에 맞게 선택 절차를 정의함
		3. 선택 절차에 따라 선택을 수행함
		4. 선택된 해가 문제의 조건을 만족하는 지 검사
		5. 조건을 만족하지 않으면 해당 해를 제외한다.
		6. 모든 선택이 완료되면 해답을 검사한다.
		7. 조건을 만족하지 않으면 해답으로 인정되지 않는다.

	*/
#pragma endregion
	int money = 1370;

	money_check(money);

	cout << endl;

	cout << Greedy(money);

	return 0;
}
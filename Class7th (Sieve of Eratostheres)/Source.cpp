#include <iostream>

using namespace std;

// 시간 복잡도 : n or n/2
bool isPrime(int n) {
	int count = 0;

	if (n <= 1)	// 0에서 1로 수정
	{
		return false;
	}

	for (int i = 2; i <= n; i++) // 위 조건이 1로 했으니 2부터 시작
	{
		if (n % i == 0) {
			count++;
		}
	}
	if (count <= 2)
	{
		return true;
	}
	else
	{
		return false;
	}


	//for문안에 조건은 좀 더 간단하게 가능함
	/*
	*for~
		if (n % i == 0) {
		return false;

	return true;
	}*/
}

void sieve(int n) {
	// 동적 배열, 1차원, 1부터	
	//int check = 0;
	//int* arr = new int[check];
	//int* temp = new int[n];//....

	//for (int i = 1; i < n; i++)
	//{
	//	if (n % i == 0)
	//	{
	//		arr[check] = i;
	//		check++;
	//		//???
	//	}
	//}

	//for (int i = 0; i < check; i++)
	//{
	//	cout << arr[i] << " ";
	//}

	int* container = new int[n + 1];

	for (int i = 0; i <= n; i++)
	{
		container[i] = i;
	}

	for (int i = 2; i <= sqrt(n); i++)//n=10이면 2, 3	49면 7 234567
	{//2부터 루트n 값 까지 ㅇㅋ?
		if (container[i] == 0)
		{
			//4,6,8,10,9 걸러짐
			continue;
		}

		for (int j = i * 2; j <= n; j += i) {
			// 소수인 숫자들
			// i가 2일때 4,6,8,10인 배열 란에 0이 들어감
			// i가 3일때 6,9인 배열 란에 0이 들어감
			// j 반복 끝나고 위에서 다시 실행 될 때
			// i가 해당 배열 란의 값을 확인할 때 0 이면 바로 다음
			// 값으로 넘어감
			container[j] = 0;
		}

	}

	for (int i = 2; i <= n; i++)
	{
		if (container[i] != 0) {
			cout << container[i] << " ";
		}
	}

	delete[] container;
}

int main()
{
#pragma region MyRegion

#pragma endregion

	int num = 22;

	isPrime(num);

	//sieve(10);

	sieve(49);
}


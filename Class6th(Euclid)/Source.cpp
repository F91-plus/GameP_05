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

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (container[i] == 0) 
		{
			continue;
		}

		for (int j = i * 2; j <= n; j += i) {
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

	if (isPrime(num))
	{
		cout << "소수입니다." << endl;
	}
	else {
		cout << "소수가 아님" << endl;
	}

	sieve(10);

	sieve(49);
}


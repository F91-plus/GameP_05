#include <iostream>

using namespace std;

#define SIZE 6

int parent[SIZE];

int find(int x) {
	if (x == 0)
	{
		return parent[x];
	}
	else if (parent[x] != parent[x - 1])
	{
		return find(x - 1);
	}

	while (!(x == parent[x - 1]))
	{
		return find(x - 1);
	}
}

void Union(int x, int y) {
	int a = find(x);
	int b = find(y);

	cout << "a : " << a << endl;
	cout << "b : " << b << endl;
	cout << endl;
}

int find2(int x)
{
	//배열의 인덱스와 값이 같다면 Root Node 발견
	if (x == parent[x]) {
		return x;
	}
	else {
		// 부모 노드의 번호를 전달하면서, Root Node를 찾을 떄까지
		// 재귀 호출을 반복한다.
		return parent[x] = find2(parent[x]);
	}
}

void Union2(int x, int y)
{
	x = find2(x);
	y = find2(y);

	if (x == y) return;

	if (x < y)
	{
		parent[y] = x;
	}
	else {
		parent[x] = y;
	}
}

bool same(int x, int y) {
	return find2(x) == find2(y);
}

int main()
{
#pragma region 유니온 파인드
	/*
		여러 노드가 존재할 떄 어떤 노드가 다른 노드와 연결되어
		있는지 확인하는 알고리즘

		Union : 특정한 두 개의 노드를 같은 집합으로 합치는 연산

		find : 특정한 노드가 어느 집합에 있는지 확인하는 연산

		1. 배열의 1번에 있는 값을 확인
		2. 배열의 0번에 있는 값을 확인
		3. 배열의 인덱스와 값이 일치
		4. 0번과 1번노드가 속해있는 트리의 루트 노드이다

		Root Node를 찾는 함수
	*/
#pragma endregion

	for (int i = 0; i < SIZE; i++)
	{
		parent[i] = i;
	}

	Union2(0, 1);
	Union2(3, 4);
	Union2(4, 5);

	cout << same(0, 1) << endl;
	cout << same(3, 5) << endl;
	cout << same(3, 0) << endl;

	return 0;
}
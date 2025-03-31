#include <iostream>
#include <vector>

using namespace std;

#define SIZE 8

class Node {
private:
	bool visited[SIZE];
	vector<int> adjacencyList[SIZE];
public:
	Node()
	{
		for (int i = 0; i < SIZE; i++)
		{
			visited[i] = false;
		}
	}

	void insert(int i, int j)
	{
		adjacencyList[i].push_back(j);
		adjacencyList[j].push_back(i);
	}

	void search(int start)
	{
		// 현재 노드를 방문한 것으로 표시한다.
		visited[start] = true;

		// 현재 노드를 출력합니다.
		cout << start << " ";

		// 현재 노드와 연결된 다른 노드를 재귀적으로 방문
		for (int i = 0; i < adjacencyList[start].size(); i++)
		{
			//현재 노드와 연결된 다음 노드를 가져옵니다.
			int next = adjacencyList[start][i];

			if (visited[next] == false)
			{
				// 다음 노드가 방문하지 않은 노드라면 'Search' 함수를 호출
				search(next);
			}
		}
	}
};

class Node2
{
private:
	bool visited2[SIZE];
	vector<int> List[SIZE];
public:
	Node2()
	{
		for (int i = 0; i < SIZE; i++)
		{
			visited2[i] = false;
		}
	}

	int insert2(int i, int j)
	{
		List[i].push_back(j);
		List[j].push_back(i);
	}

	void search2(int start)
	{
		visited2[start] = true;

		cout << start << " ";

		for (int i = 0; i < List[start].size(); i++)
		{
			int next2 = List[start][i];

			if (visited2[next2] == false)
			{
				search2(next2);
			}
		}
	}

};


int main()
{
#pragma region 깊이 우선 탐색 (Depth First Search)
	/*
		root 노드에서부터 다음 분기로 넘어가기 전에
		해당 분기를 완벽하게 탐색하는 방법

		깊이 우선 탐색은 Stack이라는 자료 구조를 활용함

		1. 시작 노드를 스택에 넣고 방문 처리를 한다.
		2. 스택의 최상단 노드에 방문하지 않은 인접 노드가 있으면
		   그 노드를 스택에 넣고 방문처리한다.

		3. 방문하지 않은 인접 노드가 없으면 스택에서 최상단에 있는 노드를
		   꺼낸다.

		4. 더 이상 2번의 과정을 수행할 수 이없을 때까지 반복한다.
	*/

#pragma endregion

	Node node;

	node.insert(1, 2);
	node.insert(1, 3);

	node.insert(2, 3);
	node.insert(2, 4);
	node.insert(2, 5);

	node.insert(3, 6);
	node.insert(3, 7);

	node.insert(4, 5);
	node.insert(6, 7);

	node.search(1);

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

#define SIZE 8

//template <typename T = int>
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
			adjacencyList[i];
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



int main()
{
#pragma region MyRegion

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
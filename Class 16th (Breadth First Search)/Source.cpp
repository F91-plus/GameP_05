#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define SIZE 8

class Node {
private:
	queue<int> queue;	//+

	bool visited[SIZE];
	vector<int> breadthList[SIZE];
public:
	Node()
	{
		for (int i = 0; i < SIZE; i++)
		{
			visited[i] = false;
			//breadthList[i].clear;
		}
	}

	void insert(int i, int j)
	{
		breadthList[i].push_back(j);
		breadthList[j].push_back(i);
		/*if (i>=0 && i<SIZE && j>=0 && j<SIZE)
		{

		}*/
	}

	void search(int start)
	{
		queue.push(start);
		visited[start] = true;

		while (queue.empty() == false)
		{
			int temp = queue.front();

			queue.pop();

			cout << temp << " ";

			for (int i = 0; i < breadthList[temp].size(); i++)
			{
				int next = breadthList[temp][i];

				if (visited[next] == false)
				{
					queue.push(next);
					visited[next] = true;
				}
			}
		}
		//for (int i = 0; i < SIZE; i++)
		//{
		//	int temp = 0;
		//	int next = breadthList[start][i];
		//	//breadthList[start].pop_back();

		//	queue.push(start);
		//	visited[start] = true;
		//	temp = queue.pop();

		//	if (visited[temp] == true)
		//	{
		//		//queue.push(breadthList[temp][i]);
		//		//queue.push(next);
		//		visited[temp] = true;
		//		cout << temp << " ";
		//	}
		//}
	}
};

int main()
{
#pragma region 너비 우선 탐색(Breadth First Search)
	/*
		시작 정점을 방문한 후 시작 정점에 인접한
		모든 정점들을 우선 방문하는 방법

		더 이상 방문하지 않은 정점이 없을 때까지 방문하지 않은
		모든 정점들에 대해서도 너비 우선 탐색을 적용합니다.
	*/
#pragma endregion

	Node node;
	node.insert(1, 2);
	node.insert(1, 3);

	node.insert(2, 4);
	node.insert(2, 5);

	node.insert(3, 6);
	node.insert(3, 7);

	node.search(1);

	return 0;
}

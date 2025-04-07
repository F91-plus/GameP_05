#include <iostream>
#include <vector>

#define SIZE 6
#define INFINITY 10000000

using namespace std;

class Dijkstra
{
private:
	int dijkstra_arr[SIZE][SIZE] =
	{
		{0,2,5,1,INFINITY, INFINITY},
		{2,0,3,2,INFINITY, INFINITY},
		{5,3,0,3,1,5},
		{1,2,3,0,1,INFINITY},
		{INFINITY, INFINITY, 1, 1, 0, 2},
		{INFINITY,INFINITY,5,INFINITY,2,0}
	};

	bool visited[SIZE];
	int distance[SIZE];

public:
	Dijkstra() {
		for (int i = 0; i < SIZE; i++)
		{
			visited[i] = false;
			distance[i] = 0;
		}
	}

	void calculate(int start) {//start 1~6
		if (start == 0) return;

		// 시작점 방문자로
		visited[start - 1] = true;

		for (int i = 0; i < SIZE; i++)
		{
			distance[i] = dijkstra_arr[start - 1][i];
		}
		for (int i = 0; i < SIZE; i++)
		{
			dijkstra_arr[i][i] = INFINITY;
		}

		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				if (visited[i] == false && distance[i] > dijkstra_arr[j][i] || distance[i] > Find())
				{
					if (visited[i] == false && dijkstra_arr[j][i] > distance[i] > Find())
					{
						distance[i] = Find();
						visited[i] = true;
					}
					else {
						distance[i] = dijkstra_arr[j][i];
						visited[i] = true;
					}
				}
			}
		}

		for (int i = 0; i < SIZE; i++)
		{
			cout << distance[i] << " ";
		}
	}

	// 거리 찾기
	const int& Find()
	{
		int temp = 0;
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++) {
				if (visited[i] == false)
				{
					for (int k = 0; k < i; k++) {
						temp += dijkstra_arr[k][j];
					}
				}
			}
		}

		return temp;
	};

};

class Dijkstra2
{
private:
	int dijkstra_arr[SIZE][SIZE] =
	{
		{0,2,5,1,INFINITY, INFINITY},
		{2,0,3,2,INFINITY, INFINITY},
		{5,3,0,3,1,5},
		{1,2,3,0,1,INFINITY},
		{INFINITY, INFINITY, 1, 1, 0, 2},
		{INFINITY,INFINITY,5,INFINITY,2,0}
	};

	bool visited[SIZE];
	int distance[SIZE];

public:
	Dijkstra2() {
		for (int i = 0; i < SIZE; i++)
		{
			visited[i] = false;
			distance[i] = 0;
		}
	}

	// 거리 찾기
	const int& Find()
	{
		int index = 0;
		int min = INFINITY;

		for (int i = 0; i < SIZE; i++)
		{
			// 각 배열의 거리 값을 넣고, 방문 false 상태
			if (distance[i] < min && visited[i] == false) {
				min = distance[i];

				index = i;//0~5
			}
		}

		return index;
	};

	void calculate(int start) {
		for (int i = 0; i < SIZE; i++)
		{
			distance[i] = dijkstra_arr[start][i];
		}
		visited[start] = true;

		for (int i = 0; i < SIZE - 1; i++)
		{
			int minNode = Find();

			visited[minNode] = true;

			for (int j = 0; j < SIZE; j++)
			{
				if (visited[j] == false) {
					if (distance[minNode] + dijkstra_arr[minNode][j] < distance[j])
					{
						distance[j] = distance[minNode] + dijkstra_arr[minNode][j];
					}
				}
			}
		}

		for (int i = 0; i < SIZE; i++)
		{
			cout << distance[i] << " ";
		}
	}
};


int main()
{
#pragma region 다익스트라 알고리즘
	/*
		시작점으로부터 모든 노드까지의 최소 거리를 구해주는 알고리즘

		1. 거리 배열에 weight [시작 노드]의 값들로 초기화
		2. 시작점을 방문 처리한다.
		3. 거리 배열에서 최소 비용 노드를 찾고 방문 처리한다.
			- 단, 이미 방문한 노드는 제외한다.
		4. 최소 비용 노드를 거쳐갈지 고민해서 거리 배열을 갱신한다.
			- 단, 이미 방문한 노드는 제외한다.
		5. 모든 노드를 방문할 떄까지 3~4번을 반복한다.

		방문하지 않은 노드 중에서 가장 작은 거리를 가진 노드를 방문하고,
		그 노드와 연결된 다른 노드까지의 거리를 계산한다.
	*/
#pragma endregion
	Dijkstra dijkstra;

	//dijkstra.calculate(1);

	Dijkstra2 dijkstra2;

	dijkstra2.calculate(0);

	return 0;
}
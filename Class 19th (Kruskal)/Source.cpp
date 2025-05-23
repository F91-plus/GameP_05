﻿#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define SIZE 8

class Kruskal {
private:
	class Edge {
	private:
		int vertexX;
		int vertexY;
		int weight;
	public:
		Edge(int vertexX, int vertexY, int weight) {
			this->vertexX = vertexX;
			this->vertexY = vertexY;
			this->weight = weight;
		}

		const int& VertexX() { return vertexX; }
		const int& VertexY() { return vertexY; }
		const int& Weight() { return weight; }

		const bool& operator < (const Edge& edge) {
			return weight < edge.weight;
		}
	};
	int cost;
	int parent[SIZE];
	vector<Edge> nodeList;

public:
	Kruskal() {
		cost = 0;

		for (int i = 0; i < SIZE; i++)
		{
			parent[i] = i;
		}
	}

	void insert(int vertexX, int vertexY, int weight) {
		//Edge edge(vertexX, vertexY, weight);
		nodeList.push_back(Edge(vertexX, vertexY, weight));	//..k(edge);
	}

	int find(int x)
	{
		//배열의 인덱스와 값이 같다면 Root Node 발견
		if (x == parent[x]) {
			return x;
		}
		else {
			// 부모 노드의 번호를 전달하면서, Root Node를 찾을 떄까지
			// 재귀 호출을 반복한다.
			return parent[x] = find(parent[x]);
		}
	}

	void Union(int x, int y)
	{
		x = find(x);
		y = find(y);

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
		return find(x) == find(y);
	}

	void calculate() {
		sort(nodeList.begin(), nodeList.end());

		for (int i = 0; i < nodeList.size(); i++)
		{
			if (same(nodeList[i].VertexX(), nodeList[i].VertexY()) != 1) {
				cost += nodeList[i].Weight();

				Union(nodeList[i].VertexX(), nodeList[i].VertexY());
			}
		}

		cout << "최소 Cost : " << cost << endl;

		/*while (true)
		{
			int count = 0;
			if (nodeList[0].Weight() < nodeList[1].Weight())
			{
				Union(nodeList[0].VertexX(), nodeList[0].VertexY());
				count++;
				if (same(nodeList[0].VertexX(), nodeList[0].VertexY()) != 1)
				{
					parent[0] = nodeList[0].Weight();
				}
			}
			else
			{
				count++;
				parent[0] = nodeList[1].Weight();
			}

			if (count == 6)
			{
				break;
			}
		}*/


		/*for (int i = 0; i < nodeList.size(); i++)
		{
			cout << "vertexX : " << nodeList[i].VertexX() << endl;
			cout << "vertexY : " << nodeList[i].VertexY() << endl;
			cout << "wieght : " << nodeList[i].Weight() << endl;
			cout << endl;
		}*/

	}
};

int main()
{
#pragma region 최소 신장 트리
	/*
		그래프의 모든 정점을 포함하면서 사이클이 존재하지 않는
		부분 그래프로, 그래프의 모든 정점을 최소 비용으로 연결하는 트리

		그래프의 정점의 수가 n개일 때, 간선의 수는 n-1개

		- class Kruskal > class edge, cost
		- parent[] (사이클 확인용), size 8
	*/
#pragma endregion
	Kruskal kruskal;
	kruskal.insert(1, 7, 10);
	kruskal.insert(4, 7, 14);

	kruskal.insert(1, 4, 30);
	kruskal.insert(2, 4, 25);

	kruskal.insert(1, 2, 64);
	kruskal.insert(1, 5, 19);

	kruskal.insert(5, 7, 73);
	kruskal.insert(2, 5, 61);

	kruskal.insert(5, 3, 22);
	kruskal.insert(5, 6, 48);
	kruskal.insert(3, 6, 36);

	kruskal.calculate();
	return 0;
}
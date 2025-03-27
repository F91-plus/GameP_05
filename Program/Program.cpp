#include <iostream>
#include <vector>

using namespace std;

#define SIZE 8

template <typename T>
class Node {
private:
	bool visited[SIZE];
	vector<T> adjacencyList[SIZE];
public:
	Node() 
	{
		for (int i = 0; i < SIZE; i++)
		{
			visited[i] = false;
			adjacencyList[i] = NULL;
		}
	}

	void insert(int i, int j)
	{
		adjacencyList[i].push_back(j);
		adjacencyList[j].push_back(i);
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

	return 0;
}
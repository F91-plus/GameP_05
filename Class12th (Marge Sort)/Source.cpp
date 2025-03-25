#include <iostream>

using namespace std;

#define SIZE 8

void merge_sort(int list[], int start, int end)
{
	//대충 망한 코드
	/*
	int middle = (start + end) / 2;

	while (true)
	{
		if (start == end)
		{
			break;
		}

		int* temp = new int[middle + 1];

		cout << "왼쪽 : ";
		for (int i = 0; i < middle + 1; i++)
		{
			cout << list[i] << " ";
			temp[i] = list[i];
		}

		merge_sort(temp, start, end);
	}

	while (true)
	{
		if (start == end)
		{
			break;
		}

		cout << endl << "오른쪽 : ";
		for (int i = middle + 1; i <= end; i++)
		{
			cout << list[i] << " ";
		}
		break;
	}
	*/

}

void combine(int list[], int start, int middle, int end)
{
	/*cout << list << endl;
	cout << start << endl;
	cout << middle << endl;
	cout << end << endl;
	*/
	if (start == end) {
		return;
	}

	int count = 0;
	int left = start;
	int right = middle + 1;	// end >> middle+1(확인)
	int* temp = new int[end - start + 1];	// end >> end-start+1

	//for (int i = 0; i < end-start+1; i++)	// 0 1 | 2 3
	while (left <= middle && right <= end) {
		if (list[left] <= list[right])
		{
			temp[count] = list[left];
			count++;
			left++;
		}
		else
		{
			temp[count] = list[right];
			count++;
			right++;
		}
	}

	// 남은 요소를 하나만 넣어줌
	// 왼쪽과 오른쪽 중 남은 요소가 2 이상인 경우 터짐ㅅㄱ
	if (left == middle)
	{
		temp[count] = list[left];
		count++;
		left++;
	}
	if (right == end)
	{
		temp[count] = list[right];
		count++;
		right++;
	}

	for (int i = 0; i < end - start + 1; i++)
	{
		list[i] = temp[i];
		cout << temp[i] << " ";
	}
	cout << endl;
}

void combine2(int list[], int start, int middle, int end)
{
	int count = 0;
	int left = start;
	int right = middle + 1;	// end >> middle+1(확인)
	int* temp2 = new int[end - start + 1];	// end >> end-start+1

	for (int i = 0; i < end - start + 1; i++)
	{
		temp2[i] = 0;
	}

	while (left <= middle && right <= end) {
		if (list[left] <= list[right])
		{
			temp2[count++] = list[left++];
		}
		else
		{
			temp2[count++] = list[right++];
		}
	}

	//남은 왼쪽 배열의 요소들을 복사
	while (left <= middle) {
		temp2[count++] = list[left++];
	}

	//남은 오른쪽 배열의 요소들을 복사
	while (right <= end) {
		temp2[count++] = list[right++];
	}

	//원본 배열에 정렬된 임시 배열의 값을 복사
	for (int i = 0; i < end - start + 1; i++)
	{
		list[start + i] = temp2[i];
	}

	delete[] temp2;
}

void merge_sort2(int list[], int start, int end)
{
	int middle = (start + end) / 2;
	if (start < end)
	{
		//cout << start << " " << middle << " ";
		//cout << endl;
		merge_sort2(list, start, middle);

		//cout << middle+1 << " " << end << " ";
		//cout << endl;
		merge_sort2(list, middle + 1, end);

		combine2(list, start, middle, end);
	}
}




int main()
{
#pragma region 병합 정렬
	/*
	* 하나의 리스트를 두 개의 균일한 크기로 분할하고 분할된
	* 부분 리스트를 정렬한 다음, 두 개의 정렬된 부분 리스트를
	* 합하여 전체가 정렬된 리스트가 되게 하는 방법
	*
	* 1. 리스트의 길이가 0 또는 1이면 이미 정렬된 것
	* 2. 정렬이 안된 경우
	*	  - 정렬되지 않은 리스트를 절반으로 나누어 비슷한 크기의
	*		두 부분 리스트로 나눈다.
	*	  - 각 부분 리스트를 재귀적으로 병합 정렬을 이용하여 정렬
	*	  - 두 부분 리스트를 다시 하나의 정렬된 리스트로 병합
	*/

#pragma endregion

	int list[SIZE] = { 3,5,2,7,4,1,8,6 };

	//merge_sort(list, 0, SIZE - 1);
	/*for (int i = 0; i < SIZE; i++)
	{
		cout << list[i] << " ";
	}
	*/

	merge_sort2(list, 0, SIZE - 1);

	cout << endl;

	for (const int& element : list)
	{
		cout << element << " ";
	}
}
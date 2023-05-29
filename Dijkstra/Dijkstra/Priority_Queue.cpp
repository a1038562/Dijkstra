#include "Priority_Queue.h"

void Priority_Queue::push(int key, int value) // min heap insert 함수
{
	A.push_back(make_pair(key, value)); // 값 추가
	Increase_Key(A.size() - 1); // 추가된 값에 대해 tree 재구성 (위로 이동)
}

void Priority_Queue::pop() // heap extract min 함수
{
	if (!empty())
	{
		swap(0, A.size() - 1); // 마지막 값과 root 값 위치 교환
		A.pop_back(); // 마지막 값(root였던 값) 삭제
		Min_Heapify(0); // 삭제된 값에 대해 tree 재구성 (아래로 이동)
	}
}

int Priority_Queue::size() // 크기 반환 함수
{
	return A.size();
}

pair<int, int> Priority_Queue::top() // heap minimum 함수
{
	if (!empty())
		return A[0]; // 최솟값 반환
}

bool Priority_Queue::empty() // 비어있는지 알려주는 함수
{
	return A.empty();
}

void Priority_Queue::Increase_Key(int index) // heap increase key 함수
{
	while (index > 0)
	{
		int p_index = (index - 1) / 2; // parent index

		if (A[index].second < A[p_index].second) // child가 더 작은 경우
		{
			swap(index, p_index); // parent와 child를 교환
			index = p_index; // parent로 이동
		}

		else
			break;
	}
}

void Priority_Queue::Min_Heapify(int index) // min heapify 함수
{
	int size = A.size();

	while (index < size)
	{
		int l = 2 * index + 1; // 왼쪽 child
		int r = 2 * index + 2; // 오른쪽 child
		int min = index; // 최솟값(root)

		if (l < size && A[l].second < A[min].second) // 왼쪽 child가 최솟값보다 작은 경우
			min = l;

		if (r < size && A[r].second < A[min].second) // 오른쪽 child가 최솟값보다 작은 경우
			min = r;

		if (min != index) // min가 갱신된 경우
		{
			swap(index, min); // 값 위치 교환
			index = min; // min 위치로 이동
		}

		else
			break;
	}
}

void Priority_Queue::swap(int a, int b)  // 교환 함수
{
	pair<int, int> temp = A[a];
	A[a] = A[b];
	A[b] = temp;
}
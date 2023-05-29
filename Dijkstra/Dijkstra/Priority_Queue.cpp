#include "Priority_Queue.h"

void Priority_Queue::push(int key, int value) // min heap insert �Լ�
{
	A.push_back(make_pair(key, value)); // �� �߰�
	Increase_Key(A.size() - 1); // �߰��� ���� ���� tree �籸�� (���� �̵�)
}

void Priority_Queue::pop() // heap extract min �Լ�
{
	if (!empty())
	{
		swap(0, A.size() - 1); // ������ ���� root �� ��ġ ��ȯ
		A.pop_back(); // ������ ��(root���� ��) ����
		Min_Heapify(0); // ������ ���� ���� tree �籸�� (�Ʒ��� �̵�)
	}
}

int Priority_Queue::size() // ũ�� ��ȯ �Լ�
{
	return A.size();
}

pair<int, int> Priority_Queue::top() // heap minimum �Լ�
{
	if (!empty())
		return A[0]; // �ּڰ� ��ȯ
}

bool Priority_Queue::empty() // ����ִ��� �˷��ִ� �Լ�
{
	return A.empty();
}

void Priority_Queue::Increase_Key(int index) // heap increase key �Լ�
{
	while (index > 0)
	{
		int p_index = (index - 1) / 2; // parent index

		if (A[index].second < A[p_index].second) // child�� �� ���� ���
		{
			swap(index, p_index); // parent�� child�� ��ȯ
			index = p_index; // parent�� �̵�
		}

		else
			break;
	}
}

void Priority_Queue::Min_Heapify(int index) // min heapify �Լ�
{
	int size = A.size();

	while (index < size)
	{
		int l = 2 * index + 1; // ���� child
		int r = 2 * index + 2; // ������ child
		int min = index; // �ּڰ�(root)

		if (l < size && A[l].second < A[min].second) // ���� child�� �ּڰ����� ���� ���
			min = l;

		if (r < size && A[r].second < A[min].second) // ������ child�� �ּڰ����� ���� ���
			min = r;

		if (min != index) // min�� ���ŵ� ���
		{
			swap(index, min); // �� ��ġ ��ȯ
			index = min; // min ��ġ�� �̵�
		}

		else
			break;
	}
}

void Priority_Queue::swap(int a, int b)  // ��ȯ �Լ�
{
	pair<int, int> temp = A[a];
	A[a] = A[b];
	A[b] = temp;
}
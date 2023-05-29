#ifndef Priority_Queue_H
#define Priority_Queue_H

#include <iostream>
#include <vector>

using namespace std;

class Priority_Queue
{
	vector<pair<int, int>> A; // pair���� first: vertex, second: distance
	void Increase_Key(int index); // �߰��� ���� ���� tree �籸�� (���� �̵�)
	void Min_Heapify(int index); // ������ ���� ���� tree �籸�� (�Ʒ��� �̵�)
	void swap(int a, int b); // �� ��ġ �ٲٱ�

public:
	void push(int key, int value); // �� �߰�
	void pop(); // �� ����
	int size(); // ť ũ��
	pair<int, int> top(); // �� ���� �� ��ȯ
	bool empty(); // ť�� ������� Ȯ��
};

#endif

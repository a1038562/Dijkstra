#include "Adjacency_List.h"

Adjacency_List::Adjacency_List(int vertex_num) : vertex_num(vertex_num)
{
	// �ʱ�ȭ ����
	// vertex ������ ���� ũ�� ����

	Adj_List.resize(vertex_num);

	for (int i = 0; i < vertex_num; i++)
	{
		vector<pair<int, int>> list;
		Adj_List.push_back(list);
	}
}

void Adjacency_List::add(int from, int to, int dist) // ���� ����Ʈ�� ���� �߰��ϴ� �Լ�
{
	Adj_List[from].push_back(make_pair(to, dist)); 
}

vector<vector<pair<int, int>>>  Adjacency_List::get_Adj_List() // ���� ����Ʈ�� ��ȯ�ϴ� �Լ�
{
	return Adj_List;
}



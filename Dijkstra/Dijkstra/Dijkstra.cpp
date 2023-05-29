#include "Dijkstra.h"

Dijkstra::Dijkstra(vector<vector<pair<int, int>>>Adj_List, int s, int vertex_num)
{
	// �ʱ�ȭ ����
	this->Adj_List = Adj_List;
	this->vertex_num = vertex_num;
	this->s = s;
	d.resize(vertex_num, 1e5);
	p.resize(vertex_num, -1);
	dijkstra(Adj_List, s, vertex_num); // dijkstra ����
}

void Dijkstra::dijkstra(vector<vector<pair<int, int>>>& Adj_List, int s, int vertex_num)
{
	// ������ ���� �߰�
	Q.push(s, 0); // ť�� �߰�
	d[s] = 0; // �Ÿ� �߰�

	while (!Q.empty())
	{
		// ť���� distance�� ���� ����� vertex�� ����� vertex, distance ��������
		int u = Q.top().first;
		Q.pop(); // ������ ���� ť���� ����

		// ���� vertex�� ����� ��� vertex�� ���� ����
		for (int i = 0; i < Adj_List[u].size(); i++)
		{
			int v = Adj_List[u][i].first; // vertex
			int w = Adj_List[u][i].second; // distance

			// relax ����
			if (d[v] > d[u] + w) // ����� vertex�� �Ÿ��� ���� vertex �Ÿ���
			{					// �� vertex ������ �Ÿ��� ���� ������ ���� ũ�� ����
				d[v] = d[u] + w; // ����� vertex�� �Ÿ� ����
				Q.push(v, d[v]); // ����� vertex ������ ť�� ����
				p[v] = u; // parent�� ���� vertex�� ����
			}
		}
	}

	// ��� ���
	cout << "\nPath : Distance\n";
	for (int n = 0; n < vertex_num; n++)
	{
		cout << 1;
		print_path(p, n); // path ���
		cout << " : " << d[n] << "\n"; // �Ÿ� ���
	}
}

void Dijkstra::print_path(vector<int> p, int n)
{
	if (p[n] == -1) // s�� ���
		return;

	print_path(p, p[n]); // parent�� �̵�
	cout << " -> " << n + 1; // vertex ���
}
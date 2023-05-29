#include "Dijkstra.h"

Dijkstra::Dijkstra(vector<vector<pair<int, int>>>Adj_List, int s, int vertex_num)
{
	// 초기화 과정
	this->Adj_List = Adj_List;
	this->vertex_num = vertex_num;
	this->s = s;
	d.resize(vertex_num, 1e5);
	p.resize(vertex_num, -1);
	dijkstra(Adj_List, s, vertex_num); // dijkstra 실행
}

void Dijkstra::dijkstra(vector<vector<pair<int, int>>>& Adj_List, int s, int vertex_num)
{
	// 시작점 정보 추가
	Q.push(s, 0); // 큐에 추가
	d[s] = 0; // 거리 추가

	while (!Q.empty())
	{
		// 큐에서 distance가 가장 가까운 vertex에 연결된 vertex, distance 꺼내오기
		int u = Q.top().first;
		Q.pop(); // 꺼내온 값을 큐에서 삭제

		// 현재 vertex에 연결된 모든 vertex에 대해 실행
		for (int i = 0; i < Adj_List[u].size(); i++)
		{
			int v = Adj_List[u][i].first; // vertex
			int w = Adj_List[u][i].second; // distance

			// relax 과정
			if (d[v] > d[u] + w) // 연결된 vertex의 거리가 현재 vertex 거리에
			{					// 두 vertex 사이의 거리를 더한 값보다 보다 크면 실행
				d[v] = d[u] + w; // 연결된 vertex의 거리 갱신
				Q.push(v, d[v]); // 연결된 vertex 정보를 큐에 저장
				p[v] = u; // parent를 현재 vertex로 지정
			}
		}
	}

	// 결과 출력
	cout << "\nPath : Distance\n";
	for (int n = 0; n < vertex_num; n++)
	{
		cout << 1;
		print_path(p, n); // path 출력
		cout << " : " << d[n] << "\n"; // 거리 출력
	}
}

void Dijkstra::print_path(vector<int> p, int n)
{
	if (p[n] == -1) // s인 경우
		return;

	print_path(p, p[n]); // parent로 이동
	cout << " -> " << n + 1; // vertex 출력
}
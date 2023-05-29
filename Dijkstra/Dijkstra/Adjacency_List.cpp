#include "Adjacency_List.h"

Adjacency_List::Adjacency_List(int vertex_num) : vertex_num(vertex_num)
{
	// 초기화 과정
	// vertex 개수에 따라 크기 설정

	Adj_List.resize(vertex_num);

	for (int i = 0; i < vertex_num; i++)
	{
		vector<pair<int, int>> list;
		Adj_List.push_back(list);
	}
}

void Adjacency_List::add(int from, int to, int dist) // 인접 리스트에 값을 추가하는 함수
{
	Adj_List[from].push_back(make_pair(to, dist)); 
}

vector<vector<pair<int, int>>>  Adjacency_List::get_Adj_List() // 인접 리스트를 반환하는 함수
{
	return Adj_List;
}



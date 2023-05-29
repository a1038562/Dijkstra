#ifndef Dijkstra_H
#define Dijkstra_H

#include "Priority_Queue.h"
#include "Adjacency_List.h"
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Dijkstra
{
	int vertex_num; // vertex 개수
	vector<vector<pair<int, int>>> Adj_List; // 인접 리스트
	Priority_Queue Q; // queue
	vector<int> d; // distance
	vector<int> p; // parent
	int s; // 시작점

public:
	Dijkstra(vector<vector<pair<int, int>>>Adj_List, int s, int vertex_num);
	void dijkstra(vector<vector<pair<int, int> >>& Adj_List, int s, int vertex_num); // dijkstra 실행
	void print_path(vector<int> p, int n); // path 출력
};

#endif

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
	int vertex_num; // vertex ����
	vector<vector<pair<int, int>>> Adj_List; // ���� ����Ʈ
	Priority_Queue Q; // queue
	vector<int> d; // distance
	vector<int> p; // parent
	int s; // ������

public:
	Dijkstra(vector<vector<pair<int, int>>>Adj_List, int s, int vertex_num);
	void dijkstra(vector<vector<pair<int, int> >>& Adj_List, int s, int vertex_num); // dijkstra ����
	void print_path(vector<int> p, int n); // path ���
};

#endif

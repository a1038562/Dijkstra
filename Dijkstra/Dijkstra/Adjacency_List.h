#ifndef Adjacency_List_H
#define Adjacency_List_H

#include <iostream>
#include <vector>

using namespace std;

class Adjacency_List {
	int vertex_num; // vertex 개수
	vector<vector<pair<int, int>>> Adj_List; // 인접 리스트

public:
	Adjacency_List(int numVertices); 
	void add(int from, int to, int dist); // 값 추가
	void print(); // 출력
	vector<vector<pair<int, int>>> get_Adj_List(); // 인접 리스트 반환
};

#endif
#ifndef Adjacency_List_H
#define Adjacency_List_H

#include <iostream>
#include <vector>

using namespace std;

class Adjacency_List {
	int vertex_num; // vertex ����
	vector<vector<pair<int, int>>> Adj_List; // ���� ����Ʈ

public:
	Adjacency_List(int numVertices); 
	void add(int from, int to, int dist); // �� �߰�
	void print(); // ���
	vector<vector<pair<int, int>>> get_Adj_List(); // ���� ����Ʈ ��ȯ
};

#endif
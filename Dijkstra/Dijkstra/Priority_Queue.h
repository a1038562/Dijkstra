#ifndef Priority_Queue_H
#define Priority_Queue_H

#include <iostream>
#include <vector>

using namespace std;

class Priority_Queue
{
	vector<pair<int, int>> A; // pair에서 first: vertex, second: distance
	void Increase_Key(int index); // 추가된 값에 대해 tree 재구성 (위로 이동)
	void Min_Heapify(int index); // 삭제된 값에 대해 tree 재구성 (아래로 이동)
	void swap(int a, int b); // 값 위치 바꾸기

public:
	void push(int key, int value); // 값 추가
	void pop(); // 값 삭제
	int size(); // 큐 크기
	pair<int, int> top(); // 맨 앞의 값 반환
	bool empty(); // 큐가 비었는지 확인
};

#endif

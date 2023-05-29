#include "Dijkstra.h"
#include <io.h>

pair<vector<vector<int>>, int> read_file() // csv 파일을 읽는 함수
{
	vector<vector<int>> Adj_Matrix; // 인접 행렬
	int vertex_num; // vertex 개수
	ifstream file;
	string s;
	string file_name;

	cout << "파일명(.csv): "; 
	cin >> file_name; // 파일명 입력 받기

	if (_access(file_name.c_str(), 0) == -1) // 파일이 존재하지 않는 경우
	{
		throw string("파일이 존재하지 않습니다.\n");
	}

	file.open(file_name); // 읽을 csv 파일 경로
	while (getline(file, s)) // 줄마다 읽기
	{
		if (s.find(',') != string::npos) // 문자열에 ','이 포함된 경우
		{
			vector<int> row;
			stringstream iss(s); // istringstream iss에 문자열 s를 넣어서 초기화
			string col;

			while (getline(iss, col, ',')) // ','을 기준으로 문자열 parsing
				row.push_back(stoi(col)); // 열 저장

			Adj_Matrix.push_back(row); // 행 저장
		}

		else // 문자열에 ','이 포함되지 않은 경우 -> vertex
			vertex_num = stoi(s); // vertex 저장
	}
	file.close(); // 파일 닫기
	return make_pair(Adj_Matrix, vertex_num);
}

//인접 리스트 생성 함수
vector<vector<pair<int, int> > > generate_Adj_List(vector<vector<int>> Adj_Matrix, int vertex_num)
{
	Adjacency_List Adj_List(vertex_num); // 인접 리스트 

	for (int i = 0; i < vertex_num; i++) // 2차원 벡터를 행 별로 반복
	{
		for (int j = 0; j < vertex_num; j++) // 각 행을 열 별로 반복
		{
			if (Adj_Matrix[i][j] != 0) // 인접한 vertex 사이에 edge가 존재하는 경우
			{
				// 인접 행렬에 저장된 값을 인접 리스트에 추가
				Adj_List.add(i, j, Adj_Matrix[i][j]); // from, to, distance 값 추가
			}
		}
	}

	return Adj_List.get_Adj_List();
}

int main()
{
	vector<vector<int>> Adj_Matrix; // 인접 행렬
	vector<vector<pair<int, int>>> Adj_List; // 인접 리스트
	int vertex_num; // vertex 개수
	int s = 0; // 시작점
	pair<vector<vector<int>>, int> file = make_pair(Adj_Matrix, vertex_num); // 파일 정보

	try
	{
		// 파일 읽기
		file = read_file(); 
		Adj_Matrix = file.first;
		vertex_num = file.second;

		Adj_List = generate_Adj_List(Adj_Matrix, vertex_num); // 인접 리스트 생성
		Dijkstra Dijkstra(Adj_List, s, vertex_num); // dijkstra 실행
	}

	catch (string expn) // 파일이 존재하지 않는 경우 예외 처리
	{
		cout << expn;
	}

	return 0;
}
#include "Dijkstra.h"
#include <io.h>

pair<vector<vector<int>>, int> read_file() // csv ������ �д� �Լ�
{
	vector<vector<int>> Adj_Matrix; // ���� ���
	int vertex_num; // vertex ����
	ifstream file;
	string s;
	string file_name;

	cout << "���ϸ�(.csv): "; 
	cin >> file_name; // ���ϸ� �Է� �ޱ�

	if (_access(file_name.c_str(), 0) == -1) // ������ �������� �ʴ� ���
	{
		throw string("������ �������� �ʽ��ϴ�.\n");
	}

	file.open(file_name); // ���� csv ���� ���
	while (getline(file, s)) // �ٸ��� �б�
	{
		if (s.find(',') != string::npos) // ���ڿ��� ','�� ���Ե� ���
		{
			vector<int> row;
			stringstream iss(s); // istringstream iss�� ���ڿ� s�� �־ �ʱ�ȭ
			string col;

			while (getline(iss, col, ',')) // ','�� �������� ���ڿ� parsing
				row.push_back(stoi(col)); // �� ����

			Adj_Matrix.push_back(row); // �� ����
		}

		else // ���ڿ��� ','�� ���Ե��� ���� ��� -> vertex
			vertex_num = stoi(s); // vertex ����
	}
	file.close(); // ���� �ݱ�
	return make_pair(Adj_Matrix, vertex_num);
}

//���� ����Ʈ ���� �Լ�
vector<vector<pair<int, int> > > generate_Adj_List(vector<vector<int>> Adj_Matrix, int vertex_num)
{
	Adjacency_List Adj_List(vertex_num); // ���� ����Ʈ 

	for (int i = 0; i < vertex_num; i++) // 2���� ���͸� �� ���� �ݺ�
	{
		for (int j = 0; j < vertex_num; j++) // �� ���� �� ���� �ݺ�
		{
			if (Adj_Matrix[i][j] != 0) // ������ vertex ���̿� edge�� �����ϴ� ���
			{
				// ���� ��Ŀ� ����� ���� ���� ����Ʈ�� �߰�
				Adj_List.add(i, j, Adj_Matrix[i][j]); // from, to, distance �� �߰�
			}
		}
	}

	return Adj_List.get_Adj_List();
}

int main()
{
	vector<vector<int>> Adj_Matrix; // ���� ���
	vector<vector<pair<int, int>>> Adj_List; // ���� ����Ʈ
	int vertex_num; // vertex ����
	int s = 0; // ������
	pair<vector<vector<int>>, int> file = make_pair(Adj_Matrix, vertex_num); // ���� ����

	try
	{
		// ���� �б�
		file = read_file(); 
		Adj_Matrix = file.first;
		vertex_num = file.second;

		Adj_List = generate_Adj_List(Adj_Matrix, vertex_num); // ���� ����Ʈ ����
		Dijkstra Dijkstra(Adj_List, s, vertex_num); // dijkstra ����
	}

	catch (string expn) // ������ �������� �ʴ� ��� ���� ó��
	{
		cout << expn;
	}

	return 0;
}
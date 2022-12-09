/*
  ���ϸ� : "HW13_21912193_�Ŵ�ȫ"
  ���α׷��� ���� �� �⺻ ���:
	- Graph�ڷᱸ���� DepthFirstSearch �˰����� �����Ͽ� �̷�ã�⸦ ����
	- Graph�ڷᱸ���� Dijkstra�� ���� �ִܰŸ� ã��
	- Graph�ڷᱸ���� MinimumSpannigTree���·� �����ϰ� ����غ���

  ���α׷� �ۼ��� : �Ŵ�ȫ(2022�� 12�� 9��)
  ���� Update : Version 1.0.0, 2022�� 12�� 9��(�Ŵ�ȫ)
===========================================================================================================
					���α׷� ����/���� �̷�
===========================================================================================================
   ������	  ������			����			     ����/���ϳ���
-----------------------------------------------------------------------------------------------------------
	�Ŵ�ȫ		 2022/12/06		v1.0.0		  �����ۼ�
	�Ŵ�ȫ		 2022/12/08		v1.1.0		  �ѱ� ���� �׷��� �ڷ� �߰�
	�Ŵ�ȫ		 2022/12/09		v1.2.0		  DFS, BFS �˰��� �߰�

===========================================================================================================
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include "Graph.h"
#include "DepthFIrstSearch.h"
#include "BFS_Dijkstra.h"
#include "MST_Prim.h"

using namespace std;

#define INPUT1 "Mesh_5x5.txt"
#define INPUT2 "Korea_11.txt"

void fGetGraph(Graph* g, string fin_name)
{
	ifstream fin(fin_name);
	if (fin.fail())
	{
		cout << "Error!! Fail to opening input File (" << fin_name << ") for graph initialization." << endl;
		exit(-1);
	}

	string gName, v1, v2;		// �׷����� �̸�, Vertex�� �̸� 1, 2
	double dist = 0.0;			// �� ���������� �Ÿ�
	Vertex vrtx1, vrtx2, * pVrtx1 = NULL, * pVrtx2 = NULL;
	Edge e1, e2;
	// ����, ������ ����
	int num_vrtx = 0;
	int num_edges = 0;

	fin >> gName >> num_vrtx;		// �׷����� �̸�, ����� ������ �޾ƿ�
	g->initGraph(gName, num_vrtx);
	cout << "Initializing Graph (" << gName << ") from input file (" << fin_name << ") . . . " << endl;

	// ���� ������ ���������� ���ѹݺ�
	while (!fin.eof())
	{
		fin >> v1 >> v2 >> dist;		// ������ �̸���, �Ÿ��� �Է¹���
		cout << "Insert Edge (" << v1 << " �� " << v2 << ": " << dist << ")" << endl;
		// ������ ���� ��, �׷����� �������
		vrtx1 = Vertex(v1, -1); vrtx2 = Vertex(v2, -1);
		pVrtx1 = g->insertVertex(vrtx1); pVrtx2 = g->insertVertex(vrtx2);

		// ������ ������ ������ ���� ��, �׷����� ����
		e1 = Edge(*pVrtx1, *pVrtx2, dist); e2 = Edge(*pVrtx2, *pVrtx1, dist);
		g->insertEdge(e1); g->insertEdge(e2);
		num_edges++;		//������ ���� ����
	}

	cout << "Total " << g->NumVertices() << " vertices and " << num_edges << "bi-directional edges were inserted to graph" << endl;
	fin.close();
}
void test_DepthFirstSearch(Graph* pG)
{
	cout << "\n*********************************************" << endl;
	cout << "Testing dfsGraph..." << endl;
	DepthFirstSearch dfsGraph(*pG);
	pG->initDistMtrx();
	dfsGraph.showConnectivity(cout);

	string start_nm, end_nm;
	Vertex* pStart, * pEnd;
	VrtxList path;

	while (1)
	{
		cout << "Input start and end of path to search shortest path ( . . to quit) : ";
		cin >> start_nm >> end_nm;
		if (start_nm == ".")
			break;
		// ����, ������ ����� �̸����� Vertex�� ��ȯ����
		pStart = pG->getVertex(start_nm);
		pEnd = pG->getVertex(end_nm);

		// ���� ã�� ���ϸ� ����
		if (pStart == NULL || pEnd == NULL)
		{
			cout << "Error in start or end vertex name !! " << endl;
			continue;
		}

		path.clear();
		// Ž���� �����ϰ�, ���� ����� path�� �����´�.
		dfsGraph.findPath(*pStart, *pEnd, path);
		// ������ path�� ������, ����� �����Ѵ�.
		cout << "\n Path found by DFS (" << pStart->Name() << " ==> " << pEnd->Name() << ") : ";
		for (VrtxItor vItor = path.begin(); vItor != path.end(); ++vItor)
			cout << *vItor << " �� ";
		cout << "end" << endl;

	//--------------------------------------------------------------------------------------------------
		// �ݴ�������ε� ����
		pStart = pG->getVertex(end_nm);
		pEnd = pG->getVertex(start_nm);

		path.clear();
		// Ž���� �����ϰ�, ���� ����� path�� �����´�.
		dfsGraph.findPath(*pStart, *pEnd, path);
		// ������ path�� ������, ����� �����Ѵ�.
		cout << " Path found by DFS (" << pStart->Name() << " ==> " << pEnd->Name() << ") : ";
		for (VrtxItor vItor = path.begin(); vItor != path.end(); ++vItor)
			cout << *vItor << " �� ";
		cout << "end" << endl;
	}
}
void test_DijkstraSearch(Graph* pG)
{
	cout << "\n**********************************************************" << endl;
	cout << "Testing bfsGraph..." << endl;
	BreadthFirstSearch bfsGraph(*pG);
	pG->initDistMtrx();
	pG->fprintDistMtrx(cout);

	string start_nm, end_nm;
	Vertex* pStart, * pEnd;
	VrtxList path;

	while (1)
	{
		cout << "Input start and end of path to search shortest path ( . . to quit) : ";
		cin >> start_nm >> end_nm;
		if (start_nm == ".")
			break;
		// ����, ������ ����� �̸����� Vertex�� ��ȯ����
		pStart = pG->getVertex(start_nm);
		pEnd = pG->getVertex(end_nm);

		// ���� ã�� ���ϸ� ����
		if (pStart == NULL || pEnd == NULL)
		{
			cout << "Error in start or end vertex name !! " << endl;
			continue;
		}

		// ��� Ŭ����
		path.clear();
		cout << "\n\nFinding Shortest paths (using Dijkstra) from " << pStart->Name() << " to " <<
			pEnd->Name() << " : " << endl;
		// Ž�� ��, ��� path �� ��ȯ���� 
		bfsGraph.DijkstraShortestPath(cout, *pStart, *pEnd, path);
		// ���
		cout << "Path found by Dijkstra (shortest) from " << pStart->Name() << " to " << pEnd->Name() << " : ";
		for (VrtxItor vItor = path.begin(); vItor != path.end(); ++vItor)
			cout << *vItor << " �� ";
		cout << "end" << endl;
	//---------------------------------------------------------------------------------------------------
		// �ݴ�������ε� ���
		pStart = pG->getVertex(end_nm);
		pEnd = pG->getVertex(start_nm);

		// ��� Ŭ����
		path.clear();
		cout << "\nFinding Shortest paths (using Dijkstra) from " << pStart->Name() << " to " <<
			pEnd->Name() << " : " << endl;
		// Ž�� ��, ��� path �� ��ȯ���� 
		bfsGraph.DijkstraShortestPath(cout, *pStart, *pEnd, path);
		// ���
		cout << "Path found by Dijkstra (shortest) from " << pStart->Name() << " to " << pEnd->Name() << " : ";
		for (VrtxItor vItor = path.begin(); vItor != path.end(); ++vItor)
			cout << *vItor << " �� ";
		cout << "end" << endl;
	}
}
void test_MinimumSpanningTree(Graph* pG)
{
	cout << "\n**********************************************************" << endl;
	cout << "Testing MSTGraph..." << endl;
	MinimumSpanningTree mstGraph(*pG);
	pG->initDistMtrx();
	pG->fprintDistMtrx(cout);

	string start_nm, end_nm;
	VrtxList path;

	cout << "MST Shortest Path Graph.... " << endl;
	mstGraph.PrimJarnikMST();
}

int main(void)
{
	Graph simpleGraph;
	int test_mode = 0;

	//system("mode con: cols=150 lines=50");
	fGetGraph(&simpleGraph, INPUT2);

	simpleGraph.fprintGraph(cout);
	cout << endl;

	while (1)
	{
		cout << "input test mode (1: Depth_First_Search (DFS), 2: Dijkstra_Search, 3: MinimumSpanningTree, 0: quit) :";
		cin >> test_mode;

		switch (test_mode)
		{
		case 1:
		{
			test_DepthFirstSearch(&simpleGraph);
			break;
		}
		case 2:
		{
			test_DijkstraSearch(&simpleGraph);
			break;
		}
		case 3:
		{
			test_MinimumSpanningTree(&simpleGraph);
			break;
		}
		case 0:
			return 0;
		}
	}

	return 0;
}
/*
  파일명 : "HW13_21912193_신대홍"
  프로그램의 목적 및 기본 기능:
	- Graph자료구조의 DepthFirstSearch 알고리즘을 적용하여 미로찾기를 진행
	- Graph자료구조를 Dijkstra를 통해 최단거리 찾기
	- Graph자료구조를 MinimumSpannigTree형태로 구성하고 출력해보기

  프로그램 작성자 : 신대홍(2022년 12월 9일)
  최종 Update : Version 1.0.0, 2022년 12월 9일(신대홍)
===========================================================================================================
					프로그램 수정/보완 이력
===========================================================================================================
   수정자	  수정일			버전			     수정/보완내용
-----------------------------------------------------------------------------------------------------------
	신대홍		 2022/12/06		v1.0.0		  최초작성
	신대홍		 2022/12/08		v1.1.0		  한국 지리 그래프 자료 추가
	신대홍		 2022/12/09		v1.2.0		  DFS, BFS 알고리즘 추가

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

	string gName, v1, v2;		// 그래프의 이름, Vertex의 이름 1, 2
	double dist = 0.0;			// 두 정점사이의 거리
	Vertex vrtx1, vrtx2, * pVrtx1 = NULL, * pVrtx2 = NULL;
	Edge e1, e2;
	// 정점, 간선의 개수
	int num_vrtx = 0;
	int num_edges = 0;

	fin >> gName >> num_vrtx;		// 그래프의 이름, 노드의 개수를 받아옴
	g->initGraph(gName, num_vrtx);
	cout << "Initializing Graph (" << gName << ") from input file (" << fin_name << ") . . . " << endl;

	// 파일 끝까지 읽을때까지 무한반복
	while (!fin.eof())
	{
		fin >> v1 >> v2 >> dist;		// 정점의 이름들, 거리를 입력받음
		cout << "Insert Edge (" << v1 << " → " << v2 << ": " << dist << ")" << endl;
		// 정점을 생성 후, 그래프에 집어넣음
		vrtx1 = Vertex(v1, -1); vrtx2 = Vertex(v2, -1);
		pVrtx1 = g->insertVertex(vrtx1); pVrtx2 = g->insertVertex(vrtx2);

		// 정점간 간선의 정보를 생성 후, 그래프에 삽입
		e1 = Edge(*pVrtx1, *pVrtx2, dist); e2 = Edge(*pVrtx2, *pVrtx1, dist);
		g->insertEdge(e1); g->insertEdge(e2);
		num_edges++;		//가선의 개수 갱신
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
		// 시작, 목적지 노드의 이름으로 Vertex를 반환받음
		pStart = pG->getVertex(start_nm);
		pEnd = pG->getVertex(end_nm);

		// 만약 찾지 못하면 종료
		if (pStart == NULL || pEnd == NULL)
		{
			cout << "Error in start or end vertex name !! " << endl;
			continue;
		}

		path.clear();
		// 탐색을 진행하고, 최종 경로인 path를 가져온다.
		dfsGraph.findPath(*pStart, *pEnd, path);
		// 가져온 path를 가지고, 출력을 진행한다.
		cout << "\n Path found by DFS (" << pStart->Name() << " ==> " << pEnd->Name() << ") : ";
		for (VrtxItor vItor = path.begin(); vItor != path.end(); ++vItor)
			cout << *vItor << " → ";
		cout << "end" << endl;

	//--------------------------------------------------------------------------------------------------
		// 반대방향으로도 진행
		pStart = pG->getVertex(end_nm);
		pEnd = pG->getVertex(start_nm);

		path.clear();
		// 탐색을 진행하고, 최종 경로인 path를 가져온다.
		dfsGraph.findPath(*pStart, *pEnd, path);
		// 가져온 path를 가지고, 출력을 진행한다.
		cout << " Path found by DFS (" << pStart->Name() << " ==> " << pEnd->Name() << ") : ";
		for (VrtxItor vItor = path.begin(); vItor != path.end(); ++vItor)
			cout << *vItor << " → ";
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
		// 시작, 목적지 노드의 이름으로 Vertex를 반환받음
		pStart = pG->getVertex(start_nm);
		pEnd = pG->getVertex(end_nm);

		// 만약 찾지 못하면 종료
		if (pStart == NULL || pEnd == NULL)
		{
			cout << "Error in start or end vertex name !! " << endl;
			continue;
		}

		// 경로 클리어
		path.clear();
		cout << "\n\nFinding Shortest paths (using Dijkstra) from " << pStart->Name() << " to " <<
			pEnd->Name() << " : " << endl;
		// 탐색 후, 경로 path 를 반환받음 
		bfsGraph.DijkstraShortestPath(cout, *pStart, *pEnd, path);
		// 출력
		cout << "Path found by Dijkstra (shortest) from " << pStart->Name() << " to " << pEnd->Name() << " : ";
		for (VrtxItor vItor = path.begin(); vItor != path.end(); ++vItor)
			cout << *vItor << " → ";
		cout << "end" << endl;
	//---------------------------------------------------------------------------------------------------
		// 반대방향으로도 출력
		pStart = pG->getVertex(end_nm);
		pEnd = pG->getVertex(start_nm);

		// 경로 클리어
		path.clear();
		cout << "\nFinding Shortest paths (using Dijkstra) from " << pStart->Name() << " to " <<
			pEnd->Name() << " : " << endl;
		// 탐색 후, 경로 path 를 반환받음 
		bfsGraph.DijkstraShortestPath(cout, *pStart, *pEnd, path);
		// 출력
		cout << "Path found by Dijkstra (shortest) from " << pStart->Name() << " to " << pEnd->Name() << " : ";
		for (VrtxItor vItor = path.begin(); vItor != path.end(); ++vItor)
			cout << *vItor << " → ";
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
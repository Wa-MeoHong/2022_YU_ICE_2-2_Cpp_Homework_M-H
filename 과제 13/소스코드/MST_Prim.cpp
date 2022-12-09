#include "MST_Prim.h"

void MinimumSpanningTree::initialize()
{
	Vertex* pVrtx = getGraph().pVrtxArr();
	VrtxList vrtxLst;

	this->graph.vertices(vrtxLst);		// vertex의 리스트를 반환
	int num_vertices = getNumVertices();
	for (int vID = 0; vID < num_vertices; vID++)
		pVrtx[vID].SetVrtxStat(UN_VISITED);

	EdgeList edges;
	this->graph.edges(edges);
	for (EdgeItor pe = edges.begin(); pe != edges.end(); ++pe)
		pe->SetEdgeStat(EDGE_UN_VISITED);
}

void MinimumSpanningTree::PrimJarnikMST()
{
	int num_nodes;
	Vertex* pVrtxArray = graph.pVrtxArr();
	EdgeList* pAdjLstArray = graph.pAdjLstArr();

	double** ppDistMtrx = graph.DistMtrx();
	double* pDist;

	Edge* pEdge;
	int start, min_id, dist, min_dist, end_ID;
	VrtxStatus* pVrtxStatus;

	Graph::Edge* pParentEdge, edge, min_edge;	// edge that connected
	list<Graph::Edge> selectedEdgeLst;
	list<Graph::Edge>::iterator edgeItor;

	num_nodes = graph.NumVertices();
	pDist = new double[num_nodes];
	pVrtxStatus = new VrtxStatus[num_nodes];
	pEdge = new Edge[num_nodes];
	pParentEdge = new Edge[num_nodes];

	for (int i = 0; i < num_nodes; i++)
	{
		pDist[i] = PLUS_INF;
		pVrtxStatus[i] = Not_SELECTED;
		pParentEdge[i] = Edge();
	}
	srand(time(0));
	start = rand() % num_nodes;
	cout << "Start node " << start << endl;
	pDist[start] = 0;
	selectedEdgeLst.clear();

	for (int round = 0; round < num_nodes; round++)
	{
		min_dist = PLUS_INF;
		min_id = -1;
		for (int n = 0; n < num_nodes; n++)
		{
			if ((pVrtxStatus[n] == Not_SELECTED) && (pDist[n] < min_dist))
			{
				min_dist = pDist[n];
				min_id = n;
			}
		}
		if (min_id == -1)
		{
			cout << "Error in finding Prim-Jarnik's algorithm !!" << endl;
			break;
		}
		pVrtxStatus[min_id] = SELECTed;
		EdgeItor pe = pAdjLstArray[min_id].begin();
		while (pe != pAdjLstArray[min_id].end())
		{
			end_ID = (*(*pe).pvrtx_2()).Id();
			dist = (*pe).Distance();
			if ((pVrtxStatus[end_ID] == Not_SELECTED) && (dist <= pDist[end_ID]))
			{
				pDist[end_ID] = dist;
				pParentEdge[end_ID] = *pe;
			}
			pe++;
		}
		if (min_id != start)
		{
			min_edge = pParentEdge[min_id];
			selectedEdgeLst.push_back(min_edge);
		}

		cout << "Dist after round [" << setw(2) << round << "] : ";
		for (int i = 0; i < num_nodes; i++)
		{
			if (pDist[i] == PLUS_INF)
				cout << setw(5) << "+oo";
			else
				cout << setw(5) << pDist[i];

		}
		cout << endl;
	}

	cout << "\nEnd of finding Minimum Spanning Tree by Prim-Jarnik's Algorithm";
	cout << "SelectedEdgeLst.size = " << selectedEdgeLst.size() << endl;
	cout << "Selected edges : " << endl;

	edgeItor = selectedEdgeLst.begin();
	int cnt = 0;
	while (edgeItor != selectedEdgeLst.end())
	{
		cout << *edgeItor << ", ";
		edgeItor++;
		if ((++cnt % 5) == 0)
			cout << endl;
	}
	cout << endl;
}


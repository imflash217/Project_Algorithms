#include <stdio.h>
#include <limits.h>

#define TotalNodes 10

int minCostNode(int cost[], bool isInSPTSet[]){

        int minCost = INT_MAX;
        int minCostNode_index;

        for(int n=0; n<TotalNodes; n++) {
                if(isInSPTSet[n] == false && cost[n] <= minCost) {
                        minCost = cost[n];
                        minCostNode_index = n;
                }
        }
        return minCostNode_index;       // returning the node w/ min cost
}


// Print the constructed cost array
int printCostArray(int cost[], int totalNodes){
        printf("Node cost from start\n");
        for(int i=0; i < totalNodes; i++) {
                printf("%d \t\t %d\n", i, cost[i]);
        }
}


// Dijksta's algorithm: single-source-shortest-path

void dijkstraAlgorithm(int graph[TotalNodes][TotalNodes], int startNode){
        int m_cost[TotalNodes]; // shortestPath cost from start to node i

        bool m_isInSPTSet[TotalNodes];      // stores if the node is in SPT

        // initialize all costs as INFINITE & isInSPTSet[] as false
        for(int i = 0; i < TotalNodes; i++) {
                m_cost[i] = INT_MAX;  // INT_MAX == INFINITE
                m_isInSPTSet[i] = false;    // no nodes have been visited before the start of graph traversal
        }

        // cost of start-node from itself is ZERO
        m_cost[startNode] = 0;

        // finding shortestPath for all vertices
        for(int j = 0; j < TotalNodes-1; j++) {
                //pick the min cost node from the set of un-visited nodes
                int m_minCostIndex = minCostNode(m_cost, m_isInSPTSet);

                // mark the node as visted
                m_isInSPTSet[m_minCostIndex] = true;

                // update the value of the adjacent nodes of the visited node
                for(int k = 0; k < TotalNodes; k++) {
                        // update cost[k] iff node k is not yet visited & its cost is larger than the path cost from start node via m_minCostIndex
                        if(!m_isInSPTSet[k] && graph[m_minCostIndex][k] && m_cost[m_minCostIndex] != INT_MAX && m_cost[m_minCostIndex]+graph[m_minCostIndex][k] < m_cost[k]) {
                                m_cost[k] = m_cost[m_minCostIndex] + graph[m_minCostIndex][k];
                        }
                }
        }
        printCostArray(m_cost, TotalNodes);
}

int main(){
        // An example graph in the form of Adjacency matrix
        int m_exampleGraph[TotalNodes][TotalNodes] =
        {
                {0, 4, 0, 0, 0, 0, 0, 8, 0, 10},
                {4, 0, 8, 0, 0, 0, 0, 11, 0, 12},
                {0, 8, 0, 7, 0, 4, 0, 0, 2, 5},
                {0, 0, 7, 0, 9, 14, 0, 0, 0, 6},
                {0, 0, 0, 9, 0, 10, 0, 0, 0, 14},
                {0, 0, 4, 14, 10, 0, 2, 0, 0, 8},
                {0, 0, 0, 0, 0, 2, 0, 1, 6, 9},
                {8, 11, 0, 0, 0, 0, 1, 0, 7, 2},
                {1, 0, 1, 1, 10, 11, 2, 3, 9, 0},
                {0, 0, 2, 0, 0, 0, 6, 7, 0, 3}
        };

        dijkstraAlgorithm(m_exampleGraph, 9);
        return 0;
}

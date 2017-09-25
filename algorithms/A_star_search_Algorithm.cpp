// C++ implementation of A* algorithm:
#include <bits/stdc++.h>
#include <iostream>	// std::cout
#include <cmath>	// std::sqrt, std::pow
//#include <math.h>
#include <stack>	// std::stack
#include <utility> // std::pair std::make_pair

using namespace std;

#define ROW 9
#define COL 10
#define DIRECTIONS 8

// creating a shortcut for int, int pair type 

typedef pair<int, int> m_pair;
typedef pair<double, pair<int, int> > m_p_pair;

set<m_p_pair> openList;

/*
int m_directionalNodes[DIRECTIONS][2] = {
		{0,0},{0,0},{0,0},{0,0},
		{0,0},{0,0},{0,0},{0,0}
	};
*/

// A structure to hold necessary parameters of each node
struct node{
	// row & column index of its parents
	
	int parent_i, parent_j;		// 0 <= i <= ROW-1  &  0 <= j <= COL-1
	double F, G, H; 			// F = G + H
};

// Utility func to check whether a node(row,col) is a VALID node or not
bool isValidNode(int row, int col){
	// returns true if row number and col number are in range of ROW, COL
	return ((row >= 0) && (row < ROW) && (col >= 0) && (col < COL));	// 4 input AND GATE
}

// Utility func to check whether a given node is blocked(can't be visited) or not
bool isNodeUnblocked(int grid[ROW][COL], int row, int col){
	// returns true if cell is NOT blocked i.e can be visited
	if(grid[row][col] == 1){
		return true;
	}else{
		return false;
	}
}

// Utility function to check whether a node is destination node or not
bool isDestination(int row, int col, m_pair destNode){
	if(row == destNode.first && col == destNode.second){
		return true;
	}else{
		return false;
	}
}

// Utility func to calculate heuristic H
double calcHeuristic(int row, int col, m_pair destNode){
    printf("calcHeuristic() Enter!!\n");
    double HeuristicValue = (double) std::sqrt(pow(2.0, (row - destNode.first)) + pow(2.0, (col - destNode.second)));
	// using Eucledian-distance as heuristic
	// assuming that all nodes are equi-distance row-wise & col-wise from its neighbours
	printf("calcHeuristic() done!!--%f\n", HeuristicValue);
	return (HeuristicValue);
	
}

// Utility func to trace the path from source to destination
void tracePath(node nodeDetails[ROW][COL], m_pair destNode){
	printf("\nThe Path is: ");
	int row = destNode.first;
	int col = destNode.second;

	stack<m_pair> m_path;	// std::stack, creating a stack to store the path

	while(!(nodeDetails[row][col].parent_i == row && nodeDetails[row][col].parent_j == col)){
		m_path.push(make_pair(row, col));	// std::make_pair

		int temp_row = nodeDetails[row][col].parent_i;
		int temp_col = nodeDetails[row][col].parent_j;
		row = temp_row;
		col = temp_col;
	}

	m_path.push(make_pair(row, col));
	
	// pop all nodes in the path till the path stack become empty...printing the path
	while(!m_path.empty()){
		pair<int, int> temp_path = m_path.top();	// std::pair, the top element of m_path stack before popping
		m_path.pop();		// std::stack::pop
		printf("--(%d%d)", temp_path.first, temp_path.second);
	}
	printf("\n");
	return;
}

// A* search algorithm

void aStarAlgorithm(int grid[ROW][COL], m_pair srcNode, m_pair destNode){

	// if the source is out of range
	if(isValidNode(srcNode.first, srcNode.second) == false){
		printf("srcNode is invalid or Out-of-range\n");
		return;
	}

	// if the destination is out-of-range
	if(isValidNode(destNode.first, destNode.second) == false){
		printf("destination node is invalid or out-of-range\n");
		return;
	}

	// either the srcNode or destNode is blocked
	if(isNodeUnblocked(grid, srcNode.first, srcNode.second)){
		if(isNodeUnblocked(grid, destNode.first, destNode.second)){
			printf("Both srcNode & destNode are Unblocked\n");
		}else{
			printf("srcNode is Unblocked & destNode is blocked\n");
			return;
		}
	}else{
		if(isNodeUnblocked(grid, destNode.first, destNode.second)){
			printf("srcNode is blocked & destNode is Unblocked\n");
			return;		
		}else{
			printf("Both srcNode & destNode are Blocked\n");
			return;
		}
	}

	// if the srcNode == destNode
	if(isDestination(srcNode.first, srcNode.second, destNode)){
		printf("srcNode == destNode. We are already at the destination\n");
		return;
	}

	////////////////
	bool closedList[ROW][COL];
	memset(closedList, false, sizeof(closedList));

	//Declare a 2D array of structure to hold the details of the node
	node nodeDetails[ROW][COL];

	int i, j;
	for (i=0; i<ROW; i++){
		for(j=0; j<COL; j++){
			nodeDetails[i][j].F = FLT_MAX;
			nodeDetails[i][j].G = FLT_MAX;
			nodeDetails[i][j].H = FLT_MAX;

			nodeDetails[i][j].parent_i = -1;
			nodeDetails[i][j].parent_j = -1;
		}
	}

	// Initializing the parameters of the starting node
	i = srcNode.first;
	j = srcNode.second;
	nodeDetails[i][j].F = 0.0;
	nodeDetails[i][j].G = 0.0;
	nodeDetails[i][j].H = 0.0;
	nodeDetails[i][j].parent_i = i;
	nodeDetails[i][j].parent_i = j;

	/* Create an open list having info as:
	 * <f, <i, j>>  such that f = g +h  &&  0 <= i <= ROW-1 & 0 <= j <= COL-1
	 * This open list is implementes as a set of pair of pair
	*/

	 // set<m_p_pair> openList;

	 // Initializing the srcNode on the open list and set its f = 0
	 openList.insert(make_pair(0.0, make_pair(i,j)));	// for srcNode: f=0.0

	 // is the destination found
	 bool flag_isDestinationFound = false; // at t=0 destination is not found

	while(!openList.empty())
	{
	 	m_p_pair p = *openList.begin();

	 	// remove this node from open list
	 	openList.erase(openList.begin());

	 	// add this node to the openList
	 	i = p.second.first;
	 	j = p.second.second;
	 	closedList[i][j] = true;	// node (i,j) is visited


	 	/*
	 	 * Generating all the successors of this node
	 	*/

	 	// To store the 'g', 'h', and 'f' of the successors

	 	double f_new, g_new, h_new;


	 	
	 	//--------------------- 1st successor node ---------------------//

	 	// proceed only if the node is valid
	 	if(isValidNode(i-1, j)){

	 		// check if this node is the destination node
	 		if(isDestination(i-1, j, destNode)){
	 			// setting the parent of the destination node
	 			printf("Destination node is found\n");
	 			nodeDetails[i-1][j].parent_i = i;
	 			nodeDetails[i-1][j].parent_j = j;
	 			tracePath(nodeDetails,destNode);	// tracing the path from srcNode to destNode
	 			flag_isDestinationFound = true;
	 			return;
	 		}
	 		// check if this current successor-node is already in the closedList or Blocked then IGNORE else do the following
	 		else if(closedList[i-1][j]==false && isNodeUnblocked(grid, i-1, j)){
	 			g_new = nodeDetails[i][j].G + 1.0;	// increasing g-value by 1 unit
	 			h_new = calcHeuristic(i-1,j,destNode);
	 			printf("h_new_1 = %f\n", h_new);
	 			f_new = g_new + h_new;

	 			// check if the current successor-node is in the open list
	 			// if NOT, then add it to the open list
	 			// set its parent node
	 			// ******** OR *********
	 			// if its already in the open list then:
	 			// check if this current path's cost is better than earlier ones using 'f' as a measure

	 			if(nodeDetails[i-1][j].F == FLT_MAX || nodeDetails[i-1][j].F > f_new){
	 				
	 				// put the current successor-node in the open List
	 				openList.insert(make_pair(f_new, make_pair(i-1, j)));

	 				// update the details of this current successor-node
	 				nodeDetails[i-1][j].F = f_new;
	 				nodeDetails[i-1][j].G = g_new;
	 				nodeDetails[i-1][j].H = h_new;
	 				nodeDetails[i-1][j].parent_i = i;
	 				nodeDetails[i-1][j].parent_j = j;
	 			}
	 		}
	 	}
	 	
	 	

	 	//--------------------- 2nd successor node---------------------//
		
		// proceed only if the node is valid
	 	if(isValidNode(i+1, j)){

	 		// check if this node is the destination node
	 		if(isDestination(i+1, j, destNode)){
	 			// setting the parent of the destination node
	 			printf("Destination node is found\n");
	 			nodeDetails[i+1][j].parent_i = i;
	 			nodeDetails[i+1][j].parent_j = j;
	 			tracePath(nodeDetails,destNode);	// tracing the path from srcNode to destNode
	 			flag_isDestinationFound = true;
	 			return;
	 		}
	 		// check if this current successor-node is already in the closedList or Blocked then IGNORE else do the following
	 		else if(closedList[i+1][j]==false && isNodeUnblocked(grid, i+1, j)){
	 			g_new = nodeDetails[i][j].G + 1.0;	// increasing g-value by 1 unit
	 			h_new = calcHeuristic(i+1,j,destNode);
	 			f_new = g_new + h_new;

	 			// check if the current successor-node is in the open list
	 			// if NOT, then add it to the open list
	 			// set its parent node
	 			// ******** OR *********
	 			// if its already in the open list then:
	 			// check if this current path's cost is better than earlier ones using 'f' as a measure

	 			if(nodeDetails[i+1][j].F == FLT_MAX || nodeDetails[i+1][j].F > f_new){
	 				
	 				// put the current successor-node in the open List
	 				openList.insert(make_pair(f_new, make_pair(i+1, j)));

	 				// update the details of this current successor-node
	 				nodeDetails[i+1][j].F = f_new;
	 				nodeDetails[i+1][j].G = g_new;
	 				nodeDetails[i+1][j].H = h_new;
	 				nodeDetails[i+1][j].parent_i = i;
	 				nodeDetails[i+1][j].parent_j = j;
	 			}
	 		}
	 	}

	 	

	 	//--------------------- 3rd successor node ---------------------//	

	 	// proceed only if the node is valid
	 	if(isValidNode(i, j+1)){

	 		// check if this node is the destination node
	 		if(isDestination(i, j+1, destNode)){
	 			// setting the parent of the destination node
	 			printf("Destination node is found\n");
	 			nodeDetails[i][j+1].parent_i = i;
	 			nodeDetails[i][j+1].parent_j = j;
	 			tracePath(nodeDetails,destNode);	// tracing the path from srcNode to destNode
	 			flag_isDestinationFound = true;
	 			return;
	 		}
	 		// check if this current successor-node is already in the closedList or Blocked then IGNORE else do the following
	 		else if(closedList[i][j+1]==false && isNodeUnblocked(grid, i, j+1)){
	 			g_new = nodeDetails[i][j].G + 1.0;	// increasing g-value by 1 unit
	 			h_new = calcHeuristic(i,j+1,destNode);
	 			f_new = g_new + h_new;

	 			// check if the current successor-node is in the open list
	 			// if NOT, then add it to the open list
	 			// set its parent node
	 			// ******** OR *********
	 			// if its already in the open list then:
	 			// check if this current path's cost is better than earlier ones using 'f' as a measure

	 			if(nodeDetails[i][j+1].F == FLT_MAX || nodeDetails[i][j+1].F > f_new){
	 				
	 				// put the current successor-node in the open List
	 				openList.insert(make_pair(f_new, make_pair(i, j+1)));

	 				// update the details of this current successor-node
	 				nodeDetails[i][j+1].F = f_new;
	 				nodeDetails[i][j+1].G = g_new;
	 				nodeDetails[i][j+1].H = h_new;
	 				nodeDetails[i][j+1].parent_i = i;
	 				nodeDetails[i][j+1].parent_j = j;
	 			}
	 		}
	 	} 	


	 	
	 	//--------------------- 4th successor node ---------------------//	

	 	// proceed only if the node is valid
	 	if(isValidNode(i, j-1)){

	 		// check if this node is the destination node
	 		if(isDestination(i, j-1, destNode)){
	 			// setting the parent of the destination node
	 			printf("Destination node is found\n");
	 			nodeDetails[i][j-1].parent_i = i;
	 			nodeDetails[i][j-1].parent_j = j;
	 			tracePath(nodeDetails,destNode);	// tracing the path from srcNode to destNode
	 			flag_isDestinationFound = true;
	 			return;
	 		}
	 		// check if this current successor-node is already in the closedList or Blocked then IGNORE else do the following
	 		else if(closedList[i][j-1]==false && isNodeUnblocked(grid, i, j-1)){
	 			g_new = nodeDetails[i][j].G + 1.0;	// increasing g-value by 1 unit
	 			h_new = calcHeuristic(i,j-1,destNode);
	 			f_new = g_new + h_new;

	 			// check if the current successor-node is in the open list
	 			// if NOT, then add it to the open list
	 			// set its parent node
	 			// ******** OR *********
	 			// if its already in the open list then:
	 			// check if this current path's cost is better than earlier ones using 'f' as a measure

	 			if(nodeDetails[i][j-1].F == FLT_MAX || nodeDetails[i][j-1].F > f_new){
	 				
	 				// put the current successor-node in the open List
	 				openList.insert(make_pair(f_new, make_pair(i, j-1)));

	 				// update the details of this current successor-node
	 				nodeDetails[i][j-1].F = f_new;
	 				nodeDetails[i][j-1].G = g_new;
	 				nodeDetails[i][j-1].H = h_new;
	 				nodeDetails[i][j-1].parent_i = i;
	 				nodeDetails[i][j-1].parent_j = j;
	 			}
	 		}
	 	}

	 	
	 	
	    
	 	
	}

	if(flag_isDestinationFound == false){
		printf("Failed to find the destination node.\n");
	}

	return;
}

int main(){
	// grid description: (0 -->node is BLOCKED) && (1 --> node is NOT blocked)
	int m_grid[ROW][COL] = 
	{
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 1, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        { 0, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 }
    };

    m_pair m_srcNode = make_pair(0,0);
    m_pair m_destNode = make_pair(2,2);
    aStarAlgorithm(m_grid, m_srcNode, m_destNode);
    return(0);

}
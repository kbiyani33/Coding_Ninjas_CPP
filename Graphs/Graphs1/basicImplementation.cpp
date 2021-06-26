/**
 * Following are some of the ways a graph can be implemented.
 * 
 * METHOD 1 => Using Edge list Method
 Easiest way to implement a graph is this. It has an array of vertices and an array of edged.
 In the array of edges, we have a list of pairs. Pairs indicating the 2 vertices. 
 However this is not a good way to implement graphs.
 Eg: Is there a road connecting gurgaon and delhi.
 To ansewr this we have to go through all edges which is worst case O(n^2). 
 
        So not a good method.

 * METHOD 2 => Using Adjacency List Method
This involves having an array containing all the vertices with each vertex containing each of the vertices that the said vertex is DIRECTLY CONNECTED TO.

E.g.:                       A ------ B
                            |
                            |
                            |
                            C ------- D
      A will store [B,C]
      C will store [A,D]
      B will store [A]
      and
      D will store [C]

Now the same query in the road network can be O(n) time.
We can improve the speed further by using unordered map.



* METHOD 3 => Using Adjacency Matrix.
If we have 10 vertices then we will take a 10/10 2D matrix. To see if there's an edge connecting vertex4 wwith vertex5 we will simply get the adjacencyMatrix[4][5]

This is very very fast. But very very expensive w.r.t space.
Adjacency matrix for the same example:
                            F   T   T   F
                            T   F   F   F
                            T   F   F   T
                            F   F   T   F

 */

/**
 * Input: number of vertices.
 *        number of edges.
 * Algorithm:
 * Run a for loop and get the edge information.
 *              V1 and V2 will be obtained (V1 -- V2)
 * Once we get this, we will start filling the adjacency matrix. adjacency[i][j] = adjacency[j][i]
 * 
 */

#include<iostream>
#include<vector>

using namespace std;

void printGraphDFS(int** edges, int n, int startVertex, bool* visited){
    cout << startVertex << endl;
    visited[startVertex] = true;
    for(int i=0; i<n; i++){
        if(i == startVertex)
            continue;
        
        if (edges[startVertex][i] == 1){
            if(visited[i])
                continue;
            printGraphDFS(edges, n, i, visited);
            //visited[i] = true;
        }
    }

}

int main(){
    int n, e;
    cin >> n >> e;
    int** edges = new int*[n];

    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = 0;
        }
    }

    for(int i=0; i<e; i++){
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    printGraphDFS(edges, n, 0, visited);
    for(int i=0; i<n; i++){
        delete[] edges[i];
    }
    delete[] edges;
    return 0;

    // This algorithm is known as DFS.

}
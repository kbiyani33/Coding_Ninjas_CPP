/*
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.

Find the path using DFS and print the first path that you encountered.

Note:
    1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
    2. E is the number of edges present in graph G.
    3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
    4. Save the input graph in Adjacency Matrix.

Input Format :
    The first line of input contains two integers, that denote the value of V and E.
    Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
    The following line contain two integers, that denote the value of v1 and v2.
Output Format :
    Print the path from v1 to v2 in reverse order.

Constraints :
    2 <= V <= 1000
    1 <= E <= (V * (V - 1)) / 2
    0 <= a <= V - 1
    0 <= b <= V - 1
    0 <= v1 <= 2^31 - 1
    0 <= v2 <= 2^31 - 1
    Time Limit: 1 second

Sample Input 1 :
    4 4
    0 1
    0 3
    1 2
    2 3
    1 3
Sample Output 1 :
    3 0 1

Sample Input 2 :
    6 3
    5 3
    0 1
    3 4
    0 3
Sample Output 2 :
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> getPathDFS(int** edges, int n, int start, int end, bool* visited){

    // base case if start == end
    vector<int> output ;
    if(start == end){
        output.push_back(end);
        return output;
    }
    visited[start] = true;
    for(int i=0; i<n; i++){
        if(i == start)
            continue;
        
        else if( edges[start][i] == 1 && !visited[i] ){
            vector<int> op = getPathDFS(edges, n, i, end, visited);
            if(!op.empty()){
                op.push_back(start);
                return op;
            }
        }
    }
    return output;
}

int main(){
    int V, E;
    cin >> V >> E;
    // Making edges array
    int** adjacency = new int*[V];
    for(int i=0; i<V; i++){
        adjacency[i] = new int[V];
        for(int j=0; j<V; j++){
            adjacency[i][j] = 0;
        }
    }

    // Getting edges input
    for(int i=0; i<E; i++){
        int src, tgt;
        cin >> src >> tgt;
        adjacency[src][tgt] = 1;
        adjacency[tgt][src] = 1;
    }

    // Making visited array
    bool* visited = new bool[V];
    for(int i=0; i<V; i++){
        visited[i] = false;
    }

    int start, end; // We need a path in between start and end
    cin >> start >> end;

    vector<int> path = getPathDFS(adjacency, V, start, end, visited);
    for(int i=0; i<path.size(); i++){
        cout << path[i] << " ";
    }
    cout << endl;

    // deleting heap memory
    for(int i=0; i<V; i++){
        delete[] adjacency[i];
    }
    delete[] adjacency;
    delete[] visited;
}

/*
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), check if there exists any path between them or not. Print true if the path exists and false otherwise.

Note:
    1. V is the number of vertices present in graph G  and vertices are numbered from 0 to V-1. 

    2. E is the number of edges present in graph G.

Input Format :
    The first line of input contains two integers, that denote the value of V and E.
    Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
    The following line contain two integers, that denote the value of v1 and v2.

Output Format :
    The first and only line of output contains true, if there is a path between v1 and v2 and false otherwise.

Constraints :
    0 <= V <= 1000
    0 <= E <= 1000
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
    true


Sample Input 2 :
    6 3
    5 3
    0 1
    3 4
    0 3
Sample Output 2 :
    false
*/

#include<iostream>
using namespace std;

void hasPathDFS(int** edges, int n , int start, int end, bool* visited){
    visited[start] = true;
    if(start == end)
        return;
    
    for(int i=0; i<n; i++){
        if(i == start)
            continue;
        
        else if(edges[start][i] == 1 && !visited[i])
            hasPathDFS(edges, n, i, end, visited);
    }
}

int main(){
    int V, E;
    cin >> V >> E;

    int **adjacency = new int*[V];

    for(int i=0; i<V; i++){
        adjacency[i] = new int[V];
        for(int j=0; j<V; j++){
            adjacency[i][j] = 0;
        }
    }

    for(int i=0; i<E; i++){
        int s, f;
        cin >> s >> f;
        adjacency[s][f] = 1;
        adjacency[f][s] = 1;
    }

    bool* visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i] = false;

    int start, end;
    cin >> start >> end;
    hasPathDFS(adjacency, V, start, end, visited);

    cout << boolalpha << visited[end] << endl;

    for(int i=0; i<V; i++)
        delete[] adjacency[i];
    
    delete[] adjacency;
    delete[] visited;
    return 0;
}
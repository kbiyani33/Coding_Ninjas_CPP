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

void DFS(int** edges, int n){
    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    /**
     * We will traverse the visited array and then start the function prontGraphDFS from the non-visited vertex.
     */
    for(int i=0; i<n; i++){
        if(! visited[i])
            printGraphDFS(edges, n, i, visited);
        
        else
            continue;
    }
    delete[] visited;
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
    // bool* visited = new bool[n];
    // for(int i=0; i<n; i++){
    //     visited[i] = false;
    // }
    DFS(edges, n);
    for(int i=0; i<n; i++){
        delete[] edges[i];
    }
    delete[] edges;
    return 0;

    // This algorithm is known as DFS.

}
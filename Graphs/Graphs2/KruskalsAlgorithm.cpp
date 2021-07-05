#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class edges{
    private:
        int vertex1;
        int vertex2;
        int edgeWeight;
    
    public:
        edges(int vertex1, int vertex2, int edgeWeight){
            this -> vertex1 = vertex1;
            this -> vertex2 = vertex2;
            this -> edgeWeight = edgeWeight;
        }

        int get_edgeWeight(){
            return this -> edgeWeight;
        }
        int get_vertex1(){
            return this -> vertex1;
        }
        int get_vertex2(){
            return this -> vertex2;
        }
};

bool comparator(edges &val1, edges &val2){
        return val1.get_edgeWeight() < val2.get_edgeWeight();
    }

int topMostParent(int vertex, int* parent){
    if(parent[vertex] == vertex)
        return vertex;
    
    else
        return topMostParent(parent[vertex], parent);
}

bool cycleDetected(int* parents, edges &edgesObject){
    return topMostParent(edgesObject.get_vertex1(), parents) == topMostParent(edgesObject.get_vertex2(), parents);
}

int main(){
    int n, e;
    cin >> n >> e;
    vector<edges> input;
    vector<edges> output;

    for(int i=0; i<e; i++){
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;
        edges obj(v1, v2, weight);
        input.push_back(obj);
    }

    // Now we will sort this input array of edges w.r.t edgeWeight
    sort(input.begin(), input.end(), &comparator);

    int parent[n];
    for(int i=0; i<n; i++){
        parent[i] = i;
    }
    int count=0, currentInputIndex=0;
    while(count != n-1){

        if(currentInputIndex != e){
            edges currentEdgeObj = input[currentInputIndex];
            currentInputIndex += 1;
            if(!cycleDetected(parent, currentEdgeObj)){
                count += 1;
                output.push_back(currentEdgeObj);
                parent[topMostParent(currentEdgeObj.get_vertex2(), parent)] = topMostParent(currentEdgeObj.get_vertex1(), parent);
            }
            else
                continue;
        }
        else
            break;
    }

    vector<edges>::iterator itMST = output.begin();
    while(itMST != output.end()){
        if(itMST -> get_vertex1() <= itMST -> get_vertex2())
            cout << itMST -> get_vertex1() << " " << itMST -> get_vertex2() << " " << itMST -> get_edgeWeight() << endl;
        else
            cout << itMST -> get_vertex2() << " " << itMST -> get_vertex1() << " " << itMST -> get_edgeWeight() << endl;

        itMST++;
    }
}


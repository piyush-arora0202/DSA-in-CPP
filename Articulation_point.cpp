#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    vector<int> dt, low;
    int time = 0;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int u,int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(int u, int parU, set<int> &cp) {
        dt[u] = low[u] = ++time;
        int children = 0;

        for(int i=0;i<adj[u].size();i++) {
            int v = adj[u][i];

            if(dt[v] == -1) {
                dfs(v,u,cp);
                children++;
                //update low
                low[u] = min(low[u],low[v]);

                if(parU != -1 && low[v] >= dt[u]) {
                    cp.insert(u);
                    //Articulation point => critical
                }
            } else if (v != parU) {
                low[u] = min(low[u],dt[v]);
            }
        }
        if(parU == -1 && children > 1) {
            cp.insert(u);
            //Articulation point=> critical
        }
    }
    int articulationPoints() {
        time = 0;
        dt.resize(V,-1);
        low.resize(V, 0);

        set<int> criticalPoints;
        for(int i=0;i<V;i++) {
            if(dt[i] == -1) {
                dfs(i,-1,criticalPoints);
            }
        }
        return criticalPoints.size();
    }
};
int main() {
    Graph graph(6);

    graph.addEdge(1,0);
    graph.addEdge(1,2);
    graph.addEdge(4,3);
    graph.addEdge(4,5);
    graph.addEdge(4,1);

    cout << graph.articulationPoints() << endl;

    return 0;
}
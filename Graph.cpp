#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int> *l; // int *arr

public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
        // arr = new int [V];
    }

    void addEdge(int u , int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    } 
//     void printAdjList() {
//         for (int i=0;i<V;i++) {
//             cout << i << " : ";
//             for (int neigh : l[i]) {
//                 cout << neigh << " ";
//             }
//             cout << endl;
//         }
//     }
// };
    //////// BFS traveral /////////////////
    // void bfs() { // (V+E)
    //     queue<int> Q;
    //     vector<bool> vis(V,false);

    //     Q.push(0); // src node
    //     vis[0] = true;

    //     while (Q.size() > 0) {
    //         int u = Q.front(); // src to destination // u-v
    //         Q.pop(); //src

    //         cout << u  << " ";

    //         for (int v : l[u]) {
    //             if (!vis[v]) {
    //                 vis[v] = true;
    //                 Q.push(v);
    //             }
    //         }
    //     }
    //     cout << endl;
    // }

///////////////// DFS traversal ////////////
    // void dfshelper(int u , vector<bool> &vis) {
    //     cout << u << " ";
    //     vis[u] = true;

    //     for (int v : l[u]) {
    //         if (!vis[v]) {
    //             dfshelper(v,vis);
    //         }
    //     }
    // } 
    // void dfs() {
    //     int src = 0;
    //     vector<bool> vis(V,false);

    //     dfshelper(src,vis); 
    //     cout << endl;
    // }
/////////// DFS undirected //////////////////
    // bool isCycleUndirDFS(int src , int par ,vector<bool> &vis) {
    //     vis[src] = true;
    //     list<int> neighbors = l[src];
    //     for (int v : neighbors) {
    //         if(!vis[v]) {
    //             if (isCycleUndirDFS(v,src,vis)) {
    //                 return true;
    //             }
    //         } else if (v != par) {
    //             return true;
    //         }
    //     }
    //     return false;

    // }
    // bool isCycle() {
    //     vector<bool> vis(V,false);

    //     for (int i=0;i<V;i++) {
    //         if (!vis[i]) {
    //             if (isCycleUndirDFS(i,-1,vis)) {
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }
/////////// BFS undirected //////////////////

    // bool isCycleUndirBFS(int src,vector<bool> &vis) {
    //     queue<pair<int,int>> q;
    //     q.push({src,-1});
    //     vis[src] = true;
    //     while (q.size() > 0) {
    //         int u = q.front().first;
    //         int paru = q.front().second;
    //         q.pop();

    //         list<int> neighbors = l[u];
    //         for (int v:neighbors) {
    //             if (!vis[v]) {
    //                 q.push({v,u}); // u---------------v
    //                 vis[v] = true;
    //             } else if (v != paru) {
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }

    // bool isCycle() {
    //     vector<bool> vis(V,false);

    //     for (int i=0;i<V;i++) {
    //         if (!vis[i]) {
    //             if (isCycleUndirBFS(i,vis)) {
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }
///////////detect cycle in directed graph ////////////////////////
    bool isCycleDirDFS(int curr,vector<bool> &vis,vector<bool> &recPath) {
        vis[curr] = true;
        recPath[curr] = true;

        for(int v:l[curr]) {
            if(!vis[v]) {
                if(isCycleDirDFS(v,vis,recPath)) {
                    return true;
                }
            } else if (recPath[v]) {
                return true;
            }
        }
        recPath[curr] = false;
        return false;
    }
    bool isCycle() {
        vector<bool> vis(V,false);
        vector<bool> recPath(V,false);

        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                if(isCycleDirDFS(i,vis,recPath)) {
                    return true;
                }
            }
        }
        return false;
    }

};
int main() {
    Graph g(5);

    // g.addEdge(0,1);
    // g.addEdge(1,2);
    // g.addEdge(1,3);
    // g.addEdge(2,3);
    // g.addEdge(2,4);

    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(3,0);

    cout << g.isCycle() << endl;
    // g.bfs();
    // g.dfs();
    return 0;
    // g.printAdjList(); 
} 








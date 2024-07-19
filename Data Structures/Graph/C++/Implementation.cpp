#include <iostream>
#include <vector>
using namespace std;

/*  1) Assuming given a Undirected graph
    2) Assuming from the input we are getting n(the number of nodes)
       and m(the number of edges between them)
    3) m line seperated values depeicting the total number of edges. Containging
        two values which are the two nodes between which the edge exist.
    Note :- For a undirected graph the order of the nodes while depicting an edge doesn't matter since we can assume that the edge is bidirectional
*/

/*  TC -> O(m)
    SC -> O(n*n)
*/
void storeInMatrix() {
    int n, m;
    cin >> n >> m;
    int adj1[n][n] = {0}; /* If it as a 0 based indexing */
    int adj2[n+1][n+1] = {0}; /* If it is a 1 based indexing */
    /*  Marking the intersection of index of nodes in the matrix with 1 
        to depict the presence of edge bidirectionally.
    */
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj2[u][v] = 1;
        adj2[v][u] = 1;
    }
}
/*  TC -> O(m)
    SC -> O(n*n)
*/
void storeWeightedGraphInMatrix() {
    int n, m;
    cin >> n >> m;
    int adj1[n][n] = {0}; /* If it as a 0 based indexing */
    int adj2[n+1][n+1] = {0}; /* If it is a 1 based indexing */
    /*  Marking the intersection of index of nodes in the matrix with the given 
        weight to depict the presence of edge bidirectionally or otherwise it is marked as 0.
    */
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj1[u][v] = w;
        adj2[v][u] = w;
    }
}

/*  We are maintaining a list of all the edges connected to a node by
    storing the connected neighbour nodes with it where the primary index is
    based on the nodes number. It is generally called as "Adjacency Lists"

    TC -> O(m)
    SC -> O(2*m) for undirected we are maintaing the edge for both the nodes
*/
void storeInList() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n]; /* If it as a 0 based indexing */
    vector<int> adj[n+1]; /* If it is a 1 based indexing */
    /*  For undirected graph we are maintaing adjacency list for the two neighbour
        individually to depicts a bidirectional edge.
        For directed graph we are maintaining adjacency list for only one edge 
        then its SC -> O(m)
    */
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}


int main() {
    storeInMatrix();
    storeInList();
    return 0;
}
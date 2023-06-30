#include<iostream>
using namespace std;

//? Input Format 
// In the question, they will mention whether it is a directed or undirected graph. 
// The first line contains two space-separated integers n and m denoting the number of nodes and the number of edges respectively.
// Next m lines contain two integers u and v representing an edge between u and v. In the case of an undirected graph if there is an edge
// between u and v, it means there is an edge between v and u as well. Now the question arises if there is any boundation on the number of edges,
// i.e., the value of m? The answer is NO. If we add more edges, then the value of m will increase.

//Storing in Adjacency matrix takes up n2 locations to store infos about edges
int main(){

    int n, m;
    cin >> n >> m;

    // adjacency matrix for undirected graph
    // time complexity: O(n)

    int adj[n+1][n+1];

    for(int i = 0; i < m; i++){

        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;// this statement will be removed in case of directed graph
        //In case of directed graph, edge between u and v doesnt mean edge between v and u
        //but in case of undirected graph both edges can be confirmed by just one of edge
        #include <iostream>

//Adjacency lists
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    // adjacency list for undirected graph
    // time complexity: O(2E)
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}
    }
    return 0;
}
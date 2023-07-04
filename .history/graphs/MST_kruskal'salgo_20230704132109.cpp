//uses disjoint set

struct Node{
    int wt;
    int u;
    int v;
    Node(int first, int second, int weight){
        
        u = first;
        v = second;
        wt = weight;
    
    }
};

int findPar(int node, vector<int>parent){

    if(node = parent[node])return node;

    return parent[node] = findPar(parent[node]);

}

void unio(int u, int v,vector<int>parent,vector<int>rank){
    
    u = findPar(u,parent);
    v = findPar(v,parent);

    if(rank[u]<rank[v])
        parent[v] = u;
        else if(rank[v]<rank[u])
            parent[u] = v;
        else{
            parent[v] = u;
            rank[u]++;
        }


}

bool comp(node n1, node n2){
    return n1.wt < n2.wt;
}

void kruskal(vector<node>edges, int V){

    sort(edges.begin(), edges.end(), comp);
    vector<int>parent(V);
    for(int i =0 ; i<V;i++){
        parent[i] =i;
    }
    vector<int>rank(V,0);

    int sum = 0;
    vector<pair<int,int>>mst;

    for(auto it:edges){
        if(findPar(it.v, parent)!= findPar(it.u, parent)){
            sum==it.wt;
            mst.push({it.u,it.v});
            unio(u,v,rank,parent);
        }
    }


}


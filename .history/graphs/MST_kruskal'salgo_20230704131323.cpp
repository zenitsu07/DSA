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

int findPar(int u, int v){

    

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

    int cost = 0;
    vector<pair<int,int>>mst;

}


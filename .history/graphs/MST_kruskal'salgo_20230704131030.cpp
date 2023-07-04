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

void kruskal(vector<vector<int>>edges){

    sort(edges.begin(), edges.end(), comp);
    
}


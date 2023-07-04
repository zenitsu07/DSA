int parent[100000];
int rank[100000];

void makeSet(){
    int n = 10;
    for(int i =0; i<=n;i++){
        parent[i] = i;
        rank[i] = 0;

    }
    
}

int findPar(int node){
    if(node== parent[node]) return node;

    return findPar(parent[node]);
}
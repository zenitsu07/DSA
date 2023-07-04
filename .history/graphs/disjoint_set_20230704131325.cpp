#include<iostream>
using namespace std;

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
//use path compression 
//i,e,e store 4 as parent of 7 to have easy saccess
// 7->6->5->4

    //path cmpression
    return parent[node]  = findPar(parent[node]);
    // return findPar(parent[node]);
}

void unio(int u, int v){

    u = findPar(u);
    v= findPar(v);

    if(rank[u]< rank[v])
    parent[u] = v;
    else if(rank[u]>rank[v])
        parent[v] = u;

    else{
        parent[v] = u;
        rank[u]++;
    }
}

int main(){
    makeSet();
    int m;
    cin>>m;
    while(m--){
        int u,v;
        unio(u,v);

    }

    int u = 2,v=3;
    if(findPar(v)!=findPar(u)){
        cout<<"belongs to different componenets"
    }

}
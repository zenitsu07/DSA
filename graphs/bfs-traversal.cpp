#include<iostream>
using namespace std;

void bfs_traversal(int V,vector<vector<int>>adj){

    //a data structure and vis array to store  and vector to store bfs
            
            queue<int>q;
            q.push(0);
            int vis[V+1]={0};
            vis[0]=1;
            vector<int>bfs;
            while(!q.empty()){
                //store front and pop
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for(auto it: adj[node]){
                    
                    if(!vis[it]){
                        //if not visited visit it and then push it to queue 
                        vis[it]=1;
                        q.push_back(it);

                    }
                }
            }
            return bfs;
}

int main(){



}
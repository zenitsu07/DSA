#include<iostream>
using namespace std;

//traverse each connecte nodes using bfs or dfs
void dfs(vector<vector<int>>& C,vector<int>&vis,int i){
        
        //now mark it cisited each connected node
        vis[i] = 1;
        
        for(int j = 0; j<C.size();j++){
            
            //if i is connected to j and jth city is not visited 
            if(C[i][j]==1 && vis[j]==0){
                vis[j] = 1;
                dfs(C,vis,j);//call all its neighbour sand mark them visited
            }
            
        }
    }

int findNumProvinces(vector<vector<int>>& C) {
    
        //Approach convert the given matric to adjaceny list form
        
        int n = C.size();
        vector<int>vis(n,0);
        
        if(n==0) return 0;
        int ans = 0;
        
        for(int i = 0; i<n; i++){
        
            if(!vis[i]){
                //its not visisted yet => mark it visited now so its not visited agai
                ans++;//As now this ith node is visited and it can now be a self group or                         connected group regardless
                dfs(C,vis,i);
            }
            
        }
        return ans;
    }

int main(){
    //? We will create an array of size 11 (n+1) starting with the zeroth index.
    //? Initialize this visited array to zero, indicating that all the nodes are unvisited. 
    //? Then follow the following algorithm. If a node is not visited, then call the traversal algorithm.
    int n = 10, m=8;
    int vis[n+1] = {0};
    //example 
     vector<vector<int>>& C = [[1,1,0],[1,1,0],[0,0,1]]
    // for(int i = 1; i<11;i++){
    //     if(!vis[i]) traversal(i);
    // }
    findNumProvinces(C);
}
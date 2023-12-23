class Solution {
public:
    
    bool isPathCrossing(string path) {
        
        //
        unordered_map<char, pair<int, int>> moves;
        moves['N'] = {0, 1}; // North: increment in y-coordinate
        moves['S'] = {0, -1}; // South: decrement in y-coordinate
        moves['W'] = {-1, 0}; // West: decrement in x-coordinate
        moves['E'] = {1, 0}; // East: increment in x-coordinate
        
        unordered_set<string>visited;
        int x = 0,y=0;
        visited.insert("0,0");
        for(char c:path){
            
            pair<int,int>curr = moves[c];
            
            int dx = curr.first;
            int dy = curr.second;
            x+= dx;
            y += dy;
            
            string hash = to_string(x) + "," + to_string(y);
            if( visited.find(hash) != visited.end())
                return true;
            
            visited.insert(hash);
        }
        
        return false;
        
    }
};
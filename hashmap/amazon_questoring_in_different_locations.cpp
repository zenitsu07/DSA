class solution{

    vector<int>(vector<int> locations,vector<int> movedFrom, vector<int>movedTo){
            unordered_set<int>s;
            int n = locations.size();
            for(int i = 0; i<n;i++){
                s.insert(locations[i]);
            }
            for(int i = 0; i<movedFrom.size();i++){
                s.erase(movedFrom[i]);
                s.insert(movedTo[i]);
            }
            vector<int> ans;
            for(int i =0 ; i<n;i++){
                ans.push_back(i);
            }
            sort(ans.begin(),ans.end());
        return ans;
    }
};
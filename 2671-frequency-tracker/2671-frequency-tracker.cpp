class FrequencyTracker {
public:
    
    unordered_map<int,int>ump;
    //store frequency and set of number whose frequency is same
    unordered_map<int,unordered_set<int>>mps;//set of no. whose freq are same
    
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        
        //find
        if(ump.find(number)!=ump.end()){
            int f = ump[number]; 
            //erase from its previous frequency set and update to set of  new frequency
            mps[f].erase(number);
        }
        
        ump[number]++;
        mps[ump[number]].insert(number);
    }
    
    void deleteOne(int number) {
        
        auto it = ump.find(number);
//         if(ump.count(number)){
//             ump[number]--;
            
//         }
        if(it != ump.end() && ump[number]>0){
            
            //delete from its freq set first
            int f = ump[number];
            mps[f].erase(number);
            
            ump[number]--;
            if(ump[number]){
                //if still has freq>0
                mps[ump[number]].insert(number);//push to oset of freq = ump[number] reduces by 1
            }
            
        }
        cout<<"delete = "<<number<<endl;
        return ;
            
    }
    
    bool hasFrequency(int frequency) {
       return mps[frequency].size()>0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
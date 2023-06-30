class Solution {
public:
    vector<int> twoSum(vector<int>& a, int k) {
        int sum = 0;
        int n = a.size();
        vector<int> v(2);
        map<int,int> m;
        for(int i=0;i<n;i++){
            int dif = k - a[i];
            if(m.find(dif) != m.end()){
                v[0] = i;
                v[1] = m[dif];
            } else {
                m[a[i]] = i;
            } 
        }
        return v;
    }
};
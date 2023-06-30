//With unordered map TC->   114ms
class Solution {
public:
    bool lemonadeChange(vector<int>& b) {
        unordered_map<int,int>mp;
        for(int i = 0; i<b.size();i++){
            mp[b[i]]++;
            
            
            if(b[i]==10){
                if(mp[5]<1) return false;
                else mp[5]--;
            }
            if(b[i]==20){
                if(mp[5]<1 || (mp[10]<1&&mp[5]<3)) return false;
                else if(mp[10]<1 && mp[5]>=3) {
                    mp[5] -=3;
                }
                else {
                    mp[5]--;mp[10]--;
                }
            }
        }
    return true;
    }
//?     Use std::unordered_map when 

//? You need to keep count of some data (Example – strings) and no ordering is required.
//? You need single element access i.e. no traversal.
    
//With ordered map TC->     249 ms
    | map             | unordered_map
---------------------------------------------------------
Ordering        | increasing  order   | no ordering
                | (by default)        |

Implementation  | Self balancing BST  | Hash Table
                | like Red-Black Tree |  

search time     | log(n)              | O(1) -> Average 
                |                     | O(n) -> Worst Case

Insertion time  | log(n) + Rebalance  | Same as search
                      
Deletion time   | log(n) + Rebalance  | Same as search
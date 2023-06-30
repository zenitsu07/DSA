// int rec(vector<vector<int>>&points, int day, int last, vector<vector<int>>&dp){

//     if(day ==0){
//         int mx = 0;
//         for(int i =0;i<3;i++){
//             if(i!=last) mx = max(mx,points[0][i]);
//             dp[0][i] = mx;
//         }
        
//         return mx;
//     }
//     //chekc if for this call dp vector has value entered
    
//     if(dp[day][last]!=-1) return dp[day][last];
//     //for other days
//     //perform pick and non pick for each activity if its not the last activity
//     //i.e. two calls for each non performed activities one of picked and one non picked
//     int mx = 0;

//     for(int i = 0;i < 3;i++){

//         if(i != last){

//             int pick = points[day][i] + rec(points,day-1,i,dp);
//             mx = max(mx,pick);
            
//         }

//     }
//     dp[day][last] = mx;
//     return dp[day][last];
    
// }

// int ninjaTraining(int n, vector<vector<int>> &points){

//     //three choices for each day
//     //choose one out of each day
//     //try all possibke outcomes and return max obtained
//     //since we are passing 3 as last in rev call make dp array of n*4
//     vector<vector<int>>dp(n,vector<int>(4,-1));
//     int ans = rec(points,n-1,3,dp);
//     return ans;

// }

//bottom down tabular
// int ninjaTraining(int n, vector<vector<int>> &points){

    
//      vector<vector<int>>dp(n,vector<int>(4,-1));

// //define dp[0][i] for each i on 0th day first
//     int mx = 0;

//     dp[0][0] = max(points[0][2],points[0][1]);
//     dp[0][1] = max(points[0][0],points[0][2]);
//     dp[0][2] = max(points[0][0],points[0][1]);
//     dp[0][3] = max(points[0][0],max(points[0][1],points[0][2]) );
    
       
//     for(int day = 1; day<n;day++){
        
//         for(int last = 0;last<=3;last++){
            
//             dp[day][last] = 0;
//             int maxi =0;
//             for(int task =0; task<3;task++){
//                 if(task!=last){
//                     int point = points[day][task] + dp[day-1][task];
//                     maxi = max(maxi,point);
//                 }
//             }
//             dp[day][last] = maxi; 

//         }

//     }
//     return dp[n-1][3];

// }

//space optimisation
int ninjaTraining(int n, vector<vector<int>> &points){

    
     vector<int>prev(4);

//define prev[0][i] for each i on 0th day first
    int mx = 0;

    prev[0] = max(points[0][2],points[0][1]);
    prev[1] = max(points[0][0],points[0][2]);
    prev[2] = max(points[0][0],points[0][1]);
    prev[3] = max(points[0][0],max(points[0][1],points[0][2]) );
    
       
    for(int day = 1; day<n;day++){
        
        vector<int>temp(4);
        for(int last = 0;last<=3;last++){
            
            temp[last] = 0;

            for(int task =0; task<3;task++){

                if(task!=last){
                    temp[last]= max(temp[last],points[day][task] + prev[task]);
                }

            }
            
        }
        //now update the dp array
        prev= temp;

    }
    
    return prev[3];

}
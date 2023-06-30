#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<string> gss(string str){

    if(str.size() == 0){

        vector<string> e ;
        e.push_back("");
        cout<<e[0]<<endl;
        return e;//return empty
    
    }
   //store substring of string which is every character excluding first
    char first = str[0];
    string rest = str.substr(1);
    // cout<<rest;
    vector<string> result = gss(rest);//calling by passing "bc" only
    //new vector with all results
    vector<string> myresult;
    //using loop or recursive

    for(int i =0 ; i < result.size(); i++){

        myresult.push_back(""+ result[i]);

    }

    for(int i =0 ; i<result.size(); i++){

        myresult.push_back(first + result[i]);

    }
    return myresult;
}
//result of (bc) -> ---, --c, -bc, -b-
int main(){

    string s;
    cin >> s;
    vector <string> ans = gss(s);
    int cnt = 0;

    cout << "[";
    for (string str : ans){

        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
        
    }
    cout << "]";
}
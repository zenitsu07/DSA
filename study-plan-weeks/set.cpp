#include<iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    set <int,greater<int>> s;
s.insert(223);
s.insert(34);
set<int,greater<int>>::iterator itr;

for ( itr = s.begin(); itr != s.end(); itr++)
{
    cout<< *itr<<" ";
}
}
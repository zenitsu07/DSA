#include<iostream>
using namespace std;
//Use Debug Console to watch the control flow of recursion in both fun1 and fun2
void fun1(int n)
{
    //functin showng return order of recursion process 
    if(n>0){
        fun1(n-1);
        //at returning time-descending
        cout<<n;
    }
    else{
        cout<<"return control-";
    }

}
void fun2(int n)
{
    //functin showng return order of recursion process 
    if(n>0){
        
        //execution of print on calling time-Ascending
        cout<<n;
        fun2(n-1);
        
    }
   

}
//when recursive condtion is not met control returns to last recursion call 
//then execute left statements 
//?in recursion two pahses-
//1- function calling ascending order
//2- returning back to first call of functin - descending order
int main(){
    int x = 4; 
    fun1(x);
    cout<<endl;
    fun2(x);
    cout<<endl;
}

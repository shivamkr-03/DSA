#include<bits/stdc++.h>
using namespace std;


bool operand(char c){
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}


string prefix_to_infix(string& s){
    stack<string> stk;
    string infix = "";
    int n = s.length();

    for(int i = n - 1; i >= 0; -- i){
        if(operand(s[i])){
            stk.push(infix + s[i]);
        }
        else{
            string op1 = stk.top();
            stk.pop();
            string op2 = stk.top();
            stk.pop();
            stk.push(op1 + s[i] + op2);
        }
    }

    infix = stk.top();
    
    return infix;
}

int main(){

    string prefix = "-+*ab*cde";
    string infix = prefix_to_infix(prefix);
    
    printf("prefix: %s \n", prefix.c_str());
    
    printf("infix: %s \n", infix.c_str());
    return 0;
}
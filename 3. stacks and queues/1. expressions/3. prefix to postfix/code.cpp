#include<bits/stdc++.h>
using namespace std;


bool operand(char c){
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}


string prefix_to_postfix(string& s){
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
            stk.push(op1 + op2 + s[i]);
        }
    }

    infix = stk.top();
    
    return infix;
}

int main(){

    string prefix = "-+*ab*cde";
    string postfix = prefix_to_postfix(prefix);
    
    printf("prefix: %s \n", prefix.c_str());
    
    printf("postfix: %s \n", postfix.c_str());
    return 0;
}
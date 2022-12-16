#include<bits/stdc++.h>
using namespace std;


bool operand(char c){
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}


string postfix_to_infix(string& s){
    stack<string> stk;
    string infix = "";
    for(char i: s){
        if(operand(i)){
            stk.push(infix + i);
        }
        else{
            string op2 = stk.top();
            stk.pop();
            string op1 = stk.top();
            stk.pop();
            stk.push(op1 + i + op2);
        }
    }

    infix = stk.top();
    
    return infix;
}

int main(){

    string postfix = "ab*cd*+e-";
    string infix = postfix_to_infix(postfix);
    
    printf("postfix: %s \n", postfix.c_str());
    
    printf("infix: %s \n", infix.c_str());
    return 0;
}
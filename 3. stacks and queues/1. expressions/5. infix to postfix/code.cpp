#include<bits/stdc++.h>
using namespace std;


bool operand(char c){
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
int priority(char c){
    if(c == '^')             return 3;
    if(c == '*' or c == '/') return 2;
    if(c == '+' or c == '-') return 1;
    return -1;


}

string infix_to_postfix(string& s){
    stack<char> stk;
    string postfix = "";
    
    for(char c: s){
        // if the character is an operand add if directly to the postfix
        if(operand(c)){
            postfix += c;
        }
        // if there is a opening bracket '(' push it to the stack;
        else if(c == '('){
            stk.push(c);
        }
        // if there is a closing bracket ')' remove all elements from the stack and
        // add it to the postfix expression until stack has '(' and also pop the bracket 
        else if( c == ')'){
            while(stk.top() != '('){
                
                postfix += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        // if we encounter a operator
        else{
            while(!stk.empty() and priority(c) < priority(stk.top())){

                postfix += stk.top();
                stk.pop();
            }
            stk.push(c);
        }
    }
    while(!stk.empty()){
        postfix += stk.top();
        stk.pop();
    }
    return postfix;
}

int main(){

    string infix = "a+b*(c+d)*(p^q)";
    string postfix = infix_to_postfix(infix);
    
    printf("prefix: %s \n", infix.c_str());
    
    printf("infix: %s \n", postfix.c_str());
    return 0;
}
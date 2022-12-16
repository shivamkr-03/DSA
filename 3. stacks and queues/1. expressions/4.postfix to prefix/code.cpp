#include<bits/stdc++.h>
using namespace std;


bool operand(char c){
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}


string postfix_to_prefix(string& s){
    
    stack<string> stk;
    string prefix = "";
    int n = s.length();

    for(int i = 0; i < n; ++ i){

        if(operand(s[i])){
            stk.push(prefix + s[i]);
        }
        else{
            string op2 = stk.top();
            stk.pop();
            string op1 = stk.top();
            stk.pop();
            stk.push(s[i] + op1 + op2);
        }
    }

        

    return stk.top();
}

int main(){

    string postfix = "ab*cd*+e-";
    string prefix = postfix_to_prefix(postfix);
    
    printf("postfix: %s \n", postfix.c_str());
    
    printf("prefix: %s \n", prefix.c_str());
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {12, 6, 2, 13, 7, 9};
    stack<int> stk;
    vector<int> ans(arr.size());

    for(int i = arr.size() - 1; i >= 0; -- i){
        if(stk.empty()){
            ans[i] = -1;
        }
        else if( stk.top() > arr[i]){
            ans[i] = stk.top();
        }
        else{
            while(!stk.empty() and stk.top() < arr[i]){
                stk.pop();
            }
            if(stk.empty()){
                ans[i] = -1;
            }
            else {
                ans[i] = stk.top();
                
            }
        }
        stk.push(arr[i]);

    }

    for(int i = 0; i < arr.size(); ++ i){
        cout << arr[i] <<" ";
    }
    cout << endl;
    for(int i = 0; i < arr.size(); ++ i){
        cout << ans[i] <<" ";
    }
    return 0;
}
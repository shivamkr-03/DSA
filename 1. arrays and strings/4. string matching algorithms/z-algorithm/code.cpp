#include <bits/stdc++.h>
using namespace std;
void solve();
void init(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

vector<int> z_array(string& s) {
    int n = s.size();
    vector<int> z(n);

    int l = 0, r = 0;

    for(int i = 1; i < n; ++ i){
        // kickstart if 'i' is in range of 'r'
        if(i <=r){
            z[i] = min(z[i-l], r - i + 1);
        }
        // naive calculation until 'i + z[i]' is not out of bounds
        while( i+z[i] < n and s[i + z[i]] == s[z[i]]){
            ++ z[i];
        }
        // update the range (l, r) if 'i' surpassed 'r'
        if(r < i) {
            r = i + z[i] - 1;
            l = i;
        }
    }
    return z;
}

vector<int> z_algorithm(string& txt, string& pat) {

    // combine pattern with text seperated by a special character ('$').
    string s = pat + '$' + txt;
    int n = s. size();
    // calculate z array for the combined string 
    return z_array(s);
}

int main(int argc, char const *argv[])
{	
    init();
	string txt = "hello world";
	string pat = "l";
	vector<int> ans = z_algorithm(txt, pat);

    // if the z value of the index is equal to the length of the pattern then we found the pattern
	for(int i : ans){
		if(i == pat.length()){
            cout << "found" << " ";
        }
	}
	return 0;
}


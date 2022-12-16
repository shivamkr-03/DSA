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

vector<int> rabin_karp(string const& pat, string const& txt) {
    const int p = 31; 
    const int m = 1e9 + 9;
    int pat_len = pat.size(), txt_len = txt.size();


    // declare a vector to store powers of p and calculate powers of p
    vector<long long> p_pow(max(pat_len, txt_len)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;


    // calculate prefix hashes of given text
    vector<long long> prefix(txt_len + 1, 0); 
    for (int i = 0; i < txt_len; i++)
        prefix[i+1] = (prefix[i] + (txt[i] - 'a' + 1) * p_pow[i]) % m; 


    // calculate the hash value of the pattern
    long long pat_hash = 0; 
    for (int i = 0; i < pat_len; i++) 
        pat_hash = (pat_hash + (pat[i] - 'a' + 1) * p_pow[i]) % m;


    // check for the occurances of the pattern
    vector<int> occurences;
    for (int i = 0; i + pat_len - 1 < txt_len; i++) { 
        long long cur_h = (prefix[i + pat_len] + m - prefix[i]) % m; 
        if (cur_h == pat_hash * p_pow[i] % m)
            occurences.push_back(i);
    }

    return occurences;
}

int main(int argc, char const *argv[])
{	init();
	string txt = "hello world";
	string pat = "l";
	vector<int> ans = rabin_karp(pat, txt);

	for(int i : ans){
		cout << i <<" ";
	}
	return 0;
}


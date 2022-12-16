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

vector<int> manchers(string& txt){

	// add makeup to the string
	string s = "@";

	for(char i: txt){
		s += '#';
		s += i ;
	}

	s+= "#$";
	
	// initilize variables that are required
	// lps array means longest palindromic substring ;
	
	int l = 0, r = 0;
	int n = s.length();
	vector<int> lps(n);
	// calculate lps
	for(int i = 2; i < n - 1; ++ i){

		// kickstart lps if i is in between known range r
		if(i < r){
			lps[i] = min(lps[l - (i - l)], r - i);
		}

		// look for mirrored characters to compare placing mirror at i and increment lps[i]

		while(s[i + (lps[i] + 1)] == s[i - (lps[i] + 1)]){
			++ lps[i];
		}

		// update known range as lps values updates;

		if(i + lps[i] > r){
			l = i;
			r = i + lps[i];
		}

	}
	// return lps array


	return lps;
}



int main(int argc, char const *argv[]){

	init();
	string txt = "PQPQPQP";
	vector<int> ans = manchers(txt);

	for(int i: ans){
		cout << i << " ";
	}
}


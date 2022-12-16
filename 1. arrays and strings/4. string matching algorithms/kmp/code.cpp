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

vector<int> calculate_lps(string& s){

	int n = s.length();

	int len = 0, i = 1;

	vector<int> lps(n);

	while(i < n){

		// if the prefix of length (len+1) matches with the suffix
		// plate len + 1 to lps[i] and increment len and i
		if(s[len] == s[i]){
			lps[i] = len + 1;
			 ++ i;
			 ++ len;
		}

		// if character doesnt matched and no prefix there to compare (len  == 0) then
		//  there is no prefix so lps[i] = 0 and we move to next character

		else if(len == 0){
			lps[i] = 0;
			++ i;
		}
		// if s[i] != s[len] and we are comparing for prefix of length > 1( => len != 0)
		// then move len to lps[len - 1]
		else{
			len = lps[len - 1];
		}
	}
	return lps;
}



int main(int argc, char const *argv[])
{	init();
	string pat = "onions";
	string txt = "onionionsonions";

	int pat_len = pat.length();
	int txt_len = txt.length();
	
	// kmp implementation

	// step1: calculate lps array of the pattern;
	vector<int> lps = calculate_lps(pat);

	cout << "lps array:\n";

	for(int i: lps){
		cout << i << " ";
	}
	cout << "\n\n";

	int i = 0, j = 0;

	while(i < txt_len){

		if(txt[i] == pat[j]){
			++i;
			++j;
		}
		else if(j == 0){
			++i;
		}
		else {
			j = lps[j - 1];
		}
		if(j == pat_len){
			cout << i - j << " ";
			j = lps[j - 1];
		}
	}
}


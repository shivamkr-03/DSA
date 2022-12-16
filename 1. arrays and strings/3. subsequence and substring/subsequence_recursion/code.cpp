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
int main() {
	init();
	
	string s = "ABC";
	int n = s.size();
	int range = 1 << n;
	

	for(int i = 1; i < range; ++i){
		for(int j = 0; j < n; ++ j){
			if((i & (1 << j)) != 0){
				cout << s[j] << " ";
			}
		}
		cout << endl;
	}

	return 0;

}

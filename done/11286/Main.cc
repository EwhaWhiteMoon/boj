#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;

	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		int n;
		cin >> n;
		if(n == 0){
			if(Q.empty()) cout << 0 << '\n';
			else{
				cout << Q.top().second << '\n';
				Q.pop();
			}
		}
		else Q.push(make_pair(abs(n), n));
	}
}

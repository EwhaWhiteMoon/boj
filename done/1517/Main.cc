#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void mSort(vector<int>& V, int l, int r, long long int& cnt){
	if(r - l == 1) return;
	int m = (l + r) / 2;
	mSort(V, l, m, cnt);
	mSort(V, m, r, cnt);

	vector<int> M;

	int a = l, b = m;
	while(a < m && b < r){
		if(V[a] <= V[b]){
			M.push_back(V[a++]);
			if(V[a] != V[b]) cnt += (b - m);
		}else M.push_back(V[b++]);
	}
	while(a < m){
		M.push_back(V[a++]);
		cnt += (b - m);
	}
	while(b < r) M.push_back(V[b++]);

	for(int i = l; i < r; i++){
		V[i] = M[i - l];
	}
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> A(N);

	for(int i = 0; i < N; i++){
		int an;
		cin >> an;

		A[i] = an;
	}
	long long int cnt = 0;
	mSort(A, 0, N, cnt);

	cout << cnt << '\n';
}


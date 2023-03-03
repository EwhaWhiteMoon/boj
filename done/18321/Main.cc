//start 7/08 5:20 PM

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct UnionFind{
	vector<int> F;
	vector<int> D;

	UnionFind(int N) : F(N), D(N){
		for(int i = 0; i < N; i ++){
			F[i] = i;
			D[i] = 0;
		}
	}

	void Union(int a, int b){
		int fa = Find(a);
		int fb = Find(b);
		if(fa == fb) return;
		if(D[fa] < D[fb]) swap(fa, fb);
		F[fa] = fb;
		if(D[fa] == D[fb]){
			D[fb] ++;
		}
	}

	int Find(int n){
		if(F[n] == n) return n;
		return F[n] = Find(F[n]);
	}
};

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	vector<int> cow(N);
	bool sorted = true;
	for(int i = 0; i < N; i++){
		cin >> cow[i];
		cow[i] --;
		if(cow[i] != i){
			sorted = false;
		}
	}
	if(sorted){
		cout << -1;
		return 0;
	}

	vector<vector<int>> input(M, vector<int>(3));
	for(int i = 0; i < M; i++){
		cin >> input[i][0] >> input[i][1] >> input[i][2];
		input[i][0] --;
		input[i][1] --;
	}
	sort(input.begin(), input.end(), 
			[](vector<int> a, vector<int> b){
				return a[2] > b[2]; 
			});

	int low = 0, high = M - 1, result = 0x3F3F3F3F;
	while(low <= high){
		int mid = (low + high) / 2;
		
		bool isCanSort = true;
		UnionFind uf(N);
		for(int i = 0; i <= mid; i++){
			uf.Union(input[i][0], input[i][1]);
		}
		
		for(int i = 0; i < N; i++){
			if(uf.Find(i) != uf.Find(cow[i])){
				isCanSort = false;
				break;
			}
		}
		if(isCanSort){
			if(result > mid) result = mid;
			high = mid - 1;
		}else{
			low = mid + 1;
		}
	}
	if(result == -1){
		cout << -1;
		return 0;
	}
	cout << input[result][2];
}

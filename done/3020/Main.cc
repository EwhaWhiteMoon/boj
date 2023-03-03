//2022년 8월  3일 수요일 22시 11분 32초 KST

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

void solve(vector<int> L, vector<int> H, int h){
	int N = L.size();
	
	int min = INT_MAX;
	int cnt = 0;
	for(int i = 1; i <= h; i++){
		int t = 
			(N - (lower_bound(L.begin(), L.end(), i) - L.begin())) +
			(N - (lower_bound(H.begin(), H.end(), h - i + 1) - H.begin()));

		if(min > t){
			min = t;
			cnt = 1;
		}else if(min == t){
			cnt ++;
		}
	}

	cout << min << ' ' << cnt << '\n';
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, H;
	cin >> N >> H;

	N /= 2;

	vector<int> LOW(N);
	vector<int> HIGH(N);

	for(int i = 0; i < N; i++){
		int l, h;
		cin >> l >> h;
		LOW[i] = l;
		HIGH[i] = h;
	}

	sort(LOW.begin(), LOW.end());
	sort(HIGH.begin(), HIGH.end());

	solve(LOW, HIGH, H);
}

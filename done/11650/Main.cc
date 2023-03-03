#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<pair<int, int>> points;
	for(int i = 0; i < N; i++){
		int x, y;
		cin >> x >> y;
		points.push_back(make_pair(x, y));
	}
	sort(points.begin(), points.end());

	for(pair<int, int> i : points){
		cout << i.first << ' ' << i.second << '\n';
	}
}

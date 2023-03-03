#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct lessHeap{
	vector<int> heap;
	int len;

	lessHeap(){
		len = 0;
		heap.push_back(0);
	}

	void push(int v){
		heap.push_back(v);
		len ++;

		for(int p = len; p != 1 && heap[p] < heap[p/2]; p /= 2)
			swap(heap[p], heap[p/2]);

/*		cout << '!';
		for(int i = 1; i <= len; i++){
			cout << heap[i] << ' ';
		}
		cout << '\n';
*/	}

	int pop(){
		if(len == 0) return 0;
		int result = heap[1];
		heap[1] = heap[len];
		heap.pop_back();
		len --;

		int p = 1;
		while(true){
			int minP = p;
			if(p * 2 <= len && heap[minP] > heap[p * 2]) minP = p * 2;
			if(p * 2 + 1 <= len && heap[minP] > heap[p * 2 + 1]) minP = p * 2 + 1;
			if(minP == p) break;
			swap(heap[minP], heap[p]);
			p = minP;
		}
/*		cout << '!';
		for(int i = 1; i <= len; i++){
			cout << heap[i] << ' ';
		}
		cout << '\n';
*/		return result;
	}
};

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	lessHeap lh;
	for(int i = 0; i < N; i++){
		int n;
		cin >> n;
		if(n == 0) cout << lh.pop() << '\n';
		else lh.push(n);
	}
}

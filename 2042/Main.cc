#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct SegTree{
    int N;
    vector<long long int> V;

    void update(int i, long long int n){
        //O(logN)
        i += N;
        V[i] = n;

        i /= 2;
        while(i >= 1){
            V[i] = V[i * 2] + V[i * 2 + 1];
            i /= 2;
        }
    }

    SegTree(vector<long long int> v){
        int n = v.size();
        N = 2;
        while(N <= n){
            N *= 2;
        };

        V.resize((N * 2 + 1), 0);

        for(int i = 0; i < n; i++){
            V[N + i] = v[i];
        }

        for(int i = (N * 2); i > 1; i --){
            if(i % 2 == 1) V[i / 2] = 0;
            V[i / 2] += V[i];
        }
    }
    //[l, r]
    long long int sum(int l, int r){
        long long int ans = 0;
        l += N;
        r += N;

        while(l <= r){
            if(l % 2 == 1){
                ans += V[l];
                l += 1;
            }
            if(r % 2 == 0){
                ans += V[r];
                r -= 1;
            }
                l /= 2;
                r /= 2;
        }
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long int N, M, K;
    cin >> N >> M >> K;
    vector<long long int> V;

    for(int i = 0; i < N; i++){
        long long int n;
        cin >> n;
        V.push_back(n);
    }

    SegTree S(V);

    long long int a, b, c;
    for(int i = 0; i < (M + K); i++){
        cin >> a >> b >> c;

        if(a == 1) S.update(b - 1, c);
        else cout << S.sum(b - 1, c - 1) << '\n';
    }

    return 0;
}

#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    while(cin>>n)
    {
        priority_queue<ll, vector<ll>, greater<ll> > pq;
        while (n--) {
            cin >> m;
            pq.push(m);
        }
        ll ans = 0;
        while (pq.size() >= 2) {
            ll a = pq.top(); pq.pop();
            ll b = pq.top(); pq.pop();
            ans += a + b;
            pq.push(a + b);
        }
        cout << ans << endl;
    }

    return 0;
}
/**************************************************************
    Problem: 1784
    User: xiaohuihui
    Language: C++
    Result: Accepted
    Time:76 ms
    Memory:1700 kb
****************************************************************/

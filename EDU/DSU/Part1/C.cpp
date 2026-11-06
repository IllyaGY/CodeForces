#include <iostream>
using namespace std;

typedef long long ll;

const int N = 2e5 + 1;


ll arr[N] = {0};
ll sz[N] = {0};
ll xp[N] = {0};


void init()
{
    for (ll i = 1; i < N; ++i)
    {
        arr[i] = i;
        sz[i] = 1;
    }
}


ll get(ll a)
{
    if (a == arr[a]) return a;

    ll global_lead = get(arr[a]);

    if (arr[a] != global_lead)
    {
        xp[a] += xp[arr[a]];
    }
    arr[a] = global_lead;

    return arr[a];
}

void add(ll a, ll val)
{
    ll leader = get(a);
    xp[leader] += val;
}



void u(ll c1, ll c2){
    ll l1 = get(c1);
    ll l2 = get(c2);

    if (l1 == l2) return;

    if (sz[l2] > sz[l1])
    {
        swap(l1, l2);
    }
    arr[l2] = l1;
    sz[l1] += sz[l2];
    xp[l2] -= xp[l1];
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    init();

    while (m--) {
        string st;
        int l, r;
        cin >> st >> l;
        if (st == "get")
        {
            ll leader = get(l);
            cout << xp[l] + (l == leader ? 0 : xp[leader]) << '\n';
        }
        else if (st == "join")
        {
            cin >> r;
            u(l, r);
        }
        else
        {
            cin >> r;
            add(l, r);
        }
    }

    return 0;
}
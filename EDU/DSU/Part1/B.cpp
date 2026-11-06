    #include <iostream>
    using namespace std;

    typedef long long ll;

    const int N = 3e5 + 1;

    struct node
    {
        ll elements;
        ll min;
        ll max;
    };

    ll arr[N] = {0};
    node s[N] = {0};


    void init()
    {
        for (ll i = 1; i < N; ++i)
        {
            arr[i] = i;
            s[i].elements = 1;
            s[i].min = i;
            s[i].max = i;
        }
    }


    ll get(ll a)
    {
        if (a == arr[a]) return a;

        arr[a] = get(arr[a]);

        return arr[a];
    }




    void u(ll c1, ll c2){
        ll l1 = get(c1);
        ll l2 = get(c2);

        if (l1 == l2) return;

        s[l1] = node{
            s[l2].elements + s[l1].elements,
            min(s[l2].min, s[l1].min),
            max(s[l2].max, s[l1].max),

        };

        arr[l2] = l1;
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
                node set = s[get(l)];
                cout << set.min << " " << set.max << " " << set.elements <<  endl;
            }
            else
            {
                cin >> r;
                u(l, r);
            }
        }

        return 0;
    }
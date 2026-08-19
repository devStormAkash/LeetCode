#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i,n) for(i=0;i<n;i++)
#define F first
#define S second
#define psb push_back
#define ppb pop_back
#define all(x) x.begin(), x.end()
#define Y cout << "YES\n";
#define N cout << "NO\n";

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<bool> vb;

const ll mod = 1000000007;

vector<ll> fact, invfact;

// ---------------- Modular Arithmetic ----------------

ll add(ll a, ll b){
    return (a % mod + b % mod) % mod;
}

ll sub(ll a, ll b){
    return (a % mod - b % mod + mod) % mod;
}

ll mul(ll a, ll b){
    return (a % mod) * (b % mod) % mod;
}

ll modPow(ll a, ll b){
    a %= mod;
    ll ans = 1;
    while(b){
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

ll modInv(ll a){
    return modPow(a, mod - 2);
}

ll divide(ll a, ll b){
    return mul(a, modInv(b));
}

void init(int n){
    fact.assign(n+1,1);
    invfact.assign(n+1,1);

    for(int i=1;i<=n;i++)
        fact[i]=fact[i-1]*i%mod;

    invfact[n]=modInv(fact[n]);

    for(int i=n-1;i>=0;i--)
        invfact[i]=invfact[i+1]*(i+1)%mod;
}

ll nCr(int n,int r){
    if(r<0||r>n) return 0;
    return fact[n]*invfact[r]%mod*invfact[n-r]%mod;
}

ll nPr(int n,int r){
    if(r<0||r>n) return 0;
    return fact[n]*invfact[n-r]%mod;
}

// ---------------- Input / Output ----------------

void inputarr(vector<ll>& a,ll n){
    for(int i=0;i<n;i++) cin>>a[i];
}

void outputarr(vector<ll>& a){
    for(ll x:a) cout<<x<<" ";
    cout<<"\n";
}

// ---------------- Segment Tree (Range Sum + Point Update) ----------------

class SegmentTree{
public:
    int n;
    vector<ll> tree;

    SegmentTree(int sz){
        n=sz;
        tree.assign(4*n+5,0);
    }

    void build(int node,int start,int end,vector<ll>& arr){
        if(start==end){
            tree[node]=arr[start];
            return;
        }

        int mid=(start+end)/2;
        build(2*node,start,mid,arr);
        build(2*node+1,mid+1,end,arr);

        tree[node]=tree[2*node]+tree[2*node+1];
    }

    ll query(int node,int start,int end,int l,int r){
        if(r<start||end<l)
            return 0;

        if(l<=start&&end<=r)
            return tree[node];

        int mid=(start+end)/2;

        return query(2*node,start,mid,l,r)+
               query(2*node+1,mid+1,end,l,r);
    }

    void update(int node,int start,int end,int idx,ll val){
        if(start==end){
            tree[node]=val;
            return;
        }

        int mid=(start+end)/2;

        if(idx<=mid)
            update(2*node,start,mid,idx,val);
        else
            update(2*node+1,mid+1,end,idx,val);

        tree[node]=tree[2*node]+tree[2*node+1];
    }

    void build(vector<ll>& arr){
        build(1,0,n-1,arr);
    }

    ll query(int l,int r){
        return query(1,0,n-1,l,r);
    }

    void update(int idx,ll val){
        update(1,0,n-1,idx,val);
    }
};



void solve(){
    ll n;
    cin >> n;
    if(n>=4&&(n)%2==0){
      Y
    }else{
      N
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
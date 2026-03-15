#include <bits/stdc++.h>
#ifdef LOCAL
    #include "../debug.hpp"
#else
    #define debug(...) 42
#endif

using namespace std;

template <class T>
void input(vector<T>& arr){
    for (int i = 0; i < arr.size(); i ++) cin >> arr[i];
}

#define int long long

const int inf = 1e9 + 8;
const int maxn = 1e6 + 5;
const string NAME = "";

#define with_testcases
void t_main(signed __T){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    input(a);

    vector<int> ptr(abs(k)+1);

    sort(a.begin(), a.end());

    set<int> st;
    int ans=0;
    if(k>0)
    {
        for(int i=n-1;i>=0;i--) ptr[a[i]%k]=a[i];
        for(int i=0; i<n; i++)
        {
            int j=ptr[a[i]%k];
            j=max(j, a[i]);
            while (st.count(j)) j+=k;
            ans+=abs(j-a[i])/k;
            st.insert(j);
            ptr[a[i]%k]=j;
        }
    }else{
        k=abs(k);
        for(int i:a)
            ptr[i%k]=i;
        for(int i=n-1;i>=0;i--)
        {
            int j=ptr[a[i]%k];
            j=min(j,a[i]);
            while (st.count(j)) j-=k;
            ans+=abs(j-a[i])/k;
            st.insert(j);
            ptr[a[i]%k]=j;
        }
    }

    cout<<ans;
}

void init_io(){
    cin.tie(nullptr) -> sync_with_stdio(false);
    if(!NAME.empty())
    {
        (void)!freopen((NAME + ".in").c_str(), "r", stdin);
		(void)!freopen((NAME + ".out").c_str(), "w", stdout);
    }
}

signed main(){
    int t = 1;
    #ifdef with_testcases
        cin >> t;
    #endif
    for (int i = 1; i <= t; i ++) {
        t_main(i);
        cout << '\n';
    }
}

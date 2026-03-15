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

const int mod = 1e9 + 7;

const string NAME = "";

#define with_testcases
void t_main(signed __T){
    string s;
    cin>>s;
    int n=s.size();
    int cur=1;
    bool f=true;
    for(auto i : s)
        if (i>'1') f=false;

    if(!f)
        for (auto &i : s)
            i=((i-'0')&1)+'0';
    
    int ans=!f;

    reverse(s.begin(), s.end());
    if(s[0]=='1') ans++;
    
    debug(s, ans);

    for(int i=1;i<n;i++,cur=cur*2%mod)
    {
        if (s[i]=='0') continue;
        ans = (ans + cur*3)%mod;
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

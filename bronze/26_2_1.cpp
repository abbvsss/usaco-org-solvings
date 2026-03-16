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

const int inf = 1e9 + 8;
const int maxn = 1e6 + 5;
const string NAME = "";

int K;

#define with_testcases
void t_main(signed __T){
    int n; string s;
    cin>>n>>s;
    for(auto&i:s)if(i=='M')i='0';else i='1';
    cout<<"YES";
    int cnt=0;
    for(int i=n-1;i>=0;i--)
    {
        int c=(s[i]-'0'+cnt)%2;
        cnt+=c;
        if(c)s[i]='O';
        else s[i]='M';
    }
    if(K)
    cout<<endl<<s;
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
    cin >> K;
    for (int i = 1; i <= t; i ++) {
        t_main(i);
        cout << '\n';
    }
}

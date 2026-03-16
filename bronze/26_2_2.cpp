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

// #define with_testcases
void t_main(signed __T){
    int n, k;
    cin>>n>>k;
    vector cnt(n, vector(n, vector<int>(n)));
    while(k--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(b>c) swap(b,c);
        cnt[--a][--b][--c]++;
    }
    int mx=-1, c=0;
    for(int mask=0;mask<(1<<n); mask++)
    {
        int cur=0;
        vector<int> ms, os;
        for(int i=0;i<n;i++)
            if(mask&(1<<i)) ms.push_back(i);
            else os.push_back(i);

        for(int m: ms)
        {
            for(int i=0;i<os.size();i++)
                for(int j=i+1;j<os.size();j++)
                    cur+=cnt[m][os[i]][os[j]];
        }
        if(cur>mx){mx=cur;c=1;}
        else if(cur==mx)c++;
    }

    cout<<mx<<' '<<c;
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

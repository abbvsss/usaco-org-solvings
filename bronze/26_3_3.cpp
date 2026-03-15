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

#define with_testcases
void t_main(signed __T){
    int n, m;
    cin>>n>>m;
    string t;
    cin>>t;
    vector<string> grid(n);
    input(grid);
    vector cnt(m, vector<int>(26));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cnt[i][grid[j][i]-'a']++;
        }
    }

    vector<vector<int>> ans;
    
    for(int i=0;i<m;i++)
    {
        if (cnt[i][t[i]-'a']) {
            for(int j=0;j<n;j++)
            {
                if(grid[j][i]==t[i])
                {
                    if(j!=0)
                    ans.push_back({2, 1, j+1, i+1});
                    swap(grid[j][i], grid[0][i]);
                    break;
                }
            }
            continue;
        }
        for(int j=0;j<m;j++)
        {
            if(cnt[j][t[i]-'a']<=(t[i]==t[j])) continue;
            debug(i,j);
            for(int k=n-1;k>=0;k--)
            {
                if(grid[k][j]!=t[i]) continue;
                debug(k);
                cnt[i][grid[k][i]-'a']--;
                cnt[j][grid[k][j]-'a']--;
                swap(grid[k][j],grid[k][i]);
                cnt[i][grid[k][i]-'a']++;
                cnt[j][grid[k][j]-'a']++;
                ans.push_back({1, k+1, i+1, j+1});
                break;
            }
            i--;
            break;
        }
    }

    cout<<ans.size()<<'\n';
    for(auto &i : ans) 
    {
        cout<<i[0];
        for(int j=1;j<4;j++)
        {
            cout<<' '<<i[j];
        }
        cout<<'\n';
    }
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
        // cout << '\n';
    }
}

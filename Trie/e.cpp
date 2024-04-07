#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
// Integer Ranges
#define imax INT_MAX
#define imin INT_MIN
#define llmax LLONG_MAX
#define llmin LLONG_MIN
#define mod (int)(1e9 + 7)
#define ll long long
#define int ll

// Data Structures
#define v(a) vector<a>
#define p(a, b) pair<a, b>
#define vv(a) vector<vector<a>>
#define ump(a, b) unordered_map<a, b>
#define omp(a, b) map<a, b>
#define ust(a) unordered_set<a>
#define ost(a) set<a>
#define maxheap(a) priority_queue<a>
#define minheap(a) priority_queue<a, vector<a>, greater<a>>

// Sorting Functions
#define Sort(a) sort(a.begin(),a.end())
#define DSort(a) sort(a.begin(),a.end(),greater<a>())

// Debugging
#define debug(i) cout << "debug : " << i << endl;
#define input(arr) for(int i=0;i<arr.size();i++) cin>>arr[i];
#define print(arr) for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";
#define nline cout<<endl

class Solution {
public:
    void calculator(ll n, vector<ll>& a,int k) {
        int ans = INT_MIN;
        vecctor<int> special(n,0);

        for(int i=n-1;i>=0;i--){
            for(int j=i;j>=0;j-=k){
                if(j-k>=n) special[j] = ()
                special[j] = max(special[j-k],0);
            }
            ans = max(ans,temp);
        }
        return ans;
    }
};

signed main() {
    fastio();
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        input(a);
        Solution obj;
        obj.calculator(n, a);
    }
    return 0;
}
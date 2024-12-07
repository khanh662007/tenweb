#include<bits/stdc++.h>
using namespace std;
const int NMAX=2000+3;
const int N=2e6+3;
const long long MOD=1e8;
struct in{
    int l;
    int r;
    int pos;
    bool operator<(in pa){
        return l<pa.l;
    }
}a[N];
#define f first
#define s second
int k,n,m,pos=1;
long long res,c[N],dp[1000][1000],f[1000][1000],ans,bt[N],b[N];
vector<int>v;
pair<int,int>pa[N];
map<int,int>mp;
void feo(){
    freopen("BAG.inp","r",stdin);
    freopen("BAG.out","w",stdout);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    feo();
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].r,a[i].pos=i;
    }
    bt[0]=0;
    //sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			f[i][j]=f[i-1][j];
			if ((j>=a[i].l) && (f[i-1][j-a[i].l]+a[i].r>f[i-1][j]))
				f[i][j]=f[i-1][j-a[i].l]+a[i].r;
		}
    int pos=0;
    for(int i=1;i<=m;i++){
        if(res<f[n][i]){
            res=f[n][i];
            pos=i;
        }
    }
    cout<<res<<'\n';
    //cout<<bt[44]<<'\n';
    int d=res;
    int j=m;
    for (int i=n; i>=1; i--)
        if (f[i][j]!=f[i-1][j])
        {
            v.push_back(i);
            j-=a[i].l;
        }
    sort(v.begin(),v.end());
    for(auto x:v)
        cout<<x<<" ";
        cout<<'\n';
    cout<<pos;
}

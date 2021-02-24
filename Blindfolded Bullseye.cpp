#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937_64 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int ask(int x,int y) {
	printf("%d %d\n",x,y);
	fflush(stdout);
	char s[10];
	scanf("%s",s);
	if (s[0]=='C') return 2;
	if (s[0]=='H') return 1;
	else return 0;
}

void solve() {
	int sx=0,sy=0;
	while (1) {
		int x=rnd(2000000001)-1000000000;
		int y=rnd(2000000001)-1000000000;
		int d=ask(x,y);
		if (d==2) return;
		if (d==1) {
			sx=x; sy=y;
			break;
		}
	}
	int xl=sx,xr=1000000001;
	while (xl+1<xr) {
		int md=xl+(xr-xl)/2;
		int d=ask(md,sy);
		if (d==2) return;
		if (d==1) xl=md; else xr=md;
	}
	int px=xl;

	xr=sx,xl=-1000000001;
	while (xl+1<xr) {
		int md=xl+(xr-xl)/2;
		int d=ask(md,sy);
		if (d==2) return;
		if (d==1) xr=md; else xl=md;
	}
	int qx=xr;


	xl=sy,xr=1000000001;
	while (xl+1<xr) {
		int md=xl+(xr-xl)/2;
		int d=ask(sx,md);
		if (d==2) return;
		if (d==1) xl=md; else xr=md;
	}
	int py=xl;

	xr=sy,xl=-1000000001;
	while (xl+1<xr) {
		int md=xl+(xr-xl)/2;
		int d=ask(sx,md);
		if (d==2) return;
		if (d==1) xr=md; else xl=md;
	}
	int qy=xr;
	assert(ask((px+qx)/2,(py+qy)/2)==2);

}

int _,a,b;
int main() {
	scanf("%d%d%d",&_,&a,&b);
	for (;_;_--) {
		solve();
	}
}
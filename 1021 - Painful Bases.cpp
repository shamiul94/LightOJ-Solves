//
// Created by Heisenberg on 07-Jul-18.
//


#include <bits/stdc++.h>
#include<vector>

#define ll                                      long long int
#define ull                                     unsigned long long
#define ld                                      long double

#define ff                                      first
#define ss                                      second

#define fi                                      freopen("in.txt", "r", stdin)
#define fo                                      freopen("out.txt", "w", stdout)
#define m0(a) memset(a , 0 , sizeof(a))
#define m1(a) memset(a , -1 , sizeof(a))
#define pi acos(-1.0)
#define debug                                   printf("yes\n")
#define what_is(x)                              cout << #x << " is " << x << endl
#define pf                                      printf
#define sf                                      scanf

#define pb                                      push_back
#define mp                                      make_pair
#define eb                                      emplace_back
#define pii                                     pair<int, int>
#define piii                                    pair<pii, int>

#define SQR(a)                                  ((a)*(a))
#define QUBE(a)                                 ((a)*(a)*(a))

#define scanI(a)                                scanf("%d",&a)
#define scanI2(a, b)                             scanI(a) , scanI(b)
#define scanI3(a, b, c)                           scanI(a), scanI(b), scanI(c)
#define scanI4(a, b, c, d)                         scanI(a), scanI(b), scanI(c), scanI(d)

#define sll(a)                                scanf("%lld",&a)
#define sll2(a, b)                             sll(a) , sll(b)
#define sll3(a, b, c)                           sll(a), sll(b), sll(c)
#define sll4(a, b, c, d)                         sll(a), sll(b), sll(c), sll(d)

#define inf LLONG_MAX
#define minf LLONG_MIN
#define min3(a, b, c) min(a,min(b,c))
#define max3(a, b, c) max(a,max(b,c))
#define ones(mask)  __builtin_popcount(mask)
#define mx 150000

using namespace std;

ll BigMod(ll B, ll P, ll M)
{
    ll R = 1;
    while (P > 0)
    {
        if (P % 2 == 1)
        {
            R = (R * B) % M;
        }
        P /= 2;
        B = (B * B) % M;
    }
    return R;
}

int Set(int N, int pos)
{
    return N = N | (1 << pos);
}

int reset(int N, int pos)
{
    return N = N & ~(1 << pos);
}

bool check(int N, int pos)
{
    return (bool) (N & (1 << pos));
}

void binary(int m)
{
    int d ;
    string s ;
    while(m)
    {
        d = m % 2 ;
        char c = d + '0';
        s = s + c ;
        m = m / 2 ;
    }
    cout <<  s  << endl ;
}

/************************************** END OF INITIALS ****************************************/

ll base, K, N;
string Num;
ll dp[(1 << 16)+2][20] = {};
ll Arr[20];

void toIntArr(string str)
{
    N = str.length();
    for (ll i = 0; i < N; i++)
    {
        if (str[i] <= '9' && str[i] >= '0')
        {
            Arr[i] = str[i] - '0';
        }
        else
        {
            Arr[i] = str[i] - 'A' + 10;
        }
    }
}

ll solve(int mask, ll tillNum)
{
    if (mask == (1<<N)-1)
    {
        if(tillNum == 0)
            return 1 ;
        else
            return 0 ;
    }

    if (dp[mask][tillNum] != -1)
        return dp[mask][tillNum] ;

    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (check(mask, i) == 0)
        {
            ans += solve(Set(mask, i), (tillNum * base + Arr[i])%K);
        }
    }

    return dp[mask][tillNum] = ans;
}

int main()
{

//    fi ;
//    fo;
    ll T, t = 0;
    sll(T);

    while (T--)
    {
        m1(dp);
        t++;

        sll2(base, K);
        cin >> Num;
        toIntArr(Num);

        ll ans = solve(0, 0);

        printf("Case %lld: ", t);

        cout << ans << endl;
    }
    return 0 ;
}

/*
3
2 2
10
10 2
5681
16 1
ABCDEF0123456789
*/

/*
1
12
20922789888000
*/

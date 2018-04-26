#include<cstdio>
#define maxn 10000009
int zi[maxn], mu[maxn], next[maxn];
int gcd(int a, int b)
{
    if(b==0)    return a;
    return gcd(b, a%b);
}
void huajian(int *a, int *b)
{
    int zi=*a, mu=*b, g=gcd(zi, mu);
    *a=zi/g;
    *b=mu/g;
}
void solve()
{
    int a, b, c, d, n, m, tail, wi, wm, cur, ne, k;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &n, &m);
    huajian(&a, &b);
    huajian(&c, &d);
    zi[1]=a, mu[1]=b, zi[2]=c, mu[2]=d;
    tail=3;
    cur=1;
    next[1]=2;
    next[2]=tail;
    k=0;
    while(cur!=2)
    {
        ne=next[cur];
        wi=zi[cur]+zi[ne];
        wm=mu[cur]+mu[ne];
        huajian(&wi, &wm);
        if(wm>m)
        {
            cur=next[cur];
  
            k++;
            if(k==n&&cur!=2)
            {
                printf("%d %d\n", zi[cur], mu[cur]);
                return;
            }
              
        }
        else if((wi!=zi[cur]||wm!=mu[cur])&&(wi!=zi[ne]||wm!=mu[ne]))
        {
            next[tail]=next[cur];
            next[cur]=tail;
            zi[tail]=wi;
            mu[tail]=wm;
            tail++;
        }
    }
    printf("-1\n");
    return;
}
int main()
{
    int Q;
    scanf("%d", &Q);
    while(Q--)
    {
        solve();
    } 
    return 0;
}

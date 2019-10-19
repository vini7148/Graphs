#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct ed
{
    int u,v;
    float w;
};

struct ex
{
    int a,b;
};

bool operator<(const ed& a, const ed& b)
{
    return a.w < b.w;
}

class se
{
    int pa[1001],ra[1001];
public:
    void make(int i)
    {
        pa[i] = i;
        ra[i] = 0;
    }
    int fi(int i)
    {
        while(i != pa[i])
            i = pa[i];
        return i;
    }
    void uni(int i, int j)
    {
        int id,jd;
        id = fi(i);
        jd = fi(j);
        if(id == jd)
            return ;
        else if(ra[id] > ra[jd])
            pa[jd] = id;
        else
        {
            pa[id] = jd;
            if(ra[id] == ra[jd])
                ra[jd]++;
        }
    }
};

class gp
{
    int v,e;
    vector<ex> ea;
    vector<ed> ee;
    void mked(int a, int b)
    {
        ed ans = {a, b, sqrt((a*a)*1.00+(b*b)*1.00)};
        ee.push_back(ans);
    }
    void cre()
    {

    }
public:
    void input()
    {
        cin >> v;
        e = v;
        for(int i = 1; i <= e; i++)
        {
            ex e;
            cin >> e.a >> e.b;
            ea.push_back(e);
        }
        cre();
    }
    float ro()
    {
        se s;
        for(int i=1;i<=v;i++)
            s.make(i);
        float ans=0;

        sort(ee.begin(),ee.end());

        for(int i=0;i<e;i++)
        {
            if(s.fi(ee[i].u) != s.fi(ee[i].v))
            {
                ans += ee[i].w;
                s.uni(ee[i].u, ee[i].v);
            }
        }
        return ans;
    }
    void output()
    {
        cout << ro();
    }
};

int main()
{
    gp g;
    g.input();
    g.output();
}

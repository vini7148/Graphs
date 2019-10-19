#include <iostream>
#include <vector>

using namespace std;

class gp
{
    int v,e,nu[1000],cc=1;
    bool vi[1001]={false};
    vector<int> ad[1000];
    void app(int a,int b)
    {
        ad[a].push_back(b);
    }

public:

    void input()
    {
        cin>>v>>e;
        for(int i=0;i<e;i++)
        {
            int a,b;
            cin>>a>>b;
            app(a,b);
            app(b,a);
        }
    }
    void ex(int x)
    {
        vi[x]=true;
        nu[x]=cc;
        for(int i=0;i<ad[x].size();i++)
        {
            if(!vi[ad[x][i]])
                ex(ad[x][i]);
        }
    }
    void dfs()
    {
        cc=1;
        for(int i=1;i<=v;i++)
        {
            if(!vi[i])
            {
                ex(i);
                cc++;
            }
        }
    }
    void output()
    {
        dfs();
        if(nu[1]==nu[v])
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}g;

int main()
{
    g.input();
    g.output();
}

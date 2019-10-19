//#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class gp
{
	int v, e, nu[1000], cc = 1, cl = 0;;
	bool vi[1001] = { false },vi2[1001] = { false };
	vector<int> ad[1000];
	int pr[1001], po[1001];
	void app(int a, int b)
	{
		ad[a].push_back(b);
	}

public:

	void input()
	{
		cin >> v >> e;
		for (int i = 0; i < e; i++)
		{
			int a, b;
			cin >> a >> b;
			//app(a, b);
			app(b, a);
		}
	}
	void pre(int i)
	{
		cl++;
		pr[i] = cl;
	}
	void post(int i)
	{
		cl++;
		po[i] = cl;
	}
	void ex(int x)
	{
		vi[x] = true;
		nu[x] = cc;
		for (int i = 0; i < ad[x].size(); i++)
		{
			if (!vi[ad[x][i]])
				ex(ad[x][i]);
		}
	}
	void ex2(int x)
	{
		vi2[x] = true;
		//nu[x] = cc;
		for (int i = 0; i < ad[x].size(); i++)
		{
			if (!vi2[ad[x][i]])
				ex2(ad[x][i]);
		}
	}
	void dfs()
	{
		cc = 1;
		for (int i = 1; i <= v; i++)
		{
			pre(i);
			if (!vi[i])
			{
				ex(i);
				cc++;
			}
			post(i);
		}
	}
	int ck(int x)
	{
		if(x==v)
            return 0;
		int j=-1,ma=-1;
		for(int i=1;i<=v;i++)
        {
            if(po[i]>ma && !vi2[i])
            {
                ma=po[i];
                j=i;
            }
        }
        ex2(j);
        int co=1;
        for(int i=1;i<=v;i++)
        {
            if(vi2[i])
                co++;
        }
        if(co>x)
            return 1;
        else
            return ck(co);
	}
	void output()
	{
        dfs();
        cout<<ck(1)<<endl;
	}
}g;

int main()
{
	g.input();
	g.output();
}

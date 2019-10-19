#include <iostream>
#include <vector>

using namespace std;

int qu[100], n = 100, front = - 1, rear = - 1;

void Insert(int val)
{
   if (rear == n - 1){}
      //cout<<"qu Overflow"<<endl;
   else
   {
      if (front == - 1)
      front = 0;
      //cout<<"Insert the element in qu : "<<endl;
      //cin>>val;
      rear++;
      qu[rear] = val;
   }
}

int Delete()
{
   if (front == - 1 || front > rear)
   {
      //cout<<"qu Underflow ";
   return 0;
   }
   else
   {
      front++;
      return qu[front-1];
   }
}

class gh
{
	int v, e;
	vector<int> adj[1001];
	unsigned int dist[1001] = { -1 };
	bool vi[1001] = { false };
	void add(int a, int b)
	{
		adj[a].push_back(b);
	}
public:
	void input()
	{
		cin >> v >> e;
		for (int i = 0; i < e; i++)
		{
			int a, b;
			cin >> a, b;
			add(a, b);
		}
	}
	void bfs(int x)
	{
		//qu bb;
		dist[x] = 0;
		//bb.enqu(x);
		Insert(x);
		int u;
        u = Delete();
		while (u)
		{

			for (int i = 0; i < adj[u].size(); i++)
			{
				if (dist[adj[u][i]] == -1)
				{
					Insert(adj[u][i]);
					dist[adj[u][i]] = dist[u] + 1;
				}
			}
			u = Delete();
		}
	}
	void incase()
	{
		int x, y;
		cin >> x >> y;
		bfs(x);
		cout << dist[y];
	}
};

int main()
{
	gh g;
	g.input();
	g.incase();
}

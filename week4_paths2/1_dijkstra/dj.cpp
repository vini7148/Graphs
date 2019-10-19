#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct ha
{
    int d, v;
};

void swap(ha *x, ha *y);

class MinHeap
{
    ha *harr;
    int capacity;
    int heap_size;
public:
    MinHeap(int capacity);

    void MinHeapify(int );

    int parent(int i) { return (i-1)/2; }

    int left(int i) { return (2*i + 1); }

    int right(int i) { return (2*i + 2); }

    int extractMin();

    void decreaseKey(int i, int new_val);

    int getMin() { return harr[0].v; }

    void deleteKey(int i);

    void insertKey(int k, int v);
};

MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new ha[cap];
}

void MinHeap::insertKey(int k, int v)
{
    if (heap_size == capacity)
        return;

    heap_size++;
    int i = heap_size - 1;
    harr[i].d = k;
    harr[i].v = v;

    while (i != 0 && harr[parent(i)].d > harr[i].d)
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}

void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i].d = new_val;
    while (i != 0 && harr[parent(i)].d > harr[i].d)
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}

int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0].v;
    }

    ha root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);

    return root.v;
}

void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l].d < harr[i].d)
        smallest = l;
    if (r < heap_size && harr[r].d < harr[smallest].d)
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

void swap(ha *x, ha *y)
{
    ha temp = *x;
    *x = *y;
    *y = temp;
}

class gp
{
    int v, e;
	vector<int> adj[1001],co[1001][1001];
	unsigned int dist[1001] = { -1 }, prev[1001] = { 0 };
	bool vi[1001] = { false };
	void add(int a, int b, int c)
	{
		adj[a].push_back(b);
		co[a][b].push_back(c);
	}
public:
	void input()
	{
		cin >> v >> e;
		for (int i = 0; i < e; i++)
		{
			int a, b, c;
			cin >> a, b, c;
			add(a, b, c);
		}
	}
	void dj(int x)
	{
	    dist[x] = 0;
	    MinHeap h(v+1);
	    for(int i=1;i<=v;i++)
        {
            h.insertKey(dist[i],i);
        }

	}
};

int main()
{

}

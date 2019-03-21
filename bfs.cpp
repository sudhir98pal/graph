//BT17CSE030
//Breath first traversal using queue.
#include <bits/stdc++.h>
#define pb push_back
#define max_size 1000
using namespace std;
//***********************************************************************************
class Queue
{
private:
    int item, i;
    int arr_queue[max_size];
    int rear;
    int front;

public:

    Queue()
		{
        rear = 0;
        front = 0;
    }

    void qpush(int x)
		{
        if (rear ==max_size)
            cout << "\n## Queue Reached Max!";
        else {
            arr_queue[rear++] =x;

        }
    }

    void dqueue() {
        if (front == rear)
            cout << "\n## Queue is Empty!";
        else {
            front++;
        }
    }
		bool qempty()
		{
			return (front==rear);
		}

int qfront()
{
	return arr_queue[front];
}

};
//***********************************************************************************
vector<bool> v;
vector<vector<int> > g;

void edge(int a, int b)
{
	g[a].pb(b);//go to vector g at a and push back b there.

 g[b].pb(a);//go to vector g at b and push back a there.
 // edge ---> a----b undirected.
}

void bfs(int u)
{
Queue q;

	q.qpush(u);
	v[u] = true;

	while (!q.qempty()) {

		int f = q.qfront();
		q.dqueue();

		cout << f << " ";

		// Enqueue all adjacent of f and mark them visited
		for (auto i = g[f].begin(); i != g[f].end(); i++) {
			if (!v[*i])
      {
				q.qpush(*i);
				v[*i] = true;
			}
		}
	}
}

// Driver code
int main()
{
	int n, e;
  //n=upper bound of graph +1,say n=8 then graph should have node with values 0 to 7
  //e=no of edge
	cin >> n >> e;

	v.assign(n, false);//intially false all
	g.assign(n, vector<int>());// vector containing other vectors.

	int a, b;
	for (int i = 0; i < e; i++)
  {
		cin >> a >> b;
		edge(a, b);//making edge between a and b.
	}

	for (int i = 1; i < n; i++) // staring from 1.
	{
		if (!v[i])// if not visited the calling bfs. for node i.
			bfs(i);
	}

	return 0;
}
//Time Complexity: O(V+E)

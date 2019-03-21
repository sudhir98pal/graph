//BT17CSE030
//lentgh of two node using bfs
//The idea is to perform BFS from one of given input vertex(u).
// At the time of BFS maintain an array of distance[n] and initialize it to zero for all vertices.
//Now, suppose during BFS, vertex x is popped from queue and we are pushing all adjacent non-visited vertices(i) back into queue
// at the same time we should update distance[i] = distance[x] + 1;.
#include<bits/stdc++.h>
using namespace std;
#define max_size 1000
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

int minEdgeBFS(vector <int> edges[], int u,int v, int n)
{
	// visited[n] for keeping track of visited
	// node in BFS
	vector<bool> visited(n, 0);

	// Initialize distances as 0
	vector<int> distance(n, 0);

	// queue to do BFS.
	Queue Q;
	distance[u] = 0;

	Q.qpush(u);
	visited[u] = true;
	while (!Q.qempty())
	{
		int x = Q.qfront();
		Q.dqueue();

		for (int i=0; i<edges[x].size(); i++)
		{
			if (visited[edges[x][i]])
				continue;

			// update distance for i
			distance[edges[x][i]] = distance[x] + 1;
			Q.qpush(edges[x][i]);
			visited[edges[x][i]] = 1;
		}
	}
	return distance[v];
}

// function for addition of edge
void addEdge(vector <int> edges[], int u, int v)
{
edges[u].push_back(v);
edges[v].push_back(u);
}

// Driver function
int main()
{
	// To store adjacency list of graph
	// int n = 9;
	// vector <int> edges[9];
	// addEdge(edges, 0, 1);
	// addEdge(edges, 0, 7);
	// addEdge(edges, 1, 7);
	// addEdge(edges, 1, 2);
	// addEdge(edges, 2, 3);
	// addEdge(edges, 2, 5);
	// addEdge(edges, 2, 8);
	// addEdge(edges, 3, 4);
	// addEdge(edges, 3, 5);
	// addEdge(edges, 4, 5);
	// addEdge(edges, 5, 6);
	// addEdge(edges, 6, 7);
	// addEdge(edges, 7, 8);
	// int u = 0;
	// int v = 5;
	// cout << minEdgeBFS(edges, u, v, n);
  //*************************
  int n2 = 4;
  vector <int> edges2[4];
  addEdge(edges2, 0, 1);
  addEdge(edges2, 0, 2);
  addEdge(edges2, 3, 3);

  int u2 = 3;
  int v2 = 2;
  cout << minEdgeBFS(edges2, u2, v2, n2);
	return 0;
}

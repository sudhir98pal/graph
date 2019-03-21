//BT17CSE030
//to check if a Given Graph is Bipartite using bfs
// 1. Use BFS to traverse all the vertices.
// 2. Take a vertex and colour it red. (‘R’)
// 3. Colour all its neighbour vertices as (‘B’). (Blue = ‘B’ and Red = ‘R’)
// 4. Colour the next level vertices as (‘R’) and so, untill all vertices are coloured.
// 5. If at any step, we encounter contradicting colours, then the given graph to us is not bipartite!.
// 6. Hence, break and print “No” else print “Yes”;
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
vector<vector<int> > g;
vector<int> color;
void edge(int a, int b)
{
	g[a].pb(b);//go to vector g at a and push back b there.

 g[b].pb(a);//go to vector g at b and push back a there.
 // edge ---> a----b undirected.
}
//*************************************************************

//1=R,0=B
bool isBipartite()
{
    color[0] = 1; // Mark colour as 1 for first vertex.
    Queue q;
    q.qpush(0);

        while (!q.qempty())
         {

      		int f = q.qfront();
      		q.dqueue();

      		// Enqueue all adjacent of f and mark them visited
      		for (auto i = g[f].begin(); i != g[f].end(); i++)
          {
      			if (color[*i]==-1)
            {
              color[*i]=1-color[f];
              	q.qpush(*i);

            }
              else if (color[*i] == color[f]) // if there is an edge and both vertices have same colours
            return 0;                                   // graph is not bipartite
          }
          }
return 1;


}
//**************************************************************************


// Driver code
int main()
{
	int n, e;
  //n=upper bound of graph +1,say n=8 then graph should have node with values 0 to 7
  //e=no of edge
	cin >> n >> e;
  color.assign(n, -1);//intially  all color =-1;
	g.assign(n, vector<int>());// vector containing other vectors.


	int a, b;
	for (int i = 0; i < e; i++)
  {
		cin >> a >> b;
		edge(a, b);//making edge between a and b.
	}

cout<<isBipartite();
	return 0;
}
//Time Complexity: O(V+E)

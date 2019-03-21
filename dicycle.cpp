//BT17CSE030
//Detect a cycle in directed_graph using color method.
#include <bits/stdc++.h>
#define pb push_back
#define max_size 1000
using namespace std;
//*************************************************************************************
enum Color {WHITE, GRAY, BLACK};
class Stack
{
    private:
        int num[max_size];
        int top;
    public:
        Stack()// constructor
				{
					top=-1;
				}
				int isEmpty()
				{
				    if(top==-1)
				        return 1;
				    else
				        return 0;
				}
        void push(int n)
				{

						 if(top!=(max_size-1))
						 {

						 ++top;
						 num[top]=n;

					 }

				}
        void pop()
				{
					    --top;
				}
					int stack_top()
					{
						return num[top];
					}


};

//*****************************************************************************************

vector<bool> v;
//boolean vector for marking of visited node
vector<vector<int> > g;
// vector of vector to maintain how many nodes are connected to it.

void edge(int a, int b)
{
	g[a].pb(b);//go to vector g at a and push back b there.

 //g[b].pb(a);//go to vector g at b and push back a there.
 // edge ---> a----b undirected.
}

bool DFSUtil(int u, int color[])
{
    // GRAY :  This vertex is being processed (DFS
    //         for this vertex has started, but not
    //         ended (or this vertex is in function
    //         call stack)
    color[u] = GRAY;

    // Iterate through all adjacent vertices

    for (auto i = g[u].begin(); i != g[u].end(); ++i)
    {
        int x = *i;  // An adjacent of u

        // If there is
        if (color[x] == GRAY)
          return true;

        // If v is not processed and there is a back
        // edge in subtree rooted with v
        if (color[x] == WHITE && DFSUtil(x, color))
          return true;
    }

    // Mark this vertex as processed
    color[u] = BLACK;

    return false;
}

// Returns true if there is a cycle in graph
bool isCyclic(int n)
{

    int color[n];//color array to store color of nodes.
    // WHITE : Vertex is not processed yet.  Initially
    //         all vertices are WHITE.
    //
    // GRAY : Vertex is being processed (DFS for this
    //        vertex has started, but not finished which means
    //        that all descendants (ind DFS tree) of this vertex
    //        are not processed yet (or this vertex is in function
    //        call stack)
    //
    // BLACK : Vertex and all its descendants are
    //         processed.
    for (int i = 0; i < n; i++)
        color[i] = WHITE;  // Initialize color of all vertices as WHITE

    // Do a DFS traversal beginning with all
    // vertices
    for (int i = 0; i <n; i++)
        if (color[i] == WHITE)
           if (DFSUtil(i, color) == true)
              return true;

    return false;
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

  if (isCyclic(n))
          cout << "Graph contains cycle";
      else
          cout << "Graph doesn't contain cycle";


	return 0;
}
//Time Complexity: O(V+E)

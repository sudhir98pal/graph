//BT17CSE030
//Detect a cycle in undirected_graph using dfs.
#include <bits/stdc++.h>
#define pb push_back
#define max_size 1000
using namespace std;
//*************************************************************************************

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
  	g[b].pb(a);//go to vector g at b and push back a there.
}

bool isCyclicUtil(int x, int parent)
{
    // Mark the current node as visited
    v[x] = true;

    // Recur for all the vertices adjacent to this vertex

    for (auto i = g[x].begin(); i != g[x].end(); ++i)
    {
        // If an adjacent is not visited, then recur for that adjacent
        if (!v[*i])
        {
           if (isCyclicUtil(*i,x))
              return true;
        }

        // If an adjacent is visited and not parent of current vertex,
        // then there is a cycle.
        else if (*i != parent)
           return true;
    }
    return false;
}

// Returns true if the graph contains a cycle, else false.
bool is_cyclic(int n)
{

  	v.assign(n, false);//intially false all

    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for (int u = 0; u <n; u++)
        if (!v[u]) // Don't recur for u if it is already visited
          if (isCyclicUtil(u, -1))
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



	g.assign(n, vector<int>());// vector containing other vectors.

	int a, b;
	for (int i = 0; i < e; i++)
  {
		cin >> a >> b;
		edge(a, b);//making edge between a and b.
	}
  if (is_cyclic(n))
          cout << "Graph contains cycle";
      else
          cout << "Graph doesn't contain cycle";



	return 0;
}
//Time Complexity: O(V+E)

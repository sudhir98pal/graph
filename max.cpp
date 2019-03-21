//BT17CSE030
//Maximum edges that can be added to DAG so that is remains DAG
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

 //g[b].pb(a);//go to vector g at b and push back a there.
 // edge ---> a----b undirected.
}
//*********************************************************************
  Stack s;

void topologicalSortUtil(int i)
{
    // Mark the current node as visited.
    v[i] = true;

    for (auto j = g[i].begin(); j != g[i].end(); ++j)
        if (!v[*j])
            topologicalSortUtil(*j);

    // Push current vertex to stack which stores result
    s.push(i);
}

vector<int> topologicalSort(int n,int e)
{
//vector to store topological order.
vector<int> topo;
    // Mark all the vertices as not visited

    	v.assign(n, false);

      for (int i = 0; i < n; i++)
        if (v[i] == false)
          topologicalSortUtil(i);

      // Print contents of stack
      while (s.isEmpty() == false)
      {

          topo.pb(s.stack_top());
          s.pop();
      }


return topo;

}
//*****************************************************************
void max_edge_add(int n,int e)
{
    vector<bool> visited;
    	visited.assign(n,false);
    vector<int> topo = topologicalSort( n, e);

    //  looping for all nodes
    for (int i = 0; i < topo.size(); i++)
    {
        int t = topo[i];

        //  In below loop we mark the adjacent node of t
        for (auto j = g[t].begin(); j != g[t].end(); j++)
            visited[*j] = true;

        //  In below loop unmarked nodes are printed
        for (int j = i + 1; j < topo.size(); j++)
        {
            // if not marked, then we can make an edge
            // between t and j
            if (!visited[topo[j]])
                cout << t << "-" << topo[j] << " ";

            visited[topo[j]] = false;
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

	g.assign(n, vector<int>());// vector containing other vectors.

	int a, b;
	for (int i = 0; i < e; i++)
  {
		cin >> a >> b;
		edge(a, b);//making edge between a and b.
	}
max_edge_add(n,e) ;
cout<<endl;

	return 0;
}
//Time Complexity: O(V+E)

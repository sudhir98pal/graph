//BT17CSE030
//finding mother vertex using dfs ...last visited if any in dfs;
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
	g[a].pb(b);


}

void dfs(int u)
{
	Stack  s;//stack stl

	s.push(u);
	v[u] = true;//mark it as visited

	while (!s.isEmpty())
   {

		int f = s.stack_top();
		s.pop();

	//	cout << f << " ";

		// pop all adjacent of f and mark them visited
		for (auto i = g[f].begin(); i != g[f].end(); i++)
    {
			if (!v[*i])
      {
				s.push(*i);
				v[*i] = true;
			}
		}
	}
}
//Returns a mother vertex if exists. Otherwise returns -1
int findmother(int n,int e)
{

  	v.assign(n, false);//intially false all

    // To store last finished vertex (or mother vertex)
    int m = 0;

    // Do a DFS traversal and find the last finished
    // vertex
    for (int i = 0; i < n; i++) {
      if (!v[i])
      {
        dfs(i);
        m=i;
      }// if not visited the calling bfs. for node i.

    }

    // If there exist mother vertex (or vetices) in given
    // graph, then v must be one (or one of them)

    // Now check if v is actually a mother vertex (or graph
    // has a mother vertex).  We basically check if every vertex
    // is reachable from v or not.

    // Reset all values in visited[] as false and do
    // DFS beginning from v to check if all vertices are
    // reachable from it or not.

    	v.assign(n, false);
      for (int i = 0; i < n; i++) {
        if (!v[i])
        {
          dfs(i);

        }// if not visited the calling bfs. for node i.

      }
    for (int i=0; i<n; i++)
        if (v[i] == false)
            return -1;

    return m;
}
// Driver code
int main()
{
	int n, e;
  //n=upper bound of graph +1,say n=8 then graph should have node with values 0 to 7
  //e=no of edge
	cin >> n >> e;
//example n=6 v=8 0--1,1--3,0--2,2---4,1--4,3---4,3---5,4---5

	g.assign(n, vector<int>());// vector containing other vectors.

	int a, b;
	for (int i = 0; i < e; i++)
  {
		cin >> a >> b;
		edge(a, b);//making edge between a and b.
	}

cout<<"the mother vertext is="<<findmother(n,e);

	return 0;
}
//Time Complexity: O(V+E)

//BT17CSE030
//Topological sorting.
//concept--> fully visited after recursion put it in stack after calling sortutil.
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

void topologicalSort(int n,int e)
{

    // Mark all the vertices as not visited

    	v.assign(n, false);

      for (int i = 0; i < n; i++)
        if (v[i] == false)
          topologicalSortUtil(i);

      // Print contents of stack
      while (s.isEmpty() == false)
      {
          cout << s.stack_top() << " ";
          s.pop();
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
cout<<" topological sort is as follows-->";
topologicalSort( n, e);
cout<<endl;

	return 0;
}
//Time Complexity: O(V+E)

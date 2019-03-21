//BT17CSE030
//Depth first traversal using stack.
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

void dfs(int u)
{
	Stack  s;//stack stl

	s.push(u);
	v[u] = true;//mark it as visited

	while (!s.isEmpty())
   {

		int f = s.stack_top();
		s.pop();

		cout << f << " ";

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

	for (int i = 0; i < n; i++) {
		if (!v[i])// if not visited the calling bfs. for node i.
			dfs(i);
	}

	return 0;
}
//Time Complexity: O(V+E)

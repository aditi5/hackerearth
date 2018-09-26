#include <bits/stdc++.h>
#include <cstack>
using namespace std;

stack<int> st;

int main()
	{
		int t, n;
		cin>>t;
		while(t--)
			{
				int max = 0;
				cin>>n;
				int a[n];
				for (int i = 0; i < n ; ++i)
				{
					cin>>a[i];
					st.push_back(a[i]);
				}
				for (int i = 0; i < n ; ++i)
				{
					if(max < st.top())
					{
						max = st.top();
					}
					if(st.top() >= max)
					{
						cout<<st.top()<<" ";
					}
					st.pop();
				}

			}





	}
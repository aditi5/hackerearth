// https://www.geeksforgeeks.org/number-nges-right/


#include <bits/stdc++.h>
using namespace std;

int main()
{

	int n, i, q, index;
	stack<int> st;
	// vector < pair<int , int > > vct;
	unordered_map < int, int > mp;
	ios_base::sync_with_stdio(false);
	cout<<"Enter the number of elements\n";
	cin>>n;
	cout<<"Enter the number of queries\n";
	cin>>q;
	int arr[n];
	cout<<"Scan all the elements\n";
	for( i = 0 ; i < n ; i++)
	{
		cin>>arr[i];
	}

	st.push(arr[0]);

	for( i = 0 ; i<n; i++)
	{
		if(st.empty())
		{
			st.push(arr[i]);
			continue;
		}

		while(!st.empty() && arr[i]>st.top())
		{
			mp[st.top()] = arr[i]; 
			st.pop();
		}

		st.push(arr[i]);


	}

	while(!st.empty()){
		mp[st.top()] = -1; 
		st.pop();
	}


	// for( i = 0 ; i < n ; i++)
	// 	{
	// 		cout<<arr[i]<<"---->"<<mp[arr[i]]<<"\t";
	// 	}


	while(q--)
	{
		cout<<"Enter the index for finding next greaters\n";
		cin>>index;
		int count = 0;
		index = arr[index];
		while(mp[index] != -1)
			{
				index = mp[index];
				count++;

			}
			cout<<"Number of nges \t"<<count<<endl;
	}

}
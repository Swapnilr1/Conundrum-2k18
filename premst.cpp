#include <bits/stdc++.h>
using namespace std;

void preorder(vector< vector< int > > v)
{
    vector <bool> visited(500,false);
    queue <int> q;
    q.push(0);
    visited[0] = true;
    while(q.size() > 0)
    {
        int x = q.front(), sz = v[x].size();
        q.pop();
        cout<<x<<"\n";
        for(int i = 0; i < sz; i++)
        {
            if(!visited[v[x][i]])
            {
                visited[v[x][i]] = true;
                q.push(v[x][i]);
            }
        }
    }
}

int main()
{
    vector< vector< int > > v(500);
    for(int i = 0; i < 499; i++)
    {
        int n, x;
        cin>>n>>x;
        v[n].push_back(x);
        v[x].push_back(n);
    }
    preorder(v);
    return 0;
}
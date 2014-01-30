#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

bool BFS(vector<vector<int>> graph,int start, int end)
{
	queue<int> q;
	bool visited[100];
	memset(visited,false,sizeof(visited));
	q.push(start);
	while(!q.empty())
	{
		int temp = q.front();
		q.pop();
		if(temp==end)
			return true;
		visited[temp] = true;
		for(unsigned int i = 0;i<graph[temp].size();i++)
		{
			if(visited[graph[temp][i]]==false)
			{
				visited[graph[temp][i]]=true;
				q.push(graph[temp][i]);
			}
		}
	}
	return false;
}

int main()
{
	vector<vector<int> > graph(6);
    	graph[0].push_back(1);
    	graph[0].push_back(2);
    	graph[1].push_back(0);
    	graph[1].push_back(3);
    	graph[2].push_back(3);
    	graph[3].push_back(4);
    	graph[4].push_back(2);
    	graph[4].push_back(3);
    	graph[4].push_back(5);
    	graph[5].push_back(0);
    	graph[5].push_back(2); 
	if(BFS(graph,0,5)||BFS(graph,5,0))
		cout<<"there exists path between 0 and 5."<<endl;
	else
		cout<<"no path between 0 and 5"<<endl;
	graph[4].pop_back();
	if(BFS(graph,0,5))
		cout<<"there exists path between 0 and 5."<<endl;
	else
		cout<<"no path between 0 and 5"<<endl;
	if(BFS(graph,0,5)||BFS(graph,5,0))
		cout<<"there exists path between 0 and 5."<<endl;
	else
		cout<<"no path between 0 and 5"<<endl;
}

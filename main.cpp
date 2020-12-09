#include <bits\stdc++.h>

using namespace std;

bool visited[100];
int getMinIndex(int dist[100][100]){
	int index = 0;
	int mindist = INT_MAX;
	for (int i = 0; i < 100; ++i)
	{
		if(dist[0][i] < mindist && !visited[i]){
			mindist = dist[0][i];
			index = i;
		}
	}
	return index;
}

void solve(int dist[100][100],int n){
	visited[0] = true;
	bool check = false;

	while(!check){
		int p = getMinIndex(dist);
		visited[p] = true;
		for (int i = 0; i < n; ++i)
		{
			if(dist[p][i]!=INT_MAX && dist[0][p]+dist[p][i]<dist[0][i]) dist[0][i] = dist[0][p] + dist[p][i];
		}

		check = true;
		for (int i = 0; i < n; ++i)
		{
			if(visited[i] == false){
				check = false;
				break;
			}
		}
	}
}
int main(){
	
	int n; 				//number of nodes(max 100)
	cin >> n;
	int dist[100][100];
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j) dist[i][j] = INT_MAX; 
	}
	for (int i = 0; i < 100; ++i) {
		dist[i][i] = 0;
		visited[i] = false;
	}
	int e;				//number of edges
	cin >> e;
	for (int i = 0; i < e; ++i)
	{
		int a,b,x;
		cin >> a >> b >> x;			//inputting edges with 1-based indexing in nodes
		dist[a-1][b-1] = x;
		dist[b-1][a-1] = x;
	}

	solve(dist,n);
	for (int i = 0; i < n; ++i) cout << i+1 << " " << dist[0][i] << endl;


	return 0;
}	
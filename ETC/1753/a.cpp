#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321
using namespace std;

int n,e,k;
int start,dest,weight;
vector<pair<int,int> > node[20005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
int dist[20005];

int main(){
    fastIO;
	
    cin>>n>>e;
	cin>>k;
	
	for(int i=0;i<e;i++){
        cin>>start>>dest>>weight;
		node[start].push_back({dest,weight});
	}
	
	for(int i=1;i<=n;i++)
		dist[i] = INF;
	
	dist[k] = 0;
	
	pq.push(make_pair(0,k));
	
	while(!pq.empty()){
		int tempW = pq.top().first;
		int tempV = pq.top().second;
		pq.pop();
		
		for(int i=0;i<node[tempV].size();i++){
			int V = node[tempV][i].first;
			int W = node[tempV][i].second;
			
			if(tempW+W<dist[V]){
				dist[V] = tempW+W;
				pq.push(make_pair(tempW+W,V));
			}
		}
	}
	
	for(int i=1;i<=n;i++)
		if(dist[i]==INF) printf("INF\n");
		else printf("%d\n",dist[i]);
	
	return 0;
}
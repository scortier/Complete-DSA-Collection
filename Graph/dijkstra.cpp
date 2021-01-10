int n,m;cin>>n>>m;
for(int i=0;i<m;i++){
	ll a,b,c;cin>>a>>b>>c;
	v[a].pb({b,c});
	v[b].pb({a,c});
}
for(int i=1;i<=n;i++){
	dis[i]=inf;
}
ll src;cin>>src;
dis[src]=0;
set<pair<int,int>>s;
s.insert({0,src});
while(!s.empty()){
	pair<int,int> x=*s.begin();
	s.erase(s.begin());
	int from=x.second;
	for(pair<int,int> i:v[from]){
		int to=i.first;
		int wt=i.second;
		if(dis[to]>dis[from]+wt){
		if(dis[to]!=inf){
				s.erase(s.find({dis[to],to}));
			}
			dis[to]=wt+dis[from];
			s.insert({dis[to],to});
		}
	}
}
pr(dis,1,n+1);e;

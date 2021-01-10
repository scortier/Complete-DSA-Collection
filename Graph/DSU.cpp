#define MAX 20001
int par[MAX], sz[MAX];
void init(int v) {
	par[v] = v;
	sz[v] = 1;
}
int find(int v) {
	return v == par[v] ? v : par[v] = find(par[v]);
}
void join(int u, int v) {
	u = find(u), v = find(v);
	if(u != v) {
		if(sz[u] < sz[v]) swap(u, v);
		par[v] = u;
		sz[u] += sz[v];
	}
}
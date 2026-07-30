class DisjointSet{

public:

vector<int> parent,rank,size;

DisjointSet(int n){

    parent.resize(n+1);
    rank.resize(n+1,0);
    size.resize(n+1,1);

    for(int i=0;i<=n;i++)
        parent[i]=i;
}

int find(int node){

    if(parent[node]==node)
        return node;

    return parent[node]=find(parent[node]);
}

void unionByRank(int u,int v){

    u=find(u);
    v=find(v);

    if(u==v) return;

    if(rank[u]<rank[v])
        parent[u]=v;

    else if(rank[v]<rank[u])
        parent[v]=u;

    else{
        parent[v]=u;
        rank[u]++;
    }
}

void unionBySize(int u,int v){

    u=find(u);
    v=find(v);

    if(u==v) return;

    if(size[u]<size[v]){
        parent[u]=v;
        size[v]+=size[u];
    }
    else{
        parent[v]=u;
        size[u]+=size[v];
    }
}
};

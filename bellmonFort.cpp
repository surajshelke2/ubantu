#include<iostream>
#include<vector>
using namespace std;


class solution {

    public:


vector<int> bellmonFortAlgo(int V,vector<vector<int>>&edges , int s)
{
    vector<int>dist(V,1e8);
    dist[0]=0;

    for (int i = 0; i < V-1; i++)
    {
        for(auto it:edges)
        {
            int u= it[0];
            int v =it[1];
            int wt =it[2];

            if(dist[u]!=1e8 && dist[u]+wt < dist[v])
            {
                dist[v]=dist[u]+wt;
            }
        }
        
        
    }


     for(auto it:edges)
        {
            int u= it[0];
            int v =it[1];
            int wt =it[2];

            if(dist[u]!=1e8 && dist[u]+wt < dist[v])
            {
               
               return {-1};
            }
        }
        return dist;
    
}


};




int main()
{
    int V =6;

    vector<vector<int>>edges(7,vector<int>(3));

    edges[0]={0,1,5};
    edges[1]={1,2,-2};
    edges[2]={2,4,3};
    edges[3]={3,2,6};
    edges[4]={3,4,-2};
    edges[5]={5,3,1};
    edges[6]={1,5,-3};


    vector<int>S;
    solution obj;
    int start=0;
    S=obj.bellmonFortAlgo(V,edges,start);

    for(auto i:S){
        cout<<i<<" ";
    }
}
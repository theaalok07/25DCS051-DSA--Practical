
#include <iostream>
using namespace std;

int graph[10][10];
int visited[10];
int n;

void DFS(int node)
{
    cout<<node<<" ";
    visited[node]=1;

    for(int i=0;i<n;i++)
    {
        if(graph[node][i]==1 && visited[i]==0)
        {
            DFS(i);
        }
    }
}

void BFS(int start)
{
    int q[10];
    int front=0;
    int rear=0;

    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }

    q[rear++]=start;
    visited[start]=1;

    while(front<rear)
    {
        int node=q[front++];
        cout<<node<<" ";

        for(int i=0;i<n;i++)
        {
            if(graph[node][i]==1 && visited[i]==0)
            {
                q[rear++]=i;
                visited[i]=1;
            }
        }
    }
}

int main()
{
    int edges;
    int u,v;
    int start;

    cout<<"Enter number of buildings: ";
    cin>>n;

    cout<<"Enter number of roads: ";
    cin>>edges;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            graph[i][j]=0;
        }
    }

    for(int i=0;i<edges;i++)
    {
        cout<<"Enter connected buildings: ";
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }

    cout<<"Enter starting building: ";
    cin>>start;

    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }

    cout<<"DFS: ";
    DFS(start);

    cout<<endl;

    cout<<"BFS: ";
    BFS(start);

    cout<<endl;

    return 0;
}

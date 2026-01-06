#include <stdio.h>

int q[10], front=0, rear=0;
int adj[10][10], visited[10];

int main(){
    int n,i,j,start;
    printf("Enter number of nodes: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&adj[i][j]);

    printf("Enter starting node: ");
    scanf("%d",&start);

    q[rear++]=start;
    visited[start]=1;

    while(front<rear){
        int v=q[front++];
        printf("%d ",v);
        for(i=0;i<n;i++){
            if(adj[v][i]==1 && visited[i]==0){
                q[rear++]=i;
                visited[i]=1;
            }
        }
    }
    return 0;
}

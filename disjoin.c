#include <stdio.h>

int parent[10];

int find(int x){
    if(parent[x]==x)
        return x;
    return find(parent[x]);
}

void unionSet(int a,int b){
    int pa=find(a);
    int pb=find(b);
    parent[pb]=pa;
}

int main(){
    int n,i,a,b;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
        parent[i]=i;

    printf("Enter two elements to union: ");
    scanf("%d%d",&a,&b);
    unionSet(a,b);

    for(i=0;i<n;i++)
        printf("Parent of %d = %d\n",i,find(i));

    return 0;
}

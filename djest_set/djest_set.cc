#include <stdio.h>
#include <stdlib.h>
/* 用来合并不相交集合的数据结构，如用来检测一个图里是否存在环
 * 如果并查集恰巧形成了一条链，我们需要压缩路径。
 * 改变一下union_vertices中链接根结点的方式
 */

#define VERTICES 6

void initialise(int *parent, int * rank)
{
    for(int i=0; i != VERTICES; ++i)
    {
        parent[i] = -1;
        rank[i] = 0;
    }
}

int find_root(int x, int* parent)
{
    int x_root = x;
    while(parent[x_root] != -1)
    {
        x_root = parent[x_root];
    }
    return x_root;
}

/*返回1，表示合并成功。返回0，表示合并失败，即两个点在同一集合*/
int union_vertices(int x, int y, int * parent, int *rank)
{
    int x_root = find_root(x, parent);
    int y_root = find_root(y, parent);
    if(x_root != y_root)
    {
        if(rank[x_root] > rank[y_root])
        {
            parent[y_root] = x_root;
        }else if(rank[y_root] > rank[x_root]){
            parent[x_root] = y_root;
        }else{
            parent[x_root] = y_root;
            ++rank[y_root];
        }
        return 1;
    }else{
        return 0;
    }
}

int main()
{
    int parent[VERTICES] = {0};
    int rank[VERTICES] = {0};
    initialise(parent, rank);
    int edges[6][2] = {
        {0,1}, {1,2}, {1,3},
        {2,4}, {3,4}, {2,5}
    };
    //这里6表示边的数量
    for(int i=0;i != 6; ++i)
    {
        int x = edges[i][0];
        int y = edges[i][1];
        if(union_vertices(x,y,parent,rank) == 0)
        {
            printf("cycle detected\n");
            exit(0);
        }
    }
    printf("no cycle\n");
    return 0;
}

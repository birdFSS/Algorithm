#ifndef __MYGRAPH_H__
#define __MYGRAPH_H__

#include "Queue.h"
#include <stdio.h>
#define INFINITY_MAX 65536

typedef struct
{
    VertexType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numVertexs, numEdges;
}MGraph;



void TestGraph(MGraph *G);
void createGraph(MGraph* G);
void DFSTraverse(MGraph G);
//void DFS(MGraph G, int i);
void BFSTraverse(MGraph G);

void TestGraph(MGraph *G)
{
    int i,j;
    G->numVertexs = 6;
    for(i=0; i < G->numVertexs; i++)
    {
        G->vexs[i] = 'a' + i;
    }
    for(i=0;i < G->numVertexs; i++)
    {
        for(j=0; j<G->numVertexs; j++)
        {
            G->arc[i][j] = INFINITY_MAX;
        }
    }
    G->arc[0][1] = 1;  G->arc[1][0] = 1;
    G->arc[0][3] = 1;  G->arc[3][0] = 1;
    G->arc[0][4] = 1;  G->arc[4][0] = 1;
    G->arc[1][4] = 1;  G->arc[4][1] = 1;
    G->arc[2][3] = 1;  G->arc[3][2] = 1;
    G->arc[1][5] = 1;  G->arc[5][1] = 1;
}

void createGraph(MGraph* G)
{
    int i,j,k,w;
    printf("请输入顶点的个数和边的个数:\n");
    scanf("%d %d", &G->numVertexs, &G->numEdges);
    for(i=0; i < G->numVertexs; i++)
    {
        scanf("%c",&G->vexs[i]);
    }
    /*初始化*/
    for(i=0;i < G->numVertexs; i++)
    {
        for(j=0; j<G->numVertexs; j++)
        {
            G->arc[i][j] = INFINITY_MAX;
        }
    }

    for(k=0;k<G->numEdges;k++)
    {
        printf("请输入边(vi,vj)的下标i和j 和权w：\n");
        scanf("%d %d %d", &i, &j, &w);
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];
    }
}



void DFS(MGraph G, int i)
{
    Boolean visited[MAXVEX];
    int j;
    visited[i] = TRUE;
    printf("%5d --- %-5c\n", i, G.vexs[i]);
    for(j=0;j<G.numVertexs;j++)
    {
        if(G.arc[i][j] == 1 && !visited[j])
        {
            DFS(G, j);
        }
    }
}

void DFSTraverse(MGraph G)
{
    Boolean visited[MAXVEX];
    int i;
    for(i=0;i<G.numVertexs;i++)
    {
        visited[i] = FALSE;
    }
    printf(">>vertex\nindex --- value\n");
    for(i=0;i<G.numVertexs; i++)
    {
        if(!visited[i])
        {
            DFS(G, i);
        }
    }
    printf("<<vertex\n");
}

void BFSTraverse(MGraph G)
{
    Boolean visited[MAXVEX];
    int i,j;
    Queue Q;
    initQueue(&Q);
    for(i=0;i<G.numVertexs;i++)
    {
        visited[i] = FALSE;
    }

    printf(">>vertex in BFS\n");
    for(i=0;i<G.numVertexs;i++)
    {
        if(!visited[i])
        {
            visited[i] = TRUE;
            printf("%5d --- %-5c\n", i, G.vexs[i]);
            enQueue(&Q, i);

            while(!isQueueEmpty(Q))
            {
                deQueue(&Q, &i);
                for(j=0;j<G.numVertexs;j++)
                {
                    if(G.arc[i][j] == 1 && !visited[j])
                    {
                        visited[j] = TRUE;
                        printf("%5d --- %-5c\n", j, G.vexs[j]);
                        enQueue(&Q, j);
                    }
                }
            }//while(!isQueueEmpty)
        }//if(!visited[i])
    }//for(i=0;i<G.numVertexs;i++)
    printf("<<vertex out BFS\n");
}










#endif






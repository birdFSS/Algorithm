#include "Graph_array.h"
#include <func.h>


void test1()
{
    MGraph g1;
    TestGraph(&g1);
    DFSTraverse(g1);
}

void test2()
{
    MGraph g2;
    TestGraph(&g2);
    BFSTraverse(g2);
}

int main(void)
{
    test2();    
    return 0;
}


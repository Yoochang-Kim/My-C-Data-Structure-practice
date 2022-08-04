#include <stdio.h>
#include "AVLGraph.h"

int main(void){
    AVLGraph graph; //그래프의 생성
    GraphInit(&graph, 5); //그래프 초기화

    AddEdge(&graph,A,B);
    AddEdge(&graph,A,D);
    AddEdge(&graph,B,C);
    AddEdge(&graph,C,D);
    AddEdge(&graph,D,E);
    AddEdge(&graph,E,A);

    ShowGraphEdgeInfo(&graph);
    GraphDestroy(&graph);
    return 0;


}
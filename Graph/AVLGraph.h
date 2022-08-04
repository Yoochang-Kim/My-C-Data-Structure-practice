#pragma once

#include "DLinkedList.h"


enum{A,B,C,D,E,F,G,H,I,J};


typedef struct _ual
{
    int numV;/* 정점의 수 */
    int numE;/* 간선의 수 */
    List * adjList; /* 간선의 정보 */
}AVLGraph;

/* 그래프 초기화 */
void GraphInit(AVLGraph * pg, int nv);

/* 그래프의 리소스 해제 */
void GraphDestroy(AVLGraph * pg);

/* 간선의 추가 */
void AddEdge(AVLGraph * pg, int fromV, int toV);

/* 간선의 정보 출력 */
void ShowGraphEdgeInfo(AVLGraph * pg);

int WhoIsPrecede(int d1, int d2);



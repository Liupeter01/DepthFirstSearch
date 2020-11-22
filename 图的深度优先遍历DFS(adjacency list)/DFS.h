#pragma once
#include"ALGraph.h"
#include"LinkStack.h"		  //链式栈

#define STACK				  //使用栈

void InitVisit(ALGraph G, BOOL** visit);			  //初始化DFS算法辅助数组
void DestroyVisitArray(BOOL* visit);			  //DFS算法辅助数组的销毁
void DFSTraverse(ALGraph G, VertexType V);		  //DFS深度优先遍历函数
void DFS(ALGraph G, LinkStack stack, BOOL* visit, VertexType V);		   //DFS基于模拟栈的实现
void Recursive_DFS(ALGraph G, BOOL* visit, VertexType V);				  //DFS基于递归的实现
#pragma once
#include"MGraph.h"
#include"LinkStack.h"

//#define STACK				  //使用栈

void InitVisitArray(MGraph G, BOOL** visit);			  //初始化DFS算法辅助数组
void DestroyVisitArray(BOOL* visit);		//DFS算法辅助数组的销毁

void DFSTraverse(MGraph G, VertexType V);		  //DFS深度优先遍历函数
void DFS(MGraph G, LinkStack stack, BOOL* visit, VertexType V);		   //DFS基于模拟栈的实现
void Recursive_DFS(MGraph G, BOOL* visit, VertexType V);				  //DFS基于递归的实现
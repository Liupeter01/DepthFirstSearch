#pragma once
#include"ALGraph.h"
#include"LinkStack.h"		  //��ʽջ

#define STACK				  //ʹ��ջ

void InitVisit(ALGraph G, BOOL** visit);			  //��ʼ��DFS�㷨��������
void DestroyVisitArray(BOOL* visit);			  //DFS�㷨�������������
void DFSTraverse(ALGraph G, VertexType V);		  //DFS������ȱ�������
void DFS(ALGraph G, LinkStack stack, BOOL* visit, VertexType V);		   //DFS����ģ��ջ��ʵ��
void Recursive_DFS(ALGraph G, BOOL* visit, VertexType V);				  //DFS���ڵݹ��ʵ��
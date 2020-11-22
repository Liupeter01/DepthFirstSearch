#pragma once
#include"MGraph.h"
#include"LinkStack.h"

//#define STACK				  //ʹ��ջ

void InitVisitArray(MGraph G, BOOL** visit);			  //��ʼ��DFS�㷨��������
void DestroyVisitArray(BOOL* visit);		//DFS�㷨�������������

void DFSTraverse(MGraph G, VertexType V);		  //DFS������ȱ�������
void DFS(MGraph G, LinkStack stack, BOOL* visit, VertexType V);		   //DFS����ģ��ջ��ʵ��
void Recursive_DFS(MGraph G, BOOL* visit, VertexType V);				  //DFS���ڵݹ��ʵ��
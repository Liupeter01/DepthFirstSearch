#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<Windows.h>

#define ElemType char

typedef struct StackNode
{
		  ElemType data;						  //������
		  struct StackNode* next;		//ָ����
}StackNode,*LinkStack;

void InitLinkStack(LinkStack* lstack);	//��ʼ����ʽջ
void DestroyLinkStack(LinkStack* lstack);	//�ݻ���ʽջ
BOOL isEmpty(LinkStack lstack);		// �пղ���
int length(LinkStack lstack);	//��ջ�Ĵ�С
ElemType GetTop(LinkStack lstack);//���ջ��Ԫ��

/*��ջ��ջ����*/
void Push_Stack(LinkStack*lstack,ElemType data);	//��ջ
void Pop_Stack(LinkStack* lstack, ElemType *x);	//��ջ
#include"DFS.h"

void InitVisit(ALGraph G, BOOL** visit)			  //��ʼ��DFS�㷨��������
{
		  *visit = (BOOL*)malloc(sizeof(BOOL) * G.vexnum);
		  assert(*visit != NULL);
		  memset(*visit, FALSE, sizeof(BOOL) * G.vexnum);
}

void DestroyVisitArray(BOOL* visit)			  //DFS�㷨�������������
{
		  free(visit);
}

void DFSTraverse(ALGraph G, VertexType V)		  //DFS������ȱ�������
{
		  BOOL* visit = NULL; //������������
		  InitVisit(G, &visit);					  //��ʼ����������

#ifdef STACK		//���ʹ��ջ���Զ�����
		  LinkStack stack;	  //ջ
		  InitLinkStack(&stack);
		  DFS(G, stack, visit, V);				  //�ȱ���һ��
#endif // �ж��Ƿ�Ԥ������ģ��ջ

		  for (int i = 0; i < G.vexnum; ++i)				//�������ͨͼ������
		  {
					if (!visit[i])					//���û�б����ʹ�
					{
							  #ifndef STACK
										Recursive_DFS(G, visit, G.Vetics[i].data);		//�ݹ����
							  #endif //��ʹ��ģ��ջĬ�Ͽ����ݹ�

							  #ifdef STACK	
										DFS(G, stack, visit, G.Vetics[i].data);		  //ģ��ջ
							  #endif //�ж��Ƿ�Ԥ������ģ��ջ
					}
		  }
#ifdef STACK	 
		DestroyLinkStack(&stack);
#endif // �ж��Ƿ�Ԥ������ģ��ջ

		DestroyVisitArray(visit);				  //�ݻ�
		printf("END\n");
}

void DFS(ALGraph G, LinkStack stack, BOOL* visit, VertexType V)		   //DFS����ģ��ջ��ʵ��
{
		  visit[LocateVertex(G, V)] = TRUE;		  //�ö����Ѿ���������
		  Push_Stack(&stack, V);		//��ջ
		  while (!isEmpty(stack))
		  {
					VertexType temp;
					Pop_Stack(&stack, &temp);
					printf("%c-->", temp);
					for (int i = FindFirstNeighbor(G, V); i != -1; i = FindNextNeighbor(G, V, G.Vetics[i].data))
					{
							  if (!visit[i])				  //���û�б����ʹ�
							  {
										visit[i] = TRUE;		  //�ö����Ѿ���������
										Push_Stack(&stack, G.Vetics[i].data);
							  }
					}
		  }
}

void Recursive_DFS(ALGraph G, BOOL* visit, VertexType V)//DFS���ڵݹ��ʵ��
{
		  printf("%c-->", V);
		  visit[LocateVertex(G, V)] = TRUE;		  //�ö����Ѿ���������
		  for (int i = FindFirstNeighbor(G, V); i != -1; i = FindNextNeighbor(G, V, G.Vetics[i].data))
		  {
					if (!visit[i])				  //���û�б����ʹ�
					{
							  Recursive_DFS(G, visit, G.Vetics[i].data);				  //�ݹ����
					}
		  }
}
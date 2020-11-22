#include"DFS.h"

void InitVisitArray(MGraph G, BOOL** visit)			  //��ʼ��DFS�㷨��������
{
          *visit = (BOOL*)malloc(sizeof(BOOL) * G.vexnum);
          memset(*visit, FALSE, sizeof(BOOL) * G.vexnum);
}

void DestroyVisitArray(BOOL* visit)	//DFS�㷨�������������
{
          free(visit);
}

void DFSTraverse(MGraph G, VertexType V)		  //DFS������ȱ�������
{
          BOOL* visit = NULL; //������������
          InitVisitArray(G, &visit);					  //��ʼ����������

#ifdef STACK		//���ʹ��ջ���Զ�����
          LinkStack stack;	  //ջ
          InitLinkStack(&stack);
#endif // �ж��Ƿ�Ԥ������ģ��ջ

          for (int i = 0; i < G.vexnum; ++i)				//�������ͨͼ������
          {
                    if (!visit[i])					//���û�б����ʹ�
                    {
                              #ifndef STACK
                                        Recursive_DFS(G, visit, G.Vex[i]);		//�ݹ����
                              #endif //��ʹ��ģ��ջĬ�Ͽ����ݹ�

                              #ifdef STACK	
                                        DFS(G, stack, visit, G.Vex[i]);		  //ģ��ջ
                              #endif //�ж��Ƿ�Ԥ������ģ��ջ
                    }
          }
#ifdef STACK	 
          DestroyLinkStack(&stack);
#endif // �ж��Ƿ�Ԥ������ģ��ջ

          DestroyVisitArray(visit);				  //�ݻ�
          printf("END\n");
}

void DFS(MGraph G, LinkStack stack, BOOL* visit, VertexType V)		   //DFS����ģ��ջ��ʵ��
{
          visit[LocateVertex(G, V)] = TRUE;        //����V��λ���Ѿ�������
          Push_Stack(&stack, V);
          while (!isEmpty(stack))
          {
                    VertexType temp;
                    Pop_Stack(&stack, &temp);
                    printf("%c-->", temp);
                    for (int pos = FindFirstNeighbor(G, temp); pos != -1; pos = FindNextNeighbor(G, temp, G.Vex[pos]))      //�����ڽӵ�
                    {
                              if (!visit[pos])            //visit�����л�û�б����ʹ�
                              {
                                        visit[pos] = TRUE;        //�Ѿ����ʹ�
                                        Push_Stack(&stack, G.Vex[pos]);      //ֻҪ����û�з��ʹ��ľ���ջ
                              }
                    }
          }
}

void Recursive_DFS(MGraph G, BOOL* visit, VertexType V)			  //DFS���ڵݹ��ʵ��
{
          printf("%c-->", V);
          visit[LocateVertex(G, V)] = TRUE;        //����V��λ���Ѿ�������
          for (int pos = FindFirstNeighbor(G, V); pos != -1; pos = FindNextNeighbor(G, V, G.Vex[pos]))      //�����ڽӵ�
          {
                    if (!visit[pos])            //visit�����л�û�б����ʹ�
                    {
                              Recursive_DFS(G, visit, G.Vex[pos]);
                    }
          }
}
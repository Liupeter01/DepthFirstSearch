#include"DFS.h"

void InitVisit(ALGraph G, BOOL** visit)			  //初始化DFS算法辅助数组
{
		  *visit = (BOOL*)malloc(sizeof(BOOL) * G.vexnum);
		  assert(*visit != NULL);
		  memset(*visit, FALSE, sizeof(BOOL) * G.vexnum);
}

void DestroyVisitArray(BOOL* visit)			  //DFS算法辅助数组的销毁
{
		  free(visit);
}

void DFSTraverse(ALGraph G, VertexType V)		  //DFS深度优先遍历函数
{
		  BOOL* visit = NULL; //创建辅助数组
		  InitVisit(G, &visit);					  //初始化辅助数组

#ifdef STACK		//如果使用栈则自动开启
		  LinkStack stack;	  //栈
		  InitLinkStack(&stack);
		  DFS(G, stack, visit, V);				  //先遍历一次
#endif // 判断是否预定义了模拟栈

		  for (int i = 0; i < G.vexnum; ++i)				//解决非连通图的问题
		  {
					if (!visit[i])					//如果没有被访问过
					{
							  #ifndef STACK
										Recursive_DFS(G, visit, G.Vetics[i].data);		//递归调用
							  #endif //不使用模拟栈默认开启递归

							  #ifdef STACK	
										DFS(G, stack, visit, G.Vetics[i].data);		  //模拟栈
							  #endif //判断是否预定义了模拟栈
					}
		  }
#ifdef STACK	 
		DestroyLinkStack(&stack);
#endif // 判断是否预定义了模拟栈

		DestroyVisitArray(visit);				  //摧毁
		printf("END\n");
}

void DFS(ALGraph G, LinkStack stack, BOOL* visit, VertexType V)		   //DFS基于模拟栈的实现
{
		  visit[LocateVertex(G, V)] = TRUE;		  //该顶点已经被访问了
		  Push_Stack(&stack, V);		//入栈
		  while (!isEmpty(stack))
		  {
					VertexType temp;
					Pop_Stack(&stack, &temp);
					printf("%c-->", temp);
					for (int i = FindFirstNeighbor(G, V); i != -1; i = FindNextNeighbor(G, V, G.Vetics[i].data))
					{
							  if (!visit[i])				  //如果没有被访问过
							  {
										visit[i] = TRUE;		  //该顶点已经被访问了
										Push_Stack(&stack, G.Vetics[i].data);
							  }
					}
		  }
}

void Recursive_DFS(ALGraph G, BOOL* visit, VertexType V)//DFS基于递归的实现
{
		  printf("%c-->", V);
		  visit[LocateVertex(G, V)] = TRUE;		  //该顶点已经被访问了
		  for (int i = FindFirstNeighbor(G, V); i != -1; i = FindNextNeighbor(G, V, G.Vetics[i].data))
		  {
					if (!visit[i])				  //如果没有被访问过
					{
							  Recursive_DFS(G, visit, G.Vetics[i].data);				  //递归调用
					}
		  }
}
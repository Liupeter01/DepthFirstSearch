#include"DFS.h"

void InitVisitArray(MGraph G, BOOL** visit)			  //初始化DFS算法辅助数组
{
          *visit = (BOOL*)malloc(sizeof(BOOL) * G.vexnum);
          memset(*visit, FALSE, sizeof(BOOL) * G.vexnum);
}

void DestroyVisitArray(BOOL* visit)	//DFS算法辅助数组的销毁
{
          free(visit);
}

void DFSTraverse(MGraph G, VertexType V)		  //DFS深度优先遍历函数
{
          BOOL* visit = NULL; //创建辅助数组
          InitVisitArray(G, &visit);					  //初始化辅助数组

#ifdef STACK		//如果使用栈则自动开启
          LinkStack stack;	  //栈
          InitLinkStack(&stack);
#endif // 判断是否预定义了模拟栈

          for (int i = 0; i < G.vexnum; ++i)				//解决非连通图的问题
          {
                    if (!visit[i])					//如果没有被访问过
                    {
                              #ifndef STACK
                                        Recursive_DFS(G, visit, G.Vex[i]);		//递归调用
                              #endif //不使用模拟栈默认开启递归

                              #ifdef STACK	
                                        DFS(G, stack, visit, G.Vex[i]);		  //模拟栈
                              #endif //判断是否预定义了模拟栈
                    }
          }
#ifdef STACK	 
          DestroyLinkStack(&stack);
#endif // 判断是否预定义了模拟栈

          DestroyVisitArray(visit);				  //摧毁
          printf("END\n");
}

void DFS(MGraph G, LinkStack stack, BOOL* visit, VertexType V)		   //DFS基于模拟栈的实现
{
          visit[LocateVertex(G, V)] = TRUE;        //顶点V的位置已经被访问
          Push_Stack(&stack, V);
          while (!isEmpty(stack))
          {
                    VertexType temp;
                    Pop_Stack(&stack, &temp);
                    printf("%c-->", temp);
                    for (int pos = FindFirstNeighbor(G, temp); pos != -1; pos = FindNextNeighbor(G, temp, G.Vex[pos]))      //查找邻接点
                    {
                              if (!visit[pos])            //visit数组中还没有被访问过
                              {
                                        visit[pos] = TRUE;        //已经访问过
                                        Push_Stack(&stack, G.Vex[pos]);      //只要存在没有访问过的就入栈
                              }
                    }
          }
}

void Recursive_DFS(MGraph G, BOOL* visit, VertexType V)			  //DFS基于递归的实现
{
          printf("%c-->", V);
          visit[LocateVertex(G, V)] = TRUE;        //顶点V的位置已经被访问
          for (int pos = FindFirstNeighbor(G, V); pos != -1; pos = FindNextNeighbor(G, V, G.Vex[pos]))      //查找邻接点
          {
                    if (!visit[pos])            //visit数组中还没有被访问过
                    {
                              Recursive_DFS(G, visit, G.Vex[pos]);
                    }
          }
}
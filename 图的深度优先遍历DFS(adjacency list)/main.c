#include"ALGraph.h"
#include"DirectEdge.h"       //有向图
#include"UnDirectEdge.h"    //无向图
#include"DFS.h"

int main()
{
          ALGraph Graph;
          InitGraph(&Graph);         //初始化

            /*顶点列表批量添加*/
          VertexType arr[] = { "ABCDEFGH" };
          CreateBatchVertex(&Graph, arr);      //顶点列表批量添加

          VertexType arr1[] = "AABBDECCF";
          VertexType arr2[] = "BCDEHHFGG";

          for (size_t i = 0; i < strlen(arr1); ++i)
          {
                    InsertUnDirectEdge(&Graph, *(arr1 + i), *(arr2 + i));
          }

          DisplayGraph(Graph);          //图的输出
          DFSTraverse(Graph, 'D');

          DestroyGraph(&Graph);         //图的销毁
          return 0;
}
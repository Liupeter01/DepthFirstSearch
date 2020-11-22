#include"MGraph.h"
#include"DirectedEdge.h"                   //有向图
#include"UnDirectedEdge.h"              //无向图
#include"DFS.h"                                  //深度优先遍历DFS

int main()
{
          MGraph Graph;
          InitGraph(&Graph);         //初始化

          /*顶点列表批量添加*/
          VertexType arr[] = { "ABCDEFGH" };
          CreateBatchVertex(&Graph, arr, NORMALGRAPH);      //顶点列表批量添加

          VertexType arr1[] = "AABBDECCF";
          VertexType arr2[] = "BCDEHHFGG";

          for (size_t i = 0; i < strlen(arr1); ++i)
          {
                    InsertUnDirectEdge(&Graph, *(arr1 + i), *(arr2 + i));
          }

          DisplayGraph(Graph);          //图的输出
          DFSTraverse(Graph, 'A');                //DFS

          DestroyGraph(&Graph);         //图的销毁
          return 0;
}
#include"MGraph.h"
#include"DirectedEdge.h"                   //����ͼ
#include"UnDirectedEdge.h"              //����ͼ
#include"DFS.h"                                  //������ȱ���DFS

int main()
{
          MGraph Graph;
          InitGraph(&Graph);         //��ʼ��

          /*�����б��������*/
          VertexType arr[] = { "ABCDEFGH" };
          CreateBatchVertex(&Graph, arr, NORMALGRAPH);      //�����б��������

          VertexType arr1[] = "AABBDECCF";
          VertexType arr2[] = "BCDEHHFGG";

          for (size_t i = 0; i < strlen(arr1); ++i)
          {
                    InsertUnDirectEdge(&Graph, *(arr1 + i), *(arr2 + i));
          }

          DisplayGraph(Graph);          //ͼ�����
          DFSTraverse(Graph, 'A');                //DFS

          DestroyGraph(&Graph);         //ͼ������
          return 0;
}
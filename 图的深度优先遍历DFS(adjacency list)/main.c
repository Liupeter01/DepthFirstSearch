#include"ALGraph.h"
#include"DirectEdge.h"       //����ͼ
#include"UnDirectEdge.h"    //����ͼ
#include"DFS.h"

int main()
{
          ALGraph Graph;
          InitGraph(&Graph);         //��ʼ��

            /*�����б��������*/
          VertexType arr[] = { "ABCDEFGH" };
          CreateBatchVertex(&Graph, arr);      //�����б��������

          VertexType arr1[] = "AABBDECCF";
          VertexType arr2[] = "BCDEHHFGG";

          for (size_t i = 0; i < strlen(arr1); ++i)
          {
                    InsertUnDirectEdge(&Graph, *(arr1 + i), *(arr2 + i));
          }

          DisplayGraph(Graph);          //ͼ�����
          DFSTraverse(Graph, 'D');

          DestroyGraph(&Graph);         //ͼ������
          return 0;
}
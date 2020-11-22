#include"ALGraph.h"
#include"DirectEdge.h"       //����ͼ
#include"UnDirectEdge.h"    //����ͼ
#include"DFS.h"

int main()
{
          ALGraph Graph;
          InitGraph(&Graph);         //��ʼ��

            /*�����б��������*/
          VertexType arr[] = { "ABCDEFGHIJKLM" };         //�������鼯��V(G)
          CreateBatchVertex(&Graph, arr);      //�����б��������

          VertexType arr1[] = "AAAABLLJDGGGH";
          VertexType arr2[] = "BCFLMJMMEHIKK";

          for (size_t i = 0; i < strlen(arr1); ++i)
          {
                    InsertUnDirectEdge(&Graph, *(arr1 + i), *(arr2 + i));
          }

          DisplayGraph(Graph);          //ͼ�����
          DFSTraverse(Graph, 'D');

          DestroyGraph(&Graph);         //ͼ������
          return 0;
}
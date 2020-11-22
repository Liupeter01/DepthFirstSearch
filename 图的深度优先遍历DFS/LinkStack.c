#include"LinkStack.h"

void InitLinkStack(LinkStack* lstack)	//��ʼ����ʽջ
{
		  (*lstack) = (LinkStack)malloc(sizeof(StackNode));	//ͷ���
		  assert((*lstack) != NULL);
		  (*lstack)->next = NULL;
}

void DestroyLinkStack(LinkStack* lstack)	//�ݻ���ʽջ
{
		  free((*lstack));
		  (*lstack)->next = NULL;
}

BOOL isEmpty(LinkStack lstack)		// �пղ���
{
		  return lstack->next == NULL;			  //ֻ��һ��ͷ���
}

int length(LinkStack lstack)	//��ջ�Ĵ�С
{
		  StackNode* p = lstack->next;
		  int counter = 0;
		  while (p != NULL)
		  {
					counter++;
					p = p->next;
		  }
		  return counter;
}

ElemType GetTop(LinkStack lstack)//���ջ��Ԫ��
{
		  return lstack->next->data;
}

void Push_Stack(LinkStack* lstack, ElemType data)	//��ջ
{
		  LinkStack s = (LinkStack)malloc(sizeof(StackNode));					//�����µĽ��
		  assert(s != NULL);
		  s->data = data;
		  s->next = NULL;
		  if ((*lstack)->next == NULL)			  //ֻ��һ��ͷ���
		  {
					StackNode* head = (*lstack);
					head->next = s;
		  }
		  else
		  {
					StackNode* head = (*lstack);
					s->next = head->next;
					head->next = s;
		  }
}

void Pop_Stack(LinkStack* lstack, ElemType* x)	//��ջ
{
		  if (!isEmpty(*lstack))				  //�ǿ�״̬
		  {
					StackNode* temp = (*lstack)->next;		//��ջԪ��
					if (temp->next == NULL)		  //ջֻ��һ��Ԫ����
					{
							  *x = temp->data;	//ȡ������
							  (*lstack)->next = NULL;
					}
					else
					{
							  *x = temp->data;	//ȡ������
							  (*lstack)->next = temp->next; //������ջԪ��
					}
					free(temp);
		  }
		  else
		  {
					printf("��ǰ��ջΪ�գ��޷����г�ջ����\n");
					return;
		  }
}
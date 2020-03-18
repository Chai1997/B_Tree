#include"B_Tree.h"

void Init_Stack(pStack S)
{
	S->pBottom = (pNode)malloc(sizeof(Node));
	if (S->pBottom == NULL)
	{
		printf("STACK 创建失败\n");
	}
	else
	{
		S->pBottom->pNext = NULL;
		S->pTop = S->pBottom;
	}
}
void Push(pStack S, pBTree* pch)
{
	pNode pNew = (pNode)malloc(sizeof(Node));
	if (pNew == NULL)
	{
		printf("STACK 结点创建失败\n");
	}
	else
	{
		pNew->data = *pch;
		pNew->pNext = S->pTop;
		S->pTop = pNew;
	}
}


bool Stack_Empty(pStack S)
{
	if (S->pBottom == S->pTop)
	{
		return true;
	}
	else
	{
		return false;
	}
}
pBTree Pop(pStack S)
{
	if (S->pBottom == S->pTop)
	{
		return -1;
	}
	else
	{
		pBTree pch = S->pTop->data;
		pNode p = S->pTop->pNext;
		free(S->pTop);
		S->pTop = p;
		return pch;
	}
}
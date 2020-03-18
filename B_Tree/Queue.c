#include"B_Tree.h"

void Init_Queue(pQueue Q)
{
	Q->pBase = (pBTree)malloc(sizeof(BTree) * MAXSIZE);
	if (NULL == Q->pBase)
	{
		printf("���д����ռ�ʧ��\n");
	}
	else
	{
		Q->pFront = 0;
		Q->pRear = 0;
	}
}

void En_Queue(pQueue Q, pBTree *p)
{
	if (((Q->pRear + 1) % MAXSIZE) == Q->pFront)
	{
		printf("��������\n");
		return;
	}
	else
	{
		Q->pBase[Q->pRear] = *p;
		Q->pRear = (Q->pRear + 1) % MAXSIZE;
	}
}

pBTree Out_Queue(pQueue Q)
{
	if (Q->pFront == Q->pRear)
	{
		printf("����Ϊ��\n");
		return;
	}
	else
	{
		pBTree* p = &(Q->pBase[Q->pFront]);
		Q->pFront = (Q->pFront + 1) % MAXSIZE;
		return *p;
	}
}

bool Queue_Empty(pQueue Q)
{
	if (Q->pFront == Q->pRear)
	{
		return true;
	}
	else
	{
		return false;
	}
}


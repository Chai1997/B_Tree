#include"B_Tree.h"

void CreatBTree(pBTree* BT)
{
	char ch;
	(void)scanf("%c", &ch);
	(void)getchar();
	if (ch == '#')
	{
		*BT = NULL;
	}
	else
	{
		(*BT) = (pBTree)malloc(sizeof(BTree));
		if ((*BT) == NULL)
		{
			printf("´´½¨Ê§°Ü\n");
		}
		else
		{
			(*BT)->date = ch;
			CreatBTree(&(*BT)->Lchild);
			CreatBTree(&(*BT)->Rchild);
		}	
	}
}

void PreOrderTraverse(pBTree BT)
{
	if (BT == NULL)
	{
		return;
	}
	else
	{
		printf("%c ", BT->date);
		PreOrderTraverse(BT->Lchild);
		PreOrderTraverse(BT->Rchild);
	}
}

void InOrderTraverse(pBTree BT)//·ÇµÝ¹é
{
	Stack S;
	Init_Stack(&S);
	pBTree p = BT;
	if (BT == NULL)
	{
		return;
	}
	else
	{
		while (p || !Stack_Empty(&S))
		{ 
			if (p)
			{
				Push(&S, &p);
				p = p->Lchild;
			}
			else
			{
				pBTree q;
				q = Pop(&S);
				printf("%c", q->date);
				p = q->Rchild;
			}
		}
	}
}
void PostOrderTraverse(pBTree BT)
{
	if (BT == NULL)
	{
		return;
	}
	else
	{
		PostOrderTraverse(BT->Lchild);
		PostOrderTraverse(BT->Rchild);
		printf("%c ", BT->date);
	}
	printf("\n");
}

void SequenceTraverse(pBTree BT)
{
	Queue Q;
	Init_Queue(&Q);
	En_Queue(&Q, &BT);
	while (!Queue_Empty(&Q))
	{
		pBTree p = Out_Queue(&Q);
		printf("%c ",p->date);

		if (p->Lchild != NULL)
			En_Queue(&Q, &(p->Lchild));

		if (p->Rchild != NULL)
			En_Queue(&Q, &(p->Rchild));

	}
} 

int Depth(pBTree BT)
{
	if (NULL == BT)
	{
		return 0;
	}
	else
	{
		int m = Depth(BT->Lchild);
		int n = Depth(BT->Rchild);
		if (m > n)
			return m + 1;
		else
			return n + 1;
	}
}

int num_Node(pBTree BT)
{
	if (BT == NULL)
		return 0;
	return num_Node(BT->Lchild) + num_Node(BT->Rchild) + 1;
}

int LeafNode(pBTree BT)
{
	static int count = 0;
	if (BT == NULL)
	{
		return 0;
	}
	if (NULL == BT->Lchild && NULL == BT->Rchild)
	{
		count++;
	}
	LeafNode(BT->Lchild);
	LeafNode(BT->Rchild);
	return count;
}

int Copy(pBTree BT, pBTree* pNew)
{
	pBTree p = BT;
	if (NULL == BT)
	{
		*pNew = NULL;
	}
	else
	{
		*pNew = (pBTree)malloc(sizeof(BTree));
		if (NULL == *pNew)
			return -1;
		else
		{
			(*pNew)->date = p->date;
			Copy(p->Lchild, &(*pNew)->Lchild);
			Copy(p->Rchild, &(*pNew)->Rchild);
		}
	}
}
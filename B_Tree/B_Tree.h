#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define MAXSIZE 20
#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct BTree
{
	char date;
	struct BTree* Lchild;
	struct BTree* Rchild;
}BTree, *pBTree;

typedef struct Queue
{
	pBTree* pBase;
	int pFront;
	int pRear;
}Queue, *pQueue;

typedef struct Node
{
	pBTree data;
	struct Node* pNext;
}Node, *pNode;

typedef struct Stack
{
	struct Node* pTop;
	struct Node* pBottom;
}Stack, *pStack;

void CreatBTree(pBTree* BT);
void PreOrderTraverse(pBTree BT);
void InOrderTraverse(pBTree BT);
void PostOrderTraverse(pBTree BT);
void SequenceTraverse(pBTree BT);

int Depth(pBTree BT);
int num_Node(pBTree BT);
int LeafNode(pBTree BT);

void Init_Stack(pStack S);
void Push(pStack S, pBTree* pch);
bool Stack_Empty(pStack S);
pBTree Pop(pStack S);


void Init_Queue(pQueue Q);
void En_Queue(pQueue Q, pBTree* p);
pBTree Out_Queue(pQueue Q);
bool Queue_Empty(pQueue Q);
int Copy(pBTree BT, pBTree* pNew);

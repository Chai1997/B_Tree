#include"B_Tree.h"

int main()
{
	pBTree BT;
	pBTree pNew;
	CreatBTree(&BT);
	//PreOrderTraverse(BT);
	//InOrderTraverse(BT);
	//printf("%d\n", Depth(BT));
	//SequenceTraverse(BT);
	Copy(BT, &pNew);
	printf("%d %d", num_Node(pNew), LeafNode(pNew));

	//printf("%d %d", num_Node(BT), LeafNode(BT));
	
	return 0;
}
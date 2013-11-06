
//12
int deep = 0;
void deepAndfloor(Tree* t, int level)
{
	if (t != NULL)
	{
		t->level = level;
		deep = (deep < level) ? level : deep;
		level++;
		deepAndfloor(t->left, level);
		deepAndfloor(t->right, level);
	}
}
deepAndfloor(root, 1); //执行函数

//13
满二叉树为节点最多的情况, 所以最多有:
	2^h-1 个节点, 
除去根节点和最多叶节点, 有:
	[2^h-2-2^(h-1)] = [2^(h-1) - 2] < [2^(h-1) -1] 
即小于 2^(h-1) -1
因为第h层最多有 2^(h-1)个节点, 所以叶节点数小于 2^(h-1)

//14
int MAX = 0;
int findMax(Tree* t, int length)
{
	if (t != NULL)
	{
		length += t->LW;
		findMax(t->left, length);
		length -= t->LW;
		length += t->RW;
		findMax(t->right, length);
	} 
	else 
	{
		return MAX = (length > MAX) ? length : MAX;
	}
}
MW[tree] = findMax(tree, 0);

//16


//34
void ite(Tree* t, int isLeft)
{
	if (t != NULL)
	{
		if (t->left != NULL || t->right != NULL)
			printf("(%d: ", t->data);
		else
			printf("(%d", t->data);
		ite(t->left, 1);
		ite(t->right, 0);
		printf(")");
		if (isLeft)
			printf(", ");
	}
}
ite(root, 0);

//36
typedef struct {
	double weight;
	int left;
	int right;
	int parent
} Node;

Node huffmanT[6];

void selectMin(huffmanT t, int n, int &p1, int &p2)
{
	int i, j;
	for (i = 1;)
}

void initHT(huffmanT T)
{

}

void createHT(huffmanT T)
{

}

void main()
{
	initHT(huffmanT);
	createHT(huffmanT);
}

平均编码长度为：0.27 + 0.23*2 + 0.22*3 + 0.12*4 + (0.09 + 0.07)*5 = 2.67

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
void inorderMorrisTraversal(TreeNode *root) {
    TreeNode *cur = root, *prev = NULL;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            printf("%d ", cur->val);
            cur = cur->right;
        }
        else
        {
            prev = cur->left;
            while (prev->right != NULL && prev->right != cur)
                prev = prev->right;

            if (prev->right == NULL)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else                    
            {
                prev->right = NULL;
                printf("%d ", cur->val);
                cur = cur->right;
            }
        }
    }
}

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
#define n 6
#define m 2*n - 1

typedef struct {
	double weight;
	int left;
	int right;
	int parent
} Node;

Node huffmanT[m];

void selectMin(huffmanT t, int n, int &p1, int &p2)
{
	int i, j;
	for (i = 1; i <= n; i++)
		if (T[i].parent == -1)
		{
			p1 = i;
			break;
		}
	for (j = i + 1; j <= n; j++)
		if (T[j].parent == -1)
		{
			p2 = j;
			break;
		}
	for (i = 1; i <= n; i++)
		if (T[p1].weight > T[i].weight && T[i].parent == -1 && p2 != i)
			p1 = i;
	for (j = 1; j <= n; j++)
		if (T[p2].weight > T[j].weight && T[j].parent == -1 && p1 != j)
			p2 = j;
}

void createHT(huffmanT T)
{
	int i, p1, p2;
	initHT(T);
	for (i = n; i <= m; i++)
	{
		selectMin(T, i-1, p1, p2);
		T[p1].parent = T[p2].parent = i;
		T[i].left = p1;
		T[i].right = p2;
		T[i].weight = T[p1].weight + T[p2].weight;
	}
}

void main()
{
	initHT(huffmanT);
	createHT(huffmanT);
}

huffman tree如下:				
				   1
				   /\
			   0.73  0.27
			   /\
			0.5  0.23
			/\
		0.28  0.22 
		/\
    0.16  0.12	 
	/\
0.07  0.09

平均编码长度为：0.27 + 0.23*2 + 0.22*3 + 0.12*4 + (0.09 + 0.07)*5 = 2.67
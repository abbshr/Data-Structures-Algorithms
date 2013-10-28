#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* addNode(int data, int fath, Node** nodesArr) { //添加子节点
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    if (fath < 0)
        nodesArr[(-fath) - 1]->left = newNode;
    else
        nodesArr[fath - 1]->right = newNode;
    return newNode;
}

void inPrevious(Node* root) { //先序
    if (NULL != root) {
        printf("%d ", root->data);
        inPrevious(root->left);
        inPrevious(root->right);
    }
}

void inMiddle(Node* root) { //中序
    if (NULL != root) {
        inMiddle(root->left);
        printf("%d ", root->data);
        inMiddle(root->right);
    }
}

void inLater(Node* root) { //后序
    if (NULL != root) {
        inLater(root->left);
        inLater(root->right);
        printf("%d ", root->data);
    }
}

void inBlock(Node** nodesArr, int num) {
    int i = 0;
    for (i; i < num; i++)
        printf("%d ", nodesArr[i]->data);
}

void main() {
    int num;
    printf("待插入的节点数:\n");
    scanf("%d", &num);
    int fath;
    int data;
    char lr;
    Node** p = (Node**)malloc(sizeof(Node*) * num);  //p保存依次按编号输入的每个节点的指针
    printf("根节点数据:\n");
    scanf("%d", &data);
    Node* pNode = (Node*) malloc(sizeof(Node));
    pNode->data = data;
    pNode->left = NULL;
    pNode->right = NULL;
    p[0] = pNode;
    int i = 1;
    
    while (i < num) {
        printf("子节点数据\n");
        scanf("%d", &data);
        printf("父节点编号&儿子\n");
        scanf("%d %c", &fath, &lr);
        if (lr == 'l')
            fath = -fath;
        p[i] = addNode(data, fath, p);
        i++;
    }

    printf("先序:");
    inPrevious(p[0]);
    printf("\n");
    printf("中序:");
    inMiddle(p[0]);
    printf("\n");
    printf("后序:");
    inLater(p[0]);
    printf("\n");
    printf("层序:");
    inBlock(p, i);
    printf("\n");
}
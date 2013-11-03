
//4
List* merge(List* head1, List* head2) 
{
    List* p = head1->next, q = head2->next;
    List* c = (List*) malloc(sizeof(List));
    List* d = c; 
    int x;
    while (p != NULL && p != NULL)
    {
        if (p->data > q->data)
        {
            d = attach(p->data, d);
            p = p->next;
        }
        if (p->data < q->data)
        {
            d = attach(q->data, d);
            q = q->next;
        }
        if (p->data = q->data)
        {
            x = p->data + q->data;
            if(x) d = attach(x, d);
            p = p->next;
            q = q->next;
        }
    }
    while (p != NULL)
    {
        d = attach(p->data, d);
        p = p->next;
    }
    while (q != NULL)
    {
        d = attach(q->data, d);
        q = q->next;
    }
    return c;
}

List* attach(int data, List* list)
{
    List* newNode = (List*) malloc(sizeof(List));
    list->next = newNode;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//8
操作步骤为：X S X X X S X S S S X X S X X S X X S S S S

//15
typedef struct Node
{
    int data;
    struct Node* next;
} Node;

void iterate(Node* head)
{
    Node* p = head->next;
    while (p != head->next)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

//18
void queryAndModify(List* head, int x) 
{
    List* p = head->next, * q;
    int i = 0, flag = 0;
    while (p != NULL) 
    {
        i++;
        if (p->data == x) 
        {
            printf("目标元素：%d ,序号:%d\n", x, i);
            flag = 1;
        }
        q = p;
        p = p->next;
    }
    if (!flag)
    {
        List* newNode = (List*) malloc(sizeof(List));
        newNode->data = x;
        newNode->next = NULL;
        q->next = newNode;
    }
}

//19
List* oddAndEven(List* evenHead)
{
    evenHead->data = 0;
    List* oddHead = (List*) malloc(sizeof(List));
    oddHead->next = evenHead->next;
    oddHead->data = 0;
    List* p = oddHead;  //奇数节点
    List* q = evenHead; //偶数节点
    while (p->next != NULL)
    {
        oddHead->data++;
        p = p->next;
        q->next = NULL; //防止偶数链第一节点错位
        if (p->next != NULL)
        {   
            evenHead->data++;
            q->next = p->next;
            p->next = q->next->next;
        }
        q = q->next;
    }
    if (q != NULL) q->next = NULL;
    return oddHead;     //返回奇数节点
}

//22
List* substr(List* head, int m, int n)
{
    List* p = head;
    List* sub = (List*) malloc(sizeof(List));
    List* q = sub, * node = NULL;
    int i = 0, j = 0;
    while (p->next != NULL)
    {
        p = p->next;
        i++;
        if (m == i) j = 1;
        if (j) {
            node = (List*) malloc(sizeof(List));
            q->next = node;
            node->data = p->data;
            node->next = NULL;
            q = q->next;
        }
        if (m + n - 1 == i) break;
    }
    return sub;   //返回一个新的子串
}
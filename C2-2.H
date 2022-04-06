typedef struct LNode
{
    ElemType_Visitor data;
    struct LNode *next;
} LNode, *LinkList;
// typedef struct LNode *LinkList; /* 另一种定义LinkList的方法 */
/* bo2-2.c 单链表线性表(存储结构由c2-2.h定义)的基本操作(12个) */
Status InitList1(LinkList1 *L)
{                                              /* 操作结果：构造一个空的线性表L */
  *L = (LinkList1)malloc(sizeof(struct LNode1)); /* 产生头结点,并使L指向此头结点 */
  if (!(*L))                                   /* 存储分配失败 */
    exit(OVERFLOW);
  (*L)->next = NULL; /* 指针域为空 */
  return OK;
}

Status DestroyList1(LinkList1 *L)
{ /* 初始条件：线性表L已存在。操作结果：销毁线性表L */
  LinkList1 q;
  while (*L)
  {
    q = (*L)->next;
    free(*L);
    *L = q;
  }
  return OK;
}

Status ClearList1(LinkList1 L) /* 不改变L */
{                            /* 初始条件：线性表L已存在。操作结果：将L重置为空表 */
  LinkList1 p, q;
  p = L->next; /* p指向第一个结点 */
  while (p)    /* 没到表尾 */
  {
    q = p->next;
    free(p);
    p = q;
  }
  L->next = NULL; /* 头结点指针域为空 */
  return OK;
}

Status ListEmpty1(LinkList1 L)
{              /* 初始条件：线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
  if (L->next) /* 非空 */
    return FALSE;
  else
    return TRUE;
}

int ListLength1(LinkList1 L)
{ /* 初始条件：线性表L已存在。操作结果：返回L中数据元素个数 */
  int i = 0;
  LinkList1 p = L->next; /* p指向第一个结点 */
  while (p)             /* 没到表尾 */
  {
    i++;
    p = p->next;
  }
  return i;
}

Status GetElem(LinkList1 L, int i, ElemType_vaccine *e) /* 算法2.8 */
{                                                      /* L为带头结点的单链表的头指针。当第i个元素存在时,其值赋给e并返回OK,否则返回ERROR */
  int j = 1;                                           /* j为计数器 */
  LinkList1 p = L->next;                                /* p指向第一个结点 */
  while (p && j < i)                                   /* 顺指针向后查找,直到p指向第i个元素或p为空 */
  {
    p = p->next;
    j++;
  }
  if (!p || j > i) /* 第i个元素不存在 */
    return ERROR;
  *e = p->data; /* 取第i个元素 */
  return OK;
}

Status Get(LinkList1 L, ElemType_vaccine *e) /* 算法2.8 */
{                                           /* L为带头结点的单链表的头指针。当第i个元素存在时,其值赋给e并返回OK,否则返回ERROR */
  int j = 1;                                /* j为计数器 */
  LinkList1 p = L->next;                     /* p指向第一个结点 */
  while (p)                                 /* 顺指针向后查找,直到p指向第i个元素或p为空 */
  {
    p = p->next;
    j++;
  }
  if (!p) /* 第i个元素不存在 */
    return ERROR;
  *e = p->data; /* 取第i个元素 */
  return OK;
}

Status comp(ElemType_vaccine c1, ElemType_vaccine c2)
{
  if (&c1 == &c2)
    return TRUE;
  else
    return FALSE;
}

int LocateElem1(LinkList1 L, ElemType_vaccine e, Status (*compare)(ElemType_vaccine, ElemType_vaccine))
{ /* 初始条件: 线性表L已存在,compare()是数据元素判定函数(满足为1,否则为0) */
  /* 操作结果: 返回L中第1个与e满足关系compare()的数据元素的位序。 */
  /*           若这样的数据元素不存在,则返回值为0 */
  int i = 0;
  LinkList1 p = L->next;
  while (p)
  {
    i++;
    if (compare(p->data, e)) /* 找到这样的数据元素 */
      return i;
    p = p->next;
  }
  return 0;
}

Status ListInsert1(LinkList1 L, int i, ElemType_vaccine e) /* 算法2.9。不改变L */
{                                                        /* 在带头结点的单链线性表L中第i个位置之前插入元素e */
  int j = 0;
  LinkList1 p = L, s;
  while (p && j < i - 1) /* 寻找第i-1个结点 */
  {
    p = p->next;
    j++;
  }
  if (!p || j > i - 1) /* i小于1或者大于表长 */
    return ERROR;
  s = (LinkList1)malloc(sizeof(struct LNode)); /* 生成新结点 */
  s->data = e;                                /* 插入L中 */
  s->next = p->next;
  p->next = s;
  return OK;
}

Status ListDelete(LinkList1 L, int i, ElemType_vaccine *e) /* 算法2.10。不改变L */
{                                                         /* 在带头结点的单链线性表L中，删除第i个元素,并由e返回其值 */
  int j = 0;
  LinkList1 p = L, q;
  while (p->next && j < i - 1) /* 寻找第i个结点,并令p指向其前趋 */
  {
    p = p->next;
    j++;
  }
  if (!p->next || j > i - 1) /* 删除位置不合理 */
    return ERROR;
  q = p->next; /* 删除并释放结点 */
  p->next = q->next;
  *e = q->data;
  free(q);
  return OK;
}

Status ListTraverse1(LinkList1 L, void (*vi)(ElemType_vaccine))
/* vi的形参类型为ElemType，与bo2-1.c中相应函数的形参类型ElemType&不同 */
{ /* 初始条件：线性表L已存在 */
  /* 操作结果:依次对L的每个数据元素调用函数vi()。一旦vi()失败,则操作失败 */
  LinkList1 p = L->next;
  while (p)
  {
    vi(p->data);
    p = p->next;
  }
  printf("\n");
  return OK;
}

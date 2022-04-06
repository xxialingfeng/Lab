
 Status MakeNode(Link *p,ElemType e)
 { 
   *p=(Link)malloc(sizeof(LNode));
   if(!*p)
     return ERROR;
   (*p)->data=e;
   return OK;
 }

 void FreeNode(Link *p)
 { 
   free(*p);
   *p=NULL;
 }

 Status InitList(LinkList *L)
 { 
   Link p;
   p=(Link)malloc(sizeof(LNode)); 
   if(p)
   {
     p->next=NULL;
     (*L).head=(*L).tail=p;
     (*L).len=0;
     return OK;
   }
   else
     return ERROR;
 }

 Status ClearList(LinkList *L)
 { 
   Link p,q;
   if((*L).head!=(*L).tail)
   {
     p=q=(*L).head->next;
     (*L).head->next=NULL;
     while(p!=(*L).tail)
     {
       p=q->next;
       free(q);
       q=p;
     }
     free(q);
     (*L).tail=(*L).head;
     (*L).len=0;
   }
   return OK;
 }

 Status DestroyList(LinkList *L)
 { 
   ClearList(L); 
   FreeNode(&(*L).head);
   (*L).tail=NULL;
   (*L).len=0;
   return OK;
 }

 Status InsFirst(LinkList *L,Link h,Link s) 
 { 
   s->next=h->next;
   h->next=s;
   if(h==(*L).tail) 
     (*L).tail=h->next; 
   (*L).len++;
   return OK;
 }

 Status DelFirst(LinkList *L,Link h,Link *q) 
 {
   *q=h->next;
   if(*q) /* ¡¥±Ì∑«ø’ */
   {
     h->next=(*q)->next;
     if(!h->next) /* …æ≥˝Œ≤Ω·µ„ */
       (*L).tail=h; /* –ﬁ∏ƒŒ≤÷∏’Î */
     (*L).len--;
     return OK;
   }
   else
     return FALSE; /* ¡¥±Ìø’ */
 }

 Status Append(LinkList *L,Link s)
 { 
   int i=1;
   (*L).tail->next=s;
   while(s->next)
   {
     s=s->next;
     i++;
   }
   (*L).tail=s;
   (*L).len+=i;
   return OK;
 }

 Position PriorPos(LinkList L,Link p)
 { 
   Link q;
   q=L.head->next;
   if(q==p) /* Œﬁ«∞«˝ */
     return NULL;
   else
   {
     while(q->next!=p) 
       q=q->next;
     return q;
   }
 }

 Status Remove(LinkList *L,Link *q)
 { 
   Link p=(*L).head;
   if((*L).len==0) /* ø’±Ì */
   {
     *q=NULL;
     return FALSE;
   }
   while(p->next!=(*L).tail)
     p=p->next;
   *q=(*L).tail;
   p->next=NULL;
   (*L).tail=p;
   (*L).len--;
   return OK;
 }

 Status InsBefore(LinkList *L,Link *p,Link s)
 { /* “—÷™p÷∏œÚœﬂ–‘¡¥±ÌL÷–µƒ“ª∏ˆΩ·µ„£¨Ω´sÀ˘÷∏Ω·µ„≤Â»Î‘⁄pÀ˘÷∏Ω·µ„÷Æ«∞£¨ */
   /* ≤¢–ﬁ∏ƒ÷∏’Îp÷∏œÚ–¬≤Â»ÎµƒΩ·µ„ */
   Link q;
   q=PriorPos(*L,*p); /* q «pµƒ«∞«˝ */
   if(!q) /* pŒﬁ«∞«˝ */
     q=(*L).head;
   s->next=*p;
   q->next=s;
   *p=s;
   (*L).len++;
   return OK;
 }

 Status InsAfter(LinkList *L,Link *p,Link s)
 { /* “—÷™p÷∏œÚœﬂ–‘¡¥±ÌL÷–µƒ“ª∏ˆΩ·µ„£¨Ω´sÀ˘÷∏Ω·µ„≤Â»Î‘⁄pÀ˘÷∏Ω·µ„÷Æ∫Û£¨ */
   /* ≤¢–ﬁ∏ƒ÷∏’Îp÷∏œÚ–¬≤Â»ÎµƒΩ·µ„ */
   if(*p==(*L).tail) /* –ﬁ∏ƒŒ≤÷∏’Î */
     (*L).tail=s;
   s->next=(*p)->next;
   (*p)->next=s;
   *p=s;
   (*L).len++;
   return OK;
 }

 Status SetCurElem(Link p,ElemType e)
 { /* “—÷™p÷∏œÚœﬂ–‘¡¥±Ì÷–µƒ“ª∏ˆΩ·µ„£¨”√e∏¸–¬pÀ˘÷∏Ω·µ„÷– ˝æ›‘™Àÿµƒ÷µ */
   p->data=e;
   return OK;
 }

 ElemType GetCurElem(Link p)
 { /* “—÷™p÷∏œÚœﬂ–‘¡¥±Ì÷–µƒ“ª∏ˆΩ·µ„£¨∑µªÿpÀ˘÷∏Ω·µ„÷– ˝æ›‘™Àÿµƒ÷µ */
   return p->data;
 }

 Status ListEmpty(LinkList L)
 { /* »Ùœﬂ–‘¡¥±ÌLŒ™ø’±Ì£¨‘Ú∑µªÿTRUE£¨∑Ò‘Ú∑µªÿFALSE */
   if(L.len)
     return FALSE;
   else
     return TRUE;
 }

 int ListLength(LinkList L)
 { /* ∑µªÿœﬂ–‘¡¥±ÌL÷–‘™Àÿ∏ˆ ˝ */
   return L.len;
 }

 Position GetHead(LinkList L)
 { /* ∑µªÿœﬂ–‘¡¥±ÌL÷–Õ∑Ω·µ„µƒŒª÷√ */
   return L.head;
 }

 Position GetLast(LinkList L)
 { /* ∑µªÿœﬂ–‘¡¥±ÌL÷–◊Ó∫Û“ª∏ˆΩ·µ„µƒŒª÷√ */
   return L.tail;
 }

 Position NextPos(Link p)
 { /* “—÷™p÷∏œÚœﬂ–‘¡¥±ÌL÷–µƒ“ª∏ˆΩ·µ„£¨∑µªÿpÀ˘÷∏Ω·µ„µƒ÷±Ω”∫ÛºÃµƒŒª÷√ */
   /* »ÙŒﬁ∫ÛºÃ£¨‘Ú∑µªÿNULL */
   return p->next;
 }

 Status LocatePos(LinkList L,int i,Link *p)
 { /* ∑µªÿp÷∏ æœﬂ–‘¡¥±ÌL÷–µ⁄i∏ˆΩ·µ„µƒŒª÷√£¨≤¢∑µªÿOK£¨i÷µ≤ª∫œ∑® ±∑µªÿERROR */
   /* i=0Œ™Õ∑Ω·µ„ */
   int j;
   if(i<0||i>L.len)
     return ERROR;
   else
   {
     *p=L.head;
     for(j=1;j<=i;j++)
       *p=(*p)->next;
     return OK;
   }
 }

 Position LocateElem(LinkList L,ElemType e,Status (*compare)(ElemType,ElemType))
 { /* ∑µªÿœﬂ–‘¡¥±ÌL÷–µ⁄1∏ˆ”Îe¬˙◊„∫Ø ˝compare()≈–∂®πÿœµµƒ‘™ÀÿµƒŒª÷√£¨ */
   /* »Ù≤ª¥Ê‘⁄’‚—˘µƒ‘™Àÿ£¨‘Ú∑µªÿNULL */
   Link p=L.head;
   do
     p=p->next;
   while(p&&!(compare(p->data,e))); /* √ªµΩ±ÌŒ≤«“√ª’“µΩ¬˙◊„πÿœµµƒ‘™Àÿ */
   return p;
 }

 Status ListTraverse(LinkList L,void(*visit)(ElemType))
 { /* “¿¥Œ∂‘Lµƒ√ø∏ˆ ˝æ›‘™Àÿµ˜”√∫Ø ˝visit()°£“ªµ©visit() ß∞‹£¨‘Ú≤Ÿ◊˜ ß∞‹ */
   Link p=L.head->next;
   int j;
   for(j=1;j<=L.len;j++)
   {
     visit(p->data);
     p=p->next;
   }
   printf("\n");
   return OK;
 }

 Status OrderInsert(LinkList *L,ElemType e,int (*comp)(ElemType,ElemType))
 { /* “—÷™LŒ™”––Úœﬂ–‘¡¥±Ì£¨Ω´‘™Àÿe∞¥∑«Ωµ–Ú≤Â»Î‘⁄L÷–°££®”√”⁄“ª‘™∂‡œÓ Ω£© */
   Link o,p,q;
   q=(*L).head;
   p=q->next;
   while(p!=NULL&&comp(p->data,e)<0) /* p≤ª «±ÌŒ≤«“‘™Àÿ÷µ–°”⁄e */
   {
     q=p;
     p=p->next;
   }
   o=(Link)malloc(sizeof(LNode)); /* …˙≥…Ω·µ„ */
   o->data=e; /* ∏≥÷µ */
   q->next=o; /* ≤Â»Î */
   o->next=p;
   (*L).len++; /* ±Ì≥§º”1 */
   if(!p) /* ≤Â‘⁄±ÌŒ≤ */
     (*L).tail=o; /* –ﬁ∏ƒŒ≤Ω·µ„ */
   return OK;
 }

 Status LocateElemP(LinkList L,ElemType e,Position *q,int(*compare)(ElemType,ElemType))
 { /* »Ù…˝–Ú¡¥±ÌL÷–¥Ê‘⁄”Îe¬˙◊„≈–∂®∫Ø ˝compare()»°÷µŒ™0µƒ‘™Àÿ£¨‘Úq÷∏ æL÷– */
   /* µ⁄“ª∏ˆ÷µŒ™eµƒΩ·µ„µƒŒª÷√£¨≤¢∑µªÿTRUE£ª∑Ò‘Úq÷∏ æµ⁄“ª∏ˆ”Îe¬˙◊„≈–∂®∫Ø ˝ */
   /* compare()»°÷µ>0µƒ‘™Àÿµƒ«∞«˝µƒŒª÷√°£≤¢∑µªÿFALSE°££®”√”⁄“ª‘™∂‡œÓ Ω£© */
   Link p=L.head,pp;
   do
   {
     pp=p;
     p=p->next;
   }while(p&&(compare(p->data,e)<0)); /* √ªµΩ±ÌŒ≤«“p->data.expn<e.expn */
   if(!p||compare(p->data,e)>0) /* µΩ±ÌŒ≤ªÚcompare(p->data,e)>0 */
   {
     *q=pp;
     return FALSE;
   }
   else /* ’“µΩ */
   {
     *q=p;
     return TRUE;
   }
 }

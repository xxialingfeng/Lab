 Status InitQueue(LinkQueue *Q)
 { /* ππ‘Ï“ª∏ˆø’∂”¡–Q */
   (*Q).front=(*Q).rear=(QueuePtr)malloc(sizeof(QNode));
   if(!(*Q).front)
     exit(OVERFLOW);
   (*Q).front->next=NULL;
   return OK;
 }

 Status DestroyQueue(LinkQueue *Q)
 { 
   while((*Q).front)
   {
     (*Q).rear=(*Q).front->next;
     free((*Q).front);
     (*Q).front=(*Q).rear;
   }
   return OK;
 }

 Status ClearQueue(LinkQueue *Q)
 {
   QueuePtr p,q;
   (*Q).rear=(*Q).front;
   p=(*Q).front->next;
   (*Q).front->next=NULL;
   while(p)
   {
     q=p;
     p=p->next;
     free(q);
   }
   return OK;
 }

 Status QueueEmpty(LinkQueue Q)
 { 
   if(Q.front==Q.rear)
     return TRUE;
   else
     return FALSE;
 }

 int QueueLength(LinkQueue Q)
 { 
   int i=0;
   QueuePtr p;
   p=Q.front;
   while(Q.rear!=p)
   {
     i++;
     p=p->next;
   }
   return i;
 }

 Status GetHead_Q(LinkQueue Q,QELemType *e) 
 { 
   QueuePtr p;
   if(Q.front==Q.rear)
     return ERROR;
   p=Q.front->next;
   *e=p->data;
   return OK;
 }

 Status EnQueue(LinkQueue *Q,QELemType e)
 {
   QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
   if(!p) 
     exit(OVERFLOW);
   p->data=e;
   p->next=NULL;
   (*Q).rear->next=p;
   (*Q).rear=p;
   return OK;
 }

 Status DeQueue(LinkQueue *Q,QELemType *e)
 { 
   QueuePtr p;
   if((*Q).front==(*Q).rear)
     return ERROR;
   p=(*Q).front->next;
   *e=p->data;
   (*Q).front->next=p->next;
   if((*Q).rear==p)
     (*Q).rear=(*Q).front;
   free(p);
   return OK;
 }

 Status QueueTraverse(LinkQueue Q,void(*vi)(QELemType))
 { 
   QueuePtr p;
   p=Q.front->next;
   while(p)
   {
     vi(p->data);
     p=p->next;
   }
   printf("\n");
   return OK;
 }

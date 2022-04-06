 typedef struct QNode
 {
   QELemType data;
   struct QNode *next;
 }QNode,*QueuePtr;

 typedef struct
 {
   QueuePtr front,rear; 
 }LinkQueue;

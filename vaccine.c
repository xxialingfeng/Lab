#define Qu 2;//AB两个队列
#define ryjg 3//两个人打疫苗的间隔最大值：3分钟
#define ymjg 3//每个人打疫苗时间的最大值：3分钟
#include "c1.h"
typedef struct{
    int OccurTime;
    int Ntype;
}Event,ElemType;
typedef struct LNode
 {
   ElemType data;
   struct LNode *next;
 }LNode,*Link,*Position;

 typedef struct LinkList 
 {
   Link head,tail; 
   int len; 
 }LinkList;
typedef LinkList EventList;
#include"bo2-6.c"
typedef struct vaccine{//定义接种人结构体
    char name[10];
    char ID[200];
    char Phone[20];
    char IfSlowD[10];//是否有慢性病
    char IfAlleg[10];//是否过敏
    char Date[20];
    char Window[20];
}ElemType_vaccine;
typedef struct LNode1
{
    ElemType_vaccine data;
    struct LNode1 *next;
} LNode1, *LinkList1;
#include "b02-1.c"
typedef struct{
    int ArrivaTime;
    int Duration;
}QELemType;
#include "c3-2.h"
#include "bo3-2.c"

EventList ev;
Event en;
Event et;
LinkQueue q[2];
ElemType_vaccine e,e0;
LinkList1 L;
QELemType customer;
int TotalTime=0,CustomeNum=0;//人员累计逗留时间，人员数
int CloseTime;//医院营业时间（单位是分）
//定义一些基本数据
ElemType_vaccine va = {"吴彦祖","420111197720205431","17396123001","否","否","2021年5月1日","A"};
ElemType_vaccine vb = {"夏凌锋","360121199912305211","15397801307","是","否","2021年5月2日","B"};
ElemType_vaccine vc = {"聂泽锋","420132199703545811","15071444870","否","是","2021年5月1日","A"};

int cmp(Event a, Event b){
    if(a.OccurTime==b.OccurTime)
    return 0;
    else
    return(a.OccurTime-b.OccurTime)/abs(a.OccurTime-b.OccurTime);
}

int Menu()
{
    int a;
    printf("***********************************************\n");
    printf("\t欢迎使用教职工疫苗接种系统\t\n");
    printf("***********************************************\n");
    printf("\t请按照序号选择对应的功能\t\t\n");
    printf("\t1：建立用户档案接种疫苗\t\t\t\n");
    printf("\t2：按时间段查询某窗口疫苗接种信息\t\t\t\n");
    printf("\t0：退出疫体温打卡登记系统\t\t\t\n");
    printf("***********************************************\n");
    printf("请输入您的选择：[ ]\b\b");
    scanf("%d", &a);
    puts("");
    return a;
}

void OpenForVaccine(){
   int i;
   InitList(&ev);
   /*InitList1(&L); 
   ListInsert1(L,1,va);
   ListInsert1(L,2,vb);
   ListInsert1(L,3,vc);//插入一些初始数据*/
   en.OccurTime=0; 
   en.Ntype=2;//两个队列
   OrderInsert(&ev,en,cmp); 
   for(i=0;i<2;++i) 
     InitQueue(&q[i]);
}

 void Random(int *d,int *i)
 {
   *d=rand()%ryjg+1;
   *i=rand()%ymjg+1; 
 }


 int Minimum(LinkQueue Q[])//返回最短的队列编号
 {
   int l[2];
   int i,k;
   for(i=0;i<2;i++)
     l[i]=QueueLength(Q[i]);
   k=0;
   for(i=1;i<2;i++)
     if(l[i]<l[0])
     {
       l[0]=l[i];
       k=i;
     }
   return k;
 }

 void input(ElemType_vaccine *c)
{
    printf("\n 请输入您的名字");
    scanf("%s", c->name);
    printf("\n 请输入您的身份证号");
    scanf("%s", c->ID);
    printf("\n 请输入您的联系电话");
    scanf("%s", c->Phone);
    printf("\n 请输入疫苗接种日期（xxxx年xx月xx日的格式）");
    scanf("%s", c->Date);
    printf("\n 请输入是否有慢性病（是或否）");
    scanf("%s", c->IfSlowD);
    printf("\n 请输入是否有过敏史（是或否");
    scanf("%s", c->IfAlleg);
    printf("\n 请输入您所在的接种窗口（A或B");
    scanf("%s", c->IfAlleg);
}

void visitElem(ElemType_vaccine c)
{
    printf("\n ");
    printf("Name: %s", c.name);
    printf("ID: %s", c.ID);
    printf("Phone: %s", c.Phone);
    printf("Date: %s", c.Date);
    printf("If has slow diease: %s", c.IfSlowD);
    printf("If allergic: %s", c.IfAlleg);
    printf("Window: %s", c.Window);
}

 void StuffArrived()//疫苗接种者到达事件
 { 
   QELemType f;
   int durtime,intertime,i;
   ++CustomeNum;
   Random(&durtime,&intertime); 
   et.OccurTime=en.OccurTime+intertime; 
   et.Ntype=Qu; 
   if(et.OccurTime<CloseTime) 
     OrderInsert(&ev,et,cmp);
   i=Minimum(q); 
   f.ArrivaTime=en.OccurTime;
   f.Duration=durtime;
   EnQueue(&q[i],f);
   if(QueueLength(q[i])==1)
   {
     et.OccurTime=en.OccurTime+durtime;
     et.Ntype=i;
     OrderInsert(&ev,et,cmp); 
   }
 }

  void StuffDeparture()
 { 
   int i;
   i=en.Ntype;
   DeQueue(&q[i],&customer); 
   TotalTime+=en.OccurTime-customer.ArrivaTime; 
   if(!QueueEmpty(q[i]))
   { 
     GetHead_Q(q[i],&customer);
     et.OccurTime=en.OccurTime+customer.Duration;
     et.Ntype=i;
     OrderInsert(&ev,et,cmp);
   }
 }

void Vaccine_Simulation()
 {
   Link p;
   OpenForVaccine(); 
   while(!ListEmpty(ev))
   {
     DelFirst(&ev,GetHead(ev),&p);
     en.OccurTime=GetCurElem(p).OccurTime;
     en.Ntype=GetCurElem(p).Ntype;
     if(en.Ntype==2){
       StuffArrived();
       printf("请您先填写个人信息！\n");
       input(&e);
       ListInsert1(L,1,e);
       printf("输入成功！\n");
       printf("请您前往指定地点打疫苗！\n");
       /*ListTraverse1(L,visitElem); */
     }
     else
       StuffDeparture();
   } 
   printf("顾客总数:%d,所有顾客共耗时:%d分钟,平均每人耗时:%d分钟\n",CustomeNum,TotalTime,TotalTime/CustomeNum);
 }

 void SearchWindow(){
        LinkList1 L;
        InitList1(&L); 
        ListInsert1(L,1,va);
        ListInsert1(L,2,vb);
        ListInsert1(L,3,vc);
        LinkList1 p = L->next;
        printf("\n请输入想要查询的时间段和窗口：\n");
        scanf("%s%s", e0.Date,e0.Window);
        ElemType_vaccine *result_sw = NULL;
        while (p->next != NULL)
        {
            if (strcmp(p->data.Date, e0.Date) == 0 && strcmp(p->data.Window,e0.Window) ==0)
            {
                result_sw = &(p->data);
                break;
            }
            p = p->next;
        }

        if(p->next == NULL){//如果下一个域为空，就把当前p指针所指的数据打印出来
            result_sw = &(p->data);
        }
        visitElem(*result_sw);
        printf("\n");
 }

int main()
 { 
   SearchWindow();
   int num;
   while(num = Menu()){
     if(num == 1){
       printf("请输入医院营业的时间长度（单位：分）\n");
       scanf("%d",&CloseTime);
       Vaccine_Simulation();
     }
     if(num == 2){
       SearchWindow();
     }
     if(num == 0){
       exit(0);
     }
   }
   return 0;
 }

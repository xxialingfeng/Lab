#include "c1.h"
typedef struct Information
{
    char VisitorName[10];//来访人员姓名
    char Phone[20];   //手机号默认为11位
    char StuName[20]; //考虑到少数名族，数组长度设置为10
    char roomId[10];  //按照华师学生宿舍3位数字，例如226，需要把数组改大一些，不然数据会溢出
    char Affair[100]; //事由，不超过100个字符
    char Date[200];   //日期，不超过200个字符
    char TimeLine[100];//时间段
} ElemType_Visitor;
#include "C2-2.H"
#include "BO2-2.C"

//输入一些原始数据
ElemType_Visitor v1 = {"吴彦祖", "17396123001", "彭于晏", "226", "看望朋友", "2021年3月21日","上午"};
ElemType_Visitor v2 = {"刘德华", "17398673502", "张家辉", "315", "借书", "2021年3月22日","下午"};
ElemType_Visitor v3 = {"郭富城", "17366358796", "周星驰", "627", "送零食", "2021年3月23日","晚上"};

int Menu()
{   
    int b;
    printf("***********************************************\n");
    printf("\t欢迎使用来访人员信息登记管理系统\t\n");
    printf("***********************************************\n");
    printf("\t请按照序号选择对应的功能\t\t\n");
    printf("\t1：录入来访人员信息\t\t\t\n");
    printf("\t2：查询来访人员信息\t\t\t\n");
    printf("\t3：某时间段访问次数统计\t\t\t\n");
    printf("\t4：查看当前所有访客信息\t\t\t\n");
    printf("\t0：退出来访人员信息登记管理系统\t\t\t\n");
    printf("***********************************************\n");
    printf("请输入您的选择：[ ]\b\b");
    scanf("%d", &b);
    puts("");
    return b;
}

void visitElem(ElemType_Visitor c)
{
    printf("\n ");
    printf("Visitor Name: %s", c.VisitorName);
    printf("Phone Number: %s", c.Phone);
    printf("Student Name: %s", c.StuName);
    printf("roomId: %s", c.roomId);
    printf("Affair: %s", c.Affair);
    printf("Date: %s", c.Date);
    printf("TimeLine: %s", c.TimeLine);
}

void input(ElemType_Visitor *c)
{
    printf("\n Please Input Visitor Information(Visitor Name)");
    scanf("%s", c->VisitorName);
    printf("\n Please Input Visitor Information(Phone Number)");
    scanf("%s", c->Phone);
    printf("\n Please Input Visitor Information(Student Name)");
    scanf("%s", c->StuName);
    printf("\n Please Input Visitor Information(roomId)");
    scanf("%s", c->roomId);
    printf("\n Please Input Visitor Information(Affair)");
    scanf("%s", c->Affair);
    printf("\n Please Input Visitor Information(Date)");
    scanf("%s", c->Date);
    printf("\n Please Input Visitor Information(TimeLine)");
    scanf("%s", c->TimeLine);
}

//按照某个字段查找对应的访客信息
void SearchVisitor()
{
    LinkList L;
    int choose;
    // char a,u1,u2,u3,u4,u5;
    ElemType_Visitor e, e0;
    InitList(&L);
    ListInsert(L, 1, v1);
    ListInsert(L, 2, v2);
    ListInsert(L, 3, v3);
    LinkList p = L->next;
    printf("\n下面进入访客查询功能，请输入对应的序号查询访客信息\n");
    printf("***********************************************\n");
    printf("\n按来访人员姓名查询:1\n");
    printf("\n按被访问学生姓名查询:2\n");
    printf("\n按房间号查询:3\n");
    printf("\n按时间段查询:4\n");
    printf("***********************************************\n");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        printf("\n请输入想要查询的来访人员姓名：\n");
        scanf("%s", e0.VisitorName);
        ElemType_Visitor *result_vn = NULL;
        while (p->next != NULL)
        {
            if (strcmp(p->data.VisitorName, e0.VisitorName) == 0)
            {
                result_vn = &(p->data);
                break;
            }
            p = p->next;
        }

        if(p->next == NULL){//如果下一个域为空，就把当前p指针所指的数据打印出来
            result_vn = &(p->data);
        }
        visitElem(*result_vn);
        printf("\n");
        break;
    case 2:
        printf("\n请输入想要查询的学生姓名：\n");
        scanf("%s", e0.StuName);
        ElemType_Visitor *result_sn = NULL;
        while (p->next != NULL)
        {
            if (strcmp(p->data.StuName, e0.StuName) == 0)
            {
                result_sn = &(p->data);
                break;
            }
            p = p->next;
        }

         if(p->next == NULL){//如果下一个域为空，就把当前p指针所指的数据打印出来
            result_sn = &(p->data);
        }
        visitElem(*result_sn);
        printf("\n");
        break;
    case 3:
        printf("\n请输入想要查询的房间号码：\n");
        scanf("%s", e0.roomId);
        ElemType_Visitor *result_ri = NULL;
        while (p->next != NULL)
        {
            if (strcmp(p->data.roomId, e0.roomId) == 0)
            {
                result_ri = &(p->data);
                break;
            }
            p = p->next;
        }
         if(p->next == NULL){//如果下一个域为空，就把当前p指针所指的数据打印出来
            result_ri = &(p->data);
        }
        visitElem(*result_ri);
        printf("\n");
        break;
    case 4:
        printf("\n请输入想要查询的日期，按照xxxx年x月x日的格式，x代表数字\n");
        scanf("%s", e0.Date);
        ElemType_Visitor *result_d = NULL;
        while (p->next != NULL)
        {
            if (strcmp(p->data.Date, e0.Date) == 0)
            {
                result_d = &(p->data);
                break;
            }
            p = p->next;
        }

        if(p->next == NULL){//如果下一个域为空，就把当前p指针所指的数据打印出来
            result_d = &(p->data);
        }
        visitElem(*result_d);
        printf("\n");
        break;
    }
}

//统计某个时间段（早上、中午、晚上）的记录的访客信息次数
void SumOfVisitors(){
    LinkList L;
    int choose;
    int countM = 0; //设置三个计数器
    int countA = 0;
    int countE = 0;
    ElemType_Visitor e, e0;
    InitList(&L);
    ListInsert(L, 1, v1);
    ListInsert(L, 2, v2);
    ListInsert(L, 3, v3);
    LinkList p = L->next;
    printf("\n下面进入时间段统计功能，请输入时间段(timeline)查询某时间段访问次数\n");
    printf("\n*********************************************************\n");
    scanf("%s",e0.TimeLine);
    ElemType_Visitor *result_morning = NULL;
    ElemType_Visitor *result_afternoon = NULL;
    ElemType_Visitor *result_evening = NULL;
        while (p->next != NULL)
        {   
            if(strcmp("早上", e0.TimeLine) == 0){//输入的时间段和对应时间段比较，相同的话计数器的值+1
               countM++;
               printf("\n共查询到的记录次数为: \n");
               printf("\n %d",countM);
               result_morning = &(p->data);
               visitElem(*result_morning);
               break;
            }else if(strcmp("下午", e0.TimeLine) == 0){
               countA++;
               printf("\n共查询到的记录次数为: \n");
               printf("\n %d",countA);
               result_afternoon = &(p->data);
               visitElem(*result_afternoon);
               break;
            } else if(strcmp("晚上", e0.TimeLine) == 0){
               countE++;
               printf("\n共查询到的记录次数为: \n");
               printf("\n %d",countE);
               result_evening = &(p->data);
               visitElem(*result_evening);
               break;
            }
            p=p->next;
        }    
}

//主测试函数
int main()
{
    LinkList L;
    InitList(&L);
    ElemType_Visitor e, e0;
    ListInsert(L, 1, v1);
    ListInsert(L, 2, v2);
    ListInsert(L, 3, v3);
    int num1;
    while(num1 = Menu()){
     if(num1 == 1){
        input(&e);
        ListInsert(L,1,e);
        ListTraverse(L,visitElem);
     }
     if(num1 == 2){
       SearchVisitor();
     }
     if(num1 == 3){
       SumOfVisitors();
     }
     if(num1 == 4){
       ListTraverse(L,visitElem);
     }
     if(num1 == 0){
       exit(0);
     }
   }
    return 0;
}

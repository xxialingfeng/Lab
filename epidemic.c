#include "c1.h"
typedef struct Teacher
{
    char TeacherID[10];//教工号
    char Name[20];   //姓名
    char Phone[20]; //电话
    char Date[10];  //日期
    char BodyTem[10]; //体温
    char IfinWH[10];   //是否在汉
    char IfContact[10];//14天内是否接触发热病人
} ElemType_Teacher;
#include "c2.H"
#include "bo.C"

//输入一些原始数据
ElemType_Teacher t1 = {"2018215091", "夏凌锋", "17396123001", "2021年3月21日", "36.4", "是","否"};
ElemType_Teacher t2 = {"2018214999", "肖小月", "17396123509", "2021年3月22日", "37.1", "是","否"};
ElemType_Teacher t3 = {"2018213008", "聂泽锋", "15071444870", "2021年3月23日", "36.5", "是","是"};

int Menu()
{
    int c;
    printf("***********************************************\n");
    printf("\t欢迎使用防疫体温打卡登记系统\t\n");
    printf("***********************************************\n");
    printf("\t请按照序号选择对应的功能\t\t\n");
    printf("\t1：录入打卡信息\t\t\t\n");
    printf("\t2：按姓名查询某事件段打卡信息\t\t\t\n");
    printf("\t3：按时间段查询体温异常的教工信息。\t\t\t\n");
    printf("\t4：查看当前所有员工信息\t\t\t\n");
    printf("\t0：退出疫体温打卡登记系统\t\t\t\n");
    printf("***********************************************\n");
    printf("请输入您的选择：[ ]\b\b");
    scanf("%d", &c);
    puts("");
    return c;
}

void visitElem(ElemType_Teacher c)
{
    printf("\n ");
    printf("TeacherID: %s", c.TeacherID);
    printf("Name: %s", c.Name);
    printf("Phone: %s", c.Phone);
    printf("Date: %s", c.Date);
    printf("BodyTem: %s", c.BodyTem);
    printf("IfinWH: %s", c.IfinWH);
    printf("IfContact: %s", c.IfContact);
}

void input(ElemType_Teacher *c)
{
    printf("\n Please Input Visitor Information(TeacherID)");
    scanf("%s", c->TeacherID);
    printf("\n Please Input Visitor Information(Name)");
    scanf("%s", c->Name);
    printf("\n Please Input Visitor Information(Phone)");
    scanf("%s", c->Phone);
    printf("\n Please Input Visitor Information(Date)");
    scanf("%s", c->Date);
    printf("\n Please Input Visitor Information(BodyTem)");
    scanf("%s", c->BodyTem);
    printf("\n Please Input Visitor Information(IfinWH)");
    scanf("%s", c->IfinWH);
    printf("\n Please Input Visitor Information(IfContact)");
    scanf("%s", c->IfContact);
}

//按照某姓名查询打卡信息
void SearchName()
{
    LinkList L;
    // char a,u1,u2,u3,u4,u5;
    ElemType_Teacher e, e0;
    InitList(&L);
    ListInsert(L, 1, t1);
    ListInsert(L, 2, t2);
    ListInsert(L, 3, t3);
    LinkList p = L->next;
    printf("\n下面进入姓名查询功能，请输入姓名查询打卡信息\n");
    printf("***********************************************\n");
        scanf("%s", e0.Name);
        ElemType_Teacher *result_vn = NULL;
        while (p->next != NULL)
        {
            if (strcmp(p->data.Name, e0.Name) == 0)
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
}

//按时间段查询体温异常的教工信息。
void SearchAbnormal(){
    LinkList L;
    ElemType_Teacher e, e0;
    InitList(&L);
    ListInsert(L, 1, t1);
    ListInsert(L, 2, t2);
    ListInsert(L, 3, t3);
    LinkList p = L->next;
    printf("\n下面进入按时间段查询体温异常的教工信息功能，请输入时间段（按照xxxx年x月x日的格式）查询\n");
    printf("***********************************************\n");
        scanf("%s", e0.Date);
        ElemType_Teacher *result_sa = NULL;
        while (p->next != NULL)
        {
            if (strcmp(p->data.Date, e0.Date) == 0)
            {
                if(p->data.BodyTem > 37 || p->data.BodyTem < 36)
                result_sa = &(p->data);
                break;
            }
            p = p->next;
        }

        if(p->next == NULL){//如果下一个域为空，就把当前p指针所指的数据打印出来
            result_sa = &(p->data);
        }
        visitElem(*result_sa);
        printf("\n");
}

//主测试函数
int main()
{
    LinkList L;
    InitList(&L);
    ElemType_Teacher e, e0;
    ListInsert(L, 1, t1);
    ListInsert(L, 2, t2);
    ListInsert(L, 3, t3);
    int num2;
    while(num2 = Menu()){
     if(num2 == 1){
        input(&e);
        ListInsert(L,1,e);
        ListTraverse(L,visitElem);
     }
     if(num2 == 2){
       SearchName();
     }
     if(num2 == 3){
        SearchAbnormal();
     }
     if(num2 == 4){
       ListTraverse(L,visitElem);
     }
     if(num2 == 0){
       exit(0);
     }
    return 0;
}

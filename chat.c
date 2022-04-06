#include "c1.h"
#define MAXSIZE 1000
#define OK 1
#define ERROR 0

//定义单链表的存储结构
struct LNode
{
    int user, time;//数据域
    char* chat;
    struct LNode* next;//指针域
}*L;  //LnkList为指向LNode类型的指针

int cnt = 1;
int ran(double a, double b)///随机数产生器，其范围为[a,b);
{
    return a + (b - a) * rand() / (RAND_MAX + 1.0);
}

void CreataList() {
    struct LNode* NewL = (struct LNode*)malloc(sizeof(struct LNode));
    NewL->user = ran(1, 4), NewL->time = ran(1, 50);
    printf("与上一条聊天记录时间间隔为%d, 请输入用户%d的聊天内容：", NewL->time, NewL->user);
    char* chat = (char*)malloc(sizeof(MAXSIZE));
    scanf("%s", chat);
    NewL->chat = chat;
    NewL->next = NULL;
    puts("");

    NewL->next = L;
    L = NewL;
}

void display(int l, int r) {
    int t = 0;
    struct LNode* p = L;
    while (p) {
        if (l <= t && t <= r) printf("   用户%d: %s\n", p->user, p->chat);
        t += p->time;
        p = p->next;
    }
}

int get_opt() {
    int op;
    puts("+----------------聊天系统-------------------+");
    puts("|          1）开始聊天                      |");
    puts("|          2）查询聊天信息                  |");
    puts("|          0）退出系统                      |");
    puts("+-------------------------------------------+");
    printf("请输入您的选择：[ ]\b\b");
    scanf("%d", &op);
    puts("");
    return op;
}

int main()
{
    while (1) {
        int opt = get_opt();
        if (!opt) break;
        if (opt == 1) {
            int op = 1;
            while (op) {
                CreataList();
                printf("聊天结束请按0,继续则按任意键……");
                getchar();
                op = getchar() - '0';
                puts("");
            }
        }

        if (opt == 2) {
            int l, r;
            printf("请输入您想要查询的时间区间:");
            scanf("%d%d", &l, &r);
            display(l, r);
        }
    }

    printf("\n聊天记录已保存在data.txt中，请查看！\n");
    freopen("data.txt", "w", stdout);
    display(0, 99999);
    return 0;
}
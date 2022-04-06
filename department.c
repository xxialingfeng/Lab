#include"c1.h"
#define MAXSIZE 1000
typedef struct Snode  //结点结构
{
    char* name;
    int parent, salary[13];
}PNode;

typedef struct  //树结构 
{
    PNode tnode[MAXSIZE];
    int n;                 //结点个数 
}Ptree;

int idx;
void find(Ptree* T, int u, char* name, const int n) {
    for (int i = 0; i < n; ++i) if (T->tnode[i].parent == u) {
        if (!strcmp(T->tnode[i].name, name)) idx = i;
        find(T, i, name, n);
    }
}

void print(Ptree* T, int u, int m) {
    for (int i = 0; i <= T->n; ++i) if (T->tnode[i].parent == u) {
        printf("====================%s部门\n", T->tnode[i].name);
        printf("上级为：%s，%d月工资情况为：%d\n", T->tnode[T->tnode[i].parent].name, m, T->tnode[i].salary[m]);
        puts("====================");
        print(T, i, m);
    }
}


void InitPNode(Ptree* T)
{
    T->tnode[0].parent = -1;
    printf("请输入学校名称:");
    T->tnode[0].name = (char*)malloc(sizeof(MAXSIZE));
    scanf("%s", T->tnode[0].name); puts("");

    printf("请输入总共部门个数:");
    scanf("%d", &(T->n)); puts("");

    int cnt = 1;
    while (cnt <= T->n) {
        printf("请输入第%d个部门的上级部门名字：", cnt);
        char* name = (char*)malloc(sizeof(MAXSIZE));
        scanf("%s", name); puts("");
        idx = -1;
        find(T, -1, name, cnt);
        if (~idx) {
            printf("请输入该部门名字：");
            char* Name = (char*)malloc(sizeof(MAXSIZE));
            scanf("%s", Name); puts("");
            int fa = idx;
            idx = -1;
            find(T, -1, Name, cnt);
            if (~idx) puts("该部门已经存在！");
            else {
                puts("没有找到该部门，正在新建部门……");
                T->tnode[cnt].parent = fa;
                T->tnode[cnt].name = Name;
                for (int i = 1; i <= 12; ++i) {
                    printf("请输入%s第%d月的工资情况：", name, i);
                    scanf("%d", &T->tnode[cnt].salary[i]);
                }
                puts("新建部门成功！");
                cnt++;
            }
        }
        else puts("该部门没有找到请重新输入！");
    }
}

int get_opt() {
    int op;
    puts("+-------------部门管理系统------------------+");
    puts("|          1）创建部门                      |");
    puts("|          2）统计部门当月情况              |");
    puts("|          0）退出系统                      |");
    puts("+-------------------------------------------+");
    printf("请输入您的选择：[ ]\b\b");
    scanf("%d", &op);
    puts("");
    return op;
}

Ptree* tree;
int main() {
    tree = (Ptree*)malloc(sizeof(Ptree));
    int opt;
    while (opt = get_opt()) {
        if (opt == 1) InitPNode(tree);
        if (opt == 2) {
            printf("请输入您要查询的月份：");
            int m;
            scanf("%d", &m);
            print(tree, 0, m);
        }
    }
    return 0;
}
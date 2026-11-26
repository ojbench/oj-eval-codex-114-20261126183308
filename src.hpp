#include<algorithm>

void Init(int **&p,int n){//初始化，n为vector的个数,传入的p指向nullptr
    p = new int *[n + 1]();
}
void Add_element(int **&p,int x,int y){//在第x(1base)个vector后面添加一个元素y
    // Each allocation stores size, capacity, then the elements.
    if (p[x] == nullptr) {
        p[x] = new int[3];
        p[x][0] = 0;
        p[x][1] = 1;
    }
    if (p[x][0] == p[x][1]) {
        int capacity = p[x][1] * 2;
        int *replacement = new int[capacity + 2];
        std::copy(p[x], p[x] + p[x][0] + 2, replacement);
        replacement[1] = capacity;
        delete[] p[x];
        p[x] = replacement;
    }
    p[x][p[x][0] + 2] = y;
    ++p[x][0];
}
int Get_element(int **&p,int x,int k){//获取第x(1base)个vector中第k个(1-base)元素的值
    return p[x][k + 1];
}
void Clear(int **&p,int n){//回收空间
    for (int i = 1; i <= n; ++i) {
        delete[] p[i];
    }
    delete[] p;
    p = nullptr;
}

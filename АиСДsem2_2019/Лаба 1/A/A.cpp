#include <stdio.h>

//using namespace std;

int rails_count = 0;

#define INT_MAX 2147483647

static char buffer[128];
int node_count = 0;

struct Node {
    int sum;
    int max_h;
    int pendingVal;
    Node* L;
    Node* R;
    int array_index;
    Node()
    {
        pendingVal = INT_MAX;
        sum = max_h = array_index = 0;
        L = 0;
        R = 0;
    }
    Node(int index) {
        array_index = index;
        L = R = 0;
        max_h = sum = 0;
        pendingVal = INT_MAX;
    }

    Node(Node * l, Node * r) {
        L = l;
        R = r;
    }

    ~Node() {
        delete R;
        delete L;
    }

    void sum_update() {
        int sum_tmp = R->max_h + L->sum;
        max_h = L->max_h > sum_tmp ? L->max_h : sum_tmp;
        sum = L->sum + R->sum;
    }

} g_Node;

Node* nodes;

inline void MakeLR(Node * rt, int l, int r) {
    if (rt->L == 0) {
        rt->L = new Node((rt->array_index << 1) + 1);
        rt->R = new Node((rt->array_index << 1) + 2);
    }
    if (rt->pendingVal == INT_MAX) return;
    rt->sum = rt->pendingVal * (r - l + 1);
    rt->max_h = rt->sum;
    if (l != r) {
        rt->L->pendingVal = rt->pendingVal;
        rt->R->pendingVal = rt->pendingVal;
    }
    rt->pendingVal = INT_MAX;
}

inline void update(Node *v, int l, int r, int l_r, int r_r, int val) {
    MakeLR(v, l, r);
    if (l_r > r || r_r < l) return;
    if (l_r <= l && r_r >= r) {
        v->pendingVal = val;
        MakeLR(v, l, r);
        return;
    }
    update(v->L, l, l + (r - l) / 2, l_r, r_r, val);
    update(v->R, l + (r - l) / 2 + 1, r, l_r, r_r, val);
    v->sum_update();
}


int Q_command(Node* v, int l, int r, int h) {
    MakeLR(v, l, r);
    if (l == r) return l;
    MakeLR(v->L, l, l + (r - l) / 2);
    if (v->L->max_h > h) {
        return Q_command(v->L, l, l + (r - l) / 2, h);
    }
    else {
        MakeLR(v->R, l + (r - l) / 2 + 1, r);
        return Q_command(v->R, l + (r - l) / 2 + 1, r, h - v->L->sum);
    }
}


int main()
{
    nodes = (Node*)buffer;
    scanf("%u", &rails_count);
    while (true) {
        char c;
        scanf("%c", &c);
        if (c == 'I')
        {
            int a, b, D;
            scanf("%u %u %u", &a, &b, &D);
            update(&g_Node, 0, rails_count, a - 1, b - 1, D);
        }
        else
        if (c == 'Q')
        {
            int op;
            scanf("%u", &op);
            int res = Q_command(&g_Node, 0, rails_count, op);
            printf("%u\n", res);
        }
        else
            if (c == 'E')
                break;
    }
    return 0;
}

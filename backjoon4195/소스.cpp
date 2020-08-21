#include <cstdio>
#include <vector>
#include <string>
#include <map>
#pragma warning(disable:4996)
using namespace std;

#define NAME_LENGTH 21
#define PARENT_MAX 200001

int parent[PARENT_MAX];

int Find(int a)
{
    if (parent[a] < 0) return a;
    return parent[a] = Find(parent[a]);
}

void Unite(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a != b)
    {
        parent[a] = parent[a] + parent[b];
        parent[b] = a;
    }
    printf("%d\n", -parent[a]);
}

int main() {
    int test;
    scanf("%d", &test);
    for (int i = 0; i < test; i++)
    {
        int f;
        scanf("%d", &f);
        fill(parent, parent + PARENT_MAX, -1);

        map<string, int> hash;
        int idx = 0;

        for (int i = 0; i < f; i++) {
            char name1[21] = { 0 };
            char name2[21] = { 0 };
            scanf("%s %s", name1, name2);

            if (hash.count(name1) == 0) {
                hash[name1] = idx++;
            }
            if (hash.count(name2) == 0) {
                hash[name2] = idx++;
            }
            int a = hash[name1];
            int b = hash[name2];

            Unite(a, b);
        }
    }

    return 0;
}
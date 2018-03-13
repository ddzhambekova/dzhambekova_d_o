#include <vector>
#include <iostream>
#include <string>

using namespace std;
struct DSU {
    vector <int> parent;
    DSU(int size) {
        parent.resize(size, -1);
    }
    void hang(int v, int p) {
        parent[v] = p;
    }
    void print() {
        for (int i = 0; i < parent.size(); ++i) {
            if (parent[i] != -1)
                cout << i << " -> " << parent[i] << endl;
            else
                cout << i << endl;
        }
    }
    int find(int v) {
        int r = v;
        while (parent[r] != -1)
            r = parent[r];
        while (parent[v] != -1)
        {
            int tmp = v;
            v = parent[v];
            parent[tmp] = r;
        }
        return v;
    }
};

int main() {


    return 0;
}
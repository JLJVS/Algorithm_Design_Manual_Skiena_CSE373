#include <stdio.h>
#include <math.h>
#include <float.h>

typedef struct {
    int x;
    int y;
} Point;

double Distance(Point a, Point b){
    double dx = a.x-b.x;
    double dy = a.y-b.y;
    return sqrt(dx*dx + dy*dy);
}


void tsp_NN(Point *pts, int n, int start , int *tour){
    // create an array of the points to show the order
    int visited[n];
    for (int i = 0; i < n; i++){
        visited[i] = 0;
    }

    // set the starting point
    int current = start;
    tour[0] = start;
    visited[start] = 1;

    for (int step = 1; step < n; step++) {
        double best = DBL_MAX;
        int next = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                double d = distance(pts[current], pts[i]);
                if (d < best) {
                    best = d;
                    next = i;
                }
            }
        }

        tour[step] = next;
        visited[next] = 1;
        current = next;
    }

    tour[n] = start; // close the cycle
}

// For the Closest pair approach we need edges

typedef struct {
    double dist;
    int a, b;
} Edge;

int find(int parent[], int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}

void unite(int parent[], int a, int b) {
    parent[find(parent, a)] = find(parent, b);
}

int cmp_edge(const void *A, const void *B) {
    Edge *e1 = (Edge*)A;
    Edge *e2 = (Edge*)B;
    return (e1->dist > e2->dist) - (e1->dist < e2->dist);
}

void tsp_closest_pair(Point *pts, int n, int *tour) {
    int total_edges = n*(n-1)/2;
    Edge edges[total_edges];

    int idx = 0;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            edges[idx++] = (Edge){ distance(pts[i], pts[j]), i, j };

    qsort(edges, total_edges, sizeof(Edge), cmp_edge);

    int parent[n], degree[n];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        degree[i] = 0;
    }

    Edge chosen[n];
    int chosen_count = 0;

    for (int i = 0; i < total_edges; i++) {
        int a = edges[i].a;
        int b = edges[i].b;

        if (degree[a] < 2 && degree[b] < 2) {
            if (find(parent, a) != find(parent, b) || chosen_count == n - 2) {
                chosen[chosen_count++] = edges[i];
                degree[a]++;
                degree[b]++;
                unite(parent, a, b);
            }
        }
        if (chosen_count == n) break;
    }

    // Build ordered cycle
    tour[0] = chosen[0].a;
    tour[1] = chosen[0].b;

    for (int k = 2; k < n; k++) {
        int last = tour[k-1];
        for (int i = 0; i < chosen_count; i++) {
            if (chosen[i].a == last && chosen[i].b != tour[k-2]) {
                tour[k] = chosen[i].b;
                break;
            }
            if (chosen[i].b == last && chosen[i].a != tour[k-2]) {
                tour[k] = chosen[i].a;
                break;
            }
        }
    }

    tour[n] = tour[0];
}





int main(void)
{   





    return 0;
}
#include <stdio.h>
#include <stdlib.h>

void Dfs(int n, int a[10][10], int source, int s[10]);
void Bfs(int n, int a[10][10], int source, int s[10]);

void main() {
    int n, a[10][10], i, j, source, s[10], ch;

    printf("Enter the Number of Nodes \n");
    scanf("%d", &n);

    printf("Enter the Adjacency Matrix \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the Source Node \n");
    scanf("%d", &source);

    for (i = 0; i < n; i++) {
        s[i] = 0;
    }

    printf("1: Depth first Traversal 2:Breadth first Traversal \n");
    scanf("%d", &ch);

    switch (ch) {
        case 1:
            printf("The DFS order is \n");
            Dfs(n, a, source, s);
            break;

        case 2:
            for (i = 0; i < n; i++) {
                s[i] = 0; // Reset the visited array for BFS
            }
            printf("The BFS order is \n");
            Bfs(n, a, source, s);
            break;

        default:
            exit(0);
    }
}

void Dfs(int n, int a[10][10], int source, int s[10]) {
    int i;

    printf("%d\t", source);
    s[source] = 1;

    for (i = 0; i < n; i++) {
        if (s[i] == 0 && a[source][i] == 1) {
            Dfs(n, a, i, s);
        }
    }
}

void Bfs(int n, int a[10][10], int source, int s[10]) {
    int q[10], f = 0, r = 0, i, u;

    printf("%d\t", source);
    s[source] = 1;

    q[r] = source;

    while (f <= r) {
        u = q[f];
        f = f + 1;

        for (i = 0; i < n; i++) {
            if (s[i] == 0 && a[u][i] == 1) {
                printf("%d\t", i);
                s[i] = 1;
                r = r + 1;
                q[r] = i;
            }
        }
    }
}

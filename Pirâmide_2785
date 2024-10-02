#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAXN 101
#define INF INT_MAX

int soma[MAXN][MAXN], matriz[MAXN][MAXN], dp[MAXN][MAXN];
int N;

int calcula(int id, int a, int b) {
    return soma[id][b] - soma[id][a - 1];
}

int solve(int linha, int pos) {
    if (linha == N + 1) return 0;
    if (dp[linha][pos] != -1) return dp[linha][pos];
    if (pos <= 0 || linha + pos - 1 > N) return dp[linha][pos] = INF;
    int agora = calcula(linha, pos, pos + linha - 1);
    int proxima = (solve(linha + 1, pos - 1) < solve(linha + 1, pos)) ? solve(linha + 1, pos - 1) : solve(linha + 1, pos);
    return dp[linha][pos] = agora + proxima;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &matriz[i][j]);
            soma[i][j] = soma[i][j - 1] + matriz[i][j];
        }
    }
    
    int resposta = solve(1, 1);
    for (int i = 2; i <= N; i++) {
        int temp = solve(1, i);
        if (temp < resposta) resposta = temp;
    }
    
    printf("%d\n", resposta);
    return 0;
}

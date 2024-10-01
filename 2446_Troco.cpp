#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool isSubsetSum(int valores[], int n, int objetivo) {
    vector<bool> possivel(objetivo + 1, false);
    possivel[0] = true;

    for (int i = 0; i < n; i++) {
        for (int j = objetivo; j >= valores[i]; j--) {
            if (possivel[j - valores[i]]) {
                possivel[j] = true;
            }
        }
    }

    return possivel[objetivo];
}

int main() {
    int v, m;
    cin >> v >> m;
    int moedas[m];
    for (int i = 0; i < m; i++) {
        cin >> moedas[i];
    }
    if (isSubsetSum(moedas, m, v)) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}

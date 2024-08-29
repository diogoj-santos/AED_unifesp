#include <iostream>
#include <string>
using namespace std;

// Função para construir a sequência posfixa
void construirPosfixa(const string& prefixa, const string& infixa, int n) {
    if (n == 0) return;

    // A raiz é o primeiro caractere da sequência prefixa
    char raiz = prefixa[0];

    // Encontra a posição da raiz na sequência infixa
    int posRaiz = infixa.find(raiz);

    // Recursivamente constrói a sub-árvore esquerda
    construirPosfixa(prefixa.substr(1, posRaiz), infixa.substr(0, posRaiz), posRaiz);

    // Recursivamente constrói a sub-árvore direita
    construirPosfixa(prefixa.substr(posRaiz + 1), infixa.substr(posRaiz + 1), n - posRaiz - 1);

    // Imprime a raiz no final (caractere posfixo)
    cout << raiz;
}

int main() {
    int C;
    cin >> C;

    while (C--) {
        int N;
        string prefixa, infixa;
        cin >> N >> prefixa >> infixa;

        construirPosfixa(prefixa, infixa, N);
        cout << endl;
    }

    return 0;
}

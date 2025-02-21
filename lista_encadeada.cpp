#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class ListaEncadeada {
private:
    Node* head;
    int tamanho;
public:
    ListaEncadeada() {
        head = nullptr;
        tamanho = 0;
    }

    bool estaVazia() {
        return tamanho == 0;
    }

    int getTamanho() {
        return tamanho;
    }

    int obterElemento(int pos) {
        if (pos < 1 || pos > tamanho) {
            cout << "Posicao invalida!" << endl;
            return -1;
        }
        Node* temp = head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    void modificarElemento(int pos, int valor) {
        if (pos < 1 || pos > tamanho) {
            cout << "Posicao invalida!" << endl;
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        temp->data = valor;
    }

    void inserirElemento(int pos, int valor) {
        if (pos < 1 || pos > tamanho + 1) {
            cout << "Posicao invalida!" << endl;
            return;
        }
        Node* novo = new Node;
        novo->data = valor;
        if (pos == 1) {
            novo->next = head;
            head = novo;
        } else {
            Node* temp = head;
            for (int i = 1; i < pos - 1; i++) {
                temp = temp->next;
            }
            novo->next = temp->next;
            temp->next = novo;
        }
        tamanho++;
    }

    void removerElemento(int pos) {
        if (pos < 1 || pos > tamanho) {
            cout << "Posicao invalida!" << endl;
            return;
        }
        Node* temp = head;
        if (pos == 1) {
            head = head->next;
            delete temp;
        } else {
            Node* anterior = nullptr;
            for (int i = 1; i < pos; i++) {
                anterior = temp;
                temp = temp->next;
            }
            anterior->next = temp->next;
            delete temp;
        }
        tamanho--;
    }

    void imprimirLista() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    ListaEncadeada lista;
    lista.inserirElemento(1, 10);
    lista.inserirElemento(2, 20);
    lista.inserirElemento(3, 30);
    lista.imprimirLista();

    lista.modificarElemento(2, 25);
    lista.imprimirLista();

    lista.removerElemento(1);
    lista.imprimirLista();

    cout << "Elemento na posicao 2: " << lista.obterElemento(2) << endl;
    return 0;
}

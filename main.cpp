#include <iostream>

struct Node { //struktura
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {} // konstruktor wezla, ustawia wartosc i zera po bokach
};

class BST {
private:
    Node* root; // korzen, czyli glowny boss calego drzewa

    Node* insert(Node* node, int val) { // rekurencyjne wpychanie wartosci na odpowiednie miejsce
        if (node == nullptr)
            return new Node(val); // jak pusto, to tworzymy nowy wezel

        if (val < node->data)
            node->left = insert(node->left, val); // mniejsze idzie w lewo
        else
            node->right = insert(node->right, val); // wieksze albo rowne w prawo

        return node;
    }

    void inorder(Node* node) { // tutaj robie to do sortowania w pamieci
        if (node == nullptr)
            return; // jak dotarlismy do konca galezi, to wracamy

        inorder(node->left); // najpierw najglebiej w lewo
        std::cout << node->data << " "; // wypisujemy aktualny element
        inorder(node->right); // a potem w prawo
    }


public:
    BST() {
        root = nullptr; // na start drzewo jest puste
    }

    void insert(int val) {
        root = insert(root, val); // wywolanie prywatnej funkcji od korzenia
    }

    void display() {
        inorder(root); // odpalanie wypisywania od korzenia
        std::cout << std::endl;
    }


};

int main() {
    BST tree;

    tree.insert(50); // tutaj wpisuje liczby do drzewa
    tree.insert(30);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    std::cout << "Elementy drzewa:" << std::endl;
    tree.display(); // wyswietlenie posortowanych danych

    return 0; // koniec programu, wszystko dziala git
}

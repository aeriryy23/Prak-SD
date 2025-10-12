#include <iostream>
using namespace std;

const int MAX = 10;

int stack[MAX];
int topIdx = -1;

bool isEmpty() {
    return topIdx == -1;
}

bool isFull() {
    return topIdx == MAX - 1;
}

void push(int value) {
    if (isFull()) {
        cout << "Stack penuh!\n";
    } else {
        stack[++topIdx] = value;
        cout << "Push " << value << " berhasil\n";
    }
}

void pop() {
    if (isEmpty()) {
        cout << "Stack kosong!\n";
    } else {
        cout << "Pop " << stack[topIdx--] << " berhasil\n";
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Stack kosong!\n";
    } else {
        cout << "Elemen teratas: " << stack[topIdx] << "\n";
    }
}

void display() {
    if (isEmpty()) {
        cout << "Stack kosong!\n";
    } else {
        cout << "Isi stack: ";
        for (int i = topIdx; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int pilih, nilai;
    do {
        cout << "\n=== STACK (Array) ===\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Tampilkan\n5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "Nilai: ";
            cin >> nilai;
            push(nilai);
        } else if (pilih == 2) {
            pop();
        } else if (pilih == 3) {
            peek();
        } else if (pilih == 4) {
            display();
        }
    } while (pilih != 5);

    cout << "Program selesai.\n";
    return 0;
}

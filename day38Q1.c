#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

int deque[MAX];
int front = MAX / 2;    // Start in the middle to allow both-end growth
int rear  = MAX / 2 - 1;
int sz    = 0;

// ─── Core Operations ────────────────────────────────────────────────────────

void push_front(int value) {
    if (front == 0) { printf("Deque Overflow at front\n"); return; }
    deque[--front] = value;
    sz++;
    printf("push_front(%d) → ", value);
    display();
}

void push_back(int value) {
    if (rear == MAX - 1) { printf("Deque Overflow at rear\n"); return; }
    deque[++rear] = value;
    sz++;
    printf("push_back(%d)  → ", value);
    display();
}

void pop_front() {
    if (sz == 0) { printf("pop_front()    → Deque Underflow\n"); return; }
    printf("pop_front()    → Removed: %d\n", deque[front++]);
    sz--;
}

void pop_back() {
    if (sz == 0) { printf("pop_back()     → Deque Underflow\n"); return; }
    printf("pop_back()     → Removed: %d\n", deque[rear--]);
    sz--;
}

void getFront() {
    if (sz == 0) { printf("front()        → Deque is empty\n"); return; }
    printf("front()        → %d\n", deque[front]);
}

void getBack() {
    if (sz == 0) { printf("back()         → Deque is empty\n"); return; }
    printf("back()         → %d\n", deque[rear]);
}

void isEmpty() {
    printf("empty()        → %s\n", sz == 0 ? "true" : "false");
}

void getSize() {
    printf("size()         → %d\n", sz);
}

// ─── Additional Operations ───────────────────────────────────────────────────

void clear() {
    front = MAX / 2;
    rear  = MAX / 2 - 1;
    sz    = 0;
    printf("clear()        → Deque cleared\n");
}

void eraseAt(int pos) {
    if (pos < 0 || pos >= sz) { printf("erase(%d)      → Invalid position\n", pos); return; }
    printf("erase(pos=%d)  → Removed: %d\n", pos, deque[front + pos]);
    for (int i = front + pos; i < rear; i++)
        deque[i] = deque[i + 1];
    rear--;
    sz--;
}

void swapDeques(int other[], int* oFront, int* oRear, int* oSz) {
    int tempDeque[MAX];
    memcpy(tempDeque, deque, sizeof(deque));

    memcpy(deque,  other, sizeof(deque));
    memcpy(other, tempDeque, sizeof(deque));

    int tf = front, tr = rear, ts = sz;
    front = *oFront; rear = *oRear; sz = *oSz;
    *oFront = tf; *oRear = tr; *oSz = ts;

    printf("swap()         → Deques swapped\n");
}

void resizeDeque(int newSize, int fillValue) {
    while (sz < newSize) { deque[++rear] = fillValue; sz++; }
    while (sz > newSize) { rear--; sz--; }
    printf("resize(%d,%d)  → ", newSize, fillValue);
    display();
}

void assign(int count, int value) {
    clear();
    for (int i = 0; i < count; i++) { deque[++rear] = value; sz++; }
    printf("assign(%d,%d)  → ", count, value);
    display();
}

void reverse() {
    int l = front, r = rear;
    while (l < r) {
        int temp   = deque[l];
        deque[l++] = deque[r];
        deque[r--] = temp;
    }
    printf("reverse()      → ");
    display();
}

void sortDeque() {
    // Bubble sort
    for (int i = front; i <= rear; i++)
        for (int j = front; j < rear - (i - front); j++)
            if (deque[j] > deque[j + 1]) {
                int temp    = deque[j];
                deque[j]    = deque[j + 1];
                deque[j + 1]= temp;
            }
    printf("sort()         → ");
    display();
}

// ─── Display ─────────────────────────────────────────────────────────────────

void display() {
    if (sz == 0) { printf("[ empty ]\n"); return; }
    printf("[ ");
    for (int i = front; i <= rear; i++) {
        if (i == rear) printf("%d ", deque[i]);
        else           printf("%d, ", deque[i]);
    }
    printf("]\n");
}

// ─── Main ────────────────────────────────────────────────────────────────────

int main() {
    printf("════════════════════════════════════\n");
    printf("        DEQUE DEMONSTRATION         \n");
    printf("════════════════════════════════════\n\n");

    printf("--- Core Operations ---\n");
    push_back(10);
    push_back(20);
    push_back(30);
    push_front(5);
    push_front(1);
    getFront();
    getBack();
    getSize();
    isEmpty();
    pop_front();
    pop_back();
    getSize();

    printf("\n--- Additional Operations ---\n");
    reverse();
    sortDeque();
    eraseAt(1);
    resizeDeque(5, 99);
    assign(4, 7);
    reverse();

    printf("\n--- Final State ---\n");
    getFront();
    getBack();
    getSize();
    printf("Final deque: ");
    display();

    return 0;
}
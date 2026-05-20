# 🗂️ Deque Implementation using Doubly Linked List in C

A complete implementation of a **Double-Ended Queue (Deque)** data structure using a **Doubly Linked List** in C, built as part of a Data Structures mini project.

---

## 📌 About

A **Deque** (pronounced *"deck"*) is a linear data structure in which elements can be added or removed from **both ends** — the front and the rear. Unlike a standard queue, it does not follow strict FIFO ordering.

This project implements a Deque using a **Doubly Linked List**, allowing dynamic memory allocation without any fixed size limitation.

---

## 🚀 Features

- ✅ Insert element at the **Front**
- ✅ Insert element at the **Rear**
- ✅ Delete element from the **Front**
- ✅ Delete element from the **Rear**
- ✅ Display all elements in the Deque
- ✅ Handles edge cases (empty deque, single element)

---

## 🛠️ Tech Stack

- **Language:** C
- **Concepts Used:** Doubly Linked List, Dynamic Memory Allocation, Pointers, Structs

---

## 📂 Project Structure
deque-doubly-linked-list-c/
│
├── DS Mini Project.c # Main source file
├── DS Report.pdf # Project report
└── README.md

---
## ⚙️ How to Compile & Run
### Prerequisites
- GCC compiler installed
### Compile
```bash
gcc "DS Mini Project.c" -o deque
Run
./deque
🖥️ Menu
Menu:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Display Deque
6. Exit
🔍 How It Works
Node Structure
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;
Deque Structure
typedef struct Dequeue {
    Node* front;
    Node* rear;
} Dequeue;
Each node holds an integer value and pointers to both the previous and next nodes, enabling O(1) insertion and deletion at both ends.

📊 Time Complexity
Operation	Time Complexity
Insert Front	O(1)
Insert Rear	O(1)
Delete Front	O(1)
Delete Rear	O(1)
Display	O(n)
📄 License
This project is open source and available under the MIT License.

👤 Author
Thomson
GitHub: @Thomson-4

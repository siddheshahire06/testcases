
Practical 1 – Linear Search and Binary Search
Language: C++
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a[50], n, key, c = 0;
    bool found = false;
    cout << "Enter number of students: ";
    cin >> n;
    cout << "Enter roll numbers: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Enter roll number to search: ";
    cin >> key;
    // Linear Search
    for (int i = 0; i < n; i++) {
        c++;
        if (a[i] == key) {
            found = true;
            break;
        }
    }
    if (found) cout << "Linear Search: Found\\n";
    else cout << "Linear Search: Not Found\\n";
    cout << "Linear comparisons: " << c << endl;
    // Binary Search needs sorted data
    sort(a, a + n);
    int low = 0, high = n - 1, mid;
    c = 0;
    found = false;
    while (low <= high) {
        mid = (low + high) / 2;
        c++;
        if (a[mid] == key) {
            found = true;
            break;
        } else if (a[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (found) cout << "Binary Search: Found\\n";
    else cout << "Binary Search: Not Found\\n";
    cout << "Binary comparisons: " << c;
    return 0;
}
Page 2
DSL Practical Codes – C++
Practical 2 – Selection Sort (Top Five Scores)
Language: C++


#include <iostream>
using namespace std;
int main() {
    float a[50], temp;
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    cout << "Enter percentages: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex])
                minIndex = j;
        }
        temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }
    cout << "Sorted percentages: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\\nTop five scores: ";
    for (int i = n - 1; i >= 0 && i >= n - 5; i--)
        cout << a[i] << " ";
    return 0;
}
Page 3
DSL Practical Codes – C++
Practical 3 – Bubble Sort (Top Five Scores)
Language: C++
#include <iostream>
using namespace std;
int main() {
    float a[50], temp;
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    cout << "Enter percentages: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    cout << "Sorted percentages: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\\nTop five scores: ";
    for (int i = n - 1; i >= 0 && i >= n - 5; i--)
        cout << a[i] << " ";
    return 0;
}
Page 4
DSL Practical Codes – C++
Practical 4 – Stack (Balanced Parentheses)
Language: C++


#include <iostream>
using namespace std;
int main() {
    char s[100], st[100];
    int top = -1;
    cout << "Enter expression: ";
    cin >> s;
    for (int i = 0; s[i] != '\\0'; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st[++top] = s[i];
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (top == -1) {
                cout << "Not Balanced";
                return 0;
            }
            char ch = st[top--];
            if ((s[i] == ')' && ch != '(') ||
                (s[i] == '}' && ch != '{') ||
                (s[i] == ']' && ch != '[')) {
                cout << "Not Balanced";
                return 0;
            }
        }
    }
    if (top == -1) cout << "Balanced";
    else cout << "Not Balanced";
    return 0;
}
Page 5
DSL Practical Codes – C++
DSL Practical Codes – C++ Page 6
Practical 5 – Queue (Job Scheduling)
Language: C++


#include <iostream>
using namespace std;
int main() {
    int q[50], front = 0, rear = -1;
    int choice, job;
    do {
        cout << "\\n1. Add Job";
        cout << "\\n2. Delete Job";
        cout << "\\n3. Display Jobs";
        cout << "\\n4. Exit";
        cout << "\\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                if (rear == 49) {
                    cout << "Queue Full";
                } else {
                    cout << "Enter job number: ";
                    cin >> job;
                    q[++rear] = job;
                    cout << "Job Added";
                }
                break;
            case 2:
                if (front > rear) {
                    cout << "Queue Empty";
                } else {
                    cout << "Deleted Job: " << q[front++];
                }
                break;
            case 3:
                if (front > rear) {
                    cout << "Queue Empty";
                } else {
                    for (int i = front; i <= rear; i++)
                        cout << q[i] << " ";
                }
                break;
        }
    } while (choice != 4);
    return 0;
}
Practical 6 – Singly Linked List (Add Club Members)
Language: C++


#include <iostream>
using namespace std;
struct Node {
    int prn;
    string name;
    Node* next;
};
Node* head = NULL;
void addMember() {
    Node* n = new Node;
    cout << "Enter PRN and name: ";
    cin >> n->prn >> n->name;
    n->next = NULL;
    if (head == NULL) {
        head = n;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = n;
    }
}
void display() {
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        cout << temp->prn << " " << temp->name << endl;
        count++;
        temp = temp->next;
    }
    cout << "Total members: " << count;
}
int main() {
    int choice;
    do {
        cout << "\\n1. Add President";
        cout << "\\n2. Add Member";
        cout << "\\n3. Add Secretary";
        cout << "\\n4. Display Members";
        cout << "\\n5. Exit";
        cout << "\\nEnter choice: ";
        cin >> choice;
        if (choice >= 1 && choice <= 3)
            addMember();
        else if (choice == 4)
            display();
    } while (choice != 5);
    return 0;
}
Page 7
DSL Practical Codes – C++
Practical 7 – Singly Linked List (Delete Members)
Language: C++


#include <iostream>
using namespace std;
struct Node {
    int prn;
    Node* next;
};
Node* head = NULL;
void addMember() {
    Node* n = new Node;
    cout << "Enter PRN: ";
    cin >> n->prn;
    n->next = NULL;
    if (head == NULL) {
        head = n;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = n;
    }
}
void deleteMember(int value) {
    Node* temp = head;
    Node* prev = NULL;
    while (temp != NULL && temp->prn != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Member Not Found";
        return;
    }
    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;
    delete temp;
    cout << "Member Deleted";
}
void deletePresident() {
    if (head == NULL) {
        cout << "List Empty";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}
void deleteSecretary() {
    if (head == NULL) {
        cout << "List Empty";
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}
void display() {
Page 8
DSL Practical Codes – C++
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->prn << " ";
        temp = temp->next;
    }
}
int main() {
    int choice, prn;
    do {
        cout << "\\n1. Add Member";
        cout << "\\n2. Delete President";
        cout << "\\n3. Delete Secretary";
        cout << "\\n4. Delete Member by PRN";
        cout << "\\n5. Display";
        cout << "\\n6. Exit";
        cout << "\\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addMember(); break;
            case 2: deletePresident(); break;
            case 3: deleteSecretary(); break;
            case 4:
                cout << "Enter PRN: ";
                cin >> prn;
                deleteMember(prn);
                break;
            case 5: display(); break;
        }
    } while (choice != 6);
    return 0;
}
Page 9
DSL Practical Codes – C++
Practical 8 – Singly Linked List (Concatenate Two Lists)
Language: C++



#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
void add(Node*& head, int value) {
    Node* n = new Node;
    n->data = value;
    n->next = NULL;
    if (head == NULL) {
        head = n;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = n;
    }
}
int main() {
    Node *first = NULL, *second = NULL;
    int n, value;
    cout << "Enter number of elements in first list: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> value;
        add(first, value);
    }
    cout << "Enter number of elements in second list: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> value;
        add(second, value);
    }
    if (first == NULL) {
        first = second;
    } else {
        Node* temp = first;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = second;
    }
    cout << "Concatenated List: ";
    while (first != NULL) {
        cout << first->data << " ";
        first = first->next;
    }
    return 0;
}
Page 10
DSL Practical Codes – C++
Practical 9 – Doubly Linked List (1's and 2's Complement)
Language: C++



#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};
int main() {
    string binary;
    Node *head = NULL, *tail = NULL;
    cout << "Enter binary number: ";
    cin >> binary;
    for (int i = 0; i < binary.length(); i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            cout << "Invalid binary number";
            return 0;
        }
        Node* n = new Node;
        n->data = binary[i] - '0';
        n->prev = tail;
        n->next = NULL;
        if (head == NULL)
            head = n;
        else
            tail->next = n;
        tail = n;
    }
    // Find 1's complement
    Node* temp = head;
    while (temp != NULL) {
        temp->data = 1 - temp->data;
        temp = temp->next;
    }
    cout << "1's Complement: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data;
        temp = temp->next;
    }
    // Add 1 to get 2's complement
    int carry = 1;
    temp = tail;
    while (temp != NULL && carry == 1) {
        if (temp->data == 0) {
            temp->data = 1;
            carry = 0;
        } else {
            temp->data = 0;
        }
        temp = temp->prev;
    }
    cout << "\\n2's Complement: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data;
        temp = temp->next;
    }
    return 0;
}
Page 11
DSL Practical Codes – C++
Practical 10 – Doubly Linked List (Binary Addition)
Language: C++



#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* prev;
    Node* next;
};
Node* createList(string s) {
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '0' && s[i] != '1')
            return NULL;
        Node* n = new Node;
        n->data = s[i] - '0';
        n->prev = tail;
        n->next = NULL;
        if (head == NULL)
            head = n;
        else
            tail->next = n;
        tail = n;
    }
    return tail; // Return last node for right-to-left addition
}
int main() {
    string a, b, result = "";
    cout << "Enter first binary number: ";
    cin >> a;
    cout << "Enter second binary number: ";
    cin >> b;
    Node* p = createList(a);
    Node* q = createList(b);
    if (p == NULL || q == NULL) {
        cout << "Invalid binary number";
        return 0;
    }
    int carry = 0;
    while (p != NULL || q != NULL || carry != 0) {
        int sum = carry;
        if (p != NULL) {
            sum += p->data;
            p = p->prev;
        }
        if (q != NULL) {
            sum += q->data;
            q = q->prev;
        }
        result = char('0' + sum % 2) + result;
        carry = sum / 2;
    }
    cout << "Binary Addition: " << result;
    return 0;
}
Page 12
DSL Practical Codes – C++
Practical 11 – Hashing (Linear Probing)
Language: C++



#include <iostream>
using namespace std;
int main() {
    int h[10], n, x;
    for (int i = 0; i < 10; i++)
        h[i] = -1;
    cout << "Enter number of clients (maximum 10): ";
    cin >> n;
    if (n < 0 || n > 10) {
        cout << "Invalid size";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cout << "Enter telephone number: ";
        cin >> x;
        int index = x % 10;
        int count = 0;
        while (h[index] != -1 && count < 10) {
            index = (index + 1) % 10;
            count++;
        }
        if (count == 10)
            cout << "Hash Table Full\\n";
        else
            h[index] = x;
    }
    cout << "Hash Table:\\n";
    for (int i = 0; i < 10; i++)
        cout << i << " -> " << h[i] << endl;
    return 0;
}
Page 13
DSL Practical Codes – C++
Practical 12 – Hashing (Quadratic Probing)
Language: C++



#include <iostream>
using namespace std;
int main() {
    int h[10], n, x;
    for (int i = 0; i < 10; i++)
        h[i] = -1;
    cout << "Enter number of clients (maximum 10): ";
    cin >> n;
    if (n < 0 || n > 10) {
        cout << "Invalid size";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cout << "Enter telephone number: ";
        cin >> x;
        int index = x % 10;
        int j;
        for (j = 0; j < 10; j++) {
            int pos = (index + j * j) % 10;
            if (h[pos] == -1) {
                h[pos] = x;
                break;
            }
        }
        if (j == 10)
            cout << "No empty position found\\n";
    }
    cout << "Hash Table:\\n";
    for (int i = 0; i < 10; i++)
        cout << i << " -> " << h[i] << endl;
    return 0;
}
Page 14
DSL Practical Codes – C++
Practical 13 – Hashing (Chaining)
Language: C++



#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* h[10] = {NULL};
void insert(int x) {
    int index = x % 10;
    Node* n = new Node;
    n->data = x;
    n->next = h[index];
    h[index] = n;
}
int main() {
    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter number: ";
        cin >> x;
        insert(x);
    }
    cout << "Hash Table:\\n";
    for (int i = 0; i < 10; i++) {
        cout << i << " -> ";
        Node* temp = h[i];
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\\n";
    }
    return 0;
}
Page 15
DSL Practical Codes – C++
Practical 14 – BST (Insert, Minimum and Mirror)
Language: C++



#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
};
Node* insert(Node* root, int x) {
    if (root == NULL) {
        Node* n = new Node;
        n->data = x;
        n->left = n->right = NULL;
        return n;
    }
    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
int minimum(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root->data;
}
void mirror(Node* root) {
    if (root == NULL)
        return;
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}
int main() {
    Node* root = NULL;
    int n, x;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }
    cout << "BST (Inorder): ";
    inorder(root);
    if (root != NULL)
        cout << "\\nMinimum value: " << minimum(root);
    mirror(root);
    cout << "\\nMirror tree (Inorder): ";
    inorder(root);
    return 0;
}
Page 16
DSL Practical Codes – C++
Practical 15 – BST (Longest Path, Minimum and Search)
Language: C++



#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
};
Node* insert(Node* root, int x) {
    if (root == NULL) {
        Node* n = new Node;
        n->data = x;
        n->left = n->right = NULL;
        return n;
    }
    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}
int height(Node* root) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}
int minimum(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root->data;
}
bool search(Node* root, int x) {
    if (root == NULL)
        return false;
    if (root->data == x)
        return true;
    if (x < root->data)
        return search(root->left, x);
    return search(root->right, x);
}
int main() {
    Node* root = NULL;
    int n, x;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }
    if (root != NULL) {
        cout << "Longest path (number of nodes): " << height(root);
        cout << "\\nMinimum value: " << minimum(root);
    }
    cout << "\\nEnter value to search: ";
    cin >> x;
    if (search(root, x))
        cout << "Value Found";
    else
        cout << "Value Not Found";
    return 0;
}
Page 17
DSL Practical Codes – C++
Practical 16 – Graph (Adjacency List and Connectivity)
Language: C++




#include <iostream>
#include <vector>
using namespace std;
vector<int> adj[50];
bool visited[50] = {false};
void dfs(int v) {
    visited[v] = true;
    for (int i = 0; i < adj[v].size(); i++) {
        int x = adj[v][i];
        if (!visited[x])
            dfs(x);
    }
}
int main() {
    int n, e, u, v;
    cout << "Enter number of cities (vertices): ";
    cin >> n;
    cout << "Enter number of flights (edges): ";
    cin >> e;
    if (n <= 0 || n > 50) {
        cout << "Invalid number of cities";
        return 0;
    }
    for (int i = 0; i < e; i++) {
        cout << "Enter connected city numbers: ";
        cin >> u >> v;
        if (u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Invalid vertex number";
            return 0;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "\\nAdjacency List:\\n";
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        for (int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
    dfs(0);
    bool connected = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            connected = false;
    }
    if (connected)
        cout << "Graph is Connected";
    else
        cout << "Graph is Not Connected";
    return 0;
}
Page 18
DSL Practical Codes – C++
#include <bits/stdc++.h>
using namespace std;

class HashTable {
private:
    struct Element {
        int key;
        int value;
    };

    vector<vector<Element>> table;
    int capacity; 
    int hash(int key) {
        return key % capacity;
    }

   public:
    HashTable(int cap) : capacity(cap) {
        table.resize(capacity);
    }

    void insert(int key, int value) {
        int index = hash(key);
        table[index].push_back({key, value});
    }

    int get(int key) {
        int index = hash(key);
        for (const Element& elem : table[index]) {
            if (elem.key == key) {
                return elem.value;
            }
        }
        return 0;
    }

    void remove(int key) {
        int index = hash(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->key == key) {
                table[index].erase(it);
                return;
            }
        }
    }

    bool search(int key) {
        int index = hash(key);
        for (const Element& elem : table[index]) {
            if (elem.key == key) {
                return true; 
            }
        }
        return false; 
    }
};

class HashTableOpenAddressing {
   private:
    vector<pair<int, int>> table;
    int capacity;
    int size;

    int hash(int key) {
        return key % capacity;
    }

    int findSlot(int key) {
        int slotIndex = hash(key);
        int startIndex = slotIndex;

        while (table[slotIndex].first != 0 && table[slotIndex].first != key) {
            slotIndex = (slotIndex + 1) % capacity;
            if (slotIndex == startIndex) {
                return -1; 
            }
        }

        return slotIndex;
    }

   public:
    HashTableOpenAddressing(int cap) : capacity(cap), size(0) {
        table.resize(capacity, {0, 0});
    }

    void insert(int key, int value) {
        if (size == capacity) {
            cout << "Table full" << endl;
            return;
        }

        int slotIndex = findSlot(key);
        if (slotIndex == -1) {
            cout << "Table full" << endl;
            return;
        }

        table[slotIndex] = {key, value};
        size++;
    }

    int get(int key) {
        int slotIndex = findSlot(key);
        if (slotIndex == -1) {
            return 0; 
        }
        return table[slotIndex].second;
    }

    void remove(int key) {
        int slotIndex = findSlot(key);
        if (slotIndex == -1) {
            return;  
        }

        table[slotIndex] = {0, 0};
        size--;
    }

    bool search(int key) {
        int slotIndex = findSlot(key);
        return slotIndex != -1;
    }
};

int main() {
    int n;
    cin >> n;
    HashTable ht1(n); 

    for (int i = 0; i < n; i++) {
        int ele;
        cin >> ele;
        ht1.insert(i, ele);
    }

    for (int i = 0; i < n; i++) {
        cout << i << ": " << ht1.get(i) << endl;
    }

    cout << "Enter key to be removed: ";
    int key;
    cin >> key;

    ht1.remove(key);

    for (int i = 0; i < n; i++) {
        cout << i << ": " << ht1.get(i) << endl;
    }

    cout << "Enter key to be searched: ";
    cin >> key;

    cout << "Search for " << key << ": " << ht1.search(key) << endl;

    cin >> n;
    HashTableOpenAddressing ht2(n);

    for (int i = 0; i < n; i++) {
        int ele;
        cin >> ele;
        ht2.insert(i, ele);
    }

    for (int i = 0; i < n; i++) {
        cout << i << ": " << ht2.get(i) << endl;
    }

    cout << "Enter key to be removed: ";
    cin >> key;

    ht2.remove(key);

    cout << "After removal ------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << ": " << ht2.get(i) << endl;
    }

    cout << "Enter key to be searched: ";
    cin >> key;

    cout << "Search for " << key << ": " << ht2.search(key) << endl;
    return 0;
}

#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Heap {
public:
  int arr[100];
  int size = 0;

  Heap() {
    arr[0] = -1;
    size = 0;
  }

  void insert(int val) {
    size++;
    int index = size;
    arr[index] = val;

    while (index > 1) {
      int parent = index / 2;

      if (arr[parent] < arr[index]) {
        swap(arr[parent], arr[index]);
        index = parent;
      } else {
        return;
      }
    }
  }

  void deleteFromheap() {
    if (size == 0) {
      cout << "Nothing to delete" << endl;
      return;
    }

    arr[1] = arr[size];
    size--;

    // take root node to its right node
    int i = 1;
    while (i <= size) {
      int leftIndex = 2 * i;
      int rightIndex = 2 * i + 1;

      if (leftIndex <= size && arr[leftIndex] > arr[i]) {
        swap(arr[i], arr[leftIndex]);
        i = leftIndex;
      } else if (rightIndex <= size && arr[rightIndex] > arr[i]) {
        swap(arr[i], arr[rightIndex]);
        i = rightIndex;
      } else {
        return;
      }
    }
  }

  void print() {
    for (int i = 1; i <= size; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

void heapify(int arr[], int n, int i) {
  int largest = i;
  int left = 2 * i;
  int right = 2 * i + 1;

  if (left <= n && arr[largest] < arr[left])
    largest = left;
  if (right <= n && arr[largest] < arr[right])
    largest = right;

  if (largest != i) {
    swap(arr[largest], arr[i]);
    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int n) {
  for (int i = n / 2; i > 0; i--) {
    heapify(arr, n, i);
  }

  while (n > 1) {
    swap(arr[1], arr[n]);
    n--;
    heapify(arr, n, 1);
  }
}

int main() {
  Heap h;
  h.insert(50);
  h.insert(55);
  h.insert(53);
  h.insert(52);
  h.insert(54);

  h.print();

  h.deleteFromheap();
  h.print();

  int arr[6] = {-1, 54, 53, 55, 52, 50};
  int n = 5;

  cout << "Printing array: ";
  for (int i = 1; i <= n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  heapSort(arr, n);
  cout << "Printing sorted array: ";
  for (int i = 1; i <= n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  cout << "Using priority queue here: " << endl;

  // max heap
  cout << "Max Heap" << endl;
  priority_queue<int> pq;

  pq.push(4);
  pq.push(2);
  pq.push(5);
  pq.push(3);

  cout << "Element at top: " << pq.top() << endl;
  pq.pop();
  cout << "Element at top: " << pq.top() << endl;
  cout << "Size: " << pq.size() << endl;
  if (pq.empty())
    cout << "Empty" << endl;
  else
    cout << "Not Empty" << endl;

  // min heap
  cout << "Min Heap" << endl;
  priority_queue<int, vector<int>, greater<int>> minHeap;
  minHeap.push(4);
  minHeap.push(2);
  minHeap.push(5);
  minHeap.push(3);

  cout << "Element at top: " << minHeap.top() << endl;
  minHeap.pop();
  cout << "Element at top: " << minHeap.top() << endl;
  cout << "Size: " << minHeap.size() << endl;
  if (minHeap.empty())
    cout << "Empty" << endl;
  else
    cout << "Not Empty" << endl;

  return 0;
}

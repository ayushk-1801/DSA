#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;
  int height;

  Node(int data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
    this->height = 1;
  }
};

int height(Node *root) {
  if (root == NULL)
    return 0;
  return root->height;
}

Node *rightRotate(Node *root) {
  Node *temp1 = root->left;
  Node *temp2 = temp1->right;

  temp1->right = root;
  root->left = temp2;

  root->height = max(height(root->left), height(root->right)) + 1;
  temp1->height = max(height(temp1->left), height(temp1->right)) + 1;

  return temp1;
}

Node *leftRotate(Node *root) {
  Node *temp1 = root->right;
  Node *temp2 = temp1->left;

  temp1->left = root;
  root->right = temp2;

  root->height = max(height(root->left), height(root->right)) + 1;
  temp1->height = max(height(temp1->left), height(temp1->right)) + 1;

  return temp1;
}

int getBalanceFactor(Node *root) {
  if (root == NULL)
    return 0;
  return height(root->left) - height(root->right);
}

Node *minNode(Node *node) {
  Node *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}

Node *insert(Node *root, int data) {
  if (root == NULL)
    return new Node(data);

  if (data < root->data)
    root->left = insert(root->left, data);
  else if (data > root->data)
    root->right = insert(root->right, data);
  else
    return root;

  root->height = 1 + max(height(root->left), height(root->right));

  int balanceFactor = getBalanceFactor(root);

  if (balanceFactor > 1 && data < root->left->data)
    return rightRotate(root);

  if (balanceFactor < -1 && data > root->right->data)
    return leftRotate(root);

  if (balanceFactor > 1 && data > root->left->data) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if (balanceFactor < -1 && data < root->right->data) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

Node *deleteNode(Node *root, int data) {
  if (root == NULL)
    return root;

  if (data < root->data)
    root->left = deleteNode(root->left, data);
  else if (data > root->data)
    root->right = deleteNode(root->right, data);
  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      Node *temp = root->left ? root->left : root->right;
      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      Node *temp = minNode(root->right);
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
    }
  }

  if (root == NULL)
    return root;

  root->height = 1 + max(height(root->left), height(root->right));
  int balanceFactor = getBalanceFactor(root);
  if (balanceFactor > 1) {
    if (getBalanceFactor(root->left) >= 0) {
      return rightRotate(root);
    } else {
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }
  if (balanceFactor < -1) {
    if (getBalanceFactor(root->right) <= 0) {
      return leftRotate(root);
    } else {
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
  }
  return root;
}

void preorder(Node *root) {
  if (root == NULL)
    return;

  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

int main() {
  Node *root = NULL;

  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);

  /* The constructed AVL Tree would be
            30
           /  \
          20   40
         /  \    \
        10  25    50
  */

  cout << "Initial tree: ";
  preorder(root);
  deleteNode(root, 40);
  cout << "\nAfter Deletion: ";
  preorder(root);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};


static void makelinear(struct node *tree, struct node **minRef, struct node **maxRef) {
  if (tree == NULL) {
    *minRef = NULL;
    *maxRef = NULL;
    return;
  }

  if (tree->left) {
    makelinear(tree->left, minRef, &tree->left);
    tree->left->right = tree;
  } else {
    *minRef = tree;
  }

  if (tree->right) {
    makelinear(tree->right, &tree->right, maxRef);
    tree->right->left = tree;
  } else {
    *maxRef = tree;
  }

  (*minRef)->left = *maxRef;
  (*maxRef)->right = *minRef;
}

static void add(struct node **treeRef, int data) {
  struct node *tree = *treeRef;
  if (tree == NULL) {
    struct node *p = calloc(1, sizeof(struct node));
    p->data = data;
    *treeRef = p;
  } else if (tree->data > data) {
    add(&tree->left, data);
  } else {
    add(&tree->right, data);
  }
}

static void printtree(struct node *tree) {
  if (tree == NULL)
    return;

  printtree(tree->left);
  printf("%d ", tree->data);
  printtree(tree->right);
}

static void printlist(struct node *head, bool backwards) {
  struct node *p = head;

  do {
    printf("%d ", p->data);
    if (backwards)
      p = p->left;
    else
      p = p->right;
  } while (p != head);

  putchar('\n');
}

int main(void) {
  struct node *tree = NULL;

  int data[] = {5, 4, 6, 2, 8, 1, 0, 9, 3, 7};
  for (int i = 0; i < sizeof(data) / sizeof(int); i++) {
    add(&tree, data[i]);
  }

  printtree(tree);
  putchar('\n');

  struct node *min;
  struct node *max;
  makelinear(tree, &min, &max);

  printlist(min, false);
  
  printlist(max, true);
  
  
  return 0;
}

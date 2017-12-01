#ifndef UTILS_H
#define UTILS_H

struct node {
  int data;
  struct node *next;
};

struct node *NewNode(int data);

struct node *NewList(int count, ...);

int Length(const struct node *head);

int Count(const struct node *head, int searchFor);

struct node *BuildOneTwoThree();

void Push(struct node **headRef, int newData);

int Pop(struct node **headRef);

int GetNth(const struct node *head, int index);

void Print(const struct node *head);

void Destroy(struct node **head);

void InsertNth(struct node **headRef, int index, int data);

void SortedInsert(struct node **headRef, struct node *newNode);

void InsertSort(struct node **headRef);

void Append(struct node **aRef, struct node **bRef);

void FrontBackSplit(struct node *source,
                    struct node **frontRef,
                    struct node **backRef);

/*
Remove duplicates from a sorted list.
 */
void RemoveDuplicates(struct node *head);

void MoveNode(struct node **aRef, struct node **bRef);

void AlternatingSplit(struct node *source,
                      struct node **aRef,
                      struct node **bRef);

struct node *ShuffleMerge(struct node *a, struct node *b);

struct node *SortedMerge(struct node *a, struct node *b);

void MergeSort(struct node **headRef);

struct node *SortedIntersect(struct node *a, struct node *b);

void Reverse(struct node **headRef);

void RecursiveReverse(struct node **headRef);

#endif

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include "utils.h"

int Length(const struct node *head) {
  int count;
  for (count = 0; head != NULL; head = head->next, ++count);
  return count;
}

struct node *BuildOneTwoThree() {
  struct node *p1 = malloc(sizeof(struct node));
  struct node *p2 = malloc(sizeof(struct node));
  struct node *p3 = malloc(sizeof(struct node));

  p1->data = 1, p1->next = p2;
  p2->data = 2, p2->next = p3;
  p3->data = 3, p3->next = NULL;

  return p1;
}

struct node *NewNode(int data) {
  struct node *p = calloc(sizeof(struct node), 1);
  p->data = data;
  return p;
}

struct node *NewList(int count, ...) {
  va_list ap;
  va_start(ap, count);

  struct node *p = NULL;
  while (count) {
    Push(&p, va_arg(ap, int));
    count--;
  }
  
  va_end(ap);

  Reverse(&p);
  return p;
}

void Push(struct node **headRef, int newData) {
  struct node *p = malloc(sizeof(struct node));
  p->data = newData;
  p->next = *headRef;
  *headRef = p;
}

void Print(const struct node *head) {
  putchar('{');

  for (; head != NULL && head->next != NULL; head = head->next)
    printf("%d, ", head->data);

  if (head != NULL)
    printf("%d", head->data);
  
  puts("}");
}

void Destroy(struct node **head) {
  struct node *current = *head;

  while (current != NULL) {
    struct node *next = current->next;
    free(current);
    current = next;
  }

  *head = NULL;
}

int Count(const struct node *head, int searchFor) {
  int count = 0;
  for (; head != NULL; head = head->next) {
    count += head->data == searchFor;
  }

  return count;
}

int GetNth(const struct node *head, int index) {
  while (index > 0 && head != NULL) {
    head = head->next;
    index--;
  }

  assert(head);
  return head->data;
}

int Pop(struct node **headRef) {
  assert(*headRef);
  
  struct node *current = *headRef;
  int result = current->data;

  *headRef = current->next;
  free(current);
  return result;
}

void InsertNth(struct node **headRef, int index, int data) {
  struct node **nextRef = headRef;
  
  while (index > 0) {
    nextRef = &(*nextRef)->next;
    index--;
  }

  Push(nextRef, data);
}

void SortedInsert(struct node **headRef, struct node *newNode) {
  struct node **nextRef = headRef;

  while (*nextRef != NULL && (*nextRef)->data <= newNode->data)
    nextRef = &(*nextRef)->next;

  newNode->next = *nextRef;
  *nextRef = newNode;
}

void InsertSort(struct node **headRef) {
  struct node *sorted = NULL;
  struct node *current = *headRef;

  while (current != NULL) {
    struct node *next = current->next;
    SortedInsert(&sorted, current);
    current = next;
  }
  
  *headRef = sorted;
}

void Append(struct node **aRef, struct node **bRef) {
  while (*aRef != NULL)
    aRef = &(*aRef)->next;

  *aRef = *bRef;

  *bRef = NULL;
}

void FrontBackSplit(struct node *source,
                    struct node **frontRef,
                    struct node **backRef) {
  *frontRef = source;

  if (source == NULL) {
    *backRef = NULL;
    return;
  }
  
  struct node *slow = source;
  struct node *fast = source->next;
  
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }

  *backRef = slow->next;
  slow->next = NULL;
}

/*
Remove duplicates from a sorted list.
 */
void RemoveDuplicates(struct node *head) {
  struct node *p = head;
  struct node *q = head;

  while (p != NULL) {
    while (q != NULL && q->data == p->data) {
      q = q->next;
    }
    p->next = q;
    p = q;
  }
}

void MoveNode(struct node **aRef, struct node **bRef) {
  struct node *tmp = *bRef;
  *bRef = tmp->next;

  tmp->next = *aRef;
  *aRef = tmp;
}

void AlternatingSplit(struct node *source, struct node **aRef, struct node **bRef) {
  while (1) {
    if (!source) return;
    MoveNode(aRef, &source);
    if (!source) return;
    MoveNode(bRef, &source);
  }
}

struct node *ShuffleMerge(struct node *a, struct node *b) {
  struct node *head = NULL;
  struct node **next = &head;

  while (a != NULL && b != NULL) {
    *next = a;
    a = a->next;
    next = &(*next)->next;

    *next = b;
    b = b->next;
    next = &(*next)->next;
  }

  if (a != NULL)
    *next = a;
  else
    *next = b;

  return head;
}

struct node *SortedMerge(struct node *a, struct node *b) {
  struct node *head = NULL;
  struct node **next = &head;
  struct node **p;

  while (a && b) {
    p = a->data <= b->data ? &a : &b;
    
    *next = *p;
    *p = (*p)->next;
    next = &(*next)->next;
  }

  if (a)
    *next = a;
  else
    *next = b;

  return head;
}

void MergeSort(struct node **headRef) {
  if (*headRef == NULL || (*headRef)->next == NULL)
    return;
  
  struct node *front;
  struct node *back;

  FrontBackSplit(*headRef, &front, &back);
  MergeSort(&front);
  MergeSort(&back);
  *headRef = SortedMerge(front, back);  
}

struct node *SortedIntersect(struct node *a, struct node *b) {
  struct node *head = NULL;
  struct node **next = &head;
  
  while (a && b) {
    if (a->data == b->data) {
      Push(next, a->data);

      next = &(*next)->next;
      a = a->next;
      b = b->next;
    } else if (a->data < b->data) {
      a = a->next;
    } else {
      b = b->next;
    }
  }

  return head;
}

void Reverse(struct node **headRef) {
  struct node *curr = *headRef;
  struct node *prev = NULL;

  while (curr != NULL) {
    struct node *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  *headRef = prev;
}

static void recrev(struct node **accRef, struct node *head) {
  if (head) {
    MoveNode(accRef, &head);
    recrev(accRef, head);
  }
}

void RecursiveReverse(struct node **headRef) {
  struct node *acc = NULL;
  recrev(&acc, *headRef);
  *headRef = acc;
}

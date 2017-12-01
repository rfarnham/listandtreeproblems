#include <stdio.h>

#include "utils.h"

void CountTest() {
  struct node *myList = BuildOneTwoThree();
  printf("%d\n", Count(myList, 2));
}

void GetNthTest() {
  struct node *myList = BuildOneTwoThree();
  printf("%d\n", GetNth(myList, 2));
}

void DeleteListTest() {
  struct node *myList = BuildOneTwoThree();
  Destroy(&myList);
}

void PopTest() {
  struct node *head = BuildOneTwoThree();
  int a = Pop(&head);
  int b = Pop(&head);
  int c = Pop(&head);
  int len = Length(head);

  printf("a = %d, b = %d, c = %d, len = %d\n", a, b, c, len);
}

void InsertNthTest() {
  struct node *head = NULL;

  InsertNth(&head, 0, 13);
  InsertNth(&head, 1, 42);
  InsertNth(&head, 1, 5);

  Print(head);
  Destroy(&head);
}

void SortedInsertTest() {
  struct node *head = BuildOneTwoThree();

  SortedInsert(&head, NewNode(10));
  SortedInsert(&head, NewNode(0));
  SortedInsert(&head, NewNode(6));

  Print(head);

  Destroy(&head);

  for (int i = 10; i > 0; i--)
    SortedInsert(&head, NewNode(i));

  Print(head);

  Destroy(&head);
}

void InsertSortTest() {
  struct node *head = NULL;

  Push(&head, 4);
  InsertSort(&head);
  Print(head);
  // {4}
  Destroy(&head);

  Push(&head, 4);
  Push(&head, 1);
  InsertSort(&head);
  Print(head);
  // {1, 4}
  Destroy(&head);

  Push(&head, 4);
  Push(&head, 1);
  Push(&head, 5);
  Push(&head, 2);
  Push(&head, 0);
  InsertSort(&head);
  Print(head);
  // {0, 1, 2, 4, 5}
  Destroy(&head);
}

void AppendTest() {
  struct node *a = BuildOneTwoThree();
  struct node *b = BuildOneTwoThree();

  Append(&a, &b);
  printf("a = "); Print(a);
  printf("b = "); Print(b);

  Append(&b, &a);
  printf("a = "); Print(a);
  printf("b = "); Print(b);

  Destroy(&a);
  Destroy(&b);

  Append(&a, &b);
  printf("a = "); Print(a);
  printf("b = "); Print(b);
}

void FrontBackSplitTest() {
  struct node *source = NULL;
  struct node *front = NULL;
  struct node *back = NULL;

#define DO(n, ...)                              \
  source = NewList(n, ##__VA_ARGS__);           \
  printf("source = "); Print(source);           \
  FrontBackSplit(source, &front, &back);        \
  printf("front = "); Print(front);             \
  printf("back = "); Print(back);               \
  Destroy(&front); Destroy(&back);

  DO(0);
  DO(1, 1);
  DO(2, 1, 2);
  DO(3, 1, 2, 3);
  DO(4, 1, 2, 3, 4);

#undef DO
  
}

void RemoveDuplicatesTest() {
  struct node *head = NULL;

#define DO(...)                                 \
  head = NewList(__VA_ARGS__);                  \
  Print(head);                                  \
  RemoveDuplicates(head);                       \
  Print(head);                                  \
  puts(".");                                    \
  Destroy(&head);

  DO(0);
  DO(1, 1);
  DO(2, 1, 1);
  DO(2, 1, 2);
  DO(3, 1, 1, 1);
  DO(3, 1, 1, 2);
  DO(7, 1, 2, 2, 3, 4, 4, 5);

#undef DO
  
}

void MoveNodeTest() {
  struct node *a = BuildOneTwoThree();
  struct node *b = BuildOneTwoThree();

  MoveNode(&a, &b);
  Print(a);
  Print(b);
  Destroy(&a);
  Destroy(&b);
}

void AlternatingSplitTest() {
  struct node *list = NULL;
  struct node *a = NULL;
  struct node *b = NULL;

#define DO(...)                                 \
  list = NewList(__VA_ARGS__);                  \
  Print(list);                                  \
  AlternatingSplit(list, &a, &b);               \
  printf("a = "); Print(a);                     \
  printf("b = "); Print(b);                     \
  puts(".");                                    \
  Destroy(&a);                                  \
  Destroy(&b);

  DO(1, 1);
  DO(2, 1, 2);
  DO(3, 1, 2, 1);
  DO(4, 1, 2, 1, 2);
  DO(5, 1, 2, 1, 2, 1);
  DO(6, 1, 2, 3, 4, 5, 6);
  
#undef DO
}

void ShuffleMergeTest() {
  struct node *a;
  struct node *b;
  struct node *p;

  a = NULL;
  b = NULL;
  p = ShuffleMerge(a, b);
  Print(p);
  Destroy(&p);

  a = NewList(1, 1);
  b = NULL;
  p = ShuffleMerge(a, b);
  Print(p);
  Destroy(&p);

  a = NULL;
  b = NewList(1, 1);
  p = ShuffleMerge(a, b);
  Print(p);
  Destroy(&p);

  a = NewList(1, 1);
  b = NewList(1, 2);
  p = ShuffleMerge(a, b);
  Print(p);
  Destroy(&p);

  a = NewList(3, 1, 2, 3);
  b = NewList(3, 4, 5, 6);
  p = ShuffleMerge(a, b);
  Print(p);
  Destroy(&p);
}

void SortedMergeTest() {
  struct node *a;
  struct node *b;
  struct node *p;

  a = NULL;
  b = NULL;
  p = SortedMerge(a, b);
  Print(p);
  Destroy(&p);

  a = NewList(1, 1);
  b = NULL;
  p = SortedMerge(a, b);
  Print(p);
  Destroy(&p);

  a = NULL;
  b = NewList(1, 1);
  p = SortedMerge(a, b);
  Print(p);
  Destroy(&p);

  a = NewList(3, 1, 3, 5);
  b = NewList(3, 2, 4, 6);
  p = SortedMerge(a, b);
  Print(p);
  Destroy(&p);

  a = NewList(5, 1, 2, 5, 6, 7);
  b = NewList(4, 3, 4, 8, 9);
  p = SortedMerge(a, b);
  Print(p);
  Destroy(&p);
    
}

void MergeSortTest() {
  struct node *list;

#define DO(...)                                 \
  list = NewList(__VA_ARGS__);                  \
  Print(list);                                  \
  MergeSort(&list);                             \
  Print(list);                                  \
  Destroy(&list);                               \
  puts(".");

  DO(0);
  DO(1, 1);
  DO(2, 2, 1);
  DO(5, 1, 4, 2, 3, 5);
  DO(10, 4, 5, 3, 2, 1, 6, 0, 7, 9, 8);
  
#undef DO
  
}

void SortedIntersectTest() {
  struct node *a;
  struct node *b;
  struct node *p;

#define DO()                                    \
  p = SortedIntersect(a, b);                    \
  Print(p);                                     \
  Destroy(&a);                                  \
  Destroy(&b);                                  \
  Destroy(&p);                                  \

  a = NULL;
  b = NULL;
  DO();

  a = NewList(1, 1);
  b = NULL;
  DO();

  a = NULL;
  b = NewList(1, 1);
  DO();

  a = NewList(1, 1);
  b = NewList(1, 2);
  DO();

  a = NewList(1, 1);
  b = NewList(1, 1);
  DO();

  a = NewList(6, 1, 4, 5, 6, 7, 9);
  b = NewList(4, 2, 5, 7, 9);
  DO();

#undef DO
}

void ReverseTest() {
  struct node *p = NewList(5, 1, 2, 3, 4, 5);
  Reverse(&p);
  Print(p);
  Destroy(&p);
}

void RecursiveReverseTest() {
  struct node *p = NewList(5, 1, 2, 3, 4, 5);
  RecursiveReverse(&p);
  Print(p);
  Destroy(&p);
}

#define TEST(function)                          \
  printf("%s\n", #function);                    \
  printf("=================\n");                \
  function();                                   \
  putchar('\n');                                                                                

int main(void) {
  TEST(CountTest);
  TEST(GetNthTest);
  TEST(DeleteListTest);
  TEST(PopTest);
  TEST(InsertNthTest);
  TEST(SortedInsertTest);
  TEST(InsertSortTest);
  TEST(AppendTest);
  TEST(FrontBackSplitTest);
  TEST(RemoveDuplicatesTest);
  TEST(MoveNodeTest);
  TEST(AlternatingSplitTest);
  TEST(ShuffleMergeTest);
  TEST(SortedMergeTest);
  TEST(MergeSortTest);
  TEST(SortedIntersectTest);
  TEST(ReverseTest);
  TEST(RecursiveReverseTest);
}
  

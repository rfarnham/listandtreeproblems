#include <stdio.h>

#include "utils.h"

void BasicCaller() {
  struct node *head;
  int len;

  head = BuildOneTwoThree(); // Start with {1, 2, 3}
  Print(head);

  Push(&head, 13);           // Push 13 on the front, yielding {13, 1, 2, 3}
                             // (The '&' is because head is passed
                             // as a reference pointer.)
  Print(head);

  Push(&(head->next), 42);   // Push 42 into the second position
                             // yielding {13, 42, 1, 2, 3}
                             // Demonstrates a use of '&' on
                             // the .next field of a node.
                             // (See technique #2 below.)

  Print(head);

  len = Length(head);        // Computes that the length is 5.

  printf("Length = %d\n", len);

  Destroy(&head);
}

struct node *BuildWithSpecialCase() {
  struct node *head = NULL;
  struct node *tail;

  // Deal with the head node here, and set the tail pointer
  Push(&head, 1);
  tail = head;

  // Do all the other nodes using 'tail'
  for (int i = 2; i < 6; i++) {
    Push(&(tail->next), i); // add node at tail->next
    tail = tail->next;      // advance tail to point to last node
  }

  return head; // head == {1, 2, 3, 4, 5};
}

struct node *BuildWithDummyNode() {
  struct node dummy = {0};    // Dummy node is temporarily the first node

  struct node *tail = &dummy; // Start the tail at the dummy.
                              // Build the list on the dummy.next (aka tail->next)

  for (int i = 1; i < 6; i++) {
    Push(&(tail->next), i);
    tail = tail->next;
  }

  // The real result list is now in dummy.next
  // dummy.next == {1, 2, 3, 4, 5}
  return dummy.next;
}

struct node *BuildWithLocalRef() {
  struct node *head = NULL;
  struct node **lastPtrRef = &head; // Start out pointing to the head pointer

  for (int i = 1; i < 6; i++) {
    Push(lastPtrRef, i); // Add node at the last pointer in the list
    lastPtrRef = &((*lastPtrRef)->next); // Advance to point to the
                                         // new last pointer
  }

  // head == {1, 2, 3, 4, 5}
  return head;
}

int main(void) {
  BasicCaller();

  struct node *p1 = BuildWithSpecialCase();
  Print(p1);
  Destroy(&p1);

  struct node *p2 = BuildWithDummyNode();
  Print(p2);
  Destroy(&p2);

  struct node *p3 = BuildWithLocalRef();
  Print(p3);
  Destroy(&p3);
  
  return 0;
}

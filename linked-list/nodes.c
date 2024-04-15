#include "headers/nodes.h"
#include "stdio.h"
#include "stdlib.h"

/*
TODO error handling
*/

struct Node *create_node() {
  struct Node *node = malloc(sizeof(struct Node));
  node->next_node = NULL;
  node->value = 0;
  return node;
}

void push(struct Node *head, int value) {
  struct Node* next_node = create_node();
  struct Node* current = head;
  while (current->next_node) {
    current = current->next_node;
  }
  next_node->value = value;
  current->next_node = next_node;

}

void pop(struct Node** head) {
  struct Node* removed_node;
  struct Node* current = *head;
  // if head is last node in linked list
  if ((*head)->next_node == NULL) {
    struct Node* old_head = *head;
    *head = NULL;
    free(old_head);
    return;
  }

  while(current->next_node->next_node) {
    current = current->next_node;
  }
  removed_node = current->next_node;
  current->next_node = NULL;
  free(removed_node);
}

void print_list(struct Node *head) {
  struct Node* current = head;
  if (head == NULL) {
    return;
  }
  while(current->next_node) {
    printf("%d -> ", current->value);
    current = current->next_node;
  }
  printf("%d\n", current->value);
}

void free_node_mem(struct Node* head) {
  struct Node* current = head;
  while(current) {
    struct Node* prev_node = current;
    current = current->next_node;
    free(prev_node);
  }
}

void append_at_index(struct Node **head, int index, int value) {
  int iteration = 0;
  struct Node* current = *head;
  struct Node* new_node = create_node();
  new_node->value = value;

  if (index == 0) {
    new_node->next_node = current;
    *head = new_node;
    return;
  }
  while(current) {
    if (iteration >= index - 1) {
      new_node->next_node = current->next_node;
      current->next_node = new_node;
      return;
    }
    iteration++;
    current = current->next_node;
  }
}

void remove_at_index(struct Node **head, int index) {
  int iteration = 0;
  struct Node *current = *head;

  if (index == 0) {
    *head = current->next_node;
    free(current);
    return;
  }

  while (current) {
    if (iteration >= index - 1) {
      struct Node* removed_node = current->next_node;
      current->next_node = current->next_node->next_node;
      free(removed_node); 
      return;
    }
    iteration++;
    current = current->next_node;
  }
}


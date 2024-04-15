#ifndef NODE
#define NODE

struct Node {
  int value;
  struct Node *next_node;
};

extern struct Node *create_node();

extern void free_node_mem(struct Node *head);

extern void push(struct Node *head, int value);

extern void pop(struct Node **head);

extern void print_list(struct Node *head);

extern void append_at_index(struct Node **head, int index, int value);

extern void remove_at_index(struct Node **head, int index);

#endif
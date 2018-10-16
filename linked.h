struct song_node{ 
  char name[100];
  char artist[100];
  struct song_node *next;
};

void print_list(struct song_node *head);
struct song_node *insert_front(struct song_node *current, char *artist, char *name);
void insert_order(struct song_node *head, char *artist, char *name);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct song_node{ 
  char name[100];
  char artist[100];
  struct song_node *next;
};

struct  song_node *insert_front(struct song_node *current, char *artist, char *name);
struct song_node *insert_order(struct song_node *head, char *artist, char *name);
struct song_node * find_node(struct song_node *head, char *artist, char *name);
struct song_node * find_artist(struct song_node *head, char *artist);
struct song_node *remove_song(struct song_node *head, char *artist, char *name);
struct  song_node *remove_song(struct song_node *head, char *artist, char *name);
struct  song_node *free_list(struct song_node *head);
struct song_node *random_element(struct song_node *head);
void    print_list(struct song_node *head);
int list_length(struct song_node *head);

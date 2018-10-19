#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked.h"

void print_library(struct song_node *library[]);
void add_song(struct song_node * library[], char *artist, char *name);
void print_letter(struct song_node * library[], char letter);
void print_artist(struct song_node *library[], char *artist);
struct song_node *search(struct song_node *library[], char *artist, char *name);
struct song_node *search_artist(struct song_node * library[], char *artist);
void remove_song(struct song_node *library[], char *artist, char *name);
void shuffle(struct song_node *library[], int number_songs);
void free_library(struct song_node *library[]);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked.h"

void print_library();
void add_song(char *artist, char *name);
void print_letter(char letter);
struct song_node *search(char *artist, char *name);
struct song_node *search_artist(char *artist);
void remove_song(char *artist, char *name);
void shuffle(int number_songs);

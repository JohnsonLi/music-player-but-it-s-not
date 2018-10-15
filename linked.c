#include <stdio.h>
#include <stdlib.h>

struct song_node{ 
  char name[100];
  char artist[100];
  struct song_node *next;
};

void print_list(struct song_node *head){
    while(head){
        printf("%s: %s |", head->artist, head->name);
        head = head->next;
    }
    printf("\n");    
    return;
}

struct song_node * insert_front(struct song_node *current, char *artist, char *name){
    struct song_node * to_add = malloc(sizeof(struct song_node));
    to_add -> name = name;
    to_add -> artist = artist;
    return to_add;
}

int main(){



    return 0;
}
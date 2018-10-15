#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node{ 
  char name[100];
  char artist[100];
  struct song_node *next;
};

void print_list(struct song_node *head){
    while(head){
        printf(" %s: %s |", head->artist, head->name);
        head = head->next;
    }
    printf("\n");    
    return;
}

struct song_node *insert_front(struct song_node *current, char *artist, char *name){
    struct song_node * to_add = malloc(sizeof(struct song_node));
    strcpy(to_add->artist, artist);
    strcpy(to_add->name, name);
    to_add -> next = current;
    return to_add;
}

void insert_order(struct song_node *head, char *artist, char *name){
    struct song_node * to_add = malloc(sizeof(struct song_node));
    to_add -> name = name;
    to_add -> artist = artist;
    
    while(strcmp(artist, head->artist) <= 0){
      

    }
}

int main(){

    struct song_node *head = malloc(sizeof(struct song_node));
    strcpy(head->artist, "Haydn");
    strcpy(head->name, "Trumpet Concerto");
    head = insert_front(head, "Beethoven", "Moonlight Sonata");
    
    print_list(head);


    return 0;
}
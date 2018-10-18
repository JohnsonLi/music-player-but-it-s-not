#include "linked.h"

struct song_node * library[27];

void print_library(){
    int i;
    for(i = 0; i < 27; i++){
        if(library[i]){
            printf("%c library:\n\t", library[i]->artist[0]);
            print_list(library[i]);
        }
    }
}

void add_song(struct song_node *to_add){
    // 97 is ascii value of 'a'
    int index = to_add->artist[0] % 97;
    if(library[index]){
        insert_order(library[index], to_add->artist, to_add->name);
    } else {
        library[index] = to_add;
    }
}

int main(){

    struct song_node *a = malloc(sizeof(struct song_node));
    strcpy(a->artist, "haydn");
    strcpy(a->name, "trumpet concerto");

    struct song_node *b = malloc(sizeof(struct song_node));
    strcpy(b->artist, "yeethoven");
    strcpy(b->name, "roomba sonata");

    print_library();
    add_song(a);
    add_song(b);
    print_library();
    


    return 0;
}
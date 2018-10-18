#include "linked.h"

struct song_node * library[27];

void print_library(){
    int i;
    for(i = 0; i < 27; i++){
        if(library[i]){
            printf("%c list:\n\t", library[i]->artist[0]);
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

void print_letter(char letter){
    int index = letter % 97;
    printf("%c list:\n\t", letter);
    print_list(library[index]);
}

struct song_node *search(char *artist, char *name){
    int index = artist[0] % 97;
    
    printf("looking for [%s: %s]\n", artist, name);

    if(library[index]){
        struct song_node *head = library[index];
        struct song_node *found = find_node(head,artist,name);
        if(found){
            printf("song found! %s: %s\n", found->artist, found->name);
            return found;
        }
        /*
        while(head){
            if(head->artist == artist && head->name == name){
                printf("song found! %s %s", head->artist, head->name);
                return head;
            }
            head = head->next;
        }
        */
    }
    printf("song not found\n");
    return NULL;
}

int main(){

    struct song_node *a = malloc(sizeof(struct song_node));
    strcpy(a->artist, "haydn");
    strcpy(a->name, "trumpet concerto");

    struct song_node *aa = malloc(sizeof(struct song_node));
    strcpy(aa->artist, "bydn");
    strcpy(aa->name, "trumpet contorto");

    struct song_node *b = malloc(sizeof(struct song_node));
    strcpy(b->artist, "yeethoven");
    strcpy(b->name, "roomba sonata");

    struct song_node *c = malloc(sizeof(struct song_node));
    strcpy(c->artist, "yeethoven");
    strcpy(c->name, "trumpet concerto");

    // print_library();

    add_song(a);
    add_song(aa);
    add_song(b);
    add_song(c);

    print_library();

    search("yeethoven", "roomba sonata");


    // print_letter('h');
    


    return 0;
}
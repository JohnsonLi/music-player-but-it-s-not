#include "linked.h"

struct song_node * library[27];

void print_library(){
    int i;
    for(i = 0; i < 27; i++){
        if(library[i]){
            if (i==26){
                printf("special characters list:\n");
            }
            else{
                printf("%c list:\n\t", library[i]->artist[0]);
            }
            print_list(library[i]);
            printf("\n");
        }
    }
}

void add_song(struct song_node *to_add){
    // 97 is ascii value of 'a'
    int index = to_add->artist[0]-97;
    if (index>25 || index<0){
        index = 26;
    }
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
    
    // printf("looking for [%s: %s]\n", artist, name);

    if(library[index]){
        struct song_node *found = find_node(library[index],artist,name);
        if(found){
            // printf("song found! %s: %s\n", found->artist, found->name);
            return found;
        }
    }
    // printf("song not found\n");
    return NULL;
}

struct song_node *search_artist(char *artist){
    int index = artist[0] % 97;
    
    //printf("looking for [%s]\n", artist);

    if(library[index]){
        struct song_node *found = find_artist(library[index], artist);
        if(found){
            // printf("artist found!");
            return found;
        }
    }
    return NULL;
}

void remove_song(char *artist, char *name){
    int index = artist[0] % 97;

    if(search(artist, name)){
        library[index]=remove_node(library[index], artist, name);
    }

}

void shuffle(int number_songs){
    int i;
    int r;
    for(i = 0; i < number_songs; i++){
        while(r){
            r=rand()%27;
        }
        print_node(random_element(library[r]));
        r=0;
    }

}

int main(){
    srand(time(NULL));
    struct song_node *a = malloc(sizeof(struct song_node));
    strcpy(a->artist, "haydn");
    strcpy(a->name, "trumpet concerto");

    struct song_node *aa = malloc(sizeof(struct song_node));
    strcpy(aa->artist, "bydn");
    strcpy(aa->name, "trumpet contorto");

    struct song_node *b = malloc(sizeof(struct song_node));
    strcpy(b->artist, "eeethoven");
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

    //print_node(search("yeethoven", "roomba sonata"));
    remove_song("eeethoven","roomba sonata");
    print_library();

    // print_letter('h');
    


    return 0;
}
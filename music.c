#include "music.h"

void print_library(struct song_node *library[]){
    int i;
    for(i = 0; i < 27; i++){
        if(library[i]){
            if (i == 26){
                printf("special characters list:\n");
            }
            else{
                printf("%s\n", library[i]->artist);
                printf("%c list:\n\t", library[i]->artist[0]);
            }
            print_list(library[i]);
            printf("\n");
        }
    }

}

void add_song(struct song_node * library[], char *artist, char *name){
    struct song_node *to_add = malloc(sizeof(struct song_node));
    strcpy(to_add->artist,artist);
    strcpy(to_add->name,name);
    // 97 is ascii value of 'a'
    int index = to_add->artist[0]-97;
    if (index>25 || index<0){
        index = 26;
    }
    if(library[index]){
        library[index] = insert_order(library[index], artist, name);
    } else {
        library[index] = to_add;
    }
}

void print_letter(struct song_node * library[], char letter){
    int index = letter % 97;
    printf("%c list:\n\t", letter);
    print_list(library[index]);
}

struct song_node *search_artist(struct song_node * library[], char *artist){
    int index = artist[0] % 97;
    
    printf("looking for [%s]\n", artist);

    if(library[index]){
        struct song_node *found = find_artist(library[index], artist);
        if(found){
            printf("artist found! %s", found->artist);
            return found;
        }
    }
    printf("artist not found");
    return NULL;
}

void print_artist(struct song_node * library[], char *artist){
    struct song_node *location = search_artist(library, artist);
    printf("%s list:\n", artist);
    while(location){
        if(strcmp(location->artist, artist) == 0){
            printf("\t");
            print_node(location);
        }
        location = location->next;
    }
}

struct song_node *search(struct song_node * library[], char *artist, char *name){
    int index = artist[0] % 97;
    
    printf("looking for [%s: %s]\n", artist, name);

    if(library[index]){
        struct song_node *found = find_node(library[index], artist, name);
        if(found){
            printf("song found! %s: %s\n", found->artist, found->name);
            return found;
        }
    }
    printf("song not found\n");
    return NULL;
}

void remove_song(struct song_node * library[], char *artist, char *name){
    int index = artist[0] % 97;

    if(search(library, artist, name)){
        library[index]=remove_node(library[index], artist, name);
    }

}

void shuffle(struct song_node * library[], int number_songs){
    
    int i;
    for(i = 0; i < number_songs; i++){
        int number = rand() % 27;
        while(!library[number]){
            number = rand() % 27;
        }
        print_node(library[number]);
    }

}

void free_library(struct song_node * library[]){
    int i;
    for(i = 0; i < 27; i++){
        library[i] = free_list(library[i]);
    }
}

// int main(){

// //     add_song("haydn","trumpet concerto");
// //     add_song("bydn","trumpet contorto");
// //     add_song("beethoven","roomba sonata");
// //     add_song("beethoven","roomba sonata1");
// //     add_song("beethovena","roomba sonefwefata2");
// //     add_song("yeethoven","trumpet concerto");
// //     add_song("&yeethoven","trumpet concerto");
//     struct song_node *library[27];
//     print_library(library);

// //     printf("freeing\n");
// //     free_library();

//     // print_library();

// //     print_list(search_artist("beethoven"));
// //     print_node(search("yeethoven", "roomba sonata"));
// //     remove_song("beethoven","roomba sonata");
// //     print_library();

// //     shuffle(5);

// //     print_artist("beethoven");
//     //s


//     return 0;
// }
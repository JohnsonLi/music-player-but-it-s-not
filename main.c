#include "music.h"

int main(){
    srand(time(NULL));

    printf("LINKED LIST TESTS\n"); 
    printf("====================================\n");

    struct song_node * head = malloc(sizeof(struct song_node));
    strcpy(head->artist, "beethoven");
    strcpy(head->name, "moonlight sonata");
    printf("Printing list:\n");
    print_list(head);

    printf("\n");

    struct song_node * a = malloc(sizeof(struct song_node));
    strcpy(a->artist, "aaaa");
    strcpy(a->name, "a song");
    struct song_node * b = malloc(sizeof(struct song_node));
    strcpy(b->artist, "bbbb");
    strcpy(b->name, "b song");
    struct song_node * c = malloc(sizeof(struct song_node));
    strcpy(c->artist, "aaaa");
    strcpy(c->name, "z song");
    printf("TESTING CMP HELPER\n");
    printf("comparing [%s: %s] to [%s: %s]:\n    result: %d\n", a->artist, a->name, b->artist, b->name, cmp_helper(a, b));
    printf("comparing [%s: %s] to [%s: %s]:\n    result: %d\n", b->artist, b->name, a->artist, a->name, cmp_helper(b, a));
    printf("comparing [%s: %s] to [%s: %s]:\n    result: %d\n", a->artist, a->name, c->artist, c->name, cmp_helper(a, c));

    printf("\n");

    printf("TESTING INSERT FRONT\n");
    head = insert_front(head, "benjamin britten", "the young person's guide to the orchestra");
    print_list(head);
    printf("\n");
    printf("TESTING INSERT ORDER\n");
    printf("adding something that would go in the front(albinoni: adagio for organ and strings):\n");
    head = insert_order(head, "albinoni", "adagio for organ and strings");
    print_list(head);
    printf("\n");
    printf("adding something that would go in the back (yeethoven: goomba sonata):\n");
    head = insert_order(head, "yeethoven", "goomba sonata");
    print_list(head);
    printf("\n");
    printf("adding same artist but different song(yeethoven: roomba sonata):\n");
    head = insert_order(head, "yeethoven", "roomba sonata");
    print_list(head);   
    printf("\n");

    printf("TESTING FIND NODE\n");
    find_node(head, "beethoven", "moonlight sonata");
    printf("\n");
    find_node(head, "albinoni", "adagio for organ and strings");
    printf("\n");
    find_node(head, "beethoven", "the fifth");
    printf("\n");

    printf("TESTING FIND ARTIST\n");
    find_artist(head, "albinoni");
    printf("\n");
    find_artist(head, "yeethoven");
    printf("\n");
    find_artist(head, "mozart");
    printf("\n");

    printf("TESTING RANDOM NODE (seeded with time)\n");
    struct song_node *random = random_element(head);
    printf("Random node: [%s: %s]\n", random->artist, random->name);
    printf("\n");

    printf("TESTING REMOVE NODE\n");
    printf("original list:\n");
    print_list(head);
    printf("\n");
    printf("removing [benjamin britten: the young person's guide to the orchestra\n");
    head = remove_node(head, "benjamin britten", "the young person's guide to the orchestra");
    printf("list now:\n");
    print_list(head);
    printf("\n");
    printf("removing [yeethoven: roomba sonata]\n");
    head = remove_node(head, "yeethoven", "roomba sonata");
    printf("list now:\n");
    print_list(head);
    printf("\n");

    printf("TESTING FREE\n");
    printf("current list:\n");
    print_list(head);
    printf("freeing list...\n");
    printf("list now:\n");
    print_list(free_list(head));

    printf("MUSIC LIBRARY TESTS\n");
    printf("====================================\n");

    struct song_node *library[27];
    int i;
    for(i; i<27;i++){
    	library[i]=malloc(sizeof(struct song_node));
    }
    printf("current library(empty):\n");
    //print_library(library);

    printf("TESTING ADD:\n");
    printf("adding [beethoven: moonlight sonata]\n");
    add_song(library, "beethoven", "moonlight sonata");
    printf("current library:\n");
    print_library(library);

    printf("adding [yeethoven: moonlight sonata]\n");
    add_song(library, "yeethoven", "moonlight sonata");
    printf("adding [mozart: requiem]\n");
    add_song(library, "mozart", "requiem");
    printf("adding [haydn: trumpet concerto]\n");
    add_song(library, "haydn", "trumpet concerto");

    printf("TESTING SEARCH:\n");
    search(library, "mozart", "requiem");
    printf("\n");
    search(library, "mozaaaaart", "requiem");
    printf("\n");

    printf("TESTING SEARCH ARTIST:\n");
    search_artist(library, "beethoven");
    printf("\n");
    search_artist(library, "beeeeeethoven");
    printf("\n");

    printf("TESTING PRINT LETTER:\n");
    printf("printing b:\n");
    print_letter(library, 'b');
    printf("printing z: (not in library)\n");
    print_letter(library, 'z');
    printf("\n");

    printf("TESTING PRINT ARTIST:\n");
    printf("printing mozart:\n");
    print_artist(library, "mozart");
    printf("\n");
    printf("printing bach: (not in library)\n");
    printf("\n");

    printf("TESTING SHUFFLE:\n");
    printf("shuffling, giving 3 songs:\n");
    shuffle(library, 3);
    printf("shuffling, giving 4 songs:\n");
    shuffle(library, 4);

    printf("TESTING DELETE:\n");
    printf("current library:\n");
    print_library(library);
    printf("\n");
    printf("removing beethoven: moonlight sonata:\n");
    remove_song(library, "beethoven", "moonlight sonata");
    printf("\n");
    printf("library now:\n");
    print_library(library);

    printf("TESTING CLEARING:\n");
    printf("clearing library...\n");
    free_library(library);
    printf("library now:\n");
    print_library(library);
}


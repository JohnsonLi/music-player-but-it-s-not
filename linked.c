#include "linked.h"

void print_list(struct song_node *head){
    while(head){
        printf(" %s: %s |", head->artist, head->name);
        head = head->next;
    }
    printf("\n");    
    return;
}

void print_node(struct song_node *node){
    printf("%s: %s\n", node->artist, node->name);
}

struct song_node *insert_front(struct song_node *current, char *artist, char *name){
    struct song_node * to_add = malloc(sizeof(struct song_node));
    strcpy(to_add->artist, artist);
    strcpy(to_add->name, name);
    to_add->next = current;
    return to_add;
}

int cmp_helper(struct song_node *hi, struct song_node *bye){
    if(strcmp(hi->artist, bye->artist) == 0){
        return strcmp(hi->name, bye->name);
    }
    return strcmp(hi->artist, bye->artist);
}


struct song_node *insert_order(struct song_node *head, char *artist, char *name){
    struct song_node *front = head;
    struct song_node *prev;
	struct song_node *to_add=malloc(sizeof(struct song_node));
	strcpy(to_add->artist, artist);
    strcpy(to_add->name, name);

    if (cmp_helper(to_add, head) <= 0){
    	return insert_front(head, artist, name);
    }
	
    while(front->next && cmp_helper(to_add, front) >= 0){
        struct song_node *temp = front;
        front = front->next;
        prev = front;
    }

    if(!front->next){
        front->next = to_add;
        return head;
    }

    struct song_node *added = insert_front(front, artist, name);
    added->next = front;
    prev->next = added;

    return head;
}

struct song_node * find_node(struct song_node *head, char *artist, char *name){
    printf("looking for [%s: %s]\n", artist, name);
	while(head){
		if (strcmp(head->artist,artist) == 0 && strcmp(head->name,name) == 0){
            printf("node found! %s: %s\n", head->artist, head->name);
			return head;
		}
        head = head->next;
	}
    printf("node not found\n");
	return NULL;
}

struct song_node * find_artist(struct song_node *head, char *artist){
    printf("looking for [%s]\n", artist);
	while(head){
		if (strcmp(head->artist, artist) == 0){
            printf("artist found!");
            print_list(head);
			return head;
		}
        head = head->next;
	}
    printf("artist not found\n");
	return NULL;
}

struct song_node *remove_node(struct song_node *head, char *artist, char *name){
    struct song_node *front = head;
    struct song_node *prev;
    if(strcmp(head->artist,artist) == 0 && strcmp(head->name,name) == 0){
        return head->next;
    }
    while(front->next){
        if (strcmp(front->artist,artist) == 0 && strcmp(front->name,name) == 0){
            prev->next = front->next;
            return head;
        }
        prev = front;
        front = front->next;
    }
    if (strcmp(front->artist,artist) == 0 && strcmp(front->name,name) == 0){
        if(!front->next){
            prev->next = NULL;
        }        
    }
    return head;
}

struct song_node *free_list(struct song_node *head){
    struct song_node *current = head;
    struct song_node *temp = head;

    while(current){
        temp = current->next;
        free(current);
        current = temp;
    }
    return current;
}

int list_length(struct song_node *head){
    int counter = 1;
    while(head->next){
        counter += 1;
        head = head->next;
    }
    return counter;
}

struct song_node *random_element(struct song_node *head){
    int random = rand() % list_length(head);
    struct song_node *current = head;
    int i;
    for(i = 0; i < random; i++){
        current = current->next;
    }
    return current;
}

// int main(){

//     struct song_node *head = malloc(sizeof(struct song_node));
//     strcpy(head->artist, "haydn");
//     strcpy(head->name, "trumpet concerto");
//     head =insert_order(head, "beethoven", "moonlight sonata");
//     head =insert_order(head, "z", "dwd");
//     head =insert_order(head, "z", "a");
//     head = insert_order(head, "a", "a");
//     print_list(head);
//     printf("%d\n", list_length(head));
//     head =remove_song(head,"beethoven","moonlight sonata");
//     print_list(head);
//     head = free_list(head);
//     print_list(head);
//     printf("%d\n", list_length(head));
//     struct song_node *random = random_element(head);
//     printf("Random element- Artist: %s, Song: %s\n", random->artist, random->name);

//     print_list(head);


//     return 0;
// }
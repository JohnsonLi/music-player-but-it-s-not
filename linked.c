#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



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
    to_add->next = current;
    return to_add;
}

struct song_node *insert_order(struct song_node *head, char *artist, char *name){
	struct song_node *front = head;
	struct song_node *to_add=malloc(sizeof(struct song_node));
	strcpy(to_add->artist, artist);
    strcpy(to_add->name, name);
    if (!front->next){
    	if(strcmp(artist,front->artist)<0||(strcmp(artist,front->artist)==0&&strcmp(name,front->name)<0)){
    		return insert_front(front,artist,name);
    	}
    	else{
    		front->next=to_add;
    		return front;
    	}
    }
	while(front->next){
		if (strcmp(artist,front->next->artist)<0){
			to_add->next=front->next;
			front->next=to_add;
			return head;
		}
		if(strcmp(artist,front->next->artist)==0){
			if(strcmp(name,front->next->name)<0){
				to_add->next=front->next;
				front->next=to_add;
				return head;
			}
			else{
				to_add->next=front->next;
				front->next=to_add->next;
				return head;
			}
		}
		front=front->next;
	}
    front->next=to_add;
	return head;
    // struct song_node * to_add = malloc(sizeof(struct song_node));
    // strcpy(to_add->artist, artist);
    // strcpy(to_add->name, name);
    //struct song_node *prev;

    //while(strcmp(artist, head->artist) <= 0){
    //    prev = head;
    //    printf("%u", prev);
    //    head = head->next;
    //    printf("%u", head);

    //}

    // while(strcmp(name, head->name) <= 0){
    //     prev = head;
    //     head = head->next;
    // }

    //prev->next = insert_front(head, artist, name);
    // boken
}

struct song_node * find_node(struct song_node *head, char *artist, char *name){
	while(head){
		if (strcmp(head->artist,artist)==0&&strcmp(head->name,name)==0){
			return head;
		}
        head=head->next;
	}
	return NULL;
}

struct song_node * find_artist(struct song_node *head, char *artist){
	while(head){
		if (strcmp(head->artist,artist)==0){
			return head;
		}
        head=head->next;
	}
	return NULL;
}

struct song_node *random_node(){
    srand(time(NULL));
}

struct song_node *remove_song(struct song_node *head, char *artist, char *name){
    struct song_node *front = head;
    if(strcmp(head->artist,artist)==0 && strcmp(head->name,name)==0){
        return head->next;
    }
    while(head->next){
        if (strcmp(head->artist,artist)==0 && strcmp(head->name,name)==0){
            head->next=head->next->next;
            return front;
        }
    }
    return NULL;
}

struct song_node *free_list(struct song_node *head){
    struct song_node *first = head;
    struct song_node *temp;
    while(head){
        temp=head->next;
        free(head);
    }
    return first;
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
    srand(time(NULL));
    int random = rand() % list_length(head);
    
    struct song_node *current = head;
    int i;
    for(i = 0; i < random; i++){
        current = current->next;
    }
    return current;
}

int main(){

    struct song_node *head = malloc(sizeof(struct song_node));
    strcpy(head->artist, "haydn");
    strcpy(head->name, "trumpet concerto");
    head =insert_order(head, "beethoven", "moonlight sonata");
    head =insert_order(head, "z", "dwd");
    head =insert_order(head, "z", "a");
    head = insert_order(head, "a", "a");
    // print_list(head);
    // printf("%d\n", list_length(head));
    // head =remove_song(head,"beethoven","moonlight sonata");
    // print_list(head);
    // printf("%d\n", list_length(head));
    struct song_node *random = random_element(head);
    printf("Random element- Artist: %s, Song: %s\n", random->artist, random->name);

    // print_list(head);


    return 0;
}
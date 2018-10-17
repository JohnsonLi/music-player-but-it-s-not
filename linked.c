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
    to_add->next = current;
    return to_add;
}

void insert_order(struct song_node *head, char *artist, char *name){
	struct song_node *to_add=malloc(sizeof(struct song_node));
	strcpy(to_add->artist, artist);
    strcpy(to_add->name, name);
    if (!head->next){
    	if(strcmp(artist,head->artist)<0||(strcmp(artist,head->artist)==0&&strcmp(name,head->name)<0)){
    		insert_front(head,artist,name);
    		return;
    	}
    	else{
    		head->next=to_add;
    		return ;
    	}
    }
	while(head->next){
		if (strcmp(artist,head->next->artist)<0){
			to_add->next=head->next;
			head->next=to_add;
			return ;
		}
		if(strcmp(artist,head->next->artist)==0){
			if(strcmp(name,head->next->name)<0){
				to_add->next=head->next;
				head->next=to_add;
				return;
			}
			else{
				to_add->next=head->next;
				head->next=to_add->next;
				return;
			}
		}
		head->next;
	}
	return;
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

}

struct song_node * find_node(struct song_node *head, char *artist, char *name){
	while(head){
		if (strcmp(head->artist,artist)==0&&strcmp(head->name,name)==0){
			return head;
		}
	}
	return NULL;
}

struct song_node * find_artist(struct song_node *head, char *artist, char *name){
	while(head){
		if (strcmp(head->artist,artist)==0){
			return head;
		}
	}
	return NULL;
}

struct song_node * choose_random(struct song_node *head);

struct song_node * remove(struct song_node *head, char *artist, char *name);

struct song_node * free(struct song_node *head);

int main(){

    struct song_node *head = malloc(sizeof(struct song_node));
    strcpy(head->artist, "haydn");
    strcpy(head->name, "trumpet concerto");
    insert_order(head, "zeethoven", "moonlight sonata");
    insert_order(head, "z", "dwd");
    insert_order(head, "z", "a");
    
    print_list(head);


    return 0;
}
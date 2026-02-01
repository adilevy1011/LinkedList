#include <stdio.h>
#include <stdlib.h>  

struct node{
    int value;
    struct node* next;

};

static int totalCount = 0; //total count of nodes
struct node* head = NULL; //head pointer

struct node* createNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->value = val;
    newNode->next = NULL;
    totalCount++;
    return newNode;
}
void addNode(int val) {
    struct node* newNode = createNode(val);

    if (head == NULL) {
        head = newNode;  // first node
    } else {
        struct node* current = head;
        while (current->next != NULL) {
            current = current->next;  // find last node
        }
        current->next = newNode;  // link new node at the end
    }
}
void changeValueOfNode(int location, int val){ 
    if(location < totalCount && location >= 0){
        struct node* current = head;
        for(int i = 0; i < location; i++){
            current = current->next;
        }
        current->value = val;
    } else{
        printf("invalid input\n");
    }
}
void printChain() {
    struct node* current = head;
    while (current != NULL) {
        printf("value: %d\n", current->value);
        current = current->next;
    }
}
int main() {
    addNode(5);
    addNode(10);
    addNode(15);
    printChain();
    changeValueOfNode(2,40);
    printChain();
    return 0;
}


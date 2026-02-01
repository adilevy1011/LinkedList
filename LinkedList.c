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

int getValueOfNode(int location){
    if(location < totalCount && location >= 0){
        struct node* current = head;
        for(int i = 0; i < location; i++){
            current = current->next;
        }
        return current->value;
    } else{
        printf("invalid input\n");
    }
}

void removeNode(int location){
    if(location < totalCount && location >= 0){
        if(location == 0){
            struct node* temp = head;
            head = head->next;
            free(temp);
            totalCount--;
            return;
        }
        struct node* current = head;
        for(int i = 0; i < location-1; i++){
            current = current->next;
        }
        struct node* temp = current->next; 
        current->next = current->next->next;
        free(temp);
        totalCount--;
    } else{
        printf("invalid input\n");
    }
}

void removeByValue(int value){
    if(head != NULL){
        while (head->value == value){
            struct node* temp = head;
            head = head->next;
            free(temp);
            totalCount--;
        }
    }
    struct node* current = head;
    while(current->next != NULL){
        if(current->next->value == value){
            struct node* temp = current->next;
            current->next = current -> next -> next;
            free(temp);
            totalCount--;
        } else current = current->next;
    }
}

void printChain() {
    struct node* current = head;
    while (current != NULL) {
        printf("value: %d\n", current->value);
        current = current->next;
    }
}

void addNodeToLocation(int location, int val){
    if(location <= 0){
        struct node* newNode = createNode(val);
        newNode->next = head;
        head = newNode;
        return;
    }
    if(location>=totalCount){
        addNode(val);
        return;
    }
    struct node* current = head;
    for(int i = 0; i < location-1; i++){
        current = current->next;
    }
    struct node* temp = current->next;
    struct node* newNode = createNode(val);
    current->next = newNode;
    newNode->next = temp;
    
}

int main() {
    for(int i = 0; i < 6; i++){
        addNode(i);
    }
    printf("before\n");
    printChain();
    printf("after\n");
    addNodeToLocation(2,99);
    printChain();
    removeNode(2);
    printf("\n");
    printChain();

    int sum = 0;
    for(int i = 0; i < totalCount; i++){
        sum += getValueOfNode(i);
    }
    printf("sum of all nodes value: %d\n", sum);
    return 0;
}


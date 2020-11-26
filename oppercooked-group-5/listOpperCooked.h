

struct Node{
    char type[10];
    char name[205];
    char flavor[25];
    char topping[25];
    double calories;
    int price;
    char size;
    int nomor;
    Node *next;
} *head, *tail, *curr;

Node *createNode(char type[], char name[], char flavor[], char topping[], double calories, int price, 
                char size,int *nomor) //node order
{
    Node *temp = (Node*)malloc(sizeof(Node));
    ++*nomor;
    temp->nomor = *nomor;
    strcpy(temp->type, type);
    strcpy(temp->name, name);
    strcpy(temp->flavor, flavor);
    strcpy(temp->topping, topping);
    temp->calories = calories;
    temp->price = price;
    temp->size = size;
    temp->next = NULL;
    return temp;
}

void pushTail(char type[], char name[], char flavor[], char topping[], double calories, int price, 
              char size,int *nomor){
    Node *temp = createNode(type,name,flavor,topping,calories,price,size,nomor);
    
    if(!tail){
        head = tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

void popAny(int nomor){ //belom kurangin nomor nya
    if(!tail){
        return;
    }
    else if(nomor == tail->nomor){
        curr = head;
        while(curr && curr->next != tail){
            curr = curr->next;
        }
        curr->next = NULL;
        free(tail);
        tail = curr;

    }
    else if(nomor == head->nomor){
        Node *newHead = head->next;
        head->next == NULL;
        free(head);
        head = newHead;   
    }
    else{
        curr = head;
        while(curr && curr->next->nomor != nomor ){
            curr = curr->next;
        }
        Node *erase = curr->next->next;
        curr->next->next = NULL;
        free(curr->next);
        curr->next = erase;

    }

}
//char type[], char name[], char flavor[], char topping[], double calories, int price, 
  //            char size,int *nomor
void printList(){
    if(!head){
        return;
    }
    else{
        curr = head;
        while(curr){
            printf("%d.\n",curr->nomor);
            printf("Type : %s\n",curr->type);
            printf("Name : %s\n",curr->name);
            if(curr->flavor[0] == '-'){
                printf("Topping : %s\n",curr->topping);
                printf("Calories : %.2lf\n",curr->calories);
            }
            else{
                 printf("Flavor : %s\n",curr->flavor);
                 printf("Size : %d\n",curr->size);
            }
            printf("%Price : %d\n",curr->price);
            
           
            curr = curr->next;
            
            
        }
        getchar();
        getchar();
        
    }
}
           
            
            




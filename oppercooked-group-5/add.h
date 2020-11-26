

void mainMenu(int profit);
void ChooseFoodToAdd(int *nomor);
int inputPrice();
double inputCalories();
char inputSize();
int totalTimeDessert(char topping);
int totalTimeDrink(char flavor);
void printMenu(int profit);

void mainMenu(int profit){
   
    int kode;
    int nomor =0;
    while(true){
        printMenu(profit);
        do{
            printf(">> ");
            scanf(" %d",&kode);
        } while(kode<1 || kode>5);
        
        if(kode==1){
            ChooseFoodToAdd(&nomor);
        }
        else if(kode ==4){
            printList();
        }
        else if(kode == 5){
            return ;
        }

    }
   

}

void printMenu(int profit){
     puts("Welcome to Opercooked");
    printf("Today Profit: $ %d\n",profit);
    puts("===========================");
    puts("1. Add Dessert or Beverage");
    puts("2. View Cooking Process");
    puts("3. View Order History");
    puts("4. Order Dessert or Beverage");
    puts("5. Exit");
}

void ChooseFoodToAdd(int *nomor){
    puts("What do you want to add?");
    puts("1. Dessert");
    puts("2. Drink");
    int chooseFood;
    int total_time;
    do{
        printf("Choose: ");
        scanf(" %d",&chooseFood);
    } while(chooseFood<1 || chooseFood>2);
    char name[225];
        do{
            printf("Input the name [at least 5 characters]: ");
            scanf(" %[^\n]",name);
        }while(strlen(name)<5);

        int price = inputPrice();
        char topping[20];
        char flavor[20];
        double calories;
        char size;
        char type[25];
        
        if(chooseFood == 1){
            strcpy(type,"Dessert");
            do{
                printf("Input the topping ['Caramel' | 'Honey' | 'Syrup'](Case Insesitive): ");
                scanf("%s",topping);
                if(topping[0]>='a'&&topping[0]<='z'){
                    topping[0]-=32;
                }
            }while(strcmp(topping,"Caramel")!=0 && strcmp(topping,"Honey")!=0 && strcmp(topping,"Syrup")!=0);
            flavor[0] = '-';
            size = '-';
            calories = inputCalories();
            total_time = totalTimeDessert(topping[0]);
            
        } else {
            strcpy(type,"Drink");
            do{
                printf("Input the falvor ['Mint' | 'Mix Berry' | 'Cheese'](Case Sesitive): ");
                scanf("%[^\n]",flavor);
            }while(strcmp(flavor,"Mint")!=0 && strcmp(flavor,"Mix Berry")!=0 && strcmp(flavor,"Cheese")!=0);
            topping[0]='-';
            calories = 0;
             size = inputSize();
            total_time = totalTimeDrink(flavor[2]);
        }
        puts("Successfully added a new menu!");
   //     /char type[], char name[], char flavor[], char topping[], double calories, int price, 
  //            char size,int *nomor
        pushTail(type,name,flavor,topping,calories,price,size,nomor);
        getchar();
        getchar();
    }


int inputPrice(){
    int price;
    do{
            printf("Input the price [10-500]: $ ");
            scanf(" %d",&price);
    } while(price<10 || price > 500);
    return price;
}

double inputCalories(){
    double calories;
    do{
        printf("Insert calories [1.00 - 99.00]: ");
        scanf(" %lf",&calories);
    } while(calories<1.00 || calories > 99.00);
    return calories;
}

char inputSize(){
    char size;
    do{
        printf("Input the size [S | M | L](Case Sensitive): ");
        scanf(" %c",&size);
    }while(size!='S' && size!='M' && size!='L');
    return size;
}

int totalTimeDessert(char topping){
    int x;
    x = rand()%90+1;
    if(x<40){
        x+=50;
    } else if(x<50){
        x+=20;
    }
    if(topping=='C') return x + 10;
    else if(topping=='H') return x + 15;
    else return x + 20;
}

int totalTimeDrink(char flavor){
    int x;
    x = rand()%50+1;
    if(x<10){
        x+=10;
    } 
    if(flavor=='n'){
        return x + 10;
    } else if(flavor=='x'){
        return x + 15;
    } else {
        return x + 20;
    }
    
}
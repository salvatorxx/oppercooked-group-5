#include <stdio.h>
#include <string.h>

int main(){

//WELCOME PAGE

//void profit(){}
//nanti void ini diisi utk ngitung profit

puts("Welcome to Opercooked");
puts("Today Profit: $ 0"); //nanti 0nya diganti void profit
puts("===========================");
puts("1. Add Dessert or Beverage");
puts("2. View Cooking Process");
puts("3. View Order History");
puts("4. Order Dessert or Beverage");
puts("5. Exit");

int num;
printf(">>");
scanf("%d", &num);
getchar();

//USER CHOOSE

//switch(num){
    //USER CHOOSE 1
    //case 1:
    puts("What do you want to add?");
    puts("1. Dessert");
    puts("2. Drink");

    int bev;
    printf("Choose:");
    scanf("%d", &bev);

    switch(bev){
        char name[20];
        //int len = strlen(name);
        int price;
        case 1:
        
        printf("Input the name [at least 5 characters]: ");
        scanf("%s", name);
        if (strlen(name) < 5){
            printf("Input the name [at least 5 characters]: ");
            scanf("%s", name);
        }

        printf("Input the price [10 - 500]: $");
        scanf("%d", &price);
        if (price < 10 || price > 500){
            printf("Input the price [10 - 500]: $");
            scanf("%d", &price);
        }
        getchar();

        //dessert type
        char topping[10];
        printf("Input the topping ['Caramel' | 'Honey' | 'Syrup']: ");
        scanf("%s", topping);

        double calories;
        printf("Insert calories [1.00 - 99.00]: ");
        scanf("%lf", &calories);
        if (calories < 1.00 || calories > 99.00){
            printf("Insert calories [1.00 - 99.00]: ");
            scanf("%lf", &calories);
        }

        puts("Successfully added a new menu!");
    //}
    //USER CHOOSE 2
    //USER CHOOSE 3
    //USER CHOOSE 4
    //USER CHOOSE 5 (exit)
}
    return 0;
}
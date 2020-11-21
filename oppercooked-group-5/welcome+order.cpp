#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* dummy struct
struct menu{
	char name[55];
	char price[55];
	char topping[55];
	char callories[55];
	char flavor[55];
	char size[55];
	menu *next;
	menu *prev;
}*head,*tail,*curr;
*/
void mainMenu(int profit);
int scanMainMenu();
void ChooseFoodToAdd();
int scanChooseFoodToAdd();
int inputPrice();
double inputCalories();
char inputSize();
int totalTimeDessert(char topping);
int totalTimeDrink(char flavor);


int main(){
    int profit = 0; // contoh
    mainMenu(profit);
    int kode = scanMainMenu();
    int total_time;

    if(kode==1){
        ChooseFoodToAdd();
        int chooseFood = scanChooseFoodToAdd();

        char name[225];
        do{
            printf("Input the name [at least 5 characters]: ");
            scanf(" %[^\n]",name);
        }while(strlen(name)<5);

        int price = inputPrice();
        
        if(chooseFood == 1){
            char topping[20];
            do{
                printf("Input the topping ['Caramel' | 'Honey' | 'Syrup'](Case Insesitive): ");
                scanf(" %s",topping);
                if(topping[0]>='a'&&topping[0]<='z'){
                    topping[0]-=32;
                }
            }while(strcmp(topping,"Caramel")!=0 && strcmp(topping,"Honey")!=0 && strcmp(topping,"Syrup")!=0);

            double calories = inputCalories();
            total_time = totalTimeDessert(topping[0]);
            
        } else {
            char flavor[20];
            do{
                printf("Input the falvor ['Mint' | 'Mix Berry' | 'Cheese'](Case Sesitive): ");
                scanf(" %[^\n]",flavor);
            }while(strcmp(flavor,"Mint")!=0 && strcmp(flavor,"Mix Berry")!=0 && strcmp(flavor,"Cheese")!=0);

            char size = inputSize();
            total_time = totalTimeDrink(flavor[2]);
        }
        puts("Successfully added a new menu!");
    }
    return 0;
}

void mainMenu(int profit){
    puts("Welcome to Opercooked");
    printf("Today Profit: $ %d\n",profit);
    puts("===========================");
    puts("1. Add Dessert or Beverage");
    puts("2. View Cooking Process");
    puts("3. View Order History");
    puts("4. Order Dessert or Beverage");
    puts("5. Exit");
}

int scanMainMenu(){
    int kode;
    do{
        printf(">> ");
        scanf(" %d",&kode);
    } while(kode<1 || kode>5);
    return kode;
}

void ChooseFoodToAdd(){
    puts("What do you want to add?");
    puts("1. Dessert");
    puts("2. Drink");
}

int scanChooseFoodToAdd(){
    int chooseFood;
    do{
        printf("Choose: ");
        scanf(" %d",&chooseFood);
    } while(chooseFood<1 || chooseFood>2);
    return chooseFood;
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

int printOrder(){
	if(!head){
		printf("There is no Dessert or Drink on the list!\nPress Enter to continue\n");
        getchar();
        return 0;
	}
     int i=1;
     curr=head;
     char format[]="| %-5s | %-10s | %-5s | %-10s | %-5s | %-10s | %-5s |\n";
     printf(format,"No","Name","Price","Topping","Callories","Flavor","Size");
     for(int j=0;j<=75;j++){
           printf("-");
     }
     puts("");
     while(curr){
        printf(format,i,curr->name,curr->price,curr->topping,curr->callories,curr->flavor,curr->size); 
    	curr=curr->next;
    	i++;
	}
    return i;
}
menu *findMenu(int num){
	if(!head){
		return NULL
	}else{
		int i=1;
		curr=head;
		while(curr&&i<num){
			curr=curr->next;
			i++;
		}
		return curr;
	}
}
void Order(){
    int choose,quantity=printOrder();
    if(quantity){
        do{
        scanf("%d",&choose);
        getchar();
        }while(choose>quantity);
        cook(findMenu(choose));    //function cooking
        printf("Successfully add to order list!\n\nPress Enter to continue");
        getchar();}
    return;
}
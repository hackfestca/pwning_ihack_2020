#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_MEAL 10
#define MAX_CHOICE 10
#define MAX_BOOK 10

int admin = 0;
int nb_choice = 0;
int nb_book = 0;
int nb_meal = 0;

typedef struct Meal Meal;
struct Meal{
	char name[10];
	int price;
};

Meal meals_arr[MAX_MEAL];

typedef struct Choice Choice;
struct Choice{
	int id;
	int quantity;
};

Choice choices_arr[MAX_CHOICE];

typedef struct Book Book;
struct Book{
	char name[10];
	char message[200];
};

Book books_arr[MAX_BOOK];

void init(){
	strcpy(meals_arr[0].name, "sushi\n\0");
	meals_arr[0].price = 100;
	nb_meal++;
	strcpy(meals_arr[1].name, "pangolin\n\0");
	meals_arr[1].price = 1000;
	nb_meal++;
	strcpy(meals_arr[2].name, "poutine\n\0");
	meals_arr[2].price = 1;
	nb_meal++;

	strcpy(books_arr[0].name, "sushi\n\0");
	strcpy(books_arr[0].message, "Very good restaurant!!!\n\0");
	nb_book++;
	strcpy(books_arr[1].name, "weird guy\0\n");
	strcpy(books_arr[1].message, "I WANT MY PANGOLIN!!!!\n\0");
	nb_book++;
}

void print_menu(){
	printf("|------------ Services Menu ------------|\n"
	       "| 1. See the menu                       |\n"
	       "| 2. Make your choice                   |\n"
	       "| 3. See your bill                      |\n"
	       "| 4. Sign our visitors book             |\n"
	       "| 5. Quit                               |\n"
	       "|---------------------------------------|\n");
	if(admin == 1){
		printf("| 7. Add a new meal |\n");
	}
}

void print_meal(){
	printf("---- Our meals ----\n");

	for (int i = 0; i < MAX_MEAL; i++)
	{
		if(meals_arr[i].name[0] == '\0'){
			break;
		}

		printf("ID: %d | name: %s | price: %d$\n", i, meals_arr[i].name, meals_arr[i].price);
		if(admin == 1){
			printf("Address name: 0x%016llx\n", meals_arr[i].name, meals_arr[i].price);
		}
	}
}

void make_choice(){
	int id = 0;
	int quantity = 0;

	if(nb_choice >= MAX_CHOICE){
		printf("You can't choose more than 10 meals!\n");
	}else{

		printf("---- Make your choice ----\n");
		printf("ID of the meal: ");
		scanf("%d", &id);

		if(id < 0 || id >= MAX_MEAL){
			printf("Invalid ID!\n");
		}
		else{
			if(meals_arr[id].name[0]  == '\0'){
				printf("Invalid ID!\n");
			}
			else if(id == 1){
				printf("Sorry but this meal is prohibited at this moment!\n");
			}
			else{
				printf("Quantity of meals: ");
				scanf("%d", &quantity);

				if(quantity < 1 || quantity > 50){
					printf("The quantity needs to be between 1 and 50!\n");
				}
				else{
					choices_arr[nb_choice].id = id;
					choices_arr[nb_choice].quantity = quantity;
					nb_choice++;
					printf("Your choice is registered!\n");
				}
			}
		}
	}
}

void see_bill(){
	int total_price = 0;
	int id = 0;
	
	for(int i = 0; i < nb_choice; i++){
		id = choices_arr[i].id;
		total_price = total_price + choices_arr[i].quantity * meals_arr[id].price;
	}

	printf("Your bill is %d$\n", total_price);
}

void sign_book(){
	char name[10];
	char message[200];

	printf("|&&&&&&&& Our visitors books &&&&&&&&|\n");
	
	for (int i = 0; i < nb_book; i++){
		printf("Message %d:\n" 
			   "%s\n"
			   "Author: %s\n",
			   i+1, books_arr[i].message, books_arr[i].name);
		if(admin == 1){
			printf("Address of message: 0x%016llx | Address of author: 0x%016llx\n", books_arr[i].message, books_arr[i].name);
		}
	}

	if(nb_book >= MAX_BOOK){
		printf("Sorry the book is full!\n");
	}
	else{
		printf("What is your name?\n");
		getchar();
		fgets(books_arr[nb_book].name, 10, stdin);
		printf("Enter your message:\n");
		fgets(books_arr[nb_book].message, 200, stdin);
		nb_book++;
		printf("Thanks for your message!\n");
	}
}

void login_admin(time_t current_time){
	int key = 0x1337C0CA ^ current_time;
	int input = 0;
	printf("|!!!!!!!! ADMIN ZONE !!!!!!!!|\n");
	printf("Enter the admin password:\n");
	scanf("%d", &input);

	if(key == input){
		printf("Welcome administrator!\n");
		admin = 1;
	}else{
		printf("Wrong password!\n");
	}
}

void add_meal(){

	char name[10];
	int price = 0;

	if(nb_meal > MAX_MEAL){
		printf("You can't create more than 10 meals!\n");
	}else{
		printf("Enter the name of your meal:\n");
		getchar();
		gets(name);
		printf("Enter the price of your meal:\n");
		scanf("%d", &price);
		strcpy(meals_arr[nb_meal].name, name);
		meals_arr[nb_meal].price = price;
		nb_meal++;
		printf("The new meal is registered!\n");
	}
}

int main()
{
	setvbuf(stdin, NULL, _IONBF, 0); //turn off buffering
	setvbuf(stdout, NULL, _IONBF, 0); //turn off buffering

	time_t current_time;
	char* c_time_string;
	int input = 0;

	current_time = time(NULL);
	c_time_string = ctime(&current_time);
	printf("Welcome to the Ihack restaurant!\n");
	printf("TIME: %s\n", c_time_string);

	init();

	while(input !=5){
		print_menu();

		scanf("%d", &input);

		if(input == 1){
			print_meal();
		}else if(input == 2){
			make_choice();
		}else if(input == 3){
			see_bill();
		}else if(input == 4){
			sign_book();
		}else if(input == 6){
			login_admin(current_time);
		}else if(input == 7){
			if(admin == 1){
				add_meal();
			}else{
				printf("You're not admin!\n");
			}
		}
	}

	printf("Bye!\n");
	return 0;
}

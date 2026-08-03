#include <stdio.h>
#include <string.h>
#include <locale.h>

#define reset "\033[0m"
#define green "\033[32m"
#define cyan   "\033[36m"
#define red "\033[31m"

#define max_costumers 200
#define max_products 100

struct costumer_data { // void costumer_registration on line 61

    int id;
    char name[50];
    int cpf;

};

typedef struct costumer_data costumer_data;

// Global variables for costumer_data;
costumer_data costumers[max_costumers];
costumer_data costumer_verify[max_costumers];
int total_costumer = 1;

struct product { // void product_registration on line 97

    int id;
    char name[50];
    float price;

};

typedef struct product product;

// Global variables for product;
product products[max_products];
int total_products = 0;

struct item_order {
    
    int id_product;
    int quantity;
};

typedef struct item_order item_order;

struct order {

    int order_number;                                                       
    int id_costumer;
    item_order itens[100]; // 
    int total_itens; // quantity of differenty products
    float total_value; // Total value of the order
    char order_date[11];

};

typedef struct order order;

void costumer_registration (void) { // struct on line 13

    printf("=================================\n");
    printf("|" cyan "     Costumer registration" reset     "     |\n" );
    printf("=================================\n");

// To do: New cpf quantity of numbers verification (Maybe change to char so i can use strlen)
    printf ("Enter your name: "); 
    fgets (costumer_verify[total_costumer].name, 49, stdin);
    costumer_verify[total_costumer].name[strcspn(costumer_verify[total_costumer].name, "\n")] = '\0';

    printf ("Enter your CPF (only numbers): ");
    scanf ("%d", &costumer_verify[total_costumer].cpf );

        for (int i = 1; i < total_costumer + 1; i++) {

            if (costumer_verify[total_costumer].cpf == costumers[i].cpf ){
                printf (red "Costumer already registered!\n" reset);
                break;
            }

            else {
                strcpy (costumers[total_costumer].name, costumer_verify[total_costumer].name); // name

                costumers[total_costumer].cpf = costumer_verify[total_costumer].cpf; //cpf

                costumers[total_costumer].id += 1;
                total_costumer++;

                printf (green "Costumer Registred!\n" reset);
                break;
            }
        }
        
}

// Register Product (Asks for "Name" and "Price" generates an ID, goes to struct product)
void product_registration (void) { // Struct on line 27 

    printf("=================================\n");
    printf("|" cyan "      Product registration" reset     "     |\n" );
    printf("=================================\n");

    printf ("Enter the product name: ");
    fgets (products[total_products].name, 49, stdin);
    products[total_products].name[strcspn(products[total_products].name, "\n")] = '\0';

    printf ("Enter the product price: ");
    scanf ("%f", &products[total_products].price);
    getchar ();

    products[total_products].id = total_products + 1;

    total_products += 1;

    printf (green "Product Registred!\n" reset);
}

void registration_menu (void) {

        int opt;

        printf("==========================\n");
        printf("|" cyan "      Registrations" reset     "     |\n" );
        printf("==========================\n");
        printf ("|" green " [1]" reset " Register Costumer  |  \n");
        printf ("|" green " [2]" reset " Register Product   |  \n");
        printf ("==========================  \n");

        scanf ("%d", &opt); 
        getchar ();

        switch (opt) {
            case 1: // Register costumer (Asks for "Name" "CPF" and generates an ID, goes to struct costumers)
                costumer_registration();
            break;

            case 2: // Register Product (Asks for "Name" and "Price" generates an ID, goes to struct product)
                product_registration();
            break;

            default:
            printf (red "Error: " reset "Enter one of the options available.\n");
            break;
        }

}

void orders_menu (void) {

        int opt;

        printf("==========================\n");
        printf("|" cyan "        New Order" reset     "       |\n" );
        printf("==========================\n");
        printf ("|" green " [1]" reset " Create a new order |  \n");
        printf ("|" green " [2]" reset " Menu               |  \n");
        printf ("==========================  \n");

        scanf ("%d", &opt); 

        switch (opt) {
            case 1: // Asks for the costumer ID (CPF), after that show the list of products
                    // Asks which product, quantity and sum each product by the quantity (Total value = Price * quantity)
                    // At the end of the order: date of the order;  Save everything at struct Orders

            break;

            case 2:
            printf ("Returning to the menu...\n");
            break;

            default:
            printf (red "Error: " reset "Enter one of the options available.\n");
            break;
        }

}

void records_menu (void) {

        int opt;

        printf("====================================\n");
        printf("|" cyan "              Records" reset     "             |\n" );
        printf("====================================\n");
        printf ("|" green " [1]" reset " List of Costumers and Products |  \n");
        printf ("|" green " [2]" reset " List of orders                 |  \n");
        printf ("====================================  \n");

        scanf ("%d", &opt); 

        switch (opt) {
            case 1: // show the list of costumers and product saved on their respectivies structs
                for (int i = 0; i < total_products; i++) {
                    printf ("Product name: %s\t",products[i].name );
                    printf ("Product price: %f\t",products[i].price );
                    printf ("Product id: %d\n",products[i].id );
                }
            break;

            case 2: // Show the list of all the orders and for each order the number, costumer, date and total value of the order
                    // Also shows which product and how many units were bought at that moment
            break;

            default:
            printf (red "Error: " reset "Enter one of the options available.\n");
            break;
        }

}

void menu (void) {
    int opt_menu;
    do {
            printf("=====================\n");
            printf("|" cyan "       MENU" reset     "        |\n" );
            printf("=====================\n");
            printf ("|" green " [1]" reset " Registrations |  \n");
            printf ("|" green " [2]" reset " Orders        |  \n");
            printf ("|" green " [3]" reset " Reports       |  \n"); 
            printf ("|" green " [4]" reset " Exit          |  \n"); 
            printf ("=====================  \n");

            scanf ("%d", &opt_menu);

            switch (opt_menu) {
                case 1:
                registration_menu ();
                break;

                case 2:
                orders_menu ();
                break;

                case 3:
                records_menu ();
                break;

                case 4:
                printf ( red "Exiting..." reset);
                break;

                default:
                printf (red "Error: " reset "Enter one of the options available.\n");
                break;
            }


    }while (opt_menu != 4);
    
}

int main () {

    menu(); // MENU void

    return 0;
}
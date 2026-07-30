#include <stdio.h>
#include <string.h>
#include <locale.h>

#define reset "\033[0m"
#define green "\033[32m"
#define cyan   "\033[36m"
#define red "\033[31m"


void registration_menu (void) {

        int opt;

        printf("==========================\n");
        printf("|" cyan "     Registrations" reset     "      |\n" );
        printf("==========================\n");
        printf ("|" green " [1]" reset " Register Client    |  \n");
        printf ("|" green " [2]" reset " Register Product   |  \n");
        printf ("==========================  \n");

        scanf ("%d", &opt); 

        switch (opt) {
            case 1: // Register client (Asks for "Name" "CPF" and generates an ID, goes to struct clients)

            break;

            case 2: // Register Product (Asks for "Name" and "Price" generates an ID, goes to struct product)

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
            case 1: // Asks for the client ID (CPF), after that show the list of products
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
        printf ("|" green " [1]" reset " List of Clients and Products |  \n");
        printf ("|" green " [2]" reset " List of orders               |  \n");
        printf ("====================================  \n");

        scanf ("%d", &opt); 

        switch (opt) {
            case 1: // show the list of clients and product saved on their respectivies structs

            break;

            case 2: // Show the list of all the orders and for each order the number, client, date and total value of the order
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

    setlocale(LC_ALL, ".UTF-8");
   
    menu(); // MENU void


    return 0;
}
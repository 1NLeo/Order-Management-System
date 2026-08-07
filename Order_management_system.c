#include <stdio.h>
#include <string.h>
#include <locale.h>

#define reset "\033[0m"
#define green "\033[32m"
#define cyan   "\033[36m"
#define red "\033[31m"
#define yellow "\033[33m"
#define purple "\033[34m"

#define max_customers 200
#define max_products 200
#define max_itens 200

struct customer_data { // void customer_registration on line 61

    int id;
    char name[50];
    int cpf;

};

typedef struct customer_data customer_data;

// Global variables for customer_data;
customer_data customers[max_customers];
customer_data customer_verify[max_customers];
int total_customer = 1;

struct product { // void product_registration on line 97

    int id;
    char name[50];
    float price;
    int quantity;

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

item_order iten_info[max_itens];
int total_items = 0;


struct order_data {

    int order_number;                                                       
    int id_customer;
    item_order items[max_itens]; // 
    int dif_itens; // quantity of differenty products
    float total_value; // Total value of the order
    char order_date[11];

};

typedef struct order_data order_data;
order_data order[max_itens]; 
int ord_id = 1;
int difitems = 0;
int total_sum = 0;


int verify = 0;
void cpf_verification() { //  verify return 1 when the customer is already registred

    printf ("Enter your CPF (only numbers): ");
    scanf ("%d", &customer_verify[total_customer].cpf );

        for (int i = 0; i < total_customer + 1; i++) {

            if (customer_verify[total_customer].cpf == customers[i].cpf) {
                verify = 1;
                break;
            }
            else {
                verify = 0;
            }
           
        }
}

void customer_registration (void) { // struct on line 13

    printf("=================================\n");
    printf("|" purple "     Customer registration" reset     "     |\n" );
    printf("=================================\n");

// To do: CPF quantity of numbers verification (Maybe change to char so i can use strlen)
    printf ("Enter your name: "); 
    fgets (customer_verify[total_customer].name, 49, stdin);
    customer_verify[total_customer].name[strcspn(customer_verify[total_customer].name, "\n")] = '\0';

    cpf_verification ();

         if (verify == 1){
                printf (red "Customer already registered!\n" reset);

            }

            else {
                strcpy (customers[total_customer].name, customer_verify[total_customer].name); // name

                customers[total_customer].cpf = customer_verify[total_customer].cpf; //cpf

                customers[total_customer].id = total_customer;
                total_customer++;

                printf (green "Customer Successfully Registred!\n" reset);
        
            }
        
}

// Register Product (Asks for "Name" and "Price" generates an ID, goes to struct product)
void product_registration (void) { // Struct on line 27 

    printf("================================\n");
    printf("|" yellow "     Product registration" reset     "     |\n" );
    printf("================================\n");

    printf ("Enter the product name: ");
    fgets (products[total_products].name, 49, stdin);
    products[total_products].name[strcspn(products[total_products].name, "\n")] = '\0';

    printf ("Enter the number of available %ss: ", products[total_products].name);
    scanf ("%d", &products[total_products].quantity);

    printf ("Enter the product price: ");
    scanf ("%f", &products[total_products].price);
    getchar ();

    products[total_products].id = total_products;

    total_products += 1;

    printf (green "Product Registred!\n" reset);
}

void registration_menu (void) {

        int opt;

        printf("==========================\n");
        printf("|" cyan "      Registrations" reset     "     |\n" );
        printf("==========================\n");
        printf ("|" green " [1]" reset " Register Customer  |  \n");
        printf ("|" green " [2]" reset " Register Product   |  \n");
        printf ("==========================  \n");

        scanf ("%d", &opt); 
        getchar ();

        switch (opt) {
            case 1: // Register costumer (Asks for "Name" "CPF" and generates an ID, goes to struct costumers)
                customer_registration();
            break;

            case 2: // Register Product (Asks for "Name" and "Price" generates an ID, goes to struct product)
                product_registration();
            break;

            default:
            printf (red "Error: " reset "Enter one of the available options.\n");
            break;
        }

}

void new_order (void) {
    // At the end of the order: date of the order;  Save everything at struct Orders
    // Verify if is there any product available and if the quantity you want is available;

    int new_odr = 0;

    
        printf("==========================\n");
        printf("|" cyan "        New Order" reset     "       |\n" );
        printf("==========================\n");
    
        cpf_verification();

    
    if (verify == 1) {

        printf (green "Customer verified!\n" reset);

        do {

            printf("======================\n");
            printf("|" yellow "       Products" reset     "     |\n" );
            printf("======================\n");

            for (int i = 0; i < total_products; i++) {
                if (products[i].quantity == 0) {
                printf ("Product id: [%d]\t",products[i].id );           
                printf ("Product name: %s\t",products[i].name );
                printf ("Product price: $%.2f\t",products[i].price );
                printf (red "Out of stock!\n" reset);
                continue;
            }    
                printf ("Product id: [%d]\t",products[i].id );           
                printf ("Product name: %s\t",products[i].name );
                printf ("Product price: $%.2f\t",products[i].price );
                printf ("Available: %d\n", products[i].quantity);
            }

            printf ("Which product do you want [id]: ");
            scanf ("%d", &iten_info[total_items].id_product);
            

            printf ("Enter the quantity you want: ");
            scanf ("%d", &iten_info[total_items].quantity);
            getchar();

            if (iten_info[total_items].quantity > products[iten_info[total_items].id_product].quantity ) {
                printf(red "ERROR: " reset "The quantity you want is bigger than the available quantity\n");

                while (iten_info[total_items].quantity > products[iten_info[total_items].id_product].quantity) {
                    printf ("Enter an available quantity: ");
                    scanf ("%d", &iten_info[total_items].quantity);
                }

                    order[total_items].dif_itens = difitems;
                    order[total_items].order_number = ord_id;

                    printf ("Another order: [1] Yes");
                    printf ("               [2] NO \n");
                    scanf ("%d", &new_odr);
                    getchar ();

                    order[total_sum].total_value += iten_info[total_items].quantity * products[iten_info[total_items].id_product].price;  
                    products[iten_info[total_items].id_product].quantity = products[iten_info[total_items].id_product].quantity - iten_info[total_items].quantity;

                    difitems++;
                    ord_id++;
                    total_items++;
            }

            else {
                order[total_items].dif_itens = difitems;
                order[total_items].order_number = ord_id;

                printf ("Another order: [1] Yes");
                printf ("               [2] NO \n");
                scanf ("%d", &new_odr);
                getchar ();

                order[total_sum].total_value += iten_info[total_items].quantity * products[iten_info[total_items].id_product].price;  
                products[iten_info[total_items].id_product].quantity = products[iten_info[total_items].id_product].quantity - iten_info[total_items].quantity;

                difitems++;
                ord_id++;
                total_items++;
            }

            
            if (new_odr == 2) {
                printf ("Enter todays date DD/MM/YYYY: ");
                fgets(order[total_items].order_date, 11, stdin);

                printf ("Order value: $%.2f\n", order[total_sum].total_value);
                total_sum++;
            }
            
        } while (new_odr != 2);  
    }

         else {
            printf (red "ERROR: " reset "customer not registered!\n");
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
            case 1: 
            new_order ();
            break;

            case 2:
            printf ("Returning to the menu...\n");
            break;

            default:
            printf (red "Error: " reset "Enter one of the available options.\n");
            break;
        }

}

void list1_records (void) {
      
        printf("======================\n");
        printf("|" yellow "       Products" reset     "     |\n" );
        printf("======================\n");
            for (int i = 0; i < total_products; i++) { 
                        
                printf ("Product name: %s\t",products[i].name );
                printf ("Product price: %.2f\t",products[i].price );
                printf ("Product id: %d\n",products[i].id );
            }

                printf("======================\n");
                printf("|" purple "      Costumers" reset     "     |\n" );
                printf("======================\n");
                    for (int i = 0; i < total_customer; i++) {

                        if (i != 0) { // The 0 free space in the array never appears
                          printf ("Customer %d: %s\n",customers[i].id, customers[i].name);
                        }

                        else {
                            continue;
                        }
                        
                    }
                    printf("\n");

}

void orders_list (void) { // To do:

}

void records_menu (void) {

        int opt;

        printf("====================================\n");
        printf("|" cyan "              Records" reset     "             |\n" );
        printf("====================================\n");
        printf ("|" green " [1]" reset " List of Customers and Products |  \n");
        printf ("|" green " [2]" reset " List of orders                 |  \n");
        printf ("====================================  \n");

        scanf ("%d", &opt); 

        switch (opt) {
            case 1: // show the list of costumers and product saved on their respectivies structs
                list1_records(); // On line 185
            break;

            case 2: // Show the list of all the orders and for each order the number, costumer, date and total value of the order
            //line 308 // Also shows which product and how many units were bought at that moment
            break;

            default:
            printf (red "Error: " reset "Enter one of the available options.\n");
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
                printf (red "Error: " reset "Enter one of the available options.\n");
                break;
            }


    }while (opt_menu != 4);
    
}

int main () {

    menu(); // MENU void

    return 0;
}
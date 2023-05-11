#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "mealfunctions.h"

// MAIN FUNCTION
int main()
{
    struct Sheets sheet = {0};
    printf("\n");
    welcome_message();

    char filename[MAX_FILENAME_LENGTH];
    printf("| Please enter filename to load  data from                 |\n");
    printf("| Or enter 'new' to start a new sheet                      |\n");
    printf("|----------------------------------------------------------|\n|  ");
    scanf("%s", filename);

    if (strcmp(filename, "new") != 0)
    {
        FILE *file = fopen(filename, "r");
        if (!file)
        {
            printf("Error: could not open file %s.\n", filename);
            return 1;
        }
        fread(&sheet, sizeof(struct Sheets), 1, file);
        fclose(file);
        printf("|----------------------------------------------------------|\n");
        printf("|                 Data loaded from '%s'                   \n", filename);
        printf("|----------------------------------------------------------|");
    }

    while (1)
    {

        printf("\n");
        printf("\n");
        display_menu();

        int option;
        scanf("%d", &option);

        switch (option)
        {
        case 0:
        {
            printf("\n");
            end_message();
            return 0;
        }
        case 1:
        {
            struct Member member = create_member();

            int case_cntrl = 1;
            while (case_cntrl == 1)
            {
                add_member(&sheet, member);
                printf("Enter 0 to return main menu: \n");
                printf("Enter 1 to Exit Without Save Data\n");
                scanf("%d", &case_cntrl);
                switch (case_cntrl)
                {
                case 0:
                    case_cntrl = 0;
                    break;
                case 1:
                    return 0;
                    break;

                default:
                    printf("|----------------------------------------------------------|\n");
                    printf("|                        Invalid Option.                   |\n");
                    printf("|----------------------------------------------------------|\n");
                    break;
                }
            }

            break;
        }
        case 2:
        {

            int case_cntrl = 1;
            while (case_cntrl == 1)
            {
                remove_member(&sheet);

                printf("\nEnter 0 to return main menu: \n");
                printf("Enter 1 to Exit Without Save Data \n");
                scanf("%d", &case_cntrl);
                switch (case_cntrl)
                {
                case 0:
                    case_cntrl = 0;
                    break;
                case 1:
                    return 0;
                    break;

                default:
                    printf("|----------------------------------------------------------|\n");
                    printf("|                        Invalid Option.                   |\n");
                    printf("|----------------------------------------------------------|\n");
                    break;
                }
            }

            break;
        }
        case 3:
        {

            int case_cntrl = 1;
            while (case_cntrl == 1)
            {
                update_mealofamonth(&sheet);
                printf("Enter 0 to return main menu: \n");
                printf("Enter 1 to Exit Without Save Data \n");
                scanf("%d", &case_cntrl);
                switch (case_cntrl)
                {
                case 0:
                    case_cntrl = 0;
                    break;
                case 1:
                    return 0;
                    break;

                default:
                    printf("|----------------------------------------------------------|\n");
                    printf("|                        Invalid Option.                   |\n");
                    printf("|----------------------------------------------------------|\n");
                    break;
                }
            }
            break;
        }
        case 4:
        {

            int case_cntrl = 1;
            while (case_cntrl == 1)
            {
                print_meal_report(&sheet);
                printf("Enter 0 to return main menu: \n");
                printf("Enter 1 to Exit Without Save Data \n");
                scanf("%d", &case_cntrl);
                switch (case_cntrl)
                {
                case 0:
                    case_cntrl = 0;
                    break;
                case 1:
                    return 0;
                    break;

                default:
                    printf("|----------------------------------------------------------|\n");
                    printf("|                        Invalid Option.                   |\n");
                    printf("|----------------------------------------------------------|\n");
                    break;
                }
            }
            break;
        }
        case 5:
        {
            int case_cntrl = 1;
            while (case_cntrl == 1)
            {
                view_member_details(&sheet);
                printf("Enter 0 to return main menu: \n");
                printf("Enter 1 to Exit Without Save Data \n");
                scanf("%d", &case_cntrl);
                switch (case_cntrl)
                {
                case 0:
                    case_cntrl = 0;
                    break;
                case 1:
                    return 0;
                    break;

                default:
                    printf("|----------------------------------------------------------|\n");
                    printf("|                        Invalid Option.                   |\n");
                    printf("|----------------------------------------------------------|\n");
                    break;
                }
            }
            break;
        }
        case 6:
        {

            int case_cntrl = 1;
            while (case_cntrl == 1)
            {
                update_balance(&sheet);
                printf("Enter 0 to return main menu: \n");
                printf("Enter 1 to Exit Without Save Data \n");
                scanf("%d", &case_cntrl);
                switch (case_cntrl)
                {
                case 0:
                    case_cntrl = 0;
                    break;
                case 1:
                    return 0;
                    break;

                default:
                    printf("|----------------------------------------------------------|\n");
                    printf("|                        Invalid Option.                   |\n");
                    printf("|----------------------------------------------------------|\n");
                    break;
                }
            }

            break;
        }
        case 7:
        {

            int case_cntrl = 1;
            while (case_cntrl == 1)
            {
                struct Bill bill = create_bill();
                add_bill(&sheet, bill);
                printf("Enter 0 to return main menu: \n");
                printf("Enter 1 to Exit Without Save Data \n");
                scanf("%d", &case_cntrl);
                switch (case_cntrl)
                {
                case 0:
                    case_cntrl = 0;
                    break;
                case 1:
                    return 0;
                    break;

                default:
                    printf("|----------------------------------------------------------|\n");
                    printf("|                        Invalid Option.                   |\n");
                    printf("|----------------------------------------------------------|\n");
                    break;
                }
            }
            break;
        }
        case 8:
        {

            int case_cntrl = 1;
            while (case_cntrl == 1)
            {
                print_bill_report(&sheet);
                printf("Enter 0 to return main menu: \n");
                printf("Enter 1 to Exit Without Save Data \n");
                scanf("%d", &case_cntrl);
                switch (case_cntrl)
                {
                case 0:
                    case_cntrl = 0;
                    break;
                case 1:
                    return 0;
                    break;

                default:
                    printf("|----------------------------------------------------------|\n");
                    printf("|                        Invalid Option.                   |\n");
                    printf("|----------------------------------------------------------|\n");
                    break;
                }
            }
            break;
        }
        case 9:
        {

            int case_cntrl = 1;
            while (case_cntrl == 1)
            {
                struct MealCost mealcost = create_mealcost();
                add_mealcost(&sheet, mealcost);
                printf("Enter 0 to return main menu: \n");
                printf("Enter 1 to Exit Without Save Data \n");
                scanf("%d", &case_cntrl);
                switch (case_cntrl)
                {
                case 0:
                    case_cntrl = 0;
                    break;
                case 1:
                    return 0;
                    break;

                default:
                    printf("|----------------------------------------------------------|\n");
                    printf("|                        Invalid Option.                   |\n");
                    printf("|----------------------------------------------------------|\n");
                    break;
                }
            }
            break;
        }
        case 10:
        {

            int case_cntrl = 1;
            while (case_cntrl == 1)
            {
                print_mealcost_report(&sheet);
                printf("Enter 0 to return main menu: \n");
                printf("Enter 1 to Exit Without Save Data \n");
                scanf("%d", &case_cntrl);
                switch (case_cntrl)
                {
                case 0:
                    case_cntrl = 0;
                    break;
                case 1:
                    return 0;
                    break;

                default:
                    printf("|----------------------------------------------------------|\n");
                    printf("|                        Invalid Option.                   |\n");
                    printf("|----------------------------------------------------------|\n");
                    break;
                }
            }
            break;
        }
        case 11:
        {
            int case_cntrl = 1;
            while (case_cntrl == 1)
            {
                printf("\n\nOptions:\n");
                printf("1. Sort By Total Number of meal(Min to Max)\n");
                printf("2. Sort By Total Number of meal(Max to Min)\n");
                printf("0. To return main menu\n");
                printf("\nEnter option number: ");
                int case_option;
                scanf("%d", &case_option);
                switch (case_option)
                {
                case 1:
                    print_meal_min_to_max(&sheet);
                    break;
                case 2:
                    print_meal_max_to_min(&sheet);
                    break;
                case 0:
                    case_cntrl = 0;
                    break;

                default:
                    printf("|----------------------------------------------------------|\n");
                    printf("|                        Invalid Option.                   |\n");
                    printf("|----------------------------------------------------------|\n");
                    break;
                }
            }
            break;
        }
        case 12:
        {

            int case_cntrl = 1;
            while (case_cntrl == 1)
            {
                print_all_info(&sheet);
                printf("\nEnter 0 to return main menu: \n");
                printf("Enter 1 to Exit Without Save Data \n");
                scanf("%d", &case_cntrl);
                switch (case_cntrl)
                {
                case 0:
                    case_cntrl = 0;
                    break;
                case 1:
                    return 0;
                    break;

                default:
                    printf("|----------------------------------------------------------|\n");
                    printf("|                        Invalid Option.                   |\n");
                    printf("|----------------------------------------------------------|\n");
                    break;
                }
            }
            break;
        }
        case 13:
        {
            printf("Enter filename to save sheet data to: ");
            scanf("%s", filename);
            FILE *file = fopen(filename, "w");
            if (!file)
            {
                printf("Error: could not open file %s.\n", filename);
                return 1;
            }
            fwrite((&sheet), (sizeof(struct Sheets)), 1, file);
            fclose(file);
            printf("\n");
             printf("|----------------------------------------------------------|\n");
            printf("|              Data saved to file '%s'.                   \n", filename);                 
            printf("|----------------------------------------------------------|\n");
            
            printf("\n");
            end_message();
            return 0;
        }
        default:
        {
            printf("|----------------------------------------------------------|\n");
            printf("|                        Invalid Option.                   |\n");
            printf("|----------------------------------------------------------|\n");
            break;
        }
        }
    }
}

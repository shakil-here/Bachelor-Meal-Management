#include <stdio.h>
#include <string.h>
#define MAX_FILENAME_LENGTH 50
#define MAX_MEMBER 100
#define MEAL_RECORD_LENGTH 30
#define MAX_BILL 10
#define MAX_MEAL_COST 30
#define MAIDBILL 500

struct Mealofamonth
{
    int days[MEAL_RECORD_LENGTH];
};
struct Member
{
    int id;
    char name[20];
    char sincemember[11];
    float Balance;
    float bill_per_person;
    struct Mealofamonth mealofamonth;
    int total_indv_meal;
    float indv_meal_cost;
    float indv_total_cost;
    float maid_bill;
};
struct Bill
{
    int bID;
    char details[30];
    float cost;
};
struct MealCost
{
    int mcID;
    char mcdetails[30];
    float mcost;
};
struct Sheets
{
    struct Member members[MAX_MEMBER];
    int num_members;
    struct Bill bills[MAX_BILL];
    int num_bill;
    struct MealCost mealcosts[MAX_MEAL_COST];
    int num_mealcost;
    float total_ubills;
    int total_meals;
    float total_meal_cost;
    float meal_rate;
};
// Create Meal Cost
struct MealCost create_mealcost()
{
    struct MealCost mealcost;
    printf("Enter Meal Cost ID: ");
    scanf("%d", &mealcost.mcID);
    printf("\nEnter Meal Cost ammount: ");
    scanf("%f", &mealcost.mcost);
    printf("\nEnter Meal Cost Details: ");
    scanf("%s", &mealcost.mcdetails);
    printf("\n");
    printf("-------------------------------------------------------------\n");
    printf("\nID:      %d\nDetails:%s\nCost:%.2f\n", mealcost.mcID, mealcost.mcdetails, mealcost.mcost);
    printf("-------------------------------------------------------------\n");
    return mealcost;
}
// Add Meal cost to sheet
void add_mealcost(struct Sheets *sheet, struct MealCost mealcost)
{
    if (sheet->num_mealcost == MAX_MEAL_COST)
    {
        printf("Error: sheet is full.\n");
        return;
    }
    for (int i = 0; i < sheet->num_mealcost; i++)
    {
        if (sheet->mealcosts[i].mcID == mealcost.mcID)
        {
            printf("Error: Meal Cost with ID %d already exists.\n", mealcost.mcID);
            return;
        }
    }
    sheet->mealcosts[sheet->num_mealcost] = mealcost;
    sheet->total_meal_cost = 0;
    for (int i = 0; i < MAX_MEAL_COST; i++)
    {
        sheet->total_meal_cost += sheet->mealcosts[i].mcost;
    }
    sheet->meal_rate = 0;
    sheet->meal_rate = (sheet->total_meal_cost / sheet->total_meals);
    for (int i = 0; i < sheet->num_members; i++)
            {
                sheet->members[i].bill_per_person=(sheet->total_ubills / sheet->num_members);
                sheet->members[i].indv_meal_cost=(sheet->members[i].total_indv_meal*sheet->meal_rate);
                sheet->members[i].maid_bill=MAIDBILL;
                sheet->members[i].indv_total_cost=(sheet->members[i].indv_meal_cost+sheet->members[i].maid_bill+sheet->members[i].bill_per_person);
            }
    sheet->num_mealcost++;
    printf("Meal cost added to sheet.\n");
}

// crerate  bill
struct Bill create_bill()
{
    struct Bill bill;
    printf("Enter Bill ID: ");
    scanf("%d", &bill.bID);
    printf("\nEnter Bill ammount: ");
    scanf("%f", &bill.cost);
    printf("\nEnter Bill Details: ");
    scanf("%s", &bill.details);
    printf("\n");
    printf("-------------------------------------------------------------\n");
    printf("\nID:      %d\nDetails:%s\nCost:%.2f\n", bill.bID, bill.details, bill.cost);
    printf("-------------------------------------------------------------\n");
    return bill;
}
// add bill to bill sheet
void add_bill(struct Sheets *sheet, struct Bill bill)
{
    if (sheet->num_bill == MAX_BILL)
    {
        printf("Error: sheet is full.\n");
        return;
    }
    for (int i = 0; i < sheet->num_bill; i++)
    {
        if (sheet->bills[i].bID == bill.bID)
        {
            printf("Error: Bill with ID %d already exists.\n", bill.bID);
            return;
        }
    }
    int i;
    sheet->bills[sheet->num_bill] = bill;
    sheet->total_ubills = 0;
    for (i = 0; i < MAX_BILL; i++)
    {
        sheet->total_ubills += sheet->bills[i].cost;
    }
    sheet->num_bill++;
     for (int i = 0; i < sheet->num_members; i++)
            {
                sheet->members[i].bill_per_person=(sheet->total_ubills / sheet->num_members);
                sheet->members[i].indv_meal_cost=(sheet->members[i].total_indv_meal*sheet->meal_rate);
                sheet->members[i].maid_bill=MAIDBILL;
                sheet->members[i].indv_total_cost=(sheet->members[i].indv_meal_cost+sheet->members[i].maid_bill+sheet->members[i].bill_per_person);
            }
    
    printf("Bill added to sheet.\n");
}

// Function to create a new member
struct Member create_member()
{
    char a[20];
    struct Member member;
    printf("Enter member ID: ");
    scanf("%d", &member.id);
    getchar();
    printf("Enter member name: ");
    fgets(member.name, 10, stdin);
    member.name[strcspn(member.name, "\n")] = '\0';
    int name_size = sizeof(member.name);
    if (name_size > 10)
    {
        gets(a);
    }
    printf("Enter member Since(DD-MM-YYYY): ");
    fgets(member.sincemember, 11, stdin);
    member.sincemember[strcspn(member.sincemember, "\n")] = '\0';
    memset(member.mealofamonth.days, 0, sizeof(member.mealofamonth.days));
    return member;
}

// Function to add a member  to the sheet
void add_member(struct Sheets *sheet, struct Member member)
{
    if (sheet->num_members == MAX_MEMBER)
    {
        printf("Error: Sheet is full.\n");
        return;
    }

    for (int i = 0; i < sheet->num_members; i++)
    {
        if (sheet->members[i].id == member.id)
        {
            printf("Error: Member with ID %d already exists.\n", member.id);
            return;
        }
    }
    sheet->members[sheet->num_members] = member;
    sheet->num_members++;
    for (int i = 0; i < sheet->num_members; i++)
            {
                sheet->members[i].bill_per_person=(sheet->total_ubills / sheet->num_members);
                sheet->members[i].indv_meal_cost=(sheet->members[i].total_indv_meal*sheet->meal_rate);
                sheet->members[i].maid_bill=MAIDBILL;
                sheet->members[i].indv_total_cost=(sheet->members[i].indv_meal_cost+sheet->members[i].maid_bill+sheet->members[i].bill_per_person);
            }
    printf("Member added to sheet.\n");
}

// Function to remove a member from the sheet
void remove_member(struct Sheets *sheet)
{
    printf("Enter ID of member to remove: ");
    int id;
    scanf("%d", &id);
    int i, found = 0;
    for (i = 0; i < sheet->num_members; i++)
    {
        if (sheet->members[i].id == id)
        {
            found = 1;
            int j;
            for (j = i; j < sheet->num_members - 1; j++)
            {
                sheet->members[j] = sheet->members[j + 1];
            }
            sheet->num_members--;
            sheet->total_meals=0;
           
    for (int i = 0; i < sheet->num_members; i++)
            {
                sheet->total_meals+=sheet->members[i].total_indv_meal;
                sheet->members[i].bill_per_person=(sheet->total_ubills / sheet->num_members);
                sheet->members[i].indv_meal_cost=(sheet->members[i].total_indv_meal*sheet->meal_rate);
                sheet->members[i].maid_bill=MAIDBILL;
                sheet->members[i].indv_total_cost=(sheet->members[i].indv_meal_cost+sheet->members[i].maid_bill+sheet->members[i].bill_per_person);
            }
             sheet->meal_rate = 0;
    sheet->meal_rate = (sheet->total_meal_cost / sheet->total_meals);
            printf("member removed from sheet.\n");
            break;
        }
    }
    if (!found)
    {
        printf("Error: member with ID %d not found.\n", id);
    }
}

// Function to update the meal record of a member for a specific day
void update_mealofamonth(struct Sheets *sheet)
{
    printf("Enter ID of Member to update Meal for: ");
    int id;
    scanf("%d", &id);
    int i, found = 0;
    for (i = 0; i < sheet->num_members; i++)
    {
        if (sheet->members[i].id == id)
        {
            found = 1;
            printf("Enter day number (1-31) to update meal for: ");
            int day;
            scanf("%d", &day);
            if (day < 1 || day > MEAL_RECORD_LENGTH)
            {
                printf("Error: invalid day number.\n");
                break;
            }
            printf("Enter Number of Meal for day %d: ", day);
            int meal;
            scanf("%d", &meal);
            sheet->members[i].mealofamonth.days[day - 1] = meal;
            printf("Meal updated for member %d on day %d.\n", id, day);

            //
            // sheet->total_meals = 0;
            // for (int k = 0; k < sheet->num_members; k++)
            // {

            //     for (int j = 0; j < MEAL_RECORD_LENGTH; j++)
            //     {
            //         sheet->total_meals += sheet->members[k].mealofamonth.days[j];
            //     }
            // }
            // printf("Total Meal : %10d \n", sheet->total_meals);
            //

            for (i = 0; i < sheet->num_members; i++)
            {
                sheet->members[i].total_indv_meal = 0;
                for (int j = 0; j < MEAL_RECORD_LENGTH; j++)
                {
                    sheet->members[i].total_indv_meal += sheet->members[i].mealofamonth.days[j];
                }
                // printf("%10d |", sheet->members[i].total_indv_meal);
            }
            sheet->total_meals = 0;
            for (int k = 0; k < sheet->num_members; k++)
            {

                sheet->total_meals += sheet->members[k].total_indv_meal;
            }
            //
            sheet->meal_rate = 0;
            sheet->meal_rate = (sheet->total_meal_cost / sheet->total_meals);

            for (int i = 0; i < sheet->num_members; i++)
            {
                sheet->members[i].bill_per_person=(sheet->total_ubills / sheet->num_members);
                sheet->members[i].indv_meal_cost=(sheet->members[i].total_indv_meal*sheet->meal_rate);
                sheet->members[i].maid_bill=MAIDBILL;
                sheet->members[i].indv_total_cost=(sheet->members[i].indv_meal_cost+sheet->members[i].maid_bill+sheet->members[i].bill_per_person);
            }
            
            //
            break;
        }
    }

    if (!found)
    {
        printf("Error: member not found.\n");
    }
}

// Function to print the meal report for the sheet
void print_meal_report(struct Sheets *sheet)
{
    int i, j;

    // Print header row
    printf("%10s |", "Date");
    for (i = 0; i < sheet->num_members; i++)
    {
        printf("%10s |", sheet->members[i].name);
    }
    printf("\n");
    printf("--------------------------------------------------------------------------\n");

    // Print meal records for each day
    for (i = 0; i < MEAL_RECORD_LENGTH; i++)
    {
        printf("%10d |", i + 1);
        for (j = 0; j < sheet->num_members; j++)
        {
            printf("%10d |", sheet->members[j].mealofamonth.days[i]);
        }
        printf("\n");
        printf("--------------------------------------------------------------------------\n");
    }
    // Print totals row
    printf("%-10s |", "Total:");
    // int total_meal = 0;

    for (i = 0; i < sheet->num_members; i++)
    {
        sheet->members[i].total_indv_meal = 0;
        for (j = 0; j < MEAL_RECORD_LENGTH; j++)
        {
            sheet->members[i].total_indv_meal += sheet->members[i].mealofamonth.days[j];
        }
        printf("%10d |", sheet->members[i].total_indv_meal);
    }
    sheet->total_meals = 0;
    for (int k = 0; k < sheet->num_members; k++)
    {

        sheet->total_meals += sheet->members[k].total_indv_meal;
    }
    //
    sheet->meal_rate = 0;
    sheet->meal_rate = (sheet->total_meal_cost / sheet->total_meals);
    //
    printf("\n");
    printf("-------------------------------------------------------------------------\n");
    printf("Total Meals : %10d\n", sheet->total_meals);
    printf("-------------------------------------------------------------------------\n");
}

// VIEW DETAILS
void view_member_details(struct Sheets *sheet)
{
    printf("Enter ID of member to view details for: ");
    int id;
    scanf("%d", &id);
    int i, found = 0;
    printf("-------------------------------------------------------------\n");
    printf("-------------------------------------------------------------\n");

    for (i = 0; i < sheet->num_members; i++)
    {
        if (sheet->members[i].id == id)
        {
            found = 1;
            printf("Member ID          : %10d\n", sheet->members[i].id);
            printf("Member Name        : %10s\n", sheet->members[i].name);
            printf("Member Since       : %10s\n", sheet->members[i].sincemember);
            printf("Meal Rate          : %10.2f TK BDT.\n", sheet->meal_rate);
            printf("Total Meal         : %10d \n", sheet->members[i].total_indv_meal);
            printf("Total Meal Cost    : %10.2f TK BDT.\n", sheet->members[i].indv_meal_cost);
            printf("Total Utility Bill : %10.2f TK BDT.\n", sheet->members[i].bill_per_person);
            printf("Maid Bill          : %10.2f TK BDT.\n",sheet->members[i].maid_bill);
            printf("-------------------------------------------------------------\n");
            printf("Total Cost         : %10.2f TK BDT.\n", sheet->members[i].indv_total_cost);
            printf("BALANCE            : %10.2f TK BDT.\n", sheet->members[i].Balance);

            printf("\n");
            // int total_meal = 0;
            // for (int j = 0; j < MEAL_RECORD_LENGTH; j++)
            // {
            //     total_meal += sheet->members[i].mealofamonth.days[j];
            // }
            // printf("Total Meal: %d\n", total_meal);
            break;
        }
    }
    if (!found)
    {
        printf("Error: member not found.\n");
    }
    printf("-------------------------------------------------------------\n");
    printf("-------------------------------------------------------------\n");
}

// FUNCTION To Add or Cut BALANCE to The Members
void update_balance(struct Sheets *sheet)
{
    printf("Enter ID of Member to ADD Balance for: ");
    int id;
    scanf("%d", &id);
    printf("-------------------------------------------------------------\n");
    int i, found = 0;
    for (i = 0; i < sheet->num_members; i++)
    {
        if (sheet->members[i].id == id)
        {

            found = 1;
            printf("\n-----------------\n");
            printf("Current Balance\n-----------------\n  o ID : %d\n  o Name : %s \n  $ Balance =  %.2f TK BDT \n", id, sheet->members[i].name, sheet->members[i].Balance);

            printf("\n\nEnter Number of Balance to add or cut  for ID %d\n(To cut use '-' before the number): ", id);
            float balance;
            scanf("%f", &balance);
            sheet->members[i].Balance += balance;
            printf("\n-----------------\n");
            printf("Balance updated\n-----------------\n  o ID : %d\n  o Name : %s \n ", id, sheet->members[i].name);
            if (balance >= 0)
            {
                printf(" + Balance Added%14s= %7.2f TK BDT\n", "", balance);
                printf("  = After Adding current total = %-6.2f TK BDT \n", sheet->members[i].Balance);
            }
            else
            {
                printf(" - Balance Cutted %13s=%8.2f TK BDT\n", "", balance);
                printf("  = After cutting current total = %-7.2f TK BDT\n", sheet->members[i].Balance);
            }

            break;
        }
    }
    if (!found)
    {
        printf("Error: member not found.\n");
    }
    printf("-------------------------------------------------------------\n");
}
// View Bills
void print_bill_report(struct Sheets *sheet)
{
    int i, j;

    // Print header row
    printf("%10s |", "ID");
    printf("%30s |", "Details");
    printf("%10s |", "Amount");
    printf("\n");
    printf("-------------------------------------------------------------\n");

    for (i = 0; i < sheet->num_bill; i++)
    {

        printf("%10d |", sheet->bills[i].bID);
        printf("%30s |", sheet->bills[i].details);
        printf("%10.2f |", sheet->bills[i].cost);
        printf("\n");
        printf("-------------------------------------------------------------\n");
    }
    // Print totals row
    printf("%-10s |", "Total ");
    printf("%-30s |", ":");
    // float total_bill = 0;
    printf("%10.2f |", sheet->total_ubills);
    printf("\n");
    printf("-------------------------------------------------------------\n");
}

// print meal cost report
void print_mealcost_report(struct Sheets *sheet)
{
    int i, j;

    // Print header row
    printf("%10s |", "ID");
    printf("%30s |", "Details");
    printf("%10s |", "Amount");
    printf("\n");
    printf("-------------------------------------------------------------\n");

    for (i = 0; i < sheet->num_mealcost; i++)
    {

        printf("%10d |", sheet->mealcosts[i].mcID);
        printf("%30s |", sheet->mealcosts[i].mcdetails);
        printf("%10.2f |", sheet->mealcosts[i].mcost);
        printf("\n");
        printf("-------------------------------------------------------------\n");
    }
    // Print totals row
    printf("%-10s |", "Total ");
    printf("%-30s |", ":");
    // float total_mealcost = 0;
    // for (i = 0; i < MAX_BILL; i++)
    // {
    //     total_mealcost += sheet->mealcosts[i].mcost;
    // }
    printf("%10.2f |", sheet->total_meal_cost);
    printf("\n");
    printf("-------------------------------------------------------------\n");
}

// MAIN FUNCTION
int main()
{
    struct Sheets sheet = {0};

    char filename[MAX_FILENAME_LENGTH];
    printf("\nEnter filename to load sheet data from,\nOr enter 'new' to start a new sheet: ");
    scanf("%s", filename);

    if (strcmp(filename, "new") != 0)
    {
        FILE *file = fopen(filename, "rb");
        if (!file)
        {
            printf("Error: could not open file %s.\n", filename);
            return 1;
        }
        fread(&sheet, sizeof(struct Sheets), 1, file);
        fclose(file);
        printf("sheet data loaded from file.\n");
    }

    while (1)
    {
        printf("\n");
        printf("1. Add member\n");
        printf("2. Remove member\n");
        printf("3. Update Meal\n");
        printf("4. View Meal report\n");
        printf("5. View member details\n");
        printf("6. Add or cut Balance\n");
        printf("7. Add Bill\n");
        printf("8. View Bill\n");
        printf("9. Add Meal Cost\n");
        printf("10. View Meal Cost Report\n");
        printf("11. Save and exit\n");

        printf("Enter option number: ");
        int option;
        scanf("%d", &option);

        switch (option)
        {
        case 1:
        {
            struct Member member = create_member();
            add_member(&sheet, member);
            break;
        }
        case 2:
        {
            remove_member(&sheet);
            break;
        }
        case 3:
        {
            update_mealofamonth(&sheet);
            break;
        }
        case 4:
        {
            print_meal_report(&sheet);
            break;
        }
        case 5:
        {
            view_member_details(&sheet);
            break;
        }
        case 6:
        {
            update_balance(&sheet);
            break;
        }
        case 7:
        {
            struct Bill bill = create_bill();
            add_bill(&sheet, bill);
            break;
        }
        case 8:
        {
            print_bill_report(&sheet);
            break;
        }
        case 9:
        {
            struct MealCost mealcost = create_mealcost();
            add_mealcost(&sheet, mealcost);
            break;
        }
        case 10:
        {
            print_mealcost_report(&sheet);
            break;
        }

        case 11:
        {
            printf("Enter filename to save sheet data to: ");
            scanf("%s", filename);
            FILE *file = fopen(filename, "wb");
            if (!file)
            {
                printf("Error: could not open file %s.\n", filename);
                return 1;
            }
            fwrite((&sheet), (sizeof(struct Sheets)), 1, file);
            fclose(file);
            printf("sheet data saved to file.\n");
            return 0;
        }
        default:
        {
            printf("Error: invalid option.\n");
            break;
        }
        }
    }
}

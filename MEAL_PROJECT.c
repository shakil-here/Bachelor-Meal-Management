#include <stdio.h>
#include <string.h>
#define MAX_FILENAME_LENGTH 300
#define MAX_MEMBER 500
#define MEAL_RECORD_LENGTH 30
#define MAX_BILL 10
#define MAX_MEAL_COST 300
#define MAIDBILL 500

struct Mealofamonth
{
    int days[MEAL_RECORD_LENGTH];
};
struct Member
{
    int id;
    char name[20];
    char mobile_number[12];
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

void print_line_meal_report(int num_members)
{
    if (num_members == 1)
    {
        printf("|%11s|%11s|", "-----------", "-----------");
        printf("\n");
    }

    if (num_members == 2)
    {
        printf("|%11s|%11s|%11s|", "-----------", "-----------", "-----------");
        printf("\n");
    }

    if (num_members == 3)
    {
        printf("|%11s|%11s|%11s|%11s|", "-----------", "-----------", "-----------", "-----------");
        printf("\n");
    }

    if (num_members == 4)
    {
        printf("|%11s|%11s|%11s|%11s|%11s|", "-----------", "-----------", "-----------", "-----------", "-----------");
        printf("\n");
    }

    if (num_members == 5)
    {
        printf("|%11s|%11s|%11s|%11s|%11s|%11s|", "-----------", "-----------", "-----------", "-----------", "-----------", "-----------");
        printf("\n");
    }
}

// Line Print for all member report
void print_line_all_report(int num_members)
{
    if (num_members == 1)
    {
        printf("|%21s|%11s|", "----------------------", "-----------");
        printf("\n");
    }

    if (num_members == 2)
    {
        printf("|%21s|%11s|%11s|", "----------------------", "-----------", "-----------");
        printf("\n");
    }

    if (num_members == 3)
    {
        printf("|%21s|%11s|%11s|%11s|", "----------------------", "-----------", "-----------", "-----------");
        printf("\n");
    }

    if (num_members == 4)
    {
        printf("|%21s|%11s|%11s|%11s|%11s|", "----------------------", "-----------", "-----------", "-----------", "-----------");
        printf("\n");
    }

    if (num_members == 5)
    {
        printf("|%21s|%11s|%11s|%11s|%11s|%11s|", "----------------------", "-----------", "-----------", "-----------", "-----------", "-----------");
        printf("\n");
    }
}

// Welcome Messages
void welcome_message()
{

    printf("|----------------------------------------------------------|\n");
    printf("|----------------------------------------------------------|\n");
    printf("|                                                          |\n");
    printf("|                   MEAL TRACKER  SYSTEM                   |\n");
    printf("|                                                          |\n");
    printf("|----------------------------------------------------------|\n");
    printf("|                         welcome                          |\n");
    printf("|----------------------------------------------------------|\n");
    printf("|----------------------------------------------------------|\n");
}

// END Messages

void end_message()
{

    printf("|----------------------------------------------------------|\n");
    printf("|----------------------------------------------------------|\n");
    printf("|                                                          |\n");
    printf("|                 MEAL TRACKER  SYSTEM                     |\n");
    printf("|                                                          |\n");
    printf("|----------------------------------------------------------|\n");
    printf("|----------------------------------------------------------|\n");
    printf("| A Project by     :  Md Shakil Hossain                    |\n");
    printf("| Email            :  mhossain223670@bscse.uiu.ac.bd       |\n");
    printf("| Github           :  www.github.com/shakil-here           |\n");
    printf("|----------------------------------------------------------|\n");
    printf("|----------------------------------------------------------|\n");
    printf("|                                                          |\n");
    printf("|          THANKS FOR USING MEAL TRACKER SYSTEM            |\n");
    printf("|                                                          |\n");
    printf("|----------------------------------------------------------|\n");
    printf("|----------------------------------------------------------|\n");
}

// Display Menu

void display_menu()
{

    printf("|-----------------------------------------|\n");
    printf("|              MENU OPTIONS               |\n");
    printf("|-----------------------------------------|\n");
    printf("|  Option  |           Action             |\n");
    printf("|----------|------------------------------|\n");
    printf("|     1    |        Add member            |\n");
    printf("|----------|------------------------------|\n");
    printf("|     2    |       Remove member          |\n");
    printf("|----------|------------------------------|\n");
    printf("|     3    |         Update Meal          |\n");
    printf("|----------|------------------------------|\n");
    printf("|     4    |       View Meal report       |\n");
    printf("|----------|------------------------------|\n");
    printf("|     5    |      View member details     |\n");
    printf("|----------|------------------------------|\n");
    printf("|     6    |     Add or cut Balance       |\n");
    printf("|----------|------------------------------|\n");
    printf("|     7    |           Add Bill           |\n");
    printf("|----------|------------------------------|\n");
    printf("|     8    |           View Bill          |\n");
    printf("|----------|------------------------------|\n");
    printf("|     9    |         Add Meal Cost        |\n");
    printf("|----------|------------------------------|\n");
    printf("|    10    |   View Meal Cost Report      |\n");
    printf("|----------|------------------------------|\n");
    printf("|    11    |       View Sorting Report    |\n");
    printf("|----------|------------------------------|\n");
    printf("|    12    | View All details of Members  |\n");
    printf("|----------|------------------------------|\n");
    printf("|    13    |       Save and Exit          |\n");
    printf("|----------|------------------------------|\n");
    printf("|    00    |       Exit without Save      |\n");
    printf("|----------|------------------------------|\n");
    printf("+----------+------------------------------+\n");
    printf("|              Enter option               |\n");
    printf("|-----------------------------------------|\n\n");
}

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
        sheet->members[i].bill_per_person = (sheet->total_ubills / sheet->num_members);
        sheet->members[i].indv_meal_cost = (sheet->members[i].total_indv_meal * sheet->meal_rate);
        sheet->members[i].maid_bill = MAIDBILL;
        sheet->members[i].indv_total_cost = (sheet->members[i].indv_meal_cost + sheet->members[i].maid_bill + sheet->members[i].bill_per_person);
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
        sheet->members[i].bill_per_person = (sheet->total_ubills / sheet->num_members);
        sheet->members[i].indv_meal_cost = (sheet->members[i].total_indv_meal * sheet->meal_rate);
        sheet->members[i].maid_bill = MAIDBILL;
        sheet->members[i].indv_total_cost = (sheet->members[i].indv_meal_cost + sheet->members[i].maid_bill + sheet->members[i].bill_per_person);
    }

    printf("Bill added to sheet.\n");
}

// Function to create a new member
struct Member create_member()
{
    char a[20];
    struct Member member;
    printf(":::::ADDING NEW MEMBER:::::\n");
    printf("+------------------------------------------------|\n");
    printf("| Enter member ID: ");
    scanf("%d", &member.id);
    getchar();
    printf("|------------------------------------------------|\n");
    printf("| Enter member name: ");
    fgets(member.name, 20, stdin);
    member.name[strcspn(member.name, "\n")] = '\0';
    // puts("|");
    printf("|------------------------------------------------|\n");
    printf("| Enter member mobile number: ");
    fgets(member.mobile_number, 12, stdin);
    printf("|------------------------------------------------|\n\n");
    member.mobile_number[strcspn(member.mobile_number, "\n")] = '\0';
    memset(member.mealofamonth.days, 0, sizeof(member.mealofamonth.days));
    member.Balance = 0;
    member.bill_per_person = 0;
    member.indv_meal_cost = 0;
    member.indv_total_cost = 0;
    member.total_indv_meal = 0;

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
        sheet->members[i].bill_per_person = (sheet->total_ubills / sheet->num_members);
        sheet->members[i].indv_meal_cost = (sheet->members[i].total_indv_meal * sheet->meal_rate);
        sheet->members[i].maid_bill = MAIDBILL;
        sheet->members[i].indv_total_cost = (sheet->members[i].indv_meal_cost + sheet->members[i].maid_bill + sheet->members[i].bill_per_person);
    }
    printf("Member added to sheet.\n\n");
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
            sheet->total_meals = 0;

            for (int i = 0; i < sheet->num_members; i++)
            {
                sheet->total_meals += sheet->members[i].total_indv_meal;
                sheet->members[i].bill_per_person = (sheet->total_ubills / sheet->num_members);
                sheet->members[i].indv_meal_cost = (sheet->members[i].total_indv_meal * sheet->meal_rate);
                sheet->members[i].maid_bill = MAIDBILL;
                sheet->members[i].indv_total_cost = (sheet->members[i].indv_meal_cost + sheet->members[i].maid_bill + sheet->members[i].bill_per_person);
            }
            sheet->meal_rate = 0;
            sheet->meal_rate = (sheet->total_meal_cost / sheet->total_meals);
            printf("Member removed from sheet.\n");
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
            printf("Meal updated for  %d on day %d.\n\n", id, day);
            for (i = 0; i < sheet->num_members; i++)
            {
                sheet->members[i].total_indv_meal = 0;
                for (int j = 0; j < MEAL_RECORD_LENGTH; j++)
                {
                    sheet->members[i].total_indv_meal += sheet->members[i].mealofamonth.days[j];
                }
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
                sheet->members[i].bill_per_person = (sheet->total_ubills / sheet->num_members);
                sheet->members[i].indv_meal_cost = (sheet->members[i].total_indv_meal * sheet->meal_rate);
                sheet->members[i].maid_bill = MAIDBILL;
                sheet->members[i].indv_total_cost = (sheet->members[i].indv_meal_cost + sheet->members[i].maid_bill + sheet->members[i].bill_per_person);
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
    printf("\n:::::VIEWING MEAL REPORT:::::\n");
    // Print header row
    printf("\n");
    print_line_meal_report(sheet->num_members);
    printf("|%10s |", "Date");
    for (i = 0; i < sheet->num_members; i++)
    {
        printf("%10s |", sheet->members[i].name);
    }
    printf("\n");
    print_line_meal_report(sheet->num_members);
    // Print meal records for each day
    for (i = 0; i < MEAL_RECORD_LENGTH; i++)
    {
        printf("|%10d |", i + 1);
        for (j = 0; j < sheet->num_members; j++)
        {
            printf("%10d |", sheet->members[j].mealofamonth.days[i]);
        }
        printf("\n");
        print_line_meal_report(sheet->num_members);
    }
    // Print totals row
    printf("|%-10s |", "Total:");
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
    printf("--------------------------------------------------------------------------");
    printf("\n");
    printf("|Total Meals :  %10d", sheet->total_meals);
    printf("\n");
    printf("--------------------------------------------------------------------------");
    printf("\n");
}

// print all info
void print_all_info(struct Sheets *sheet)
{
    printf("\n:::::VIEWING ALL MEMBERS DETAILS:::::");
    // Print header row
    printf("\n");
    print_line_all_report(sheet->num_members);
    printf("|%-21s |", " ");
    for (int i = 0; i < sheet->num_members; i++)
    {
        printf("%10s |", sheet->members[i].name);
    }
    printf("\n");
    print_line_all_report(sheet->num_members);

    for (int i = 0; i < 7; i++)
    {
        if (i == 0)
        {
            printf("%-21s", "| Member ID            |");
            for (int j = 0; j < sheet->num_members; j++)
            {
                printf("%10d |", sheet->members[j].id);
            }
            printf("\n");
            print_line_all_report(sheet->num_members);
        }
        if (i == 1)
        {
            printf("%-21s", "| Total Meal           |");
            for (int j = 0; j < sheet->num_members; j++)
            {
                printf("%10d |", sheet->members[j].total_indv_meal);
            }
            printf("\n");
            print_line_all_report(sheet->num_members);
        }
        if (i == 2)
        {
            printf("%-21s", "| Total Meal Cost      |");
            for (int j = 0; j < sheet->num_members; j++)
            {
                printf("%10.2f |", sheet->members[j].indv_total_cost);
            }
            printf("\n");
            print_line_all_report(sheet->num_members);
        }
        if (i == 3)
        {
            printf("%-21s", "| Total Bill           |");
            for (int j = 0; j < sheet->num_members; j++)
            {
                printf("%10.2f |", sheet->members[j].bill_per_person + sheet->members[j].maid_bill);
            }
            printf("\n");
            print_line_all_report(sheet->num_members);
        }
        if (i == 4)
        {
            printf("%-21s", "| Total Cost           |");
            for (int j = 0; j < sheet->num_members; j++)
            {
                printf("%10.2f |", sheet->members[j].indv_total_cost);
            }
            printf("\n");
            print_line_all_report(sheet->num_members);
        }
        if (i == 5)
        {
            printf("%-21s", "| BALANCE              |");
            for (int j = 0; j < sheet->num_members; j++)
            {
                printf("%10.2f |", sheet->members[j].Balance);
            }
            printf("\n");
            print_line_all_report(sheet->num_members);
        }
        if (i == 6)
        {

            printf("%-21s", "| Need To Pay          |");
            for (int j = 0; j < sheet->num_members; j++)
            {
                printf("%10.2f |", sheet->members[j].Balance - sheet->members[j].indv_total_cost);
            }
            printf("\n");
            print_line_all_report(sheet->num_members);
        }
    }
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
            printf("Mobile Number      : %11s\n", sheet->members[i].mobile_number);
            printf("Meal Rate          : %10.2f TK BDT.\n", sheet->meal_rate);
            printf("Total Meal         : %10d \n", sheet->members[i].total_indv_meal);
            printf("Total Meal Cost    : %10.2f TK BDT.\n", sheet->members[i].indv_meal_cost);
            printf("Total Utility Bill : %10.2f TK BDT.\n", sheet->members[i].bill_per_person);
            printf("Maid Bill          : %10.2f TK BDT.\n", sheet->members[i].maid_bill);
            printf("-------------------------------------------------------------\n");
            printf("Total Cost         : %10.2f TK BDT.\n", sheet->members[i].indv_total_cost);
            printf("BALANCE            : %10.2f TK BDT.\n", sheet->members[i].Balance);
            printf("-------------------------------------------------------------\n");
            if (((sheet->members[i].Balance) - (sheet->members[i].indv_total_cost)) < 0)
            {
                printf("Need to pay        : %10.2f", (sheet->members[i].indv_total_cost - sheet->members[i].Balance));
            }
            else if (((sheet->members[i].Balance) - (sheet->members[i].indv_total_cost)) >= 0)
            {
                printf("Return money       : %10.2f", (sheet->members[i].Balance - sheet->members[i].indv_total_cost));
            }

            printf("\n");
            printf("\n");
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
    printf(":::::VIEWING BILL REPORT:::::\n");

    // Print header row
    printf("-------------------------------------------------------------\n");

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
    printf(":::::VIEWING MEAL COST REPORT:::::\n");

    // Print header row
    printf("------------------------------------------------------------\n");
    printf("%10s |", "ID");
    printf("%30s |", "Details");
    printf("%10s |", "Amount");
    printf("\n");
    printf("------------------------------------------------------------\n");

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

    printf("%10.2f |", sheet->total_meal_cost);
    printf("\n");
    printf("-------------------------------------------------------------\n\n");
}

// Sorting by meal (min to max)
void print_meal_min_to_max(struct Sheets *sheet)
{
    int tmember = sheet->num_members;
    struct Sheets mealMinToMax[tmember];
    for (int i = 0; i < sheet->num_members; i++)
    {
        mealMinToMax->members[i] = sheet->members[i];
    }

    int i, j;
    for (i = 0; i < tmember - 1; i++)
    {
        for (j = 0; j < tmember - i - 1; j++)
        {
            if (mealMinToMax->members[j].total_indv_meal > mealMinToMax->members[j + 1].total_indv_meal)
            {
                // swap
                struct Sheets temp;
                temp.members[0] = mealMinToMax->members[j];
                mealMinToMax->members[j] = mealMinToMax->members[j + 1];
                mealMinToMax->members[j + 1] = temp.members[0];
            }
        }
    }

    // print
    printf(" %-20s \t Total Meal\n", "Name:");
    printf("----------------------------------------\n");
    for (int i = 0; i < tmember; i++)
    {
        printf(" %-20s \t %-10d\n", mealMinToMax->members[i].name, mealMinToMax->members[i].total_indv_meal);
        printf("----------------------------------------\n");
    }
}

// Sorting Meal Max to Min
void print_meal_max_to_min(struct Sheets *sheet)
{
    int tmember = sheet->num_members;
    struct Sheets mealMaxToMin[tmember];

    for (int i = 0; i < sheet->num_members; i++)
    {
        mealMaxToMin->members[i] = sheet->members[i];
    }

    int i, j;
    for (i = 0; i < tmember - 1; i++)
    {
        for (j = 0; j < tmember - i - 1; j++)
        {
            if (mealMaxToMin->members[j].total_indv_meal < mealMaxToMin->members[j + 1].total_indv_meal)
            {
                // swap
                struct Sheets temp;
                temp.members[0] = mealMaxToMin->members[j];
                mealMaxToMin->members[j] = mealMaxToMin->members[j + 1];
                mealMaxToMin->members[j + 1] = temp.members[0];
            }
        }
    }

    // print
    printf(" %-20s \t Total Meal\n", "Name:");
    printf("----------------------------------------\n");
    for (int i = 0; i < tmember; i++)
    {
        printf(" %-20s \t %-10d\n", mealMaxToMin->members[i].name, mealMaxToMin->members[i].total_indv_meal);
        printf("----------------------------------------\n");
    }
}

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

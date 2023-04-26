#include <stdio.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_MEMBER 100
#define MEAL_RECORD_LENGTH 30
struct Mealofamonth
{
    int days[MEAL_RECORD_LENGTH];
};

struct Member
{
    int id;
    char name[20];
    char dob[11];
    struct Mealofamonth mealofamonth;
};

struct Sheets
{
    struct Member members[MAX_MEMBER];
    int num_members;
};

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
   if (sizeof(member.name)>10)
    {
        gets(a);
    }
    printf("Enter member Date of Birth(DD-MM-YYYY): ");
    fgets(member.dob, 11, stdin);
    member.dob[strcspn(member.dob, "\n")] = '\0';
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
    printf("-------------------------------------------------------------\n");

    // Print meal records for each day
    for (i = 0; i < MEAL_RECORD_LENGTH; i++)
    {
        printf("%10d |", i + 1);
        for (j = 0; j < sheet->num_members; j++)
        {
            printf("%10d |", sheet->members[j].mealofamonth.days[i]);
        }
        printf("\n");
        printf("-------------------------------------------------------------\n");
    }
    // Print totals row
    printf("%-10s |", "Total:");
    for (i = 0; i < sheet->num_members; i++)
    {
        int total_meal = 0;
        for (j = 0; j < MEAL_RECORD_LENGTH; j++)
        {
            total_meal += sheet->members[i].mealofamonth.days[j];
        }
        printf("%10d |", total_meal);
    }
    printf("\n");
    printf("-------------------------------------------------------------\n");
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
            printf("Member ID: %d\n", sheet->members[i].id);
            printf("Member Name: %s\n", sheet->members[i].name);
            printf("Date of Birth: %s\n", sheet->members[i].dob);
            int total_meal = 0;
            for (int j = 0; j < MEAL_RECORD_LENGTH; j++)
            {
                total_meal += sheet->members[i].mealofamonth.days[j];
            }
            printf("Total Meal: %d\n", total_meal);
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


//MAIN FUNCTION
int main()
{
    struct Sheets sheet = {0};
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter filename to load sheet data from,\nOr enter 'new' to start a new sheet: ");
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
        printf("6. Save and exit\n");
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
            printf("Enter filename to save sheet data to: ");
            scanf("%s", filename);
            FILE *file = fopen(filename, "wb");
            if (!file)
            {
                printf("Error: could not open file %s.\n", filename);
                return 1;
            }
            fwrite(&sheet, sizeof(struct Sheets), 1, file);
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

#include <stdio.h>
void monthlist();
void LNprint();
int LeapYearChecker(int a);
int MonthVAlue(int mvalue, int YearLP);
void ShowMonthName(int a);
void InitMealSheet(int mealsheetsizeRow, int mealsheetsizeColumn, int mealsheet[][mealsheetsizeColumn], int MemberCode[], int MemberCodeSize, int monthsize);
void TBLline(int a);
void TBLheader(int a);
void Sheetprint();
int Add_Value_TO_MealSheet(int mealsheetsizeRow, int mealsheetsizeColumn, int mealsheet[][mealsheetsizeColumn], int ValueOfTheDate);
int Calculation_of_sheet(int mealsheetsizeRow, int mealsheetsizeColumn, int mealsheet[][mealsheetsizeColumn]);

int main()
{
    int inpYaer, inpMonth;
    printf("\nEnter Year : \n");
    scanf("%d", &inpYaer);
    monthlist();
    scanf("%d", &inpMonth);
    int mchk = 0;
    while (mchk != 1)
    {
        if ((inpMonth == 1) || (inpMonth == 2) || inpMonth == 3 || inpMonth == 4 || inpMonth == 5 || inpMonth == 6 || inpMonth == 7 || inpMonth == 8 || inpMonth == 9 || inpMonth == 10 || inpMonth == 11 || inpMonth == 12)
        {
            printf("\nYEAR: %d    ", inpYaer);
            ShowMonthName(inpMonth);
            printf("\n");
            mchk = 1;
        }
        else
        {
            int vanish;
            printf("\nInvalid Month\nPlease Enter a Valid Month Number (1 to 12)\n");
            scanf("%d", &inpMonth);
            scanf("%c", &vanish);
            continue;
        }
    }

    int MonthSize = MonthVAlue(inpMonth, inpYaer);

    LNprint();
    printf("How Many Member Do You Want? \n");
    int NumOfMember, nummemchk = 0;
    scanf("%d", &NumOfMember);
    while (nummemchk != 1)
    {
        if (NumOfMember >= 0 && NumOfMember <= 5)
        {
            printf("\nTotal Member: %d\n\n", NumOfMember);
            nummemchk = 1;
        }
        else
        {
            int vanish;
            printf("Invalid Member Number \nPlease Select a valid member number 1 to 5\n");
            scanf("%d", &NumOfMember);
            scanf("%c", &vanish);
        }
    }

    printf("Enter All Member Code: \n(Member code always start with 1 .Example- 101,102)\n\n");
    int membercode[NumOfMember];
    for (int i = 0; i < NumOfMember; i++)
    {
        scanf("%d", &membercode[i]);
    }

    int column = NumOfMember + 1;
    int row = MonthSize + 2;
    int MealSheet[row][column];
    InitMealSheet(row, column, MealSheet, membercode, NumOfMember, MonthSize);
    Calculation_of_sheet(row, column, MealSheet);

    TBLline(column);
    printf("|  Date  |-- ID --\n");
    for (int i = 0; i < row; i++)
    {
        TBLline(column);
        for (int j = 0; j < column; j++)
        {
            if (j == 0)
            {
                printf("|%7d |", MealSheet[i][j]);
            }
            else
                printf("%7d  |", MealSheet[i][j]);
        }
        printf("\n");
    }
    TBLline(column);
    TBLline(column);
    printf(" 1) Add Date-wise Value\n");
    printf(" 2) Exit\n");
    TBLline(column);
    int inpvalmenu;
    int valmenucheck = 0;
    scanf("%d", &inpvalmenu);
    while (valmenucheck != 1)
    {
        if (inpvalmenu == 1 || inpvalmenu == 2)
        {
            if (inpvalmenu == 2)
            {
                break;
            }
            else
            {
                int checkerYESNO;
                do
                {

                    printf("\nEnter Date:\n ");
                    int valuefordate;
                    scanf("%d", &valuefordate);
                    Add_Value_TO_MealSheet(row, column, MealSheet, valuefordate);
                    Calculation_of_sheet(row, column, MealSheet);
                    TBLline(column);
                    printf("|  Date  |-- ID --\n");
                    for (int i = 0; i < row; i++)
                    {
                        TBLline(column);
                        for (int j = 0; j < column; j++)
                        {
                            if (j == 0)
                            {
                                printf("|%7d |", MealSheet[i][j]);
                            }
                            else
                                printf("%7d  |", MealSheet[i][j]);
                        }
                        printf("\n");
                    }
                    TBLline(column);
                    valmenucheck = 1;
                    printf("\n Do You want add more?\n");
                    printf("\n 1) Yes\n");
                    printf("\n 2) No\n");
                    scanf("%d", &checkerYESNO);

                } while (checkerYESNO ==1);
            }
        }
        else
        {
            int vanishq;
            printf("Invalid Member Number \nPlease Select a valid member number 1 to 5\n");
            scanf("%d", &inpvalmenu);
            scanf("%c", &vanishq);
        }
    }
}

int LeapYearChecker(int a)
{
    if (((a % 4 == 0) && (a % 100 != 0)) || (a % 400 == 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void ShowMonthName(int a)
{
    switch (a)
    {
    case 1:
        printf("Month: JANUARY");
        break;
    case 2:
        printf("Month: FEBRUARY");
        break;
    case 3:
        printf("Month: MARCH");
        break;
    case 4:
        printf("Month: APRIL");
        break;
    case 5:
        printf("Month: MAY");
        break;
    case 6:
        printf("Month: JUNE");
        break;
    case 7:
        printf("Month: JULY");
        break;
    case 8:
        printf("Month: AUGUST");
        break;
    case 9:
        printf("Month: SEPTEMBER");
        break;
    case 10:
        printf("Month: OCTBER");
        break;
    case 11:
        printf("Month: NOVEMBER");
        break;
    case 12:
        printf("Month: DECEMBER");
        break;

    default:
        break;
    }
}
int MonthVAlue(int mvalue, int YearLP)
{
    int msize;
    switch (mvalue)
    {
    case 1:
        msize = 31;
        break;
    case 2:
        if (LeapYearChecker(YearLP) == 1)
        {
            msize = 29;
        }
        else
        {
            msize = 28;
        }

        break;
    case 3:
        msize = 31;
        break;
    case 4:
        msize = 30;
        break;
    case 5:
        msize = 31;
        break;
    case 6:
        msize = 30;
        break;
    case 7:
        msize = 31;
        break;
    case 8:
        msize = 31;
        break;
    case 9:
        msize = 30;
        break;
    case 10:
        msize = 31;
        break;
    case 11:
        msize = 30;
        break;
    case 12:
        msize = 31;
        break;

    default:
        break;
    }
    return msize;
}
void InitMealSheet(int mealsheetsizeRow, int mealsheetsizeColumn, int mealsheet[][mealsheetsizeColumn], int MemberCode[], int MemberCodeSize, int monthsize)
{

    int date[monthsize + 1];
    int dates = 0;
    for (int i = 0; i <= monthsize; i++)
    {
        date[i] = dates;
        dates++;
    }

    int i, j, k;
    for (i = 0; i < mealsheetsizeRow; i++)
    {
        for (j = 0; j < mealsheetsizeColumn; j++)
        {

            mealsheet[i][j] = 0;
        }
    }
    for (i = 0; i < mealsheetsizeRow; i++)
    {
        for (j = 0; j < mealsheetsizeColumn; j++)
        {
            if (i == 0 & j >= 1)
            {
                for (k = 0; k < j; k++)
                {
                    mealsheet[i][j] = MemberCode[k];
                }
            }
            if (j == 0 && i >= 1 && i <= mealsheetsizeRow - 1)
            {
                for (int l = 0; l < monthsize; l++)
                {

                    mealsheet[i][j] = date[i];
                }
            }
        }
    }
}

int Add_Value_TO_MealSheet(int mealsheetsizeRow, int mealsheetsizeColumn, int mealsheet[][mealsheetsizeColumn], int ValueOfTheDate)
{
    int checkerYESNO = 1;
    printf("\n Enter ID Number :\n ");
    int ValueOfTheID;
    scanf("%d", &ValueOfTheID);
    int i, j, k;

    for (i = 0; i < mealsheetsizeRow; i++)
    {
        for (j = 0; j < mealsheetsizeColumn; j++)
        {
            if (mealsheet[0][j] == ValueOfTheID)
            {
                if (mealsheet[i][0] == ValueOfTheDate)
                {
                    int value;
                    printf("\n Enter Meal number for ID: %d \n", ValueOfTheID);
                    scanf("%d", &value);
                    mealsheet[i][j] = value;
                }
            }
        }
    }
}
int Calculation_of_sheet(int mealsheetsizeRow, int mealsheetsizeColumn, int mealsheet[][mealsheetsizeColumn]){
    int i,j,k;
    for (i = 0; i < mealsheetsizeColumn ; i++)
    {
        int sum=0;
        for (j = 0; j <mealsheetsizeRow; j++)
        {
            if (i>0 && j>0 && i<mealsheetsizeColumn-1 && j<mealsheetsizeRow-1)
            {
               sum+=mealsheet[j][i];
            }
            if (i==mealsheetsizeColumn-1 && j==mealsheetsizeRow-1)
            {
               mealsheet[j][i]=sum;
            }
            
            
        }
    }
}

void TBLline(int a)
{
    switch (a)
    {
    case 2:
        printf("--------------------\n");
        break;
    case 3:
        printf("------------------------------\n");
        break;
    case 4:
        printf("----------------------------------------\n");
        break;
    case 5:
        printf("--------------------------------------------------\n");
        break;
    case 6:
        printf("------------------------------------------------------------\n");
        break;
    case 7:
        printf("----------------------------------------------------------------------\n");
        break;
    default:
        break;
    }
}
void monthlist()
{
    printf("Enter Month ( 1-12 DIGIT ONLY): \n");
    printf("-------------------------------------\n");
    printf(" | JAN-- 1  |  MAY-- 5  |  SEP--09 | \n");
    printf(" | FEB-- 2  |  JUN-- 6  |  OCT--10 | \n");
    printf(" | MAR-- 3  |  JUL-- 7  |  NOV--11 | \n");
    printf(" | APR-- 4  |  AUG-- 8  |  DEC--12 | \n");
    printf("-------------------------------------\n");
}
void LNprint()
{
    printf("_______________________________________\n");
}
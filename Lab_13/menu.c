#include "menu.h"




void menu(head *head2)
{
    int choice;
    studs *str0=NULL;

    do
    {
        printf("| |         Menu        |\n");
        printf("+-+---------------------+\n");
        printf("|1| - All students      |\n");
        printf("|2| - Passed all exams  |\n");
        printf("|3| - Didn't pass exams |\n");
        printf("|4| - Add information   |\n");
        printf("|0| - Exit              |\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
        case 1:
            system("cls");
            print_header();
            list_out(head2,0); //All
            break;
        case 2:
            system("cls");
            print_header();
            list_out(head2,1); //Passed
            break;
        case 3:
            system("cls");
            print_header();
            list_out(head2,-1); //Not passed
            break;
        case 4:
            system("cls");
            printf("Adding info:\n");
            str0 = new_struct();
            add_in_order(head2,str0);
            system("cls");
            printf("Information added\n\n");
            break;
        case 0:
            system("cls");
            break;
        default:
            system("cls");
            puts("Incorrect input!");
            break;
        }

    } while(choice!=0);
}

#include "lab11.h"
#include "lab12.h"



int main()
{
    int choice;

    do
    {
        printf("| |Chose lab to run|\n");
        printf("+-+----------------+\n");
        printf("|1| - Lab N 11     |\n");
        printf("|2| - Lab N 12     |\n");
        printf("|0| - Exit         |\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
        case 1:
            system("cls");
            do_lab11();
            break;
        case 2:
            system("cls");
            do_lab12();
            break;
        case 0:

            break;
        default:
            system("cls");
            puts("Incorrect input!");
            break;
        }

    }while(choice!=0);

    return 0;
}

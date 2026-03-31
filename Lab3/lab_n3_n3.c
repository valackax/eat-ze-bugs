#include <stdio.h>

int main() {
    int apt, floor;

    printf("Enter the apartment number (from 1 to 45): ");
    scanf("%d", &apt);

    if (apt >= 1 && apt <= 45) {
        
        switch (floor) {
            case 1:
                printf("Apartment %d is located on the 1st floor.\n", apt);
                break;
            case 2:
                printf("Apartment %d is located on the 2nd floor.\n", apt);
                break;
            case 3:
                printf("Apartment %d is located on the 3rd floor.\n", apt);
                break;
            case 4:
                printf("Apartment %d is located on the 4th floor.\n", apt);
                break;
            case 5:
                printf("Apartment %d is located on the 5th floor.\n", apt);
                break;
            case 6:
                printf("Apartment %d is located on the 6th floor.\n", apt);
                break;
            case 7:
                printf("Apartment %d is located on the 7th floor.\n", apt);
                break;
            case 8:
                printf("Apartment %d is located on the 8th floor.\n", apt);
                break;
            case 9:
                printf("Apartment %d is located on the 9th floor.\n", apt);
                break;
            default:
                printf("An error occurred in calculations.\n");
                break;
        }
    } else {
        printf("Error: in a 9-story building (with 5 apartments per floor) there are only apartments from 1 to 45.\n");
    }

    return 0;
}

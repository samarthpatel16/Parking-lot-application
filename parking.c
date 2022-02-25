 #define _CRT_SECURE_NO_WARNINGS
 #include <stdio.h>

 #define LOT_SIZE 15
 #define COLOUR_MIN 0
 #define COLOUR_MAX 2

int main(void)
 {
    // C=car, P=pick-up, M=motorcycle, [any other value: n/a]
    char vehicleType[LOT_SIZE] = { 'C','P','M','P','C',
                                  '?','C','M','P','M',
                                   '?','C','P','M','C' };
    // 0=black, 1=white, 2=blue, [any other value: other]
     int colourCode[LOT_SIZE] = { 2,  0,  2,  1,  1,
                                99,  0,  1,  0,  1,
                                -4,  2,  0,  2,  0 };
    // Positive value contains a vehicle
    int parkingSpot[LOT_SIZE] = { 221, 171, 421, 351, 501,
                                    -1, 181, 231, 391, 461,
                                     0, 251, 411, 161, 371 };
     // Estimated black book value
     double estValue[LOT_SIZE] = { 46900.0, 15020.0, 10000.0, 81000.0, 24070.0,
                                       0.0, 94000.0, 12030.0, 86099.0,  8900.0,
                                       0.0, 63250.0, 36920.0,  9333.0,     0.0 };

     int i, querying, qryColour, matches;
     char qryType;
     double minValue, totalValue;

     printf("Current Parking Lot Data\n"
         "========================\n\n");

     i = 0;

     while (i < LOT_SIZE)
     {
         if (parkingSpot[i] > 0)
         {
             printf("Spot#:%3d ", parkingSpot[i]);

            if (vehicleType[i] == 'C')
             {
                 printf("CAR        ");
             }
             else if (vehicleType[i] == 'P')
             {
                printf("PICK-UP    ");
            }
             else if (vehicleType[i] == 'M')
             {
                printf("PICK-UP ");
             }

             switch (colourCode[i])
             {
             case 0:
                 printf("(black) ");
                 break;
             case 1:
                 printf("(white) ");
                 break;
            case 2:
                 printf("(blue)  ");
                 break;
             default:
                 printf("(other) ");
                 break;
            }
             printf(" Est:$%9.2lf\n", estValue[i]);
         }

         i++;

     }

     do {
        printf("\n"
             "Search Parking Lot by Vehicle Attribute\n"
             "---------------------------------------\n\n");
         printf("Match by COLOUR AND TYPE...\n");
        printf("COLOUR OPTIONS: 0=black, 1=white, 2=blue, [any other value=other]\n");
        printf("\tVehicle Colour: ");
         scanf("%d", &qryColour);
         printf("VEHICLE TYPE OPTIONS: C=car, P=pick-up truck, M=motorcycle\n");
         printf("\tVehicle Type:   ");
         scanf(" %c", &qryType);

         printf("\n"
             "Results:\n");
         printf("============================\n");
         printf("Spot#'s    : ");

         totalValue = 0.0;
        matches = 0;

        for (i = 0; i < LOT_SIZE; i++)
         {
             if (parkingSpot[i] > 0)
             {
                if (vehicleType[i] == qryType &&
                     ((colourCode[i] == qryColour) ||
                         (qryColour < COLOUR_MIN || qryColour > COLOUR_MAX) ||
                         (colourCode[i] < COLOUR_MIN || colourCode[i] > COLOUR_MAX)))
                 {
                     printf("%d ", parkingSpot[i]);
                     totalValue += estValue[i];
                     matches++;
                 }
             }
         }

        if (matches == 0)
         {
             printf("---\n"
                 "<NO RESULTS FOUND>\n\n");
         }
         else
         {
             printf("\n"
                 "Matches found: %d\n"
                 "Total Value  : $%9.2lf\n\n", matches, totalValue);
         }

         printf("Make another query? (0=no): ");
         scanf("%d", &querying);
     } while (querying);

     return 0;
 }



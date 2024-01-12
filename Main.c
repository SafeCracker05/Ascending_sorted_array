  #include <stdio.h>
#include <time.h>

int array[20] = {34, 12, 56, 5, 65, 7, 32, 67, 3, 88, 94, 45, 23, 4, 76, 87, 59, 6, 78, 2};
int new_array[20];
int number;


void ordre_croissant();

int main(void){

    int choice; 
    clock_t start, end;
    double cpu_time_used;

    do {
        printf("1-Sorting an array\n");
        printf("0- Exit\n");
        printf("Enter an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("this is the array will be sorted\n");
                printf("the array: {34, 12, 56, 5, 65, 7, 32, 67, 3, 88, 94, 45, 23, 4, 76, 87, 59, 6, 78, 2}\n");
                printf("Enter the number: ");
                scanf("%d", &number);
                start = clock(); // Enregistrez le temps de début
                // Appeler la fonction que vous voulez chronométrer
                ordre_croissant();
                end = clock(); // Enregistrez le temps de fin
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("Time taken: %f seconds\n", cpu_time_used);
                break;

            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please enter a valid option.\n");
        }

        if (choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); // Consume the newline character
            getchar(); // Wait for Enter key
            printf("\033[H\033[J"); // Clear the terminal
        }

    } while (choice != 0);

    return 0;
    
}


void ordre_croissant() {

    int len = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < len; i++) {
        int minIndex = i;

        for (int j = i + 1; j < len; j++) {
            if (array[j] <  array[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the elements to move the minimum to the current position
        int temp = array[i]; // par example sur le i = 0 le min minIndex = 19 le temp = 34.
        array[i] = array[minIndex]; // array[0] va etre remple par l'index du nombre qui le plus petit  qui est array[minIndex]
        array[minIndex] = temp; // et le array[minIndex] == 34 on le met au fond

        // on met le plus petit au debut comment dans la deuxieme for on passera plus verifier sinon sa sortirait toujour le plus petit dans la prochaine iteration il comment a verifier j = i +1 donc il passe pas par 0 ou y'a le dernier plus petit 

        // Copy the current minimum to the result array
        new_array[i] = array[i]; // puis on ajoute dans le new_array le plus petit de nombre qui se trouve au debut du array

        printf("%d ", new_array[i]); // et on l'imprime 
    }
    printf("\n");



    
}


    

/*

    Cody Brooks
    cmbrooks@iastate.edu
    CPRE 185 Section B
    Programming Practice 3

    <Reflection 1 What were you trying to learn or achieve?>
        I tried to simulate a soda machine using the state machine design pattern
        that we learned about in the homework. The soda machine used functions,
        conditional statements and a loop to fit the requirements of the
        assignment. The soda machine is capable of receiving credit, dispensing
        soda of different flavors, keeping track of inventory and credit,
        restocking depleated sodas and returning unused credit to the user.
    <Reflection 2 Were you successful? Why or Why not?>
        Yes, the program meets all of the functionality that I wanted without
        compromise in effeciency or style.
    <Reflection 3 Would you do anything differently if starting this program over?  If so, explain what.>
        I would have looked for a way other than a global variable to provide
        a return type of enum SodaMachineStates to the getNextState() function
        to avoid bad programming style.
    <Reflection 4 Think about the most important thing you learned when writing this piece of code.  What was it and explain why it was significant.>
        

*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

enum SodaMachineStates {INITIALIZE,
                        STOCK,
                        DISPENSE,
                        ADD_CREDIT,
                        CHECK,
                        CHANGE,
                        IDLE,
                        HELP,
                        EXIT
                        };

enum SodaMachineStates getNextState ();
void returnChange (double credit);
bool closeTo (double tolerance, double target, double val);

int main () {


    enum SodaMachineStates nextState = INITIALIZE;
    int rcCount, drPepperCount, creamSodaCount, rootBeerCount;
    double credit, totalCredit, costPerCan, creditToAdd;
    bool exitMachine;
    char sodaType[50];

    exitMachine = false;
    while (!exitMachine) {

        switch (nextState) {

            case INITIALIZE:
                credit = 0.0;
                rcCount = 10;
                drPepperCount = 10;
                creamSodaCount = 10;
                rootBeerCount = 10;
                costPerCan = 0.75;
                nextState = IDLE;
                break;

            case STOCK:
                rcCount = 10;
                drPepperCount = 10;
                creamSodaCount = 10;
                rootBeerCount = 10;
                nextState = IDLE;
                printf("All sodas stocked to full capacity\n");
                break;

            case DISPENSE:
                if (credit >= costPerCan) {
                    printf("What kind of soda? ");
                    scanf("%s", sodaType);
                    if (strcmp(sodaType, "RC") == 0) {
                        if (rcCount > 0) {
                            --rcCount;
                            credit -= costPerCan;
                            totalCredit += costPerCan;
                            printf("Dispensed: RC\n");
                        } else {
                            printf("RC is out of stock\n");
                        }
                    } else if (strcmp(sodaType, "Dr_Pepper") == 0) {
                        if (drPepperCount > 0) {
                            --drPepperCount;
                            credit -= costPerCan;
                            totalCredit += costPerCan;
                            printf("Dispensed: Dr Pepper\n");
                        } else {
                            printf("Dr Pepper is out of stock");
                        }
                    } else if (strcmp(sodaType, "Cream_Soda") == 0) {
                        if (creamSodaCount > 0) {
                            --creamSodaCount;
                            credit -= costPerCan;
                            totalCredit += costPerCan;
                            printf("Dispensed: Cream Soda\n");
                        } else {
                            printf("Cream Soda is out of stock\n");
                        }
                    } else if (strcmp(sodaType, "Root_Beer") == 0) {
                        if (rootBeerCount > 0) {
                            --rootBeerCount;
                            credit -= costPerCan;
                            totalCredit += costPerCan;
                            printf("Dispensed: Root Beer\n");
                        } else {
                            printf("Root Beer is out of stock\n");
                        }
                    } else {
                        printf("This machine does not carry %s. Please us 'help' to see a list of available sodas.\n", sodaType);
                    }
                } else {
                    printf("Insufficient funds. Please insert more credit.\n");
                }
                nextState = IDLE;
                break;

            case ADD_CREDIT:
                printf("How much credit to add? ");
                scanf(" %lf", &creditToAdd);
                credit += creditToAdd;
                printf("$%.2lf added\n", creditToAdd);
                nextState = IDLE;
                break;

            case CHECK:
                printf("Inventory:\n");
                printf("\tRC Cola: %d\n", rcCount);
                printf("\tDr Pepper: %d\n", drPepperCount);
                printf("\tCream Soda: %d\n", creamSodaCount);
                printf("\tRoot Beer: %d\n", rootBeerCount);
                printf("\nCredit statistics:\n");
                printf("\tCurrently inserted: $%.2lf\n", credit);
                printf("\tTotal Collected: $%.2lf\n", totalCredit);
                printf("\n");
                nextState = IDLE;
                break;

            case CHANGE:
                returnChange(credit);
                credit = 0.0;
                nextState = IDLE;
                break;

            case HELP:
                printf("Below is a list of valid commands\n");
                printf("\tcheck: Returns the inventory of the soda machine and the current credit\n");
                printf("\tadd_credit: Adds credit to buy sodas with\n");
                printf("\tdispense: Dispenses the desired soda type if the machine has enough credit\n");
                printf("\tstock: All sodas are restocked to full capacity\n");
                printf("\tchange: Dispenses the remaining credit in the fewese number of coins possible\n");
                printf("\texit: Exits the prrogram\n");
                printf("\nBelow is a list of sodas available:\n");
                printf("\tRC\n");
                printf("\tDr Pepper (use Dr_Pepper)\n");
                printf("\tCream Soda (use Cream_Soda)\n");
                printf("\tRoot Beer (use Root_Beer)\n");
                nextState = IDLE;
                break;

            case EXIT:
                exitMachine = true;
                printf("Exiting the program\n");
                break;

            case IDLE:
            default:
                nextState = getNextState();
                break;

        }

    }

    return 0;

}

enum SodaMachineStates getNextState () {
    char command[50];
    printf("\nHow may I help you?\n");
    scanf("%s", command);
    if (strcmp(command, "exit") == 0) {
        return EXIT;
    } else if (strcmp(command, "check") == 0){
        return CHECK;
    } else if (strcmp(command, "help") == 0) {
        return HELP;
    } else if (strcmp(command, "add_credit") == 0) {
        return ADD_CREDIT;
    } else if (strcmp(command, "dispense") == 0) {
        return DISPENSE;
    } else if (strcmp(command, "change") == 0) {
        return CHANGE;
    } else if (strcmp(command, "stock") == 0) {
        return STOCK;
    } else {
        printf("Command not recognized. Use 'help' if you would like a list of available commands\n");
        return IDLE;
    }
}

void returnChange (double credit) {
    int numQuarters, numDimes, numNickles, numPennies;
    double creditRemaining;
    creditRemaining = credit;
    numQuarters = (int) (creditRemaining / 0.25);
    creditRemaining -= numQuarters * 0.25;
    numDimes = (int) (creditRemaining / 0.10);
    creditRemaining -= numDimes * 0.10;
    numNickles = (int) (creditRemaining / 0.05);
    creditRemaining -= numNickles * 0.05;
    numPennies = creditRemaining * 100;
    printf("Returned %d quarters, %d dimes, %d nickles and %d pennies\n", numQuarters, numDimes, numNickles, numPennies);

}

bool closeTo (double tolerance, double target, double val) {
    double higher, lower;
    lower = target - tolerance;
    higher = target + tolerance;
    if (val > lower && val < higher) {
        return true;
    } else {
        return false;
    }
}

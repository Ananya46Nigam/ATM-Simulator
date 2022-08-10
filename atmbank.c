
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

//Functions
void login();
void mainMenu();
void checkBalance(float balance);
float moneyDeposit(float balance);
float moneyWithdraw(float balance);
void menuExit();
void errorMessage();


//Main Code
int main() {
    //Local Declarations
    int option;
    float balance = 0.00;
    int choose;

    bool again = true;
	


    while (again) {
    mainMenu();

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("Your Selection:\t");
    scanf("%d", &option);


        switch (option) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance = moneyDeposit(balance);
                break;
            case 3:
                balance = moneyWithdraw(balance);
                break;

            case 4:
                menuExit();
                return 0;

            default:
                errorMessage();
                break;
        }

        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Would you like to choose another option?\n");
        printf("< 1 > Yes\n");
        printf("< 2 > No\n");
        scanf("%d", &choose);


		system("CLS");


        if (choose == 2) {
            again = false;
            menuExit();

        }

}


    return 0;
}//main code



//Functions

void mainMenu() {

    printf("******************Hello!*******************\n");
    printf("**********Welcome to ATM Banking***********\n\n");
    printf("****Please choose one of the options below by typing the corresponding numbers against them: ****\n\n");
    printf("< 1 >  Check Balance\n");
    printf("< 2 >  Deposit\n");
    printf("< 3 >  Withdraw\n");
    printf("< 4 >  Exit\n\n");

}//Main Menu

void checkBalance(float balance) {
    printf("You Chose To See Your Balance\n");
    printf("\n\nYour Available Balance Is: %.2f rupees\n\n", balance);

}//Check Balance





float moneyDeposit(float balance) {
    float deposit;
    printf("You Chose To Deposit\n");
    printf("Your Current Balance Is: %.2f rupees\n\n", balance);
    printf("Enter your amount to Deposit\n");
    scanf("%f", &deposit);


    balance += deposit;

    printf("\nYour New Balance Is: %.2f rupees\n\n", balance);
    return balance;

}//money deposit



float moneyWithdraw(float balance) {
    float withdraw;
    bool back = true;

    printf("You Chose to Withdraw\n");
    printf("Your Balance is: %.2f rupees\n\n", balance);

    while (back) {
    printf("Enter your amount to withdraw:\n");
    scanf("%f", &withdraw);


    if (withdraw <= balance) {
        back = false;
        balance -= withdraw;
        printf("\nYour withdrawing money is:  %.2f rupees\n", withdraw);
        printf("Your New Balance is:   %.2f rupees\n\n", balance);

    }

        else  {

        printf("Uh-oh! Looks like you don't have enough money!\n");
        printf("Please contact Customer Services if you think something is amiss\n");
        printf("Your Current Balance is:   %.2f rupees\n\n", balance);

    }
    }
    return balance;


}//money withdraw

void menuExit() {
    printf("-----Thank you for using AAA ATM\n Have a nice day-----\n");

}//exit menu

void errorMessage() {;
    printf("+++!!!You selected an invalid number! Please choose 1, 2, 3 or 4+++\n");
}//error message




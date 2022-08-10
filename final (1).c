
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

struct details
{
    char username[100];
    int account_no;
    int password;
    float balance;


}d[100];

//Functions
void login(struct details d[100],int,char *);
void mainMenu();
void checkBalance(struct details d[100],char * );
int amountToDeposit(struct details d[100],int,char * );
float moneyWithdraw(struct details d[100],int,char * );
void moneytransfer(struct details d[100],int,char * ,char * );
void changepin(struct details d[100],char * ,int);
void menuExit();
void errorMessage();
void initialize_details();

int length(int n)
{
  int count=0;
  while (n != 0)
    {
        n /= 10;
        ++count;
    }
  return count;
}

void initialize_details()
{
    int i=0;
    FILE *fp = fopen("details.txt","r+");
    if(fp==NULL)
    {
        perror("MESSAGE");
        return 0;
    }
    char buffer[50];
    while((fgets(buffer,50,fp))!=NULL)
    {
        char *v=strtok(buffer,",");
        strcpy(d[i].username,v);
        int *l=strtok(NULL,",");
        d[i].password=atoi(l);
        int *m=strtok(NULL,",");
        d[i].account_no=atoi(m);
        int *j=strtok(NULL,",");
        d[i].balance=atoi(j);
        i++;

    }
    fclose(fp);
}

int main()
{

    char uname[100],receiver[100];
    int i=0,pin,l,deposit_amount,withdraw_amount,transfer_amount;
    int option;
    float balance;
    int choose;
    printf("******************Hello!*******************\n");
    printf("**********Welcome to ATM Banking***********\n\n");
    printf("Please enter your User Name\n");
    scanf("%s",uname);
    printf("Please enter your 4 digit PIN\n");
    scanf("%d",&pin);
    initialize_details();
    l = length(pin);
    while(l!=4)
    {
        printf("\nLength of PIN is not equal to 4");
        printf("\nPlease enter your 4 digit PIN: ");
        scanf("%d",&pin);
        l = length(pin);
    }

    if(l==4)
    {
        login(d,pin,&uname);
    }

    bool again = true;
	void mainMenu()
    {
        printf("\n****Please choose one of the options below by typing the corresponding numbers against them: ****\n");
        printf("< 1 >  Check Balance\n");
        printf("< 2 >  Deposit\n");
        printf("< 3 >  Withdraw\n");
        printf("< 4 >  transfer money\n");
        printf("< 5 >  Change pin\n");
        printf("< 6 >  Exit\n\n");

    }

    while (again)
        {
            mainMenu();

            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
            printf("Your Selection:\t");
            scanf("%d", &option);


        switch(option)
        {
            case 1:
                checkBalance(d,&uname);
                break;
            case 2:
                printf("\nEnter the money to be deposited in multiples of 100:\t");
                scanf("%d",&deposit_amount);
                balance = amountToDeposit(d,deposit_amount,&uname);
                printf("\n Your Current Balance Is:Rs %.2f\n",balance);
                break;
            case 3:
                printf("\nEnter the amount to be withdrawn in multiples of 100:\t");
                scanf("%d",&withdraw_amount);
                balance = moneyWithdraw(d,withdraw_amount,&uname);
                break;

            case 4:
                printf("\nEnter the account name to which the money needs to be transfered:\t");
                scanf("%s",receiver);
                printf("\nEnter the amount to be transferred:\t");
                scanf("%d",&transfer_amount);
                moneytransfer(d,transfer_amount,&receiver,&uname);
                break;

            case 5:
                changepin(d,&uname,pin);
                printf("\nPin has been successfully changed");
                break;

            case 6:
                menuExit();
                return 0;

            default:
                errorMessage();
                break;
        }
    }
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Would you like to choose another option?\n");
        printf("< 1 > Yes\n");
        printf("< 2 > No\n");
        scanf("%d",choose);
		system("CLS");
        if (choose == 2)
        {
            again = false;
            menuExit();

        }


    return 0;
}

void login(struct details d[100],int pin,char *uname)
{
    int i=0,l;
    while(i<100)
            {
                if(strcmp(d[i].username,uname)==0)
                {
                    if(d[i].password==pin)
                    {
                        printf("\nSuccessfully logged in\n");
                        break;
                    }
                    else
                    {
                        printf("PIN incorrect.\nTries left : %d\nPlease enter the PIN again :\n",3-(i+1));
                        scanf("%d",&pin);
                        l = length(pin);
                        while(l!=4)
                        {
                          printf("Length of PIN is not equal to 4\n");
                          printf("Please enter your 4 digit PIN\n");
                          scanf("%d",&pin);
                          l = length(pin);
                        }
                    }

                }


            }
}

void checkBalance(struct details d[100],char *uname)
{
    printf("You Chose To See Your Balance\n");
    for(int i=0;i<sizeof(d);i++)
    {
        if(strcmp(d[i].username,uname)==0)
        {
            printf("\nYour Available Balance Is:Rs %.2f\n",d[i].balance);
        }
    }

}

int amountToDeposit(struct details d[100],int deposit_amount,char *uname)
{
    int total;
    printf("You Chose To See Deposit money\n");
    for(int i=0;i<sizeof(d);i++)
    {
        if(strcmp(d[i].username,uname)==0)
        {
            if(deposit_amount%100==0 && deposit_amount>100)
            {
                d[i].balance=d[i].balance+deposit_amount;
                total=d[i].balance;
            }
        }
    }
    return total;
}

float moneyWithdraw(struct details d[100],int withdraw_amount,char *uname)
{
    int total;
    printf("You Chose To See Withdraw money\n");
    for(int i=0;i<sizeof(d);i++)
    {
        if(strcmp(d[i].username,uname)==0)
        {
            if(d[i].balance>withdraw_amount && withdraw_amount>100)
            {
                d[i].balance=d[i].balance-withdraw_amount;
                total=d[i].balance;
            }
        }
    }
    return total;
}

void moneytransfer(struct details d[100],int transfer_amount,char *reciever,char *uname)
{
    float total_balance;
     printf("You Chose To See Transfer money\n");
    for(int i=0;i<sizeof(d);i++)
    {
        if(strcmp(d[i].username,uname)==0)
        {
            for(int j=0;j<sizeof(d);j++)
            {
                if(strcmp(d[j].username,reciever)==0)
                {
                    if(d[i].balance>transfer_amount && transfer_amount>100)
                    {
                        d[i].balance=d[i].balance-transfer_amount;
                        d[j].balance=d[j].balance+transfer_amount;
                        printf("\nYour Account balance after money transfer:Rs %.2f",d[i].balance);
                    }
                }
            }
        }
    }

}

void changepin(struct details d[100],char *uname,int pin)
{
    int account_number,newpin;
    printf("\nEnter your account number:\t");
    scanf("%d",&account_number);
    for(int i=0;i<sizeof(d);i++)
    {
        if(strcmp(d[i].username,uname)==0)
        {
            if(d[i].account_no==account_number)
            {
                printf("\nEnter your old pin:\t");
                if(d[i].password==pin)
                {
                    printf("\nEnter your new pin:\t");
                    scanf("%d",&newpin);
                }

            }
        }
        d[i].password=newpin;
    }
}
void menuExit()
{
    printf("-----Thank you for using AAA ATM\n Have a nice day-----\n");

}

void errorMessage()
{
    printf("+++!!!You selected an invalid number! Please choose 1, 2, 3 or 4+++");
}





#include<stdio.h>
#include<string.h>


struct details
{
    char username[100];
    int password;
    int balance;

}d[100];

void deposit(struct details d[100],int amount,char uname);
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

int main()
{
    printf("******************Hello!*******************\n");
    printf("**********Welcome to ATM Banking***********\n\n");
    char uname[100];
    int amount;
    printf("Please enter your User Name\n");
    scanf("%s",uname);
    printf("\n Enter the amount to be deposited\t");
    scanf("%d",&amount);

    FILE *fp=fopen("details.csv","r+");
    if(fp==NULL)
    {
        perror("MESSAGE");
        return 0;
    }
    char buffer[1000];
    int i=0;
    while((fgets(buffer,1000,fp))!=EOF)
    {
        char *v=strtok(buffer,",");
        strcpy(d[i].username,v);
        v=strtok(NULL,",");
        d[i].password=atoi(v);
        v=strtok(NULL,",");
        d[i].balance = atoi(v);
        i++;
    }
    return 0;
}

void deposit(struct details d[100],int amount,char uname)
{
    int total;
        for(int i=0;i<sizeof(d);i++)
        {
            if(strcmp(d[i].username,uname)>0)
            {

                if(amount%100==0 && amount<50000 && amount>100)
                {
                    d[i].balance=d[i].balance+amount;
                    total=d[i].balance;
                }
                else
                {
                    printf("\n Enter the amount to be deposited\t");
                    scanf("%d",&amount);
                    deposit(d,amount,uname);
                }
            }
        }

}


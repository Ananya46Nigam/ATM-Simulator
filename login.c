#include<stdio.h>
#include<stdlib.h> //to use exit
#include<string.h>
#include<math.h>

int length(int n){
  int count=0;
  while (n != 0) {
        n /= 10;
        ++count;
    }
  //printf("%d",count);
  return count;
}

int main(){
char uname[100],funame[100],fpin[100],dataToBeRead[50],c,option;
int pin,i,len,l,x,flag=0,j;



printf("Hi,\n Welcome to ABC Bank\n");
printf("Please enter your User Name\n");
gets(uname);
printf("Please enter your 4 digit PIN\n");
scanf("%d",&pin);
l = length(pin);
while(l!=4){
  printf("Length of PIN is not equal to 4\n");
  printf("Please enter your 4 digit PIN\n");
  scanf("%d",&pin);
  l = length(pin);
}


FILE *f;
f = fopen("pin.txt", "r");
if ( f == NULL ){
        printf( "Error 1, Having server issue.\n Please try again after some time" ) ;
    }

while( fgets ( dataToBeRead, 100, f ) != NULL )
        {
          i = 0;
          while(i<100){
            if(*(dataToBeRead+i)=='|'){
            break;
          }
          funame[i]=dataToBeRead[i];
          i++;
          }
          //funame[i] = '\0';
          //printf("%s %s\n",funame,uname);
          //printf("%d",strcmp(funame,uname));
          if(strcmp(funame,uname)==0){
            flag = 1;
            x = 0;
            //printf("%s","yes");
            i=i+1;
            j = 0;
            while(i<100){
              if(*(dataToBeRead+i)=='\n'){
              break;
            }
            fpin[j++]=dataToBeRead[i];
            i++;
            }
            //printf("%s %d \n",fpin,x);
            fpin[i] = '\0';
            for(i = 0;i<4;i++){
              x = (x*10)+(fpin[i]-'0');
              //printf("%c %d \n",fpin[i],x);
            }
            //printf("%s %d \n",fpin,x);
            for(i=0;i<2;i++){
              if(x==pin){
              printf("PIN is correct");
              break;
            }
            printf("PIN incorrect.\nTries left : %d\nPlease enter the PIN again :\n",3-(i+1));
            scanf("%d",&pin);
            l = length(pin);
            while(l!=4){
              printf("Length of PIN is not equal to 4\n");
              printf("Please enter your 4 digit PIN\n");
              scanf("%d",&pin);
              l = length(pin);
            }
            //printf("%d %d \n",pin,x);
          }
          if(i==2){
            printf("0 tries left. Do you want to reset the PIN?\nPlease Enter Y/N :\n");
            scanf("%s", &option);
            //printf("%c", option);
          }
          }
        }
fclose(f);
if(flag==0){
  printf("Username not found.\nPlease try again.\nThank you for banking with us");
  exit(0);
}
if(option=='N'){
  printf("Thank you for banking with us");
  exit(0);
}
else if(option=='Y'){
  char pass[100],passdata[100],check[100],code[100],pindata[100],pinname[100],newpin[100];
  int flagpass = 0,j;

  printf("Please enter your internet banking password :\n");
  scanf("%s",&pass);
  strcpy(check,"");
  strcat(check,uname);
  strcat(check,"|");
  strcat(check,pass);
  //printf("%s %s\n",uname,check);
  FILE *fpass;
  fpass = fopen("pass.txt", "r");
  if ( fpass == NULL ){
          printf( "Error 2, Having server issue.\n Please try again after some time" ) ;
      }
  while( fgets ( passdata, 100, fpass ) != NULL )
          {
            i = 0;
            while(i<100){
              if(*(passdata+i)=='\n'){
              break;
            }
            code[i]=passdata[i];
            i++;
            }
            code[i] = '\0';
            //printf("%s yo\n",code);
            //printf("%d",strcmp(code,check));
            if(strcmp(code,check)==0){
              printf("Password is correct\n");
              flagpass = 1;
              FILE *f2;
              FILE *f3;
              f2 = fopen("pin.txt", "r");
              f3 = fopen("temp.txt","w");
              if ( f2 == NULL ){
                      printf( "Error 2, Having server issue.\n Please try again after some time" ) ;
                  }
              while( fgets ( pindata, 100, f2 ) != NULL )
              {
              j = 0;
              //printf("%s\n", pindata);
              while(j<100){
                if(*(pindata+j)=='|'){
                break;
              }
              pinname[j]=pindata[j];
              j++;
              }
              pinname[j] = '\0';
              //printf("%s %d %s\n",pinname, strcmp(pinname,uname), pindata);
              if(strcmp(pinname,uname)==0){
                char y[100];
                strcpy(y,"");
                strcat(y,uname);
                strcat(y,"|");
                printf("Please enter the new 4 digit PIN :\n");
                scanf("%s",&newpin);
                x = 0;
                for(i = 0;i<4;i++){
                  x = (x*10)+(newpin[i]-'0');
                  //printf("%c %d \n",fpin[i],x);
                }
                l = length(x);
                while(l!=4){
                  printf("Length of PIN is not equal to 4\n");
                  printf("Please enter the 4 digit PIN :\n");
                  scanf("%s",&newpin);
                  x = 0;
                  for(i = 0;i<4;i++){
                    x = (x*10)+(newpin[i]-'0');
                    //printf("%c %d \n",fpin[i],x);
                  }
                  l = length(x);
                }
                strcat(y,newpin);
                strcat(y,"\n");
                fputs(y,f3);
                printf("%s", "PIN changed successfully");
                //break;
              }
              else{
                fputs(pindata,f3);
              }


          }
          fclose(f2);
          fclose(f3);
          remove("pin.txt");
          rename("temp.txt", "pin.txt");
          }
        }
  if(flagpass==0){
    printf("Password is incorrect\n");
    printf("Please contact the bank.\nThank you for banking with us\n");
    exit(0);
  }
  fclose(fpass);


}
//printf("%s%d",uname,pin);
}

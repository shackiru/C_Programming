#include <stdio.h>

int main()             /* main first is of interger type and is the built in function used for starting the execution and finshing the given program*/
{  
    int count;            /* integer variable used in for loop, for number of times user want to take to shout name*/
    int counter;     /* integer variable used in for loop, to print name number of times*/
    
    int T, N;         /* interger T is used for given testcases and N is used for  print names number of times*/
    char *j="Jojo";    /* character poiinter varibale used to print jojo*/
    char *l="Lili";    /* character poiinter varibale used to print Lili*/
   
    scanf("%d", &T);
   
   for(count=1; count<=T; count++)        /*for loop to take input from user that how many times you want to print name in given test case*/
   {
       printf("Enter a number of times you want to shout in Case %d ", count);  /* number of times user want to take to shout name  */ 
    scanf("%d", &N);
  
       printf("Case #%d",count);  /* print statement to print case in given input*/
       printf(":\n");
     
     /* Initialize the value of counter to 1 and keep on incrementing it's value in every iteration till counter <= N */
    for(counter = 1; counter <= N; counter++)
     {  
         if (counter%15==0)        /*if statement for condition if number is 15 or not*/
         {
              printf("%d ", counter); /* print statement to print lili if number is 15*/
             printf("%s \n", l);  
         }
         else if (counter%3==0)    /*if statement for condition if number is 3 or not*/
         {
               printf("%d ", counter);  /* print statement to print lili if number is 3*/
              printf("%s \n", j);  
         }
         else if (counter%5==0)    /*if statement for condition if number is 5 or not*/
         {
               printf("%d ", counter); 
              printf("%s \n", j);  /* print statement to print lili if number is 5*/
         }
         else
         {
              printf("%d ", counter); /*print statement for condition if number is other then 3,5 amd 15*/
              printf("%s \n", l);
         }
        
    }
   }
    return 0;  
} 

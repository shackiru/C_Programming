 #include <stdio.h>  
 //recursive function F(n) 
 int F(int n) 
 {     
    //if n is equal to 1 then return 1     
    if(n==1)  
    {
        return 1;     
    }       
    //if n is even then call F(n/2)     
    if(n%2==0)   
    {
        return F(n/2);     
    }      
    //if n is odd then call F(n-1) + F(n+1)     
    else  
    {
        return F(n-1) + F(n+1);
    }      
}  
//main function 

int main() 
{        
    int n, t;

    scanf("%d",&t);                   
    for(int i = 0; i < t; i++)     
    {                  
        scanf("%d",&n);                  
        //call recursive function F(n) and store the return value in result        
        int result = F(n);                          
        printf("Case #%d: %d\n", i + 1, result);        
    } 	
    return 0; 
}
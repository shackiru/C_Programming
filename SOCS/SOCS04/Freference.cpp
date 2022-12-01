 #include <stdio.h>  
 int main() {    
	char s[10000];	//delaring a character array to store string    
	scanf("%[^\n]s",s);	//inputting string (incl. whitespaces) from user    
 	for (int i = 0; s[i]!='\0'; i++) {            
	 if(s[i] >= 'a' && s[i] <= 'z') {    
	 //if there are lowercase characters in the string             
	 s[i] = s[i] -32;                
	 //convert lowercase to uppercase         
	 }     
	 }          
	 for (int i = 0; s[i]!='\0'; i++){       //again traverse the loop         
	 if(s[i]=='I')                       //if character at i-th index is 'I', make it '1'             
	 s[i] = '1';                  
	 else if(s[i]=='R')                  //if character at i-th index is 'R', make it '2'             
	 s[i] = '2';                      
	else if(s[i]=='E')                  //if character at i-th index is 'E', make it '3'             
	 s[i] = '3';                      
	else if(s[i]=='A')                  //if character at i-th index is 'A', make it '4'            
	  s[i] = '4';                      
	else if(s[i]=='S')                  //if character at i-th index is 'S', make it '5'             
	  s[i] = '5';                     
	else if(s[i]=='G')                  //if character at i-th index is 'G', make it '6'            
	 s[i] = '6';                      
	else if(s[i]=='T')                  //if character at i-th index is 'T', make it '7'             
	s[i] = '7';                      
	else if(s[i]=='B')                  //if character at i-th index is 'B', make it '8'             
	s[i] = '8';                      
	else if(s[i]=='P')                  //if character at i-th index is 'P', make it '9'             
	s[i] = '9';                      
	else if(s[i]=='O')                  //if character at i-th index is 'O', make it '0'             
	s[i] = '0';     
	}          
	printf("%s", s);                        //print the modified string     
return 0; 
}


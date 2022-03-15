#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define stackSize 40 
char infix[40], res[40], opStack[40] ; 
int top = -1 ; 

void push(char x){
	if(top == stackSize-1) printf("Stack is full\n");
	else{
		opStack[++top] = x ; 
	}
}

char pop(){
	if(top == -1) printf("Stack is empty\n") ; 
	else{
		return opStack[top--] ; 
	}
}


void convert(){
	int i=0, j=0 ; // index for stack j , index for the char stream - i 
	for(i=0; infix[i]!='\0'; i++){
		if(isdigit(infix[i]) || isalpha(infix[i])) res[j++] = infix[i] ; 
		else{
			switch(infix[i]){
				case '(' : push(infix[i]) ; break ; 
				case ')' : while(opStack[top]!='(') res[j++] = pop() ; pop(); break ; 
				case '$' :
				case '^' : while(opStack[top]=='$'||opStack[top]=='^') 
								res[j++] = pop() ; 
								push(infix[i]) ; break ; 
				case '/' : 
				case '*' :while(opStack[top]=='$'||opStack[top]=='^'||
				opStack[top]=='*'||opStack[top]=='/') 
								res[j++] = pop() ; 
								push(infix[i]) ; break ;
				case '+' : 
				case '-' : while(opStack[top]=='$'||opStack[top]=='^'||
				opStack[top]=='*'||opStack[top]=='/'||
				opStack[top]=='+'||opStack[top]=='-')
								res[j++] = pop() ; 
								push(infix[i]) ; break; 
			}
		}
	}
	while(top > -1)
		res[j++] = pop() ;
	res[j] = '\0' ; 
	printf("Postfix Expression : %s", res) ;  
	
	
}
int main(){
	printf("Enter the infix Expression\n") ; 
	gets(infix) ; 
	convert() ; 
	return 0 ; 
}
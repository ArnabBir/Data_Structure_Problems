#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{//defining the structure
  char ch;
  struct node * next;
}node;
typedef node * Stack;
int prcd(char,char);
Stack Init();
int IsEmpty(Stack);
Stack push(Stack,char);
Stack pop(Stack);
char top(Stack);
int main()
{//main function starts
  int l,j=0,i=0;
  char symb[50];
  Stack opstk;
  opstk=Init();
  printf("\nEnter the expression in infix form: \n");
  scanf("%s",symb);
  l=strlen(symb)+1;
  char *Postexpr;
  Postexpr=(char *)malloc(l*sizeof(char));
  while(symb[i]!='\0')
  {
   if(symb[i]!='*'&&symb[i]!='+'&&symb[i]!='('&&symb[i]!=')')
   {//checking for operands
     Postexpr[j]=symb[i];
     j++;
   }
   else
   {//checking whether the operator has to be pushed or stack to be popped
     if(IsEmpty(opstk)||prcd(top(opstk),symb[i]))
       opstk=push(opstk,symb[i]);
     else
     {
         if(symb[i]!=')')
         {//emptying the stack only if not parenthesis till the opening one
             while(!IsEmpty(opstk)&&opstk->next->ch!='(')
             {
                 Postexpr[j]=opstk->next->ch;
                 j++;
                 opstk=pop(opstk);
             }
             opstk=push(opstk,symb[i]);
         }
         else
         {//popping till the last parenthesis
             while(opstk->next->ch!='(')
             {
                 Postexpr[j]=opstk->next->ch;
                 j++;
                 opstk=pop(opstk);
             }
             opstk=pop(opstk);
         }
    }
   }
   i++;
  }
  if(!IsEmpty(opstk))
   while(!IsEmpty(opstk))
   {//emptying the stack at the end
     Postexpr[j]=opstk->next->ch;
     j++;
     opstk=pop(opstk);
   }
  Postexpr[j]='\0';
  printf("The postfix expression is:\n");
  printf("%s",Postexpr);
  printf("\n");
  return 0;
}//main function ends
int prcd(char a,char b)
{//function to check the precedence of operators(highest if for brackets)
    if((a=='*'&&b=='+')||b==')')
        return 0;
    return 1;
}
Stack Init()
{//function to initialize the stack
 Stack Head;
 Head=(Stack)malloc(sizeof(node));
 Head->ch='\0';
 Head->next=NULL;
 return Head;
}
int IsEmpty(Stack s)
{//function to check for empty stack
 if(s->next==NULL)
   return 1;
 return 0;
}
char top(Stack s)
{//function to return the top element
 return s->next->ch;
}
Stack push(Stack s,char c)
{//function to push a new element in the stack
 Stack new;
 new=(Stack)malloc(sizeof(node));
 new->ch=c;
 new->next=s->next;
 s->next=new;
 return s;
}
Stack pop(Stack s)
{//function to pop an element from the stack
 s->next->ch='\0';
 return s->next;
}

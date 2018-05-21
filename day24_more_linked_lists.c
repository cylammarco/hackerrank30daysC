#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* removeDuplicates(Node *head)
{
    /* Pointer to traverse the linked list */
    struct Node* current = head;
 
    /* Pointer to store the next pointer of a node to be deleted*/
    struct Node* next_next; 
   
    /* do nothing if the list is empty */
    if (current == NULL) 
       return; 
 
    /* Traverse the list till last node */
    while (current->next != NULL) 
    {
       /* Compare current node with next node */
       if (current->data == current->next->data) 
       {
           /* The sequence of steps is important*/              
           next_next = current->next->next;
           free(current->next);
           current->next = next_next;  
       }
       else /* This is tricky: only advance if no deletion */
       {
          current = current->next; 
       }
    }
    return head;
}

Node* insert(Node *head,int data)
{
  Node *p = (Node*)malloc(sizeof(Node));
  p->data = data;
  p->next=NULL;   
  
  if(head==NULL){
   head=p;  
  
  }
  else if(head->next==NULL)
  {
      head->next=p;
      
  }
  else{
  Node *start=head;
  while(start->next!=NULL)
    start=start->next;
  
  start->next=p;   
  
  }
      return head;
}
void display(Node *head)
{
	Node *start=head;
	while(start)
	{
		printf("%d ",start->data);
		start=start->next;
	}
}
int main()
{
	int T,data;
    scanf("%d",&T);
    Node *head=NULL;	
    while(T-->0){
        scanf("%d",&data);
        head=insert(head,data);
    }
    head=removeDuplicates(head);
	display(head);
		
}

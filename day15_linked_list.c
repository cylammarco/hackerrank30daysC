#include <stdlib.h>
#include <stdio.h>	
typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* insert(Node *head,int data)
{
    Node *new_node = (Node*) malloc(sizeof(Node));
    
    new_node->data = data;
    new_node->next = NULL;
    
    if (head == NULL)
    {
        head = new_node;
    }
    else if (head->next == NULL)
    {
        head->next = new_node;
    }
    else
    {   
        Node *new_tail = head;
        while (new_tail->next != NULL)
        {
            new_tail = new_tail->next;
        }
        new_tail->next = new_node;
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
  display(head);
		
}

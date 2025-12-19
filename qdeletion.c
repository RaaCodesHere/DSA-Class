#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};

int main(){
	head = del_first(head);
	ptr = head;
	while(ptr != NULL)
	{
		printf("%d",ptr->data);
		ptr = ptr->link;
	}
	return 0;
}
	struct node* del_first(struct node *head)
	{
		if(head == NULL)
		printf("List is already empty!");
		else
		{
			struct node *temp = head;
			head = head->link;
			free(temp);
		}
		return head;
	}


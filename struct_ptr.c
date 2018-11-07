#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#define OK            0
#define ERROR        -1
#define MALLOC_ERROR -2

//void create_lnode(struct lnode node[10],int i);

typedef struct lnode
{
	//int *next;
	struct lnode *next;  //指针的类型不能是int型的，因为 node[i].next = &node[i+1] 要求类型保持一致; 
	int data;
 }lnode;
 
typedef struct lnode * link;
 
void create_lnode(struct lnode *p,int *a)
{
	struct lnode *s ;//= (struct lnode *)malloc(sizeof(struct lnode));
	
	int i;
	
	for(i=9;i>=0;i--)
	{
		s = (struct lnode *)malloc(sizeof(struct lnode));
		
		s->data = a[i];
		
		s->next = p->next;
		 
		p->next = s;
	}
	//free(s);
	//printf("%d\n",s);	 	
} 

void display(link l)
{
	for(;l != NULL;)
	{
		
		printf("%d\n",l->data);
	
		l = l->next;
	}
 } 
 
int print_link() 
{
	link p,l;
	
	p = (struct lnode*)malloc(sizeof(struct lnode));
	
	//printf("%d\n",*p);
	
	link p1 = p;
	
	p->next = NULL;
	
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	
	create_lnode(p,a);
	
	l = p->next;
	
	printf("%d\nhello",(p++)->data);
	
	display(l);
	
	free(p);
		
	return 0;
}

int main()
{
	link head,l;
	
	head = (struct lnode*)malloc(sizeof(struct lnode));	//要动态申请空间，要手动释放，不然分配在堆上的数据越来越大，堆区满的时候会发生新数据占用原来数据的堆区（内存泄漏）， 
	
	//l = (struct lnode*)malloc(sizeof(struct lnode));
	
	head->next = NULL;
	
	//printf("%d %d\n",p,l);
	
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	
	create_lnode(head,a);
	
	l = head->next;
	
	display(l);
	
	free(head);
	
	//free(l);
		
	return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
 
 
 
typedef int ElementType;

typedef struct node
{
	ElementType data;    
	struct node *next;   
}Node;

typedef Node *PNode; 

 
int Create_List_Head(PNode h, ElementType data)
{
	if (h == NULL)
	{
		return ERROR;
	}
	
	PNode node = (PNode)malloc(sizeof(Node)/sizeof(char));
	
	if (node == NULL)
	{
		return MALLOC_ERROR;
	}
	
	node->data = data;
	
	node->next = h->next;
	
	h->next = node;
	
	return OK;
}
 
 
 
void DisPlay(PNode h)
{
	if (h == NULL)
	{
		return;
	}
	PNode temp = h->next;  // 链表第一个结点指针
	
	while (temp)
	{
		printf ("%4d", temp->data);
		
		temp = temp->next;
	}
	
	printf ("\n");
}
 
int copy_web()
{
	PNode head_node = (PNode)malloc(sizeof(Node)/sizeof(char));
	
	if (head_node == NULL)
	{
		return ERROR;
	}
	head_node->next = NULL;   
	
	
	int i = 1;
	
	for (i = 1; i < 10; i++)
	{
		
 		if (Create_List_Head(head_node, i) != OK)
		{
			return ERROR;
		}  
	
	}
	
	DisPlay(head_node);
	
	return 0;
}



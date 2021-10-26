/**************************************************************** 

Creater:- Kumbhar Onkar Sandeep
Number:-BL.EN.U4EAC19032
Project:-Implementation of priority queue
Subject:-Data Structure and Algorithms
**********All Access To Third Party Denied
So, Here we will create Hotel application which will use priority queue.
We can serve any number of customers order at a time
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct hotel_order* order;//We are redefining struct pointer variable

int size;            //In c++ it will be easy to define class for different users
                    //Like customers,waiter,kitchen staff,owner
struct hotel_order{
    int table_no;
    char order_list[100];
    order next;
}*waiter;

void takeOrder(char* a,int table,int prio)
{
    order new_order=(order)malloc(sizeof(struct hotel_order));
    new_order->table_no=table;
    strcpy(new_order->order_list,a);
    if(size==0)
    {
        waiter=new_order;
        new_order->next=NULL;
    }else{
        if(prio==-2)
        {
            order acc;
            acc=(order)malloc(sizeof(struct hotel_order));
            acc=waiter;
            while(acc->next!=NULL)
            {
                acc=acc->next;
            }
            new_order->next=NULL;
            acc->next=new_order;
        }else{
            if (prio==1)
            {
                new_order->next=waiter;
                waiter=new_order;
            }else{
                order acc=(order)malloc(sizeof(struct hotel_order));
                acc=waiter;
                if(size<prio)
                {
                    prio=size;
                }
                int count=1;
                while(count<prio)
                {
                    acc=acc->next;
                    count++;
                }
                new_order->next=acc->next;
                acc->next=new_order;
            }
        }
    }
    size++;
}

void DisplayOrderList()
{
    order acc=(order)malloc(sizeof(struct hotel_order));
    acc=waiter;
    int count=1;
    printf("Total Number of orders with details...\n");
    printf("Ind    Table_no    OrderDetails\n");
    while(count<=size)
    {
        printf("%d      %d              %s\n",count,acc->table_no,acc->order_list);
        acc=acc->next;
        count++;
    }
}

order RemoveOrder()
{
    order acc=(order)malloc(sizeof(struct hotel_order));
    acc=waiter;
    waiter=waiter->next;
    free(acc);
    size--;
    return waiter;
}
int main(void)
{
    system("cls");
    system("color a");//This will change color to green
    int flag=1;
    //order waiter;//This is for waiter application part
    waiter=(order)malloc(sizeof(struct hotel_order));
    waiter->next=NULL;
    size=0;
    while(flag)
    {
        printf("\t\t\t\tWelcome To Imaginary Hotel Service\n\n");
        printf("We Provide Different Ways to take Order and arrange it in priority...\n");
        printf("Index                               Operations\n");
        printf("1.                          Take Order with priority\n");
        printf("2.                          Take Order Without priority\n");
        printf("3.                          Display Order List\n");
        printf("4.                          Remove Order From List\n");
        int index;
        printf("Enter Index Of Operation You Want To Perform::=>");
        scanf("%d",&index);
        switch (index)
        {
            case 1:///Take an order with priority
            {
                int wish=1;
                while(wish)
                {
                    char a[100];
                    printf("\nEnter Order Details...(DO NOT USE SPACES)::=>");
                    scanf("%s",a);
                    int prio,table_no;
                    printf("\nEnter Priority With this order..::=>");
                    scanf("%d",&prio);
                    printf("\nEnter table number With this order..::=>");
                    scanf("%d",&table_no);
                    takeOrder(a,table_no,prio);
                    printf("Do you want to continue same operation?(if yes enter 1 or enter 0)=>");
                    scanf("%d",&wish);   
                }
                break;
            }
            case 2:
            {
                int wish=1;
                while (wish)
                {
                    char a[100];
                    int prio,table_no;
                    printf("\nEnter Order Details...(DO NOT USE SPACES)::=>");
                    scanf("%s",a);
                    printf("\nEnter table number With this order..::=>");
                    scanf("%d",&table_no);
                    takeOrder(a,table_no,-2);
                    printf("Do you want to continue same operation?(if yes enter 1 or enter 0)=>");
                    scanf("%d",&wish);   
                }
                break;
            }
            case 3:
            {
                int wish=1;
                while (wish)
                {
                    DisplayOrderList();
                    printf("Do you want to continue same operation?(if yes enter 1 or enter 0)=>");
                    scanf("%d",&wish);   
                }
                break;
            }
            case 4:
            {
                //Everytime It will remove highest priority order
                int wish=1;
                while (wish)
                {
                    RemoveOrder();
                    printf("Do you want to continue same operation?(if yes enter 1 or enter 0)=>");
                    scanf("%d",&wish);   
                }
                break;
            }
            default:
            {
                printf("Sorry You choose wrong Index!!!\nTry Next Time\n");
                break;
            }
        }
        printf("Do You want to Run This Application Again...?(If yes enter 1 or enter 0)=>");
        scanf("%d",&flag);
        system("cls");
    }
    return 0;
}
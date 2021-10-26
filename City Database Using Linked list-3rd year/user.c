/*
    ****************************************************************
    Name:- Kumbhar Onkar Sandeep
    Reg.No:- BL.EN.U4EAC19032
    Sub:- Project (Data structure and algorithm project)

    This is user file to implement given problem.
    ****************************************************************
    RULES:-1)Set capital before doing anything 
    `````  2)Give proper input values
*/
#include<stdio.h>
#include<string.h>//Dealing with names
#include<math.h>//For calculating sqrt 
#include<stdlib.h>

int size=0;
typedef struct city* city_db;
struct city{
    char name[20];
    int latitude;
    int lognitude;
    struct city *next;
}*capital,*head;//Capital will store fixed point value

void set_capital(char* a,int la,int lo)//For finding data withing distace radius we need to set capital
{
    capital=(city_db)malloc(sizeof(struct city));
    strcpy(capital->name,a);
    capital->latitude=la;
    capital->lognitude=lo;
    capital->next=NULL;
    printf("\nCapital has been updated...\n");
}
//User will no need to send head or root for any operation
//in c++ by using class it will become easy

void insert(char* a,int la,int lo)
{
    city_db new_city;
    new_city=(city_db)malloc(sizeof(struct city));
    strcpy(new_city->name,a);
    new_city->latitude=la;
    new_city->lognitude=lo;
    if(size==0)
    {
        head=new_city;//Here we will assign to head variable 
        size++;
    }else{
        city_db acc=(city_db)malloc(sizeof(struct city));
        acc=head;
        while(acc->next!=NULL)
        {
            acc=acc->next;
        }
        acc->next=new_city;
        new_city->next=NULL;
        size++;
    }
}
void search_by_name(char* a)
{
    if(size==0)//We will check size of dataset
    {
        printf("\nCity database have no data...!!\n");
        return;
    }
    city_db acc=(city_db)malloc(sizeof(struct city));
    acc=head;//Here we are giving ref to head pointer
    int f=0;
    while(acc!=NULL)
    {
        if(strcmp(a,acc->name)==0)//After finding element we will print all data found
        {
            printf("%s      %d      %d\n",acc->name,acc->latitude,acc->lognitude);
            f=1;
        }
        acc=acc->next;
    }
    if(f==0)//If not we will print below message
    {
        printf("\nNo data found with given data...!!\n");
    }
}
void search_by_coordinate(int la,int lo)
{
    if(size==0)//We will check size of dataset
    {
        printf("\nCity database have no data...!!\n");
        return;
    }
    city_db acc=(city_db)malloc(sizeof(struct city));
    acc=head;
    int f=0;
    while(acc!=NULL)
    {
        if(acc->latitude==la&&acc->lognitude==lo)//After finding element we will print all data found
        {
            printf("%s      %d      %d\n",acc->name,acc->latitude,acc->lognitude);
            f=1;
        }
        acc=acc->next;
    }
    if(f==0)//If not we will print below message
    {
        printf("\nNo data found with given data...!!\n");
    }
}
void delete_by_name(char* a)
{
    if(size==0)//We will check size of dataset
    {
        printf("\nCity database have no data...!!\n");
        return;
    }
    city_db acc=(city_db)malloc(sizeof(struct city));
    acc=head;
    city_db temp=(city_db)malloc(sizeof(struct city));
    int f=0;
    while(acc!=NULL)
    {
        if(strcmp(a,acc->name)==0)//After finding element we will break while loop and we will delete node
        {
            f=1;
            size--;
            break;
        }
        temp=acc;
        acc=acc->next;
    }
    if(f==0)//If not we will print below message
    {
        printf("\nNo data found with given data...!!\n");
    }else{
        if(acc==head)
        {
            head=acc->next;
        }else{
            temp->next=acc->next;
        }
        free(acc);
        printf("\nData deleted succesfully...!!\n");
    }
}
void delete_by_coordinate(int la,int lo)
{
    if(size==0)//We will check size of dataset
    {
        printf("\nCity database have no data...!!\n");
        return;
    }
    city_db acc=(city_db)malloc(sizeof(struct city));
    acc=head;
    city_db temp=(city_db)malloc(sizeof(struct city));
    int f=0;
    while(acc!=NULL)
    {
        if(acc->latitude==la&&acc->lognitude==lo)//After finding element we will break while loop and we will delete node
        {
            f=1;
            size--;
            break;
        }
        temp=acc;
        acc=acc->next;
    }
    if(f==0)
    {
        printf("\nNo data found with given data...!!\n");
    }else{
        if(acc==head)
        {
            head=acc->next;
        }else{
            temp->next=acc->next;
        }
        free(acc);
        printf("\nData deleted succesfully...!!\n");
    }
}
void print_record(float distance)
{
    if(size==0)
    {
        printf("\nCity database have no data...!!\n");
        return;
    }
    city_db new_city;
    new_city=(city_db)malloc(sizeof(struct city));
    new_city=head;
    while(new_city!=NULL)//Here we will find min distance i.e. radius of circle
    {
        float min_distace=sqrt(pow((capital->latitude-new_city->latitude),2)+pow((capital->lognitude-new_city->lognitude),2));
        if(min_distace<=distance)//We will campare wit dataset
        {
            printf("\n%s      %d      %d\n",new_city->name,new_city->latitude,new_city->lognitude);
        }
        new_city=new_city->next;
    }
}

int main(void)
{
    system("cls");
    //This is for user access
    printf("\t\t\tWelcome to city database...\n");
    printf("!!!We can do different operations on city database by user interface...!!!\n");
    int wish=1;
    while(wish)
    {
        int index;
        printf("\nOperation on database....\n");
        printf("Index                       Operation Name\n");
        printf("1)                     Set capital of state\n");
        printf("2)                     Insert\n");
        printf("3)                     Serach by name\n");
        printf("4)                     Search by coordinate\n");
        printf("5)                     Print record within distance\n");
        printf("6)                     delete by name\n");
        printf("7)                     delete by coordinate\n");
        printf("Enter index for performing operation on database..::");
        scanf("%d",&index);
        switch (index)
        {
            int in_wish=1;
            case 1:
            {
                char a[20];
                int la,lo;
                printf("\nEnter name lagitude logitude (seperated with spaces)::");
                scanf("%s %d %d",a,&la,&lo);
                set_capital(&a,la,lo);
                break;
            }
            case 2:
            {
                in_wish=1;
                while(in_wish)
                {
                    char a[20];
                    int la,lo;
                    printf("\nEnter name lagitude logitude (seperated with spaces)::");
                    scanf("%s %d %d",a,&la,&lo);
                    insert(&a,la,lo);
                    printf("\nIf you want to continue this operation...(then enter 1 or enter 0)::");
                    scanf("%d",&in_wish);
                }
                break;
            }
            case 3:
            {
                in_wish=1;
                while(in_wish)
                {
                    char a[20];
                    printf("\nEnter name for search::");
                    scanf("%s",a);
                    search_by_name(&a);
                    printf("\nIf you want to continue this operation...(then enter 1 or enter 0)::");
                    scanf("%d",&in_wish);
                }
                break;
            }
            case 4:
            {
                in_wish=1;
                while(in_wish)
                {
                    int la,lo;
                    printf("\nEnter lagitude logitude (seperated with spaces)::");
                    scanf("%d %d",&la,&lo);
                    search_by_coordinate(la,lo);
                    printf("\nIf you want to continue this operation...(then enter 1 or enter 0)::");
                    scanf("%d",&in_wish);
                }
                break;
            }
            case 5:
            {
                in_wish=1;
                while(in_wish)
                {
                    int distance;
                    printf("\nEnter distance value within you want data of city..::");
                    scanf("%d",&distance);
                    print_record(distance);
                    printf("\nIf you want to continue this operation...(then enter 1 or enter 0)::");
                    scanf("%d",&in_wish);
                }
                break;
            }
            case 6:
            {
                in_wish=1;
                while(in_wish)
                {
                    char a[20];
                    printf("\nEnter name of city for deletion::");
                    scanf("%s",a);
                    delete_by_name(&a);
                    printf("\nIf you want to continue this operation...(then enter 1 or enter 0)::");
                    scanf("%d",&in_wish);
                }
                break;
            }
            case 7:
            {
                in_wish=1;
                while(in_wish)
                {
                    int la,lo;
                    printf("\nEnter lagitude logitude (seperated with spaces)::");
                    scanf("%d %d",&la,&lo);
                    delete_by_coordinate(la,lo);
                    printf("\nIf you want to continue this operation...(then enter 1 or enter 0)::");
                    scanf("%d",&in_wish);
                }
                break;
            }
            default:
            {
                printf("\nYou have entered wrong index...\n");
                break;
            }
        }
        printf("\nIf you want to continue with another operation...(then enter 1 or enter 0)::");
        scanf("%d",&wish);
    }
    return 0;
}
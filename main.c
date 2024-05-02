#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert_first(int a);
void insert_any_point(int a);
void insert_last(int a);
void delete_first(int a);
void delete_any_point(int a);
void delete_last(int a);
void update(int a);
void mainpage(int a);
void choose(int a);
void payment(int a);

struct node
{
    char name[10];
    int kg;
    int price;
    struct node *next;
};
struct customer
{
    char things[10];
    int kg;
    int pricekg;
    struct customer *next;
};
struct customer *first;
struct node *head;
char element[10];
int taka, totalkg;
int sum = 0;

void insert_first(int a)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("What's the item?\n");
    scanf("%s", element);
    printf("Price of per kg item? ");
    scanf("%d", &taka);
    printf("How much kg of this item do you want?");
    scanf("%d", &totalkg);
    newnode->kg = totalkg;
    strcpy(newnode->name, element);
    newnode->price = taka;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
    mainpage(1);
}
void insert_any_point(int a)
{
    struct node *newnode, *temp, *prev;
    newnode = (struct node *)malloc(sizeof(struct node));
    temp = head;
    int loc, p = 1;
    if (temp == NULL)
    {
        printf("store is empty\n");
    }
    else
    {
        printf("What's the item?\n");
        scanf("%s", element);
        printf("Price of per kg item? ");
        scanf("%d", &taka);
        strcpy(newnode->name, element);
        newnode->price = taka;
        newnode->next = NULL;
        printf("Location of new item?\n");
        scanf("%d", &loc);
        printf("How much kg of this item do you want?");
        scanf("%d", &totalkg);
        newnode->kg = totalkg;
        while (p != loc)
        {
            prev = temp;
            temp = temp->next;
            p++;
        }
        newnode->next = prev->next;
        prev->next = newnode;
    }
    mainpage(1);
}
void insert_last(int a)
{
    struct node *temp, *prev;
    temp = head;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("store is empty\n");
    }
    else
    {
        printf("What's the item?\n");
        scanf("%s", element);
        printf("Price of per kg item? ");
        scanf("%d", &taka);
        printf("How much kg of this item do you want?");
        scanf("%d", &totalkg);
        newnode->kg = totalkg;
        strcpy(newnode->name, element);
        newnode->price = taka;
        newnode->next = NULL;
        while (temp != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = newnode;
    }
    mainpage(1);
}
void delete_first(int a)
{
    if (head == NULL)
    {
        printf("Here no any item to delete\n");
    }
    else
    {
        head = head->next;
    }
    update(1);
    mainpage(1);
}
void delete_any_point(int a)
{
    struct node *newnode, *temp, *prev;
    temp = head;
    int loc, p = 1;
    printf("which location item do you want to delete?");
    scanf("%d", &loc);
    if (head == NULL)
    {
        printf("Here no any item to delete\n");
    }
    while (p != loc)
    {
        prev = temp;
        temp = temp->next;
        p++;
    }
    prev->next = temp->next;
    update(1);
    mainpage(1);
}
void delete_last(int a)
{
    struct node *temp, *prev, *temp1;
    temp1 = head;
    temp = NULL;
    if (head == NULL)
    {
        printf("Here no any item to delete\n");
    }
    while (temp1 != NULL)
    {
        prev = temp;
        temp = temp1;
        temp1 = temp1->next;
    }
    prev->next = NULL;
    update(1);
    mainpage(1);
}
void update(int a)
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%s per kg = ", temp->name);
        printf("%d taka || Total of this item = %d kg\n", temp->price, temp->kg);
        temp = temp->next;
    }
    mainpage(1);
}
void mainpage(int a)
{
    int choice, choice1;
    printf("1. Insert item\n2. Delete item\n3. Reserve item\n4. Update item\n5. Choose your product\n6.Payment\n7. Exit\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("1. Insert first place\n2. Insert item any point\n3. Insert last place\n");
        printf("Enter your choice : ");
        scanf("%d", &choice1);
        if (choice1 == 1)
            insert_first(1);
        else if (choice1 == 2)
            insert_any_point(1);
        else
            insert_last(1);
    }
    else if (choice == 2)
    {
        printf("1. Delete first item\n2. Delete item any point\n3. Delete last item\n");
        printf("Enter your choice : ");
        scanf("%d", &choice1);
        if (choice1 == 1)
            delete_first(1);
        else if (choice1 == 2)
            delete_any_point(1);
        else
            delete_last(1);
    }
    else if (choice == 3)
    {
        int i = 1;
        struct node *temp;
        temp = head;
        if (temp != NULL)
        {
            while (temp != NULL)
            {
                printf("%d. %s\n", i, temp->name);
                temp = temp->next;
                i++;
            }
        }
        else
        {
            printf("There is no item in the shop\n");
        }
        mainpage(1);
    }
    else if (choice == 4)
    {
        update(1);
    }
    else if (choice == 5)
    {
        choose(1);
    }
    else if (choice == 6)
    {
        payment(1);
    }
    else
    {
        printf("Thank you to our supershop\n");
    }
}
void choose(int a)
{
    int p, much;
    char string[10];
    printf("Item name : ");
    scanf("%s", string);
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        p = strcmp(temp->name, string);
        if (p == 0)
        {
            struct customer *newcustomer;
            newcustomer = (struct customer *)malloc(sizeof(struct customer));
            strcpy(newcustomer->things, string);
            printf("How much kg of this item do you need?\n");
            scanf("%d", &much);
            while (temp->kg < much && temp->kg != 0)
            {
                printf("You can take less than %d kg of this item\n", temp->kg);
                scanf("%d", &much);
            }
            if (temp->kg == 0)
            {
                printf("Item is finished \n");
                break;
            }
            temp->kg = temp->kg - much;
            newcustomer->kg = much;
            newcustomer->pricekg = temp->price;
            newcustomer->next = NULL;
            sum += much * temp->price;
            if (first == NULL)
            {
                first = newcustomer;
            }
            else
            {
                newcustomer->next = first;
                first = newcustomer;
            }
            break;
        }
        temp = temp->next;
    }
    if (p != 0)
    {
        printf("Item is not in the list\n");
    }
    mainpage(1);
}
void payment(int a)
{
    int pay;
    struct customer *temp;
    temp = first;
    while (temp != NULL)
    {
        printf("%s = %d kg * %d taka =%d\n", temp->things, temp->kg, temp->pricekg, temp->kg * temp->pricekg);
        temp = temp->next;
    }
    printf("__________________________________________\n");
    printf("Your total amount = %d taka\n", sum);
    printf("You pay = ");
    scanf("%d", &pay);
    if (sum - pay == 0)
    {
        printf("Fully payment successful\n");
        first = NULL;
        temp = NULL;
        sum = 0;
    }
    else
    {
        while ((sum - pay) != 0)
        {
            sum = sum - pay;
            printf("__________________________________________\n");
            printf("Your total amount = %d taka\n", sum);
            printf("You pay = ");
            scanf("%d", &pay);
        }
        sum = sum - pay;
        if (sum == 0)
        {
            printf("Fully payment successful\n");
            first = NULL;
            temp = NULL;
            sum = 0;
        }
    }
    mainpage(1);
}
int main()
{
    printf("---------------WELCOME TO OUR SUPERSHOP---------------\n");
    printf("What do you want????\n");
    mainpage(1);
    return 0;
}
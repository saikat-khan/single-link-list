#include<stdio.h>
struct node{
    int id;
    char gender;
    int score;
    struct node *next;
}*head;

void insertlast(int i,char g, int s)
{
    struct node *p,*t;
    p=head;
    t=(struct node*)malloc(sizeof(struct node));
    t->id=i;
    t->gender=g;
    t->score=s;
    t->next=NULL;
    if(head==NULL)
    {
        head=t;
    }
    else
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=t;
    }
}
void deletfirst()
{
    if(head==NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        head=head->next;
    }
}
void insertafter(int key, int i,char g, int s)
{
     struct node *p,*t;
    p=head;
    t=(struct node*)malloc(sizeof(struct node));
    t->id=i;
    t->gender=g;
    t->score=s;
    t->next=NULL;
    if(head==NULL)
    {
        printf("Not possible to insert \n");
    }
    else
    {
        while(p->score!=key)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}
void highest()
{
    int max=-1,in=0;
    struct node *p;
    p=head;
    while(p!=NULL)
    {
        if(p->score>max)
        {
            max=p->score;
            in=p->id;
        }
        p=p->next;
    }
    printf("%d got the highest score %d\n",in,max);

}
void average()
{
    int sum=0,c=0;
    struct node *p;
    p=head;
    while(p!=NULL)
    {
        c++;
        sum=sum+p->score;
        p=p->next;
    }
    printf("Average score of the list is %d\n",sum/c);
}
void print()
{
    struct node *p;
    p=head;
    while(p!=NULL)
    {
        printf("%d->%c->%d\n",p->id,p->gender,p->score);
        p=p->next;
    }
    printf("\n\n");
}
int main()
{
    head=NULL;
    insertlast(1,'M',70);
    insertlast(2,'F',85);
    insertlast(3,'M',95);
    insertlast(4,'M',62);
    insertlast(5,'F',82);
    insertlast(6,'F',75);
    print();
    insertafter(70,7,'M',88);
    print();
    deletfirst();
    print();
    highest();
    average();
    return 0;

}

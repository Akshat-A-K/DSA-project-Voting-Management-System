#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct Node
{
    int age;
    char name[100];
    char aadhar[20];
    char voter_id[100];
    char birth_date[100];
    struct Node *next;
	int booth_no;
} *head,*start=NULL,*tem=NULL;

void log_in();
void admin();
void show();
void stop();
void winner();

int vote1,vote2,vote3,vote4,vote5;

void not_again()
{
    int x;
    system("COLOR 04");
    printf("\n\n\n\n");
    printf("\t\t\t YOU HAVE GIVEN YOUR VOTE SUCCESSFULLY \n\n\n");
    printf("\t\t\t YOU CANNOT GIVE YOUR VOTE MORE THAN ONCE \n\n\n");
    printf("\t\t\t If You want to see present winner Enter One(1) or Enter Any Other Key for Main Logs\n\n");
    scanf("%d",&x);
    if(x==1)
    {
        winner();
    }
    else
    {
         system("cls");
        log_in(start);
    }
}

void voting()
{
    system("COLOR 8F");
    printf("\n\n");
    printf("\t\t * * * * * LIST OF CANDIDATES * * * * * \n\n\n");
    printf("\t\t\t NAME & THEIR RESPECTIVE SYMBOL\n\n");
    printf("\t\t\t 1. NARENDRA MODI 		1. LOTUS\n");
    printf("\t\t\t 2. ARVIND KEJRIWAL 		2. BROOM\n");
    printf("\t\t\t 3. RAHUL GANDHI 		3. PALM\n");
    printf("\t\t\t 4. MAMTA BANERJEE 		4. JORA GHAS PHUL\n");
    printf("\t\t\t 5. UDDHAV THACKERAY 	5. BOW AND ARROW\n\n\n");
    int b,j;
    printf("\t\t\t Enter Your Choice \n");
    for(j=1; j<=1; j++)
    {
        scanf("%d",&b);
        if(b==1)
        {
            vote1++;
            printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO NARENDRA MODI\n");
            break;
        }
        if(b==2)
        {
            vote2++;
            printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO ARVIND KEJRIWAL\n");
            break;
        }
        if(b==3)
        {
            vote3++;
            printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO RAHUL GANDHI\n");
            break;
        }
        if(b==4)
        {
            vote4++;
            printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO MAMTA BANERJEE\n");
            break;
        }
        if(b==5)
        {
            vote5++;
            printf("\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO KARTIK UDDHAV THACKERAY\n");
            break;
        }
        if(b!=1||b!=2||b!=3||b!=4||b!=5)
        {
            printf("\n\t\t************* INVALID CHOICE ENTERED**************\t\t\n");
            printf("\n\t\t\tENTER AGAIN\t\t\t\n");
            j--;
        }
    }
    printf("\n\n***********************THANK YOU************************\n\n");
    printf("press any key");
    getch();
}

struct Node *voter_insert(struct Node *start)
{
    int UNIVERSAL=0;
    int *z,R;
    z = &UNIVERSAL;
    struct Node *temp,*t=head;
    int a;
    char name[50],birth_date[15],aadhar[20],v_id[50];
    system("cls");
    system("COLOR 95");
    printf("\n\n\n\n");
    printf("\t IF AADHAR ID, YOUR NAME AND YOUR DATE OF BIRTH MATCHES THEN YOU CAN GIVE YOUR VOTE OTHERWISE NOT\n\n");
    printf("\t\t\t ID YOU DO WRONG %d TIMES, THE PORTAL WILL BE CLOSED AUTOMATICALLY\n\n\n",R);
    printf("\t\tPlease \n");
    printf("\t\t\tEnter your AADHAR ID number: ");
    gets(aadhar);
    gets(aadhar);
    int rr=0;
    while(t!=NULL)
    {
        if(strcmp(t->aadhar,aadhar)==0)
        {
            rr++;
            break;
        }
        t=t->next;
    }
    if(rr)
    {
        not_again();
    }
    else
    {
        printf("\t\t\tEnter your AGE:");
        scanf("%d",&a);
        if(a<18) {
            printf("You are note eligible for voting....\n");
            return NULL;
        }
        printf("\t\t\tEnter Your NAME: ");
        gets(name);
        gets(name);
        printf("\t\t\tEnter Your BIRTH DATE in dd-mm-yyyy format:");
        gets(birth_date);
        printf("\t\t\tEnter Your VOTER-ID:");
        gets(v_id);
        temp=(struct Node *)malloc(sizeof(struct Node));
        strcpy(temp->aadhar,aadhar);
        strcpy(temp->name,name);
        temp->age=a;
        strcpy(temp->birth_date,birth_date);
        strcpy(temp->voter_id,v_id);
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tem=temp;

        }
        else
        {
            tem->next=temp;
            tem=temp;
        }
        voting();
    }
}

void log_in(struct Node *start)
{  system("cls");
    system("COLOR E7");
    printf("\n\n\nFOR ENTRY OF VOTE\n");
    printf("\t1. VOTING PORTAL\n");
    printf("\t2. GO TO ADMIN PORTAL:\n");
    printf("\t3. FOR WINNER\n");
    printf(" \t ****So Please Enter****\n\n\n");
    int t;
    scanf("%d",&t);
    if(t==1)
    {
        start=voter_insert(start);
    }
    if(t==2)
    {
        admin();
    }
    if(t==3)
    {
        winner();
    }
    if(t!=1||t!=2||t!=3)
    {
        log_in(start);
    }
}

void admin()
{
    system("cls");
    system("COLOR 8F");
    printf("\nENTER PASSWORD TO GO TO THE ADMIN PORTAL:");
    int pass;
    scanf("%d",&pass);
    if(pass=1234) show();
    else
    {
        printf("YOU ENTERED WRONG PASSWORD");
        log_in(start);
    }
}

void show()
{
    int x;
    system("cls");
    printf("\n\n\n");
    system("COLOR A5");
    printf("\t\tPresent Vote Count :\n\n");
    printf("\t\t Narendra Modi is on %d Votes\n",vote1);
    printf("\t\t Arvind Kejriwal is on %d Votes\n",vote2);
    printf("\t\t Rahul Gandhi is on %d Votes\n",vote3);
    printf("\t\t Mamta Banerjee is on %d Votes\n",vote4);
    printf("\t\t Uddhav Thackeray is on %d Votes\n\n\n",vote5);
    printf("\t\t\tEnter Any Key For Main PORTAL\t\t\n\t\t\t\tOR\n\t\t\tENTER THE SPECIAL PASSWORD TO CLOSING ELECTIONS\n\t\t");
    scanf("%d",&x);
    if(x==5678) {
        winner();
		exit(0);
    }
    else
        log_in(start);
}

int max_vote(int v1,int v2,int v3,int v4,int v5) {
    int v[5]= {v1,v2,v3,v4,v5};
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            if(v[i]<v[j]) {
                int t=v[j];
                v[j]=v[i];
                v[i]=t;
            }
        }
    }
    return v[4];
}

void winner()
{
    printf("\n\n");
    system("COLOR DF");
    int m=max_vote(vote1,vote2,vote3,vote4,vote5);
    if(m==vote1)
        printf("\t\t\tThe Winner is Narendra Modi and he has got %d votes\n\n\n",vote1);
    if(m==vote2)
        printf("\t\t\tThe Winner is Arvind Kejriwal and he has got %d votes\n\n\n",vote2);
    if(m==vote3)
        printf("\t\t\tThe Winner is Rahul Gandhi and he has got %d votes\n\n\n",vote3);
    if(m==vote4)
        printf("\t\t\tThe Winner is Mamta Banerjee and she has got %d votes\n\n\n",vote4);
    if(m==vote5)
        printf("\t\t\tThe Winner is Uddhav Thackeray and he has got %d votes\n\n\n",vote5);
	exit(0);
}

int main()
{   system("COLOR E5");
    printf("\n\n\t\t\t=====================================================\n");
    printf("\n\n\t\t\t==============WELCOME TO ELECTION BOOTH==============\n");
    printf("\n\n\t\t\t=====================================================\n");

    printf("\n\n\t\t\t====Please enter 1 for logging in to the portal====\n\n");

     while(1)
    {
        int x;
        scanf("%d",&x);
        if(x==1) log_in(start);
    }
    return 0;
}

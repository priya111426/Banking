#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct Admin{
	char name_admin[20],email_admin[20],pass_admin[20];
};
struct Customer{
	char name_cust[20],email_cust[20],pass_cust[20];
	char city_cust[20],state_cust[20];
	int age_cust,house_cust,pin_cust,street_cust,balance,Account_no;
	int atm_pin;
};
struct Employee{
	char name_emp[20],email_emp[20],pass_emp[20];
	char city_emp[20],state_emp[20];
	int age_emp,house_emp,pin_emp,street_emp,emp_id;
};
struct Bank{
	struct Admin ad;
	struct Employee emp;
	struct Customer cust;
};
struct Bank b;
void admin_login();
void employee_login();
void customer_login();
void display_emp();
void add_emp();
void delete_emp();
void search_emp();
void edit_emp();
void display_cust();
void add_cust();
void delete_cust();
void search_cust();
void edit_cust();
void display_emp_own();
int print_total();
void display_cust_own();
void widraw();
void deposit();
void atm_service();
void admin_details();
void search_emp_name();
void search_emp_age();
void search_emp_id();
void search_emp_email();
void search_emp_city();
void search_emp_state();
void search_cust_name();
void search_cust_age();
void search_cust_acc();
void search_cust_email();
void search_cust_city();
void search_cust_state();
void main()
{
	int ch,f,i;
	FILE *p;
	char str[20];
	char ps[20];
	admin_details();
	while(1)
	{
		printf("\n");
		system("pause");
		system("cls");
		printf("\n---->>> BANK MENU <<<------");
		printf("\n___________________________");
		printf("\nPress 1 to Admin login");
		printf("\nPress 2 to Employee Login");
		printf("\nPress 3 to Customer Login");
		printf("\nPress 4 to ATM service");
		printf("\nPress 5 to exit");
		printf("\n___________________________");
		printf("\nenter your choice   ");
		scanf("%d",&ch);
		printf("\n___________________________\n");
		switch(ch)
		{
			case 1:
				i=0;
				printf("enter admin mail id    ");
				fflush(stdin);
				gets(str);
				printf("enter the password\n");
				while(1)
				{
					ch=getch();
					if(ch==13)
					break;
					ps[i]=ch;
					printf("*");
					i++;
				}
				ps[i]='\0';
				if((strcmp(str,b.ad.email_admin)==0)&&strcmp(ps,b.ad.pass_admin)==0)
				admin_login();
				else
				printf("Invalid email id or password");
				break;
			case 2:
				f=0;
				i=0;
				p=fopen("Employee_login.txt","rb+");
				printf("enter employee mail id    ");
				fflush(stdin);
				gets(str);
				printf("enter the password\n");
				while(1)
				{
					ch=getch();
					if(ch==13)
					break;
					ps[i]=ch;
					printf("*");
					i++;
				}
				ps[i]='\0';
				rewind(p);
				while(fread(&b.emp,sizeof(b.emp),1,p)==1)
				{
					if((strcmp(str,b.emp.email_emp)==0)&&strcmp(ps,b.emp.pass_emp)==0)
					{
						f=1;
						fclose(p);
						employee_login();
					}
				}
				if(f==0)
				printf("Invalid Email Id or Password");
				break;
			case 3:
				f=0;
				i=0;
				p=fopen("Customer_login.txt","rb+");
				printf("enter customer mail id  ");
				fflush(stdin);
				gets(str);
				printf("enter the password\n");
				while(1)
				{
					ch=getch();
					if(ch==13)
					break;
					ps[i]=ch;
					printf("*");
					i++;
				}
				ps[i]='\0';
				rewind(p);
				while(fread(&b.cust,sizeof(b.cust),1,p)==1)
				{
				if((strcmp(str,b.cust.email_cust)==0)&&strcmp(ps,b.cust.pass_cust)==0)
				{
					customer_login();
					f=1;
				}
				}
				if(f==0)
				printf("Invalid Account number or Password");
				fclose(p);
				break;
			case 4:
				atm_service();
				break;
			case 5:
				exit(1);
			default:
				printf("Invalid choice\n");
		}
	}
}
void admin_details()
{
	strcpy(b.ad.name_admin,"Nitin chauhan");
    strcpy(b.ad.email_admin,"nitin@gmail.com");
    strcpy(b.ad.pass_admin,"nitin123");
}
void admin_login()
{
	int ch;
	while(1)
	{
		printf("\n");
		system("pause");
		system("cls");
		printf("\nWelcome MR. %s",b.ad.name_admin);
		printf("\n-------->>> Admin MENU <<<----------");
		printf("\n____________________________________");
		printf("\nPress 1 to add Employee details");
		printf("\nPress 2 to display Employee details");
		printf("\nPress 3 to delete Employee details");
		printf("\nPress 4 to edit Employee details");
		printf("\nPress 5 to search Employee details");
		printf("\nPress 6 to LOG OUT");
		printf("\n____________________________________");
		printf("\nenter your choice");
		printf("\n____________________________________");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				add_emp();
				break;
			case 2:
				display_emp();
				break;
			case 3:
				delete_emp();
				break;
			case 4:
				edit_emp();
				break;
			case 5:
				search_emp();
				break;
			case 6:
				break;
			default:
				printf("Invalid choice");
		}
		if(ch==6)
		break;
	}
}
void add_emp()
{
	FILE *p;
	int num,f;
	p=fopen("Employee_login.txt","rb+");
	if(p==NULL)
	p=fopen("Employee_login.txt","wb+");
	while(1)
	{
		f=0;
		rewind(p);
		printf("enter the employee id  ");
		scanf("%d",&num);
		while(fread(&b.emp,sizeof(b.emp),1,p)==1)
		{
			if(num==b.emp.emp_id)
			{
				f=1;
				break;
			}
		}
		if(f==1)
		printf("Employee id Already exist\n");
		else
		break;
	}
	b.emp.emp_id=num;
	printf("enter the employee name ");
	fflush(stdin);
	gets(b.emp.name_emp);
	printf("enter the age ");
	scanf("%d",&b.emp.age_emp);
	printf("enter the employee mail id and password ");
	fflush(stdin);
	gets(b.emp.email_emp);
	gets(b.emp.pass_emp);
	printf("enter the house number, street number and pin number ");
	scanf("%d",&b.emp.house_emp);
	scanf("%d",&b.emp.street_emp);
	scanf("%d",&b.emp.pin_emp);
	printf("enter the city name and state ");
	fflush(stdin);
	gets(b.emp.city_emp);
	gets(b.emp.state_emp);
	fseek(p,0,SEEK_END);
	fwrite(&b.emp,sizeof(b.emp),1,p);
	fclose(p);
}
void display_emp()
{
	FILE *p;
	int c=0;
	p=fopen("Employee_login.txt","rb+");
	if(p==NULL)
	printf("No Employee details exist");
	else
	{
		printf("Employee details");
		printf("\n______________________________________________________");
		while(fread(&b.emp,sizeof(b.emp),1,p)==1)
		{
			c++;
		}
		if(c==0)
		printf("No Information is Available to display");
		else
		{
		rewind(p);
		printf("\nName\tID\tEMAIL\t\tAGE\tCITY\tState");
		printf("\n______________________________________________________");
		while(fread(&b.emp,sizeof(b.emp),1,p)==1)
		{
			printf("\n%s\t%d\t%s\t%d\t%s\t%s",b.emp.name_emp,b.emp.emp_id,b.emp.email_emp,b.emp.age_emp,b.emp.city_emp,b.emp.state_emp);
		}
		printf("\n_______________________________________________________");
		printf("\nTotal %d results found",c);
	    }
	}
	fclose(p);
}
void delete_emp()
{
	FILE *p,*q;
	int num,f;
	p=fopen("Employee_login.txt","rb+");
	if(p==NULL)
	printf("No information is available");
	else
	{
		q=fopen("temp.txt","wb+");
		printf("enter the employee id to delete ");
		scanf("%d",&num);
		while(fread(&b.emp,sizeof(b.emp),1,p)==1)
		{
		    if(num==b.emp.emp_id)
		    {
		    	f=1;
		    	break;
			}
		}
		if(f==0)
		printf("No Such Employee exist");
		else
		{
			rewind(p);
			while(fread(&b.emp,sizeof(b.emp),1,p)==1)
			{
		    	if(num!=b.emp.emp_id)
		    	{
		    		fseek(q,0,SEEK_END);
		    		fwrite(&b.emp,sizeof(b.emp),1,q);	
				}
			}
			fclose(p);
			fclose(q);
			remove("Employee_login.txt");
			rename("temp.txt","Employee_login.txt");
		}
		fclose(p);
		fclose(q);
	}
}
void edit_emp()
{
	FILE *p;
	int ch,f,num,s=sizeof(b.emp);
	p=fopen("Employee_login.txt","rb+");
	if(p==NULL)
	printf("Sorry No Information is Available to Edit");
	else
	{
		printf("\nenter the employee id to edit details ");
		scanf("%d",&num);
		while(fread(&b.emp,sizeof(b.emp),1,p)==1)
		{
			f=0;
		    if(num==b.emp.emp_id)
		    {
		    	f=1;
		    	fseek(p,-s,SEEK_CUR);
			    printf("\nPress 1 to edit Name");
				printf("\nPress 2 to edit Age");
				printf("\nPress 3 to edit Email Id");
				printf("\nPress 4 to edit pass Word");
				printf("\n_________________________\n");
				printf("enter your choice   ");
				scanf("%d",&ch);
				printf("\n_________________________\n");
				switch(ch)
				{
				case 1:
					printf("enter the new name of the employee ");
					fflush(stdin);
					gets(b.emp.name_emp);
					break;
				case 2:
					printf("enter the age of the employee ");
					scanf("%d",&b.emp.age_emp);
					break;
				case 3:
					printf("enter the new Employee email id   ");
					fflush(stdin);
					gets(b.emp.email_emp);
					break;
				case 4:
					printf("enter the new password   ");
					fflush(stdin);
					gets(b.emp.pass_emp);
					break;
				default:
					printf("Invalid choice");
				}
                fwrite(&b.emp,sizeof(b.emp),1,p);
                fclose(p);
                break;
		    }
		}
		if(f==0)
		printf("No Such Employee exist");
	}
}
void search_emp()
{
	FILE *p;
	char ch;
	p=fopen("Employee_login.txt","rb+");
	if(p==NULL)
	printf("Sorry No Information is Available to Search");
	else
	{
		fclose(p);
		printf("\nEmployee search Menu");
		printf("\n_________________________");
	 	printf("\nPress 1 to search by Name");
		printf("\nPress 2 to search by Age");
		printf("\nPress 3 to search by Id");
        printf("\nPress 4 to search by Email id");
		printf("\nPress 5 to search by City");
		printf("\nPress 6 to search by state");
		printf("\n_________________________\n");
		printf("enter your choice   ");
		scanf("%d",&ch);
		printf("\n_________________________\n");
		switch(ch)
		{
			case 1:
				search_emp_name();
				break;
			case 2:
				search_emp_age();
				break;
			case 3:
				search_emp_id();
				break;
			case 4:
				search_emp_email();
				break;
			case 5:
				search_emp_city();
				break;
			case 6:
				search_emp_state();
				break;
			default:
				printf("Invalid choice");
		}
	}
}
void search_emp_name()
{
	FILE *p;
	char str[20];
	int f=0;
	p=fopen("Employee_login.txt","rb+");
	printf("enter the employee name to search ");
	fflush(stdin);
	gets(str);
	while(fread(&b.emp,sizeof(b.emp),1,p)==1)
	{
		if(strcmp(b.emp.name_emp,str)==0)
		{
			f=1;
		}
	}
	if(f==0)
	printf("No Such Employee exist ");
	else
	{
		rewind(p);
		system("cls");
		printf("Employee details:");
		printf("\nName\tID\tEMAIL\t\tAGE\tCITY\tState");
		while(fread(&b.emp,sizeof(b.emp),1,p)==1)
		{
			if(strcmp(b.emp.name_emp,str)==0)
			{
			printf("\n%s\t%d\t%s\t%d\t%s\t%s",b.emp.name_emp,b.emp.emp_id,b.emp.email_emp,b.emp.age_emp,b.emp.city_emp,b.emp.state_emp);
			}
		}
	}
    fclose(p);
}
void search_emp_age()
{
	FILE *p;
	int num;
	int f=0;
	p=fopen("Employee_login.txt","rb+");
	printf("enter the employee age to search ");
	scanf("%d",&num);
	while(fread(&b.emp,sizeof(b.emp),1,p)==1)
	{
		if(b.emp.age_emp==num)
		{
			f=1;
		}
	}
	if(f==0)
	printf("No Such Employee exist ");
	else
	{
		rewind(p);
		system("cls");
		printf("Employee details:");
		printf("\nName\tID\tEMAIL\t\tAGE\tCITY\tState");
		while(fread(&b.emp,sizeof(b.emp),1,p)==1)
		{
			if(b.emp.age_emp==num)
			{
			printf("\n%s\t%d\t%s\t%d\t%s\t%s",b.emp.name_emp,b.emp.emp_id,b.emp.email_emp,b.emp.age_emp,b.emp.city_emp,b.emp.state_emp);
			}
		}
	}
    fclose(p);
}
void search_emp_id()
{
	FILE *p;
	int num;
	int f=0;
	p=fopen("Employee_login.txt","rb+");
	printf("enter the employee id to search ");
	scanf("%d",&num);
	while(fread(&b.emp,sizeof(b.emp),1,p)==1)
	{
		if(b.emp.emp_id==num)
		{
			f=1;
		}
	}
	if(f==0)
	printf("No Such Employee exist ");
	else
	{
		rewind(p);
		system("cls");
		printf("Employee details:");
		printf("\nName\tID\tEMAIL\t\tAGE\tCITY\tState");
		while(fread(&b.emp,sizeof(b.emp),1,p)==1)
		{
			if(b.emp.emp_id==num)
			{
			printf("\n%s\t%d\t%s\t%d\t%s\t%s",b.emp.name_emp,b.emp.emp_id,b.emp.email_emp,b.emp.age_emp,b.emp.city_emp,b.emp.state_emp);
			}
		}
	}
    fclose(p);
}
void search_emp_email()
{
	FILE *p;
	char str[20];
	int f=0;
	p=fopen("Employee_login.txt","rb+");
	printf("enter the employee email id to search ");
	fflush(stdin);
	gets(str);
	while(fread(&b.emp,sizeof(b.emp),1,p)==1)
	{
		if(strcmp(b.emp.email_emp,str)==0)
		{
			f=1;
		}
	}
	if(f==0)
	printf("No Such Employee exist ");
	else
	{
		rewind(p);
		system("cls");
		printf("Employee details:");
		printf("\nName\tID\tEMAIL\t\tAGE\tCITY\tState");
		while(fread(&b.emp,sizeof(b.emp),1,p)==1)
		{
			if(strcmp(b.emp.email_emp,str)==0)
			{
			printf("\n%s\t%d\t%s\t%d\t%s\t%s",b.emp.name_emp,b.emp.emp_id,b.emp.email_emp,b.emp.age_emp,b.emp.city_emp,b.emp.state_emp);
			}
		}
	}
    fclose(p);
}
void search_emp_city()
{
	FILE *p;
	char str[20];
	int f=0;
	p=fopen("Employee_login.txt","rb+");
	printf("enter the employee city name to search ");
	fflush(stdin);
	gets(str);
	while(fread(&b.emp,sizeof(b.emp),1,p)==1)
	{
		if(strcmp(b.emp.city_emp,str)==0)
		{
			f=1;
		}
	}
	if(f==0)
	printf("No Such Employee exist ");
	else
	{
		rewind(p);
		system("cls");
		printf("Employee details:");
		printf("\nName\tID\tEMAIL\t\tAGE\tCITY\tState");
		while(fread(&b.emp,sizeof(b.emp),1,p)==1)
		{
			if(strcmp(b.emp.city_emp,str)==0)
			{
			printf("\n%s\t%d\t%s\t%d\t%s\t%s",b.emp.name_emp,b.emp.emp_id,b.emp.email_emp,b.emp.age_emp,b.emp.city_emp,b.emp.state_emp);
			}
		}
	}
    fclose(p);
}
void search_emp_state()
{
	FILE *p;
	char str[20];
	int f=0;
	p=fopen("Employee_login.txt","rb+");
	printf("enter the employee state name to search ");
	fflush(stdin);
	gets(str);
	while(fread(&b.emp,sizeof(b.emp),1,p)==1)
	{
		if(strcmp(b.emp.state_emp,str)==0)
		{
			f=1;
		}
	}
	if(f==0)
	printf("No Such Employee exist ");
	else
	{
		rewind(p);
		system("cls");
		printf("Employee details:");
		printf("\nName\tID\tEMAIL\t\tAGE\tCITY\tState");
		while(fread(&b.emp,sizeof(b.emp),1,p)==1)
		{
			if(strcmp(b.emp.state_emp,str)==0)
			{
			printf("\n%s\t%d\t%s\t%d\t%s\t%s",b.emp.name_emp,b.emp.emp_id,b.emp.email_emp,b.emp.age_emp,b.emp.city_emp,b.emp.state_emp);
			}
		}
	}
    fclose(p);
}
void employee_login()
{
	int ch;
	while(1)
	{
		printf("\n");
		system("pause");
		system("cls");
		printf("\nWelcome MR. %s",b.emp.name_emp);
		printf("\n-------->>> Employee MENU <<<----------");
		printf("\n____________________________________");
		printf("\nPress 1 to add Customer details");
		printf("\nPress 2 to display Customer details");
		printf("\nPress 3 to delete Customer details");
		printf("\nPress 4 to edit Customer details");
		printf("\nPress 5 to search Customer details");
		printf("\nPress 6 to Print Total Bank Balance");
		printf("\nPress 7 to LOG OUT");
		printf("\n____________________________________");
		printf("\nenter your choice");
		printf("\n____________________________________");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				add_cust();
				break;
			case 2:
				display_cust();
				break;
			case 3:
				delete_cust();
				break;
			case 4:
				edit_cust();
				break;
			case 5:	
			    search_cust();
				break;
			case 6:
				printf("Total Balance = %d",print_total());
				break;
			case 7:
				break;
			default:
				printf("Invalid choice");
		}
		if(ch==7)
		break;
	}
}
void add_cust()
{
	FILE *p;
	int num,f;
	p=fopen("Customer_login.txt","rb+");
	if(p==NULL)
	p=fopen("Customer_login.txt","wb+");
	while(1)
	{
		f=0;
		rewind(p);
		printf("enter the Account number of customer  ");
		scanf("%d",&num);
		while(fread(&b.cust,sizeof(b.cust),1,p)==1)
		{
			if(num==b.cust.Account_no)
			{
				f=1;
				break;
			}
		}
		if(f==1)
		printf("Account number is Alreadt exist\n");
		else
		break;
	}
	b.cust.Account_no=num;
	printf("enter the customer name ");
	fflush(stdin);
	gets(b.cust.name_cust);
	printf("enter the age ");
	scanf("%d",&b.cust.age_cust);
	printf("enter the customer mail id and password ");
	fflush(stdin);
	gets(b.cust.email_cust);
	gets(b.cust.pass_cust);
	printf("enter the house number, street number and pin number ");
	scanf("%d",&b.cust.house_cust);
	scanf("%d",&b.cust.street_cust);
	scanf("%d",&b.cust.pin_cust);
	printf("enter the city name state ");
	fflush(stdin);
	gets(b.cust.city_cust);
	gets(b.cust.state_cust);
	printf("enter the opening amount ");
	scanf("%d",&b.cust.balance);
	printf("enter the pin number for ATM service ");
	scanf("%d",&b.cust.atm_pin);
	fseek(p,0,SEEK_END);
	fwrite(&b.cust,sizeof(b.cust),1,p);
	fclose(p);
}
void display_cust()
{
	FILE *p;
	int c=0;
	p=fopen("customer_login.txt","rb+");
	if(p==NULL)
	printf("No customer details exist");
	else
	{
		while(fread(&b.cust,sizeof(b.cust),1,p)==1)
		{
			c++;
		}
		if(c==0)
		printf("No Information is Available to display");
		else
		{
		rewind(p);
		printf("customer details");
		printf("\n______________________________________________________");
		printf("\nName\tAccount\tBalance\tEMAIL\t\tAGE\tCITY\tState");
		printf("\n______________________________________________________");
		while(fread(&b.cust,sizeof(b.cust),1,p)==1)
		{
			printf("\n%s\t%d\t%d\t%s\t%d\t%s\t%s",b.cust.name_cust,b.cust.Account_no,b.cust.balance,b.cust.email_cust,b.cust.age_cust,b.cust.city_cust,b.cust.state_cust);
		}
		printf("\n_______________________________________________________");
		printf("\nTotal %d results found",c);
	    }
	}
	fclose(p);
}
void delete_cust()
{
	FILE *p,*q;
	int num,f;
	p=fopen("Customer_login.txt","rb+");
	if(p==NULL)
	printf("No information is available");
	else
	{
		q=fopen("temp.txt","wb+");
		printf("enter the Account number to delete ");
		scanf("%d",&num);
		while(fread(&b.cust,sizeof(b.cust),1,p)==1)
		{
		    if(num==b.cust.Account_no)
		    {
		    	f=1;
		    	break;
			}
		}
		if(f==0)
		printf("No Such customer exist");
		else
		{
			rewind(p);
			while(fread(&b.cust,sizeof(b.cust),1,p)==1)
			{
		    	if(num!=b.cust.Account_no)
		    	{
		    		fseek(q,0,SEEK_END);
		    		fwrite(&b.cust,sizeof(b.cust),1,q);	
				}
			}
			fclose(p);
			fclose(q);
			remove("Customer_login.txt");
			rename("temp.txt","Customer_login.txt");
		}
		fclose(p);
		fclose(q);
	}
}
void edit_cust()
{
	FILE *p;
	int ch,f,num,s=sizeof(b.cust);
	p=fopen("Customer_login.txt","rb+");
	if(p==NULL)
	printf("Sorry No Information is Available to Edit");
	else
	{
		printf("\nenter the Account number to edit details ");
		scanf("%d",&num);
		while(fread(&b.cust,sizeof(b.cust),1,p)==1)
		{
			f=0;
		    if(num==b.cust.Account_no)
		    {
		    	f=1;
		    	fseek(p,-s,SEEK_CUR);
			    printf("\nPress 1 to edit Name");
				printf("\nPress 2 to edit Age");
				printf("\nPress 3 to edit Email Id");
				printf("\nPress 4 to edit pass Word");
				printf("\n_________________________\n");
				printf("enter your choice   ");
				scanf("%d",&ch);
				printf("\n_________________________\n");
				switch(ch)
				{
				case 1:
					printf("enter the new name of the custloyee ");
					fflush(stdin);
					gets(b.cust.name_cust);
					break;
				case 2:
					printf("enter the age of the custloyee ");
					scanf("%d",&b.cust.age_cust);
					break;
				case 3:
					printf("enter the new custloyee email id   ");
					fflush(stdin);
					gets(b.cust.email_cust);
					break;
				case 4:
					printf("enter the new password   ");
					fflush(stdin);
					gets(b.cust.pass_cust);
					break;
				default:
					printf("Invalid choice");
				}
                fwrite(&b.cust,sizeof(b.cust),1,p);
                fclose(p);
                break;
		    }
		}
		if(f==0)
		printf("No Such Customer exist");
	}
}
void search_cust()
{
	FILE *p;
	char ch;
	p=fopen("Customer_login.txt","rb+");
	if(p==NULL)
	printf("Sorry No Information is Available to Search");
	else
	{
		fclose(p);
		printf("\nCustomer search Menu");
		printf("\n_________________________");
	 	printf("\nPress 1 to search by Name");
		printf("\nPress 2 to search by Age");
		printf("\nPress 3 to search by Account number");
        printf("\nPress 4 to search by Email id");
		printf("\nPress 5 to search by City");
		printf("\nPress 6 to search by state");
		printf("\n_________________________\n");
		printf("enter your choice   ");
		scanf("%d",&ch);
		printf("\n_________________________\n");
		switch(ch)
		{
			case 1:
				search_cust_name();
				break;
			case 2:
				search_cust_age();
				break;
			case 3:
				search_cust_acc();
				break;
			case 4:
				search_cust_email();
				break;
			case 5:
				search_cust_city();
				break;
			case 6:
				search_cust_state();
				break;
			default:
				printf("Invalid choice");
		}
	}
}
void search_cust_name()
{
	FILE *p;
	char str[20];
	int f=0;
	p=fopen("Customer_login.txt","rb+");
	printf("enter the Customer name to search ");
	fflush(stdin);
	gets(str);
	while(fread(&b.cust,sizeof(b.cust),1,p)==1)
	{
		if(strcmp(b.cust.name_cust,str)==0)
		{
			f=1;
		}
	}
	if(f==0)
	printf("No Such Customer exist ");
	else
	{
		rewind(p);
		system("cls");
		printf("Customer details:");
		printf("\nName\tAccount\tEMAIL\t\tAGE\tCITY\tState");
		while(fread(&b.cust,sizeof(b.cust),1,p)==1)
		{
			if(strcmp(b.cust.name_cust,str)==0)
			{
			printf("\n%s\t%d\t%s\t%d\t%s\t%s",b.cust.name_cust,b.cust.Account_no,b.cust.email_cust,b.cust.age_cust,b.cust.city_cust,b.cust.state_cust);
			}
		}
	}
    fclose(p);
}
void search_cust_age()
{
	FILE *p;
	int num;
	int f=0;
	p=fopen("Customer_login.txt","rb+");
	printf("enter the Customer age to search ");
	scanf("%d",&num);
	while(fread(&b.cust,sizeof(b.cust),1,p)==1)
	{
		if(b.cust.age_cust==num)
		{
			f=1;
		}
	}
	if(f==0)
	printf("No Such Customer exist ");
	else
	{
		rewind(p);
		system("cls");
		printf("Customer details:");
		printf("\nName\tAccount\tEMAIL\t\tAGE\tCITY\tState");
		while(fread(&b.cust,sizeof(b.cust),1,p)==1)
		{
			if(b.cust.age_cust==num)
			{
			printf("\n%s\t%d\t%s\t%d\t%s\t%s",b.cust.name_cust,b.cust.Account_no,b.cust.email_cust,b.cust.age_cust,b.cust.city_cust,b.cust.state_cust);
			}
		}
	}
    fclose(p);
}
void search_cust_acc()
{
	FILE *p;
	int num;
	int f=0;
	p=fopen("Customer_login.txt","rb+");
	printf("enter the Customer id to search ");
	scanf("%d",&num);
	while(fread(&b.cust,sizeof(b.cust),1,p)==1)
	{
		if(b.cust.Account_no==num)
		{
			f=1;
		}
	}
	if(f==0)
	printf("No Such Customer exist ");
	else
	{
		rewind(p);
		system("cls");
		printf("Customer details:");
		printf("\nName\tAccount\tEMAIL\t\tAGE\tCITY\tState");
		while(fread(&b.cust,sizeof(b.cust),1,p)==1)
		{
			if(b.cust.Account_no==num)
			{
			printf("\n%s\t%d\t%s\t%d\t%s\t%s",b.cust.name_cust,b.cust.Account_no,b.cust.email_cust,b.cust.age_cust,b.cust.city_cust,b.cust.state_cust);
			}
		}
	}
    fclose(p);
}
void search_cust_email()
{
	FILE *p;
	char str[20];
	int f=0;
	p=fopen("Customer_login.txt","rb+");
	printf("enter the Customer email id to search ");
	fflush(stdin);
	gets(str);
	while(fread(&b.cust,sizeof(b.cust),1,p)==1)
	{
		if(strcmp(b.cust.email_cust,str)==0)
		{
			f=1;
		}
	}
	if(f==0)
	printf("No Such Customer exist ");
	else
	{
		rewind(p);
		system("cls");
		printf("custloyee details:");
		printf("\nName\tAccount\tEMAIL\t\tAGE\tCITY\tState");
		while(fread(&b.cust,sizeof(b.cust),1,p)==1)
		{
			if(strcmp(b.cust.email_cust,str)==0)
			{
			printf("\n%s\t%d\t%s\t%d\t%s\t%s",b.cust.name_cust,b.cust.Account_no,b.cust.email_cust,b.cust.age_cust,b.cust.city_cust,b.cust.state_cust);
			}
		}
	}
    fclose(p);
}
void search_cust_city()
{
	FILE *p;
	char str[20];
	int f=0;
	p=fopen("Customer_login.txt","rb+");
	printf("enter the Customer city name to search ");
	fflush(stdin);
	gets(str);
	while(fread(&b.cust,sizeof(b.cust),1,p)==1)
	{
		if(strcmp(b.cust.city_cust,str)==0)
		{
			f=1;
		}
	}
	if(f==0)
	printf("No Such Customer exist ");
	else
	{
		rewind(p);
		system("cls");
		printf("Customer details:");
		printf("\nName\tAccount\tEMAIL\t\tAGE\tCITY\tState");
		while(fread(&b.cust,sizeof(b.cust),1,p)==1)
		{
			if(strcmp(b.cust.city_cust,str)==0)
			{
			printf("\n%s\t%d\t%s\t%d\t%s\t%s",b.cust.name_cust,b.cust.Account_no,b.cust.email_cust,b.cust.age_cust,b.cust.city_cust,b.cust.state_cust);
			}
		}
	}
    fclose(p);
}
void search_cust_state()
{
	FILE *p;
	char str[20];
	int f=0;
	p=fopen("Customer_login.txt","rb+");
	printf("enter the Customer state name to search ");
	fflush(stdin);
	gets(str);
	while(fread(&b.cust,sizeof(b.cust),1,p)==1)
	{
		if(strcmp(b.cust.state_cust,str)==0)
		{
			f=1;
		}
	}
	if(f==0)
	printf("No Such Customer exist ");
	else
	{
		rewind(p);
		system("cls");
		printf("custloyee details:");
		printf("\nName\tAccount\tEMAIL\t\tAGE\tCITY\tState");
		while(fread(&b.cust,sizeof(b.cust),1,p)==1)
		{
			if(strcmp(b.cust.state_cust,str)==0)
			{
			printf("\n%s\t%d\t%s\t%d\t%s\t%s",b.cust.name_cust,b.cust.Account_no,b.cust.email_cust,b.cust.age_cust,b.cust.city_cust,b.cust.state_cust);
			}
		}
	}
    fclose(p);
}
int print_total()
{
	FILE *p;
	int t=0;
	p=fopen("Customer_login.txt","rb+");
	if(p==NULL)
	return 0;
	else
	{
		while(fread(&b.cust,sizeof(b.cust),1,p)==1)
		{
			t=t+b.cust.balance;
		}
		fclose(p);
		return t;
	}
}
void customer_login()
{
	int ch;
	while(1)
	{
		printf("\n");
		system("pause");
		system("cls");
		printf("\nWelcome MR./MISS/MRS. %s",b.cust.name_cust);
		printf("\n-------->>> Customer MENU <<<----------");
		printf("\n____________________________________");
		printf("\nPress 1 to Display Customer Own details");
		printf("\nPress 2 to Deposit");
		printf("\nPress 3 to Widraw");
		printf("\nPress 4 to LOG OUT");
		printf("\n____________________________________");
		printf("\nenter your choice");
		printf("\n____________________________________");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				display_cust_own();
				break;
			case 2:
				deposit();
				break;
			case 3:
				widraw();
				break;
			case 4:
				break;
			default:
				printf("Invalid choice");
		}
		if(ch==4)
		break;
	}
}
void display_cust_own()
{
	FILE *p;
	int f=0,num;
	p=fopen("Customer_login.txt","rb+");
	printf("enter the Account number ");
	scanf("%d",&num);
	while(fread(&b.cust,sizeof(b.cust),1,p)==1)
	{
		if(num==b.cust.Account_no)
		{
			f=1;
			printf("\n---->>> WELCOME MR. %s <<<------",b.cust.name_cust);
			printf("\n_________________________________");
			printf("\nAccount Number          %d",b.cust.Account_no);
			printf("\nPIN Number              %d",b.cust.atm_pin);
			printf("\nAge                     %d",b.cust.age_cust);	
			printf("\nHouse Number            %d",b.cust.house_cust);
			printf("\nStreet Number           %d",b.cust.street_cust);
			printf("\nPin Number              %d",b.cust.pin_cust);
			printf("\nCity                    %s",b.cust.city_cust);
			printf("\nState                   %s",b.cust.state_cust);
			printf("\n_________________________________");
			printf("\nBalance                 %d",b.cust.balance);
			printf("\n_________________________________");		
		}
	}
	if(f==0)
	printf("Invalid Account Number");
	fclose(p);
}
void widraw()
{
	FILE *p;
	int f=0,num,temp,m=sizeof(b.cust);
	p=fopen("Customer_login.txt","rb+");
	printf("enter the Account number ");
	scanf("%d",&num);
	while(fread(&b.cust,sizeof(b.cust),1,p)==1)
	{
		if(num==b.cust.Account_no)
		{
			f=1;
			printf("enter the amount to widraw ");
			scanf("%d",&temp);
			if(b.cust.balance-temp<1000)
			{
				printf("Insufficient Balance");
			}
			else
			{
				b.cust.balance=b.cust.balance-temp;
				printf("Transaction successfull\nCurrent Balance %d",b.cust.balance);
			fseek(p,-m,SEEK_CUR);
			fwrite(&b.cust,sizeof(b.cust),1,p);
			break;
			}
		}
	}
	if(f==0)
	printf("Invalid Account Number");
	fclose(p);
}
void deposit()
{
	FILE *p;
	int f=0,num,temp,m=sizeof(b.cust);
	p=fopen("Customer_login.txt","rb+");
	printf("enter the Account number ");
	scanf("%d",&num);
	while(fread(&b.cust,sizeof(b.cust),1,p)==1)
	{
		if(num==b.cust.Account_no)
		{
			f=1;
			printf("enter the amount to deposit ");
			scanf("%d",&temp);
			b.cust.balance=b.cust.balance+temp;
			printf("Current Balance %d",b.cust.balance);
			fseek(p,-m,SEEK_CUR);
			fwrite(&b.cust,sizeof(b.cust),1,p);
			break;
		}
	}
	if(f==0)
	printf("Invalid Account Number");
	fclose(p);
}
void atm_service()
{
	int num,pin;
	FILE *p;
	int i,f=0,j;
	p=fopen("Customer_login.txt","rb+");
	if(p==NULL)
	{
		printf("No Customer details Exist");
	}
	else
	{
		printf("enter the account number ");
		scanf("%d",&num);
        while(fread(&b.cust,sizeof(b.cust),1,p)==1)
        {
        	if(num==b.cust.Account_no)
        	{
        		f=1;
            	for(i=0;i<3;i++)
            	{
            		printf("\nenter the pin number\n");
	    			pin=0;
					for(j=1;j<=4;j++)
	   					{
	    				pin=pin*10+getch()-48;
	    				printf("*");
						}
					getch();
					if(pin==b.cust.atm_pin)
					{
					widraw();
					break;
					}
					else if(i<2)
					printf("\nInvalid pin number");
				}
				if(i==3)
				printf("\nAccount is Blocked");
				break;
			}
		}
	if(f==0)
	printf("Invalid Account Number");
	}
	fclose(p);
}

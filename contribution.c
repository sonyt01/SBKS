#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Donor{
	char first_name[20];
	char last_name[20];
	float contribution;
	char donation_type[20];
	unsigned int donor_id_no;
};
void add_donor_record();
void view_donor_record();
int name_is_valid(char[],char[]);
void contribution_calculation();
void contribution_type()
{
	printf("\n\t\t--------CONTRIBUTION TYPES-------\n ");
	printf("\n\t\t1.Cash \n ");
	printf("\n\t\t1.Clothes \n ");
	printf("\n\t\t1.Volunteer works \n ");
}
void contribution_criteria()
{
   printf("\n\t\t-----------DASHBOARD--------------\n ");
	printf("\n\t\t1.Cash:Rs1000\t\t\t\t  1points\n ");
	printf("\n\t\t1.Clothes:1kg\t\t\t\t  1points \n ");
	printf("\n\t\t1.Volunteer works:1hour \t\t 10points \n ");
}
void menu()
{
    while (1)
    {
        system("cls");
        int choice = 0;
        printf("-------Donation-------");
        printf("\n\t\t1.Add Donor Record\n");
        printf("\n\t\t2.Display Donor Leaderboard\n");
        printf("------------------------------------\n");
    re_choice:
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
            add_donor_record();
            break;
           

        //case 2:
            // view_donor_record();
           // break;

        default:
            printf("\nInvalid Choice");
            Sleep(1000);
            menu();
            break;
        }
        choice = 0;
    }
}
void add_donor_record()
{
     struct Donor input_donor;
     struct Donor read_donor;
      FILE *file_ptr;
      int name_valid;
      int is_donor_present = 0;
      char type1[]="cash";
      char type2[]="clothes";
      char type3[]="volunteer ";
      float n,pts1,m,pts2,p,pts3;
      float totalpoints;
      char choose;
      char type[25];



      
     file_ptr = fopen("D:/dummy/donor_info.txt", "rb+");
     if (file_ptr == NULL)
    {
        printf("\nFILE DOESN'T EXIST\n");
        getchar();
        exit(0);
    }
    printf("\n\t\t======Add Donor Record=======\n");
    fflush(stdin);
again_name:
    printf("\n\t\tEnter first name: ");
    scanf("%s", input_donor.first_name);
    fflush(stdin);
    printf("\n\t\tEnter last name: ");
    scanf("%s", input_donor.last_name);
    fflush(stdin);
    name_valid = name_is_valid(input_donor.first_name, input_donor.last_name);
    if (!name_valid)
    {
        goto again_name;

    }
    
 /*   printf("\nEnter your symbol no: ");
    scanf("%d", &input_donor.donor_id_no);
    while (fread(&read_donor, sizeof(struct Donor), 1, file_ptr))
    {
        if (read_donor.donor_id_no == input_donor.donor_id_no)
        {
            is_donor_present = 1;
            printf("\ndonor with %d symbol number already exists.\n", input_donor.donor_id_no);
            goto again_id;
        }
    }*/
    
   	again:
 	printf("\n\tEnter Contribution Type: ");
    scanf("%s",type);
    if(strcmp(type,type1)==0)
    {
          printf("\nenter the amount that you want to donate: ");
          scanf("%f",&n);
          pts1=n/100;
        printf("points=%.2f",pts1);
    }
	fflush(stdin);
    if(strcmp(type,type2)==0)
    {
      printf("\nenter how many kilos of clothes you want to donate: ");
      scanf("%2f",&m);
      pts2=1*m;
    printf("\npoints=%.2f",pts2);
    }
    fflush(stdin);
    if(strcmp(type,type3)==0)
    {
	     printf("\nenter how many hoursof volunteer work has been done:  ");
	     scanf("%f",&p);
	     pts3=10*p;
	     printf("points=%.2f",pts3);
    }
	alpha:
    fflush(stdin);
    printf("\nDo you want to add your donation?If yes then press 'Y'or'y' else 'N'or 'n':" );
    scanf("%c",&choose);
    if(choose=='Y'||choose=='y')
    {
    	goto again;
	}
	else if(choose=='N'||choose=='n')
	{
	 totalpoints=pts1+pts2+pts3;
    printf("the total points gained is %.2f ",totalpoints);
//		goto add;
	}
	else
	{
		printf("\nenter valid choice: ");
		goto alpha;
	}
       if (!is_donor_present)
    {
        fwrite(&input_donor, sizeof(struct Donor), 1, file_ptr);
    }
    printf("\nFILE HAS BEEN SUCCESSFULLY ADDED");
    fclose(file_ptr);
    Sleep(3000);
}


int name_is_valid(char firstname[], char lastname[])
{
	int i=0;
    for ( i = 0; i < strlen(firstname); i++)
    {
        if (!isalpha(firstname[i]))
        {
            printf("\nInvalid input! Only alphabets are accepted.\n");
            return 0;
        }
    }
    for (i = 0; i < strlen(lastname); i++)
    {
        if (!isalpha(lastname[i]))
        {
            printf("\nInvalid input! Only alphabets are accepted.\n");
            return 0;
        }
    }
    return 1;
}
int main()
{
	contribution_type ();
	contribution_criteria();
	menu();
	
	return 0;
	
}


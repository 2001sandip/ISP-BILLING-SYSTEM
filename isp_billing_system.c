#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
struct isp
{
char name[60],add[50],mnum[20],cnum[25l],pkg[15];
float amount;
}s;
    void addrecords();
    void recordlist();
    void recordmodify();
    void packagelist();
    void deleterecords();
    void searchrecords();
    void payment();
    int main()
       {
	    char choice;
	    system("cls");
        printf("\n\n\t\t=====================( 'WELCOME TO ISP BILLING SYSTEM' )=====================");
        Sleep(400);
        printf("\n\n\t\tPRESS ANY KEY FOR MAIN MENU : ");
	    getch();
        system("cls");
	while (1)
	  {
		system("cls");
        Sleep(500);
        printf("\n\t\t------------------------( 'MAIN MENU' )------------------------\n");
        Sleep(500);
		printf("\n\t\t[A]\tFOR ADDING NEW RECORD.");
		printf("\n\t\t[R]\tFOR RECORDS LIST.");
		printf("\n\t\t[L]\tFOR PACKAGE LIST.");
		printf("\n\t\t[M]\tFOR MODIFYING RECORDS.");
		printf("\n\t\t[P]\tFOR BILL PAYMENT.");
		printf("\n\t\t[S]\tFOR SEARCHING RECORDS.");
		printf("\n\t\t[D]\tFOR DELETING RECORDS.");
		printf("\n\t\t[C]\tCLOSE PROGRAM.");
        Sleep(800);
        printf("\n\n\t\tENTER HERE\t: ");
		choice=getche();
		choice=toupper(choice);
		switch(choice)
		{
            case 'A':
            addrecords();
            break;

            case 'R':
            recordlist();
            break;

            case 'L':
            packagelist();
            break;

            case 'M':
			recordmodify();
            break;

			case 'P':
			payment();
            break;

			case 'S':
			searchrecords();
            break;

			case 'D':
			deleterecords();
            break;

			case 'C':
				system("cls");
				printf("\n\n\t\t\tTHANK YOU");
                Sleep(500);
				printf("\n\t\t FOR USING OUR SERVICE");
                printf("\n\n\n");
				Sleep(1000);
				exit(0);
				break;
			default:
				system("cls");
				printf("\n\n\t\t\t\tWRONG ENTRY");
                Sleep(500);
                printf("\n\n\t\t\tPLEASE ENTER PROPERLY.....!!!!");
				printf("\n\n\t\tPRESS ANY KEY TO CONTINUE");
				getch();
		}
	}
}

void addrecords()
{
    int a;
	FILE *f;
	char test;
	f=fopen("D:\\isp_project.ojs","ab+");
	if(f==0)
	{   f=fopen("D:\\isp_project.ojs","wb+");
		system("cls");
		printf("\n\tPLEASE WAIT WHILE WE CONFIGURE YOUR COMPUTER..");
		printf("\n\nPRESS ANY KEY TO CONTINUE : ");
		getch();
	}
	while(1)
	{
		system("cls");
        printf("\n\t------------( 'PLEASE FILL YOUR DETAILS PROPERLY' )------------");
        printf("\n\n\t\tENTER FULL NAME\t\t: ");
        fflush(stdin);
        scanf("%[^\n]",&s.name);
        printf("\n\t\tENTER CITIZENSHIP NO\t: ");
        fflush(stdin);
        scanf("%[^\n]",&s.cnum);
        printf("\n\t\tENTER MOBILE NUMBER\t: ");
        fflush(stdin);
        scanf("%[^\n]",&s.mnum);
        printf("\n\t\tENTER YOUR ADDRESS\t: ");
        fflush(stdin);
        scanf("%[^\n]",&s.add);
            printf("\n\n\t\t--------------( 'PACKAGE' )------------\n\n");
            printf("\tPACKAGE TYPE\t\tSPEED(Mbps)\tPRICE(Rs.)\t\tSPEED(Mbps)\tPRICE(Rs.)\n");
            for(a=1;a<=100;a++) 
            {
                printf("-"); 
            }
            printf("\n");
            printf("\t1MONTH\t\t\t50\t\t650\t\t\t80\t\t1050\n");
            printf("\t3MONTHS\t\t\t50\t\t1100\t\t\t80\t\t1600\n");
            printf("\t6MONTHS\t\t\t50\t\t2100\t\t\t80\t\t3200\n");
            printf("\t12MONTHS\t\t50\t\t4000\t\t\t80\t\t6000");
            printf("\n\n");
            for(a=1;a<101;a++)
            {
                printf("-");
            }
		printf("\n\n\t\tENTER PACKAGE TYPE\t: ");
        fflush(stdin);
        scanf("%[^\n]",&s.pkg);
        printf("\n\t\tENTER AMOUNT\t\t: ");
		scanf("%f",&s.amount);
		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		system("cls");
		printf("\n\t\t\t1 RECORD SUCCESSFULLY RECORDED...");
        Sleep(800);
		printf("\n\n\tPRESS ESC KEY TO EXIT, ANY OTHER KEY TO ADD ANOTHER RECORED--> ");
		test=getche();
		if(test==27)
			break;
	}
	fclose(f);
}

void recordlist()
{
	FILE *f;
	int i;
	if((f=fopen("D:\\isp_project.ojs","rb"))==NULL)
		exit(0);
	system("cls");
    printf("\n\t\t\t=========================( 'RECORDS LIST' )=========================\n\n\n");
	printf("\tUser's Name\t\tCitizenship No.\t\tAddress\t\tMobile No.\t\tPkg Type\t\tAmount\n");
	for(i=0;i<137;i++)
		printf("-");
	while(fread(&s,sizeof(s),1,f)==1)
	{
printf("\n\t%-10s\t\t%-10s\t\t%-10s\t%-10s\t\t%-10s\t\t%.2f/-",s.name,s.cnum,s.add,s.mnum,s.pkg,s.amount);
	}
	printf("\n\n\n");
	for(i=0;i<137;i++)
	  {
         printf("-");
      }
    printf("\n\n\t\tPRESS ANY KEY TO CONTINUE : ");
fclose(f);
getch();
}

void packagelist()
{
    system("cls");
    int a;
    FILE *f;
    f=fopen("D:\\isp_project.ojs","r");
    printf("\n\n\t\t----------------------------( 'PACKAGE' )----------------------------");
    Sleep(800);
    printf("\n\n\n\tPACKAGE TYPE\t\tSPEED(Mbps)\tPRICE(Rs.)\t\tSPEED(Mbps)\tPRICE(Rs.)\n");
    for(a=1;a<=100;a++)
    {
        printf("-");
    }
    printf("\n");
    printf("\t1MONTH\t\t\t50\t\t650\t\t\t80\t\t1050\n\n");
    printf("\t3MONTHS\t\t\t50\t\t1100\t\t\t80\t\t1600\n\n");
    printf("\t6MONTHS\t\t\t50\t\t2100\t\t\t80\t\t3200\n\n");
    printf("\t12MONTHS\t\t50\t\t4000\t\t\t80\t\t6000");
    printf("\n\n");
    for(a=1;a<101;a++){
        printf("-");
    }
    Sleep(500);
    printf("\n\n\t\tPRESS ANY KEY TO CONTINUE THE PROGRAM : ");
    fclose(f);
    getch();   
}
void deleterecords()
 {
	FILE *f,*t;
	int i=1;
	char mnum[20];
	if((t=fopen("D:\\temp.ojs","w+"))==NULL)
	exit(0);
	if((f=fopen("D:\\isp_project.ojs","rb+"))==NULL)
	exit(0);
	system("cls");
    printf("\n\tENTER THE NUMBER TO DELETED FROM THE DATABASE.....\n\n");
    printf("\t\tENTER HERE\t: ");
	fflush(stdin);
	scanf("%[^\n]",mnum);
	while(fread(&s,sizeof(s),1,f)==1)
	{
	  if(strcmp(s.mnum,mnum)==0)
		{
          i=0;
		  continue;
		}
		else
		{
            fwrite(&s,sizeof(s),1,t);
        }
	}
	if(i==1)
	{       
     system("cls");
	 printf("\t\tMOBILE NUMBER %s IS NOT FOUND IN DATABASE....",mnum);
     Sleep(800);
     printf("\n\n\t\tPLEASE ENTER CORRECT MOBILE NUMBER....");
	 getch();
	 fclose(f);
	 fclose(t);
	 main();
	}
	 
	 system("cls");
     Sleep(1500);
     printf("\n\t\tTHE NUMBER %s IS FOUND IN DATABASE....",mnum);
     Sleep(2500);
     system("cls");
     printf("\n\n\n\t\t\tDELETING.......");
     remove("D:\\isp_project.ojs");
	 rename("D:\\temp.ojs","D:\\isp_project.ojs");
    Sleep(3000);
     system("cls");
	 printf("\n\n\t\tSUCCESSFULLY DELETED FROM DATABASE....!!!!",mnum);
     Sleep(2500);
     printf("\n\n\t\tPRESS ANY KEY TO CONTINUE PROGRAM : ");
	 fclose(f);
	 fclose(t);
	 getch();
 }
void searchrecords()
 {
   FILE *f;
   char mnum[20];
   int flag=1;
   f=fopen("D:\\isp_project.ojs","rb+");
   if(f==0)
   exit(0);
   fflush(stdin);
   system("cls");
   printf("\n\t\tENTER MOBILE NUMBER TO SEARCH IN OUR DATABASE  : ");
   scanf("%s",mnum);
  while(fread(&s,sizeof(s),1,f)==1)
  {
    if(strcmp(s.mnum,mnum)==0)
	{	
     system("cls");
     Sleep(1000);
	 printf("\n\n\t\tRECORD IS FOUND....");
     Sleep(2000);
     system("cls");
     Sleep(500);
     printf("\n\t\t===================( 'RESULT' )===================\n\n");
     Sleep(1000);
	 printf("\t\t\tUSER NAME\t\t: %s",s.name);
	 printf("\n\t\t\tCITIZENSHIP NUMBER\t: %s",s.cnum);
	 printf("\n\t\t\tADDRESS\t\t\t: %s",s.add);
	 printf("\n\t\t\tMOBILE NUMBER\t\t: %s",s.mnum);
	 printf("\n\t\t\tPACKAGE TYPE\t\t: %s",s.pkg);
	 printf("\n\t\t\tPACKAGE AMOUNT\t\t: Rs. %.2f/-",s.amount);
     printf("\n\n\t\tPRESS ANY KEY TO CONTINUE THE PROGRAM : ");
	 flag=0;
	 break;
    }
	else if(flag==1)
	{	
      system("cls");
	  printf("\n\t\tREQUESTED NUMBER '%s' IS NOT FOUND IN DATABASE...");
      Sleep(1500);
      printf("\n\n\t\tPLEASE ENTER NUMBER PROPERLY");
      Sleep(2000);
      printf("\n\n\t\tPRESS ANY KEY TO CONTINUE THE PROGRAM : ");
	}
  }
	getch();
	fclose(f);
}
void recordmodify()
  {
    int a;
	FILE *f;
	char mnum[20];
	long int size=sizeof(s);
	if((f=fopen("D:\\isp_project.ojs","rb+"))==NULL)
	exit(0);
	system("cls");
    printf("\n\t\t----------------( 'MODIFYING RECORD' )----------------\n\n");
    printf("\t\tPLEASE PROVIDE US YOUR MOBILE NUMBER:-\n");
    printf("\t\tENTER HERE\t: ");
	scanf("%[^\n]",mnum);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
	  if(strcmp(s.mnum,mnum)==0)
	  {
		system("cls");
        Sleep(1000);
        printf("\n\t\tMOBILE NUMBER IS MATCHED...");
        Sleep(1500);
        system("cls");
        Sleep(2000);
        printf("\n\t\t=================( 'RECORD MODIFY' )=================");
		printf("\n\n\n\t\tENTER FULL NAME\t\t: ");
        fflush(stdin);
        scanf("%[^\n]",&s.name);
        printf("\n\t\tENTER CITIZENSHIP NO\t: ");
        fflush(stdin);
        scanf("%[^\n]",&s.cnum);
        printf("\n\t\tENTER MOBILE NUMBER\t: ");
        fflush(stdin);
        scanf("%[^\n]",&s.mnum);
        printf("\n\t\tENTER YOUR ADDRESS\t: ");
        fflush(stdin);
        scanf("%[^\n]",&s.add);
            printf("\n\n\t\t--------------( 'PACKAGE' )------------\n\n");
            printf("\tPACKAGE TYPE\t\tSPEED(Mbps)\tPRICE(Rs.)\t\tSPEED(Mbps)\tPRICE(Rs.)\n");
            for(a=1;a<=100;a++) 
            {
                printf("-"); 
            }
            printf("\n");
            printf("\t1MONTH\t\t\t50\t\t650\t\t\t80\t\t1050\n");
            printf("\t3MONTHS\t\t\t50\t\t1100\t\t\t80\t\t1600\n");
            printf("\t6MONTHS\t\t\t50\t\t2100\t\t\t80\t\t3200\n");
            printf("\t12MONTHS\t\t50\t\t4000\t\t\t80\t\t6000");
            printf("\n\n");
            for(a=1;a<101;a++)
            {
                printf("-");
            }
		printf("\n\n\t\tENTER PACKAGE TYPE\t: ");
        fflush(stdin);
        scanf("%[^\n]",&s.pkg);
        printf("\n\t\tENTER AMOUNT\t\t: ");
		scanf("%f",&s.amount);
		fseek(f,-size,SEEK_CUR);
		fwrite(&s,sizeof(s),1,f);
        system("cls");
        printf("\n\t\tWE ARE MODIFYING YOUR RECORD.....!!!\n\n");
        Sleep(1000);
        printf("\t\tPLEASE WAIT THIS MAY TAKE FEW SECONDS....");
        Sleep(4000);
        system("cls");
        printf("\n\t\tSUCCESSFULLY MODIFIED.....");
        Sleep(4000);
		break;
	  }
      else{
            system("cls");
            Sleep(1000);
            printf("\n\t\tTHE NUMBER %s IS NOT MATCH WITH OUR DATABASE....",mnum);
            Sleep(1000);
            printf("\n\n\t\tPLEASE PROVIDE US YOUR CORRECT MOBILE NUMBER TO MODIFY YOUR RECORDS...");
            getch();
        }
	}
   fclose(f);
}

void payment()
{
	FILE *f;
    int a;
	char mnum[20],date[50];
	long int size=sizeof(s);
	float amt;
	int i;
	if((f=fopen("D:\\isp_project.ojs","rb+"))==NULL)
	exit(0);
	system("cls");
    Sleep(800);
	printf("\n\t\tENTER YOUR SUBSCRIBED NUMBER\t: ");
	scanf("%[^\n]",mnum);
	fflush(stdin);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.mnum,mnum)==0)
		{
			system("cls");
            printf("\n\t\tTHE NUMBER %s IS FOUND IN OUR DATABASE......");
            Sleep(1000);
            system("cls");
            for(i=0;i<80;i++)
			 {
                printf("-");
             }
			printf("\n\t\tUSER'S NAME\t\t: %s",s.name);
            printf("\n\t\tCITIZENSHIP NO\t\t: %s",s.cnum);
            printf("\n\t\tMOBILE NUMBER\t\t: %s",s.mnum);
            printf("\n\t\tADDRESS\t\t\t: %s",s.add);
            printf("\n\t\tYOUR PACKAGE\t\t: %s",s.pkg);
            printf("\n\t\tYOUR DUE BALANCE\t: Rs. %.2f/-",s.amount);
			printf("\n");
			for(i=0;i<80;i++)
			 {
                printf("-");
             }
            printf("\n\t\tENTER AMOUNT\t: ");
			fflush(stdin);
			scanf(" %f",&amt);
            printf("\n\t\tENTER CURRENT DATE\t: ");
            fflush(stdin);
            scanf("%s",date);
			s.amount=s.amount-amt;
			fseek(f,-size,SEEK_CUR);
			fwrite(&s,sizeof(s),1,f);
            system("cls");
            Sleep(700);
	        printf("\n\n\t\tTHANK YOU %s FOR YOUR TIMELY PAYMENTS",s.name);
            Sleep(2000);
            system("cls");
            printf("\n\t\tYOUR BILL IS GENERATING PLEASE WAIT...");
            Sleep(2500);
            system("cls");
            printf("\n\n\t\t\t\t\t\tBILL\n");
            for(a=1;a<=115;a++)
            {
            printf("_");
            }
            printf("\n");
            printf("\t\t\t\t\t     WORLD LINK\n");
            printf("\t\t\t\t\tGulariya-06, Bardiya\t\t\tDate :- %s",date);
            printf("\n\n");
            printf("\t\t\t\t\t  PAYMENT COMPLETE\n");
            for(a=1;a<=116;a++)
            {
                printf("-");
            }
            printf("\n\n\tBranch\t\t: Gulariya\t\t\t\t\t\tUser's Name\t: %s",s.name);
            printf("\n\n\tPackage Type\t: %s\t\t\t\t\t\tPaid Amount\t: Rs. %.2f/-",s.pkg,amt);
            printf("\n\n\tAddress\t\t: %s\t\t\t\t\t\tDue Amount\t: %.2f/-",s.amount);
            printf("\n\n\tMobile\t\t: %s\t\t\t\t\t\tCitizenship NO.\t: %s",s.mnum,s.cnum);
            printf("\n\n\tType\t\t: Internet Service\t\t\t\t\tPayment Method\t: eSewa Wallet");
            printf("\n\n\n\t\t\t\t============>THANK YOU<============");
            printf("\n\n\n");
            for(a=1;a<=116;a++)
            {
            printf("_");
            }
			break;
		}
        
	}
	getch();
	fclose(f);
}

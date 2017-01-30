
	
	

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct t{
	char id[50];
	char pass[50];
}log;

typedef struct r{
	char fname[50];
	char lname[50];
	char id[50];
	char password[50];
	char confpass[50];
	int age;
	char dob[50];
	char sex[50];
	char email[50];
	char phone[10];
}regist;

typedef struct c{
	char address[100];
	char hobbies[100];
	char skills[100];
	char highschoolmarks[10];
	char highschool[50];
	char collegemarks[10];
	char college[50];
	char degree[50];
	char qualifications[100];
}resume;

int Findword(char *word, char *file) //finding password in the file 
{
	char line[1024];
	char passcheck[50];
	int i;
	FILE* f = fopen(file,"r+");
	for(i=0;i<4;i++)
	{
		fgets(line , sizeof(line) , f);
	}
	if(strstr(line,word)==NULL)
		return 0;
	strcpy(passcheck,strstr(line,word));
	if(strcmp(passcheck,word))
	{
		return 1;
	}
	fclose(f);
	return 0;
}

void inputCV(char *file)
{
	resume *cv;
	int i,t1;
	char line[1024];
	cv = (resume*)malloc(sizeof(resume));
	FILE *f;
	f = fopen(file,"a+");
	printf("Enter the following information to generate a CV\n");
	printf("Address :\t");
	scanf("%s",&cv->address);
	printf("\nHobbies :\t");
	scanf("%s",&cv->hobbies);
	printf("\nSkills :\t");
	scanf("%s",&cv->skills);
	printf("\nHigh school :\t");
	scanf("%s",&cv->highschool);
	printf("\nHigh school performance :\t");
	scanf("%s",&cv->highschoolmarks);
	printf("\nCollege :\t");
	scanf("%s",&cv->college);
	printf("\nCollege performance :\t");
	scanf("%s",&cv->collegemarks);
	printf("\nDegrees :\t");
	scanf("%s",&cv->degree);
	printf("\nAdditional Qualifications :\t");
	scanf("%s",&cv->qualifications);
	system("clear");/////
	fprintf(f,"Address = %s \nHobbies = %s \nSkills = %s \n High school = %s \nHigh school performance = %s \nCollege = %s \nCollege performance = %s \nDegrees = %s \nAdditional Qualifications = %s\n",cv->address,cv->hobbies,cv->skills,cv->highschool,cv->highschoolmarks,cv->college,cv->collegemarks,cv->degree,cv->qualifications);
	fclose(f);
}

void outputCV(char *file)
{
	resume *cv;
	int i,t1;
	char line[1024];
	cv = (resume*)malloc(sizeof(resume));
	FILE *f;
	f = fopen(file,"r+");
	printf("-----PERSONAL INFORMATION-----\n");
	for(i=0;i<2;i++)
	{
		fgets(line , sizeof(line) , f);
		printf("%s\n",line);
	}
	fgets(line , sizeof(line) , f);
	fgets(line , sizeof(line) , f);
	for(i=0;i<6;i++)
	{
		fgets(line , sizeof(line) , f);
		printf("%s\n",line);
	}
	printf("\n\n\n-----HOBBIES-----\n");
	fgets(line , sizeof(line) , f);
	printf("%s\n",line);
	printf("\n\n\n-----SKILLS-----\n");
	fgets(line , sizeof(line) , f);
	printf("%s\n",line);
	printf("\n\n\n-----EDUCATIONAL QUALIFICATIONS-----\n");
	for(i=0;i<6;i++)
	{
		fgets(line , sizeof(line) , f);
		printf("%s\n",line);
	}
	fclose(f);
}

int profile(char *login)
{
	resume *cv;
	int i,t1;
	char line[1024];
	cv = (resume*)malloc(sizeof(resume));
	char file[50];
	FILE *f;
	strcpy(file,login);
	strcat(file,".txt");
	f = fopen(file,"a+");
	printf("Enter 1 to print your CV\n");
	scanf("%d",&t1);
	if(t1==1)
	{
		for(i=0;i<10;i++)
		{
			if(fgets(line , sizeof(line) , f)==NULL)
			{
				rewind(f);
				inputCV(file);
				outputCV(file);
				return 0;
			}
		}
		fclose(f);
		outputCV(file);
	}
}

int login_page()
{
	FILE *f;
	char filename[50];
	log *login = (log*)malloc(sizeof(log));
	system("clear");/////
	printf("login id:\t");
	scanf("%s",&login->id);
	printf("\npassword:\t");
	scanf("%s",&login->pass);
	strcpy(filename,login->id);
	strcat(filename,".txt");
	f = fopen(filename,"r+");
	if(f==NULL)
	{
		return 0; //file doesnt exist for the username entered
	}
	if(Findword(login->pass,filename))
	{
		printf("Welcome %s.\n",&login->id);
		profile(login->id); // directly proceed to profile page
		return 1; //successful login
	}
	fclose(f);
	return 2; //password doesnt match username
}

void register_page()
{
	FILE *f;
	char filename[50];
	regist *reg = (regist*)malloc(sizeof(regist));
	system("clear");//////
	printf("First Name :\t");
	scanf("%s",&reg->fname);
	printf("\nLast Name :\t");
	scanf("%s",&reg->lname);
	do{
		printf("\nlogin id :\t");
		scanf("%s",&reg->id);
		strcpy(filename,reg->id);
		strcat(filename,".txt");
	}while(fopen(filename,"r")!=NULL);
	do{
		printf("\npassword :\t");
		scanf("%s",&reg->password);
		printf("\nconfirm password :\t");
		scanf("%s",&reg->confpass);
	}while(strcmp(reg->password,reg->confpass));
	printf("\nsex :\t");
	scanf("%s",&reg->sex);
	printf("\nemail id :\t");
	scanf("%s",&reg->email);
	printf("\nage :\t");
	scanf("%d",&reg->age);
	printf("\ndate of birth (ddmmyyyy):\t");
	scanf("%s",&reg->dob);
	printf("\nphone number :\t");
	scanf("%s",&reg->phone);
	f = fopen(filename,"w+");
	fprintf(f,"First Name = %s \nLast Name = %s\n",reg->fname,reg->lname);
	fprintf(f,"login id = %s \npassword = %s \nsex = %s \nemail id = %s \nage = %d \ndate of birth = %s \nphone number = %s \n",reg->id,reg->password,reg->sex,reg->email,reg->age,reg->dob,reg->phone);
	fclose(f);
	system("clear");/////
	printf("Welcome %s .\n",reg->id);
	profile(reg->id); //directly proceed to profile page
}


int main()
{
	int t1,t2;
	printf("enter 0 for login or 1 for registering\n");
	scanf("%d",&t1);
	if(!t1) //to login
	{
		int t3;
		while((t3=login_page())!=1) //three types of return values for login_page ,depending upon success or failure in login
		{
			int temp;
			if(t3==1)
			{
				return 0;
			}
			else 
			{
				printf("login id or password is incorrect\n");
				printf("press 1 if you dont have an account else enter 0\n");
				scanf("%d",&temp);
				if(temp==1)
				{
					register_page();
					return 0;
				}
			}
		}
	}
	else{   //to register
		printf("Enter 0 to go back to login or 1 to register\n");
		scanf("%d",&t2);
		if(!t2)
		{
			login_page();
		}
		else
		{
			register_page();
		}
	}
}


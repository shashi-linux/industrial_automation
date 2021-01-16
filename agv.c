#include"my_header.h"

struct r_v
{
	int x;
	int y;
	int start_end_point[2];
	int cnt;
	int f;
	int f1;
	int collide;
	int ud;
};

struct h_v
{
	int x;
	int y;
	int start_end_point[2];
	int f;
	int collide;
};


struct r_v rv1;
struct r_v rv2;
struct r_v rv3;
struct r_v rv4;

struct h_v hv;

int c_point[4][2]={{9,3},{9,6},{9,8},{9,10}};


void remote_vehicle1()
{

	rv1.cnt++;
	if(rv1.cnt>3)
	{
		
		rv1.f1=0;
		if(rv1.f==0)
			rv1.x++;
		else
			rv1.x--;
	}
	else
	{
		if(rv1.f==1)
			printf("         RV1 is loadind-> %dsec left\n",rv1.ud);
		else
			printf("         RV1 is uploadind-> %dsec left\n",rv1.ud);
		
		rv1.ud--;
	}

	if((rv1.x==rv1.start_end_point[0]) &&(rv1.f1==0))
	{
		rv1.f1=1;
		rv1.cnt=0;
		rv1.f=0;
		rv1.ud=3;
	}


	if((rv1.x==rv1.start_end_point[1])&&(rv1.f1==0))
	{
		rv1.cnt=0;
		rv1.f1=1;
		rv1.f=1;
		rv1.ud=3;
	}

}



void remote_vehicle2()
{

	rv2.cnt++;
	if(rv2.cnt>3)
	{
		rv2.f1=0;
		if(rv2.f==0)
			rv2.x++;
		else
			rv2.x--;
	}
	else
	{
		if(rv2.f==1)
			printf("         RV2 is loadind-> %dsec left\n",rv2.ud);
		else
			printf("         RV2 is uploadind-> %dsec left\n",rv2.ud);
		
		rv2.ud--;
	}


	if((rv2.x==rv2.start_end_point[0])&&(rv2.f1==0))
	{
		rv2.cnt=0;
		rv2.f1=1;
		rv2.f=0;
		rv2.ud=3;
	}


	if((rv2.x==rv2.start_end_point[1])&&(rv2.f1==0))
	{
		rv2.cnt=0;
		rv2.f1=1;
		rv2.f=1;
		rv2.ud=3;
	}



}

void remote_vehicle3()
{

	rv3.cnt++;
	if(rv3.cnt>3)
	{
		rv3.f1=0;
		if(rv3.f==0)
			rv3.x++;
		else
			rv3.x--;
	}
	else
	{
		if(rv3.f==1)
			printf("         RV3 is loadind-> %dsec left\n",rv3.ud);
		else
			printf("         RV3 is uploadind-> %dsec left\n",rv3.ud);
		
		rv3.ud--;
	}

	if((rv3.x==rv3.start_end_point[0])&&(rv3.f1==0))
	{
		rv3.f1=1;
		rv3.cnt=0;
		rv3.f=0;
		rv3.ud=3;
	}


	if((rv3.x==rv3.start_end_point[1])&&(rv3.f1==0))
	{
		rv3.f1=1;
		rv3.cnt=0;
		rv3.f=1;
		rv3.ud=3;
	}



}
////////////////////////////////

void remote_vehicle4()
{

	rv4.cnt++;
	if(rv4.cnt>3)
	{
		rv4.f1=0;
		if(rv4.f==0)
			rv4.x++;
		else
			rv4.x--;
	}
	else
	{
		if(rv4.f==1)
			printf("         RV4 is loadind-> %dsec left\n",rv4.ud);
		else
			printf("         RV4 is uploadind-> %dsec left\n",rv4.ud);
		
		rv4.ud--;
	}

	if((rv4.x==rv4.start_end_point[0])&&(rv4.f1==0))
	{
		rv4.cnt=0;
		rv4.f1=1;
		rv4.f=0;
		rv4.ud=3;
	}


	if((rv4.x==rv4.start_end_point[1]) && (rv4.f1==0))
	{
		rv4.cnt=0;
		rv4.f1=1;
		rv4.f=1;
		rv4.ud=3;
	}



}

/////////////////////////////////
void Rec_Meassage()
{
	///////////////////////// HUMAN VEHICLE LOGIC/////////////////////////////////
		int i,j,k;
		for(i=13;i>=0;i--,printf("\n"))
		{
		for(j=0;j<=17;j++)
		{
		if(j==9)
		printf("|");
		if((i==rv4.y)&&(j==rv4.x))
		printf("%3s","RV4");
		else if((i==rv3.y)&&(j==rv3.x))
		printf("%3s","RV3");
		else if((i==rv2.y)&&(j==rv2.x))
		printf("%3s","RV2");
		else if((i==rv1.y)&&(j==rv1.x))
		printf("%3s","RV1");
		else if((i==hv.y)&&(j==hv.x))
		printf("%3s","HV ");
		else
		printf("___");
		}
		}



	puts("****ALL VEHICLE COORDINATES****");
	printf("          RV4->(%d,%d)\n",rv4.x,rv4.y);
	printf("          RV3->(%d,%d)\n",rv3.x,rv3.y);
	printf("          RV2->(%d,%d)\n",rv2.x,rv2.y);
	printf("          RV1->(%d,%d)\n",rv1.x,rv1.y);
	printf("          HV->(%d,%d)\n",hv.x,hv.y);

	//////////////////////////////////////////////////////////
	if(((rv1.x-1)==c_point[0][0]) || ((rv1.x+1)==c_point[0][0]))
	{ 
		if(((hv.y-1)==c_point[0][1]) || ((hv.y+1)==c_point[0][1])) 
		{
			hv.collide=1;
			rv1.collide=1;
		}
	}

	if(((rv2.x-1)==c_point[1][0]) || ((rv2.x+1)==c_point[1][0]))
	{ 
		if(((hv.y-1)==c_point[1][1]) || ((hv.y+1)==c_point[1][1])) 
		{
			hv.collide=1;
			rv2.collide=1;
		}
	}

	if(((rv3.x-1)==c_point[2][0]) || ((rv3.x+1)==c_point[2][0]))
	{ 
		if(((hv.y-1)==c_point[2][1]) || ((hv.y+1)==c_point[2][1])) 
		{
			hv.collide=1;
			rv3.collide=1;
		}
	}

	if(((rv4.x-1)==c_point[3][0]) || ((rv4.x+1)==c_point[3][0]))
	{ 
		if(((hv.y-1)==c_point[3][1]) || ((hv.y+1)==c_point[3][1])) 
		{
			hv.collide=1;
			rv4.collide=1;
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////
	if(hv.collide==1)
	{
		hv.collide=0;

		if(rv1.collide==1)
		{

			if((hv.f==0) && (hv.y>c_point[0][1]))
			{
				hv.y++;
			}
			else if((hv.f==1) && (hv.y<c_point[0][1]))
			{
				hv.y--;
			}
			else
			{
				puts("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
				puts("\n human vehicle is waiting to cross remote vehicle rv1 \n");
				puts("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
			}
			rv1.collide=0;
		}

		if(rv2.collide==1)
		{

			if((hv.f==0) && (hv.y>c_point[1][1]))
			{
				hv.y++;
			}
			else if((hv.f==1) && (hv.y<c_point[1][1]))
			{
				hv.y--;
			}
			else
			{
				puts("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
				puts("\n human vehicle is waiting to cross remote vehicle rv2 \n");
				puts("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
			}
			rv2.collide=0;
		}

		if(rv3.collide==1)
		{

			if((hv.f==0) && (hv.y>c_point[2][1]))
			{
				hv.y++;
			}
			else if((hv.f==1) && (hv.y<c_point[2][1]))
			{
				hv.y--;
			}
			else
			{
				puts("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
				puts("\n human vehicle is waiting to cross remote vehicle rv3 \n");
				puts("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
			}
			rv3.collide=0;
		}
		if(rv4.collide==1)
		{

			if((hv.f==0) && (hv.y>c_point[3][1]))
			{
				hv.y++;
			}
			else if((hv.f==1) && (hv.y<c_point[3][1]))
			{
				hv.y--;
			}
			else
			{
				puts("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
				puts("\n human vehicle is waiting to cross remote vehicle rv4 \n");
				puts("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
			}
			rv4.collide=0;
		}

	}
	else
	{

		if(hv.y==hv.start_end_point[0])
		{
			hv.f=0;
		}

		if(hv.y==hv.start_end_point[1])
		{
			hv.f=1;
		}

		if(hv.f==0)
			hv.y++;
		else
			hv.y--;

		/*
		   if(((rv1.x-1)==c_point[0][0]) || ((rv1.x+1)==c_point[0][0]))
		   { 
		   if(((hv.y-1)==c_point[0][1]) || ((hv.y+1)==c_point[0][1])) 
		   {
		   hv.collide=1;
		   rv1.collide=1;
		   }
		   }

		   if(((rv2.x-1)==c_point[1][0]) || ((rv2.x+1)==c_point[1][0]))
		   { 
		   if(((hv.y-1)==c_point[1][1]) || ((hv.y+1)==c_point[1][1])) 
		   {
		   hv.collide=1;
		   rv2.collide=1;
		   }
		   }

		   if(((rv3.x-1)==c_point[2][0]) || ((rv3.x+1)==c_point[2][0]))
		   { 
		   if(((hv.y-1)==c_point[2][1]) || ((hv.y+1)==c_point[2][1])) 
		   {
		   hv.collide=1;
		   rv3.collide=1;
		   }
		   }*/

	}
}


///////////////////// MAIN FUNCTION //////////////////////
main()
{
	//time_t t;
	struct timeb t;
	struct tm *tmptr;
	char datestring[20],timestring[20];
	//t=time(NULL);
	rv1.x=3;
	rv1.y=3;
	rv1.start_end_point[0]=0;
	rv1.start_end_point[1]=17;
	rv1.cnt=0;
	rv1.f=0;
	rv1.f1=0;
	rv1.ud=3;
	rv1.collide=0;



	rv2.x=8;
	rv2.y=6;
	rv2.start_end_point[0]=0;
	rv2.start_end_point[1]=17;
	rv2.cnt=5;
	rv2.f=1;
	rv2.f1=0;
	rv2.ud=3;
	rv2.collide=0;


	rv3.x=10;
	rv3.y=8;
	rv3.start_end_point[0]=0;
	rv3.start_end_point[1]=17;
	rv3.cnt=4;
	rv3.f=0;
	rv3.f1=0;
	rv3.ud=3;
	rv3.collide=0;

	rv4.x=13;
	rv4.y=10;
	rv4.start_end_point[0]=0;
	rv4.start_end_point[1]=17;
	rv4.cnt=4;
	rv4.f=1;
	rv4.f1=0;
	rv4.ud=3;
	rv4.collide=0;


	hv.x=9;
	hv.y=0;
	hv.start_end_point[0]=0;
	hv.start_end_point[1]=13;
	hv.f=0;
	hv.collide=0;

	while(1)
	{

		ftime(&t);
		tmptr=localtime(&t.time);
		//tmptr=localtime(&t);
		strftime(datestring,20,"%F",tmptr);
		strftime(timestring,20,"%T",tmptr);
		//printf("%s %s\n",datestring,timestring);
		//printf("%s %s %d\n",datestring,timestring,t.millitm);

		printf("          xx***xx *SHASHIKANT* INDUSTRY xx***xx        \n");
		printf("                   **DATE**  hr:mi:se millisec        \n");
		printf("UPLOADIND        %s  %s  %d      LOADING\n",datestring,timestring,t.millitm);
		Rec_Meassage();
		remote_vehicle1();
		remote_vehicle2();
		remote_vehicle3();
		remote_vehicle4();

		sleep(1);
		system("clear");
	}

}

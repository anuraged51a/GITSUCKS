#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
#include<process.h>
#include<time.h>
//#include<graphics.h>
//#include<iomanip.h>
#define V 6
using namespace std;
int completed[10],n1,cost=0;
int ary[10][10];
int ret;
int sum;
bool mem[10000][10000];
void takeInput()
{
    int i,j;

    printf("\nEnter the Cost Matrix\n");

    for(i=0;i < n1;i++)
    {
       // printf("\nEnter Elements of Row: %d\n",i+1);

        for( j=0;j < n1;j++)
            scanf("%d",&ary[i][j]);

        completed[i]=0;
    }

  /*  printf("\n\nThe cost list is:");

    for( i=0;i < n1;i++)
    {
        printf("\n");

        for(j=0;j < n1;j++)
            printf("\t%d",ary[i][j]);
    }*/
}

void find(vector<vector<int> >& mem_coinage,int row,int col,int ret,int deno[])
    {
    int j,flag=0;
    if(ret==0)
        {
            return ;
        }
    if(ret!=0)
        {
            for(j=row; j>=0; j--)
                {
                    if(mem_coinage[j][col]==mem_coinage[j-1][col])
                        {
                            flag=0;
                        }
                    else
                        {
                            flag=1;
                            break;
                        }
                }
            if(flag==1)
                {
                    cout<<"\ndenomination: "<<deno[j-1]<<endl;
                    row=j;
                    col=ret-deno[j-1];
                    ret=ret-deno[j-1];

                }

            find(mem_coinage,row,col,ret,deno);
        }

}
int find_min(int a,int b)
    {
        int s1;
        if(a<b)
            s1=a;
        else
            s1=b;
        return s1;
    }
int least(int c)
    {
        int i,nc=999;
        int min=999,kmin;
        for(i=0;i < V;i++)
            {
                if((ary[c][i]!=0)&&(completed[i]==0))
                    if(ary[c][i]+ary[i][c] < min)
                        {
                            min=ary[i][0]+ary[c][i];
                            kmin=ary[c][i];
                            nc=i;
                        }
            }

        if(min!=999)
            cost+=kmin;

        return nc;
    }
int coin_change(int deno[],int size_deno,vector<vector<int> >& quan)
{
    int i,j,x,y;
    int mem_coinage[size_deno+1][ret+1];
    for(i=0; i<size_deno+1; i++)
    {
        for(j=0; j<ret+1; j++)
        {
            mem_coinage[i][j]=0;
        }
    }

    for(j=0; j<=ret; j++)
        mem_coinage[0][j]=99999;
    for(i=1; i<=size_deno; i++)
        mem_coinage[i][0]=0;

    for(i=1; i<=size_deno; i++)
    {
        for(j=1; j<=ret; j++)
        {
            if(deno[i-1]<=j)
                mem_coinage[i][j]=find_min((1+mem_coinage[i][j-deno[i-1]]),mem_coinage[i-1][j]);
            else
                mem_coinage[i][j]=mem_coinage[i-1][j];
        }
    }
    for(i=0; i<size_deno+1; i++)
    {
        quan.push_back(vector<int>());
        for(j=0; j<ret+1; j++)
        {
            quan[i].push_back(mem_coinage[i][j]);
            // cout<<mem[i][j]<<"\t";
        }
    }
    return mem_coinage[size_deno][ret];
}

void mincost(int city)
{
    int i,ncity;
    completed[city]=1;
    cout<<city+1<<"--->";
    ncity=least(city);
    if(ncity==999)
    {
        ncity=0;
        cout<<ncity+1;
        cost+=ary[city][ncity];
        return;
    }

    mincost(ncity);
}

COORD coord={0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
int main()
{
   gotoxy(1,2);
	cout<<  "\t    лл      лл ллллллл лл      ллллллл ллллллл лллл лллл ллллллл";
    cout<<"\n\t    лл      лл лл      лл      лл      лл   лл лл ллл лл лл     ";
    cout<<"\n\t    лл  лл  лл ллллл   лл      лл      лл   лл лл  л  лл ллллл  ";
    cout<<"\n\t    лл  лл  лл лл      лл      лл      лл   лл лл     лл лл     ";
    cout<<"\n\t    лллллллллл ллллллл ллллллл ллллллл ллллллл лл     лл ллллллл";
	gotoxy(6,9);
	cout << "     **************************************************************" << endl;
	gotoxy(6,10);
	cout << "                           ALGORITHM AND PROBLEM SOLVING PROJECT                     " << endl;
	gotoxy(6,11);
	cout << "     **************************************************************" << endl;
        cout<<"RAMLAL DAIRY PROBLEM";
        cout<<endl<<endl<<"Sub By:Anurag Gupta(17803028)"<<endl<<"  "<<"Abhimanyu Chandak(17803001)"<<endl<<"  "<<"Mayank Gupta(17803002)"<<endl<<"  "<<"Shubham Mishra(17803025)";
    delay(4000);
    system("cls");
    int cust_quantity[n1],sum_quantity=0,quantity,lo=0;
    printf("Enter the number of customers: ");
    scanf("%d",&n1);

    for(int i=0;i<n1;i++)
    {
        cout<<"\n\t Enter the quantity of milk required by Customer "<<i+1<<": ";
        cin>>quantity;
        cust_quantity[lo]=quantity;
        lo++;
        sum_quantity+=quantity;

    }
    sum=sum_quantity;

    int i,j=0;
    int arr[]={0,1,2,3,4,5,6,8,10,12,15,18,20,22,25,50};
    int quality[]={0,25,15,45,66,89,24,70,99,53,15,87,23,65,43,68};
    int n=15;
    cout<<endl;
    takeInput();
    mincost(0); //passing 0 because starting vertex
    cout<<"\n\n\tMinimum cost is of transportation for Shyam "<<cost<<endl;




    int deno[]= {1,2,5,10,20,50,100,200,500,1000,2000};
    int size_deno=sizeof(deno)/sizeof(deno[0]);

    int amt,cust;
    for(int z=0;z<lo;z++)
    {
    amt=cust_quantity[z]*45;
    A:
    cout<<"\n\tTotal cost of milk for customer"<<z+1<<": "<<amt;
    cout<<"\n\t Amount of money customer "<<z+1<<" has given:";
    cin>>cust;
    ret=cust-amt;

    vector< vector<int> > Vec;
    if(ret>0)
    {
    int change=coin_change(deno,size_deno,Vec);

    cout<<"\nAmount to be returned by Shyam:"<<ret<<endl;

        cout<<"\n----Shyam should return the following denomination(s) to the customer---- ";
        find(Vec,size_deno,ret,ret,deno);
        cout<<"-------------------------------------------------------------";
    }
    else
    {
     cout<<"\n-----PLEASE GIVE  "<<(ret)*-1<<" .RS MORE-----";
    cout<<"-------------------------------------------------------------";
     goto A;
    }
    }
    return 0;

}

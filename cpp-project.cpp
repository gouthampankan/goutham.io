#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
struct location
{
 int r[30],g[30];
}loc[30];
int row(int p)
{
 int first;
 first=p/10;
 return first;
}
int column(int t)
{
 int last;
 last=t%10;
 return last;
}
void main()
{
 clrscr();
 int i,end,j,a,b,c[30][30],z[30][30],k=0,v[30][30],n,m[30],d,repetition=1,count=0,left1=81,left2=81,left3=81,h,sum=0,f=0,cost=0,rep=0;
 char u='U',x='X',choice[10],selection[10];
 for(i=0,a=1,b=1;i<10;i++)
    {
     for(j=0;j<10;j++)
       {
	if(i+j!=0)
	 {
	  if(i==0)
	   {
	    c[i][j]=3;
	    z[i][j]=3;
	    v[i][j]=3;
	   }
	  else if(j==0)
	   {
	    c[i][j]=2;
	    z[i][j]=2;
	    v[i][j]=2;
	   }
	  else
	   {
	    c[i][j]=0;
	    z[i][j]=0;
	    v[i][j]=0;
	   }
	 }
	else
	 {
	  c[i][j]=4;
	  z[i][j]=4;
	  v[i][j]=4;
	 }
       }
    }
 do
 {
  repetition=0;
  end=0;
  cout<<"Please select any one of the movies below\n";
  cout<<"1. Pulimurugan\n";
  cout<<"2. Doctor Strange\n";
  cout<<"3. Spiderman:Homecoming\n";
  cout<<"Enter your choice (1-3) :\n";
  cin>>k;
  switch(k)
  {
   case 1:clrscr();
	  if(left1>0)
	  {
	   do
	   {
	    if(repetition==0)
	    {
	     if(f==0)
	      cout<<"\t\t\t\tMOVIE TICKET BOOKING\n\n";
	     for(i=0,count=0,a=1,b=1;i<10;i++)
	      {
	       for(j=0;j<10;j++)
	       {
		if(c[i][j]==3)
		 cout<<"   "<<a++;
		else if(c[i][j]==2)
		 cout<<endl<<b++;
		else if(c[i][j]==1)
		 cout<<"   "<<x;
		else if(c[i][j]==0)
		 cout<<"   "<<u;
	       }
	    }
	   if(left1<81)
	    cout<<"\nThere are "<<left1<<" seats remaining !";
	   if(f==0)
	   {
	    cout<<"\nEnter the number of seats required : "<<endl;
	    cin>>n;
	   }
	   else
	   {
	    n=f;
	    cout<<endl;
	   }
	   if(n>0)
	   {
	     cout<<"(Enter the row number first, then enter the column number.)"<<endl<<"Eg:44,55,etc."<<endl;
	     cout<<"Enter the locations of the seats required : "<<endl;
	     for(i=0;i<n;i++)
	       cin>>m[i];
	     for(i=0;i<n;i++)
	       {
		loc[k].r[i]=row(m[i]);
		loc[k].g[i]=column(m[i]);
	       }
	   }
	  for(d=0,h=0,f=0;d<n;d++)
	    {
	     for(i=0;i<10;i++)
	       {
		for(j=0;j<10;j++)
		  {
		    if((loc[k].r[d]==i)&&(loc[k].g[d]==j))
		     {
		      if(c[i][j]==1)
		       {
			clrscr();
			h=1;
		       }
		      else if((i==0)||(j==0))
		      {
		       clrscr();
		       h=1;
		      }
		    }
		  }
	       }
	    }
	  if(h==1)
	   cout<<"\t\t\t\tMOVIE TICKET BOOKING\n\n";
	  for(d=0,f=0;d<n;d++)
	    {
	      for(i=0;i<10;i++)
	       {
		for(j=0;j<10;j++)
		  {
		   if((loc[k].r[d]==i)&&(loc[k].g[d]==j))
		    {
		     if(c[i][j]==1)
		      {
		       cout<<"The location "<<m[d]<<" is already selected.\n";
		       h=1;
		       f++;
		      }
		     else if((i>0)&&(j>0))
		      {
		       c[i][j]=1;
		       if(i>7)
			cost+=35;
		       else
			cost+=25 ;
		      }
		     else
		      {
		       f++;
		       h=1;
		       cout<<"The location "<<m[d]<<" is invalid. \n";
		      }
		    }
		  }
	       }
	    }
	  if(h==0)
	   clrscr();
	  rep=2;
	  if(h==1)
	   cout<<"Please select "<<f<<" other locations.\n\n";
	  else
	   {
	    if(left1>0)
	     {
	      do
	      {
	       cout<<"\t\t\t\tMOVIE TICKET BOOKING\n\n";
	       for(i=0,a=1,b=1;i<10;i++)
		 {
		  for(j=0;j<10;j++)
		    {
		     if(c[i][j]==3)
		      cout<<"   "<<a++;
		     else if(c[i][j]==2)
		      cout<<endl<<b++;
		     else if(c[i][j]==1)
		      {
		       cout<<"   "<<x;
		       if(rep==2)
			 {
			  left1--;
			  count++;
			 }
		       }
		      else if(c[i][j]==0)
		       cout<<"   "<<u;
		     }
		  }
		sum=count;
		if(f==0)
		 {
		 if(cost>0)
		  cout<<"\nThe total cost is "<<cost;
		 else
		  cout<<"\nYou have selected no seats.";
		 cout<<"\nDo you wish to exit? \nIf yes, press (Y), else press (N). \nEnter your choice : \n";
		 gets(choice);
		 }
		if(strcmpi(choice,"y")==0)
		 {
		 end=1;
		 count=81;
		 rep=0;
		 cost=0;
		 repetition=1;
		 }
		else if(strcmpi(choice,"n")==0)
		 {
		 repetition=1;
		 count=81;
		 sum+=count;
		 rep=0;
		 cost=0;
		 }
		else
		 rep=1;
		 clrscr();
		}while(rep!=0);
	       }
	     }
	    }
	   }while(count<81);
	  }
	  else
	   cout<<"We are booked out for'Pulimurugan'.\n";
	  break;
   case 2:clrscr();
	  if(left2>0)
	  {
	   do
	   {
	    if(repetition==0)
	     {
	      if(f==0)
	       cout<<"\t\t\t\tMOVIE TICKET BOOKING\n\n";
	      for(i=0,count=0,a=1,b=1;i<10;i++)
		{
		 for(j=0;j<10;j++)
		 {
		 if(z[i][j]==3)
		  cout<<"   "<<a++;
		 else if(z[i][j]==2)
		  cout<<endl<<b++;
		 else if(z[i][j]==1)
		  cout<<"   "<<x;
		 else if(z[i][j]==0)
		   cout<<"   "<<u;
		 }
	      }
	    if(left2<81)
	    cout<<"\nThere are "<<left2<<" seats remaining !";
	   if(f==0)
	    {
	    cout<<"\nEnter the number of seats required : "<<endl;
	    cin>>n;
	   }
	  else
	   {
	    n=f;
	    cout<<endl;
	   }
	  if(n>0)
	   {
	     cout<<"(Enter the row number first, then enter the column number.)"<<endl<<"Eg:44,55,etc."<<endl;
	     cout<<"Enter the locations of the seats required : "<<endl;
	     for(i=0;i<n;i++)
	       cin>>m[i];
	     for(i=0;i<n;i++)
	       {
		loc[k].r[i]=row(m[i]);
		loc[k].g[i]=column(m[i]);
	       }
	   }
	  for(d=0,h=0,f=0;d<n;d++)
	    {
	     for(i=0;i<10;i++)
	       {
		for(j=0;j<10;j++)
		  {
		    if((loc[k].r[d]==i)&&(loc[k].g[d]==j))
		     {
		      if(z[i][j]==1)
		       {
			clrscr();
			h=1;
		       }
		      else if((i==0)||(j==0))
		      {
		       clrscr();
		       h=1;
		      }
		    }
		  }
	       }
	    }
	  if(h==1)
	   cout<<"\t\t\t\tMOVIE TICKET BOOKING\n\n";
	  for(d=0,f=0;d<n;d++)
	    {
	      for(i=0;i<10;i++)
	       {
		for(j=0;j<10;j++)
		  {
		   if((loc[k].r[d]==i)&&(loc[k].g[d]==j))
		    {
		     if(z[i][j]==1)
		      {
		       cout<<"The location "<<m[d]<<" is already selected.\n";
		       h=1;
		       f++;
		      }
		     else if((i>0)&&(j>0))
		      {
		       z[i][j]=1;
		       if(i>7)
			cost+=35;
		       else
			cost+=25 ;
		      }
		     else
		      {
		       f++;
		       h=1;
		       cout<<"The location "<<m[d]<<" is invalid. \n";
		      }
		    }
		  }
	       }
	    }
	  if(h==0)
	   clrscr();
	  rep=2;
	  if(h==1)
	   cout<<"Please select "<<f<<" other locations.\n\n";
	  else
	   {
	    if(left2>0)
	     {
	      do
	      {
	       cout<<"\t\t\t\tMOVIE TICKET BOOKING\n\n";
	       for(i=0,a=1,b=1;i<10;i++)
		 {
		  for(j=0;j<10;j++)
		    {
		     if(z[i][j]==3)
		      cout<<"   "<<a++;
		     else if(z[i][j]==2)
		      cout<<endl<<b++;
		     else if(z[i][j]==1)
		      {
		       cout<<"   "<<x;
		       if(rep==2)
			{
			 left2--;
			 count++;
			}
		      }
		     else if(z[i][j]==0)
		      cout<<"   "<<u;
		    }
		 }
	       sum=count;
	       if(f==0)
		{
		 if(cost>0)
		  cout<<"\nThe total cost is "<<cost;
		 else
		  cout<<"\nYou have selected no seats.";
		 cout<<"\nDo you wish to exit? \nIf yes, press (Y), else press (N). \nEnter your choice : \n";
		 gets(choice);
		}
	       if(strcmpi(choice,"y")==0)
		{
		 repetition=1;
		 end=1;
		 count=81;
		 rep=0;
		 cost=0;
		}
	       else if(strcmpi(choice,"n")==0)
		{
		 repetition=1;
		 count=81;
		 sum+=count;
		 rep=0;
		 cost=0;
		}
	       else
		rep=1;
	       clrscr();
	       }while(rep!=0);
	      }
	     }
	    }
	   }while(count<81);
	  }
	  else
	   cout<<"We are booked out for 'Doctor Strange'.\n";
	  break;
   case 3:clrscr();
	  if(left3>0)
	   {
	    do
	    {
	     if(repetition==0)
	     {
	      if(f==0)
	       cout<<"\t\t\t\tMOVIE TICKET BOOKING\n\n";
	      for(i=0,count=0,a=1,b=1;i<10;i++)
	      {
	      for(j=0;j<10;j++)
		{
		if(v[i][j]==3)
		 cout<<"   "<<a++;
		else if(v[i][j]==2)
		 cout<<endl<<b++;
		else if(v[i][j]==1)
		 cout<<"   "<<x;
		else if(v[i][j]==0)
		 cout<<"   "<<u;
	       }
	    }
	   if(left3<81)
	    cout<<"\nThere are "<<left3<<" seats remaining !";
	   if(f==0)
	    {
	     cout<<"\nEnter the number of seats required : "<<endl;
	     cin>>n;
	    }
	  else
	   {
	    n=f;
	    cout<<endl;
	   }
	  if(n>0)
	   {
	     cout<<"(Enter the row number first, then enter the column number.)"<<endl<<"Eg:44,55,etc."<<endl;
	     cout<<"Enter the locations of the seats required : "<<endl;
	     for(i=0;i<n;i++)
	       cin>>m[i];
	     for(i=0;i<n;i++)
	       {
		loc[k].r[i]=row(m[i]);
		loc[k].g[i]=column(m[i]);
	       }
	   }
	  for(d=0,h=0,f=0;d<n;d++)
	    {
	     for(i=0;i<10;i++)
	       {
		for(j=0;j<10;j++)
		  {
		    if((loc[k].r[d]==i)&&(loc[k].g[d]==j))
		     {
		      if(v[i][j]==1)
		       {
			clrscr();
			h=1;
		       }
		      else if((i==0)||(j==0))
		      {
		       clrscr();
		       h=1;
		      }
		    }
		  }
	       }
	    }
	  if(h==1)
	   cout<<"\t\t\t\tMOVIE TICKET BOOKING\n\n";
	  for(d=0,f=0;d<n;d++)
	    {
	      for(i=0;i<10;i++)
	       {
		for(j=0;j<10;j++)
		  {
		   if((loc[k].r[d]==i)&&(loc[k].g[d]==j))
		    {
		     if(v[i][j]==1)
		      {
		       cout<<"The location "<<m[d]<<" is already selected.\n";
		       h=1;
		       f++;
		      }
		     else if((i>0)&&(j>0))
		      {
		       v[i][j]=1;
		       if(i>7)
			cost+=35;
		       else
			cost+=25 ;
		      }
		     else
		      {
		       f++;
		       h=1;
		       cout<<"The location "<<m[d]<<" is invalid. \n";
		      }
		    }
		  }
	       }
	    }
	  if(h==0)
	   clrscr();
	  rep=2;
	  if(h==1)
	   cout<<"Please select "<<f<<" other locations.\n\n";
	  else
	   {
	    if(left3>0)
	     {
	      do
	      {
	       cout<<"\t\t\t\tMOVIE TICKET BOOKING\n\n";
	       for(i=0,a=1,b=1;i<10;i++)
		 {
		  for(j=0;j<10;j++)
		    {
		     if(v[i][j]==3)
		      cout<<"   "<<a++;
		     else if(v[i][j]==2)
		      cout<<endl<<b++;
		     else if(v[i][j]==1)
		      {
		       cout<<"   "<<x;
		       if(rep==2)
			{
			 left3--;
			 count++;
			}
		      }
		     else if(v[i][j]==0)
		      cout<<"   "<<u;
		    }
		 }
	       sum=count;
	       if(f==0)
		{
		 if(cost>0)
		  cout<<"\nThe total cost is "<<cost;
		 else
		  cout<<"\nYou have selected no seats.";
		 cout<<"\nDo you wish to exit? \nIf yes, press (Y), else press (N). \nEnter your choice : \n";
		 gets(choice);
		}
	       if(strcmpi(choice,"y")==0)
		{
		 repetition=1;
		 count=81;
		 rep=0;
		 cost=0;
		 end=1;
		}
	       else if(strcmpi(choice,"n")==0)
		{
		 count=81;
		 sum+=count;
		 rep=0;
		 cost=0;
		 repetition=1;
		}
	       else
		rep=1;
	       clrscr();
	       }while(rep!=0);
	      }
	     }
	    }
	   }while(count<81);
	  }
	  else
	   cout<<"We are booked out for 'Spiderman:Homecoming'.";
	  break;
   default:clrscr();
	   do
	   {
	    cout<<"Invalid Entry.\n";
	    cout<<"Do you select again?\n";
	    cout<<"Please enter (Y) for Yes, and (N) for No.\n";
	    gets(selection);
	    if(strcmpi(selection,"y")==0)
	     {
	      end=0;
	      rep=1;
	     }
	    else if(strcmpi(selection,"n")==0)
	     {
	      end=1;
	      rep=1;
	     }
	    else
	     rep=0;
	    clrscr();
	   }while(rep!=1);
	   break;
  }
 }while(end!=1);
 getch();
}

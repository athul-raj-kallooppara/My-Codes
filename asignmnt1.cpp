#include<iostream>
#include<cstdlib>
#include<vector>
#include<cmath>
#include<termios.h>
#include<unistd.h>
#include<stdio.h>

using namespace std;

int getch(void)
{
	struct termios oldt, newt;
	int ch;
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~( ICANON | ECHO );
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return ch;
}

int bin_val(int n, int i)
{
  n=n>>i;
  n=n&1;
  return n;
}

int indice(int x)
{
  int i=0,p;
  if(x!=0)
  {
    p=x&1;
    while(p==0)
    {
      i++;
      p=bin_val(x,1);
      x=x>>1;
    }
    return i;
  }
  else
  {
    cout<<"There is no 1 in ZERO.\n\n";
    exit(0);
  }
}

int ham(int x)
{
  int count=0,p,q=32;
  while(q--)
  {
    p=x&1;
    if(p==1)
    {
      count++;
    }
    x=x>>1;
  }
  return count;
}

int ham2()
{
  int k,hm=0,n,i=0,power;
	vector<int> ui;
  cout<<"Enter the value of 'm'  :";
  cin>>n;
  power=pow(2,n);
  cout<<"Enter the function values below.\n";
	while(i<power)
	{
    cin>>k;
		ui.push_back(k);
		if(k!=0)
		{
			hm+=1;
		}
    i++;
	}
	return hm;
}

int hmds()
{
  int i,k,k1,hm=0,sum,power;
  vector<int> ui;
  vector<int> u2;
  cout<<"Enter the value of 'm'  :";
  cin>>k1;
  power=pow(2,k1);
  cout<<"\n\nFirst table\n\n***********\n\n";
  for(i=0;i<power;i++)
  {
    cin>>k;
    ui.push_back(k);
  }
  cout<<"\n\nSecond table\n\n************\n\n";
  for(i=0;i<power;i++)
  {
    cin>>k;
    u2.push_back(k);
    sum=pow(ui[i],u2[i]);
    if(sum!=0)
    {
      hm+=1;
    }
  }
  return hm;
}

int is_balanced(vector<int>& funct)
{
	int k,c1=0,c2=0;
	k=funct.size();
	for(int i=0;i<k;i++)
	{
		if(funct[i]!=0)
			c1+=1;
		else
			c2+=1;
	}
	if(c1==c2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int scalar_pdt()
{
  vector<int> a;
  vector<int> b;
  int n,k,scalar=0,i,power;
  cout<<"Enter the value of 'm'  :";
  cin>>n;
  power=pow(2,n);
  cout<<"Enter the first vector 'a'  :";
  for(i=0;i<power;i++)
  {
    cin>>k;
    a.push_back(k);
  }
  cout<<"Enter the Second vector 'x' :";
  for(i=0;i<power;i++)
  {
    cin>>k;
    b.push_back(k);
    scalar+=a[i]*b[i];
  }
  return scalar;
}

int sign(int e)
{
  if(e%2==0)
    return 1;
  else
    return -1;
}

int walsh()
{
  vector<int> f;
  int i,sp,m,po,k,w=0,sgn;
  cout<<"\nEnter the value of m :";
  cin>>m;
  po=pow(2,m);
  cout<<"\nEnter the function f(x) :";
  for(i=0;i<po;i++)
  {
    cin>>k;
    f.push_back(k);
  }
  cout<<"Finding the Scalar Product.\n**************************\n\n";
  sp=scalar_pdt();
  for(i=0;i<po;i++)
  {
    sgn=f[i]+sp;
    w+=sign(sgn);
  }
  return w;
}

int fast_walsh_transform(int f[],int limit,int m)
{
  int temp,lim1,lim2;
  for(int i=0;i<limit;i++)
    f[i]=sign(f[i]);
  while(m--)
  {
    lim1=pow(2,m);
    for(int i=0;i<limit;i=i+2*lim1)
    {
	     lim2=i+lim1;
	      for(int j=i;j<lim2;j++)
        {
		        temp=f[j]+f[j+lim1];
		        f[j+lim1]=f[j]-f[j+lim1];
		        f[j]=temp;
        }
    }
  }
}

int nonlineraity(int f[],int limit)
{
  int max=abs(f[0]);
  for(int i=1;i<limit;i++)
    if(abs(f[i])>max)
      max=abs(f[i]);
  return max;
}

int monomial_degree(int M)
{
  int r = ham(M);
  return r;
}

int  monomial_eval(int M, int x)
{
  if ( ham(M&x) >= ham(M) )
	 return 1;
	return 0;
}

int degree_ANF(int A[],int n)
{
  int max=0,x;
  for (int i=0;i<n;i++)
  {
		if ( A[i]&1)
    {
      x = monomial_degree (i);
			if ( max < x)
				max = x;
		}
	}
	return max;
}

int  ANF_eval (int A[], int x, int n)
{
	int output;
	for (int i= 0;i<n;i++ )
   {
		if ( A[i])
			output=pow(output,monomial_eval(i,x));
			//output ^= monomial_eval(i,x);
	}
	return output;
}


int main()
{
  int n,i,value,cs;
	char check;
	do
	{
  system("clear");
  cout<<"Give 1 for reading a bit in a position.\nGive 2 for finding the indice of first non-zero digit.\nGive 3 to find the Hamming weight.\n";
  cout<<"Give 4 to find Hamming weight from truth table.\nGive 5 to find hamming distance of two functions.\n";
  cout<<"Give 6 to find whether a function is balanced or not.\nGive 7 to find the Scalar Product.\nGive 8 to do the Sign Function\n";
  cout<<"Give 9 to find the walsh transform.\nGive 10 to perform fast walsh.   \nGive 11 to find non-linearity of a function.\nGive 12 to compute the degree of a monoomial.";
	cout<<"\nGive 13 to compute degree between two monomials.\nGive 14 to compute Algebraic Normal Form.\nGive 15 to compute ANF_eval(A,x)";
	cout<<"\n\nPress Enter to continue...";
  getch();
  cout<<"  \n\n>>>";
  cin>>cs;
	system("clear");
  if(cs==1){
    cout<<"Enter the integer  :";
    cin>>n;
    cout<<"Enter the position :";
    cin>>i;
    value=bin_val(n,i);
    cout<<value<<" is in position\n\n";
  }
  else if(cs==2)
  {
    cout<<"Enter the integer  :";
    cin>>n;
    value=indice(n);
    cout<<"The indice of 1st non-zero bit is   :"<<value<<"\n\n";
  }
  else if(cs==3)
  {
    cout<<"Enter the integer  :";
    cin>>n;
    value=ham(n);
    cout<<"Hamming weight  :"<<value<<"\n\n";
  }
  else if(cs==4)
  {
    value=ham2();
    cout<<"\n\nThe Hamming weight is  :"<<value;
  	cout<<"\n\n";
  }
  else if(cs==5)
  {
    value=hmds();
    cout<<"\n\nHamming Distance  :"<<value<<"\n\n";
  }
  else if(cs==6)
  {
    int k,n,i=0;
  	vector<int> ui;
  	cout<<"\n\nEnter the table size  :";
    cin>>n;
    cout<<"Enter the table below.\n";
  	while(i<n)
  	{
      cin>>k;
  		ui.push_back(k);
      i++;
  	}
  	value=is_balanced(ui);
    if(value==1)
    {
      cout<<"\n\nFunction is Balanced.\n\n";
    }
    else
    {
      cout<<"\n\nFunction is Unbalanced.\n\n";
    }
  }
  else if(cs==7)
  {
    value=scalar_pdt();
    cout<<"\nThe scalar product is  :"<<value<<"\n\n";
  }
  else if(cs==8)
  {
    cout<<"Enter the value of 'e'  :";
    cin>>n;
    value=sign(n);
    cout<<"The sign function result is :"<<value<<"\n\n";
  }
  else if(cs==9)
  {
    value=walsh();
    cout<<"The walsh tranform value is :"<<value<<"\n\n";
  }
  else if(cs==10)
  {
    int m,count=0;
      cout<<"\nEnter the value of m of array length 2^m :";
      cin>>m;
      int f[1000],limit=pow(2,m);
      cout<<"Enter the elements of F1 [0 or 1]:\n";
      for(int i=0;i<limit;i++)
      {
        cin>>f[i];
        if(f[i]!=0 && f[i]!=1)
        {
          cout<<"Invalid Input  enter [0 or 1]:\n";
          i--;
        }
      }
      fast_walsh_transform(f,limit,m);
      for (int  i = 0; i < limit; i++ )
        cout<<" "<<f[i];
      cout<<endl;
      getch();
  }
  else if (cs==11) {
      int m,count=0;
      cout<<"\nEnter the value of m of array length 2^m :";
      cin>>m;
      int f[1000],limit=pow(2,m);
      cout<<"Enter the elements of F1 [0 or 1]:\n";
      for(int i=0;i<limit;i++)
      {
        cin>>f[i];
        if(f[i]!=0 && f[i]!=1)
        {
          cout<<"Invalid Input  enter [0 or 1]:\n";
          i--;
        }
      }
      fast_walsh_transform(f,limit,m);
      cout<<"\n\nThe nonlinearity of a Boolean function f is equal to "<<nonlineraity(f,limit)<<"\n\n\n";
      getch();
  }
  else if(cs==12)
  {
    unsigned int M;
     cout<<"Enter the monomial:";
     cin>>M;
     cout<<"The monomial degree is :"<<monomial_degree(M)<<"\n\n";
		 getch();
  }
	else if(cs==13)
	{
 		 unsigned int M,x;
		 cout<<"Enter the monomial:";
		 cin>>M;
		 cout<<"Enter the monomial:";
		 cin>>x;
		 if (monomial_eval (M, x))
			 cout<<x<<" is a variable of the given monomial "<<M<<endl;
		 else
			 cout<<x<<" is a variable of the given monomial "<<M<<endl;
	}
	else if(cs==14)
	{
	  	unsigned int n;
      cout<<"Enter the number of elements:";
      cin>>n;
      cout<<"Enter the elements [0 or 1]:\n";
      int f[n];
      for(int i=0;i<n;i++)
      {
        cin>>f[i];
        if(f[i]!=0 && f[i]!=1)
        {
          cout<<"Invalid Input  enter [0 or 1]:\n";
          i--;
        }
      }
      cout<<"The ANF of given binary function is :"<< degree_ANF(f,n)<<endl;
	}
	else if(cs==15)
	{
	  	unsigned int n;
      cout<<"Enter the number of elements:";
      cin>>n;
      cout<<"Enter the elements [0 or 1]:\n";
      int f[n];
      for(int i=0;i<n;i++)
      {
        cin>>f[i];
        if(f[i]!=0 && f[i]!=1)
        {
          cout<<"Invalid Input  enter [0 or 1]:\n";
          i--;
        }
      }
      cout<<"The ANF of given binary function is :"<< degree_ANF(f,n)<<endl;
	}
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nDo you want to continue...(y/n)";
	cin>>check;
	getch();
  }while(check=='y'||check=='Y');
	system("clear");
  return 0;
}

#include<iostream>
#include<string>

using namespace std;

int mult(int num1,int mod)
{
	int num2, temp;
	int  x = 0, y = 1, lastx = 1, lasty = 0, flag = 0;
	num2 = mod;
	while (num2 != 0) 
	{ 
		int quotient, remainder;
		quotient = num1 / num2;
		remainder = num1 % num2;
		num1 = num2;
		num2 = remainder;
		temp = x;
		x = lastx - quotient * x;  
		lastx = temp;
		temp = y;
		y = lasty - quotient * y;
		lasty=temp;
	}
	if(flag == 1)
	{
		temp = lastx;
		lastx = lasty;
		lasty = temp;
	}
	if(lastx < 0)
	{
		lastx = mod + lastx;
	}
	if(num1 != 1)
	{
		cout<<"Multiplicative Inverse doesn't Exist";
	}
	else 
	{
		return lastx;
	}
}

int solve(int a1,int a2, int b1, int b2, int &a, int &b)
{
	int inv,t;
	//a1=l-97;
	//a2=l2-97;
	//cout<<a1<<"  "<<a2<<"\n\n";
	inv=mult((b2-b1),26);
	int a3=a2-a1;
	if(a3<0)
	{
		a3=a3+26;
	}	
	t=(a3*inv)%26;
	if((t==1)||(t==3)||(t==5)||(t==7)||(t==9)||(t==11)||(t==15)||(t==17)||(t==19)||(t==21)||(t==23)||(t==25))
	{
		a=t;
		b=a1-(b1*a);
		b=b%26;
		if(b<0)
			b+=26;
		return 1;
	}
	else
	{
		cout<<"not possible\n";
		return -1;
	}
}
char affine(char text,int a, int b)
{
	char ctext; 
	int p,q;
	if((text>='a')&&(text<='z'))
	{
		a=mult(a,26);
		p=text-97;
		q=a*(p-b);
		q=q%26;
		if(q<0)
			q+=26;
		q=q+97;
		ctext=q;
		return ctext;
	}
	else
		return text;
	/*for(i=0;i<len;i++)
	{
		cout<<ctext[i];
	}*/
	cout<<"\n\n";
}
int main()
{
	string ctext[500],text;
	char bc,t[26],l,l2,check;
	int j,len,count,i,n[26],lrg,lrg2,a=0,b=0,flag=0;
	cout<<"\nEnter the message  :";
	getline(cin,text);
	len=text.length();
	for(i=97;i<123;i++)
	{
		count=0;
		bc=i;
		for(j=0;j<len;j++)
		{
			if(text[j]==bc)
			{
				count+=1;
			}
		}
		n[i-97]=count;
		t[i-97]=i;
	}
	for(i=0;i<26;i++)
	{
		cout<<t[i]<<"  : "<<n[i]<<"\n";
	}
	//Finding largest counted alphabet
	lrg=n[0];
	lrg2=n[0];
	l=t[0];
	l2=t[0];
	for(i=1;i<26;i++)
	{
		if(n[i]>lrg)
		{
			lrg2=lrg;
			lrg=n[i];
			l2=l;
			l=t[i];
		}
	}
	cout<<"\n"<<lrg<<"  "<<lrg2<<"\n"<<l<<"  "<<l2<<"\n\n";
	do
	{
	flag=0;
	int ret;
	char c1,c2;
	cout<<"Choose the alphbets correspond to e and t :";
	cin>>c1>>c2;	
	a=0;
	b=0;
	ret=solve(c1-97,c2-97,4,19,a,b);
	//ret=solve(22,5,4,19,a,b);
	if(ret==-1)
	{
		flag =1;
		cout<<"Cannot solve.\n";
	}
	else
	{
		cout<<a<<"  "<<b<<"\n\n";
	}
	if(flag==0)
	{
	for(i=0;i<len;i++)
	{
		ctext[i]=affine(text[i],a,b);
	}
	for(i=0;i<len;i++)
	{
		cout<<ctext[i];
	}	
	}
	cout<<"\n\n";
	cout<<"Continue(y/n)";
	cin>>check;
	}while(check=='y');
	return 0;
}

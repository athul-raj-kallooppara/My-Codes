#include<iostream>

using namespace std;

int main()
{
  float w[100],p[100],r[100],max,temp,sum=0,price=0,c,rem,tot=0,ratio;
  int j,i,n,mem;
  cout<<"Enter the total capacity  :";
  cin>>max;
  cout<<"Enter the number of elements   :";
  cin>>n;
  cout<<"\nEnter the weight :";
  for(i=0;i<n;i++){
    cin>>w[i];
  }
  cout<<"\nEnter the price :";
  for(i=0;i<n;i++)
  {
    cin>>p[i];
    r[i]=p[i]/w[i];
  }
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(r[i]<r[j])
      {
        temp=r[i];
        r[i]=r[j];
        r[j]=temp;
        temp=w[i];
        w[i]=w[j];
        w[j]=temp;
        temp=p[i];
        p[i]=p[j];
        p[j]=temp;
      }
    }
  }
  for(i=0;i<n;i++)
  {
    if(sum<=max)
    {
      sum+=w[i];
      mem=i;
      tot=tot+p[i];
    }
    else
    {
      break;
    }
  }
  c=sum-max;
  rem=w[mem]-c;
  ratio=rem/w[mem];
  tot=tot-p[mem]+(p[mem]*ratio);
  cout<<"\n\nOnly "<<rem<<" is taken from the weight "<<w[mem];
  cout<<"\n\nThe profit is  :"<<tot<<"\n\n";
  return 0;
}

#include<bits/stdc++.h>
 
using namespace std;

struct node {
	int number;
	int index;
	int place;
} temp[1000],temp2[1000];

void merge(int min, int mid, int max)
{
	int l1=min;
	int l2=mid+1;

	int i;
	for(i=min; l1<=mid && l2<=max; i++)
	{
		if(temp[l1].number > temp[l2].number)
		{
//			temp2[i].number = temp[l2].number;
//			temp2[i].place = temp[l2].place;
//			temp2[i].index = temp[l2++].index;
			temp2[i] = temp[l2++];
		}
		else
		{
//			temp2[i].number = temp[l1].number;
//			temp2[i].place = temp[l1].place;
//		        temp2[i].index = temp[l1++].index;
                      temp2[i] = temp[l1++];
		}

	}

	while(l1<=mid)
	{
//		   temp2[i].number = temp[l1].number;
//		   temp2[i].place = temp[l1].place;
//	           temp2[i++].index = temp[l1++].index;
                 temp2[i++] = temp[l1++];
         }

	while(l2<=max)
	{
//                   temp2[i].number = temp[l2].number;
//		   temp2[i].place = temp[l2].place;
//		   temp2[i++].index = temp[l2++].index;
                 temp2[i++] = temp[l2++];
	}

	for(i=min;i<=max;i++)
		temp[i] = temp2[i];
}




void sort(int min, int max)
{
	if(min < max)
	{
		sort(min, (min+max)/2);
		sort(((min+max)/2)+1, max);
		merge(min, (min+max)/2, max);
	}
	else
		return;
}

void print(int ini, int fin)
{
	int i;
	for(i=ini; i<fin; i++)
	{
		cout << temp[i].number << " 	";
		cout << temp[i].index << "	" << temp[i].place;
		cout << endl;
	}
}


int main()
{
	int q;
	cin >> q;
	while(q--)
	{
          int n,x,y;
	  cin >> n >> x >> y;
	  int a[1000],b[1000];
	  int i;
	  for(i=0; i<n ;i++)
		cin >> a[i];

	  for(i=0;i<n;i++)
		  cin >> b[i];

	 int min;

	 if(x>y)
		 min = y;
	 else
		 min = x;

	 int negative = 0;
	 int positive = 0;

	 for(i=0; i<n;i++)
	 {
		 temp[i].number = a[i]-b[i];
		 temp[i].index = i;
//		 temp[i].place = 0;

		 if(temp[i].number < 0)
		 {
			 temp[i].place = 2;
			 negative++;
		 }
		 else
		 {
			 temp[i].place = 1;
			 positive++;
		}
	}

	 sort(0,n-1);

//         print(0,n);

	 i=0;

	 if( y<negative)
	 {
            while( negative > y )
	    {
		    temp[i].place = 1;
		    negative--;
		    i++;
	    }

//	    while(y--)
//	    {
//		    temp[i].place = 2;
//	    }
	 }

	 if( x < positive)
	 {
		 while( positive > x)
		 {
			 if(temp[i].number >= 0)
			{
			 temp[i].place = 2;
			 positive--;
			}
			 i++;
		 }
	 }

	 int tip = 0;
	 print(0,n);

        for(i=0;i<n;i++)
	{
		if(temp[i].place == 1)
			tip = tip + a[temp[i].index];
		else
			tip =tip +b[temp[i].index];
	}

	cout << tip << endl;

  }

return 0;
}
	


	  
	


#include<stdio.h>
typedef struct
{
	int x1 ;
	int x2 ;
	int y1 ;
	int y2 ;
}P ;
#define LEN 4

int getMaxValue(int a[], int len , int *x , int *y)
{
	int b = 0;
	int i , sum=0 ;
	for ( i = 0 ; i < len ; i++)
	{
		if( b > 0)
			b+=a[i] ;
		else
		{
			b=a[i] ;
			*x = i ; //记录起点
		}
		if (b > sum)
		{
			sum = b ;
			*y = i ;//记录终点
		}
	}
	return sum ;
}

int getMaxValue2(int a[][LEN] , int len2 , P *p )
{
	int i ,j ;
	int sum = 0 ;
	int b =0 ;
	int x,y ;
	int k = 0 ;
	for ( i = 1 ; i < len2 ; ++i)
	{
		for ( j = 0 ; j < LEN ;++j )
		{
			a[i][j] += a[i-1][j] ;
		}
	}
	for (i = 0 ; i < len2 ; ++i )
	{
		for (j = 0 ; j <=i ; ++j)
		{
			for ( k = 0 ; k < LEN ; ++k)
			{
				if(i != 0)
				   a[i][k]-=a[j][k] ;
				else
					break ;
			}
			b= getMaxValue(a[i] , LEN , &x , &y);
			if(b > sum)
			{
				sum = b ;
				if (i == 0)
				{
					p->x1 = 0;
					p->x2 = 0;
					p->y1 = x ;
					p->y2 = y ;
				}
				else
				{
					p->y2 = y ;
					p->x2 = i ;
					p->y1 = x ;
					p->x1 = j+1 ;
				}
			}
		}
	}
	return sum ;
}

int main()
{
	int a[4][4]={{0,-2,-7,0},{9,2,-6,2},{-4,1,-4,1},{-1 , 8 ,0 ,-2}};
	P p ;
	printf("%d\n",getMaxValue2(a,4,&p));
	printf("x:%d y:%d x1:%d y1:%d\n",p.x1,p.y1,p.x2,p.y2);
	return 0 ;
}



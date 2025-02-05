/*
Ex no.2) Sparse Matrix
65) Sreelakshmi K
Date: 22/11/23
*/

#include <stdio.h>

#define MAXTERM 101

typedef struct
{
	int row;
	int col;
	int value;
	
}term;

term s1[MAXTERM],s2[MAXTERM],t1[MAXTERM],t2[MAXTERM],sum[MAXTERM];



void readMatrix(int a[][10],int m,int n)
{
	int i,j;

	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			scanf("%d",&a[i][j]);
}

void toTuple(int a[][10],int m,int n,term s[])
{
	int i,j,k = 1;
	for(i = 0; i < m; i++)
        {
	        for(j = 0; j < n; j++)
		{
			if(a[i][j] != 0)
			{
				s[k].row = i;
				s[k].col = j;
				s[k].value = a[i][j];
				k++;
			}
		}
	}

	s[0].row = m;
	s[0].col = n;
        s[0].value = k - 1;

	

}

void Sum(term a[],term b[],term sum[])
{
	int i = 1,j = 1,k = 1;

	sum[0].row = a[0].row;
        sum[0].col = a[0].col;


	while(i <= a[0].value && j <= b[0].value)
	{
		if(a[i].row == b[j].row)
		{
			if(a[i].col == b[j].col)
			{
				sum[k].row = a[i].row;
				sum[k].col = a[i].col;
				sum[k].value = a[i].value + b[j].value;
				i++; j++; k++;
			}
			else if(a[i].col < b[j].col)
                        { 
                                sum[k].row = a[i].row;
                                sum[k].col = a[i].col;
                                sum[k].value = a[i].value;
                                i++; k++;
                        }
			else
                        { 
                                sum[k].row = b[j].row;
                                sum[k].col = b[j].col;
                                sum[k].value = b[j].value;
                                j++; k++;
                        }


		}
		else if(a[i].row < b[j].row)
                {
                        sum[k].row = a[i].row;
                        sum[k].col = a[i].col;
                        sum[k].value = a[i].value;
                        i++; k++;
                }
		else
		{
			sum[k].row = b[j].row;
                        sum[k].col = b[j].col;
                        sum[k].value = b[j].value;
                        j++; k++;

		}

	}

	for(i; i <= a[0].value; i++)
	{
		sum[k].row = a[i].row;
                sum[k].col = a[i].col;
                sum[k].value = a[i].value;
                k++;
	}

	for(j; j <= b[0].value; j++)
        { 
                sum[k].row = b[j].row;
                sum[k].col = b[j].col;
                sum[k].value = b[j].value;
                k++;
        }

	sum[0].value = k - 1;

}

void transpose(term s[],term t[])
{
	int i,j,k = 1;

	t[0].row = s[0].col;
	t[0].col = s[0].row;
	t[0].value = s[0].value;
	

	for(i = 0; i < s[0].col; i++)
	{
		for(j = 0; j <= s[0].value; j++)
		{
			if(s[j].col == i)
			{
				t[k].row = s[j].col;
				t[k].col = s[j].row;
				t[k].value = s[j].value;
				k++;
			}	
		}
	}
}

void printTuple(term s[])
{
	int i;
	for(i = 0; i <= s[0].value;i++)
	{
		printf("%d  %d  %d\n",s[i].row,s[i].col,s[i].value);
	}
}

int main()
{
	int a[10][10],b[10][10],m,n,p,q;

	printf("Enter two matrices of same order\n");

	printf("Enter the order of Matrix A: ");
	scanf("%d%d",&m,&n);

	printf("Enter the order of Matrix B: ");
        scanf("%d%d",&p,&q);

	if(m != p || n != q)
		printf("The order is different\n");
	else
	{
		printf("Enter elements of A:\n");
		readMatrix(a,m,n);
		printf("Enter elements of B:\n");
		readMatrix(b,m,n);

		toTuple(a,m,n,s1);
		toTuple(b,m,n,s2);

		printf("Tuple form of A:\n");
		printTuple(s1);

		printf("Tuple form of B:\n");
                printTuple(s2);
		
		Sum(s1,s2,sum);
		printf("Sum of A & B in Tuple form:\n");
                printTuple(sum);

		printf("Tuple form of transpose of  A:\n");
		transpose(s1,t1);
                printTuple(t1);

		printf("Tuple form of transpose of  B:\n");
		transpose(s2,t2);
                printTuple(t2);

	}

}

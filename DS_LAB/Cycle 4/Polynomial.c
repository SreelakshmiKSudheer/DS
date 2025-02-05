/*
Ex no.1) Polynomial using arrays
65) Sreelakshmi K
Date: 13/11/23
*/


#include <stdio.h>

typedef struct 
{
	float coeff;
	int exp;
}Poly;

Poly P[10],Q[10],R[20];

void get_poly(Poly *p,int *n)
{
	int i = 0;
	printf("Enter a polynomial expression as mentioned below\n");
	printf("How many terms? ");
	scanf("%d",n);

	printf("Enter the coeffient <space> exponent:");
	for(i = 0; i < *n; i++)
	{
		scanf("%f %d",&(p[i].coeff),&(p[i].exp));
	}
	
}

void display_poly(Poly *p,int n)
{
	int i = 0;

	for(i = 0; i < n; i++)
	{
		printf("%.2fx^%d ",p[i].coeff,p[i].exp);
		if(I < n-1)
			printf(" + ");
	}
	printf("\n");

}

void add_poly(Poly *p,Poly *q,Poly *r,int pn,int qn,int *rn)
{
	int i = 0,j = 0,k = 0;

	while(i < pn && j < qn)
	{
		if(p[i].exp == q[j].exp)
		{
			r[k].exp = p[i].exp;
			r[k].coeff = p[i].coeff + q[j].coeff;
			i++; 
			j++; 
			k++;
		}
		else if(p[i].exp > q[j].exp)
		{
			r[k].exp = p[i].exp;
                        r[k++].coeff = p[i++].coeff;
		}
		else
		{ 
                        r[k].exp = q[j].exp;
                        r[k++].coeff = q[j++].coeff;
                }

	}
	if(i < pn)
	{
		r[k].exp = p[i].exp;
                r[k++].coeff = p[i++].coeff;
	}
	if(j < qn)
	{
		r[k].exp = q[j].exp;
                r[k++].coeff = q[j++].coeff;

	}
	*rn = k;
}

int main()
{
	int pn,qn,rn;

	get_poly(P,&pn);
        get_poly(Q,&qn);

	printf("Input polynomials are:\n");
	display_poly(P,pn);
        display_poly(Q,qn);

	printf("Sum of the polynomials is:\n");
	add_poly(P,Q,R,pn,qn,&rn);
        display_poly(R,rn);

}

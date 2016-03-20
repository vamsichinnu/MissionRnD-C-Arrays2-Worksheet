/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<stdlib.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int check(struct transaction *A, struct transaction *B, int p, int q)
{
	int i, temp;
	for (i = 6; A[p].date[i] != '\0'; i++)
	{
		if (A[p].date[i] == B[q].date[i])
		{
			temp = 1;
		}
		else if (A[p].date[i] >B[q].date[i])
		{
			temp = 0;
			break;
		}
		else
		{
			temp = -1;
			break;
		}
	}
	if (temp == 1)
	{
		if (A[p].date[3] * 10 + A[p].date[4] == (B[q].date[3] * 10) + B[q].date[4])
		{
			temp = 1;
		}
		else if (A[p].date[3] * 10 + A[p].date[4] > (B[q].date[3] * 10) + B[q].date[4])
		{
			temp = 0;
		}
		else
		{
			temp = -1;
		}
	}
	if (temp == 1)
	{
		if (A[p].date[0] * 10 + A[p].date[1] == (B[q].date[0] * 10) + B[q].date[1])
		{
			temp = 1;
		}
		else if (A[p].date[0] * 10 + A[p].date[1] > (B[q].date[0] * 10) + B[q].date[1])
		{
			temp = 0;
		}
		else
		{
			temp = -1;
		}
	}
	return temp;
}

struct transaction *mergeSortedArrays(struct  transaction *A, int ALen, struct  transaction *B, int BLen){

	int i = 0, j = 0, temp, k = 0;
	struct transaction *temp1;
	if (A&&B&&ALen>0 && BLen>0)
	{
		temp1 = (struct transaction *)malloc((ALen + BLen)*sizeof(struct transaction));
		for (k = 0; k< (ALen + BLen); k++)
		{
			if (i<ALen&&j<BLen)
			{
				temp = check(A, B, i, j);
				if (temp == 0)
				{
					temp1[k] = B[j];
					j++;
				}
				else
				{
					temp1[k] = A[i];
					i++;
				}
			}
			else
			{
				break;
			}
		}
		if (j <BLen)
		{
			while (j != BLen)
			{

				temp1[k] = B[j];
				k++;
				j++;
			}
		}
		else
		{
			while (i != ALen)
			{
				temp1[k] = A[i];
				k++;
				i++;
			}
		}
	}
	else{
		return NULL;
	}
	return temp1;
}
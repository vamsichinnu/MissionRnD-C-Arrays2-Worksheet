/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/


#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int check(struct transaction *A, struct transaction *B, int ALen, int BLen, int i, int j)

{
	int k, temp;
	for (k = 6; A[i].date[k] != '\0'; k++)
	{
		if (A[i].date[k] == B[i].date[k])
		{
			temp = 1;
		}
		else if (A[i].date[k] > B[i].date[k])
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}
	if (temp == 1)
	{
		if (A[i].date[3] * 10 + A[i].date[4] == (B[i].date[3] * 10) + B[i].date[4])
		{
			temp = 1;
		}
		else if (A[i].date[3] * 10 + A[i].date[4]>(B[i].date[3] * 10) + B[i].date[4])
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}
	if (temp == 1)
	{
		if (A[i].date[0] * 10 + A[i].date[1] == (B[i].date[0] * 10) + B[i].date[1])
		{
			return 1;
		}
		else if (A[i].date[0] * 10 + A[i].date[1]> (B[i].date[0] * 10) + B[i].date[1])
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}
}
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i, j = 0, count = 0;
	struct transaction  *res = NULL;
	res = (struct transaction *)malloc(sizeof(struct transaction) * 0);
	if (A&&B&&ALen > 0 && BLen > 0)
	{
		for (i = 0; i < ALen; i++)
		{
			if (j >= BLen)
			{
				break;
			}
			if (check(A, B, ALen, BLen, i, j) == 1)
			{
				res = (struct transaction *)realloc(res, sizeof(struct transaction)*(count + 1));
				res[count] = A[i];
				printf("%s\n", res[count].date);
				count++;
				j++;
			}
			else if (check(A, B, ALen, BLen, i, j) == 0)
			{
				j++;
			}
		}
		if (count == 0)
		{
			return NULL;
		}

	}
	else
	{
		return NULL;
	}
	return res;
}
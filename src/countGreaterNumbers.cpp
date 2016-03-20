/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int positioncheck(struct transaction *Arr, char *date, int mid)
{
	int i, temp = 0;
	for (i = 6; date[i] != '\0'; i++)
	{
		if (date[i] == Arr[mid].date[i])
		{
			temp = 1;
		}
		else if (date[i] > Arr[mid].date[i])
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
		if (date[3] * 10 + date[4] == (Arr[mid].date[3] * 10) + Arr[mid].date[4])
		{
			temp = 1;
		}
		else if (date[3] * 10 + date[4] > (Arr[mid].date[3] * 10) + Arr[mid].date[4])
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
		if (date[0] * 10 + date[1] == (Arr[mid].date[0] * 10) + Arr[mid].date[1])
		{
			temp = 1;
		}
		else if (date[0] * 10 + date[1] > (Arr[mid].date[0] * 10) + Arr[mid].date[1])
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
int binarysearch(struct transaction *Arr, int min, int max, char *date, int len)
{
	int mid, temp, i;
	mid = (min + max) / 2;
	while (min<max)
	{
		temp = positioncheck(Arr, date, mid);
		if (temp == 1)
		{
			if (positioncheck(Arr, date, mid + 1) == 1)
			{
				min = mid + 1;
				break;
			}
			else
			{
				return len - mid - 1;
			}
		}

		else if (temp == 0)
		{
			min = mid + 1;
		}
		else
		{
			max = mid - 1;
		}
		mid = (min + max) / 2;
	}

	if (min == max&&min != 0 && max != len - 1)
	{
		return len - mid - 1;
	}
	else if (min == 0)
	{
		return len;
	}
	else if (max == len - 1)
	{
		return 0;
	}

}

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {

	int p;
	if (Arr&&len>0)
	{
		p = binarysearch(Arr, 0, len - 1, date, len);
		return p;
	}
	else
	{
		return -1;
	}
}

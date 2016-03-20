/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/

void mergesort(int *arr, int min, int mid, int max)
{
	int tmp[30];
	int i, j, k, m;
	j = min;
	m = mid + 1;
	for (i = min; j <= mid && m <= max; i++)
	{
		if (arr[j] <= arr[m])
		{
			tmp[i] = arr[j];
			j++;
		}
		else
		{
			tmp[i] = arr[m];
			m++;
		}
	}
	if (j>mid)
	{
		for (k = m; k <= max; k++)
		{
			tmp[i] = arr[k];
			i++;
		}
	}
	else
	{
		for (k = j; k <= mid; k++)
		{
			tmp[i] = arr[k];
			i++;
		}
	}
	for (k = min; k <= max; k++)
		arr[k] = tmp[k];
}
void part(int *arr, int min, int max)
{
	int mid;
	if (min<max)
	{
		mid = (min + max) / 2;
		part(arr, min, mid);
		part(arr, mid + 1, max);
		mergesort(arr, min, mid, max);
	}
}

int findSingleOccurenceNumber(int *A, int len) {
	int i, j;
	if (len > 0 && (len % 3 == 1))
	{

		part(A, 0, len - 1);
		for (i = 0; i < len; i = i + 3)
		{
			if (A[i] != A[i + 1] && i % 3 == 0)
			{
				return A[i];
			}
		}
	}
	else
	{
		return -1;
	}
}

/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31

int* wordlength(char *str, int* len)
{/*char *str1 = "the are all is well";
 char *str2 = "is who the";
 */
	int* arr = (int*)malloc(sizeof(int) * 31);
	int i, length = 0, j = 1, start = 0;
	arr[0] = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (i == 0 && str[i] == 32){
			i++;
			arr[0] = 1;
		}

		if (str[i] == 32)
		{
			arr[j] = i - 1;
			j++;

			arr[j] = i + 1;
			j++;

		}
		length++;
	}
	arr[j] = length - 1;
	*len = j + 1;
	return arr;
}
char ** commonWords(char *str1, char *str2) {
	if (str1 != NULL && str2 != NULL){
		char **res;
		int* arr1;
		int* arr2;
		int len1, len2, i, lw1 = 0, lw2 = 0, j, k, m, n, p = 0, offset = 0;
		res = (char**)malloc(sizeof(char*) * 5);
		if (str1 == "       " || str2 == "       ")
			return NULL;
		else
		{
			arr1 = wordlength(str1, &len1);
			arr2 = wordlength(str2, &len2);
			for (i = 1; i<len1; i = i + 2)
			{
				lw1 = (arr1[i] - arr1[i - 1]) + 1;
				for (j = 1; j<len2; j = j + 2)
				{
					lw2 = (arr2[j] - arr2[j - 1]) + 1;
					if (lw1 == lw2)
					{
						k = 0;
						char* word = (char*)malloc(sizeof(char)*(lw1 + 1));
						m = arr1[i - 1];
						int start3 = m;
						n = arr2[j - 1];
						while (k < lw1)
						{
							if (str1[m] == str2[n])
							{
								word[k] = (char)str1[m];
								m++;
								n++;
								k++;
							}
							else
								break;
						}
						word[k] = '\0';
						if (k == lw1)
						{
							offset = 1;
							res[p] = word;
							p++;
						}
					}
				}
			}
			if (offset == 1)
				return res;
			else
				return NULL;

		}
	}
	return NULL;
}


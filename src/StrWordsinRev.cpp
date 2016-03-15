/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void strreverse(char*input, int i, int j)
{
	char temp;
	while (i < j)
	{
		temp = input[i];
		input[i] = input[j];
		input[j] = temp;
		i++;
		j--;
	}
}
void str_words_in_rev(char *input, int len){
	int a = 0, i, j,count=0;
	for (i = 0; i<len; i++)
	{
		if (input[i] == 32)
		{
			strreverse(input, a, i - 1);
			a = i + 1;
			count = 1;
		}
	}
	if (count == 1)
	{
		strreverse(input, a, len - 1);

		strreverse(input, 0, len - 1);
	}

}
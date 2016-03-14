/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/


#include<malloc.h>
#include<stdlib.h>
int calpower(int no)
{
	int i = 0, k = 10;
	for (i = 1; i<no; i++)
	{
		k = k * 10;
	}
	return k;

}

void number_to_str(float number, char *str, int afterdecimal)
{
	int offset = 0, a = 0, temp = 0, i, index = 0, size = 0, quo = 0;


	if (number < 0)
	{

		number = number*-1;
		offset = 1;
	}
	a = number;
	while (a > 0)
	{
		index++;
		a = a / 10;
	}
	a = number;
	number = number - a;
	if (afterdecimal != 0)
		temp = number*calpower(afterdecimal);

	if (temp == 0)
		size = (index + afterdecimal + offset);
	else
		size = (index + afterdecimal + offset + 1);

	//str = (char*)malloc(sizeof(char)*size);
	i = 0;

	if (offset == 1)
	{
		str[i] = '-';
		i++;

	}
	while (a > 10)
	{
		quo = a / calpower(index - 1);

		a = a%calpower(index - 1);
		str[i] = quo + 48;

		i++;

		index--;
	}
	str[i] = a + 48;



	if (afterdecimal != 0)
	{

		str[++i] = '.';

		while (temp > 10)
		{
			quo = temp / calpower(afterdecimal - 1);
			temp = temp%calpower(afterdecimal - 1);
			str[++i] = quo + 48;



			afterdecimal--;
		}
		str[++i] = temp + 48;



	}


	str[++i] = '\0';
	
}

/*****************************************************************************/
#include "monty.h"
/**
 * _strcmp - compare two strings
 *
 * @s1: string 1
 * @s2: string 2
 *
 * Return: -15 if s1 < s2, 0 if s1 == s2 and 15 if s1 > s2
 */
int _strcmp(const char *s1, const char *s2)
{
	int i, shorter, s1_sz, s2_sz, sm_sz;

	/* get the string sizes */
	s1_sz = _strlen(s1);
	s2_sz = _strlen(s2);

	/* Note the shorter string */
	if (s1_sz < s2_sz)
		shorter = 1;
	else if (s1_sz == s2_sz)
		shorter = 0;
	else
		shorter = 2;

	/* note the smaller size */
	sm_sz = (s1_sz <= s2_sz) ? s1_sz : s2_sz;

	/* scan each byte */
	for (i = 0; i < sm_sz; i++)
	{
	if (s1[i] < s2[i])
		return (s1[i] - s2[i]);
	else if (s1[i] > s2[i])
		return (s1[i] - s2[i]);
	}

	/* in case of equal scan, use shorter one */
	if (shorter == 1)
		return (-s2[i]);
	else if (shorter == 0)
		return (0);
	else if (shorter == 2)
		return (s1[i]);
	return (999);
}


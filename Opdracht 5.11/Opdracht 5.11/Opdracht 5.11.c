
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int geldig, checkid(char id[]);

	char code[13];

	printf("\nWelkom\n");

	printf("\nVoer uw identificatiecode in : ");
	scanf("%s", &code);
	getchar();

	geldig = checkid(code);

	if (geldig == 1)	{ printf("\nDe ingevoerde code is geldig\n"); }
	else				{ printf("\nOngeldige invoer\n"); }
	getchar();
}



int checkid(char code[])
{
	int teller, som = 0, uitkomst, geldig[5];

	for (teller = 1; teller <= 11; teller += 1)
	{
		if (isdigit(code[teller]))		{ geldig[0] = 1; }			//Is character 1-11 een digit
		else							{ geldig[0] = 0; break; }
	}
	if (code[0] == 80)					{ geldig[1] = 1; }			//Is character 0 een P ('P'==80 in ASCII)
	else								{ geldig[1] = 0; }
	if (code[12] == 0)					{ geldig[2] = 1; }			//Zijn er niet meer dan 12 characters
	else								{ geldig[2] = 0; }

	som = code[0];

	for (teller = 1; teller <= 11; teller += 1)
	{
		som = som + (code[teller] - 48);							//-48 omdat '0' == 48 in ASCII
	}

	uitkomst = som % 9;

	if (uitkomst == 1)					{ geldig[3] = 1; }
	else								{ geldig[3] = 0; }

	geldig[4] = geldig[0] + geldig[1] + geldig[2] + geldig[3];

	if (geldig[4] == 4)					{ return 1; }
	else
	{
		if (geldig[1] != 1)	{ printf("\nOngeldige land code !"); }
		if (geldig[0] != 1)	{ printf("\nOngeldige numerieke code !"); }
		if (geldig[2] != 1)	{ printf("\nOngeldig  aantal characters !"); }
		if (geldig[3] != 1)	{ printf("\nOngeldige modules uitkomst !"); }
		return 0;
	}
}

/*
Test waardes :	P11111111111 (11x1)	= 80 + 11 = 91			(10*9+1)
P12345678911		= 80 + 45 + 2 = 127		(14*9+1)
*/

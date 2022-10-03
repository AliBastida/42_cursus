#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "word_frame.h"

void	print_line_of_stars(int max_length)
{
	int count;

	count = 0;
	while (count < max_length + 2)
	{
		write (1, "*", 1);
		count++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	char *frase; 
	char **palabras;
	int	count;
	int tmp_length;
	int max_length;
	int needed_spaces;

	//Paso 1: Chqueamos numero de paramatreos
	if (argc != 2)
	{
		write(2, "Error: wrong num of params", 28);
		return (-1);
	}
	printf("Todo esta correcto empezamos\n");

	//Paso 2: Cojo la frase
	frase = argv[1];
	printf("%s\n", frase);
	
	//Paso3: Hago un spli de la frase
	palabras = ft_split(frase, ' ');
	count = 0;
	max_length = 0;

	//Paso 4: Buscar la longitud maxima de la palabra mas larga
	while (palabras[count])
	{
		tmp_length = 0;
		printf ("%s\n", palabras[count]);
		while (palabras[count][tmp_length])
			tmp_length++;
		printf("el length es: %d \n", tmp_length);
		if (tmp_length > max_length)
			max_length = tmp_length;
		count++;
	}
	printf("El max lenght es: %d\n", max_length);

	//Paso 5: Imprimi la linea de arriba (el max lenght + 2)
	print_line_of_stars(max_length);



	//Paso 6: Imprimir lineas con las palabras
	//con  Estrellas a los lados
	// Falta contemplar el max lenght
	// la diferencia de lo que mide cada palabra respecto a max lenght darle espacios
	count = 0;
	//int count2;
	while (palabras[count])
	{
		//count2 = 0;
		printf("*");
		printf("%s", palabras[count]);
		//aqui me falta contemplar posibles espacios
		if(ft_strlen(palabras[count]) < (size_t)max_length)
		{
			needed_spaces = max_length - ft_strlen(palabras[count]); 
			while(needed_spaces)
			{
				printf(" ");
				needed_spaces--;
			}
			
			//printf("necesito %d espacios", needed_spaces);
		}

		printf("*\n");
		count++;
	}

	//Paso Ultimo: Imprimir la linea de abajo
	print_line_of_stars(max_length);

	return (0);
}


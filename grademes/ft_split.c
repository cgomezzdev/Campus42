
//"hola   que tal" -> 3
//"hola   que tal " -> 3
//" hola   que tal" -> 3
//"       " -> 0
//"" -> 0
int contar_palabras(const char *str, char c)
{
	int count;
	int i;

	count = 0;
	i = 0;
	//contar palabras o contando inicios de palabras (En ambos casos hay una regla general, i una posible excepcion)
	// while(s[i])
	// {
	// 	if(i > 0 && s[i] != c && s[i - 1] == c)
	// 		count++;
	// 	if (i == 0 & s[i] != c)
	// 		count++;
	// 	i++;
	// }
	//contar palabras contando finales de palabras (En ambos casos hay una regla general, i una posible excepcion)
	while(s[i])
	{
		/*if(s[i] != c && s[i + 1] == c)
			count++;
		if(s[i] != c && s[i + 1] == '\0')
			count++;*/
		if(s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	printf("numero de palabras es: |%d|\n", count);
	return count;
}
char *ft_substr(const char *str, int start, int len)
{
	char *palabra;
	int i;

	palabra = malloc(sizeof(char) * (len + 1))
	//estoy en examen me la pela protegerlo

	i = 0;
	while(i < len)
	{
		palabra[i] = str[start];
		i++;
		start++;
	}
	//cerrar el string
	palabra[i] = '\0';
	printf("palabra cortada es: |%s|\n", palabra);
	return palabra;
}  


char **ft_split(const char *str, char c)
{
	//contar palabras	
	char **matrix;
	int i;
	int start;
	int words;

	palabras_pegadas = 0;
	i = 0;
	//reservamos la memoria con malloc de contador de palabras.
	// los dos fallos tipicos, no acoradrse que es (char *) i olvidarse de poner (contar palabras + 1) entre parentesis
	matrix = malloc((contrar_palabtas(str, c) + 1) * (sizeof(char *)));
	//estoy en examen me la pela protegerlo

	//cortar i pegar palabras
	while(str[i])
	{
		// Si encuentro inicio de palabra, me guardo esa posicion
		if(i > 0 && s[i] != c && s[i - 1] == c)
	 		start = i;
	 	if (i == 0 && s[i] != c)
	 		start = i;
		// Si encuenro final de palabra, corto i pego
		if(s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			matrix[palabras_pegadas] = ft_substr(str, start, i - start + 1); // el len es end - start + 1
			//estoy en examen me la pela protegerlo
			palabras_pegadas++;
		}
		i++;
	}

	//cerrar la ultima psoicion con  NULL 
	matrix[palabras_pegadas] = NULL;
	return matrix;
}


//"hola   que tal" -> 3
//"hola   que tal " -> 3
//" hola   que tal" -> 3
//"       " -> 0
//"" -> 0
int main()
{
	char **resultado;
	int i;

	i = 0;
	resultado = ft_split(" hola que tal ", ' ');
	while(resultado[i])
	{	
		printf("|%s|\n", resultado[i]);
		i++;
	}
}
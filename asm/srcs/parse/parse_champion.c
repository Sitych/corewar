# include "asm.h"
# define CH_STR 10000

typedef struct s_corewar
{
	int line_number;
	t_championstr champion_str[CH_STR];
	t_label *label;
	t_instr instr[16];
	char *file;
}				t_corewar;

int ft_is_label_char(char c)
{
	int i;

	i = 0;
	while (LABEL_CHARS[i])
	{
		if (LABEL_CHARS[i] == c)
			return (1);
	}
	return (0);
}

//ВАРИАНТЫ
//есть лейбл, неверные символы 500
//есть лейбл, неверный последний знак 400
//есть лейбл и верный последний знак 200 -> проверить есть ли еще символы на строке и если нет то номер этой строки не прибавляем дальше
//нет лейбла и верный последний знак (строка с него начинается)
//нет лейбла и есть последний знак(в середине)
int ft_check_label(char *line, t_championstr championstr)
{
	int i;

	i = 0;
	while (line[i] != LABEL_CHAR && line[i] != '\n' && line[i] != '\0')
	{
		if (ft_is_label_char(line[i]))
			championstr.label += line[i];
		else
			return (500);
		i++;
	}
	if (ft_strcmp("", championstr.label) == 0)
		exit_error(corewar, "invalid label_chars");
	if (line[i] && line[i] == LABEL_CHAR) {
		int j = 0;
		while (j < i)
		{
			championstr.label = ft_memalloc(sizeof(char *));
			championstr.label[j]= line[j];
			j++;
		}
	}

	return (200);
}

void ft_parse_line(t_corewar corewar)
{
	int code;
	int i;

	i = 0;
	while (corewar.file[i] != '\n')
	{
		code = ft_check_label(corewar);
		//вынести в отдельную функцию-обработчик ошибок
		if (code == 100)
		{

		}
		if (code == 400)
		{

		}
		if (code == 500)
		{
			ft_printf("*****ERROR*****\n%s\nline: %d\n", "invalid label_chars", line_number);
			exit(1);
		}
		if (code == 300)
		{

		}
		if (code == 200)
		{

		}
	}
}

t_champion *parse_champion(char *chmp_file_name)
{
	/// YOUR CODE HERE
	t_corewar corewar;
	t_championstr championstr[10000];
	char *initial_file = "line";
	char *file = "line";
	char *line = "";
	while (*file != '\0')
	{
		while (*file != '\n')
		{
			line+=*file;
			*file++;
		}
		*file++;
	}
//	ft_parse_line("line", );
	ft_printf("Hi, %s!!\n", chmp_file_name);
	return (NULL);
}


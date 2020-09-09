#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "libftprintf.h"

// ///"live", 1, {T_DIR}, 1, 10, "alive", 0, 0
// typedef struct s_opt
// {
// 	int		tab_index; // index in op_tab (op.c)
// 	int		op; // продумать представление операции
// }				t_opt;

typedef struct		s_op
{
	char			*name_oper;
	int				col_arg;
	int				*type_arg;
	int				opcode;
	int				cycle_to_die;
	char			*comment;
	int				change_carry;
	int				code_type_arg;
}					t_op;

//структура для аргумента
typedef struct s_arg
{
	int direct; //аргумент direct - 1 или indirect - 0
	int size; //размер аргумента (2 или 4) нужен для получения значения
	int value; //значение, для label рассчитывается при ВТОРОМ проходе
	int arg_number; //порядковый номер аргумента, возможно, не нужен, но может пригодиться для валидации
	int instr_num_curr; //порядковый номер текущей инструкции
	int instr_num_to_go; //порядковый номер инструкции, к которой нужно перескачить (сложить размеры инструкций между двумя значениями)
	int bc;
	int reg; //если аргумент является регистром то здесь число, иначе - 0
}              t_arg;

//инструкции считываемые из файла
typedef struct s_championstr
{
	char *name;
	char *label;
	int bc;
	int number; // порядковый номер инструкции, нужен для подсчета лейбла
	int id;
	int size; //итоговый размер инструкции, нужен для подсчета лейбла(хз,
	// может и не надо если размер инструкций с аргументами статичен)
	t_arg *args;
}               t_championstr;

typedef struct		s_champion
{
	t_header        header;
	t_championstr   *championstr;// пока просто запиши весь код чемпиона сюда
}					t_champion;

//инструкции, данные в задании (Операции и их аргументы)
typedef struct s_instr
{
    char *name; //название инструкции
    int bc; //байткод, но надо подумать в чем его хранить (код операции)
    int id; //id инструкции и связующее звено между массивом считываемых инструкций и данной структуры
    //здесь нужно прописать возможный размер, количество аргументов и тп, все то, что дано в таблице
    int num_args; //номер строки

}               t_instr;

//аргументы операций
typedef struct  s_name_args
{
    int    		t_reg;
    int    		t_dir;
    int			t_ind;
//    t_name_args	*next;
}               t_name_args;

//считанные лейблы
//список
typedef struct s_label
{
    char *name;
    t_championstr championstr;
    // int label_id; //id лейбла
    // int id; //id инструкции в t_instr заполняется при ВТОРОМ проходе
    // int number; //number в t_champinstr заполняется при ВТОРОМ проходе
    //t_arg *args;
}               t_label;

/* Алгоритм
2 прохода:
---------1 проход---------
1) парсинг name и comment
2) парсинг строки
    --парсинг и валидация лейбла, заполнение структуры лейблов
    --парсинг и валидация названия команды
    --парсинг и валидация аргументов и разделителей
3)Обработка ошибок
---------2 проход---------
1)валидация лейблов,заполнение порядкого номера инструкции, айдишника
2)после этого для каждой инструкции расчет байткода и запись в файл
*/

t_champion *parse_champion(char *chmp_file_name);
int		check_label(char *label);

#endif
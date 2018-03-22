#include <stdio.h>
#include <stdlib.h>
int 	vals[10];
int 	vals_len = 0;

int		ft_do_op(int operand1, int operand2, char operator)
{
	if (operator == '-')
		return (operand1 - operand2);
	else if (operator == '+')
		return (operand1 + operand2);
	else if (operator == '*')
		return (operand1 * operand2);
	else if (operator == '/')
		return (operand1 / operand2);
	else if (operator == '%')
		return (operand1 % operand2);
	else
		return 0;
}
void	ft_solve(char operator)
{
	int		operand1;
	int		operand2;
	int		result;

	operand1 = vals[vals_len - 2];
	operand2 = vals[vals_len - 1];
	result = ft_do_op(operand1, operand2, operator);
	vals[vals_len - 1] = '\0';
	vals[vals_len - 2] = result;
	--vals_len;
}
int 	ft_precedence(char op, char last_op, int finaleval)
{
	int 	last_op_order;
	int 	op_order;

	if (last_op == '(' || op == '(')
		return (0);
	if (last_op == '*' || last_op == '/' || last_op == '%')
		last_op_order = (1);
	else if (last_op == '+' || last_op == '-')
		last_op_order = (0);
	if (op == '*' || op == '/' || op == '%')
		op_order = (1);
	else if (last_op == '+' || last_op == '-')
		op_order = (0);
	if (finaleval == 1 || op == ')' || last_op_order >= op_order)
		return (1);
	return (0);
}
int 	*ft_evaluate(char op, int finaleval)
{
	static char 	ops[10];
	static int 		len = 0;

	if (len > 0 || finaleval == 1) //avoid the while loop for evalexpress's return statement
		while (len > 0 && ft_precedence(op, ops[len - 1], finaleval))//if ) or op with precedence is passed in
		{
			if (ops[len] == '(' && op == ')')
				break;
			ft_solve(ops[--len]);
			ops[len] = '\0';
		}
	if (op == ')' && ops[len - 1] == '(')
		ops[--len] = '\0';
	else if (op != ')')
		ops[len++] = op; //(+
	printf("op:%c\tops[0]:%c\tops:%s\tlen:%d\tvals[0]:%d\tvals[1]:%d\n\n", op, ops[0], ops, len, vals[0],vals[1]);
	return (vals[0]);
}
int 	ft_getoperand(char **str)
{
	int 	n;
	int 	operand;
	int 	sign;

	sign = 1;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign *= -1;
		++*str;
	}
	operand = 0;
	while (**str >= '0' && **str <= '9')
	{
		n = (**str - '0');
		operand = operand * 10 + n;
		++*str;//shifts pointer passed in pointer to position after digit
	}
	return (operand * sign);
}
int 	ft_isdigit(char *exp)
{
	if (*exp == '-' || *exp == '+')
		if (*(exp + 1) >= '0' && *(exp + 1) <= '9')
			if (*(exp - 1) == '+' || *(exp - 1) == '*' || *(exp - 1) == '/' || *(exp - 1) == '-' || *(exp - 1) == '%')
				return (1);
			else if (*(exp - 1) == NULL)
				return (1);
	if (*exp >= '0' && *exp <= '9')
		return (1);
	return (0);
}
char 	*ft_strcpy(char *dest, char *src)
{
	while(*dest++ = *src++)
	{
		;
	}
	*dest = '\0';
	return(dest);
}
int 	ft_strlen(char *str)
{
	int 	len;

	len = 0;
	while (str[len++])
	{
		;
	}
	return (len);
}
int		*ft_evalexpress(char *str)
{
	char 	*exp = (char *)malloc(sizeof(exp) * ft_strlen(str));

	ft_strcpy(exp, str);
	while (*exp)
	{
		if (ft_isdigit(exp))
			vals[vals_len++] = ft_getoperand(&exp);
		if (*exp == '+' || *exp == '*' || *exp == '/' || *exp == '-' || *exp == '%')
			ft_evaluate(*exp, 0);
		if (*exp == '(' || *exp == ')')
			ft_evaluate(*exp, 0);
		exp++;
	}
	return (ft_evaluate(NULL, 1));//if null is passed in, the evaluate function will solve until len == 0
}
int main()
{
	int 	*answer = ft_evalexpress("+4+-2+5+(1+1)%-2");
	printf("ANSWER IS:%d", answer);
	return 0;
}
//have to create function to qualify string as an valid expression
//may have to create other functions to evaluate postfix and prefix expressions
//also have to account for other edge cases
//free malloc'd mem

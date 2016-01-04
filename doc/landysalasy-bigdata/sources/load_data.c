#include "catalogue.h"
#include "load_data.h"

static char *smart_strcat(char *str_1, char *str_2)
{
	char *tmp;
	uint16_t size_str_1 = strlen(str_1);
	uint16_t size_str_2 = strlen(str_2);

	if (!str_1 || !str_2)
		return (NULL);
	if ((tmp = malloc(sizeof(*tmp) * (size_str_1 + size_str_2 + 1))) == NULL)
		return (NULL);
	strcpy(tmp, str_1);
	strcpy(&tmp[size_str_1], str_2);
	tmp[size_str_1 + size_str_2] = '\0';
	free(str_1);
	free(str_2);
	return (tmp);
}

static char *handle_expression(char *read_buffer, void (*handler)(char *, void *), void *data)
{
	char *brk = read_buffer;

	while (brk != NULL && read_buffer[0] != '\0')
	{
		brk = strpbrk(read_buffer, SEPARATOR);
		if (brk != NULL)
		{
			brk[0] = '\0';
			if (strlen(read_buffer) > 0)
				handler(read_buffer, data);
			read_buffer = brk + 1;
		}
	}
	return (strdup(read_buffer));
}

static void handle_buffer(char *tmp_buffer, char **unhandle_buffer)
{
	if (strlen(tmp_buffer) == 0)
	{
		free(tmp_buffer);
		free(*unhandle_buffer);
		*unhandle_buffer = NULL;
	}
	else
	{
		free(*unhandle_buffer);
		*unhandle_buffer = tmp_buffer;
	}
}

/**
*\author Dorian Pinaud
*\version 0.1
*\date Mars 2014
*\brief Load data form file indicate.
*\fun \b load_data.
*\param file_name Name of file targeted.
*\param handler Function pointer use to handle the file targeted.
*\param data Contain the data generate by the function pointer in parameter.
*\return 0 if load fail, 1 if everything is ok.
*/
uint8_t load_data(char const *file_name, void (*handler)(char *, void *), void *data)
{
	FILE *file;
	char read_buffer[SIZE_BUFFER];
	char buffer[SIZE_BUFFER];
	uint8_t offset_buffer = 0;
	char *unhandle_buffer = NULL;

	if ((file = fopen(file_name, "r")) == NULL)
	{
		log_error("Error : [%s] filename can't be open.\n", file_name);
		return (0);
	}
	memset(read_buffer, '\0', SIZE_BUFFER);
	while (fgets(read_buffer, SIZE_BUFFER, file) != NULL && feof(file) != EOF)
	{
		if (unhandle_buffer != NULL)
		{
			if ((unhandle_buffer = smart_strcat(unhandle_buffer, strdup(read_buffer))) == NULL)
				return (0);
		}
		else
			unhandle_buffer = strdup(read_buffer);
		handle_buffer(handle_expression(unhandle_buffer, handler, data), &unhandle_buffer);
	}
	if (unhandle_buffer != NULL && strlen(unhandle_buffer) > 0)
	{
		handler(unhandle_buffer, data);
		free(unhandle_buffer);
	}
	fclose(file);
	return (1);
}
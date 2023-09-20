#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* Define buffer sizes for reading and writing. */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* Define constants for command chaining types. */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* Define options for converting numbers. */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* Flag indicating whether system getline() is used. */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * Define a singly linked list structure for strings.
 * @num: Number associated with the string.
 * @str: The string itself.
 * @next: Pointer to the next node in the list.
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * Define a structure for passing information to functions, ensuring a uniform
 * prototype for function pointer structs.
 *
 * @arg: String generated from getline containing arguments.
 * @argv: Array of strings generated from arguments.
 * @path: String path for the current command.
 * @argc: Argument count.
 * @line_count: Error count.
 * @err_num: Error code for exit() calls.
 * @linecount_flag: Flag to count this line of input.
 * @fname: Program filename.
 * @env: Linked list local copy of environ.
 * @history: History node.
 * @alias: Alias node.
 * @environ: Custom modified copy of environ from LL env.
 * @env_changed: Flag indicating if environ was changed.
 * @status: Return status of the last exec'd command.
 * @cmd_buf: Address of pointer to cmd ; chain buffer, for memory management.
 * @cmd_buf_type: CMD_type ||, &&, ;.
 * @readfd: File descriptor from which to read line input.
 * @histcount: History line number count.
 */

typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * Define a structure for built-in commands.
 * @type: The built-in command flag.
 * @func: The associated function.
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/* Function declarations and more code... */

#endif

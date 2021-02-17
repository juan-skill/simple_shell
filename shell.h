#ifndef SHELL
#define SHELL

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <errno.h>


/**
 * struct list - linked list for environmental variables
 * @var: string to hold environmental variable
 * @next: points to next node
 */
typedef struct list
{
	char *var;
	struct list *next;

} list_t;

#define MAXLINE 1024
list_t *env;
extern char **environ;


/* function prototypes */
int start_mode_interactive(int);
int start_mode_noninteractive(int);

size_t get_line(char **str, int);
char *formatt_input(char *command);
char *replace_newline(char *command);
char *_ignore_delimiter(char *str, char delimiter);

list_t *env_linked_list(char **env);
list_t *add_end_node(list_t **head, char *str);


char **_str_tok(char *str, char delimiter);
int count_options(char *str, char delimiter);
int built_in(char **token, int num, char **command);
int _execve(char *argv[], int num);
char *_which(char *str);
char *get_env(char *str, list_t *env);

/* command */
int __exit(char **s, int num, char **command);
int _env(char **str);
size_t print_list(list_t *h);

/*libraries */
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strcat(char *dest, char *src);
char *_strdup(const char *str);
char *_strcpy(char *dest, const char *src);
int _strcmp(char *s1, char *s2);
int _strlen(const char *s1);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *itostr(int num);

void free_double_ptr(char **str);
void free_linked_list(list_t *list);

/*error message */
void not_found(char *str, int num, list_t *env);
void illegal_number(char *str, int c_n, list_t *env);



#endif

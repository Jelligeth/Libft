/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dliu <dliu@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 11:29:23 by dliu          #+#    #+#                 */
/*   Updated: 2023/02/20 13:58:58 by dliu          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define ANSI_COL_RED "\x1b[31m"
# define ANSI_COL_GREEN "\x1b[32m"
# define ANSI_COL_YELLOW "\x1b[33m"
# define ANSI_COL_BLUE "\x1b[34m"
# define ANSI_COL_MAGENTA "\x1b[35m"
# define ANSI_COL_CYAN "\x1b[36m"
# define ANSI_COL_RESET "\x1b[0m"

typedef struct a_list
{
	void			*content;
	struct a_list	*next;
}					t_list;

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *node);
void		ft_lstadd_back(t_list **lst, t_list *node);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

typedef struct s_print
{
	va_list		argsp;
	t_list		*plist;
	int			count;
	int			isneg;
	int			iszero;
	int			plus;
	int			hash;
	int			space;
	int			dash;
	int			zero;
	int			dot;
	int			width_min;
	int			width_precision;
}				t_print;

int			ft_printf(const char *s, ...);
int			set_flags(t_print *tab, const char *format);
int			add_node(t_print *tab, char *content, const int addback);
char		*ft_strrep(const char c, const size_t len);
void		print_char(t_print *tab, const char c);
void		print_string(t_print *tab);
void		print_int(t_print *tab, const char c);
void		print_hex(t_print *tab, const char c);
void		print_pnt(t_print *tab);
void		apply_flags_chars(t_print *tab);
void		apply_flags_num(t_print *tab);
void		apply_flags_hex(t_print *tab);
void		check_write(t_print *tab);

char		*get_next_line(int fd);

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putstr_col_fd(char *color, char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);

int			ft_atoi(const char *str);
long long	ft_atoll(const char *str);
int			ft_toupper(int c);
int			ft_tolower(int c);

void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
/**
 * Locates the first occurance of c in s.
 * @param s Pointer to the first char in a string.
 * @param c The character to find in the string.
 * @param n The maximum amount of bytes to check. 
 * @returns A pointer to the byte located or NULL if not found.
*/
void		*ft_memchr(const void *s, int c, size_t n);
/**
 * Compares byte string s1 against byte string s2. Both strings are assumed to
 * be n bytes long.
 * @returns The difference between the bytes, treated as unsigned char values.
*/
int			ft_memcmp(const void *s1, const void *s2, size_t n);
/**
 * Writes len bytes of value c to the string b.
 * @param b Void pointer converted to an unsigned char pointer.
 * @param c Int value of character converted to unsigned char.
 * @returns Returns b.
*/
void		*ft_memset(void *str, int c, size_t n);
/**
 * Copies n bytes from memory area src to memory area dst.
 * Overlap behavior is undefined, use memmove instead.
*/
void		*ft_memcpy(void *dst, const void *src, size_t n);
/**
 * Copies len bytes from src to dst in a non-destructive manner.
 * @returns the original value of dst.
*/
void		*ft_memmove(void *dst, const void *src, size_t len);

size_t		ft_strlen(const char *s);
/**
 * Counts and returns the amount of strings in a string array.
*/
size_t		ft_strarray_count(char **s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

/**
 * Locates the first occurrence of c (converted to a char) in a string.
 * @param s Pointer to first character in a string.
 * @param c The character to locate.
 * @returns A pointer to the located character or NULL if it does not appear.
*/
char		*ft_strchr(const char *s, int c);
/**
 * Locates the last occurrence of c (converted to a char) in a string.
 * @param s Pointer to first character in a string.
 * @param c The character to locate.
 * @returns A pointer to the located character or NULL if it does not appear.
*/
char		*ft_strrchr(const char *s, int c);
/**
 * Locates the first occurrence of a string in another string.
 * @param haystack The string to search in.
 * @param needle The string to locate.
 * @param len The maximum length to search.
 * @returns Haystack if needle is empty. Null if Needle not found.
 * Else pointer to the first character of the first occurrence of needle.
*/
char		*ft_strnstr(const char *haystack, const char*needle, size_t len);
/**
 * Lexicographically compares two strings.
 * @returns The difference between the strings if found or 0 if no diff found.
*/
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * Copies a string from src to dst. Guarantees NUL-termination if there is space.
 * @returns The total length of the string attempted to be created.
*/
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
/**
 * Allocates (with malloc(3)) and returns a substring from a string.
 * @param s The string from which to create the substring.
 * @param start The start index of the substrign in the string 's'
 * @param len The maximum length of the substring.
 * @returns The substring. NULL if the allocation fails.
*/
char		*ft_substr(char const *s, unsigned int start, size_t len);
/**
 * Allocates (with malloc(3)) and returns a copy of s1 with chars in set removed
 * from the beginning and end of the string.
*/
char		*ft_strtrim(char const *s1, char const *set);
/**
 * Allocates (with malloc(3)) and returns a string with repeating characters.
*/
char		*ft_strrep(const char c, const size_t len);

/**
 * Applies the function f to each character of the string s and creates a new
 * string (with malloc(3)).
 * @param s The string on which to iterate.
 * @param f The funciton to apply to each character.
 * @returns The strign created from the successive application of f
 * of NULL if allocation fails.
*/
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/**
 * Applies the function f on each char of a string.
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
*/
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
/**
 * Reverses the string in place.
*/
char		*ft_strrev(char *string);

/**
 * Splits a string into an array of strings allocated (with malloc(3)).
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return The array of new strings ending with a NULL pointer
 * or NULL if the allocation fails.
*/
char		**ft_split(const char *s, char c);

/**
 * Allocates (with malloc(3)) and returns a string
 * representing the integer received as an argument.
 */
char		*ft_itoa(int n);

/**
 * Allocates (with malloc(3)) and returns a string
 * representing the number received as an argument.
 */
char		*ft_lltoa_base(long long n, int base);
/**
 * Allocates (with malloc(3)) and returns a string
 * representing the unsigned number received as an argument.
 * Negative numbers will not be handled.
 */
char		*ft_ltoa_unsigned_base(unsigned long num, int base);

/**
 * Checks, converts and stores to address a valid int from a string.
 * @param check_me The string to check and convert.
 * @param num The address of an int in which to store the converted number.
 * @returns 0 if invalid, 1 if valid.
*/
int			ft_atoi_validate(char *check_me, int *num);

/**
 * Compares the result of a - b with min and returns the smallest one.
*/
int			ft_min(int a, int b, int min);
/**
 * Compares a to b and returns the smallest value, or a if they are equal.
*/
int			ft_smallest(int a, int b);
/**
 * Compares a to b and returns the biggest value, or a if they are equal.
*/
int			ft_biggest(int a, int b);
/**
 * Counts and returns the length of the number n in the given base.
*/
int			ft_numlen(long long n, int base);

/**
 * Splits a string into an array of strings allocated with malloc(3).
 * Splits will be delimited by white spaces, unless within quotation marks.
*/
char		**ft_split2(char *s);

/**
 * Uses malloc, joins multiple strings together.
 * @param count The amount of strings to join.
*/
char		*ft_joinstrs(int count, ...);

void		ft_error(char *errstr);
void		ft_perror(char *progname, char *err, char *messsage);
void		ft_pdebug(int c);

void		ft_free(void *content);
void		ft_free_strarr(char **array);
void		ft_free_strarrarr(char ***arrarr);
void		ft_free_strnarr(char **array, size_t n);
void		ft_free_intarrarr(int **intarrarr);

#endif
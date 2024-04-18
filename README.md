# 42-Porto-Common Core-Libft
## My first library, libft.

### String & Char Functions:

1. ```ft_strchr:``` char	*ft_strchr(char *str, char c);<br /><br />
         **Desctiption:** Finds the first occurrence of c in the string pointed by *str.<br />
         **Return Value:** Pointer to the beggining of the occurrence of c in the string pointed by *str<br /><br />
2. ```ft_strdup```: char	*ft_strdup(char *s);<br /><br />
         **Desctiption:** Duplicates the string pointed by *s.<br />
         **Return Value:** Returns the duplicated string.<br /><br />
3. ```ft_striteri```: void	ft_striteri(char *s, void (*f)(unsigned int, char*));<br /><br />
         **Desctiption:** Applies the function ’f’ on each character of the string passed as argument, passing its index as first argument.<br />
         **Return Value:** None.<br /><br />
4. ```ft_strjoin```: char	*ft_strjoin(char const *s1, char const *s2);<br /><br />
         **Desctiption:** Allocates and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’.<br />
         **Return Value:** The new string.<br /><br />
5. ```ft_strlcat```: int	ft_strlcat(char *dst, char *src, int n);<br /><br />
         **Desctiption:** Concatenate the string pointed by *src into the string pointed by *dst, while n size.
         **Return Value:** size of dst + src.<br /><br />
6. ```ft_strlcpy```: int	ft_strlcpy(char *dst, char *src, int n);<br /><br />
         **Desctiption:** Copy the string pointed by *src into the string pointed by *dst, while n size.<br />
         **Return Value:** size of the src string.<br /><br />
7. ```ft_strlen```: int	ft_strlen(char const *str);<br /><br />
         **Desctiption:** Calculates the size of a string.<br />
         **Return Value:** Size of the string.<br /><br />
8. ```ft_strmapi```: char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));<br /><br />
         **Desctiption:** Applies the function ’f’ to each character of the string ’s’, and passing its index as first argument to create a new string (with malloc(3)) resulting from successive applications of ’f’.<br />
         **Return Value:** The string created from the successive applications of ’f’.<br /><br />
9. ```ft_strncmp```: int	ft_strncmp(char const *s1, char const *s2, size_t n);<br /><br />
         **Desctiption:** Compares the strings s1 and s2 while n size.<br />
         **Return Value:** returns a positive value if s1 > s2, a negative value if s1 < s2 and 0 if s1 = s2.<br /><br />
10. ```ft_strnstr```: char	*ft_strnstr(char *origin, char *find, int n);<br /><br />
         **Desctiption:** Finds the first occurrence of find in the string origin.<br />
         **Return Value:** Returns the origin string begginning in the first occurrence of find.<br /><br />
11. ```ft_strrchr```: char	*ft_strrchr(char *str, char c);<br /><br />
         **Desctiption:** Finds the last occurrence of c in the string str.<br />
         **Return Value:** Returns the last occurence of c in str string.<br /><br />
12. ```ft_strtrim```: char	*ft_strtrim(char const *s1, char const *set);<br /><br />
         **Desctiption:** Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string.<br />
         **Return Value:** The trimmed string.<br /><br />
13. ```ft_substr```: char	*ft_substr(char const *s, unsigned int start, size_t len);<br /><br />
         **Desctiption:** Allocates (with malloc(3)) and returns a substring from the string ’s’. The substring begins at index ’start’ and is of maximum size ’len’.<br />
         **Return Value:** The substring.<br /><br />
14. ```ft_atoi```: int	ft_atoi(char *str);<br /><br />
         **Desctiption:** converts the string argument str to an integer.<br />
         **Return Value:** The integer number.<br /><br />
15. ```ft_isalnum```: int	ft_isalnum(int c);<br /><br />
         **Desctiption:** Checks if c is an alphanumeric character.<br />
         **Return Value:** 1 if true, 0 if false.<br /><br />
16. ```ft_isalpha```: int	ft_isalpha(int c);<br /><br />
         **Desctiption:** Checks if c is a letter.<br />
         **Return Value:** 1 if true, 0 if false.<br /><br />
17. ```ft_isascii```: int	ft_isascii(int c);<br /><br />
         **Desctiption:** Checks if c is on ascii table.<br />
         **Return Value:** 1 if true, 0 if false.<br /><br />
18. ```ft_isdigit```: int	ft_isdigit(int c);<br /><br />
         **Desctiption:** Checks if c is a number.<br />
         **Return Value:** 1 if true, 0 if false.<br /><br />
19. ```ft_isprint```: int	ft_isprint(int c);<br /><br />
         **Desctiption:** Checks if c is printable.<br />
         **Return Value:** 1 if true, 0 if false.<br /><br />
20. ```ft_itoa```: char	*ft_itoa(int n);<br /><br />
         **Desctiption:** Allocates and returns a string representing the integer received as an argument. Negative numbers must be handled.<br />
         **Return Value:** The string representing the integer.<br /><br />
21. ```ft_putchar_fd```: void	ft_putchar_fd(char c, int fd);<br /><br />
         **Desctiption:** Outputs the character ’c’ to the given file descriptor.<br />
         **Return Value:** None.<br /><br />
22. ```ft_putendl_fd```: void	ft_putchar_fd(char c, int fd);<br /><br />
         **Desctiption:** Outputs the string ’s’ to the given file descriptor followed by a newline.<br />
         **Return Value:** None.<br /><br />
23. ```ft_putnbr_fd```: void	ft_putnbr_fd(int n, int fd);<br /><br />
         **Desctiption:** Outputs the integer ’n’ to the given filedescriptor.<br />
         **Return Value:** None.<br /><br />
24. ```ft_putstr_fd```: void	ft_putstr_fd(char *s, int fd);<br /><br />
         **Desctiption:** Outputs the string ’s’ to the given file descriptor.<br />
         **Return Value:** None.<br /><br />
25. ```ft_split```: char	**ft_split(char *s, char c);<br /><br />
         **Desctiption:** Allocates and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter.<br />
         **Return Value:** The array of new strings resulting from the split.<br /><br />
26. ```ft_tolower```: int	ft_tolower(int c);<br /><br />
         **Desctiption:** Converts c to its lowercase equivalent if c is an uppercase letter and has a lowercase equivalent.<br />
         **Return Value:** The lowercase of c.<br /><br />
27. ```ft_toupper```: int	ft_toupper(int c);<br /><br />
         **Desctiption:** Converts c to its uppercase equivalent if c is a lowercase letter and has an uppercase equivalent.<br />
         **Return Value:** The uppercase of c.<br /><br />

### Memory Manipulation Functions:<br />

1. ```ft_bzero```: void	ft_bzero(void *s, int n);<br /><br />
         **Desctiption:** Place n zero-valued bytes in the area pointed to by s.<br />
         **Return Value:** None.
   <br /><br />
2. ```ft_calloc```: void	*ft_calloc(int nitems, int size);<br /><br />
         **Desctiption:** allocates the requested memory and returns a pointer to it.<br />
         **Return Value:** returns a pointer to the allocated memory.
   <br /><br />
3. ```ft_memchr```: void	*ft_memchr(void *str, int c, int n);<br /><br />
         **Desctiption:** searches for the first occurrence of c in the first n bytes of str.<br />
         **Return Value:** This function returns a pointer to the matching byte.
   <br /><br />
4. ```ft_memcmp```: int	ft_memcmp(void *s1, void *s2, int n);<br /><br />
         **Desctiption:** compares the first n bytes of memory area s1 and memory area s2.<br />
         **Return Value:** if s1 > s2, return a positive value, if s1 < s2, returns a negative value, if s1 = s2, returns 0.
   <br /><br />
5. ```ft_memcpy```: void	*ft_memcpy(void *dst, const void *src, int n);<br /><br />
         **Desctiption:** copies n characters from memory area src to memory area dst.<br />
         **Return Value:** None.
   <br /><br />
6. ```ft_memmove```: void	*ft_memmove(void *s1, void *s2, int n);<br /><br />
         **Desctiption:** copies n characters from s2 to s1<br />
         **Return Value:** None.
   <br /><br />
7. ```ft_memset```: void	*ft_memset(void *str, int c, size_t n);<br /><br />
         **Desctiption:** copies c to the first n characters of str.<br />
         **Return Value:** None.
   <br /><br />

### Linked Lists Functions:<br />

1. ```ft_lstadd_back```: void	ft_lstadd_back(t_list **lst, t_list *new);<br /><br />
         **Desctiption:** Adds the node ’new’ at the end of the list.<br />
         **Return Value:** None.
   <br /><br />
2. ```ft_lstadd_front```: void	ft_lstadd_front(t_list **lst, t_list *new);<br /><br />
         **Desctiption:** Adds the node ’new’ at the beginning of the list.<br />
         **Return Value:** None.
   <br /><br />
3. ```ft_lstclear```: void	ft_lstclear(t_list **lst, void (*del)(void *));<br /><br />
         **Desctiption:** Deletes and frees the given node and every successor of that node, using the function ’del’ and free(3).<br />
         **Return Value:** None.
   <br /><br />
4. ```ft_lstdelone```: void	ft_lstdelone(t_list *lst, void (*del)(void *));<br /><br />
         **Desctiption:** Takes as a parameter a node and frees the memory of the node’s content using the function ’del’ given as a parameter and free the node.<br />
         **Return Value:** None.
   <br /><br />
5. ```ft_lstiter```: void	ft_lstiter(t_list *lst, void (*f)(void *));<br /><br />
         **Desctiption:** Iterates the list ’lst’ and applies the function ’f’ on the content of each node.<br />
         **Return Value:** None.
   <br /><br />
6. ```ft_lstlast```: t_list	*ft_lstlast(t_list *lst);<br /><br />
         **Desctiption:** Returns the last node of the list.<br />
         **Return Value:** Last node of the list.
   <br /><br />
7. ```ft_lstmap```: t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));<br /><br />
         **Desctiption:** Iterates the list ’lst’ and applies the function ’f’ on the content of each node. Creates a new list resulting of the successive applications of the function ’f’.<br />
         **Return Value:** The new list.
   <br /><br />
8. ```ft_lstnew```: t_list	*ft_lstnew(void *content);<br /><br />
         **Desctiption:** Allocates (with malloc(3)) and returns a new node. The member variable ’content’ is initialized with the value of the parameter ’content’.<br />
         **Return Value:** The new node.
   <br /><br />
9. ```ft_lstsize```: int	ft_lstsize(t_list *lst);<br /><br />
         **Desctiption:** Counts the number of nodes in a list.<br />
         **Return Value:** The length of the list.
   <br /><br />

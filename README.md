# ft_printf

Recode the libc’s printf function.

### Installation

```
$ git clone https://github.com/Kugumi/ft_printf.git
$ cd ft_printf
$ make
$ gcc -Wall -Wextra -Werror main.c libftprintf.a
```

### Usage

```
Change main.c with the following conversions and flags and compile again (gcc -Wall -Wextra -Werror main.c libftprintf.a)
```

### Conversions
|        |        |
| ------ | ------ |
| c | Returns true if file is "block-special". |
| s | Returns true if file is "character-special." |
| p | Returns true if file is a directory. |
| d | Returns true if file exists. |
| i | Returns true if file exists, and is a regular file. |
| o | Returns true if file has the setgid bit set. |
| u | Returns true if file is a symbolic link. |
| x | Returns true if the file is a named pipe. |
| X | Returns true if file is readable by the user running test. |
| hh | Returns true if file exists, and is not empty. |
| h | Returns true if file is a socket. |
| l | Returns true if file has the setuid bit set. |
| ll | Returns true if the user running test has write permission to file. |
| f, lf, Lf | Returns true if file is executable by the user running test. |
| %% | Returns true if string string is empty, i.e. "". |

### Flags
|        |        |
| ------ | ------ |
| # | Returns true if file is "block-special". |
| 0 | Returns true if file is "character-special." |
| - | Returns true if file is a directory. |
| + | Returns true if file exists. |
| ⌴ | Returns true if file exists, and is a regular file. |

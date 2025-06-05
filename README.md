# libft_all

## Summary  
This repository implements a comprehensive **Libft** library—a reimplementation of common C standard library functions—along with additional utility modules: array helpers, **Get_Next_Line**, **ft_printf / ft_fprintf**, and error/string utilities. All functions are compiled into a static archive (`libft.a`) that can be linked into your C projects. :contentReference[oaicite:0]{index=0}

## Repository Structure  
- **Makefile**  
  - Builds `libft.a` from all `.c` sources.  
  - Creates object files in `objs/`  
  - Targets:  
    - `all` (default): Compile all sources into `objs/*.o` and archive into `libft.a`.  
    - `clean`: Remove object files.  
    - `fclean`: Remove `libft.a` and `objs/` directory.  
    - `re`: Run `fclean` then `all`. :contentReference[oaicite:1]{index=1}

- **Source Files**  
  - **Character checks & conversions**  
    - `ft_isalpha.c`, `ft_isdigit.c`, `ft_isalnum.c`, `ft_isascii.c`, `ft_isprint.c`  
    - `ft_isspace.c`, `ft_isnumber.c`  
    - `ft_tolower.c`, `ft_toupper.c`  
    - `ft_atoi.c` (string-to-integer), `ft_itoa.c` (integer-to-string) :contentReference[oaicite:2]{index=2}  

  - **Memory functions**  
    - `ft_bzero.c`, `ft_memset.c`, `ft_memcpy.c`, `ft_memmove.c`, `ft_memcmp.c`, `ft_memchr.c`  
    - `ft_calloc.c`, `ft_realloc.c` :contentReference[oaicite:3]{index=3}  

  - **String functions**  
    - `ft_strlen.c`, `ft_strlen_newline.c`, `ft_strlcpy.c`, `ft_strlcat.c`  
    - `ft_strchr.c`, `ft_strrchr.c`, `ft_strncmp.c`, `ft_strcmp.c`, `ft_strnstr.c`  
    - `ft_strdup.c`, `ft_strndup.c`, `ft_strcpy.c`-style (`ft_strncpy.c`)  
    - `ft_substr.c`, `ft_strjoin.c`, `ft_strjoin_three.c`, `ft_strtrim.c`, `ft_split.c`  
    - `ft_strmapi.c`, `ft_striteri.c` :contentReference[oaicite:4]{index=4}  

  - **File-line / Format utilities**  
    - **Get_Next_Line**: `ft_get_next_line.c`, `ft_get_next_line_utils.c` (read a file descriptor line by line) :contentReference[oaicite:5]{index=5}  
    - **ft_printf / ft_fprintf**: `ft_printf.c`, `ft_printf_utils.c`, `ft_fprintf.c` (formatted printing to `stdout` or given file descriptor) :contentReference[oaicite:6]{index=6}  

  - **Output helpers**  
    - `ft_putchar_fd.c`, `ft_putstr_fd.c`, `ft_putendl_fd.c`, `ft_putendl.c`, `ft_putnbr_fd.c` :contentReference[oaicite:7]{index=7}  

  - **Linked-list functions**  
    - `ft_lstnew.c`, `ft_lstadd_front.c`, `ft_lstadd_back.c`, `ft_lstsize.c`, `ft_lstlast.c`  
    - `ft_lstdelone.c`, `ft_lstclear.c`, `ft_lstiter.c`, `ft_lstmap.c` :contentReference[oaicite:8]{index=8}  

  - **Array helpers**  
    - `ft_array_count_str.c` (count number of strings in a NULL-terminated array)  
    - `ft_array_dup.c` (duplicate a NULL-terminated array of strings)  
    - `ft_array_free.c` (free a NULL-terminated array)  
    - `ft_array_join.c` (concatenate two NULL-terminated arrays) :contentReference[oaicite:9]{index=9}  

  - **Error / Miscellaneous**  
    - `ft_error.c` (print error message and exit) :contentReference[oaicite:10]{index=10}  

- **Header**  
  - **`libft.h`**: Declares all function prototypes, necessary `#include`s (e.g., `<stdlib.h>`, `<unistd.h>`), and any required macros. :contentReference[oaicite:11]{index=11}

## Languages and Tools  
- **C (98.2%)**: All functionality is implemented in standard C (ISO C99–C11 compatible). :contentReference[oaicite:12]{index=12}  
- **Makefile (1.8%)**: Automates building `objs/` directory and archiving into `libft.a`. :contentReference[oaicite:13]{index=13}

## How to Use This Library  
1. **Clone the repository**  
   ```bash
   git clone https://github.com/yuhi-ootani/lifbt_all.git
   cd lifbt_all
   ``` :contentReference[oaicite:14]{index=14}

2. **Build `libft.a`**  
   ```bash
   make

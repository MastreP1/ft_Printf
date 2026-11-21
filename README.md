*This project has been created as part of the 42 curriculum by omejri.*

# ft_printf — Formatted Output Conversion

## Description

**`ft_printf`** is a custom implementation of the standard C library function `printf()` from `<stdio.h>`. Developed as part of the 42 curriculum, the goal of this project is to explore and master **variadic functions** (`<stdarg.h>`), formatted output string parsing, and low-level data conversion while strictly adhering to **The 42 Norm**.

The function writes formatted output directly to the standard output (`stdout`, file descriptor 1) and returns the total number of characters successfully printed, or `-1` if an output error occurs. As required by the subject specifications, `ft_printf` does not implement intermediate output buffering.

### Function Prototype

```c
int ft_printf(const char *format, ...);
```

### Supported Conversions

`ft_printf` parses the format string and handles the following mandatory conversion specifiers:

| Specifier | Description | Expected Argument Type |
| :---: | :--- | :--- |
| **`%c`** | Prints a single ASCII character. | `int` (promoted from `char`) |
| **`%s`** | Prints a null-terminated string. If the pointer is `NULL`, outputs `(null)`. | `char *` |
| **`%p`** | Prints a `void *` memory address in lowercase hexadecimal with a `0x` prefix. If the pointer is `NULL`, outputs `(nil)`. | `void *` |
| **`%d`** | Prints a signed decimal integer (base 10). | `int` |
| **`%i`** | Prints an integer in base 10 (identical to `%d`). | `int` |
| **`%u`** | Prints an unsigned decimal integer (base 10). | `unsigned int` |
| **`%x`** | Prints a number in hexadecimal lowercase format (base 16: `0123456789abcdef`). | `unsigned int` |
| **`%X`** | Prints a number in hexadecimal uppercase format (base 16: `0123456789ABCDEF`). | `unsigned int` |
| **`%%`** | Prints a literal percent sign (`%`) without consuming an argument. | *None* |

---

## Instructions

### Compilation

The library is compiled into a static archive named `libftprintf.a` at the root of the repository using `ar rcs`. The `Makefile` includes the standard 42 rules:

```bash
make        # Compiles source files and creates libftprintf.a
make clean  # Removes intermediate object (.o) files
make fclean # Removes object files and the libftprintf.a archive
make re     # Executes fclean followed by make
```

### Execution & Usage

To test and link `libftprintf.a` in your own C program:

1. The following Steps must be performed with the Provided library and in the same Directory As the git repository
    ```bash
    git clone https://github.com/My_REPO ft_PrintF # For example
    ```

2. Create a `main.c`:
   ```c
   #include "ft_printf.h"

   int main(void)
   {
       int count;

       count = ft_printf("Hello %s! Number: %d, Hex: %x, Pointer: %p\n", "42", 42, 42, &count);
       ft_printf("Printed %d characters.\n", count);
       return (0);
   }
   ```
3. Compile and link against `libftprintf.a`:
   ```bash
   cc -Wall -Wextra -Werror main.c libftprintf.a -o test_printf
   ./test_printf
   ```

---

## Algorithm & Data Structure Justification

### 1. Data Structure Selection
* **Format String Stream (`const char *`):**  
  The format string is treated as a continuous read-only memory stream. Rather than heap buffers, the parser traverses the string using direct pointer arithmetic (`s++`).
* **Variadic Argument List (`va_list`):**  
  Under the **System V AMD64 ABI**, parameters are classified across registers and stack slots. The standard `<stdarg.h>` macros (`va_start`, `va_arg`, `va_end`) provide an efficient, $\mathcal{S}(1)$ portable mechanism to dereference argument registers (from the Register Save Area) and spilled arguments (from the caller's stack frame).

### 2. Algorithmic Architecture
* **Single-Pass Stream Scanner:**  
  The parser evaluates the format string sequentially in $\mathcal{S}(N)$ linear time (where $N$ is the string length). Non-specifier characters are emitted immediately using the `write()` system call. When a `%` symbol is detected, a lookahead inspects the succeeding character to dispatch the corresponding conversion handler.
* **Recursive Modulo Radix Conversion:**  
  Numeric and pointer conversions (`%d`, `%i`, `%u`, `%x`, `%X`, `%p`) utilize divide-and-conquer modulo recursion. The digits are extracted by repeatedly dividing by the base (10 or 16) and written in natural left-to-right order during stack unwinding.

## Resources

### References
* [System V Application Binary Interface: AMD64 Architecture Processor Supplement](https://gitlab.com/x86-psABIs/x86-64-ABI) — Technical standard detailing argument registers, the Register Save Area (RSA), caller stack frame placement, and `va_list` internal representation.  
  > ℹ️ *Note: This implementation is developed and optimized for systems adhering to the System V x86-64 ABI (Linux / macOS).*
* [The Linux Programming Interface (Michael Kerrisk)](https://man7.org/tlpi/) — Comprehensive reference on process memory segments, stack frame activation records, and POSIX file I/O (`write`).
* [C Programming: A Modern Approach (K. N. King)](http://knking.com/books/c2/) — In-depth guide to variadic functions (`<stdarg.h>`) and default argument promotions.
* [Linux Programmer's Manual: printf(3)](https://man7.org/linux/man-pages/man3/printf.3.html) — Reference specification for format conversions and return values.

### AI Usage Disclosure
In accordance with 42 AI Guidelines (Chapter III & V):
* **Conceptual Clarification:** AI was consulted to explore the low-level mechanics of the System V AMD64 ABI, how `<stdarg.h>` structures the Register Save Area (RSA), and how stack frames interact with caller arguments.
* **Documentation Structuring:** AI was used to draft and verify the Markdown formatting for this `README.md` to ensure full compliance with the 42 project checklist.
* **Implementation:** All C code logic, edge-case testing, and Norm compliance verification were implemented and validated independently without automated code generation.

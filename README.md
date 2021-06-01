# Ft_printf
The goal of this project is to recode printf. A function (ft_printf) that will mimic the real printf.

Allowed built-in functions: **malloc**, **free**, **write**, **va_start**, **va_arg**, **va_copy**, **va_end**.

Function prototype: `ft_printf(const char *, ...);`

It will manage the following conversions: `cspdiuxX%`

It will manage any combination of the following flags: `-0.*` and minimum field width with all conversions.

**Examples:**

## Usage
1. Add `#include "ft_printf.h"` in your project.
2. Do `make` to compile Ft_printf. After that copy the `libftprintf.a` and `ft_printf.h` and paste them into your project.
3. Compile your project using `gcc YourFileName -L. -lftprintf -I.`.
4. Run your program using `./a.out`.

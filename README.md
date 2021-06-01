# Ft_printf
The goal of this project is to recode printf. A function (ft_printf) that will mimic the real printf.

Allowed built-in functions: **malloc**, **free**, **write**, **va_start**, **va_arg**, **va_copy**, **va_end**.

Function prototype: `ft_printf(const char *, ...);`

It will manage the following conversions: `cspdiuxX%`

It will manage any combination of the following flags: `-0.*` and minimum field width with all conversions.

<table>
  <tr>
    <td align="center">Example</td>
  </tr>
  <tr>
    <td><img src="https://user-images.githubusercontent.com/84783740/120312792-d3b1b100-c2e1-11eb-859d-755e84e7eb64.png"></td>
  </tr>
</table>

<table>
  <tr>
    <td align="center">Result</td>
  </tr>
  <tr>
    <td><img src="https://user-images.githubusercontent.com/84783740/120312815-dd3b1900-c2e1-11eb-9982-0503d59459e8.png"></td>
  </tr>
</table>

## Usage
1. Add `#include "ft_printf.h"` in your project.
2. Do `make` to compile Ft_printf. After that copy the `libftprintf.a` and `ft_printf.h` and paste them into your project.
3. Compile your project using `gcc YourFileName -L. -lftprintf -I.`.
4. Run your program using `./a.out`.

<table>
  <tr>
    <td align="center">Your program</td>
    <td align="center">Result</td>
  </tr>
  <tr>
    <td><img src="https://user-images.githubusercontent.com/84783740/120312748-c7c5ef00-c2e1-11eb-8297-215bf537989e.png"></td>
    <td><img src="https://user-images.githubusercontent.com/84783740/120312767-cdbbd000-c2e1-11eb-8e4e-38f2508f697e.png"></td>
  </tr>
</table>

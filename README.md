# _printf

This project is a custom printf function implementation in C that formats and prints data to the standard output.

## Overview

This printf implementation supports the following conversion specifiers: 

- %c - Character  
- %s - String
- %d - Signed integer  
- %i - Signed integer
- %b - Signed binary
- %u - Unsigned integer
- %o - Unsigned octal 
- %x - Unsigned hexadecimal integer  
- %X - Unsigned hexadecimal integer (uppercase)
- %p - Pointer address
- %S - Prints a string with non-printable characters
- %r - Prints string in reverse
- %R - Prints string in rot13 cipher
- %% - Prints a percent sign

It handles the following flags:  

- `-` - Left-align within the given field width  
- `+` - Preceed result with plus or minus sign  
- ` ` - (space) If no sign is going to be written, prepend a space 
- `#` - Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively 
- `0` - Left-pads the number with zeroes (0) instead of spaces when padding is specified

It also handles field width, precision, length modifiers and custom specifiers.  

This printf behaves like the standard printf in C, but is implemented by myself without the standard library!  

## Files  

These are the files that make up this printf project:  

| File | Description |  
| :-- | :-- |  
| `_printf.c` | Function similar to printf where format string is parsed to print data accordingly  |
| `main.h` | Header file that contains all function prototypes and macros   |
| `functions_put.c` | Helper functions to write chars and strings to stdout |   
| `functions_print.c` | Functions to handle printing chars, strings, ints, and numbers |
| `functions_specifiers.c` | Functions to handle conversion specifiers (%d, %c, etc)|      
| `get_print.c` | Function to get proper specifier printing function |
|`get_flags.c` | Handles flags parsing |      
| `get_width.c` | Handles width parsing |
| `get_precision.c` |Handles precision parsing |
| `get_length.c` | Handles length modifiers |

## Usage

To use the custom printf:  

```c  
#include "main.h"

printf("String: %s\n", a_string);
printf("Character: %c\n", a_character);  
printf("Decimal: %d\n", a_number);
``` 

## Contributing

Contributions are welcome! Here are some ways you can contribute to this project:

- Report bugs and issues
- Fix bugs and issues
- Add new validation functionality
- Improve styling and overall UX
- Refactor code to improve quality
- Write documentation and improve existing docs

To contribute:
1. Fork the repository
2. Create a new branch
3. Make your changes and commit them
4. Push your branch and submit a pull request

I will review pull requests and provide feedback.

## License

This project is open source and available under the [MIT License](LICENSE).

## Credits

Created by Mohammed Khalid and Mostafa Mokhtar

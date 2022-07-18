# get_next_line
*Reading a line from a fd is way too tedious*

## Introduction
May it be a file, stdin, or even later a network connection, you will always need a way to read content line by line. It is time to start working on this function, which will be essential for your future projects.

## Outline

## Functions Overview

get_next_line functions
| Function | Description |
| :------: | :---------: |
| `find_newline` | Scans string for `'\n'`. Returns `0` if found, otherwise `-1` |
| `read_line` | Reads `BUFFER_SIZE` bytes from `fd` and stores in `storage`. Stops reading when the last read contains a newline. |
| `get_line` | Returns line from `storage`, remaining characters after `'\n'` is stored back into `storage`. |
| `get_next_line` | Returns line or `NULL` if error or nothing left to read. |

get_next_line utility functions
| Function | Description |
| :------: | :---------: |
| `ft_strlen` | Returns length of string. |
| `ft_strdup` | Allocates memory and duplicates string. Returns the duplicated string. |
| `ft_strjoin` | Allocates memory and joins two strings. 
| `ft_substr` | Allocates memory and returns a substring from a string. |
| `ft_free_str` | Safe memory free. |

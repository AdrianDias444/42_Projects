#!/usr/bin/python3

import sys


def main() -> None:
    if len(sys.argv) != 2:
        print("Usage: ft_ancient_text.py <file>")
        sys.exit(1)

    filename: str = sys.argv[1]

    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file '{filename}'")

    try:
        file_obj = open(filename, 'r')

        content: str = file_obj.read()

        print("---")
        print(content, end='')
        print("---")

        file_obj.close()
        print(f"File '{filename}' closed.")

    except FileNotFoundError:
        print(f"Error opening file '{filename}': "
              f"[Errno 2] No such file or directory: '{filename}'")
        sys.exit(1)

    except PermissionError:
        print(f"Error opening file '{filename}': "
              f"[Errno 13] Permission denied: '{filename}'")
        sys.exit(1)

    except IOError as e:
        print(f"Error opening file '{filename}': {e}")
        sys.exit(1)


if __name__ == "__main__":
    main()

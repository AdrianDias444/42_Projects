#!/usr/bin/python3

import sys


def main() -> None:
    if len(sys.argv) != 2:
        print("Usage: ft_ancient_text.py <file>\n")
        sys.exit(1)

    filename: str = sys.argv[1]

    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file '{filename}'")

    try:
        file_obj = open(filename, 'r')

        content = file_obj.read()

        print("---\n")
        print(content)
        print("---")

        file_obj.close()
        print(f"File '{filename}' closed.")

    except FileNotFoundError as e:
        print(f"Error opening file '{filename}': {e}")
    except PermissionError as e:
        print(f"Error opening file '{filename}': {e}")
    except IOError as e:
        print(f"Error opening file '{filename}': {e}")
    finally:
        sys.exit(1)


if __name__ == "__main__":
    main()

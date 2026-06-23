#!/usr/bin/python3

import sys


def main():
    print("=== Command Quest ===")
    args = len(sys.argv)

    if (args < 2):
        print("No arguments provided!")
        print(f"Program name: {sys.argv[0]}")
        print(f"Total arguments: {args}")
    if (args >= 2):
        print(f"Program name: {sys.argv[0]}")
        print(f"Arguments received: {args - 1}")
        i = 1
        while (i < args):
            print(f"Argument {i}: {sys.argv[i]}")
            i += 1
        print(f"Total arguments: {args}")
    print()


if __name__ == "__main__":
    main()

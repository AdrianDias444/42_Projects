#!/usr/bin/python3

def garden_operations(error: int):
    if (error == 0):
        nb = int("abc")
        print(nb)
    elif (error == 1):
        nb2 = 10/0
        print(nb2)
    elif (error == 2):
        open("missing.txt", "r")
    elif (error == 3):
        nb = "str" + 1


def test_error_types():
    print("=== Garden Error Types Demo ===")
    i = 0
    while i < 5:
        print(f"Testing {i}...")

        try:
            out = garden_operations(i)
            print("Operation Completed successfully")
        except ValueError:
            print(f"Caught {i}: invalid literal for int() with base 10")
        except ZeroDivisionError:
            print(f"Caught {i}: division by zero")
        except FileNotFoundError:
            print(f"Caught {i}: no such file or directory")
        except TypeError:
            print(f"Caught {i}: can only concatenate str (not 'int') to str")
        print()
        i += 1
    return (out)


def main():
    test_error_types()
    print("All error types tested successfully!")


if __name__ == "__main__":
    main()

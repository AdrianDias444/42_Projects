#!/usr/bin/python3

class Temp_Limits(Exception):
    pass


def raise_temp_limits(temp_nb) -> None:
    if temp_nb > 40:
        raise Temp_Limits(f"{temp_nb}°C is too hot for plants (max 40°C)")
    elif temp_nb < 0:
        raise Temp_Limits(f"{temp_nb}°C is too cold for plants (min 0°C)")


def input_temperature(temp_str):
    try:
        print(f"Input data is '{temp_str}'")
        nb = int(temp_str)
        raise_temp_limits(nb)
        print(f"Temperature is now {nb}°C\n")
        return (nb)
    except ValueError:
        print("Caught input_temperature error: invalid literal ", end="")
        print(f"for int() with base 10: '{temp_str}'\n")
    except Temp_Limits as e:
        print(f"Caught input_temperature error: {e}\n")


def test_temperature():
    try:
        input_temperature(25)
        input_temperature('abc')
        input_temperature(100)
        input_temperature(-50)
        print("All tests completed - program didn't crash!")
    except Exception:
        print("Input_temperature() fail!, Error catched")



def main():
    print("=== Garden Temperature Checker ===")
    print()
    test_temperature()


if __name__ == "__main__":
    main()

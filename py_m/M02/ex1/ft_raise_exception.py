#!/usr/bin/python

class Temperature_Limits(Exception):
    pass
        
def raise_temperature_limits(temp_nb) -> None:
    if temp_nb > 40:
        raise Temperature_Limits(f"Caught input_temperature error: {temp_nb}°C is too hot for plants (max 40°C)\n")
    elif temp_nb < 0:
        raise Temperature_Limits(f"Caught input_temperature error: {temp_nb}°C is too cold for plants (min 0°C)\n")
def input_temperature(temp_str)-> int:
    try:
        print(f"Input data is '{temp_str}'")
        nb = int(temp_str)
        raise_temperature_limits(nb)
        print(f"Temperature is now {nb}°C\n")
        return (nb)
    except ValueError:
        print(f"Caught input_temperature error: invalid literal for int() with base 10: '{temp_str}'\n")
    except Temperature_Limits as e:
        print(e)
def test_temperature():
    input_temperature(25)
    input_temperature('abc')
    input_temperature(100)
    input_temperature(-50)
    print("All tests completed - program didn't crash!")

def main():
    print("=== Garden Temperature Checker ===")
    print()
    test_temperature()
if __name__ == "__main__":
    main()
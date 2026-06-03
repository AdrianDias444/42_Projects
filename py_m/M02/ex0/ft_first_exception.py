#!/usr/bin/python

def input_temperature(temp_str)-> int:
    try:
        print(f"Input data is '{temp_str}'")
        nb = int(temp_str)
        print(f"Temperature is now {nb}°C\n")
        return (nb)
    except ValueError:
        print(f"Caught input_temperature error: invalid literal for int() with base 10: '{temp_str}'\n")
    
def test_temperature():
    input_temperature(25)
    input_temperature('abc')
    print("All tests completed - program didn't crash!")
    
def  main():
    print("=== Garden Temperature ===\n")
    test_temperature()
            
if __name__ == "__main__":
    main()
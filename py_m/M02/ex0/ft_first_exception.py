def check_temperature(temp_str:str):
    try:
        nb = int(temp_str)
        if(0 <= nb <= 50):
            return nb
        else:
            if(nb < 0):
                print(f"Error: {temp_str}C is too cold for plants (min 0°C)")
            else:
                print(f"Error: {temp_str}C is too hot for plants (max 40°C)")
    except ValueError:
        print(f"Error: '{temp_str}' is not a valid number")


def test_temperature_input():
    print("=== Garden Temperature Checker ===\n")

    test = ["25", "abc", "100", "-50"]
    for a in test:
        print(f"Testing temperature: {a}")
        out = check_temperature(a)
        if(out):
            print(f"Temperature {a}°C is perfect for plants!")

        print()


test_temperature_input()

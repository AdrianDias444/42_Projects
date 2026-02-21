def garden_operations(error:str):
    if(error == "ValueError"):
        nb = int("abc")
    elif(error == "ZeroDivisionError"):
        nb2 = 10/0
    elif (error == "FileNotFoundError"):
        open("missing.txt", "r")
    elif (error == "KeyError"):
        garden_dict = {"tomatoes": 10}
        garden_dict["missing\_plant"]
        
def test_error_types():
    print("=== Garden Error Types Demo ===")

    test = ["ValueError", "ZeroDivisionError",
    "FileNotFoundError", "KeyError"]

    for a in test:
        print(f"Testing {a}...")

        try:
            out = garden_operations(a)
        except ValueError:
            print(f"Caught {a}: invalid literal for int()")            
        except ZeroDivisionError:
            print(f"Caught {a}: division by zero")
        except FileNotFoundError:
            print(f"Caught {a}: no such file 'missing.txt'")
        except KeyError:
            print(f"Caught {a}: 'missing\_plant'")
        print()

test_error_types()



a = int("212s13")


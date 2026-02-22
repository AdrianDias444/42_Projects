class VoidError(Exception):
    pass

def raise_void_error(plant):
    if(plant.strip(" ") == ""):
        raise VoidError ("Cannot water be void - invalid plant!")



def water_plants(plant_list):
    print("Opening watering system")
    try:
        for plant in plant_list:
            if plant == None:
                plant = ""
            raise_void_error(plant)
            print(f"Watering {plant}")
    except VoidError as e:
        print(e)
    finally:
        print("Closing watering system (cleanup)")

    print("Watering completed successfully!")

def test_watering_system():
    plants = ["tomato", "lettuce", "carrots"]
    water_plants(plants)    
    
    print()
    print("Testing with error...")
    plants_errors = ["tomato", "l", None]
    water_plants(plants_errors)




if __name__ == "__main__":
    print("=== Garden Watering System ===\n")

    print("Testing normal vatering...")
    test_watering_system()

    print("\nCleanup always happens, even with errors")
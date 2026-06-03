#!/usr/bin/python

class PlantError(Exception):
    pass

def water_plant(plant_name:str):
    if plant_name == plant_name.capitalize():
        print(f"Watering {plant_name}: [OK]")
    else:
        raise PlantError(f"Caught PlantError: Invalid plant name to water: '{plant_name}'")

def test_watering_system():
    print("Testing valid plants...")
    plants1 = ["Tomato", "Letuce", "Carrots"]
    
    try:
        print("Opening watering system")
        for a in plants1:
            water_plant(a)
    except PlantError as e:
        print(e)
        print(".. ending tests and returning to main")
    finally:
        print("Closing watering system")
    print("\nTesting invalid plants...")
    plants2 = ["Tomato", "lettuce", "Carrots"]
    try:
        print("Opening watering system")
        for a in plants2 :
            water_plant(a)
    except PlantError as e:
        print(e)
        print(".. ending tests and returning to main")
    finally:
        print("Closing watering system")
    print("\nCleanup always happens, even with errors!")


def main():
    print("=== Garden Watering System ===\n")
    test_watering_system()
    
if __name__ == "__main__":
    main()
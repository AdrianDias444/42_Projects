class VoidError(Exception):
    pass

class WaterError(Exception):
    pass

class SunlightError(Exception):
    pass

def check_plant_health(plant_name, water_level, sunlight_hours):
    if(not plant_name or plant_name.strip(" ") == ""):
        raise VoidError("Plant name cannot be empty!\n")

    if(not(1 <= water_level <= 10)):
        if(water_level > 10):
            raise WaterError(f"Water level {water_level} is too high (max 10)")
        else:
            raise WaterError(f"Water level {water_level} is too low (min 1)")

    if(not(2 <= sunlight_hours <= 12)):
        if(sunlight_hours > 12):
            raise SunlightError(f"Sunlight hours {sunlight_hours} is too high (max 12)")
        else:
            raise SunlightError(f"Sunlight hours {sunlight_hours} is too low (min 2)")


def test_plant_checks():

    print("Testing good values...")
    plant = "tomato"
    try:
        check_plant_health(plant, 5, 10)
        print(f"Plant '{plant}' is healthy!\n")
    except:
        print("Error")

    print("Testing empty plant names...")
    plant2 = None
    try:
        check_plant_health(plant2, 5, 10)
        print(f"Plant '{plant2}' have a valid name\n")
    except VoidError as e:
            print(f"Error: {e}")

    print("Testing bad water level...")
    try:
        check_plant_health("tomato", 50, 10)
        print(f"Water level is good\n")
    except WaterError as e:
            print(f"Error: {e}\n")

    print("Testing bad sunlight hours...")
    try:        
        check_plant_health("tomato", 5, 0)
        print(f"Great Sunlight hours\n")
    except SunlightError as e:
        print(f"Error: {e}")


if __name__ == "__main__":
    print("=== Garden Plant Health Checker ===\n")

    test_plant_checks()

    print("\nAll error raising tests completed!")
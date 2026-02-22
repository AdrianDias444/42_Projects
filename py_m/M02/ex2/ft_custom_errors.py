class GardenError(Exception):
    pass

class PlantError(GardenError):
    pass

class WaterError(GardenError):
    pass

def raise_garden_error(number_of_tomatos:int):
    if (number_of_tomatos < 0):
        raise GardenError("Its too hot")

def raise_plant_error(plants_age:int):
    if (plants_age < 0):
        raise PlantError("The tomato plant is wilting")

def raise_water_error(last_watering:int):
    if(last_watering > 3):
        raise WaterError("Not enough water in the tank")


if __name__ == "__main__":
    print("=== Custom Garden Errors Demo ===\n")

    testing = ["GardenError", "PlantError", "WaterError"]
    
    print("Testing PlantError...")
    try:
        raise_plant_error(-12)
    except PlantError as e:
        print(f"Caught PlantError: {e}\n")

    print("Testing WaterError")
    try:
        raise_water_error(4)
    except WaterError as e:
        print(f"Caught WaterError: {e}\n")
    
    print("Testing catching all garden errors...")

    try:
        raise_plant_error(-12)
    except GardenError as e:
        print(f"Caught a garden error: {e}")

    try:
        raise_water_error(4)
    except GardenError as e:
        print(f"Caught a garden error: {e}")
    print("\nAll custom error type work correctly!")
#!/usr/bin/python3

class GardenError(Exception):
    pass


class PlantError(GardenError):
    pass


class WaterError(GardenError):
    pass


def raise_garden_error(number_of_plants: int):
    if (number_of_plants < 0):
        raise GardenError("Have not plants in garden")


def raise_plant_error(sun_hours_per_day: int):
    if (sun_hours_per_day < 0):
        raise PlantError("The tomato plant is wilting")


def raise_water_error(water_tank: int):
    if (water_tank < 3):
        raise WaterError("Not enough water in the tank")


def test_custom_errors():
    print("=== Custom Garden Errors Demo ===\n")

    print("Testing PlantError...")
    try:
        raise_plant_error(-12)
    except PlantError as e:
        print(f"Caught PlantError: {e}\n")

    print("Testing WaterError")
    try:
        raise_water_error(2)
    except WaterError as e:
        print(f"Caught WaterError: {e}\n")

    print("Testing catching all garden errors...")
    try:
        raise_plant_error(-12)
    except GardenError as e:
        print(f"Caught a garden error: {e}")
    try:
        raise_water_error(2)
    except GardenError as e:
        print(f"Caught a garden error: {e}")
    print("\nAll custom error type work correctly!")


def main():
    test_custom_errors()


if __name__ == "__main__":
    main()

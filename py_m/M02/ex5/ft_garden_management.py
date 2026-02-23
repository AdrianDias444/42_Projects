class VoidError(Exception):
    pass

class WaterError(Exception):
    pass

class SunlightError(Exception):
    pass

class ExistError(Exception):
    pass

class ErrorRecovery(Exception):
    pass

class Plant():
    def __init__(self, name:str, water:int, sun:int):
        self.name = name
        self.water = water
        self.sun = sun


def raise_void_error(plant:Plant):
    if(plant.strip(" ") == ""):
        raise VoidError("Error adding plant: Plant name cannot be empty!")

def raise_water_error(plant:Plant):
    if(1 <= plant.water <= 10):
        return
    else:
        if(plant.water > 10):
            raise WaterError(f"{plant.name}: water level {plant.water} is too high (max 10)")
        else:
            raise WaterError(f"{plant.name}: water level {plant.water} is too low (min 1)")

def raise_sunlight_error(plant:Plant):
    if(not(2 <= plant.sun <= 12)):
        if(plant.sun > 12):
            raise SunlightError(f" {plant.name}: sunlight hours {plant.sun} is too high (max 12)")
        else:
            raise SunlightError(f" {plant.name}: sunlight hours {plant.sun} is too low (min 2)")

def raise_exist_error(plant:Plant, plants):
    if plant in plants:
        return
    else:
        raise ExistError("The plant doesnt exist, what are you trying to do bro:)")

def raise_error_recovery(water_tank:int):
    if(0 > water_tank):
        raise ErrorRecovery("Not enought water in tank")
    else:
        return
class GardenManager():
    def __init__(self, name:str, water_tank:int):
        self.name = name
        self.plants = []
        self.number = 0
        self.water_tank = water_tank

    def add_plant(self, plant:Plant):
        try:
            raise_void_error(plant.name)
            self.plants.append(plant)
            print(f"Added {plant.name} successfully")
            self.number += 1
        except VoidError as e:
            print(e)

    def water_plant(self, plants):
        print("Opening watering system")
        for plant in plants:
            print(f"Watering {plant.name} - success")
            plant.water+= 3
            self.water_tank -=3
        print("Closing watering system (cleanup)")
    
    def check_plants_health(self, plant):
        try:
            raise_exist_error(plant, self.plants)
        except ExistError as e:
            print(e)

        try:
            raise_water_error(plant)        
        except WaterError as e:
            print(f"Error checking {e}")

        try:
            raise_sunlight_error(plant)
        except SunlightError as e:
            print(f"Error checking{e}")

    def error_recovery(self, plants):
        try:
            for plant in plants:
                raise_error_recovery(self.water_tank)
        except ErrorRecovery as e:
            print(f"Caught GardenError: {e}")
        finally:
            print("System recovered an continuing")

    def add_water_to_tank(self):
        self.water_tank += 10
def test_garden_management():
    garden = GardenManager("Adrian", 8)

    print("Adding plants to garden...")
    
    name = ["tomato", "lettuce", "apple"]
    for i in name:
        plant = Plant(i, 53, 22)
        garden.add_plant(plant)
    
    print("\nWatering plants...")
    plants = garden.plants
    garden.water_plant(plants)

    print("\nChecking plant health...")
    for i in plants:
        garden.check_plants_health(i)

    print("\nTesting error recovery...")
    garden.error_recovery(plants)

    print("Garden management system test complete")

if __name__ == "__main__":
    test_garden_management()
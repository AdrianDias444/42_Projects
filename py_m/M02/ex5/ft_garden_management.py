class VoidError(Exception):
    pass

class WaterError(Exception):
    pass

class SunlightError(Exception):
    pass

class Plant():
    def __init__(self, name:str, water:str, sun:str):
        self.name = name
        self.water = water
        self.sun = sun


def raise_void_error(plant:Plant):
    if(plant.strip(" ") == ""):
        raise VoidError("Plant name cannot be empty!\n")

def raise_water_error(water_level:int):
    if(not(1 <= water_level <= 10)):
        if(water_level > 10):
            raise WaterError(f"Water level {water_level} is too high (max 10)")
        else:
            raise WaterError(f"Water level {water_level} is too low (min 1)")

def raise_sunlight_error(sunlight_hours:int):
    if(not(2 <= sunlight_hours <= 12)):
        if(sunlight_hours > 12):
            raise SunlightError(f"Sunlight hours {sunlight_hours} is too high (max 12)")
        else:
            raise SunlightError(f"Sunlight hours {sunlight_hours} is too low (min 2)")




class GardenManager():
    def __init__(self, name:str, number:int):
        self.name = name
        self.plants = []
        self.number = number

    def add_plant(self, plant:Plant):
        try:
            raise_void_error(plant.name)
            self.plants.append(plant)
        except:
            print("Error adding plant: Plant name cannot be empty!")

    def water_plant(self, plant:Plant):
        print("Watering plants...")
        try:
            self.plants[plant]
            plant.water += 3
        except KeyError:
            print("This plant doesnt exist, what are you trying to do bro:)")
    def check_plants_health(self, plant:Plant):
        try:
            self.plants[plant]
            print("Checking plant health")

        except KeyError:
            print("This plant doesnt exist, what are you trying to do bro:)")

            
        




def test_garden_management():
    pass



if __name__ == "__main__":
    pass
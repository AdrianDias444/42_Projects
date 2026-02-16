if __name__ == "__main__"
    class Plant:
        def __init__(self, name:str, height:int, age:int):
            self.name = name
            self.height = height
            self.age = age

        def get_info(plant:Plant):
            print(f"{plant.name}: {plant.height}cm, {plant.age} days old")
        def grow(plant:Plant):
            plant.height = plant.height+6
        def age(plant:Plant):
            plant.age = plant.age+6

    plant = Plant("Rose", 25, 30)
    height_initial = plant.height
    print("=== Day 1 ===")

    Plant.get_info(plant)

    print("=== Day 7 ===")
    Plant.grow(plant)
    Plant.age(plant)
    Plant.get_info(plant)

    print(f"Growth this week + {plant.height - height_initial}cm")
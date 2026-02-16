if __name__ == "__main__":
    class Plant:
        def __init__(self, name:str, height:int, age:int):
            self.name = name
            self.height = height
            self.age = age

        def get_info(plant:Plant):
            return plant.name, plant.height, plant.age
        
        def set_height(plant:Plant, new_height:int):
            if(new_height > 0):
                print(f"Height updated: {new_height}cm")
                plant.height = new_height
            else:
                print(f"Invalid operation attempted: height {new_height} [REJECTED]")
        
        def set_age(plant:Plant, new_age:int):
            if(new_age > 0):
                print(f"Age updated: {new_age} days")
                plant.age = new_age
            else:
                print("Negative height rejected")

        

    plant = Plant("Rose", 30, 5)

    print("=== Garden Security System ===")
    print(f"Plant created: {plant.get_info()[0]}")

    print()
    plant.set_height(25)
    plant.set_age(30)
    print()
    plant.set_height(-5)
    plant.set_age(-1)

    print(f"\nCurrent plant: {plant.name} ({plant.height}cm, {plant.age} days)")
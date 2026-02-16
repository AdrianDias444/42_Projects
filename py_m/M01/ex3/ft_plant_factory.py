if __name__ == "__main__":
    class Plant:
        def __init__(self, name:str, height:int, age:int):
            self.name = name
            self.height = height
            self.age = age
        def get_info(plant:Plant):
            print(f"Created: {plant.name} ({plant.height}cm, {plant.age} days old)")

    plant = [Plant("Rose", 25, 30), Plant("Oak", 200, 365), Plant("Cactus", 5, 90), Plant("Sunflower", 80, 45), Plant("Fern", 15, 120)]

    j = 0
    for i in plant:
        i.get_info()
        j+=1

    print(f"Total plants created: {j}")

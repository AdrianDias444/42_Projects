class Plant():
    def __init__(self, name:str, height:int, age:int):
        self.name = name
        self.height = height
        self.age = age
    def grow(self):
        self.height += 1
        print(f"{self.name} grew 1cm")
class FloweringPlant(Plant):
    def __init__(self, name:str, height:int, age:int, color:str):
        super().__init__(name, height, age)
        self.color = color

class PrizeFlower(FloweringPlant):
    def __init__(self, name:str, height:int, age:int, color:str):
        super().__init__(name, height, age)

def create_garden_network():

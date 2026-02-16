class Plant:
    def __init__(self, name:str, height:int, age:int):
        self.name = name
        self.height = height
        self.age = age

class Flower(Plant):
    def __init__(self, name:str, height:int, age:int, color:str):
        super().__init__(name, height, age)
        self.color = color
    def bloom(self):
        print(f"{self.name} is blooming beautifully!")
    def get_info(self):
        print(f"{self.name}(Flower): {self.height}cm, {self.age} days, {self.color} color")

class Tree(Plant):
    def __init__(self, name:str, height:int, age:int, trunk_diameter:int):
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter
    def produce_shade(self):
        print(f"{self.name} provides {1.56*self.trunk_diameter} square meters of shade")
    def get_info(self):
        print(f"{self.name} (Tree): {self.height}cm, {self.age} days, {self.trunk_diameter}cm diameter")
    
class Vegetable(Plant):
    def __init__(self, name:str, height:int, age:int, harvest_season:str, nutritional_value:str):
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value
    def get_info(self):
        print(f"{self.name} (Vegetable): {self.height}cm, {self.age} days, {self.harvest_season} harvest\n{self.name} is rich in {self.nutritional_value}")

print("=== Garden Plant Types ===")

flower = Flower("Rose", 25, 30, "red")
tree = Tree("Oak", 500, 1825, 50)
vegetable = Vegetable("Tomato", 80, 90, "summer", "vitamin C")

print()
flower.get_info()
flower.bloom()
print()
tree.get_info()
tree.produce_shade()
print()
vegetable.get_info()
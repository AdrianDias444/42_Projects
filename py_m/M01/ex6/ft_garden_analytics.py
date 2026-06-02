#!/usr/bin/python3

class Plant:
    class data():
        def __init__(self):
            self.grow_calls = 0
            self.age_count = 0
            self.show_count = 0
        def add_grow_calls(self) -> None:
            self.grow_calls += 1
        def add_age_calls(self) -> None:
            self.age_count += 1
        def add_show_count(self) -> None:
            self.show_count += 1
            
    def __init__(self, name: str, height: float, age_days: int) -> None:
        self.name = name
        self.height = height
        self.age_days = age_days
        self.stats = self.data()
    def grow(self) -> None:
        self.height += 21
        self.stats.add_grow_calls()
    def age(self) -> None:
        self.age_days += 20
        self.stats.add_age_calls()
    def display(self) -> None:
        print(f"[statistic for {self.name}]")
        print(f"Stats: {self.stats.grow_calls} grow, {self.stats.age_count} age, {self.stats.show_count} show")
        
    @classmethod
    def create_anonymous_plant(cls) -> Plant:
        return cls("Unknown plant", 0.0, 0)
    @staticmethod
    def older_than_an_year(age:int) -> bool:
        if age > 365:
            return True
        else:
            return False
    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.age_days} days old")
        self.stats.add_show_count()
class Flower(Plant):
    def __init__(self, name: str, height: float, age_days: int, color: str):
        super().__init__(name, height, age_days)
        self.color = color
        self.bloomed = False
    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.age_days} days old")
        print(f" Color: {self.color}")
        if self.bloomed:
            print(f" {self.name} is blooming beautifully!")
        else:
            print(f" {self.name} has not bloomed yet")
        self.stats.add_show_count()
        
        
    def bloom(self) -> None:
        print(f"[Asking the {self.name} to bloom]")
        self.bloomed = True
        
class Seed(Flower):
    def __init__(self, name:str, height:float, age_days:int, color:str):
        super().__init__(name, height, age_days, color)
        self.number_of_seeds = 0
        self.bloomed = False
    def bloom(self) -> None:
        super().bloom()
        self.number_of_seeds = 42
    def show(self) -> None:
        super().show()
        print(f"Seeds: {self.number_of_seeds}")

class Tree(Plant):
    class Data(Plant.data):
        def __init__(self):
            super().__init__()
            self.shade_count = 0
        def shade_call(self) -> None:
            self.shade_count += 1
    def __init__(self, name: str, height: float, age_days: int, trunk_diameter: float) -> None:
        super().__init__(name, height, age_days)
        self.trunk_diameter = trunk_diameter
        self.stats = self.Data()

    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.age_days} days old")
        print(f" Trunk diameter: {self.trunk_diameter}")
        self.stats.add_show_count()
    def produce_shade(self) -> None:
        print(f"[Asking the {self.name} to produce shade]")
        print(f"Tree {self.name} now produces a shade of ", end="")
        print(f"{self.height}cm and {self.trunk_diameter}cm wide.")
        self.stats.shade_call()
    def display(self) -> None:
        print(f"[statistic for {self.name}]")
        print(f"Stats: {self.stats.grow_calls} grow, {self.stats.age_count} age, {self.stats.show_count} show")
        print(f"{self.stats.shade_count} shade")
        

def display_plant_stats(plant):
    plant.display()    
    
def main():
    print("=== Garden Statistics ===")
    print("=== Check year-old")
    plant1 = Flower("Rose", 15.0, 30, "red")
    plant2 = Tree("Oak", 110.0, 400, 5.0)
    print("Is 30 days more than a year? -> ", plant1.older_than_an_year(plant1.age_days))
    print("Is 400 days more than a year? ->", plant2.older_than_an_year(plant2.age_days))
    
    print()
    print("=== Flower")
    plant1.show()
    plant1.display()
    print(f"[asking the {plant1.name} to grow and bloom]")
    plant1.grow()
    plant1.bloom()
    plant1.show()
    plant1.display()
    
    print()
    print("=== Tree")
    plant2.show()
    plant2.display()
    plant2.produce_shade()
    plant2.display()
    
    plant3 = Seed("Sunflower", 80.0, 45, "yellow")
    print()
    print("=== Seed")
    plant3.show()
    print(f"[make the {plant3.name} grow, age and bloom]")
    plant3.grow()
    plant3.age()
    plant3.bloom()
    plant3.show()
    plant3.display()
    
    print()
    print("=== Anonymous")
    anonymous = Plant.create_anonymous_plant()
    anonymous.show()
    display_plant_stats(anonymous)
    
if __name__ == "__main__":
    main()

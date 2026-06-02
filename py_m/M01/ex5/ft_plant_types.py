#!/usr/bin/python3

class Plant:
    def __init__(self, name: str, height: float, age_days: int) -> None:
        self.name = name
        self.height = height
        self.age_days = age_days
    def grow(self) -> None:
        self.height += 21
    def age(self) -> None:
        self.age_days += 20

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
        
    def bloom(self) -> None:
        print(f"[Asking the {self.name} to bloom]")
        self.bloomed = True

class Tree(Plant):
    def __init__(self, name: str, height: float, age_days: int, trunk_diameter: int) -> None:
        super().__init__(name, height, age_days)
        self.trunk_diameter = trunk_diameter

    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.age_days} days old")
        print(f" Trunk diameter: {self.trunk_diameter}")
    def produce_shade(self) -> None:
        print(f"[Asking the oak to produce shade]")
        print(f"Tree {self.name} now produces a shade of ", end="")
        print(f"{self.height}cm and {self.trunk_diameter}cm wide.")

class Vegetable(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        age_days: int,
        harvest_season: str,
        nutritional_value: int,
    ) -> None:
        super().__init__(name, height, age_days)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value
    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.age_days} days old")
        print(f" Harvest season: {self.harvest_season}")
        print(f" Nutritional value: {self.nutritional_value}")
    def grow_and_age(self):
        print(f"[make {self.name} grow and age for 20 days]")
        self.nutritional_value += 20
        self.grow()
        self.age()
def main():
    print("=== Garden Plant Types ===")
    flower = Flower("Rose", 15, 10, "red")
    tree = Tree("Oak", 200, 365, 5)
    vegetable = Vegetable("Tomato", 5, 10, "April", 0)

    print("=== Flower")
    flower.show()
    flower.bloom()
    flower.show()
    print()
    print("=== Tree")
    tree.show()
    tree.produce_shade()
    print()
    print("=== Vegetable")
    vegetable.show()
    vegetable.grow_and_age()
    vegetable.show()
if __name__ == "__main__":
    main()

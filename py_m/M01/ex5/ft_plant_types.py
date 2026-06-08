#!/usr/bin/python3

class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def show(self) -> str:
        return f"{self.name}: {round(self.height,1)}cm, {self.age} days old"

    def grow(self) -> None:
        self.height += 42

    def increse_age(self) -> None:
        self.age += 20


class Flower(Plant):
    def __init__(self, name: str, height: float, age: int, color: str):
        super().__init__(name, height, age)
        self.color = color
        self.bloomed = False

    def show(self) -> str:
        print(f"{self.name}: {self.height}cm, {self.age} days old")
        print(f" Color: {self.color}")
        if self.bloomed:
            print(f" {self.name} is blooming beautifully!")
        else:
            print(f" {self.name} has not bloomed yet")
        return ("")

    def bloom(self) -> None:
        print(f"[Asking the {self.name} to bloom]")
        self.bloomed = True


class Tree(Plant):
    def __init__(self, name: str, height: float, age: int, trunk: int) -> None:
        super().__init__(name, height, age)
        self.trunk_diameter = trunk

    def show(self) -> str:
        print(f"{self.name}: {self.height}cm, {self.age} days old")
        print(f" Trunk diameter: {self.trunk_diameter}")
        return ("")

    def produce_shade(self) -> None:
        print("[Asking the oak to produce shade]")
        print(f"Tree {self.name} now produces a shade of ", end="")
        print(f"{self.height}cm and {self.trunk_diameter}cm wide.")


class Vegetable(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        age: int,
        harvest_season: str,
        nutritional_value: int,
    ) -> None:
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value

    def show(self) -> str:
        print(f"{self.name}: {self.height}cm, {self.age} days old")
        print(f" Harvest season: {self.harvest_season}")
        print(f" Nutritional value: {self.nutritional_value}")
        return ("")

    def grow_and_age(self):
        print(f"[make {self.name} grow and age for 20 days]")
        self.nutritional_value += 20
        self.grow()
        self.increse_age()


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

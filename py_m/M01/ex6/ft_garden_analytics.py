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
class Seed(Flower):
    def __init__(self, name:str, height:float, age_days:int, color:str)
        
def main():


if __name__ == "__main__":
    main()

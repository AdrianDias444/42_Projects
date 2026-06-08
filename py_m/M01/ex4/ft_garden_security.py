#!/usr/bin/python3


class Plant:
    def __init__(self, name: str, height: float, age_days: int):
        self.name = name
        self.height = height
        self.age = age_days

    def show(self) -> str:
        return f"{self.name}: {round(self.height,1)}cm, {self.age} days old"

    def get_height(self) -> float:
        return self.height

    def get_age(self) -> int:
        return self.age

    def set_height(self, new_height: int) -> None:
        if new_height > 0:
            print(f"Height updated: {new_height}cm")
            self.height = new_height
        else:
            print(f"{self.name}: Error, height cant't be negative")
            print("Height update rejected")

    def set_age(self, new_age: int) -> None:
        if new_age > 0:
            print(f"Age updated: {new_age} days")
            self.age = new_age
        else:
            print(f"{self.name}: Error, age can't be negative")
            print("Age update rejected")


def main():
    plant = Plant("Rose", 15, 10)

    print("=== Garden Security System ===")
    print(f"Plant created: {plant.show()}")

    print()
    plant.set_height(25)
    plant.set_age(30)
    print()
    plant.set_height(-5)
    plant.set_age(-1)

    print(f"\nCurrent state: {plant.show()}")


if __name__ == "__main__":
    main()

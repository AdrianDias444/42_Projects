#!/usr/bin/python3


class Plant:
    def __init__(self, name: str, height: float, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def show(self) -> None:
        print(f"Created: {self.name}: {self.height}cm, {self.age} days old")

    def grow(self) -> None:
        self.height += 0.55


def main():
    print("=== Plant Factory Output ===")
    plant = [
        Plant("Rose", 25, 30),
        Plant("Oak", 200, 365),
        Plant("Cactus", 5, 90),
        Plant("Sunflower", 80, 45),
        Plant("Fern", 15, 120),
    ]

    j = 0
    for i in plant:
        i.show()
        j += 1

    print(f"Total plants created: {j}")


if __name__ == "__main__":
    main()

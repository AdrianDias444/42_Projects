#!/usr/bin/python3


class Plant:
    def __init__(self, name: str, height: float, age_days: int) -> None:
        self.name = name
        self.height = height
        self.age_days = age_days

    def show(self) -> None:
        print(f"{self.name}: {round(self.height, 2)}cm, ", end="")
        print(f"{self.age_days} days old")

    def grow(self) -> None:
        self.height += 0.55

    def age(self) -> None:
        self.age_days += 1


def main():
    plant = Plant("Rose", 25, 30)
    initial_height = plant.height
    print("=== Garden Plant Growth ===")
    plant.show()
    for i in range(1, 8):
        print(f"=== Day {i} ===")
        plant.grow()
        plant.age()
        plant.show()

    growth = round(plant.height - initial_height, 2)
    print(f"Growth this week + {growth}cm")


if __name__ == "__main__":
    main()

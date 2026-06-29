from ex1 import HealingCreatureFactory, TransformCreatureFactory


def main():
    try:
        print("Testing Creature with healing capability\n base:")
        sproutling = HealingCreatureFactory.create_base()
        print(sproutling.describe())
        print(sproutling.attack())
        print(sproutling.heal())
        print(" evolved:")
        bloomelle = HealingCreatureFactory.create_evolved()
        print(bloomelle.describe())
        print(bloomelle.attack())
        print(bloomelle.heal(sproutling))
    except Exception as err:
        print(f"\33[31mERROR: {err}\33[0m")

    try:
        print("\nTesting Creature with transform capability\n base:")
        shiftling = TransformCreatureFactory.create_base()
        print(shiftling.describe())
        print(shiftling.attack())
        print(shiftling.transform())
        print(shiftling.attack())
        print(shiftling.revert())
        print(" evolved:")
        morphagon = TransformCreatureFactory.create_evolved()
        print(morphagon.describe())
        print(morphagon.attack())
        print(morphagon.transform())
        print(morphagon.attack())
        print(morphagon.revert())
    except Exception as err:
        print(f"\33[31mERROR: {err}\33[0m")


if __name__ == "__main__":
    main()

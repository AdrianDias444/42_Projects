import ex0 as f


def main():
    try:
        flameling = f.FlameFactory.create_base()
        print("Testing factory")
        print(flameling.describe())
        print(flameling.attack())
        pyrodon = f.FlameFactory.create_evolved(flameling)
        print(pyrodon.describe())
        print(pyrodon.attack())

        print("\nTesting factory")
        aquabub = f.AquaFactory.create_base()
        print(aquabub.describe())
        print(aquabub.attack())
        torragon = f.AquaFactory.create_evolved(aquabub)
        print(torragon.describe())
        print(torragon.attack())

        print("\nTesting battle")
        print(flameling.describe())
        print(" vs.")
        print(aquabub.describe())
        print(" fight!")
        print(flameling.attack())
        print(aquabub.attack())

    except ValueError as err:
        print(f"\33[31mERROR: {err}\33[0m")


if __name__ == "__main__":
    main()

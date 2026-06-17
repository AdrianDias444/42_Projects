from ex0 import FlameFactory, AquaFactory

def test_factory(factory):
    print("Testing factory")
    
    base = factory.create_base()
    print(base.describe())
    print(base.attack())
    
    evolved = factory.create_evolved()
    print(evolved.describe())
    print(evolved.attack())
    
    print()

def battle_factory(factory1, factory2):
    print("Testing battle")
    
    creature1 = factory1.create_base()
    creature2 = factory2.create_base()
    
    print(creature1.describe())
    print("vs.")
    print(creature2.describe())
    print("fight!")
    print(creature1.attack())
    print(creature2.attack())
    print()

def main():
    flame_factory = FlameFactory()
    aqua_factory = AquaFactory()
    
    test_factory(flame_factory)
    test_factory(aqua_factory)
    
    battle_factory(flame_factory, aqua_factory)

if __name__ == "__main__":
    main()
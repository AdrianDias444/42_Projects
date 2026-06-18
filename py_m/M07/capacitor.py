from ex1 import HealingCreatureFactory, TransformCreatureFactory

def test_healing_factory():
    print("Testing Creature with healing capability")
    
    factory = HealingCreatureFactory()
    
    print("base:")
    base = factory.create_base()
    print(base.describe())
    print(base.attack())
    print(base.heal())
    
    print("evolved:")
    evolved = factory.create_evolved()
    print(evolved.describe())
    print(evolved.attack())
    print(evolved.heal())
    print()

def test_transform_factory():
    print("Testing Creature with transform capability")
    
    factory = TransformCreatureFactory()
    
    print("base:")
    base = factory.create_base()
    print(base.describe())
    print(base.attack())
    print(base.transform())
    print(base.attack())
    print(base.revert())
    
    print("evolved:")
    evolved = factory.create_evolved()
    print(evolved.describe())
    print(evolved.attack())
    print(evolved.transform())
    print(evolved.attack())
    print(evolved.revert())

def main():
    test_healing_factory()
    test_transform_factory()

if __name__ == "__main__":
    main()
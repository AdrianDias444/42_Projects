from ex0 import FlameFactory, AquaFactory
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex2 import NormalStrategy, AggressiveStrategy, DefensiveStrategy, InvalidStrategyError

def battle(opponents: list[tuple]) -> None:
    print("*** Tournament ***")
    print(f"{len(opponents)} opponents involved")
    
    creatures = []
    for factory, strategy in opponents:
        creature = factory.create_base()
        creatures.append((creature, strategy))
    
    for i in range(len(creatures)):
        for j in range(i + 1, len(creatures)):
            creature1, strategy1 = creatures[i]
            creature2, strategy2 = creatures[j]
            
            print("* Battle *")
            print(creature1.describe())
            print("vs.")
            print(creature2.describe())
            print("now fight!")
            
            try:
                if not strategy1.is_valid(creature1):
                    raise InvalidStrategyError(creature1.name, 
                                             strategy1.__class__.__name__.replace('Strategy', '').lower())
                if not strategy2.is_valid(creature2):
                    raise InvalidStrategyError(creature2.name, 
                                             strategy2.__class__.__name__.replace('Strategy', '').lower())
                
                strategy1.act(creature1)
                strategy2.act(creature2)
                
            except InvalidStrategyError as e:
                print(f"Battle error, aborting tournament: {e}")
                return  # Aborta o torneio
            
            print()

def main():
    flame_factory = FlameFactory()
    aqua_factory = AquaFactory()
    healing_factory = HealingCreatureFactory()
    transform_factory = TransformCreatureFactory()
    
    normal = NormalStrategy()
    aggressive = AggressiveStrategy()
    defensive = DefensiveStrategy()
    
    print("Tournament 0 (basic)")
    print("[ (Flameling+Normal), (Healing+Defensive) ]")
    opponents = [
        (flame_factory, normal),
        (healing_factory, defensive)
    ]
    battle(opponents)
    print()
    
    print("Tournament 1 (error)")
    print("[ (Flameling+Aggressive), (Healing+Defensive) ]")
    opponents = [
        (flame_factory, aggressive),  # ❌ Flameling NÃO tem TransformCapability!
        (healing_factory, defensive)
    ]
    battle(opponents)
    print()
    
    print("Tournament 2 (multiple)")
    print("[ (Aquabub+Normal), (Healing+Defensive), (Transform+Aggressive) ]")
    opponents = [
        (aqua_factory, normal),
        (healing_factory, defensive),
        (transform_factory, aggressive)
    ]
    battle(opponents)

if __name__ == "__main__":
    main()
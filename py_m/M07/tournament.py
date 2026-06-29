from ex0.creature import Creature
from ex0 import FlameFactory, AquaFactory
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex2.strategies import BattleStrategy, NormalStrategy, \
                        AggressiveStrategy, DefensiveStrategy, CreatureError


def battle(creature1: Creature, creature1_strat: BattleStrategy,
           creature2: Creature, creature2_strat: BattleStrategy) -> None:
    print("\n* Battle *")
    print(creature1.describe())
    print(" vs.")
    print(creature2.describe())
    print(" now fight!")
    try:
        creature1_strat.act()
        creature2_strat.act()
    except CreatureError as err:
        print(f"Battle error, aborting tournament: {err}")


def main():
    flameling = FlameFactory.create_base()
    sproutling = HealingCreatureFactory.create_base()
    aquabub = AquaFactory.create_base()
    shiftling = TransformCreatureFactory.create_base()

    flameling_normal = NormalStrategy(flameling)
    sproutling_defensive = DefensiveStrategy(sproutling)
    flameling_aggressive = AggressiveStrategy(flameling)
    aquabub_normal = NormalStrategy(aquabub)
    shiftling_aggressive = AggressiveStrategy(shiftling)

    print("Tournament 0 (basic)\n"
          "[ (Flameling+Normal), (Healing+Defensive) ]\n"
          "*** Tournament ***\n"
          "2 opponents involved")
    battle(flameling, flameling_normal, sproutling, sproutling_defensive)

    print("\nTournament 1 (error)\n"
          "[ (Flameling+Aggressive), (Healing+Defensive) ]\n"
          "*** Tournament ***\n"
          "2 opponents involved")
    battle(flameling, flameling_aggressive, sproutling, sproutling_defensive)

    print("\nTournament 2 (multiple)\n"
          "[ (Aquabub+Normal), (Healing+Defensive), (Transform+Aggressive) ]\n"
          "*** Tournament ***\n"
          "3 opponents involved")
    battle(aquabub, aquabub_normal, sproutling, sproutling_defensive)
    battle(aquabub, aquabub_normal, shiftling, shiftling_aggressive)
    battle(sproutling, sproutling_defensive, shiftling, shiftling_aggressive)


if __name__ == "__main__":
    main()

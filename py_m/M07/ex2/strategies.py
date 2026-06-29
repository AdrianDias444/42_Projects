from abc import ABC, abstractmethod
from ex0.creature import Creature


class CreatureError(Exception):
    pass


class BattleStrategy(ABC):
    def __init__(self, creature: Creature) -> None:
        self.creature = creature

    @abstractmethod
    def act(self) -> None:
        pass

    @abstractmethod
    def is_valid(self) -> bool:
        pass


class NormalStrategy(BattleStrategy):
    def __init__(self, creature: Creature):
        super().__init__(creature)
        self.strat_type = "Normal"

    def act(self) -> None:
        if not self.is_valid():
            raise CreatureError(f"Invalid Creature '{self.creature.name}'"
                                f" for this {self.strat_type} strategy")
        print(self.creature.attack())

    def is_valid(self) -> bool:
        return hasattr(self.creature, "attack")


class AggressiveStrategy(BattleStrategy):
    def __init__(self, creature: Creature):
        super().__init__(creature)
        self.strat_type = "Aggressive"

    def act(self):
        if not self.is_valid():
            raise CreatureError(f"Invalid Creature '{self.creature.name}'"
                                f" for this {self.strat_type} strategy")
        print(self.creature.transform())
        print(self.creature.attack())
        print(self.creature.revert())

    def is_valid(self) -> bool:
        return hasattr(self.creature, "transform") and \
                hasattr(self.creature, "attack") and \
                hasattr(self.creature, "revert")


class DefensiveStrategy(BattleStrategy):
    def __init__(self, creature: Creature):
        super().__init__(creature)
        self.strat_type = "Normal"

    def act(self) -> None:
        if not self.is_valid():
            raise CreatureError(f"Invalid Creature '{self.creature.name}'"
                                f" for this {self.strat_type} strategy")
        print(self.creature.attack())
        print(self.creature.heal())  # type: ignore

    def is_valid(self) -> bool:
        return hasattr(self.creature, "attack") and \
                hasattr(self.creature, "heal")

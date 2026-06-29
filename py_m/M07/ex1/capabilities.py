from abc import ABC, abstractmethod
from typing import Optional
from ex0.creature import Creature


class HealCapability(ABC):
    def __init__(self) -> None:
        pass

    @abstractmethod
    def heal(self, target: Optional[Creature | list[Creature]]) -> str:
        pass


class TransformCapability(ABC):
    def __init__(self) -> None:
        pass

    @abstractmethod
    def transform(self):
        pass

    @abstractmethod
    def revert(self):
        pass


class Sproutling(Creature, HealCapability):
    def __init__(self, name: str, creature_type: str) -> None:
        super().__init__(name, creature_type)

    def attack(self) -> str:
        return f"{self.name} uses Vine Whip!"

    def heal(self, target: Optional[Creature | list[Creature]] = None) -> str:
        if type(target) is None:
            return f"{self.name} heals itself for a small amount"
        else:
            return f"{self.name} heals itself and others for a small amount"


class Bloomelle(Creature, HealCapability):
    def __init__(self, name: str, creature_type: str) -> None:
        super().__init__(name, creature_type)

    def attack(self) -> str:
        return f"{self.name} uses Petal Dance!"

    def heal(self, target: Optional[Creature | list[Creature]] = None) -> str:
        if type(target) is None:
            return f"{self.name} heals itself for a large amount"
        else:
            return f"{self.name} heals itself and others for a large amount"


class Shiftling(Creature, TransformCapability):
    def __init__(self, name: str, creature_type: str) -> None:
        super().__init__(name, creature_type)
        self.transformed = False

    def attack(self) -> str:
        if self.transformed:
            return f"{self.name} performs a boosted strike!"
        return f"{self.name} attacks normally."

    def transform(self):
        self.transformed = True
        return f"{self.name} shifts into a sharper form!"

    def revert(self):
        self.transformed = False
        return f"{self.name} returns to normal."


class Morphagon(Creature, TransformCapability):
    def __init__(self, name: str, creature_type: str):
        super().__init__(name, creature_type)
        self.transformed = False

    def attack(self) -> str:
        if self.transformed:
            return f"{self.name} unleashes a devastating morph strike!"
        return f"{self.name} attacks normally."

    def transform(self):
        self.transformed = True
        return f"{self.name} morphs into a dragonic battle form!"

    def revert(self):
        self.transformed = False
        return f"{self.name} stabilizes its form."

from abc import ABC, abstractmethod
from .creature import Creature, Flameling, Pyrodon, Aquabub, Torragon


class CreatureFactory(ABC):
    def __init__(self) -> None:
        pass

    @staticmethod
    @abstractmethod
    def create_base() -> Creature:
        pass

    @staticmethod
    @abstractmethod
    def create_evolved() -> Creature:
        pass


class FlameFactory(CreatureFactory):
    def __init__(self) -> None:
        pass

    @staticmethod
    def create_base() -> Flameling:
        return Flameling("Flameling", "Fire")

    @staticmethod
    def create_evolved(creature: Creature) -> Pyrodon:  # type: ignore
        return Pyrodon("Pyrodon", "Fire/Flying")


class AquaFactory(CreatureFactory):
    def __init__(self) -> None:
        pass

    @staticmethod
    def create_base() -> Aquabub:
        return Aquabub("Aquabub", "Water")

    @staticmethod
    def create_evolved(creature: Creature) -> Torragon:  # type: ignore
        return Torragon("Torragon", "Water")

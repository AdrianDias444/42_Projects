from ex0 import CreatureFactory
from .capabilities import Sproutling, Bloomelle, Shiftling, Morphagon


class HealingCreatureFactory(CreatureFactory):
    def __init__(self) -> None:
        pass

    @staticmethod
    def create_base() -> Sproutling:
        return Sproutling("Sproutling", "Grass")

    @staticmethod
    def create_evolved() -> Bloomelle:
        return Bloomelle("Bloomelle", "Grass/Fairy")


class TransformCreatureFactory(CreatureFactory):
    def __init__(self) -> None:
        pass

    @staticmethod
    def create_base() -> Shiftling:
        return Shiftling("Shiftling", "Normal")

    @staticmethod
    def create_evolved() -> Morphagon:
        return Morphagon("Morphagon", "Normal/Dragon")

from ex0.creature import Creature
from .capabilities import HealCapability

class Sproutling(Creature, HealCapability):
    def __init__(self):
        super().__init__("Sproutling", "Grass")
    
    def attack(self) -> str:
        return "Sproutling uses Vine Whip!"
    
    def heal(self, target: str = "itself") -> str:
        return f"Sproutling heals {target} for a small amount"

class Bloomelle(Creature, HealCapability):
    def __init__(self):
        super().__init__("Bloomelle", "Grass/Fairy")
    
    def attack(self) -> str:
        return "Bloomelle uses Petal Dance!"
    
    def heal(self, target: str = "itself and others") -> str:
        return f"Bloomelle heals {target} for a large amount"
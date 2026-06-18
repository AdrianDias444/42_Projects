from abc import ABC, abstractmethod
from ex0.factory import CreatureFactory
from ex0.creature import Creature
from .healing import Sproutling, Bloomelle
from .transform import Shiftling, Morphagon

class HealingCreatureFactory(CreatureFactory):    
    def create_base(self) -> Creature:
        return Sproutling()
    
    def create_evolved(self) -> Creature:

        return Bloomelle()

class TransformCreatureFactory(CreatureFactory):    
    def create_base(self) -> Creature:
        return Shiftling()
    
    def create_evolved(self) -> Creature:
        return Morphagon()
from abc import ABC, abstractmethod
from ex0.creature import Creature
from ex1.capabilities import HealCapability, TransformCapability
from .exceptions import InvalidStrategyError

class BattleStrategy(ABC):    
    @abstractmethod
    def is_valid(self, creature: Creature) -> bool:
        pass
    
    @abstractmethod
    def act(self, creature: Creature) -> None:
        pass

class NormalStrategy(BattleStrategy):    
    def is_valid(self, creature: Creature) -> bool:
        return True
    
    def act(self, creature: Creature) -> None:
        if not self.is_valid(creature):
            raise InvalidStrategyError(creature.name, "normal")
        print(creature.attack())

class AggressiveStrategy(BattleStrategy):    
    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, TransformCapability)
    
    def act(self, creature: Creature) -> None:
        if not self.is_valid(creature):
            raise InvalidStrategyError(creature.name, "aggressive")
        
        print(creature.transform())
        print(creature.attack())
        print(creature.revert())

class DefensiveStrategy(BattleStrategy):    
    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, HealCapability)
    
    def act(self, creature: Creature) -> None:
        if not self.is_valid(creature):
            raise InvalidStrategyError(creature.name, "defensive")
        
        print(creature.attack())
        print(creature.heal())
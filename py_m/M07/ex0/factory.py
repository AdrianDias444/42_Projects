from abc import ABC, abstractmethod
from .creature import Creature

class CreatureFactory(ABC):    
    @abstractmethod
    def create_base(self) -> Creature:
        pass
    
    @abstractmethod
    def create_evolved(self) -> Creature:
        pass

class FlameFactory(CreatureFactory):
    def create_base(self) -> Creature:
        from .fire_creatures import Flameling  # Import atrasado
        return Flameling()
    
    def create_evolved(self) -> Creature:
        from .fire_creatures import Pyrodon  # Import atrasado
        return Pyrodon()

class AquaFactory(CreatureFactory):    
    def create_base(self) -> Creature:
        from .water_creatures import Aquabub
        return Aquabub()
    
    def create_evolved(self) -> Creature:
        from .water_creatures import Torragon
        return Torragon()
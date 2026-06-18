from abc import ABC, abstractmethod

class HealCapability(ABC):
    @abstractmethod
    def heal(self, target: str = "itself") -> str:
        pass

class TransformCapability(ABC):
    def __init__(self):
        self._transformed = False
    
    @abstractmethod
    def transform(self) -> str:
        pass
    
    @abstractmethod
    def revert(self) -> str:
        pass
    
    def is_transformed(self) -> bool:
        return self._transformed
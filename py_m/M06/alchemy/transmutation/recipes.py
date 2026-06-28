import elements
from alchemy.potions import strength_potion
from ..elements import create_air


def lead_to_gold():
    air = create_air()
    strength = strength_potion()
    fire = elements.create_fire()

    return (f"Recipe transmuting Lead to Gold: brew '{air}'"
            f"and '{strength}' mixed with '{fire}'")

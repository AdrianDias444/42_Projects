import alchemy.grimoire


def light_spell_allowed_ingredients():
    return ["earth", "air", "fire", "water"]


def light_spell_record(spell_name: str, ingredients: str) -> str:
    result = alchemy.grimoire.validate_ingredients(ingredients)
    return f"Spell recorded: {spell_name} ({result})"

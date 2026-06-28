import alchemy.grimoire


def validate_ingredients(ingredients: str) -> str:
    allowed = alchemy.grimoire.light_spell_allowed_ingredients()
    ingredients_lower = ingredients.lower()

    for ingredient in allowed:
        if ingredient in ingredients_lower:
            return f"{ingredients} - VALID"

    return f"{ingredients} - INVALID"

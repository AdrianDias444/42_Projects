def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    print(seed_type.capitalize(), "seeds: ", end="")
    if unit.lower() == "packets":
        print(quantity, "packets available")
    elif unit.lower() == "grams":
        print(quantity, "grams total")
    elif unit.lower() == "area":
        print(f"covers {quantity} square meters")
    else:
        print(f"{unit} is a invalid output")


# ft_seed_inventory("tomato", 15, "packets")
# ft_seed_inventory("carrot", 8, "grams")
# ft_seed_inventory("lettuce", 12, "Area")

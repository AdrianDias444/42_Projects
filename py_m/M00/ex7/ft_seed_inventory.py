def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    print(seed_type.capitalize(), "seeds: ", end="")
    if(unit == "packets"):
        print(quantity, "packets available")
    elif(unit == "grams"):
        print(quantity, "grams total")
    else:
        print(f"covers {quantity} square meters")

# ft_seed_inventory("tomato", 15, "packets")
# ft_seed_inventory("carrot", 8, "grams")
# ft_seed_inventory("lettuce", 12, "area")
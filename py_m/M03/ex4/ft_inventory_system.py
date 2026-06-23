#!/usr/bin/python3
import sys


def process_argv():
    inventory = {}

    for arg in sys.argv[1:]:
        if ':' not in arg:
            print(f"Error - invalid parameter '{arg}'")
            continue

        item, qty_str = arg.split(':', maxsplit=1)

        if item in inventory:
            print(f"Redundant item '{item}' - discarding")
            continue

        try:
            qty = int(qty_str)
            inventory[item] = qty
        except ValueError:
            print(f"Quantity error for '{item}': invalid ", end="")
            print(f"literal for int() with base 10: '{qty_str}'")

    return (inventory)


def return_min(inventory):
    min_key = list(inventory.keys())[0]
    for item in inventory:
        if inventory[item] < inventory[min_key]:
            min_key = item
    return {min_key: inventory[min_key]}


def return_max(inventory):
    max_key = list(inventory.keys())[0]
    for item in inventory:
        if inventory[item] > inventory[max_key]:
            max_key = item
    return {max_key: inventory[max_key]}


def main():
    print("=== Inventory System Analysis ===")
    if len(sys.argv) == 1:
        print("Need Arguments")
        return
    inventory = process_argv()
    if len(inventory) == 0:
        return
    print(f"Got inventory: {inventory}")
    print(f"Item list: {list(inventory.keys())}")
    print(f"Total quantity of the {len(inventory.keys())} ", end="")
    print(f"items: {sum(inventory.values())}")
    for item in inventory.keys():
        total = sum(inventory.values())
        print(f"Item {item} represents {round(inventory[item]/total*100, 1)}%")

    max_dict = return_max(inventory)
    print(f"Item most abundant: {list(max_dict)[0]} ", end="")
    print(f"with quantity {list(max_dict.values())[0]}")

    min_dict = return_min(inventory)
    print(f"Item least abundant: {list(min_dict)[0]} ", end="")
    print(f"with quantity {list(min_dict.values())[0]}")

    inventory['magic_item'] = 1
    print(f"Updated inventory: {inventory}")


if __name__ == "__main__":
    main()

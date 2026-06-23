#!/usr/bin/python3

import random


def main():
    print("=== Game Data Alchemist ===")
    players = [
        'Alice',
        'bob',
        'Charlie',
        'dylan',
        'Emma',
        'Gregory',
        'john',
        'kevin',
        'Liam'
    ]
    print(f"Initial list of players: {players}")

    all_cap = [nome.capitalize() for nome in players]
    print(f"New list with all names capitalized: {all_cap}")

    only_cap = [nome for nome in players if nome[0].isupper()]
    print(f"New list of capitalized names only: {only_cap}")

    scores = {nome: random.randint(0, 1000) for nome in all_cap}
    print(f"Score dict: {scores}")

    avg = sum([scores[nome] for nome in scores]) / len(scores)
    print(f"Score average is {round(avg, 2)}")

    high = {nome: scores[nome] for nome in scores if scores[nome] > avg}
    print(f"High scores: {high}")


if __name__ == "__main__":
    main()

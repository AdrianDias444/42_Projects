#!/usr/bin/python3

import random


def gen_player_achievements(all_awards):
    num_awards = random.randint(5, 10)
    return set(random.sample(all_awards, num_awards))


all_awards = [
    'Crafting Genius',
    'World Savior',
    'Master Explorer',
    'Collector Supreme',
    'Untouchable',
    'Boss Slayer',
    'Strategist',
    'Unstoppable',
    'Speed Runner',
    'Survivor',
    'Treasure Hunter',
    'First Steps',
    'Sharp Mind',
    'Hidden Path Finder'
]


def main():
    print("=== Achievement Tracker System ===")
    alice = gen_player_achievements(all_awards)
    bob = gen_player_achievements(all_awards)
    charlie = gen_player_achievements(all_awards)
    dylan = gen_player_achievements(all_awards)

    print(f"Player Alice {alice}\n")
    print(f"Player Bob {bob}\n")
    print(f"Player Charlie {charlie}\n")
    print(f"Player Dylan {dylan}\n")

    union = set().union(alice, bob, charlie, dylan)
    print(f"All distinct achievement: {union}\n")

    inter = set.intersection(alice, bob, charlie, dylan)
    print(f"Common achievements: {inter}\n")

    alice_diff = alice.difference(bob, charlie, dylan)
    print(f"Only Alice has: {alice_diff}\n")

    bob_diff = bob.difference(alice, charlie, dylan)
    print(f"Only Bob has: {bob_diff}\n")

    charlie_diff = charlie.difference(alice, bob, dylan)
    print(f"Only Charlie has: {charlie_diff}\n")

    dylan_diff = dylan.difference(alice, bob, charlie)
    print(f"Only Dylan has: {dylan_diff}\n")

    alice_missing = set(all_awards).difference(alice)
    print(f"Alice is missing: {alice_missing}\n")

    bob_missing = set(all_awards).difference(bob)
    print(f"Bob is missing: {bob_missing}\n")

    charlie_missing = set(all_awards).difference(charlie)
    print(f"Charlie is missing: {charlie_missing}\n")

    dylan_missing = set(all_awards).difference(dylan)
    print(f"Dylan is missing: {dylan_missing}\n")


if __name__ == "__main__":
    main()

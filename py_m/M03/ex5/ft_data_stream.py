#!/usr/bin/python3

import random


def gen_event():
    player = ["alice", "bob", "charlie", "dylan"]
    actions = [
        "run",
        "eat",
        "sleep",
        "grab",
        "move",
        "climb",
        "swim",
        "release",
        "use"
    ]

    while True:
        name = random.choice(player)
        action = random.choice(actions)
        yield (name, action)


def consume_event(event_list):
    while event_list:
        event = random.choice(event_list)
        event_list.remove(event)
        yield event


def main():
    print("=== Game Data Stream Processor ===")
    gerador = gen_event()
    for i in range(1000):
        evento = next(gerador)
        print(f"Event {i}: Player {evento[0]} did action {evento[1]}")

    gerador2 = gen_event()
    lista = []

    for i in range(10):
        lista.append(next(gerador2))

    print(f"Built list of 10 events: {lista}")

    for event in consume_event(lista):
        print(f"Got event from list: {event}")
        print(f"Remains in list: {lista}")


if __name__ == "__main__":
    main()

from typing import Generator


class StreamWizard():
    def __init__(self):
        pass
    def generate_events(self, i:int) -> Generator:
        players = ["adrian", "Odair", "George", ]
        events = ["killed monster", "found treasure", "leveled up"]

        yield(
            "alice",
            "killed monster"
        )

        yield(
            "bob",
            "found treasure"
        )
        yield(
            "charlie",
            "levelep up"
        )

    def print_first_3_events(events):

        for event in events:
            print(f"Event [] {event[0]} {event[1]}")
if __name__ == "__main__":
    print("=== Game Data Stream Processor ===")
    
    manager = StreamWizard()
    events = manager.generate_events(10)
    
    number_of_events = 1000

    for event in events:
        print(f"{event[0]}, {event[1]}")

""" 
def fun(max):
    i = 1
    while i <= max:
        if(i != 10):
            yield i

        i += 1
count = fun(15)
for i in count:
    print(i) """
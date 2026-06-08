#!/usr/bin/python3
import sys

def print_results(scores):
    print(f"Scores processed: {scores}")
    print(f"Total players: {len(scores)}")
    print(f"Total score: {sum(scores)}")
    print(f"Average score: {sum(scores)/len(scores)}")
    print(f"High score: {max(scores)}")
    print(f"Low score: {min(scores)}")
    print(f"Score range {max(scores) - min(scores)}")

def error_message():
    print("No scores provided.  Usage: python3 ft_score_analytics.py <score1> <score2> ...")
    
def main():
    print("=== Player Score Analytics ===")
    error = False
    lenght = len(sys.argv)

    if(lenght < 2):
        error = True
    else:
        i = 1
        scores = []
        while(i < lenght):
            try:
                nb = int(sys.argv[i])
                scores.append(nb)
            except ValueError:
                print(f"Invalid parameter: '{sys.argv[i]}'")
            finally:
                i +=1
        if len(scores) == 0:
            error = True
    if not error:
        print_results(scores)
    else:
        error_message()
if __name__ == "__main__":
    main()
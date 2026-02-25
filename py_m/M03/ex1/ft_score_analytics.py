import sys

if __name__ == "__main__":
    print("=== Player Score Analytics ===")
    lenght = len(sys.argv)

    if(lenght < 2):
        print("No scores provided.  Usage: python3 ft_score_analytics.py <score1> <score2> ...")
    else:
        i = 1
        scores = []
        while(i < lenght):
            nb = int(sys.argv[i])
            scores.append(nb)
            i +=1
        print(f"Scores processed: {scores}")
        print(f"Total players: {len(scores)}")
        print(f"Total score: {sum(scores)}")
        print(f"Average score: {sum(scores)/len(scores)}")
        print(f"High score: {max(scores)}")
        print(f"Low score: {min(scores)}")
        print(f"Score range {max(scores) - min(scores)}")
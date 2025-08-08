
'''  Problem 022  
    Using 022.txt, a 46K text file containing over five-thousand first names, begin by sorting 
    it into alphabetical order. Then working out the alphabetical value for each name, multiply
    this value by its alphabetical position in the list to obtain a name score.
    For example, when the list is sorted into alphabetical order, COLIN, which is worth
    3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of
    938 * 53 = 49714. What is the total of all the name scores in the file? '''
    
def solution() -> int:
    names = []
    name = ""
    
    # read from file
    with open("..\\022.txt") as file:
        while True:
            c = file.read(1)
            
            if not c:
                break
            elif c == '"':
                continue
            elif c == ',':
                names.append(name)
                name = ""
            else:
                name += c
                
        # Insert the final name
        names.append(name)
        
    names.sort()
                
    total_score = 0
    for name in names:
        # ord('A') = 65; hence only subtract 64.
        name_score = sum([ord(c) - 64 for c in name])
        total_score += name_score * (names.index(name) + 1)
        
    return total_score


def main():
    print(f"The total score of all names is {solution()}.")
    
    
if __name__ == "__main__":
    main()
    
# Solved 8th August 2025.
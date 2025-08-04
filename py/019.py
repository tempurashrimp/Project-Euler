
''' Problem 019:
    How many Sundays fell on the first of the month during the 
    twentieth century (1 Jan 1901 to 31 Dec 2000)? '''

def solution() -> int:
    # We save the day of the week as a number from 0 to 6,
    # where 0 represents Sunday, and 6 represents Saturday.
    # 1st January 1901 is a Tuesday.
    day, firsts = 2, 0

    for year in range(1901, 2001):
        # 2000 is a leap year
        leap = False if year % 4 else True
        
        for month in range(12):
            if month in [3, 5, 8, 10]:
                # April, June, September or November
                day += 30
            elif month == 1:
                # February
                day += 29 if leap else 28
            else:
                day += 31
                
            day %= 7
            firsts += 0 if day else 1
        
    return firsts


def main():
    print(f"The number of Sundays on the 1st of the month in the 20th century is {solution()}")
    
if __name__ == "__main__":
    main()
    
# Solved 4th August 2025
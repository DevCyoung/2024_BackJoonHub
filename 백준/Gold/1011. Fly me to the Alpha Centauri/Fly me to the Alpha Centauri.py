import math

caseSize = int( input() )

for i in range(caseSize):
    
    start , end = map( int , input().split() )
    
    
    Range = end - start
    maxNum= int(math.sqrt(Range))
    result= 0
    
    if maxNum == math.sqrt(Range):
        result = maxNum * 2 - 1
    elif Range <= maxNum * maxNum + maxNum:
        result = maxNum * 2
    else :
        result = maxNum * 2 + 1
    print(result)
    
        
    
    
    
    
    
    
    
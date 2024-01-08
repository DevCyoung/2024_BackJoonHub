iNum   = int( input() )
result = 0
for i in range(1,iNum + 1):
    result += i   
    
    if result >= iNum:
        a = result - iNum + 1 
        b = i - (result - iNum)
        (a ,b) = (b , a) if i % 2 == 0 else (a ,b)
        print( "{0}/{1}".format( a, b  ) )
        break;
            
        
        
         

    
    
    
    
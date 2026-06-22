def hackerlandRadioTransmitters(x, k):
    # Write your code here
    x.sort() 
    N = len(x)
    transmitters = 0
    i = 0
    
    while i < N:
        transmitters += 1
        
        loc = x[i] + k
        while i < N and x[i] <= loc:
            i += 1
            
        loc = x[i-1] + k
        while i < N and x[i] <= loc:
            i += 1        
                        
    return transmitters
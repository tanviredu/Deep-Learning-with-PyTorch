import numpy as np
import random

#constants
SPEED_LIMIT = 60.000000000
eps = 0.000000001

#variables
data = []

def prediction(speed,limit):
    return (speed<limit or (speed-limit)<eps)

def backPropagate(limit):
    learn_rate = 0.3
    for x in data:
        speed = x[0]
        verdict = x[1]
        y_hat = prediction(speed,limit)

        if y_hat == verdict :
            continue
        elif verdict == 1 and y_hat == 0:
            limit += abs(limit-speed)*learn_rate
        elif verdict == 0 and y_hat == 1:
            limit -= abs(limit-speed)*learn_rate
    return limit

def perceptionAlgorithm(limit):
    return backPropagate(limit)

limit = random.uniform(1.0,180.0)

for counter in range(1,400):
    print counter
    speed = random.uniform(1.0,90.0)
    print speed
    limit = perceptionAlgorithm(limit)
    print limit
    if prediction(speed,limit) == 1:
        print "Inside speed limit.Passed"
    else:
        print "Outside speed limit.Blocked"
    verdict = (speed < SPEED_LIMIT or (speed - SPEED_LIMIT) < eps)
    data.append((speed,verdict))
    print verdict
    print "\n"

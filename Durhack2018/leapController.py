import os, sys, inspect, thread, time
src_dir = os.path.dirname(inspect.getfile(inspect.currentframe()))
arch_dir = '../lib/'
arch_dir2 = '../lib/x64'
sys.path.insert(0, os.path.abspath(os.path.join(src_dir, arch_dir)))
sys.path.insert(0, os.path.abspath(os.path.join(src_dir, arch_dir2)))

import Leap, math
from Leap import CircleGesture, KeyTapGesture, ScreenTapGesture, SwipeGesture


lastLeft = 0
lastRight = 0
lastUp = 0
lastDown = 0

def main():

    controller = Leap.Controller()
    listener = SampleListener()
    controller.add_listener(listener)

    # Keep this process running until Enter is pressed
    try:
        sys.stdin.readline()
    except KeyboardInterrupt:
        pass

class SampleListener(Leap.Listener):
    def on_connect(self, controller):
        controller.enable_gesture(Leap.Gesture.TYPE_SWIPE)


    def on_frame(self, controller):
        global lastUp, lastDown, lastLeft, lastRight
        frame = controller.frame()
        gestures = frame.gestures()
        for gesture in gestures:
            if gesture.type is Leap.Gesture.TYPE_SWIPE:
                swipe = Leap.SwipeGesture(gesture)
                if swipe.speed > 200:
                    #Right Swipe
                    if Leap.Vector(1,0,0).angle_to(swipe.direction) <  math.pi / 4 and (time.time() - lastRight) > 0.5:
                        print("R")
                        lastRight = time.time()
                    #Left
                    if Leap.Vector(-1,0,0).angle_to(swipe.direction) <  math.pi / 4 and (time.time() - lastLeft) > 0.5:
                        print("L")
                        lastLeft = time.time()
                    #Up
                    if Leap.Vector(0,1,0).angle_to(swipe.direction) <  math.pi / 4 and (time.time() - lastUp) > 0.5:
                        print("U")
                        lastUp = time.time()
                    if Leap.Vector(0,-1,0).angle_to(swipe.direction) <  math.pi / 4 and (time.time() - lastDown) > 0.5:
                        print("D")
                        lastDown = time.time()

                    #print("X: {0} Y: {1} Z: {2}".format(str(swipe.direction.x), str(swipe.direction.y), str(swipe.direction.z)))


main()

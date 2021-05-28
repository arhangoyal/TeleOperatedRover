# TeleOperatedRover

[Project video and tutorial](https://www.youtube.com/watch?v=dcaPVJwRSpw)

Here are the instructions for building a gesture controlled rover (tele operated rover). It consists of a rover unit which has a collision avoidance sensor onboard. The transmitter, instead of being a clumsy remote, is a cool glove which can be worn on the hand and then moved to transmit signals to the rover using hand movements. RF signals are used for communication.

This project has applications in vehicle underbody inspection (for security or maintenance) and to fly drones.


## Supplies required: <br />
S.No. | Item | Quantity
----- | ---- | --------
1 | Arduino/Genuino UNO (with UNO cable) | 2
2 | Li-ion Battery (12V) | 1
3 | Jumper Wires (Male to male, male to female, female to female) | 40 each
4 | Breadboard | 1
5 | L298 Motor Driver Module | 1
6 | MPU6050 Gyroscope | 1
7 | RF Receiver and Transmitter | 1 each
8 | Ultrasonic Sensor | 1
9 | Chassis setup | 1
10 | Battery Holder (often included with chassis) | 1
11 | Switch (often included with chassis) | 2
12 | Wire Stripper | 1
13 | De-soldering Pump (not necessary) | 1
14 | Double Sided Tape | 1


## Preparing the Arduino IDE: <br />
1. Download and link the [VirtualWire library](https://drive.google.com/file/d/1F_sQFRT4lsN5dUKXJdckl21weMJFzy1P/view?usp=sharing) <br />
2. Upload [Receiver Program](receiver_project_night_Analog_rovervideo.ino) to the Arduino on the rover <br />
3. Upload [Transmitter Program](transmitter_code_rovervideo.ino) to the Arduino on the glove <br />


## Building the Rover

### Step 1: Assemble the Chassis
- Assemble the chassis to make the base for your rover. This is a fairly easy step and you should be done in no time.

### Step 2: Check all the Components
- Check all the sensors by interfacing them with the Arduino separately. You can check any tutorial on how to interface the sensors individually with the Arduino.

### Step 3: Transmitter Setup
- Transmitter glove setup [image 1](https://user-images.githubusercontent.com/44669235/119938738-7c8ea200-bfaa-11eb-9cef-a57d17f44eff.png) and [image 2](https://user-images.githubusercontent.com/44669235/119938744-7f899280-bfaa-11eb-8b56-ad50a875fe1f.png)
- First, solder the pins to the gyroscope. Now make the connections according to the [circuit diagram](https://user-images.githubusercontent.com/44669235/119938773-89ab9100-bfaa-11eb-9ea7-5a9ccf9417f0.png). **Do not connect the battery right now.**
- Next, plug your Arduino into your laptop. Upload the following code file and see if the code is working properly (do this by removing the comments for the print statements in the code). Click on the serial monitor button (top right of your screen) to view the output of the print statements. If everything is working properly, you may go ahead and connect the battery.
- Remember to make sure that the orientation of the gyroscope in correct (according to the code used). Please check the above shown diagrams to check the orientation I used for the gyroscope.
- The gyroscope will send readings to the Arduino. From there, the readings will go to the RF transmitter to be transmitted so that the receiver can pick up the waves.

### Step 4: Receiver Setup
- Click [here](https://user-images.githubusercontent.com/44669235/119938726-74cefd80-bfaa-11eb-9be5-cc4ac54b3a45.png) for a picture of the receiver setup
- Make the connections according to the [circuit diagram](https://user-images.githubusercontent.com/44669235/119938770-87e1cd80-bfaa-11eb-9733-43d8758b6401.png). Do not connect the battery right now. Next, plug your Arduino into your laptop. Upload the following code file and see if the code is working properly. To do this:
  1. Remove the comments for the print statements in the program
  2. Switch on the transmitter setup
  3. Place the rover on some sort of a stand so that the wheels don’t touch the ground and the rover doesn’t take off the moment its receiver receives data
- **NOTE:** You may need to reverse the direction of one or both the motors If the code is working correctly, you should be able to see the correct output (forward, backward, right, left or stop) on your serial monitor according to your hand movements. If everything is working correctly, you may connect the battery. However, before connecting the battery you must check all the connections. One wrong terminal could blow your circuit.

### Step 5: Make the Setup using the Batteries
- Now unplug your laptop and connect the batteries to the respective setups. Test your project.
- Don’t let the rover get more than 5m away from the you, or else the rover may stop or start misbehaving!

### Step 6: Assembly
- Now it’s time to assemble the rover and actually see it in action! For my rover assembly design, check the pictures in the ‘Circuit Diagrams and Theory’ section. You are free to assemble the rover in a different way. Just make sure it is well balanced, or else it may do wheelies (don’t go like “Wow!” because you may find the rover the wrong way up).
- While testing, you may find that the rover is not moving accurately. There’ll be some delay and errors as we’re using simple RF modules. Also, in a practical scenario, the motors have some differences and the rover’s center of mass is not where you expect it to be. So you may find the rover moving diagonally when it’s supposed to go straight. Errors in the balance may be fixed by changing the speed for the left and right motors. Multiply variables ‘ena’ and ‘enb’ by different numbers to perfect your rover’s balance.
- Feel free to reach out to me in case of any doubts!


## Social: <br />
Do share your comments. I'd love to hear about your experience while trying out the project! I'll try to reply to all queries within 24 hours.
1. YouTube: <br />
    a. [Scientify Inc](https://www.youtube.com/c/scientifyinc) <br />
    b. [Scientify Hindi](https://www.youtube.com/c/scientifyhindi) <br />
2. [Linkedin](https://www.linkedin.com/in/arhangoyal/) <br />
3. [Instagram](https://www.instagram.com/scientifyinc_/) <br />
4. [Instructables](https://www.instructables.com/member/Scientify%20Inc/instructables/) <br />

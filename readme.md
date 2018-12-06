# Installation:

git clone https://github.com/citybooom/Servo_cmd_rosWS.git 

cd Servo_cmd_rosWS

git submodule update

catkin_make


# How to use:

$ roslaunch servo_cmd servo_serial.launch

$ rostopic pub /m0 std_msgs/Int16 [value]



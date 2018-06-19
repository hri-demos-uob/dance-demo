CHECKLIST FOR THE OPENDAY DEMO AT UNIVERSITY OF BIRMINGHAM
---

One important variable is the number of version of the demo.

* v02 for the 9th of September 2017 (~/tmp/openday_v02).
* v03 for the 22th 23th of June 2018 (~/tmp/openday_v03).



# Setting Up

1. Create path to save data

```
mkdir -p ~/tmp/openday_v03
```

2. tune the following parameters for the `~/catkin_ws/src/razor_imu_9dof/config/razor*.yaml` [2]

```
vim  ~/catkin_ws/src/razor_imu_9dof/config/razor1.yaml
vim  ~/catkin_ws/src/razor_imu_9dof/config/razor2.yaml
vim  ~/catkin_ws/src/razor_imu_9dof/config/razor3.yaml
vim  ~/catkin_ws/src/razor_imu_9dof/config/razor4.yaml
```

```
number_of_samples: 2000
main_data_stream_path: /home/map479/tmp/openday_v03
```
1000 samples ~ 20 seconds;   
2000 samples ~ 40 seconds;   
3000 samples ~ 60 seconds  


# NAO

The boot process is completed when NAO says “OGNAK GNOUK” and it takes around
2minutes 13 seconds, then you can establish the network connection with NAO
(selecting NAO in the in the network options)
and open a terminal to execute nao's movements with the python script.

## TERMINAL 1
```

cd ~/mxochicale/github/opendayuob-hridemo/nao_arm_movements/python_animation
./TenUpperArmMovements_changingspeed.py

```

The execution time for 
`./TenUpperArmMovements_changingspeed.py`
is 34 seconds.






# IMUS and ROS [1,2]

1. Turn on Razor sensors (wait 2 seconds to let them reboot)

2. bind bluetooth modules to rfcommN ports, where N is the number of port

## TERMINAL 2 

```
cd ~/mxochicale/github/ros/bluetooth_dev_conf/automatic_connection && ./bind_four_automatic_connection_ubuntu1604.sh && sleep 15

```
and wait around 15 seconds

In case of "Can't create device: Operation not permitted" run this: 
`sudo chmod u+s /usr/bin/rfcomm`



Once the bluetooth modules have been binded, you can launch the app

```
roslaunch razor_imu_9dof razor-pub-four-imus.launch
```
booting sensors takes around 15 to 20 seconds


Then press 'crtl-c' in the terminal


3. release bluetooth modules from  the rfcommN ports, 
where N is the number of ports


```
cd ~/mxochicale/github/ros/bluetooth_dev_conf/automatic_connection && ./release_four_automatic_connection_ubuntu1604.sh
```

4. Turn off sensors




# OPENFACE [3]

Make sure that `openface_pNN.sh` is changing to the right path to save
video files.

## TERMINAL 3

```
cd ~/mxochicale/github/opendayuob-hridemo/running-demo
sleep 10 && ./openface_pNN.sh pNNgXXaNN
```
sleep 10 seconds to wait for the 15 seconds for the imus to boot

Press `ctr-q` in the video window to exit




#  REFERENCES

[1] [automatic_connection](https://github.com/mxochicale/ros/tree/master/bluetooth_dev_conf/automatic_connection)  
[2] Further information about package configuration [mx_razor_imu_9dof/catkin_ws](https://github.com/mxochicale/ros/tree/master/mx_razor_imu_9dof/catkin_ws)  
[3] https://github.com/mxochicale/openface  




## RECOMMENDATIONS AND OBSERVATIONS for the next /openday_v03

* When a new user start the experiment, the labels for partcipants were wrong for
which is recommended to have a piece of paper to write down the participant number
which might be part of the general check list.
* It would be nice to program the robot with some voice commands while the user
is waiting for the sensors seeting up in ROS

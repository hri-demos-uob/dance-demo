Setup for the first test of the demo
---


One important variable is the number of version of the demo.


* v05 for the Fri 19 Oct 18:41:03 BST 2018 (~/tmp/openday_v05)
* v04 for the 15th of September 2018 (~/tmp/openday_v04)
* v03 for the 22th 23th of June 2018 (~/tmp/openday_v03)
* v02 for the 9th of September 2017 (~/tmp/openday_v02)


# Setting Up

1. Create path to save data

```
mkdir -p ~/tmp/openday_v05
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
main_data_stream_path: /home/map479/tmp/openday_v05
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
cd ~/mxochicale/github/opendayuob-hridemo/nao_arm_movements/python_animation && sleep 5 && ./TenUpperArmMovements_changingspeed.py

```

The execution time for 
`./TenUpperArmMovements_changingspeed.py`
is 34 seconds.






# IMUS and ROS [1,2]

1. Turn on Razor sensors (wait 2 seconds to let them reboot)

## TERMINAL 2 

2. bind bluetooth modules to rfcommN ports, where N is the number of port

```
cd ~/mxochicale/github/ros/bluetooth_dev_conf/automatic_connection && ./bind_four_automatic_connection_ubuntu1604.sh && sleep 15

```
and wait around 15 seconds

In case of "Can't create device: Operation not permitted" run this: 
`sudo chmod u+s /usr/bin/rfcomm`


3. Collect data with ros

Once the bluetooth modules have been binded, you can launch the app

```
roslaunch razor_imu_9dof razor-pub-four-imus.launch
```
booting sensors takes around 15 to 20 seconds

4. Stop data collection

Then press 'crtl-c' in the terminal


5. release bluetooth modules from  the rfcommN ports, 
where N is the number of ports

```
cd ~/mxochicale/github/ros/bluetooth_dev_conf/automatic_connection && ./release_four_automatic_connection_ubuntu1604.sh
```

6. Turn off sensors

Starting from sensor4, sensor3, sensor2 and sensor1







# OPENFACE [3]

Make sure that `openface_pNN.sh` is changing to the right path to save
video files.


```
$  vim openface_pNN.sh
```

then change version of openday vNN
```
cd /home/map479/tmp/openday_v05 && mkdir -p openface && cd openface
```


## TERMINAL 3

```
cd ~/mxochicale/github/opendayuob-hridemo/demo && sleep 10 && ./openface_pNN.sh pNNgXXaNN
```
sleep 10 seconds to wait for the 15 seconds for the imus to boot

Press `ctrl-q` in the video window to exit

then the script will compute the landmarks of the video
and replay the video with facelandmarks
Press `ctrl-q` to exit


# DATA PATHS

```
cd /home/map479/tmp/openday_v05
```

#  REFERENCE

[1] [automatic_connection](https://github.com/mxochicale/ros/tree/master/bluetooth_dev_conf/automatic_connection)  
[2] Further information about package configuration [mx_razor_imu_9dof/catkin_ws](https://github.com/mxochicale/ros/tree/master/mx_razor_imu_9dof/catkin_ws)  
[3] https://github.com/mxochicale/openface  




